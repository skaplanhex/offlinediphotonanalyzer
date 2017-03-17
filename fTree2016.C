#define fTree2016_cxx
#include "fTree2016.h"
#include "helperFunctions.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

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

double getAvgSF(double pt, double eta, TH1D* tempEB, TH1D* tempEE, double lumi2015, double lumi2016){

    bool isEB = fabs(eta) < 1.4442;
    bool isEE = 1.566 < fabs(eta) && fabs(eta) < 2.5;

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
    double retVal = ( lumi2015 + (lumi2016*SF) )/(lumi2015 + lumi2016); // assume a SF of 1 for 2015
    return retVal;
}

void fTree2016::Loop(TString outfilename, bool isMC=false)
{
//   In a ROOT session, you can do:
//      root> .L fTree2016.C
//      root> fTree2016 t
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

    // Double_t bins_30003500[6] = {0.,600.,1100.,1800.,2600.,13000.};
    // Double_t bins[7] = {0.,600.,1100.,1800.,2600.,3500.,13000.};
    Double_t bins_30003500[6] = {0.,600.,1100.,1800.,2600.,13000.};
    Double_t bins[7] = {0.,600.,1100.,1800.,2600.,3500.,13000.};

    bool calcPDFWeights = outfilename.Contains("ADDPlots_GGJets") || outfilename.Contains("ADDPlots_Ms") || outfilename.Contains("ADDPlots_ADDBkg");
    bool applyKFactor = outfilename.Contains("ADDPlots_GGJets");

    cout << "applyKFactor: " << 1.*applyKFactor << endl;
    cout << "calcPDFWeights: " << 1.*calcPDFWeights << endl;

    TH1D* leadingPhoPt_EBEB = createTH1D("leadingPhoPt_EBEB","leadingPhoPt_EBEB",300.,0.,1500.,"Leading Photon pT (GeV/c)","Events");
    TH1D* subleadingPhoPt_EBEB = createTH1D("subleadingPhoPt_EBEB","subleadingPhoPt_EBEB",300,0.,1500.,"Subleading Photon pT (GeV/c)","Events");
    TH1D* leadingPhoEta_EBEB = createTH1D("leadingPhoEta_EBEB","leadingPhoEta_EBEB",100,-5.,5.,"Leading Photon #eta","Events");
    TH1D* subleadingPhoEta_EBEB = createTH1D("subleadingPhoEta_EBEB","subleadingPhoEta_EBEB",100,-5.,5.,"Subleading Photon #eta","Events");
    TH1D* leadingPhoPhi_EBEB = createTH1D("leadingPhoPhi_EBEB","leadingPhoPhi_EBEB",100,-3.141593,3.141593,"Leading Photon #phi","Events");
    TH1D* subleadingPhoPhi_EBEB = createTH1D("subleadingPhoPhi_EBEB","subleadingPhoPhi_EBEB",100,-3.141593,3.141593,"Subleading Photon #phi","Events");
    TH1D* ggMass_EBEB = createTH1D("ggMass_EBEB","ggMass_EBEB",650,0.,13000.,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_EBEB_JPBinning = createTH1D("ggMass_EBEB_JPBinning","ggMass_EBEB",34,320.,1000.,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_EBEB_30003500varbin = createTH1D("ggMass_EBEB_30003500varbin","ggMass_EBEB_30003500varbin",5,bins_30003500,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_EBEB_varbin = createTH1D("ggMass_EBEB_varbin","ggMass_EBEB_varbin",6,bins,"m_{#gamma#gamma} (GeV/c^{2})","Events");

    TH1D* ggMass_EBEB_20004000 = createTH1D("ggMass_EBEB_20004000","ggMass_EBEB_20004000 (raw yield)",1,2000.,4000.,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_EBEE_20004000 = createTH1D("ggMass_EBEE_20004000","ggMass_EBEE_20004000 (raw yield)",1,2000.,4000.,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* leadingPhoPt_EBEE = createTH1D("leadingPhoPt_EBEE","leadingPhoPt_EBEE",300.,0.,1500.,"Leading Photon pT (GeV/c)","Events");
    TH1D* subleadingPhoPt_EBEE = createTH1D("subleadingPhoPt_EBEE","subleadingPhoPt_EBEE",300,0.,1500.,"Subleading Photon pT (GeV/c)","Events");
    TH1D* leadingPhoEta_EBEE = createTH1D("leadingPhoEta_EBEE","leadingPhoEta_EBEE",100,-5.,5.,"Leading Photon #eta","Events");
    TH1D* subleadingPhoEta_EBEE = createTH1D("subleadingPhoEta_EBEE","subleadingPhoEta_EBEE",100,-5.,5.,"Subleading Photon #eta","Events");
    TH1D* leadingPhoPhi_EBEE = createTH1D("leadingPhoPhi_EBEE","leadingPhoPhi_EBEE",100,-3.141593,3.141593,"Leading Photon #phi","Events");
    TH1D* subleadingPhoPhi_EBEE = createTH1D("subleadingPhoPhi_EBEE","subleadingPhoPhi_EBEE",100,-3.141593,3.141593,"Subleading Photon #phi","Events");
    TH1D* ggMass_EBEE = createTH1D("ggMass_EBEE","ggMass_EBEE",650,0.,13000.,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_EBEE_30003500varbin = createTH1D("ggMass_EBEE_30003500varbin","ggMass_EBEE_30003500varbin",5,bins_30003500,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_EBEE_varbin = createTH1D("ggMass_EBEE_varbin","ggMass_EBEE_varbin",6,bins,"m_{#gamma#gamma} (GeV/c^{2})","Events");

    TH1D* hEventWeight = createTH1D("hEventWeight","",101,-0.05,1.05,"Event Weight","Events");

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

    TH1D* ggMass_NLODown_EBEB = createTH1D("ggMass_NLODown_EBEB","ggMass_NLODown_EBEB",650,0.,13000.,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_NLODown_EBEB_varbin = createTH1D("ggMass_NLODown_EBEB_varbin","ggMass_NLODown_EBEB_varbin",6,bins,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_NLOUp_EBEB = createTH1D("ggMass_NLOUp_EBEB","ggMass_NLOUp_EBEB",650,0.,13000.,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_NLOUp_EBEB_varbin = createTH1D("ggMass_NLOUp_EBEB_varbin","ggMass_NLOUp_EBEB_varbin",6,bins,"m_{#gamma#gamma} (GeV/c^{2})","Events");

    TH1D* ggMass_NLODown_EBEE = createTH1D("ggMass_NLODown_EBEE","ggMass_NLODown_EBEE",650,0.,13000.,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_NLODown_EBEE_varbin = createTH1D("ggMass_NLODown_EBEE_varbin","ggMass_NLODown_EBEE_varbin",6,bins,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_NLOUp_EBEE = createTH1D("ggMass_NLOUp_EBEE","ggMass_NLOUp_EBEE",650,0.,13000.,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_NLOUp_EBEE_varbin = createTH1D("ggMass_NLOUp_EBEE_varbin","ggMass_NLOUp_EBEE_varbin",6,bins,"m_{#gamma#gamma} (GeV/c^{2})","Events");

    //scale variation
    TH1D* ggMass_fs0p5_EBEB = createTH1D("ggMass_fs0p5_EBEB","ggMass_fs0p5_EBEB",650,0.,13000.,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_fs0p5_EBEB_30003500varbin = createTH1D("ggMass_fs0p5_EBEB_30003500varbin","ggMass_fs0p5_EBEB_30003500varbin",5,bins_30003500,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_fs0p5_EBEB_varbin = createTH1D("ggMass_fs0p5_EBEB_varbin","ggMass_fs0p5_EBEB_varbin",6,bins,"m_{#gamma#gamma} (GeV/c^{2})","Events");

    TH1D* ggMass_fs2_EBEB = createTH1D("ggMass_fs2_EBEB","ggMass_fs2_EBEB",650,0.,13000.,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_fs2_EBEB_30003500varbin = createTH1D("ggMass_fs2_EBEB_30003500varbin","ggMass_fs2_EBEB_30003500varbin",5,bins_30003500,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_fs2_EBEB_varbin = createTH1D("ggMass_fs2_EBEB_varbin","ggMass_fs2_EBEB_varbin",6,bins,"m_{#gamma#gamma} (GeV/c^{2})","Events");

    TH1D* ggMass_renor0p5_EBEB = createTH1D("ggMass_renor0p5_EBEB","ggMass_renor0p5_EBEB",650,0.,13000.,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_renor0p5_EBEB_30003500varbin = createTH1D("ggMass_renor0p5_EBEB_30003500varbin","ggMass_renor0p5_EBEB_30003500varbin",5,bins_30003500,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_renor0p5_EBEB_varbin = createTH1D("ggMass_renor0p5_EBEB_varbin","ggMass_renor0p5_EBEB_varbin",6,bins,"m_{#gamma#gamma} (GeV/c^{2})","Events");

    TH1D* ggMass_renor2_EBEB = createTH1D("ggMass_renor2_EBEB","ggMass_renor2_EBEB",650,0.,13000.,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_renor2_EBEB_30003500varbin = createTH1D("ggMass_renor2_EBEB_30003500varbin","ggMass_renor2_EBEB_30003500varbin",5,bins_30003500,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_renor2_EBEB_varbin = createTH1D("ggMass_renor2_EBEB_varbin","ggMass_renor2_EBEB_varbin",6,bins,"m_{#gamma#gamma} (GeV/c^{2})","Events");

    TH1D* ggMass_fs0p5_EBEE = createTH1D("ggMass_fs0p5_EBEE","ggMass_fs0p5_EBEE",650,0.,13000.,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_fs0p5_EBEE_30003500varbin = createTH1D("ggMass_fs0p5_EBEE_30003500varbin","ggMass_fs0p5_EBEE_30003500varbin",5,bins_30003500,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_fs0p5_EBEE_varbin = createTH1D("ggMass_fs0p5_EBEE_varbin","ggMass_fs0p5_EBEE_varbin",6,bins,"m_{#gamma#gamma} (GeV/c^{2})","Events");

    TH1D* ggMass_fs2_EBEE = createTH1D("ggMass_fs2_EBEE","ggMass_fs2_EBEE",650,0.,13000.,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_fs2_EBEE_30003500varbin = createTH1D("ggMass_fs2_EBEE_30003500varbin","ggMass_fs2_EBEE_30003500varbin",5,bins_30003500,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_fs2_EBEE_varbin = createTH1D("ggMass_fs2_EBEE_varbin","ggMass_fs2_EBEE_varbin",6,bins,"m_{#gamma#gamma} (GeV/c^{2})","Events");

    TH1D* ggMass_renor0p5_EBEE = createTH1D("ggMass_renor0p5_EBEE","ggMass_renor0p5_EBEE",650,0.,13000.,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_renor0p5_EBEE_30003500varbin = createTH1D("ggMass_renor0p5_EBEE_30003500varbin","ggMass_renor0p5_EBEE_30003500varbin",5,bins_30003500,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_renor0p5_EBEE_varbin = createTH1D("ggMass_renor0p5_EBEE_varbin","ggMass_renor0p5_EBEE_varbin",6,bins,"m_{#gamma#gamma} (GeV/c^{2})","Events");

    TH1D* ggMass_renor2_EBEE = createTH1D("ggMass_renor2_EBEE","ggMass_renor2_EBEE",650,0.,13000.,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_renor2_EBEE_30003500varbin = createTH1D("ggMass_renor2_EBEE_30003500varbin","ggMass_renor2_EBEE_30003500varbin",5,bins_30003500,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_renor2_EBEE_varbin = createTH1D("ggMass_renor2_EBEE_varbin","ggMass_renor2_EBEE_varbin",6,bins,"m_{#gamma#gamma} (GeV/c^{2})","Events");


    if (calcPDFWeights){

        // for the SM background: loop over pdf eigenvector number and create histograms
        for (int i=1; i<53; i++){

            vec_pdfVar_ggMass_EBEB.push_back( createTH1D( TString::Format("ggMass_EBEB_CT10_%i",i), TString::Format("ggMass_EBEB_CT10_%i",i),650,0.,13000.,"m_{#gamma#gamma} (GeV/c^{2})","Events") );
            vec_pdfVar_ggMass_EBEB_varbin.push_back( createTH1D(TString::Format("ggMass_EBEB_varbin_CT10_%i",i), TString::Format("ggMass_EBEB_varbin_CT10_%i",i),6,bins,"m_{#gamma#gamma} (GeV/c^{2})","Events" ) ) ;
            vec_pdfVar_ggMass_EBEB_30003500varbin.push_back( createTH1D(TString::Format("ggMass_EBEB_30003500varbin_CT10_%i",i), TString::Format("ggMass_EBEB_30003500varbin_CT10_%i",i),5,bins_30003500,"m_{#gamma#gamma} (GeV/c^{2})","Events" ) );

            vec_pdfVar_ggMass_EBEE.push_back( createTH1D( TString::Format("ggMass_EBEE_CT10_%i",i), TString::Format("ggMass_EBEE_CT10_%i",i),650,0.,13000.,"m_{#gamma#gamma} (GeV/c^{2})","Events") );
            vec_pdfVar_ggMass_EBEE_varbin.push_back( createTH1D(TString::Format("ggMass_EBEE_varbin_CT10_%i",i), TString::Format("ggMass_EBEE_varbin_CT10_%i",i),6,bins,"m_{#gamma#gamma} (GeV/c^{2})","Events" ) ) ;
            vec_pdfVar_ggMass_EBEE_30003500varbin.push_back( createTH1D(TString::Format("ggMass_EBEE_30003500varbin_CT10_%i",i), TString::Format("ggMass_EBEE_30003500varbin_CT10_%i",i),5,bins_30003500,"m_{#gamma#gamma} (GeV/c^{2})","Events" ) );

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
    ggMass_EBEE->Sumw2();
    ggMass_EBEE_30003500varbin->Sumw2();
    ggMass_EBEE_varbin->Sumw2();

    ggMass_EBEB_20004000->Sumw2();
    ggMass_EBEE_20004000->Sumw2();

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
        if (!TriggerBit_HLT_DoublePhoton60) continue; // only admit events that pass HLT_DoublePhoton_60
        if (Photon1_pt < 75. || Photon2_pt < 75.) continue; // enforce 75 GeV pT cut

        // bool EBEB = isEBEB(Photon1_scEta,Photon2_scEta); // fabs is taken in the helper function!
        // bool EBEE = isEBEE(Photon1_scEta,Photon2_scEta);
        bool EBEB = Diphoton_isEBEB;
        bool EBEE = Diphoton_isEBEE || Diphoton_isEEEB;

        // mass cuts
        if (EBEB && Diphoton_Minv < 230.) continue;
        if (EBEE && Diphoton_Minv < 320.) continue;

        // get event weight
        // If running over data, some filler will be there, so set it to be 1 manually if the event weight is <= 0
        double eventWeight = 1.;
        double nominalKFactor = 1.;
        // const double LUMI2015 = 2.620674712485; // /fb
        const double LUMI2015 = 0.; // /fb
        const double LUMI2016 = 35.867059982506; // /fb
        // const double LUMITOTAL = LUMI2015 + LUMI2016;
        const double LUMITOTAL = LUMI2015 + LUMI2016;

        if (isMC){
            double avgSFProd = getAvgSF(Photon1_pt,Photon1_scEta,sfEB,sfEE,LUMI2015,LUMI2016) * getAvgSF(Photon2_pt,Photon2_scEta,sfEB,sfEE,LUMI2015,LUMI2016); // selection efficiency scale factors, will equal 1 for only 2015
            eventWeight = (double)Event_weightAll*avgSFProd*LUMITOTAL;
            // multiply SM diphoton by k-factor; using RECO mass for now...
            if (applyKFactor && EBEB) nominalKFactor = getKFactor(kFactor_default_EBEB,Diphoton_Minv);
            else if (applyKFactor && EBEE) nominalKFactor = getKFactor(kFactor_default_EBEE,Diphoton_Minv);
            if (applyKFactor) eventWeight *= nominalKFactor;
        }
        hEventWeight->Fill(Event_weightAll);

        if (EBEB){
            leadingPhoPt_EBEB->Fill(Photon1_pt,eventWeight);
            subleadingPhoPt_EBEB->Fill(Photon2_pt,eventWeight);
            leadingPhoEta_EBEB->Fill(Photon1_scEta,eventWeight);
            subleadingPhoEta_EBEB->Fill(Photon2_scEta,eventWeight);
            leadingPhoPhi_EBEB->Fill(Photon1_scPhi,eventWeight);
            subleadingPhoPhi_EBEB->Fill(Photon2_scPhi,eventWeight);
            ggMass_EBEB->Fill(Diphoton_Minv,eventWeight);
            ggMass_EBEB_JPBinning->Fill(Diphoton_Minv,eventWeight);
            ggMass_EBEB_30003500varbin->Fill(Diphoton_Minv,eventWeight);
            ggMass_EBEB_varbin->Fill(Diphoton_Minv,eventWeight);

            ggMass_EBEB_20004000->Fill(Diphoton_Minv); //no weight because we want the raw yield!

            if (calcPDFWeights){
                for(int i=0; i<52; i++){
                    vec_pdfVar_ggMass_EBEB.at(i)->Fill( Diphoton_Minv,eventWeight*getPDFValue(Diphoton_Minv,EBEB,pdfVarEBEB.at(i)) );
                    vec_pdfVar_ggMass_EBEB_varbin.at(i)->Fill( Diphoton_Minv,eventWeight*getPDFValue(Diphoton_Minv,EBEB,pdfVarEBEB.at(i)) );
                    vec_pdfVar_ggMass_EBEB_30003500varbin.at(i)->Fill( Diphoton_Minv,eventWeight*getPDFValue(Diphoton_Minv,EBEB,pdfVarEBEB.at(i)) );
                }
                ggMass_renor0p5_EBEB->Fill( Diphoton_Minv,eventWeight );
                ggMass_renor2_EBEB->Fill( Diphoton_Minv,eventWeight );
                ggMass_fs0p5_EBEB->Fill( Diphoton_Minv,eventWeight*getKFactor(kFactor_fs0p5_EBEB,Diphoton_Minv) / nominalKFactor );
                ggMass_fs2_EBEB->Fill( Diphoton_Minv,eventWeight*getKFactor(kFactor_fs2_EBEB,Diphoton_Minv) / nominalKFactor );
                ggMass_NLODown_EBEB->Fill(Diphoton_Minv,eventWeight*getKFactor(kFactor_NLODown_EBEB,Diphoton_Minv,false) / nominalKFactor);
                ggMass_NLOUp_EBEB->Fill(Diphoton_Minv,eventWeight*getKFactor(kFactor_NLOUp_EBEB,Diphoton_Minv) / nominalKFactor);

                ggMass_renor0p5_EBEB_varbin->Fill( Diphoton_Minv,eventWeight );
                ggMass_renor2_EBEB_varbin->Fill( Diphoton_Minv,eventWeight );
                ggMass_fs0p5_EBEB_varbin->Fill( Diphoton_Minv,eventWeight*getKFactor(kFactor_fs0p5_EBEB,Diphoton_Minv) / nominalKFactor );
                ggMass_fs2_EBEB_varbin->Fill( Diphoton_Minv,eventWeight*getKFactor(kFactor_fs2_EBEB,Diphoton_Minv) / nominalKFactor );
                ggMass_NLODown_EBEB_varbin->Fill(Diphoton_Minv,eventWeight*getKFactor(kFactor_NLODown_EBEB,Diphoton_Minv,false) / nominalKFactor);
                ggMass_NLOUp_EBEB_varbin->Fill(Diphoton_Minv,eventWeight*getKFactor(kFactor_NLOUp_EBEB,Diphoton_Minv) / nominalKFactor);
            }
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

            if (calcPDFWeights){
                for(int i=0; i<52; i++){
                    vec_pdfVar_ggMass_EBEE.at(i)->Fill( Diphoton_Minv,eventWeight*getPDFValue(Diphoton_Minv,EBEB,pdfVarEBEE.at(i)) );
                    vec_pdfVar_ggMass_EBEE_varbin.at(i)->Fill( Diphoton_Minv,eventWeight*getPDFValue(Diphoton_Minv,EBEB,pdfVarEBEE.at(i)) );
                    vec_pdfVar_ggMass_EBEE_30003500varbin.at(i)->Fill( Diphoton_Minv,eventWeight*getPDFValue(Diphoton_Minv,EBEB,pdfVarEBEE.at(i)) );
                }
                ggMass_renor0p5_EBEE->Fill( Diphoton_Minv,eventWeight );
                ggMass_renor2_EBEE->Fill( Diphoton_Minv,eventWeight );
                ggMass_fs0p5_EBEE->Fill( Diphoton_Minv,eventWeight*getKFactor(kFactor_fs0p5_EBEE,Diphoton_Minv) / nominalKFactor );
                ggMass_fs2_EBEE->Fill( Diphoton_Minv,eventWeight*getKFactor(kFactor_fs2_EBEE,Diphoton_Minv) / nominalKFactor );
                ggMass_NLODown_EBEE->Fill(Diphoton_Minv,eventWeight*getKFactor(kFactor_NLODown_EBEE,Diphoton_Minv,false) / nominalKFactor);
                ggMass_NLOUp_EBEE->Fill(Diphoton_Minv,eventWeight*getKFactor(kFactor_NLOUp_EBEE,Diphoton_Minv) / nominalKFactor);

                ggMass_renor0p5_EBEE_varbin->Fill( Diphoton_Minv,eventWeight );
                ggMass_renor2_EBEE_varbin->Fill( Diphoton_Minv,eventWeight );
                ggMass_fs0p5_EBEE_varbin->Fill( Diphoton_Minv,eventWeight*getKFactor(kFactor_fs0p5_EBEE,Diphoton_Minv) / nominalKFactor );
                ggMass_fs2_EBEE_varbin->Fill( Diphoton_Minv,eventWeight*getKFactor(kFactor_fs2_EBEE,Diphoton_Minv) / nominalKFactor );
                ggMass_NLODown_EBEE_varbin->Fill(Diphoton_Minv,eventWeight*getKFactor(kFactor_NLODown_EBEE,Diphoton_Minv,false) / nominalKFactor);
                ggMass_NLOUp_EBEE_varbin->Fill(Diphoton_Minv,eventWeight*getKFactor(kFactor_NLOUp_EBEE,Diphoton_Minv) / nominalKFactor);

            }
        } // end EBEE block
    } // end event loop
        
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
    hEventWeight->Write();
   
    pdfVarFileEBEB.Close();
    pdfVarFileEBEE.Close();

    f.Close();
} // end fTree2016::Loop() method
