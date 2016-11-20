#define fTree_cxx
#include "fTree.h"
#include "helperFunctions.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

// fits from Antonis
double getKFactor(double m, bool EBEB){

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

// pdf variation
double getPDFValue(double m, bool EBEB, TH1D* pdfHist){

    int binNum = pdfHist->FindBin(m);
    if (m >= 10100.) binNum = 100; //overflow was added to the last bin
    if (binNum == 0) binNum = 1; // map underflow to first bin
    if (EBEB && m < 230.) binNum = pdfHist->FindBin(230.);
    if (!EBEB && m < 320.) binNum = pdfHist->FindBin(320.);
    double content = pdfHist->GetBinContent(binNum);
    return content;

}


void fTree::Loop(TString outfilename, bool applyEventWeights=false)
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

    // Double_t bins_30003500[6] = {0.,600.,1100.,1800.,2600.,13000.};
    // Double_t bins[7] = {0.,600.,1100.,1800.,2600.,3500.,13000.};
    Double_t bins_30003500[6] = {0.,600.,1100.,1800.,2600.,13000.};
    Double_t bins[7] = {0.,600.,1100.,1800.,2600.,3500.,13000.};

    bool applyKFactor = outfilename.Contains("ADDPlots_GGJets") || outfilename.Contains("ADDPlots_Ms") || outfilename.Contains("ADDPlots_ADDBkg");

    TH1D* leadingPhoPt_EBEB = createTH1D("leadingPhoPt_EBEB","leadingPhoPt_EBEB",300.,0.,1500.,"Leading Photon pT (GeV/c)","Events");
    TH1D* subleadingPhoPt_EBEB = createTH1D("subleadingPhoPt_EBEB","subleadingPhoPt_EBEB",300,0.,1500.,"Subleading Photon pT (GeV/c)","Events");
    TH1D* leadingPhoEta_EBEB = createTH1D("leadingPhoEta_EBEB","leadingPhoEta_EBEB",100,-5.,5.,"Leading Photon #eta","Events");
    TH1D* subleadingPhoEta_EBEB = createTH1D("subleadingPhoEta_EBEB","subleadingPhoEta_EBEB",100,-5.,5.,"Subleading Photon #eta","Events");
    TH1D* leadingPhoPhi_EBEB = createTH1D("leadingPhoPhi_EBEB","leadingPhoPhi_EBEB",100,-3.141593,-3.141593,"Leading Photon #phi","Events");
    TH1D* subleadingPhoPhi_EBEB = createTH1D("subleadingPhoPhi_EBEB","subleadingPhoPhi_EBEB",100,-3.141593,-3.141593,"Subleading Photon #phi","Events");
    TH1D* ggMass_EBEB = createTH1D("ggMass_EBEB","ggMass_EBEB",651,-10.,13000.,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_EBEB_JPBinning = createTH1D("ggMass_EBEB_JPBinning","ggMass_EBEB",34,320.,1000.,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_EBEB_30003500varbin = createTH1D("ggMass_EBEB_30003500varbin","ggMass_EBEB_30003500varbin",5,bins_30003500,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_EBEB_varbin = createTH1D("ggMass_EBEB_varbin","ggMass_EBEB_varbin",6,bins,"m_{#gamma#gamma} (GeV/c^{2})","Events");

    TH1D* leadingPhoPt_EBEE = createTH1D("leadingPhoPt_EBEE","leadingPhoPt_EBEE",300.,0.,1500.,"Leading Photon pT (GeV/c)","Events");
    TH1D* subleadingPhoPt_EBEE = createTH1D("subleadingPhoPt_EBEE","subleadingPhoPt_EBEE",300,0.,1500.,"Subleading Photon pT (GeV/c)","Events");
    TH1D* leadingPhoEta_EBEE = createTH1D("leadingPhoEta_EBEE","leadingPhoEta_EBEE",100,-5.,5.,"Leading Photon #eta","Events");
    TH1D* subleadingPhoEta_EBEE = createTH1D("subleadingPhoEta_EBEE","subleadingPhoEta_EBEE",100,-5.,5.,"Subleading Photon #eta","Events");
    TH1D* leadingPhoPhi_EBEE = createTH1D("leadingPhoPhi_EBEE","leadingPhoPhi_EBEE",100,-3.141593,-3.141593,"Leading Photon #phi","Events");
    TH1D* subleadingPhoPhi_EBEE = createTH1D("subleadingPhoPhi_EBEE","subleadingPhoPhi_EBEE",100,-3.141593,-3.141593,"Subleading Photon #phi","Events");
    TH1D* ggMass_EBEE = createTH1D("ggMass_EBEE","ggMass_EBEE",651,-10.,13000.,"m_{#gamma#gamma} (GeV/c^{2})","Events");
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

    //scale variation
    TH1D* ggMass_fs0p5_EBEB = createTH1D("ggMass_fs0p5_EBEB","ggMass_fs0p5_EBEB",651,-10.,13000.,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_fs0p5_EBEB_30003500varbin = createTH1D("ggMass_fs0p5_EBEB_30003500varbin","ggMass_fs0p5_EBEB_30003500varbin",5,bins_30003500,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_fs0p5_EBEB_varbin = createTH1D("ggMass_fs0p5_EBEB_varbin","ggMass_fs0p5_EBEB_varbin",6,bins,"m_{#gamma#gamma} (GeV/c^{2})","Events");

    TH1D* ggMass_fs2_EBEB = createTH1D("ggMass_fs2_EBEB","ggMass_fs2_EBEB",651,-10.,13000.,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_fs2_EBEB_30003500varbin = createTH1D("ggMass_fs2_EBEB_30003500varbin","ggMass_fs2_EBEB_30003500varbin",5,bins_30003500,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_fs2_EBEB_varbin = createTH1D("ggMass_fs2_EBEB_varbin","ggMass_fs2_EBEB_varbin",6,bins,"m_{#gamma#gamma} (GeV/c^{2})","Events");

    TH1D* ggMass_renor0p5_EBEB = createTH1D("ggMass_renor0p5_EBEB","ggMass_renor0p5_EBEB",651,-10.,13000.,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_renor0p5_EBEB_30003500varbin = createTH1D("ggMass_renor0p5_EBEB_30003500varbin","ggMass_renor0p5_EBEB_30003500varbin",5,bins_30003500,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_renor0p5_EBEB_varbin = createTH1D("ggMass_renor0p5_EBEB_varbin","ggMass_renor0p5_EBEB_varbin",6,bins,"m_{#gamma#gamma} (GeV/c^{2})","Events");

    TH1D* ggMass_renor2_EBEB = createTH1D("ggMass_renor2_EBEB","ggMass_renor2_EBEB",651,-10.,13000.,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_renor2_EBEB_30003500varbin = createTH1D("ggMass_renor2_EBEB_30003500varbin","ggMass_renor2_EBEB_30003500varbin",5,bins_30003500,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_renor2_EBEB_varbin = createTH1D("ggMass_renor2_EBEB_varbin","ggMass_renor2_EBEB_varbin",6,bins,"m_{#gamma#gamma} (GeV/c^{2})","Events");

    TH1D* ggMass_fs0p5_EBEE = createTH1D("ggMass_fs0p5_EBEE","ggMass_fs0p5_EBEE",651,-10.,13000.,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_fs0p5_EBEE_30003500varbin = createTH1D("ggMass_fs0p5_EBEE_30003500varbin","ggMass_fs0p5_EBEE_30003500varbin",5,bins_30003500,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_fs0p5_EBEE_varbin = createTH1D("ggMass_fs0p5_EBEE_varbin","ggMass_fs0p5_EBEE_varbin",6,bins,"m_{#gamma#gamma} (GeV/c^{2})","Events");

    TH1D* ggMass_fs2_EBEE = createTH1D("ggMass_fs2_EBEE","ggMass_fs2_EBEE",651,-10.,13000.,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_fs2_EBEE_30003500varbin = createTH1D("ggMass_fs2_EBEE_30003500varbin","ggMass_fs2_EBEE_30003500varbin",5,bins_30003500,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_fs2_EBEE_varbin = createTH1D("ggMass_fs2_EBEE_varbin","ggMass_fs2_EBEE_varbin",6,bins,"m_{#gamma#gamma} (GeV/c^{2})","Events");

    TH1D* ggMass_renor0p5_EBEE = createTH1D("ggMass_renor0p5_EBEE","ggMass_renor0p5_EBEE",651,-10.,13000.,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_renor0p5_EBEE_30003500varbin = createTH1D("ggMass_renor0p5_EBEE_30003500varbin","ggMass_renor0p5_EBEE_30003500varbin",5,bins_30003500,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_renor0p5_EBEE_varbin = createTH1D("ggMass_renor0p5_EBEE_varbin","ggMass_renor0p5_EBEE_varbin",6,bins,"m_{#gamma#gamma} (GeV/c^{2})","Events");

    TH1D* ggMass_renor2_EBEE = createTH1D("ggMass_renor2_EBEE","ggMass_renor2_EBEE",651,-10.,13000.,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_renor2_EBEE_30003500varbin = createTH1D("ggMass_renor2_EBEE_30003500varbin","ggMass_renor2_EBEE_30003500varbin",5,bins_30003500,"m_{#gamma#gamma} (GeV/c^{2})","Events");
    TH1D* ggMass_renor2_EBEE_varbin = createTH1D("ggMass_renor2_EBEE_varbin","ggMass_renor2_EBEE_varbin",6,bins,"m_{#gamma#gamma} (GeV/c^{2})","Events");


    if (applyKFactor){

        // for the SM background: loop over pdf eigenvector number and create histograms
        for (int i=1; i<53; i++){

            vec_pdfVar_ggMass_EBEB.push_back( createTH1D( TString::Format("ggMass_EBEB_CT10_%i",i), TString::Format("ggMass_EBEB_CT10_%i",i),651,-10.,13000.,"m_{#gamma#gamma} (GeV/c^{2})","Events") );
            vec_pdfVar_ggMass_EBEB_varbin.push_back( createTH1D(TString::Format("ggMass_EBEB_varbin_CT10_%i",i), TString::Format("ggMass_EBEB_varbin_CT10_%i",i),6,bins,"m_{#gamma#gamma} (GeV/c^{2})","Events" ) ) ;
            vec_pdfVar_ggMass_EBEB_30003500varbin.push_back( createTH1D(TString::Format("ggMass_EBEB_30003500varbin_CT10_%i",i), TString::Format("ggMass_EBEB_30003500varbin_CT10_%i",i),5,bins_30003500,"m_{#gamma#gamma} (GeV/c^{2})","Events" ) );

            vec_pdfVar_ggMass_EBEE.push_back( createTH1D( TString::Format("ggMass_EBEE_CT10_%i",i), TString::Format("ggMass_EBEE_CT10_%i",i),651,-10.,13000.,"m_{#gamma#gamma} (GeV/c^{2})","Events") );
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
    } // end applyKFactor block

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

    // get all pdf variation histos
    std::vector<TH1D*> pdfVarEBEB;
    std::vector<TH1D*> pdfVarEBEE;

    TFile pdfVarFileEBEB("PDF_sys_NormScaling_BB_long.root","read");
    TFile pdfVarFileEBEE("PDF_sys_NormScaling_BE_long.root","read");
    TFile scaleVarFileEBEB("SYS_scaling_Renorm_and_factScale_h_M_BB_b17.root","read");
    TFile scaleVarFileEBEE("SYS_scaling_Renorm_and_factScale_h_M_BE_b17.root","read");

    for(int i=1; i<53; i++){
        TString histName = TString::Format("DIPHOX_PDF_o_DIPHOX_Default_%i",i);
        TH1D* histEBEB = (TH1D*)pdfVarFileEBEB.Get(histName);
        TH1D* histEBEE = (TH1D*)pdfVarFileEBEE.Get(histName);

        pdfVarEBEB.push_back(histEBEB);
        pdfVarEBEE.push_back(histEBEE);
    }

    TFile scaleVarFileEBEB("SYS_scaling_Renorm_and_factScale_h_M_BB_b17.root","read");
    TFile scaleVarFileEBEE("SYS_scaling_Renorm_and_factScale_h_M_BE_b17.root","read");

    TH1D* renor0p5_EBEB = (TH1D*)scaleVarFileEBEB.Get("DIPHOX_Renor0p5_o_DIPHOX_Default_h_M_BB_b17");
    TH1D* renor2_EBEB = (TH1D*)scaleVarFileEBEB.Get("DIPHOX_Renor2_o_DIPHOX_Default_h_M_BB_b17");
    TH1D* fs0p5_EBEB = (TH1D*)scaleVarFileEBEB.Get("DIPHOX_fs0p5_o_DIPHOX_Default_h_M_BB_b17");
    TH1D* fs2_EBEB = (TH1D*)scaleVarFileEBEB.Get("DIPHOX_fs2_o_DIPHOX_Default_h_M_BB_b17");

    TH1D* renor0p5_EBEE = (TH1D*)scaleVarFileEBEE.Get("DIPHOX_Renor0p5_o_DIPHOX_Default_h_M_BB_b17");
    TH1D* renor2_EBEE = (TH1D*)scaleVarFileEBEE.Get("DIPHOX_Renor2_o_DIPHOX_Default_h_M_BB_b17");
    TH1D* fs0p5_EBEE = (TH1D*)scaleVarFileEBEE.Get("DIPHOX_fs0p5_o_DIPHOX_Default_h_M_BB_b17");
    TH1D* fs2_EBEE = (TH1D*)scaleVarFileEBEE.Get("DIPHOX_fs2_o_DIPHOX_Default_h_M_BB_b17");

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
        const double LUMI = 2.691; // /fb

        if (applyEventWeights){
            eventWeight = (double)Event_weightAll*LUMI; 
            if (applyKFactor) eventWeight *= getKFactor(Diphoton_Minv,EBEB); // multiply SM diphoton bkg by k-factor; using RECO mass for now...

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

            if (applyKFactor){
                for(int i=0; i<52; i++){
                    vec_pdfVar_ggMass_EBEB.at(i)->Fill( Diphoton_Minv,eventWeight*getPDFValue(Diphoton_MinvEBEB,EBEB,pdfVarEBEB.at(i)) );
                    vec_pdfVar_ggMass_EBEB_varbin.at(i)->Fill( Diphoton_Minv,eventWeight*getPDFValue(Diphoton_MinvEBEB,EBEB,pdfVarEBEB.at(i)) );
                    vec_pdfVar_ggMass_EBEB_30003500varbin.at(i)->Fill( Diphoton_Minv,eventWeight*getPDFValue(Diphoton_MinvEBEB,EBEB,pdfVarEBEB.at(i)) );

                    ggMass_renor0p5_EBEB->Fill( Diphoton_Minv,eventWeight*getPDFValue(Diphoton_MinvEBEB,EBEB,renor0p5_EBEB );
                    ggMass_renor2_EBEB->Fill( Diphoton_Minv,eventWeight*getPDFValue(Diphoton_MinvEBEB,EBEB,renor2_EBEB );
                    ggMass_fs0p5_EBEB->Fill( Diphoton_Minv,eventWeight*getPDFValue(Diphoton_MinvEBEB,EBEB,fs0p5_EBEB );
                    ggMass_fs2_EBEB->Fill( Diphoton_Minv,eventWeight*getPDFValue(Diphoton_MinvEBEB,EBEB,fs2_EBEB );

                    ggMass_renor0p5_EBEB_varbin->Fill( Diphoton_Minv,eventWeight*getPDFValue(Diphoton_MinvEBEB,EBEB,renor0p5_EBEB );
                    ggMass_renor2_EBEB_varbin->Fill( Diphoton_Minv,eventWeight*getPDFValue(Diphoton_MinvEBEB,EBEB,renor2_EBEB );
                    ggMass_fs0p5_EBEB_varbin->Fill( Diphoton_Minv,eventWeight*getPDFValue(Diphoton_MinvEBEB,EBEB,fs0p5_EBEB );
                    ggMass_fs2_EBEB_varbin->Fill( Diphoton_Minv,eventWeight*getPDFValue(Diphoton_MinvEBEB,EBEB,fs2_EBEB );
                }
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

            if (applyKFactor){
                for(int i=0; i<52; i++){
                    vec_pdfVar_ggMass_EBEE.at(i)->Fill( Diphoton_Minv,eventWeight*getPDFValue(Diphoton_MinvEBEB,EBEB,pdfVarEBEE.at(i)) );
                    vec_pdfVar_ggMass_EBEE_varbin.at(i)->Fill( Diphoton_Minv,eventWeight*getPDFValue(Diphoton_MinvEBEB,EBEB,pdfVarEBEE.at(i)) );
                    vec_pdfVar_ggMass_EBEE_30003500varbin.at(i)->Fill( Diphoton_Minv,eventWeight*getPDFValue(Diphoton_MinvEBEB,EBEB,pdfVarEBEE.at(i)) );

                    ggMass_renor0p5_EBEE->Fill( Diphoton_Minv,eventWeight*getPDFValue(Diphoton_MinvEBEE,EBEB,renor0p5_EBEE );
                    ggMass_renor2_EBEE->Fill( Diphoton_Minv,eventWeight*getPDFValue(Diphoton_MinvEBEE,EBEB,renor2_EBEE );
                    ggMass_fs0p5_EBEE->Fill( Diphoton_Minv,eventWeight*getPDFValue(Diphoton_MinvEBEE,EBEB,fs0p5_EBEE );
                    ggMass_fs2_EBEE->Fill( Diphoton_Minv,eventWeight*getPDFValue(Diphoton_MinvEBEE,EBEB,fs2_EBEE );

                    ggMass_renor0p5_EBEE_varbin->Fill( Diphoton_Minv,eventWeight*getPDFValue(Diphoton_MinvEBEE,EBEB,renor0p5_EBEE );
                    ggMass_renor2_EBEE_varbin->Fill( Diphoton_Minv,eventWeight*getPDFValue(Diphoton_MinvEBEE,EBEB,renor2_EBEE );
                    ggMass_fs0p5_EBEE_varbin->Fill( Diphoton_Minv,eventWeight*getPDFValue(Diphoton_MinvEBEE,EBEB,fs0p5_EBEE );
                    ggMass_fs2_EBEE_varbin->Fill( Diphoton_Minv,eventWeight*getPDFValue(Diphoton_MinvEBEE,EBEB,fs2_EBEE );
                }

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
    if (applyKFactor){
        for(int i=0; i<52; i++){
            vec_pdfVar_ggMass_EBEB.at(i)->Write();
            vec_pdfVar_ggMass_EBEB_varbin.at(i)->Write();
            vec_pdfVar_ggMass_EBEB_30003500varbin.at(i)->Write();

            vec_pdfVar_ggMass_EBEE.at(i)->Write();
            vec_pdfVar_ggMass_EBEE_varbin.at(i)->Write();
            vec_pdfVar_ggMass_EBEE_30003500varbin.at(i)->Write();
        }
    }
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
    scaleVarFileEBEB.Close();
    scaleVarFileEBEE.Close();
    f.Close();
} // end fTree::Loop() method
