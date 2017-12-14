#define fTree_cxx
#include "fTree.h"
#include "helperFunctions.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TMath.h>

void writeLine(std::ofstream& s, long run, long ls, long evt, TString whichPhoton,  TString region, TString cat, double pt, double scEta, double eta, double phi, double mass, double chIsoHiggs, double chIso03, double phoIso, double rhoCorPhoIso, double vz){

    s << run << ":" << ls << ":" << evt << "_" << whichPhoton.Data() <<  ", " << region.Data() << ", " << cat.Data() << ", " << pt << ", " << scEta << ", " << eta << ", " << phi << ", " << mass << ", " << chIsoHiggs << ", " << chIso03 << ", " << phoIso << ", " << rhoCorPhoIso << ", " << vz << "\n";
}
// fits from Antonis
double getKFactorOld(double m, bool EBEB){

    if (EBEB){
        double p0 = 8.90218e-01;
        double p1 = 5.19225e-04;
        double p2 = -1.37800e-07;
        double p3 = 1.97496e-11;
        double p4 = -1.04218e-15;

        double kf = p0 + p1*m + p2*m*m + p3*m*m*m + p4*m*m*m*m;
        return kf;
    }

    // EBEE
    else{

        double p0 = 9.46368e-01;
        double p1 = 3.22040e-04;
        double p2 = -8.06809e-08;
        double p3 = 1.34850e-11;
        double p4 = -8.24515e-16;

        double kf = p0 + p1*m + p2*m*m + p3*m*m*m + p4*m*m*m*m;
        return kf;
    }

}

double getKFactor(TF1* fit, double m, bool isMCFM = true){
    double mTemp = m;
    if (isMCFM){ //correction for the fact that MCFM k-factors only go from 500 to 4000 GeV
        if (m<500.)
            mTemp = 500.;
        else if (m>4000.)
            mTemp = 4000.;
    }
    double kFactor = fit->Eval(mTemp);
    return kFactor;
}

// pdf variation
double getPDFValue(double m, bool EBEB, TH1D* pdfHist){
    int binNum = pdfHist->FindBin(m);
    if (m >= 8200.) binNum = 80; //overflow was added to the last bin
    if (binNum == 0) binNum = 1; // map underflow to first bin
    if (EBEB && m < 230.) binNum = pdfHist->FindBin(230.);
    if (!EBEB && m < 320.) binNum = pdfHist->FindBin(320.);
    if (binNum == 1) binNum = 2; // temp fix because the 1st bin (200-300 GeV) was 0 due to a bug 
    double content = pdfHist->GetBinContent(binNum);
    return content;

}

double getSF(double pt, double eta, TH1D* tempEB, TH1D* tempEE, TString mode){

    bool isEB = fabs(eta) < 1.4442;
    bool isEE = 1.566 < fabs(eta) && fabs(eta) < 2.5;

    const double LUMI2015 = 2.620674712485; // /fb
    const double LUMI2016 = 35.867059982506; // /fb

    double SF = 0.;
    if (isEB){
        int binNum = tempEB->FindBin(pt);
        if (binNum > tempEB->GetNbinsX()) binNum = tempEB->GetNbinsX(); // use closest SF
        SF = tempEB->GetBinContent(binNum);
    }
    else if (isEE){
        int binNum = tempEE->FindBin(pt);
        if (binNum > tempEE->GetNbinsX()) binNum = tempEE->GetNbinsX(); // use closest SF
        SF = tempEE->GetBinContent(binNum);
    }
    double retVal;
    if ( mode.EqualTo("2015MC") ) retVal = 1.; // assume a SF of 1 for 2015
    else if ( mode.EqualTo("2016MC") ) retVal = SF;
    else if ( mode.EqualTo("20152016MC") ) retVal = ( LUMI2015 + (LUMI2016*SF) )/(LUMI2015 + LUMI2016); // "average out" scale factor when running 2015+2016
    else retVal = 1.;

    return retVal;
}

void fTree::Loop(TString outfilename, TString mode = "DATA")
{
//   In a ROOT session, you can do:
//      root> .L fTree.C
//      root> fTree t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch

    // std::ofstream massFile;
    // massFile.open("masses.txt");
    std::ofstream out;
    TString tempName = outfilename;
    tempName.ReplaceAll(".root",".csv");
    out.open(tempName.Data());
    bool is2015MC     = mode.EqualTo("2015MC");
    bool is2016MC     = mode.EqualTo("2016MC");
    bool is20152016MC = mode.EqualTo("20152016MC");

    bool isMC = is2015MC || is2016MC || is20152016MC;


    Double_t bins_30003500[6] = {0.,600.,1100.,1800.,2600.,13000.};
    Double_t bins[7] = {0.,600.,1100.,1800.,2600.,3500.,13000.};

    bool calcPDFWeights = outfilename.Contains("ADDPlots_GGJets") || outfilename.Contains("ADDPlots_Ms") || outfilename.Contains("ADDPlots_ADDBkg");
    bool isADD = outfilename.Contains("ADDPlots_Ms") || outfilename.Contains("ADDPlots_ADDBkg");
    bool applyKFactor = outfilename.Contains("ADDPlots_GGJets");

    cout << "mode: " << mode.Data() << endl;
    cout << "applyKFactor: " << 1.*applyKFactor << endl;
    cout << "calcPDFWeights: " << 1.*calcPDFWeights << endl;

    TH1D* leadingPhoPt_EBEB = createTH1D("leadingPhoPt_EBEB","leadingPhoPt_EBEB",50,75.,1500.,"p_{T}(#gamma_{1}) [GeV]","Events");
    TH1D* subleadingPhoPt_EBEB = createTH1D("subleadingPhoPt_EBEB","subleadingPhoPt_EBEB",50,75.,1500.,"p_{T}(#gamma_{2}) [GeV]","Events");
    TH1D* leadingPhoEta_EBEB = createTH1D("leadingPhoEta_EBEB","leadingPhoEta_EBEB",100,-5.,5.,"#eta(#gamma_{1})","Events");
    TH1D* subleadingPhoEta_EBEB = createTH1D("subleadingPhoEta_EBEB","subleadingPhoEta_EBEB",100,-5.,5.,"#eta(#gamma_{2})","Events");
    TH1D* leadingPhoPhi_EBEB = createTH1D("leadingPhoPhi_EBEB","leadingPhoPhi_EBEB",25,-3.141593,3.141593,"#phi(#gamma_{1})","Events");
    TH1D* subleadingPhoPhi_EBEB = createTH1D("subleadingPhoPhi_EBEB","subleadingPhoPhi_EBEB",25,-3.141593,3.141593,"#phi(#gamma_{2})","Events");
    TH1D* ggMass_EBEB = createTH1D("ggMass_EBEB","ggMass_EBEB",650,0.,13000.,"m_{#gamma#gamma} [GeV]","Events");
    TH1D* ggMass_EBEB_JPBinning = createTH1D("ggMass_EBEB_JPBinning","ggMass_EBEB",34,320.,1000.,"m_{#gamma#gamma} [GeV]","Events");
    TH1D* ggMass_EBEB_30003500varbin = createTH1D("ggMass_EBEB_30003500varbin","ggMass_EBEB_30003500varbin",5,bins_30003500,"m_{#gamma#gamma} [GeV]","Events");
    TH1D* ggMass_EBEB_varbin = createTH1D("ggMass_EBEB_varbin","ggMass_EBEB_varbin",6,bins,"m_{#gamma#gamma} [GeV]","Events");

    TH1D* ggMass_EBEB_20004000 = createTH1D("ggMass_EBEB_20004000","ggMass_EBEB_20004000 (raw yield)",1,2000.,4000.,"m_{#gamma#gamma} [GeV]","Events");
    TH1D* ggMass_EBEE_20004000 = createTH1D("ggMass_EBEE_20004000","ggMass_EBEE_20004000 (raw yield)",1,2000.,4000.,"m_{#gamma#gamma} [GeV]","Events");
    TH1D* leadingPhoPt_EBEE = createTH1D("leadingPhoPt_EBEE","leadingPhoPt_EBEE",50,75.,1500.,"p_{T}(#gamma_{1}) [GeV]","Events");
    TH1D* subleadingPhoPt_EBEE = createTH1D("subleadingPhoPt_EBEE","subleadingPhoPt_EBEE",50,75.,1500.,"p_{T}(#gamma_{2}) [GeV]","Events");
    TH1D* leadingPhoEta_EBEE = createTH1D("leadingPhoEta_EBEE","leadingPhoEta_EBEE",100,-5.,5.,"#eta(#gamma_{1})","Events");
    TH1D* subleadingPhoEta_EBEE = createTH1D("subleadingPhoEta_EBEE","subleadingPhoEta_EBEE",100,-5.,5.,"#eta(#gamma_{2})","Events");
    TH1D* leadingPhoPhi_EBEE = createTH1D("leadingPhoPhi_EBEE","leadingPhoPhi_EBEE",25,-3.141593,3.141593,"#phi(#gamma_{1})","Events");
    TH1D* subleadingPhoPhi_EBEE = createTH1D("subleadingPhoPhi_EBEE","subleadingPhoPhi_EBEE",25,-3.141593,3.141593,"#phi(#gamma_{2})","Events");
    TH1D* dRgg_EBEB = createTH1D("dRgg_EBEB","",30,0.,6," #DeltaR_{#gamma#gamma}","Events");
    TH1D* dRgg_EBEE = createTH1D("dRgg_EBEE","",30,0.,6," #DeltaR_{#gamma#gamma}","Events");
    TH1D* ggMass_EBEE = createTH1D("ggMass_EBEE","ggMass_EBEE",650,0.,13000.,"m_{#gamma#gamma} [GeV]","Events");
    TH1D* ggMass_EBEE_30003500varbin = createTH1D("ggMass_EBEE_30003500varbin","ggMass_EBEE_30003500varbin",5,bins_30003500,"m_{#gamma#gamma} [GeV]","Events");
    TH1D* ggMass_EBEE_varbin = createTH1D("ggMass_EBEE_varbin","ggMass_EBEE_varbin",6,bins,"m_{#gamma#gamma} [GeV]","Events");

    TH1D* hEventWeight = createTH1D("hEventWeight","",101,-0.05,1.05,"Event Weight","Events");

    TH1D* cosThetaStar_EBEB = new TH1D("cosThetaStar_EBEB",";|cos(#theta*)|;Events",25,0.,1.);
    TH1D* cosThetaStar_EBEE = new TH1D("cosThetaStar_EBEE",";|cos(#theta*)|;Events",25,0.,1.);
    TH1D* cosThetaStar_EBEB_mgg500To740 = new TH1D("cosThetaStar_EBEB_mgg500To740",";|cos(#theta*)|;Events",100,0.,1.);
    TH1D* cosThetaStar_EBEB_mgg740To760 = new TH1D("cosThetaStar_EBEB_mgg740To760",";|cos(#theta*)|;Events",100,0.,1.);
    TH1D* cosThetaStar_EBEB_mgg760To820 = new TH1D("cosThetaStar_EBEB_mgg760To820",";|cos(#theta*)|;Events",100,0.,1.);

    TH2D* eta1Vseta2_EBEB_mgg500To740 = new TH2D("eta1Vseta2_EBEB_mgg500To740",";#eta_{1};#eta_{2}",20,-1.4442,1.4442,20,-1.4442,1.4442);

    // pdf variation
    std::vector<TH1D*> vec_pdfVar_ggMass_EBEB;
    std::vector<TH1D*> vec_pdfVar_ggMass_EBEB_varbin;
    std::vector<TH1D*> vec_pdfVar_ggMass_EBEB_30003500varbin;

    std::vector<TH1D*> vec_scaleVar_ggMass_EBEB;
    std::vector<TH1D*> vec_scaleVar_ggMass_EBEB_varbin;
    std::vector<TH1D*> vec_scaleVar_ggMass_EBEB_30003500varbin;

    std::vector<TH1D*> vec_pdfVar_ggMass_EBEE;
    std::vector<TH1D*> vec_pdfVar_ggMass_EBEE_varbin;
    std::vector<TH1D*> vec_pdfVar_ggMass_EBEE_30003500varbin;

    std::vector<TH1D*> vec_scaleVar_ggMass_EBEE;
    std::vector<TH1D*> vec_scaleVar_ggMass_EBEE_varbin;
    std::vector<TH1D*> vec_scaleVar_ggMass_EBEE_30003500varbin;

    // "NLO" variation: handle on shape variation

    TH1D* ggMass_NLODown_EBEB = createTH1D("ggMass_NLODown_EBEB","ggMass_NLODown_EBEB",650,0.,13000.,"m_{#gamma#gamma} [GeV]","Events");
    TH1D* ggMass_NLODown_EBEB_varbin = createTH1D("ggMass_NLODown_EBEB_varbin","ggMass_NLODown_EBEB_varbin",6,bins,"m_{#gamma#gamma} [GeV]","Events");
    TH1D* ggMass_NLOUp_EBEB = createTH1D("ggMass_NLOUp_EBEB","ggMass_NLOUp_EBEB",650,0.,13000.,"m_{#gamma#gamma} [GeV]","Events");
    TH1D* ggMass_NLOUp_EBEB_varbin = createTH1D("ggMass_NLOUp_EBEB_varbin","ggMass_NLOUp_EBEB_varbin",6,bins,"m_{#gamma#gamma} [GeV]","Events");

    TH1D* ggMass_NLODown_EBEE = createTH1D("ggMass_NLODown_EBEE","ggMass_NLODown_EBEE",650,0.,13000.,"m_{#gamma#gamma} [GeV]","Events");
    TH1D* ggMass_NLODown_EBEE_varbin = createTH1D("ggMass_NLODown_EBEE_varbin","ggMass_NLODown_EBEE_varbin",6,bins,"m_{#gamma#gamma} [GeV]","Events");
    TH1D* ggMass_NLOUp_EBEE = createTH1D("ggMass_NLOUp_EBEE","ggMass_NLOUp_EBEE",650,0.,13000.,"m_{#gamma#gamma} [GeV]","Events");
    TH1D* ggMass_NLOUp_EBEE_varbin = createTH1D("ggMass_NLOUp_EBEE_varbin","ggMass_NLOUp_EBEE_varbin",6,bins,"m_{#gamma#gamma} [GeV]","Events");

    //scale variation
    TH1D* ggMass_fs0p5_EBEB = createTH1D("ggMass_fs0p5_EBEB","ggMass_fs0p5_EBEB",650,0.,13000.,"m_{#gamma#gamma} [GeV]","Events");
    TH1D* ggMass_fs0p5_EBEB_30003500varbin = createTH1D("ggMass_fs0p5_EBEB_30003500varbin","ggMass_fs0p5_EBEB_30003500varbin",5,bins_30003500,"m_{#gamma#gamma} [GeV]","Events");
    TH1D* ggMass_fs0p5_EBEB_varbin = createTH1D("ggMass_fs0p5_EBEB_varbin","ggMass_fs0p5_EBEB_varbin",6,bins,"m_{#gamma#gamma} [GeV]","Events");

    TH1D* ggMass_fs2_EBEB = createTH1D("ggMass_fs2_EBEB","ggMass_fs2_EBEB",650,0.,13000.,"m_{#gamma#gamma} [GeV]","Events");
    TH1D* ggMass_fs2_EBEB_30003500varbin = createTH1D("ggMass_fs2_EBEB_30003500varbin","ggMass_fs2_EBEB_30003500varbin",5,bins_30003500,"m_{#gamma#gamma} [GeV]","Events");
    TH1D* ggMass_fs2_EBEB_varbin = createTH1D("ggMass_fs2_EBEB_varbin","ggMass_fs2_EBEB_varbin",6,bins,"m_{#gamma#gamma} [GeV]","Events");

    TH1D* ggMass_renor0p5_EBEB = createTH1D("ggMass_renor0p5_EBEB","ggMass_renor0p5_EBEB",650,0.,13000.,"m_{#gamma#gamma} [GeV]","Events");
    TH1D* ggMass_renor0p5_EBEB_30003500varbin = createTH1D("ggMass_renor0p5_EBEB_30003500varbin","ggMass_renor0p5_EBEB_30003500varbin",5,bins_30003500,"m_{#gamma#gamma} [GeV]","Events");
    TH1D* ggMass_renor0p5_EBEB_varbin = createTH1D("ggMass_renor0p5_EBEB_varbin","ggMass_renor0p5_EBEB_varbin",6,bins,"m_{#gamma#gamma} [GeV]","Events");

    TH1D* ggMass_renor2_EBEB = createTH1D("ggMass_renor2_EBEB","ggMass_renor2_EBEB",650,0.,13000.,"m_{#gamma#gamma} [GeV]","Events");
    TH1D* ggMass_renor2_EBEB_30003500varbin = createTH1D("ggMass_renor2_EBEB_30003500varbin","ggMass_renor2_EBEB_30003500varbin",5,bins_30003500,"m_{#gamma#gamma} [GeV]","Events");
    TH1D* ggMass_renor2_EBEB_varbin = createTH1D("ggMass_renor2_EBEB_varbin","ggMass_renor2_EBEB_varbin",6,bins,"m_{#gamma#gamma} [GeV]","Events");

    TH1D* ggMass_fs0p5_EBEE = createTH1D("ggMass_fs0p5_EBEE","ggMass_fs0p5_EBEE",650,0.,13000.,"m_{#gamma#gamma} [GeV]","Events");
    TH1D* ggMass_fs0p5_EBEE_30003500varbin = createTH1D("ggMass_fs0p5_EBEE_30003500varbin","ggMass_fs0p5_EBEE_30003500varbin",5,bins_30003500,"m_{#gamma#gamma} [GeV]","Events");
    TH1D* ggMass_fs0p5_EBEE_varbin = createTH1D("ggMass_fs0p5_EBEE_varbin","ggMass_fs0p5_EBEE_varbin",6,bins,"m_{#gamma#gamma} [GeV]","Events");

    TH1D* ggMass_fs2_EBEE = createTH1D("ggMass_fs2_EBEE","ggMass_fs2_EBEE",650,0.,13000.,"m_{#gamma#gamma} [GeV]","Events");
    TH1D* ggMass_fs2_EBEE_30003500varbin = createTH1D("ggMass_fs2_EBEE_30003500varbin","ggMass_fs2_EBEE_30003500varbin",5,bins_30003500,"m_{#gamma#gamma} [GeV]","Events");
    TH1D* ggMass_fs2_EBEE_varbin = createTH1D("ggMass_fs2_EBEE_varbin","ggMass_fs2_EBEE_varbin",6,bins,"m_{#gamma#gamma} [GeV]","Events");

    TH1D* ggMass_renor0p5_EBEE = createTH1D("ggMass_renor0p5_EBEE","ggMass_renor0p5_EBEE",650,0.,13000.,"m_{#gamma#gamma} [GeV]","Events");
    TH1D* ggMass_renor0p5_EBEE_30003500varbin = createTH1D("ggMass_renor0p5_EBEE_30003500varbin","ggMass_renor0p5_EBEE_30003500varbin",5,bins_30003500,"m_{#gamma#gamma} [GeV]","Events");
    TH1D* ggMass_renor0p5_EBEE_varbin = createTH1D("ggMass_renor0p5_EBEE_varbin","ggMass_renor0p5_EBEE_varbin",6,bins,"m_{#gamma#gamma} [GeV]","Events");

    TH1D* ggMass_renor2_EBEE = createTH1D("ggMass_renor2_EBEE","ggMass_renor2_EBEE",650,0.,13000.,"m_{#gamma#gamma} [GeV]","Events");
    TH1D* ggMass_renor2_EBEE_30003500varbin = createTH1D("ggMass_renor2_EBEE_30003500varbin","ggMass_renor2_EBEE_30003500varbin",5,bins_30003500,"m_{#gamma#gamma} [GeV]","Events");
    TH1D* ggMass_renor2_EBEE_varbin = createTH1D("ggMass_renor2_EBEE_varbin","ggMass_renor2_EBEE_varbin",6,bins,"m_{#gamma#gamma} [GeV]","Events");

    // saturation histos
    TH1D* ggMass_sat_EBEB = createTH1D("ggMass_sat_EBEB","ggMass_sat_EBEB",650,0.,13000.,"m_{#gamma#gamma} [GeV]","Events");
    TH1D* ggMass_sat_EBEE = createTH1D("ggMass_sat_EBEE","ggMass_sat_EBEE",650,0.,13000.,"m_{#gamma#gamma} [GeV]","Events");

    // pileup reweighting histos
    TH1D* ggMass_puDown_EBEB = new TH1D("ggMass_puDown_EBEB",";m_{#gamma#gamma} [GeV];Events",650,0.,13000.);
    TH1D* ggMass_pu_EBEB = new TH1D("ggMass_pu_EBEB",";m_{#gamma#gamma} [GeV];Events",650,0.,13000.);
    TH1D* ggMass_puUp_EBEB = new TH1D("ggMass_puUp_EBEB",";m_{#gamma#gamma} [GeV];Events",650,0.,13000.);

    TH1D* ggMass_puDown_EBEE = new TH1D("ggMass_puDown_EBEE",";m_{#gamma#gamma} [GeV];Events",650,0.,13000.);
    TH1D* ggMass_pu_EBEE = new TH1D("ggMass_pu_EBEE",";m_{#gamma#gamma} [GeV];Events",650,0.,13000.);
    TH1D* ggMass_puUp_EBEE = new TH1D("ggMass_puUp_EBEE",";m_{#gamma#gamma} [GeV];Events",650,0.,13000.);

    // trigger efficiency inputs
    TH1D* passEBEB_pt2 = new TH1D("passEBEB_pt2","",28,0.,700.);
    TH1D* passEBEE_pt2 = new TH1D("passEBEE_pt2","",28,0.,700.);
    TH1D* passIncl_pt2 = new TH1D("passIncl_pt2","",28,0.,700.);

    TH1D* allEBEB_pt2 = new TH1D("allEBEB_pt2","",28,0.,700.);
    TH1D* allEBEE_pt2 = new TH1D("allEBEE_pt2","",28,0.,700.);
    TH1D* allIncl_pt2 = new TH1D("allIncl_pt2","",28,0.,700.);

    // dPhi distributions
    TH1D* dPhi_EBEB = createTH1D("dPhi_EBEB","",40,0.,3.1415927,"|#Delta#phi_{#gamma#gamma}|","Events");
    TH1D* dPhi_EBEE = createTH1D("dPhi_EBEE","",40,0.,3.1415927,"|#Delta#phi_{#gamma#gamma}|","Events");
    // dEta distributions
    TH1D* dEta_EBEB = createTH1D("dEta_EBEB","",40,0.,2.89,"|#Delta#eta_{#gamma#gamma}|","Events");
    TH1D* dEta_EBEE = createTH1D("dEta_EBEE","",60,0.,5.,"|#Delta#eta_{#gamma#gamma}|","Events");

    TH1D* dPhi_raw_mgg320To500_EBEB = createTH1D("dPhi_raw_mgg320To500_EBEB","",40,0.,3.1415927,"|#Delta#phi_{#gamma#gamma}|","Events");
    TH1D* dPhi_raw_mgg500To750_EBEB = createTH1D("dPhi_raw_mgg500To750_EBEB","",40,0.,3.1415927,"|#Delta#phi_{#gamma#gamma}|","Events");
    TH1D* dPhi_raw_mgg750To1000_EBEB = createTH1D("dPhi_raw_mgg750To1000_EBEB","",40,0.,3.1415927,"|#Delta#phi_{#gamma#gamma}|","Events");
    TH1D* dPhi_raw_mgg500To1000_EBEB = createTH1D("dPhi_raw_mgg500To1000_EBEB","",40,0.,3.1415927,"|#Delta#phi_{#gamma#gamma}|","Events");
    TH1D* dPhi_MCFMNLO_mgg320To500_EBEB = createTH1D("dPhi_MCFMNLO_mgg320To500_EBEB","",40,0.,3.1415927,"|#Delta#phi_{#gamma#gamma}|","Events");
    TH1D* dPhi_MCFMNLO_mgg500To750_EBEB = createTH1D("dPhi_MCFMNLO_mgg500To750_EBEB","",40,0.,3.1415927,"|#Delta#phi_{#gamma#gamma}|","Events");
    TH1D* dPhi_MCFMNLO_mgg750To1000_EBEB = createTH1D("dPhi_MCFMNLO_mgg750To1000_EBEB","",40,0.,3.1415927,"|#Delta#phi_{#gamma#gamma}|","Events");
    TH1D* dPhi_MCFMNLO_mgg500To1000_EBEB = createTH1D("dPhi_MCFMNLO_mgg500To1000_EBEB","",40,0.,3.1415927,"|#Delta#phi_{#gamma#gamma}|","Events");
    TH1D* dPhi_MCFMNNLO_mgg320To500_EBEB = createTH1D("dPhi_MCFMNNLO_mgg320To500_EBEB","",40,0.,3.1415927,"|#Delta#phi_{#gamma#gamma}|","Events");
    TH1D* dPhi_MCFMNNLO_mgg500To750_EBEB = createTH1D("dPhi_MCFMNNLO_mgg500To750_EBEB","",40,0.,3.1415927,"|#Delta#phi_{#gamma#gamma}|","Events");
    TH1D* dPhi_MCFMNNLO_mgg750To1000_EBEB = createTH1D("dPhi_MCFMNNLO_mgg750To1000_EBEB","",40,0.,3.1415927,"|#Delta#phi_{#gamma#gamma}|","Events");
    TH1D* dPhi_MCFMNNLO_mgg500To1000_EBEB = createTH1D("dPhi_MCFMNNLO_mgg500To1000_EBEB","",40,0.,3.1415927,"|#Delta#phi_{#gamma#gamma}|","Events");
    TH1D* dPhi_Diphox_mgg320To500_EBEB = createTH1D("dPhi_Diphox_mgg320To500_EBEB","",40,0.,3.1415927,"|#Delta#phi_{#gamma#gamma}|","Events");
    TH1D* dPhi_Diphox_mgg500To750_EBEB = createTH1D("dPhi_Diphox_mgg500To750_EBEB","",40,0.,3.1415927,"|#Delta#phi_{#gamma#gamma}|","Events");
    TH1D* dPhi_Diphox_mgg750To1000_EBEB = createTH1D("dPhi_Diphox_mgg750To1000_EBEB","",40,0.,3.1415927,"|#Delta#phi_{#gamma#gamma}|","Events");
    TH1D* dPhi_Diphox_mgg500To1000_EBEB = createTH1D("dPhi_Diphox_mgg500To1000_EBEB","",40,0.,3.1415927,"|#Delta#phi_{#gamma#gamma}|","Events");
    TH1D* dPhi_raw_mgg320To500_EBEE = createTH1D("dPhi_raw_mgg320To500_EBEE","",40,0.,3.1415927,"|#Delta#phi_{#gamma#gamma}|","Events");
    TH1D* dPhi_raw_mgg500To750_EBEE = createTH1D("dPhi_raw_mgg500To750_EBEE","",40,0.,3.1415927,"|#Delta#phi_{#gamma#gamma}|","Events");
    TH1D* dPhi_raw_mgg750To1000_EBEE = createTH1D("dPhi_raw_mgg750To1000_EBEE","",40,0.,3.1415927,"|#Delta#phi_{#gamma#gamma}|","Events");
    TH1D* dPhi_raw_mgg500To1000_EBEE = createTH1D("dPhi_raw_mgg500To1000_EBEE","",40,0.,3.1415927,"|#Delta#phi_{#gamma#gamma}|","Events");
    TH1D* dPhi_MCFMNLO_mgg320To500_EBEE = createTH1D("dPhi_MCFMNLO_mgg320To500_EBEE","",40,0.,3.1415927,"|#Delta#phi_{#gamma#gamma}|","Events");
    TH1D* dPhi_MCFMNLO_mgg500To750_EBEE = createTH1D("dPhi_MCFMNLO_mgg500To750_EBEE","",40,0.,3.1415927,"|#Delta#phi_{#gamma#gamma}|","Events");
    TH1D* dPhi_MCFMNLO_mgg750To1000_EBEE = createTH1D("dPhi_MCFMNLO_mgg750To1000_EBEE","",40,0.,3.1415927,"|#Delta#phi_{#gamma#gamma}|","Events");
    TH1D* dPhi_MCFMNLO_mgg500To1000_EBEE = createTH1D("dPhi_MCFMNLO_mgg500To1000_EBEE","",40,0.,3.1415927,"|#Delta#phi_{#gamma#gamma}|","Events");
    TH1D* dPhi_MCFMNNLO_mgg320To500_EBEE = createTH1D("dPhi_MCFMNNLO_mgg320To500_EBEE","",40,0.,3.1415927,"|#Delta#phi_{#gamma#gamma}|","Events");
    TH1D* dPhi_MCFMNNLO_mgg500To750_EBEE = createTH1D("dPhi_MCFMNNLO_mgg500To750_EBEE","",40,0.,3.1415927,"|#Delta#phi_{#gamma#gamma}|","Events");
    TH1D* dPhi_MCFMNNLO_mgg750To1000_EBEE = createTH1D("dPhi_MCFMNNLO_mgg750To1000_EBEE","",40,0.,3.1415927,"|#Delta#phi_{#gamma#gamma}|","Events");
    TH1D* dPhi_MCFMNNLO_mgg500To1000_EBEE = createTH1D("dPhi_MCFMNNLO_mgg500To1000_EBEE","",40,0.,3.1415927,"|#Delta#phi_{#gamma#gamma}|","Events");
    TH1D* dPhi_Diphox_mgg320To500_EBEE = createTH1D("dPhi_Diphox_mgg320To500_EBEE","",40,0.,3.1415927,"|#Delta#phi_{#gamma#gamma}|","Events");
    TH1D* dPhi_Diphox_mgg500To750_EBEE = createTH1D("dPhi_Diphox_mgg500To750_EBEE","",40,0.,3.1415927,"|#Delta#phi_{#gamma#gamma}|","Events");
    TH1D* dPhi_Diphox_mgg750To1000_EBEE = createTH1D("dPhi_Diphox_mgg750To1000_EBEE","",40,0.,3.1415927,"|#Delta#phi_{#gamma#gamma}|","Events");
    TH1D* dPhi_Diphox_mgg500To1000_EBEE = createTH1D("dPhi_Diphox_mgg500To1000_EBEE","",40,0.,3.1415927,"|#Delta#phi_{#gamma#gamma}|","Events");

    // other id variables

    TH1D* hOverE_photon1_EBEB = new TH1D("hOverE_photon1_EBEB",";H/E;Events",25,0.,0.05);
    TH1D* chIso_photon1_EBEB = new TH1D("chIso_photon1_EBEB",";Iso_{ch} [GeV];Events",12,0.,5.);
    TH1D* phoIso_photon1_EBEB = new TH1D("phoIso_photon1_EBEB",";#bar{Iso}_{#gamma} [GeV];Events",16,0.,2.75);
    TH1D* sieie_photon1_EBEB = new TH1D("sieie_photon1_EBEB",";#sigma_{i#etai#eta};Events",50,0.,0.0112);

    TH1D* hOverE_photon1_EBEE = new TH1D("hOverE_photon1_EBEE",";H/E;Events",25,0.,0.05);
    TH1D* chIso_photon1_EBEE = new TH1D("chIso_photon1_EBEE",";Iso_{ch} [GeV];Events",12,0.,5.);
    TH1D* phoIso_photon1_EBEE = new TH1D("phoIso_photon1_EBEE",";#bar{Iso}_{#gamma} [GeV];Events",16,0.,2.75);
    TH1D* sieie_photon1_EBEE = new TH1D("sieie_photon1_EBEE",";#sigma_{i#etai#eta};Events",50,0.,0.03);

    TH1D* hOverE_photon2_EBEB = new TH1D("hOverE_photon2_EBEB",";H/E;Events",25,0.,0.05);
    TH1D* chIso_photon2_EBEB = new TH1D("chIso_photon2_EBEB",";Iso_{ch} [GeV];Events",12,0.,5.);
    TH1D* phoIso_photon2_EBEB = new TH1D("phoIso_photon2_EBEB",";#bar{Iso}_{#gamma} [GeV];Events",16,0.,2.75);
    TH1D* sieie_photon2_EBEB = new TH1D("sieie_photon2_EBEB",";#sigma_{i#etai#eta};Events",50,0.,0.0112);

    TH1D* hOverE_photon2_EBEE = new TH1D("hOverE_photon2_EBEE",";H/E;Events",25,0.,0.05);
    TH1D* chIso_photon2_EBEE = new TH1D("chIso_photon2_EBEE",";Iso_{ch} [GeV];Events",12,0.,5.);
    TH1D* phoIso_photon2_EBEE = new TH1D("phoIso_photon2_EBEE",";#bar{Iso}_{#gamma} [GeV];Events",16,0.,2.75);
    TH1D* sieie_photon2_EBEE = new TH1D("sieie_photon2_EBEE",";#sigma_{i#etai#eta};Events",50,0.,0.03);

    if (calcPDFWeights){

        // for the SM background: loop over pdf eigenvector number and create histograms
        for (int i=1; i<53; i++){

            vec_pdfVar_ggMass_EBEB.push_back( createTH1D( TString::Format("ggMass_EBEB_CT10_%i",i), TString::Format("ggMass_EBEB_CT10_%i",i),650,0.,13000.,"m_{#gamma#gamma} [GeV]","Events") );
            vec_pdfVar_ggMass_EBEB_varbin.push_back( createTH1D(TString::Format("ggMass_EBEB_varbin_CT10_%i",i), TString::Format("ggMass_EBEB_varbin_CT10_%i",i),6,bins,"m_{#gamma#gamma} [GeV]","Events" ) ) ;
            vec_pdfVar_ggMass_EBEB_30003500varbin.push_back( createTH1D(TString::Format("ggMass_EBEB_30003500varbin_CT10_%i",i), TString::Format("ggMass_EBEB_30003500varbin_CT10_%i",i),5,bins_30003500,"m_{#gamma#gamma} [GeV]","Events" ) );

            vec_pdfVar_ggMass_EBEE.push_back( createTH1D( TString::Format("ggMass_EBEE_CT10_%i",i), TString::Format("ggMass_EBEE_CT10_%i",i),650,0.,13000.,"m_{#gamma#gamma} [GeV]","Events") );
            vec_pdfVar_ggMass_EBEE_varbin.push_back( createTH1D(TString::Format("ggMass_EBEE_varbin_CT10_%i",i), TString::Format("ggMass_EBEE_varbin_CT10_%i",i),6,bins,"m_{#gamma#gamma} [GeV]","Events" ) ) ;
            vec_pdfVar_ggMass_EBEE_30003500varbin.push_back( createTH1D(TString::Format("ggMass_EBEE_30003500varbin_CT10_%i",i), TString::Format("ggMass_EBEE_30003500varbin_CT10_%i",i),5,bins_30003500,"m_{#gamma#gamma} [GeV]","Events" ) );

        }

        for (int i=0; i<52; i++){
            vec_pdfVar_ggMass_EBEB.at(i)->Sumw2();
            vec_pdfVar_ggMass_EBEB_varbin.at(i)->Sumw2();
            vec_pdfVar_ggMass_EBEB_30003500varbin.at(i)->Sumw2();

            vec_pdfVar_ggMass_EBEE.at(i)->Sumw2();
            vec_pdfVar_ggMass_EBEE_varbin.at(i)->Sumw2();
            vec_pdfVar_ggMass_EBEE_30003500varbin.at(i)->Sumw2();
        }
        ggMass_fs0p5_EBEB->Sumw2();
        ggMass_fs0p5_EBEB_30003500varbin->Sumw2();
        ggMass_fs0p5_EBEB_varbin->Sumw2();
        ggMass_fs2_EBEB->Sumw2();
        ggMass_fs2_EBEB_30003500varbin->Sumw2();
        ggMass_fs2_EBEB_varbin->Sumw2();
        ggMass_renor0p5_EBEB->Sumw2();
        ggMass_renor0p5_EBEB_30003500varbin->Sumw2();
        ggMass_renor0p5_EBEB_varbin->Sumw2();
        ggMass_renor2_EBEB->Sumw2();
        ggMass_renor2_EBEB_30003500varbin->Sumw2();
        ggMass_renor2_EBEB_varbin->Sumw2();
        ggMass_NLODown_EBEB->Sumw2();
        ggMass_NLODown_EBEB_varbin->Sumw2();
        ggMass_NLOUp_EBEB->Sumw2();
        ggMass_NLOUp_EBEB_varbin->Sumw2();
        ggMass_fs0p5_EBEE->Sumw2();
        ggMass_fs0p5_EBEE_30003500varbin->Sumw2();
        ggMass_fs0p5_EBEE_varbin->Sumw2();
        ggMass_fs2_EBEE->Sumw2();
        ggMass_fs2_EBEE_30003500varbin->Sumw2();
        ggMass_fs2_EBEE_varbin->Sumw2();
        ggMass_renor0p5_EBEE->Sumw2();
        ggMass_renor0p5_EBEE_30003500varbin->Sumw2();
        ggMass_renor0p5_EBEE_varbin->Sumw2();
        ggMass_renor2_EBEE->Sumw2();
        ggMass_renor2_EBEE_30003500varbin->Sumw2();
        ggMass_renor2_EBEE_varbin->Sumw2();
        ggMass_NLODown_EBEE->Sumw2();
        ggMass_NLODown_EBEE_varbin->Sumw2();
        ggMass_NLOUp_EBEE->Sumw2();
        ggMass_NLOUp_EBEE_varbin->Sumw2();
    } // end calcPDFWeights block

    leadingPhoPt_EBEB->Sumw2();
    subleadingPhoPt_EBEB->Sumw2();
    leadingPhoEta_EBEB->Sumw2();
    subleadingPhoEta_EBEB->Sumw2();
    leadingPhoPhi_EBEB->Sumw2();
    subleadingPhoPhi_EBEB->Sumw2();
    ggMass_EBEB->Sumw2();
    ggMass_EBEB_JPBinning->Sumw2();
    ggMass_EBEB_30003500varbin->Sumw2();
    ggMass_EBEB_varbin->Sumw2();
    leadingPhoPt_EBEE->Sumw2();
    subleadingPhoPt_EBEE->Sumw2();
    leadingPhoEta_EBEE->Sumw2();
    subleadingPhoEta_EBEE->Sumw2();
    leadingPhoPhi_EBEE->Sumw2();
    subleadingPhoPhi_EBEE->Sumw2();
    dRgg_EBEB->Sumw2();
    dRgg_EBEE->Sumw2();
    ggMass_EBEE->Sumw2();
    ggMass_EBEE_30003500varbin->Sumw2();
    ggMass_EBEE_varbin->Sumw2();

    ggMass_EBEB_20004000->Sumw2();
    ggMass_EBEE_20004000->Sumw2();

    ggMass_sat_EBEB->Sumw2();
    ggMass_sat_EBEE->Sumw2();

    ggMass_puDown_EBEB->Sumw2();
    ggMass_pu_EBEB->Sumw2();
    ggMass_puUp_EBEB->Sumw2();
    ggMass_puDown_EBEE->Sumw2();
    ggMass_pu_EBEE->Sumw2();
    ggMass_puUp_EBEE->Sumw2();

    hOverE_photon1_EBEB->Sumw2();
    chIso_photon1_EBEB->Sumw2();
    phoIso_photon1_EBEB->Sumw2();
    sieie_photon1_EBEB->Sumw2();
    hOverE_photon1_EBEE->Sumw2();
    chIso_photon1_EBEE->Sumw2();
    phoIso_photon1_EBEE->Sumw2();
    sieie_photon1_EBEE->Sumw2();

    hOverE_photon2_EBEB->Sumw2();
    chIso_photon2_EBEB->Sumw2();
    phoIso_photon2_EBEB->Sumw2();
    sieie_photon2_EBEB->Sumw2();
    hOverE_photon2_EBEE->Sumw2();
    chIso_photon2_EBEE->Sumw2();
    phoIso_photon2_EBEE->Sumw2();
    sieie_photon2_EBEE->Sumw2();

    cosThetaStar_EBEB->Sumw2();
    cosThetaStar_EBEE->Sumw2();

    cosThetaStar_EBEB_mgg500To740->Sumw2();
    cosThetaStar_EBEB_mgg740To760->Sumw2();
    cosThetaStar_EBEB_mgg760To820->Sumw2();
    eta1Vseta2_EBEB_mgg500To740->Sumw2();

    dEta_EBEB->Sumw2();
    dEta_EBEE->Sumw2();

    dPhi_EBEB->Sumw2();
    dPhi_EBEE->Sumw2();
    dPhi_raw_mgg320To500_EBEB->Sumw2();
    dPhi_raw_mgg500To750_EBEB->Sumw2();
    dPhi_raw_mgg750To1000_EBEB->Sumw2();
    dPhi_raw_mgg500To1000_EBEB->Sumw2();
    dPhi_MCFMNLO_mgg320To500_EBEB->Sumw2();
    dPhi_MCFMNLO_mgg500To750_EBEB->Sumw2();
    dPhi_MCFMNLO_mgg750To1000_EBEB->Sumw2();
    dPhi_MCFMNLO_mgg500To1000_EBEB->Sumw2();
    dPhi_MCFMNNLO_mgg320To500_EBEB->Sumw2();
    dPhi_MCFMNNLO_mgg500To750_EBEB->Sumw2();
    dPhi_MCFMNNLO_mgg750To1000_EBEB->Sumw2();
    dPhi_MCFMNNLO_mgg500To1000_EBEB->Sumw2();
    dPhi_Diphox_mgg320To500_EBEB->Sumw2();
    dPhi_Diphox_mgg500To750_EBEB->Sumw2();
    dPhi_Diphox_mgg750To1000_EBEB->Sumw2();
    dPhi_Diphox_mgg500To1000_EBEB->Sumw2();
    dPhi_raw_mgg320To500_EBEE->Sumw2();
    dPhi_raw_mgg500To750_EBEE->Sumw2();
    dPhi_raw_mgg750To1000_EBEE->Sumw2();
    dPhi_raw_mgg500To1000_EBEE->Sumw2();
    dPhi_MCFMNLO_mgg320To500_EBEE->Sumw2();
    dPhi_MCFMNLO_mgg500To750_EBEE->Sumw2();
    dPhi_MCFMNLO_mgg750To1000_EBEE->Sumw2();
    dPhi_MCFMNLO_mgg500To1000_EBEE->Sumw2();
    dPhi_MCFMNNLO_mgg320To500_EBEE->Sumw2();
    dPhi_MCFMNNLO_mgg500To750_EBEE->Sumw2();
    dPhi_MCFMNNLO_mgg750To1000_EBEE->Sumw2();
    dPhi_MCFMNNLO_mgg500To1000_EBEE->Sumw2();
    dPhi_Diphox_mgg320To500_EBEE->Sumw2();
    dPhi_Diphox_mgg500To750_EBEE->Sumw2();
    dPhi_Diphox_mgg750To1000_EBEE->Sumw2();
    dPhi_Diphox_mgg500To1000_EBEE->Sumw2();
    passEBEB_pt2->Sumw2();
    passEBEE_pt2->Sumw2();
    passIncl_pt2->Sumw2();
    allEBEB_pt2->Sumw2();
    allEBEE_pt2->Sumw2();
    allIncl_pt2->Sumw2();

    // get the kfactor fits
    TFile kFactorFile_Diphox("kFactorFits.root","read");

    // MCFM
    TFile kFactorFile_EBEB_default("kfactor_BB_R1F1.root","read");
    TFile kFactorFile_EBEB_scaledown("kfactor_BB_R0p5F0p5.root","read"); 
    TFile kFactorFile_EBEB_scaleup("kfactor_BB_R2F2.root","read"); 

    TFile kFactorFile_EBEE_default("kfactor_BE_R1F1.root","read");
    TFile kFactorFile_EBEE_scaledown("kfactor_BE_R0p5F0p5.root","read"); 
    TFile kFactorFile_EBEE_scaleup("kfactor_BE_R2F2.root","read");    

    TF1* kFactor_default_EBEB = (TF1*)kFactorFile_EBEB_default.Get("pol3");
    TF1* kFactor_fs0p5_EBEB = (TF1*)kFactorFile_EBEB_scaledown.Get("pol3");
    TF1* kFactor_fs2_EBEB = (TF1*)kFactorFile_EBEB_scaleup.Get("pol3");
    // TF1* kFactor_renor0p5_EBEB = (TF1*)kFactorFile.Get("kFactor_renor0p5_EBEB");
    // TF1* kFactor_renor2_EBEB = (TF1*)kFactorFile.Get("kFactor_renor2_EBEB");
    TF1* kFactor_NLODown_EBEB = (TF1*)kFactorFile_Diphox.Get("kFactor_default_EBEB");
    TF1* kFactor_NLOUp_EBEB = (TF1*)kFactorFile_EBEB_default.Get("pol3_NLO");

    TF1* kFactor_default_EBEE = (TF1*)kFactorFile_EBEE_default.Get("pol3");
    TF1* kFactor_fs0p5_EBEE = (TF1*)kFactorFile_EBEE_scaledown.Get("pol3");
    TF1* kFactor_fs2_EBEE = (TF1*)kFactorFile_EBEE_scaleup.Get("pol3");
    // TF1* kFactor_renor0p5_EBEE = (TF1*)kFactorFile.Get("kFactor_renor0p5_EBEE");
    // TF1* kFactor_renor2_EBEE = (TF1*)kFactorFile.Get("kFactor_renor2_EBEE");
    TF1* kFactor_NLODown_EBEE = (TF1*)kFactorFile_Diphox.Get("kFactor_default_EBEE");
    TF1* kFactor_NLOUp_EBEE = (TF1*)kFactorFile_EBEE_default.Get("pol3_NLO");


    // get all pdf variation histos
    std::vector<TH1D*> pdfVarEBEB;
    std::vector<TH1D*> pdfVarEBEE;

    TFile pdfVarFileEBEB("PDF_sys_NormScaling_BB_long_22_2_17.root","read");
    TFile pdfVarFileEBEE("PDF_sys_NormScaling_BE_long_22_2_17.root","read");


    for(int i=1; i<53; i++){
        TString histName = TString::Format("DIPHOX_PDF_o_DIPHOX_Default_%i",i);
        TH1D* histEBEB = (TH1D*)pdfVarFileEBEB.Get(histName);
        TH1D* histEBEE = (TH1D*)pdfVarFileEBEE.Get(histName);

        pdfVarEBEB.push_back(histEBEB);
        pdfVarEBEE.push_back(histEBEE);
    }

    // get selection efficiency scale factor histos for 2016
    TFile sf2016file("scalefactors2016.root","read");
    TH1D* sfEB = (TH1D*)sf2016file.Get("SFEB");
    TH1D* sfEE = (TH1D*)sf2016file.Get("SFEE");

    gROOT->SetBatch();

    if (fChain == 0) return;

    Long64_t nentries = fChain->GetEntriesFast();

    Long64_t nbytes = 0, nb = 0;
    for (Long64_t jentry=0; jentry<nentries;jentry++) {
        Long64_t ientry = LoadTree(jentry);
        if (ientry < 0) break;
        nb = fChain->GetEntry(jentry);   nbytes += nb;
        // if (Cut(ientry) < 0) continue;

        // current file:
        // fChain->GetCurrentFile()->GetName();

        if (jentry % 1000 == 0) cout << "Now looking at event #" << jentry << endl;
        // Photon1 is the leading photon, Photon2 is the second leading
        // if (jentry>3000) break;

        if (!isGood) continue; // only use analysis level events
        bool EBEB = Diphoton_isEBEB;
        bool EBEE = Diphoton_isEBEE || Diphoton_isEEEB;

        // fill efficiencies before other cuts!
        if (TriggerBit_HLT_DoublePhoton40){
            bool pass = TriggerBit_HLT_DoublePhoton60;
            double ptTemp = Photon2_pt;
            if (Photon2_pt > 700.) ptTemp = 699.;
            if (EBEB || EBEE){
                if (pass) passIncl_pt2->Fill(ptTemp);
                allIncl_pt2->Fill(ptTemp);
            }
            if (EBEB){
                if (pass) passEBEB_pt2->Fill(ptTemp);
                allEBEB_pt2->Fill(ptTemp);
            }
            if (EBEE){
                if (pass) passEBEE_pt2->Fill(ptTemp);
                allEBEE_pt2->Fill(ptTemp);
            }
        }
        bool passTrigger = TriggerBit_HLT_DoublePhoton60 || TriggerBit_HLT_ECALHT800;
        if ( !passTrigger ) continue; // only admit events that pass HLT_DoublePhoton_60 or HLT_ECALHT800
        if (Photon1_pt < 75. || Photon2_pt < 75.) continue; // enforce 75 GeV pT cut
        if (Photon1_r9_5x5 < 0.8 || Photon2_r9_5x5 < 0.8) continue; // enforce r9>0.8 cut
        if (Diphoton_Minv < 500.) continue; // mass cut
        if (Diphoton_deltaR < 0.45) continue; // dR cut
        // if (Photon1_r9_5x5 < 0.8 || Photon2_r9_5x5 < 0.8) continue; // enforce r9>0.8 for both photons
        if (!EBEB && !EBEE) continue; // if neither an EBEB nor an EBEE event, ignore it.

        // double cut1;
        // double cut2;
        // if (Photon1_isEB) cut1 = 2.75;
        // else if (Photon1_isEE) cut1 = 2.;

        // if (Photon2_isEB) cut2 = 2.75;
        // else if (Photon2_isEE) cut2 = 2.;

        // double phoIso1 = 2.5 + Photon1_photonIso03 - (Photon1_rho*Photon1_phoEAHighPtID) - (Photon1_pt*Photon1_kappaHighPtID);
        // double phoIso2 = 2.5 + Photon2_photonIso03 - (Photon2_rho*Photon2_phoEAHighPtID) - (Photon2_pt*Photon2_kappaHighPtID);
        // if (phoIso1 > cut1 || phoIso2 > cut2) continue;

        // print out high mass events in data to make fireworks printouts
        if (mode.EqualTo("DATA") && Diphoton_Minv > 1900.){
            cout << "(mgg, run:ls:eventNum) = " << "(" << Diphoton_Minv << ", " << Event_run << ":" << Event_LS << ":" << Event_evnum << ")" << endl;
        }
        // set event weights, luminosity, k-factor, etc.
        double eventWeight = 1.;
        double nominalKFactor = 1.;
        const double LUMI2015 = 2.620674712485; // /fb
        const double LUMI2016 = 35.867059982506; // /fb
        // const double LUMITOTAL = LUMI2015 + LUMI2016;
        double LUMITOTAL;
        if (is2015MC) LUMITOTAL = LUMI2015;
        else if (is2016MC) LUMITOTAL = LUMI2016;
        else if (is20152016MC) LUMITOTAL = LUMI2015 + LUMI2016;

        if (isMC){
            double sfProd = getSF(Photon1_pt,Photon1_scEta,sfEB,sfEE,mode) * getSF(Photon2_pt,Photon2_scEta,sfEB,sfEE,mode); // selection efficiency scale factors, will equal 1 for only 2015
            eventWeight = (double)Event_weightAll*sfProd*LUMITOTAL;
            // multiply SM diphoton by k-factor; using RECO mass for now...
            if (applyKFactor && EBEB) nominalKFactor = getKFactor(kFactor_default_EBEB,GenDiphoton_Minv);
            else if (applyKFactor && EBEE) nominalKFactor = getKFactor(kFactor_default_EBEE,GenDiphoton_Minv);
            if (applyKFactor) eventWeight *= nominalKFactor;
            // for clockwork model
            // if (isADD){
            //     // do this in steps to make sure it's right
            //     double k = 500.; // GeV
            //     eventWeight *= (1./(GenDiphoton_Minv*GenDiphoton_Minv*GenDiphoton_Minv*GenDiphoton_Minv*GenDiphoton_Minv));
            //     eventWeight *= sqrt( 1 - ( k*k/(GenDiphoton_Minv*GenDiphoton_Minv) ) );
            //     if (GenDiphoton_Minv < k) eventWeight *= 0.; // theta(mgg-k)
            // }
        }
        hEventWeight->Fill(Event_weightAll);

        // calculate dPhi
        double dPhi = fabs( Diphoton_deltaPhi );
        // double cosThetaStar = tanh( fabs(  (Photon1_eta - Photon2_eta) / 2.  )  );
        double cosThetaStar = sqrt(       ( cosh(Photon1_eta - Photon2_eta) - 1. ) / (  cosh(Photon1_eta - Photon2_eta) - cos(Photon1_phi - Photon2_phi)    )       );

        if (EBEB){
            leadingPhoPt_EBEB->Fill(Photon1_pt,eventWeight);
            subleadingPhoPt_EBEB->Fill(Photon2_pt,eventWeight);
            leadingPhoEta_EBEB->Fill(Photon1_eta,eventWeight);
            subleadingPhoEta_EBEB->Fill(Photon2_eta,eventWeight);
            leadingPhoPhi_EBEB->Fill(Photon1_phi,eventWeight);
            subleadingPhoPhi_EBEB->Fill(Photon2_phi,eventWeight);
            ggMass_EBEB->Fill(Diphoton_Minv,eventWeight);
            ggMass_EBEB_JPBinning->Fill(Diphoton_Minv,eventWeight);
            ggMass_EBEB_30003500varbin->Fill(Diphoton_Minv,eventWeight);
            ggMass_EBEB_varbin->Fill(Diphoton_Minv,eventWeight);

            if (Photon1_isSaturated || Photon2_isSaturated){
                ggMass_sat_EBEB->Fill(Diphoton_Minv,eventWeight);
            }

            ggMass_puDown_EBEB->Fill(Diphoton_Minv,eventWeight*Event_weightPuDown);
            ggMass_pu_EBEB->Fill(Diphoton_Minv,eventWeight*Event_weightPu);
            ggMass_puUp_EBEB->Fill(Diphoton_Minv,eventWeight*Event_weightPuUp);

            ggMass_EBEB_20004000->Fill(Diphoton_Minv); //no weight because we want the raw yield!

            dPhi_EBEB->Fill(dPhi,eventWeight);
            dEta_EBEB->Fill(fabs(Diphoton_deltaEta),eventWeight);
            dRgg_EBEB->Fill(Diphoton_deltaR,eventWeight);

            hOverE_photon1_EBEB->Fill(Photon1_hadTowerOverEm,eventWeight);
            chIso_photon1_EBEB->Fill(Photon1_chargedHadIso03,eventWeight);
            phoIso_photon1_EBEB->Fill(Photon1_corPhotonIso03,eventWeight);
            sieie_photon1_EBEB->Fill(Photon1_sigmaIetaIeta5x5,eventWeight);

            hOverE_photon2_EBEB->Fill(Photon2_hadTowerOverEm,eventWeight);
            chIso_photon2_EBEB->Fill(Photon2_chargedHadIso03,eventWeight);
            phoIso_photon2_EBEB->Fill(Photon2_corPhotonIso03,eventWeight);
            sieie_photon2_EBEB->Fill(Photon2_sigmaIetaIeta5x5,eventWeight);

            cosThetaStar_EBEB->Fill(cosThetaStar,eventWeight);
            if (500. < Diphoton_Minv && Diphoton_Minv < 740.){
                cosThetaStar_EBEB_mgg500To740->Fill(cosThetaStar,eventWeight);
                eta1Vseta2_EBEB_mgg500To740->Fill(Photon1_scEta,Photon2_scEta,eventWeight);
            }
            else if (740. < Diphoton_Minv && Diphoton_Minv < 760.) cosThetaStar_EBEB_mgg740To760->Fill(cosThetaStar,eventWeight);
            else if (760. < Diphoton_Minv && Diphoton_Minv < 820.) cosThetaStar_EBEB_mgg760To820->Fill(cosThetaStar,eventWeight);

            if (320. < Diphoton_Minv && Diphoton_Minv < 500.){
                dPhi_raw_mgg320To500_EBEB->Fill(dPhi,eventWeight/nominalKFactor);
                if (applyKFactor){
                    dPhi_MCFMNLO_mgg320To500_EBEB->Fill(dPhi,eventWeight*getKFactor(kFactor_NLOUp_EBEB,GenDiphoton_Minv)/nominalKFactor);
                    dPhi_MCFMNNLO_mgg320To500_EBEB->Fill(dPhi,eventWeight);
                    dPhi_Diphox_mgg320To500_EBEB->Fill(dPhi,eventWeight*getKFactor(kFactor_NLODown_EBEB,GenDiphoton_Minv)/nominalKFactor);
                }
            }
            if (500. < Diphoton_Minv && Diphoton_Minv < 750.){
                dPhi_raw_mgg500To750_EBEB->Fill(dPhi,eventWeight/nominalKFactor);
                if (applyKFactor){
                    dPhi_MCFMNLO_mgg500To750_EBEB->Fill(dPhi,eventWeight*getKFactor(kFactor_NLOUp_EBEB,GenDiphoton_Minv)/nominalKFactor);
                    dPhi_MCFMNNLO_mgg500To750_EBEB->Fill(dPhi,eventWeight);
                    dPhi_Diphox_mgg500To750_EBEB->Fill(dPhi,eventWeight*getKFactor(kFactor_NLODown_EBEB,GenDiphoton_Minv)/nominalKFactor);
                }
                
            }
            if (750. < Diphoton_Minv && Diphoton_Minv < 1000.){
                dPhi_raw_mgg750To1000_EBEB->Fill(dPhi,eventWeight/nominalKFactor);
                if (applyKFactor){
                    dPhi_MCFMNLO_mgg750To1000_EBEB->Fill(dPhi,eventWeight*getKFactor(kFactor_NLOUp_EBEB,GenDiphoton_Minv)/nominalKFactor);
                    dPhi_MCFMNNLO_mgg750To1000_EBEB->Fill(dPhi,eventWeight);
                    dPhi_Diphox_mgg750To1000_EBEB->Fill(dPhi,eventWeight*getKFactor(kFactor_NLODown_EBEB,GenDiphoton_Minv)/nominalKFactor);
                }               
            }
            if (500. < Diphoton_Minv && Diphoton_Minv < 1000.){
                dPhi_raw_mgg500To1000_EBEB->Fill(dPhi,eventWeight/nominalKFactor);
                if (applyKFactor){
                    dPhi_MCFMNLO_mgg500To1000_EBEB->Fill(dPhi,eventWeight*getKFactor(kFactor_NLOUp_EBEB,GenDiphoton_Minv)/nominalKFactor);
                    dPhi_MCFMNNLO_mgg500To1000_EBEB->Fill(dPhi,eventWeight);
                    dPhi_Diphox_mgg500To1000_EBEB->Fill(dPhi,eventWeight*getKFactor(kFactor_NLODown_EBEB,GenDiphoton_Minv)/nominalKFactor);
                }                
            }

            if (calcPDFWeights){
                for(int i=0; i<52; i++){
                    vec_pdfVar_ggMass_EBEB.at(i)->Fill( Diphoton_Minv,eventWeight*getPDFValue(GenDiphoton_Minv,EBEB,pdfVarEBEB.at(i)) );
                    vec_pdfVar_ggMass_EBEB_varbin.at(i)->Fill( Diphoton_Minv,eventWeight*getPDFValue(GenDiphoton_Minv,EBEB,pdfVarEBEB.at(i)) );
                    vec_pdfVar_ggMass_EBEB_30003500varbin.at(i)->Fill( Diphoton_Minv,eventWeight*getPDFValue(GenDiphoton_Minv,EBEB,pdfVarEBEB.at(i)) );
                }
                ggMass_renor0p5_EBEB->Fill( Diphoton_Minv,eventWeight );
                ggMass_renor2_EBEB->Fill( Diphoton_Minv,eventWeight );
                ggMass_fs0p5_EBEB->Fill( Diphoton_Minv,eventWeight*getKFactor(kFactor_fs0p5_EBEB,GenDiphoton_Minv) / nominalKFactor );
                ggMass_fs2_EBEB->Fill( Diphoton_Minv,eventWeight*getKFactor(kFactor_fs2_EBEB,GenDiphoton_Minv) / nominalKFactor );
                ggMass_NLODown_EBEB->Fill(Diphoton_Minv,eventWeight*getKFactor(kFactor_NLODown_EBEB,GenDiphoton_Minv,false) / nominalKFactor);
                ggMass_NLOUp_EBEB->Fill(Diphoton_Minv,eventWeight*getKFactor(kFactor_NLOUp_EBEB,GenDiphoton_Minv) / nominalKFactor);

                ggMass_renor0p5_EBEB_varbin->Fill( Diphoton_Minv,eventWeight );
                ggMass_renor2_EBEB_varbin->Fill( Diphoton_Minv,eventWeight );
                ggMass_fs0p5_EBEB_varbin->Fill( Diphoton_Minv,eventWeight*getKFactor(kFactor_fs0p5_EBEB,GenDiphoton_Minv) / nominalKFactor );
                ggMass_fs2_EBEB_varbin->Fill( Diphoton_Minv,eventWeight*getKFactor(kFactor_fs2_EBEB,GenDiphoton_Minv) / nominalKFactor );
                ggMass_NLODown_EBEB_varbin->Fill(Diphoton_Minv,eventWeight*getKFactor(kFactor_NLODown_EBEB,GenDiphoton_Minv,false) / nominalKFactor);
                ggMass_NLOUp_EBEB_varbin->Fill(Diphoton_Minv,eventWeight*getKFactor(kFactor_NLOUp_EBEB,GenDiphoton_Minv) / nominalKFactor);
            }
            // write out info for each photon
            writeLine(out,Event_run,Event_LS,Event_evnum,"lead","EB","EBEB",Photon1_pt,Photon1_scEta,Photon1_eta,Photon1_phi,Diphoton_Minv,Photon1_chargedHadIso,Photon1_chargedHadIso03,Photon1_corPhotonIso03,Photon1_photonIso03,HiggsVertex_vz);
            writeLine(out,Event_run,Event_LS,Event_evnum,"sublead","EB","EBEB",Photon2_pt,Photon2_scEta,Photon2_eta,Photon2_phi,Diphoton_Minv,Photon2_chargedHadIso,Photon2_chargedHadIso03,Photon2_corPhotonIso03,Photon2_photonIso03,HiggsVertex_vz);
        } // end EBEB block

        else if (EBEE){
            leadingPhoPt_EBEE->Fill(Photon1_pt,eventWeight);
            subleadingPhoPt_EBEE->Fill(Photon2_pt,eventWeight);
            leadingPhoEta_EBEE->Fill(Photon1_scEta,eventWeight);
            subleadingPhoEta_EBEE->Fill(Photon2_scEta,eventWeight);
            leadingPhoPhi_EBEE->Fill(Photon1_scPhi,eventWeight);
            subleadingPhoPhi_EBEE->Fill(Photon2_scPhi,eventWeight);
            ggMass_EBEE->Fill(Diphoton_Minv,eventWeight);
            ggMass_EBEE_30003500varbin->Fill(Diphoton_Minv,eventWeight);
            ggMass_EBEE_varbin->Fill(Diphoton_Minv,eventWeight);

            ggMass_EBEE_20004000->Fill(Diphoton_Minv); //no weight because we want the raw yield!

            hOverE_photon1_EBEE->Fill(Photon1_hadTowerOverEm,eventWeight);
            chIso_photon1_EBEE->Fill(Photon1_chargedHadIso03,eventWeight);
            phoIso_photon1_EBEE->Fill(Photon1_corPhotonIso03,eventWeight);
            sieie_photon1_EBEE->Fill(Photon1_sigmaIetaIeta5x5,eventWeight);
            hOverE_photon2_EBEE->Fill(Photon2_hadTowerOverEm,eventWeight);
            chIso_photon2_EBEE->Fill(Photon2_chargedHadIso03,eventWeight);
            phoIso_photon2_EBEE->Fill(Photon2_corPhotonIso03,eventWeight);
            sieie_photon2_EBEE->Fill(Photon2_sigmaIetaIeta5x5,eventWeight);

            if (Photon1_isSaturated || Photon2_isSaturated){
                ggMass_sat_EBEE->Fill(Diphoton_Minv,eventWeight);
            }

            ggMass_puDown_EBEE->Fill(Diphoton_Minv,eventWeight*Event_weightPuDown);
            ggMass_pu_EBEE->Fill(Diphoton_Minv,eventWeight*Event_weightPu);
            ggMass_puUp_EBEE->Fill(Diphoton_Minv,eventWeight*Event_weightPuUp);
            
            dPhi_EBEE->Fill(dPhi,eventWeight);
            dEta_EBEE->Fill(fabs(Diphoton_deltaEta),eventWeight);
            dRgg_EBEE->Fill(Diphoton_deltaR,eventWeight);
            cosThetaStar_EBEE->Fill(cosThetaStar,eventWeight);

            if (320. < Diphoton_Minv && Diphoton_Minv < 500.){
                dPhi_raw_mgg320To500_EBEE->Fill(dPhi,eventWeight/nominalKFactor);
                if (applyKFactor){
                    dPhi_MCFMNLO_mgg320To500_EBEE->Fill(dPhi,eventWeight*getKFactor(kFactor_NLOUp_EBEE,GenDiphoton_Minv)/nominalKFactor);
                    dPhi_MCFMNNLO_mgg320To500_EBEE->Fill(dPhi,eventWeight);
                    dPhi_Diphox_mgg320To500_EBEE->Fill(dPhi,eventWeight*getKFactor(kFactor_NLODown_EBEE,GenDiphoton_Minv)/nominalKFactor);
                }
            }
            if (500. < Diphoton_Minv && Diphoton_Minv < 750.){
                dPhi_raw_mgg500To750_EBEE->Fill(dPhi,eventWeight/nominalKFactor);
                if (applyKFactor){
                    dPhi_MCFMNLO_mgg500To750_EBEE->Fill(dPhi,eventWeight*getKFactor(kFactor_NLOUp_EBEE,GenDiphoton_Minv)/nominalKFactor);
                    dPhi_MCFMNNLO_mgg500To750_EBEE->Fill(dPhi,eventWeight);
                    dPhi_Diphox_mgg500To750_EBEE->Fill(dPhi,eventWeight*getKFactor(kFactor_NLODown_EBEE,GenDiphoton_Minv)/nominalKFactor);
                }
                
            }
            if (750. < Diphoton_Minv && Diphoton_Minv < 1000.){
                dPhi_raw_mgg750To1000_EBEE->Fill(dPhi,eventWeight/nominalKFactor);
                if (applyKFactor){
                    dPhi_MCFMNLO_mgg750To1000_EBEE->Fill(dPhi,eventWeight*getKFactor(kFactor_NLOUp_EBEE,GenDiphoton_Minv)/nominalKFactor);
                    dPhi_MCFMNNLO_mgg750To1000_EBEE->Fill(dPhi,eventWeight);
                    dPhi_Diphox_mgg750To1000_EBEE->Fill(dPhi,eventWeight*getKFactor(kFactor_NLODown_EBEE,GenDiphoton_Minv)/nominalKFactor);
                }               
            }
            if (500. < Diphoton_Minv && Diphoton_Minv < 1000.){
                dPhi_raw_mgg500To1000_EBEE->Fill(dPhi,eventWeight/nominalKFactor);
                if (applyKFactor){
                    dPhi_MCFMNLO_mgg500To1000_EBEE->Fill(dPhi,eventWeight*getKFactor(kFactor_NLOUp_EBEE,GenDiphoton_Minv)/nominalKFactor);
                    dPhi_MCFMNNLO_mgg500To1000_EBEE->Fill(dPhi,eventWeight);
                    dPhi_Diphox_mgg500To1000_EBEE->Fill(dPhi,eventWeight*getKFactor(kFactor_NLODown_EBEE,GenDiphoton_Minv)/nominalKFactor);
                }                
            }

            if (calcPDFWeights){
                for(int i=0; i<52; i++){
                    vec_pdfVar_ggMass_EBEE.at(i)->Fill( Diphoton_Minv,eventWeight*getPDFValue(GenDiphoton_Minv,EBEB,pdfVarEBEE.at(i)) );
                    vec_pdfVar_ggMass_EBEE_varbin.at(i)->Fill( Diphoton_Minv,eventWeight*getPDFValue(GenDiphoton_Minv,EBEB,pdfVarEBEE.at(i)) );
                    vec_pdfVar_ggMass_EBEE_30003500varbin.at(i)->Fill( Diphoton_Minv,eventWeight*getPDFValue(GenDiphoton_Minv,EBEB,pdfVarEBEE.at(i)) );
                }
                ggMass_renor0p5_EBEE->Fill( Diphoton_Minv,eventWeight );
                ggMass_renor2_EBEE->Fill( Diphoton_Minv,eventWeight );
                ggMass_fs0p5_EBEE->Fill( Diphoton_Minv,eventWeight*getKFactor(kFactor_fs0p5_EBEE,GenDiphoton_Minv) / nominalKFactor );
                ggMass_fs2_EBEE->Fill( Diphoton_Minv,eventWeight*getKFactor(kFactor_fs2_EBEE,GenDiphoton_Minv) / nominalKFactor );
                ggMass_NLODown_EBEE->Fill(Diphoton_Minv,eventWeight*getKFactor(kFactor_NLODown_EBEE,GenDiphoton_Minv,false) / nominalKFactor);
                ggMass_NLOUp_EBEE->Fill(Diphoton_Minv,eventWeight*getKFactor(kFactor_NLOUp_EBEE,GenDiphoton_Minv) / nominalKFactor);

                ggMass_renor0p5_EBEE_varbin->Fill( Diphoton_Minv,eventWeight );
                ggMass_renor2_EBEE_varbin->Fill( Diphoton_Minv,eventWeight );
                ggMass_fs0p5_EBEE_varbin->Fill( Diphoton_Minv,eventWeight*getKFactor(kFactor_fs0p5_EBEE,GenDiphoton_Minv) / nominalKFactor );
                ggMass_fs2_EBEE_varbin->Fill( Diphoton_Minv,eventWeight*getKFactor(kFactor_fs2_EBEE,GenDiphoton_Minv) / nominalKFactor );
                ggMass_NLODown_EBEE_varbin->Fill(Diphoton_Minv,eventWeight*getKFactor(kFactor_NLODown_EBEE,GenDiphoton_Minv,false) / nominalKFactor);
                ggMass_NLOUp_EBEE_varbin->Fill(Diphoton_Minv,eventWeight*getKFactor(kFactor_NLOUp_EBEE,GenDiphoton_Minv) / nominalKFactor);

            }
            // void writeLine(std::ofstream& s, long run, long ls, long evt, TString whichPhoton,  TString region, TString cat, double pt, double scEta, double eta, double phi, double mass, double chIsoHiggs, double chIso03, double phoIso, double rhoCorPhoIso, double vz)
            TString r1,r2;
            if (Diphoton_isEEEB){
                r1 = "EE";
                r2 = "EB";
            }
            else if (Diphoton_isEBEE){
                r1="EB";
                r2="EE";
            }
            writeLine(out,Event_run,Event_LS,Event_evnum,"lead",r1,"EBEE",Photon1_pt,Photon1_scEta,Photon1_eta,Photon1_phi,Diphoton_Minv,Photon1_chargedHadIso,Photon1_chargedHadIso03,Photon1_corPhotonIso03,Photon1_photonIso03,HiggsVertex_vz);
            writeLine(out,Event_run,Event_LS,Event_evnum,"sublead",r2,"EBEE",Photon2_pt,Photon2_scEta,Photon2_eta,Photon2_phi,Diphoton_Minv,Photon2_chargedHadIso,Photon2_chargedHadIso03,Photon2_corPhotonIso03,Photon2_photonIso03,HiggsVertex_vz);
        } // end EBEE block
    } // end event loop
    out.close();

    // append lumi to outfilename for MC
    if (isMC){
        TString postFix = "_" + mode;
        postFix.ReplaceAll("MC","LUMI.root");
        outfilename.ReplaceAll(".root",postFix);
    }
    
    TFile f(outfilename,"recreate");
    f.cd();
    leadingPhoPt_EBEB->Write();
    subleadingPhoPt_EBEB->Write();
    leadingPhoEta_EBEB->Write();
    subleadingPhoEta_EBEB->Write();
    leadingPhoPhi_EBEB->Write();
    subleadingPhoPhi_EBEB->Write();
    leadingPhoPt_EBEE->Write();
    subleadingPhoPt_EBEE->Write();
    leadingPhoEta_EBEE->Write();
    subleadingPhoEta_EBEE->Write();
    leadingPhoPhi_EBEE->Write();
    subleadingPhoPhi_EBEE->Write();
    ggMass_EBEB->Write();
    ggMass_EBEB_JPBinning->Write();
    ggMass_EBEB_30003500varbin->Write();
    ggMass_EBEB_varbin->Write();
    ggMass_EBEE->Write();
    ggMass_EBEE_30003500varbin->Write();
    ggMass_EBEE_varbin->Write();
    ggMass_EBEB_20004000->Write();
    ggMass_EBEE_20004000->Write();
    if (calcPDFWeights){
        for(int i=0; i<52; i++){
            vec_pdfVar_ggMass_EBEB.at(i)->Write();
            vec_pdfVar_ggMass_EBEB_varbin.at(i)->Write();
            vec_pdfVar_ggMass_EBEB_30003500varbin.at(i)->Write();

            vec_pdfVar_ggMass_EBEE.at(i)->Write();
            vec_pdfVar_ggMass_EBEE_varbin.at(i)->Write();
            vec_pdfVar_ggMass_EBEE_30003500varbin.at(i)->Write();
        }
    }
    ggMass_NLODown_EBEB->Write();
    ggMass_NLODown_EBEB_varbin->Write();
    ggMass_NLOUp_EBEB->Write();
    ggMass_NLOUp_EBEB_varbin->Write();
    ggMass_NLODown_EBEE->Write();
    ggMass_NLODown_EBEE_varbin->Write();
    ggMass_NLOUp_EBEE->Write();
    ggMass_NLOUp_EBEE_varbin->Write();
    ggMass_fs0p5_EBEB->Write();
    ggMass_fs0p5_EBEB_varbin->Write();
    ggMass_fs2_EBEB->Write();
    ggMass_fs2_EBEB_varbin->Write();
    ggMass_renor0p5_EBEB->Write();
    ggMass_renor0p5_EBEB_varbin->Write();
    ggMass_renor2_EBEB->Write();
    ggMass_renor2_EBEB_varbin->Write();
    ggMass_fs0p5_EBEE->Write();
    ggMass_fs0p5_EBEE_varbin->Write();
    ggMass_fs2_EBEE->Write();
    ggMass_fs2_EBEE_varbin->Write();
    ggMass_renor0p5_EBEE->Write();
    ggMass_renor0p5_EBEE_varbin->Write();
    ggMass_renor2_EBEE->Write();
    ggMass_renor2_EBEE_varbin->Write();
    ggMass_sat_EBEB->Write();
    ggMass_sat_EBEE->Write();
    ggMass_puDown_EBEB->Write();
    ggMass_pu_EBEB->Write();
    ggMass_puUp_EBEB->Write();
    ggMass_puDown_EBEE->Write();
    ggMass_pu_EBEE->Write();
    ggMass_puUp_EBEE->Write();
    hEventWeight->Write();
    dPhi_EBEB->Write();
    dPhi_EBEE->Write();
    dRgg_EBEB->Write();
    dRgg_EBEE->Write();
    dEta_EBEB->Write();
    dEta_EBEE->Write();
    hOverE_photon1_EBEB->Write();
    chIso_photon1_EBEB->Write();
    phoIso_photon1_EBEB->Write();
    sieie_photon1_EBEB->Write();
    hOverE_photon1_EBEE->Write();
    chIso_photon1_EBEE->Write();
    phoIso_photon1_EBEE->Write();
    sieie_photon1_EBEE->Write();
    hOverE_photon2_EBEB->Write();
    chIso_photon2_EBEB->Write();
    phoIso_photon2_EBEB->Write();
    sieie_photon2_EBEB->Write();
    hOverE_photon2_EBEE->Write();
    chIso_photon2_EBEE->Write();
    phoIso_photon2_EBEE->Write();
    sieie_photon2_EBEE->Write();
    dPhi_raw_mgg320To500_EBEB->Write();
    dPhi_raw_mgg500To750_EBEB->Write();
    dPhi_raw_mgg750To1000_EBEB->Write();
    dPhi_raw_mgg500To1000_EBEB->Write();
    dPhi_MCFMNLO_mgg320To500_EBEB->Write();
    dPhi_MCFMNLO_mgg500To750_EBEB->Write();
    dPhi_MCFMNLO_mgg750To1000_EBEB->Write();
    dPhi_MCFMNLO_mgg500To1000_EBEB->Write();
    dPhi_MCFMNNLO_mgg320To500_EBEB->Write();
    dPhi_MCFMNNLO_mgg500To750_EBEB->Write();
    dPhi_MCFMNNLO_mgg750To1000_EBEB->Write();
    dPhi_MCFMNNLO_mgg500To1000_EBEB->Write();
    dPhi_Diphox_mgg320To500_EBEB->Write();
    dPhi_Diphox_mgg500To750_EBEB->Write();
    dPhi_Diphox_mgg750To1000_EBEB->Write();
    dPhi_Diphox_mgg500To1000_EBEB->Write();
    dPhi_raw_mgg320To500_EBEE->Write();
    dPhi_raw_mgg500To750_EBEE->Write();
    dPhi_raw_mgg750To1000_EBEE->Write();
    dPhi_raw_mgg500To1000_EBEE->Write();
    dPhi_MCFMNLO_mgg320To500_EBEE->Write();
    dPhi_MCFMNLO_mgg500To750_EBEE->Write();
    dPhi_MCFMNLO_mgg750To1000_EBEE->Write();
    dPhi_MCFMNLO_mgg500To1000_EBEE->Write();
    dPhi_MCFMNNLO_mgg320To500_EBEE->Write();
    dPhi_MCFMNNLO_mgg500To750_EBEE->Write();
    dPhi_MCFMNNLO_mgg750To1000_EBEE->Write();
    dPhi_MCFMNNLO_mgg500To1000_EBEE->Write();
    dPhi_Diphox_mgg320To500_EBEE->Write();
    dPhi_Diphox_mgg500To750_EBEE->Write();
    dPhi_Diphox_mgg750To1000_EBEE->Write();
    dPhi_Diphox_mgg500To1000_EBEE->Write();
    passEBEB_pt2->Write();
    passEBEE_pt2->Write();
    passIncl_pt2->Write();
    allEBEB_pt2->Write();
    allEBEE_pt2->Write();
    allIncl_pt2->Write();

    cosThetaStar_EBEB->Write();
    cosThetaStar_EBEE->Write();
    cosThetaStar_EBEB_mgg500To740->Write();
    cosThetaStar_EBEB_mgg740To760->Write();
    cosThetaStar_EBEB_mgg760To820->Write();
    eta1Vseta2_EBEB_mgg500To740->Write();
   
    pdfVarFileEBEB.Close();
    pdfVarFileEBEE.Close();

    f.Close();
} // end fTree::Loop() method
