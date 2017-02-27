#define extractFakeContributions_cxx
#include "extractFakeContributions.h"
#include "helperFunctions.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <map>

enum fakeRateSys{
  kNoSys  = 0,
  kEBDown = 1,
  kEBUp   = 2,
  kEEDown = 3,
  kEEUp   = 4
};

std::map<int,double> sysFactorMap = {{0,1.},{1,0.676678226209},{2,1.12166201919},{3,0.663347777029},{4,1.05608960856}};
// sysFactorMap[0] = 1.;
// sysFactorMap[1] = 0.65;
// sysFactorMap[2] = 1.16;
// sysFactorMap[3] = 0.7;
// sysFactorMap[4] = 1.08;

double getEffCorr(double pt, TH1D* hist){
  int binNum = hist->FindBin(pt);
  double eff = hist->GetBinContent(binNum);
  if (eff == 0.) eff = 1.; //this only happens at high pT where we're just limited by statistics, but should be fully efficient
  return 1./eff;
}
double getFakeRate(double pt, double eta){

    // fake rate in the barrel
    if ( isEB(eta) ){
       // double P0 = 0.00225252571161;
       // double P1 = 30882.04375711645480;
       // double P2 = 3.25285076412319;
       double P0 = 0.02854062423359;
       double P1 = 1054.67561386442435;
       double P2 = 2.43255894722459;
       return P0 + ( P1 / TMath::Power(pt,P2) );
    }
    // fake rate in the endcaps
    else if ( isEE(eta) ){
      if (pt <= 175.){
        // double P0 = 0.00984487675098;
        // double P1 = 0.00001462335960;
        // double P2 = 0.00000249248908;
        double P0 = 0.07583295145724;
        double P1 = 0.00003927399330;
        double P2 = 0.00000255676015;
        return P0 + P1*(pt-175.) + P2*(pt-175.)*(pt-175.);
      }
      else{
        // double slope = 0.00001462335960;
        // double yint = 0.00728578882033;
        double slope = 0.00003927399330;
        double yint = 0.06896000263001;
        return yint + slope*pt;
      }
    }
    else return 0.;
}

void extractFakeContributions::Loop()
{
//   In a ROOT session, you can do:
//      root> .L extractFakeContributions.C
//      root> extractFakeContributions t
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

    Double_t bins_30003500[6] = {0.,600.,1100.,1800.,2600.,13000.};
    Double_t bins[7] = {0.,600.,1100.,1800.,2600.,3500.,13000.};

    TH1D* justtlMass_EBEB = createTH1D("justtlMass_EBEB","justtlMass_EBEB",650,0.,13000.,"m_{Tight-Loose} (GeV/c^{2})","Events");
    TH1D* ltMass_EBEB = createTH1D("ltMass_EBEB","ltMass_EBEB",650,0.,13000.,"m_{Loose-Tight} (GeV/c^{2})","Events");
    TH1D* tlMass_EBEB = createTH1D("tlMass_EBEB","tlMass_EBEB",650,0.,13000.,"m_{Tight-Loose} (GeV/c^{2})","Events");
    TH1D* llMass_EBEB = createTH1D("llMass_EBEB","llMass_EBEB",650,0.,13000.,"m_{Loose-Loose} (GeV/c^{2})","Events");
    TH1D* ffMass_EBEB = createTH1D("ffMass_EBEB","ffMass_EBEB",650,0.,13000.,"m_{fake} (GeV/c^{2})","Events");
    TH1D* justtlMass_EBEE = createTH1D("justtlMass_EBEE","justtlMass_EBEE",650,0.,13000.,"m_{Tight-Loose} (GeV/c^{2})","Events");
    TH1D* ltMass_EBEE = createTH1D("ltMass_EBEE","ltMass_EBEE",650,0.,13000.,"m_{Loose-Tight} (GeV/c^{2})","Events");
    TH1D* tlMass_EBEE = createTH1D("tlMass_EBEE","tlMass_EBEE",650,0.,13000.,"m_{Tight-Loose} (GeV/c^{2})","Events");
    TH1D* llMass_EBEE = createTH1D("llMass_EBEE","llMass_EBEE",650,0.,13000.,"m_{Loose-Loose} (GeV/c^{2})","Events");
    TH1D* ffMass_EBEE = createTH1D("ffMass_EBEE","ffMass_EBEE",650,0.,13000.,"m_{fake} (GeV/c^{2})","Events");

    TH1D* justtlMass_EBEB_30003500varbin = createTH1D("justtlMass_EBEB_30003500varbin","justtlMass_EBEB",5,bins_30003500,"m_{Tight-Loose} (GeV/c^{2})","Events");
    TH1D* ltMass_EBEB_30003500varbin = createTH1D("ltMass_EBEB_30003500varbin","ltMass_EBEB",5,bins_30003500,"m_{Loose-Tight} (GeV/c^{2})","Events");
    TH1D* tlMass_EBEB_30003500varbin = createTH1D("tlMass_EBEB_30003500varbin","tlMass_EBEB",5,bins_30003500,"m_{Tight-Loose} (GeV/c^{2})","Events");
    TH1D* llMass_EBEB_30003500varbin = createTH1D("llMass_EBEB_30003500varbin","llMass_EBEB",5,bins_30003500,"m_{Loose-Loose} (GeV/c^{2})","Events");
    TH1D* ffMass_EBEB_30003500varbin = createTH1D("ffMass_EBEB_30003500varbin","ffMass_EBEB",5,bins_30003500,"m_{fake} (GeV/c^{2})","Events");
    TH1D* justtlMass_EBEE_30003500varbin = createTH1D("justtlMass_EBEE_30003500varbin","justtlMass_EBEE",5,bins_30003500,"m_{Tight-Loose} (GeV/c^{2})","Events");
    TH1D* ltMass_EBEE_30003500varbin = createTH1D("ltMass_EBEE_30003500varbin","ltMass_EBEE",5,bins_30003500,"m_{Loose-Tight} (GeV/c^{2})","Events");
    TH1D* tlMass_EBEE_30003500varbin = createTH1D("tlMass_EBEE_30003500varbin","tlMass_EBEE",5,bins_30003500,"m_{Tight-Loose} (GeV/c^{2})","Events");
    TH1D* llMass_EBEE_30003500varbin = createTH1D("llMass_EBEE_30003500varbin","llMass_EBEE",5,bins_30003500,"m_{Loose-Loose} (GeV/c^{2})","Events");
    TH1D* ffMass_EBEE_30003500varbin = createTH1D("ffMass_EBEE_30003500varbin","ffMass_EBEE",5,bins_30003500,"m_{fake} (GeV/c^{2})","Events");

    TH1D* justtlMass_EBEB_varbin = createTH1D("justtlMass_EBEB_varbin","justtlMass_EBEB",6,bins,"m_{Tight-Loose} (GeV/c^{2})","Events");
    TH1D* ltMass_EBEB_varbin = createTH1D("ltMass_EBEB_varbin","ltMass_EBEB",6,bins,"m_{Loose_Tight} (GeV/c^{2})","Events");
    TH1D* tlMass_EBEB_varbin = createTH1D("tlMass_EBEB_varbin","tlMass_EBEB",6,bins,"m_{Tight-Loose} (GeV/c^{2})","Events");
    TH1D* llMass_EBEB_varbin = createTH1D("llMass_EBEB_varbin","llMass_EBEB",6,bins,"m_{Loose-Loose} (GeV/c^{2})","Events");
    TH1D* ffMass_EBEB_varbin = createTH1D("ffMass_EBEB_varbin","ffMass_EBEB",6,bins,"m_{fake} (GeV/c^{2})","Events");
    TH1D* justtlMass_EBEE_varbin = createTH1D("justtlMass_EBEE_varbin","justtlMass_EBEE",6,bins,"m_{Tight-Loose} (GeV/c^{2})","Events");
    TH1D* ltMass_EBEE_varbin = createTH1D("ltMass_EBEE_varbin","ltMass_EBEE",6,bins,"m_{Loose_Tight} (GeV/c^{2})","Events");
    TH1D* tlMass_EBEE_varbin = createTH1D("tlMass_EBEE_varbin","tlMass_EBEE",6,bins,"m_{Tight-Loose} (GeV/c^{2})","Events");
    TH1D* llMass_EBEE_varbin = createTH1D("llMass_EBEE_varbin","llMass_EBEE",6,bins,"m_{Loose-Loose} (GeV/c^{2})","Events");
    TH1D* ffMass_EBEE_varbin = createTH1D("ffMass_EBEE_varbin","ffMass_EBEE",6,bins,"m_{fake} (GeV/c^{2})","Events");

    TH1D* justgjMass_EBEB = createTH1D("justgjMass_EBEB","justgjMass_EBEB",650,0.,13000.,"m_{#gamma+jet} (GeV/c^{2})","Events");
    TH1D* jgMass_EBEB = createTH1D("jgMass_EBEB","jgMass_EBEB",650,0.,13000.,"m_{jet+#gamma} (GeV/c^{2})","Events");
    TH1D* gjMass_EBEB = createTH1D("gjMass_EBEB","gjMass_EBEB",650,0.,13000.,"m_{#gamma+jet} (GeV/c^{2})","Events");
    TH1D* jjMass_EBEB = createTH1D("jjMass_EBEB","jjMass_EBEB",650,0.,13000.,"m_{jet+jet} (GeV/c^{2})","Events");
    TH1D* fakeMass_EBEB = createTH1D("fakeMass_EBEB","fakeMass_EBEB",650,0.,13000.,"m_{fake} (GeV/c^{2})","Events");
    TH1D* justgjMass_EBEE = createTH1D("justgjMass_EBEE","justgjMass_EBEE",650,0.,13000.,"m_{#gamma+jet} (GeV/c^{2})","Events");
    TH1D* jgMass_EBEE = createTH1D("jgMass_EBEE","jgMass_EBEE",650,0.,13000.,"m_{jet+#gamma} (GeV/c^{2})","Events");
    TH1D* gjMass_EBEE = createTH1D("gjMass_EBEE","gjMass_EBEE",650,0.,13000.,"m_{#gamma+jet} (GeV/c^{2})","Events");
    TH1D* jjMass_EBEE = createTH1D("jjMass_EBEE","jjMass_EBEE",650,0.,13000.,"m_{jet+jet} (GeV/c^{2})","Events");
    TH1D* fakeMass_EBEE = createTH1D("fakeMass_EBEE","fakeMass_EBEE",650,0.,13000.,"m_{fake} (GeV/c^{2})","Events");

    TH1D* justgjMass_EBEB_30003500varbin = createTH1D("justgjMass_EBEB_30003500varbin","justgjMass_EBEB",5,bins_30003500,"m_{#gamma+jet} (GeV/c^{2})","Events");
    TH1D* jgMass_EBEB_30003500varbin = createTH1D("jgMass_EBEB_30003500varbin","jgMass_EBEB",5,bins_30003500,"m_{jet+#gamma} (GeV/c^{2})","Events");
    TH1D* gjMass_EBEB_30003500varbin = createTH1D("gjMass_EBEB_30003500varbin","gjMass_EBEB",5,bins_30003500,"m_{#gamma+jet} (GeV/c^{2})","Events");
    TH1D* jjMass_EBEB_30003500varbin = createTH1D("jjMass_EBEB_30003500varbin","jjMass_EBEB",5,bins_30003500,"m_{jet+jet} (GeV/c^{2})","Events");
    TH1D* fakeMass_EBEB_30003500varbin = createTH1D("fakeMass_EBEB_30003500varbin","fakeMass_EBEB",5,bins_30003500,"m_{fake} (GeV/c^{2})","Events");
    TH1D* justgjMass_EBEE_30003500varbin = createTH1D("justgjMass_EBEE_30003500varbin","justgjMass_EBEE",5,bins_30003500,"m_{#gamma+jet} (GeV/c^{2})","Events");
    TH1D* jgMass_EBEE_30003500varbin = createTH1D("jgMass_EBEE_30003500varbin","jgMass_EBEE",5,bins_30003500,"m_{jet+#gamma} (GeV/c^{2})","Events");
    TH1D* gjMass_EBEE_30003500varbin = createTH1D("gjMass_EBEE_30003500varbin","gjMass_EBEE",5,bins_30003500,"m_{#gamma+jet} (GeV/c^{2})","Events");
    TH1D* jjMass_EBEE_30003500varbin = createTH1D("jjMass_EBEE_30003500varbin","jjMass_EBEE",5,bins_30003500,"m_{jet+jet} (GeV/c^{2})","Events");
    TH1D* fakeMass_EBEE_30003500varbin = createTH1D("fakeMass_EBEE_30003500varbin","fakeMass_EBEE",5,bins_30003500,"m_{fake} (GeV/c^{2})","Events");

    TH1D* justgjMass_EBEB_varbin = createTH1D("justgjMass_EBEB_varbin","justgjMass_EBEB",6,bins,"m_{#gamma+jet} (GeV/c^{2})","Events");
    TH1D* jgMass_EBEB_varbin = createTH1D("jgMass_EBEB_varbin","jgMass_EBEB",6,bins,"m_{jet+#gamma} (GeV/c^{2})","Events");
    TH1D* gjMass_EBEB_varbin = createTH1D("gjMass_EBEB_varbin","gjMass_EBEB",6,bins,"m_{#gamma+jet} (GeV/c^{2})","Events");
    TH1D* jjMass_EBEB_varbin = createTH1D("jjMass_EBEB_varbin","jjMass_EBEB",6,bins,"m_{jet+jet} (GeV/c^{2})","Events");
    TH1D* fakeMass_EBEB_varbin = createTH1D("fakeMass_EBEB_varbin","fakeMass_EBEB",6,bins,"m_{fake} (GeV/c^{2})","Events");
    TH1D* justgjMass_EBEE_varbin = createTH1D("justgjMass_EBEE_varbin","justgjMass_EBEE",6,bins,"m_{#gamma+jet} (GeV/c^{2})","Events");
    TH1D* jgMass_EBEE_varbin = createTH1D("jgMass_EBEE_varbin","jgMass_EBEE",6,bins,"m_{jet+#gamma} (GeV/c^{2})","Events");
    TH1D* gjMass_EBEE_varbin = createTH1D("gjMass_EBEE_varbin","gjMass_EBEE",6,bins,"m_{#gamma+jet} (GeV/c^{2})","Events");
    TH1D* jjMass_EBEE_varbin = createTH1D("jjMass_EBEE_varbin","jjMass_EBEE",6,bins,"m_{jet+jet} (GeV/c^{2})","Events");
    TH1D* fakeMass_EBEE_varbin = createTH1D("fakeMass_EBEE_varbin","fakeMass_EBEE",6,bins,"m_{fake} (GeV/c^{2})","Events");

    // systematics
    TH1D* fakeMass_EBEB_EBUp = createTH1D("fakeMass_EBEB_EBUp","fakeMass_EBEB",650,0.,13000.,"m_{fake} (GeV/c^{2})","Events");
    TH1D* fakeMass_EBEB_EBDown = createTH1D("fakeMass_EBEB_EBDown","fakeMass_EBEB",650,0.,13000.,"m_{fake} (GeV/c^{2})","Events");

    TH1D* fakeMass_EBEE_EBUp = createTH1D("fakeMass_EBEE_EBUp","fakeMass_EBEE",650,0.,13000.,"m_{fake} (GeV/c^{2})","Events");
    TH1D* fakeMass_EBEE_EBDown = createTH1D("fakeMass_EBEE_EBDown","fakeMass_EBEE",650,0.,13000.,"m_{fake} (GeV/c^{2})","Events");
    TH1D* fakeMass_EBEE_EEUp = createTH1D("fakeMass_EBEE_EEUp","fakeMass_EBEE",650,0.,13000.,"m_{fake} (GeV/c^{2})","Events");
    TH1D* fakeMass_EBEE_EEDown = createTH1D("fakeMass_EBEE_EEDown","fakeMass_EBEE",650,0.,13000.,"m_{fake} (GeV/c^{2})","Events");

    TH1D* fakeMass_EBEB_EBUp_varbin = createTH1D("fakeMass_EBEB_EBUp_varbin","fakeMass_EBEB",6,bins,"m_{fake} (GeV/c^{2})","Events");
    TH1D* fakeMass_EBEB_EBDown_varbin = createTH1D("fakeMass_EBEB_EBDown_varbin","fakeMass_EBEB",6,bins,"m_{fake} (GeV/c^{2})","Events");

    TH1D* fakeMass_EBEE_EBUp_varbin = createTH1D("fakeMass_EBEE_EBUp_varbin","fakeMass_EBEE",6,bins,"m_{fake} (GeV/c^{2})","Events");
    TH1D* fakeMass_EBEE_EBDown_varbin = createTH1D("fakeMass_EBEE_EBDown_varbin","fakeMass_EBEE",6,bins,"m_{fake} (GeV/c^{2})","Events");
    TH1D* fakeMass_EBEE_EEUp_varbin = createTH1D("fakeMass_EBEE_EEUp_varbin","fakeMass_EBEE",6,bins,"m_{fake} (GeV/c^{2})","Events");
    TH1D* fakeMass_EBEE_EEDown_varbin = createTH1D("fakeMass_EBEE_EEDown_varbin","fakeMass_EBEE",6,bins,"m_{fake} (GeV/c^{2})","Events");



    // ofstream allstream_EBEB("all_EBEB.txt");
    // ofstream gjstream_EBEB("gj_EBEB.txt");
    // ofstream jgstream_EBEB("jg_EBEB.txt");

    // ofstream allstream_EBEE("all_EBEE.txt");
    // ofstream gjstream_EBEE("gj_EBEE.txt");
    // ofstream jgstream_EBEE("jg_EBEE.txt");

    // ofstream gjstream_EEEB("gj_EEEB.txt");
    // ofstream jgstream_EEEB("jg_EEEB.txt");

    // ofstream jjstream_EBEB("jj_EBEB.txt");
    // ofstream jjstream_EBEE("jj_EBEE.txt");
    // ofstream jjstream_EEEB("jj_EEEB.txt");

    // fake efficiency histos
    // TFile effFile("hadronicOverEmEffPlots_20152016_pt75.root","read");
    // TH1D* effTF_pt1_EBEB = (TH1D*)effFile.Get("effTF_loose_hadronicOverEm010_pt1_EBEB");
    // TH1D* effTF_pt2_EBEB = (TH1D*)effFile.Get("effTF_loose_hadronicOverEm010_pt2_EBEB");
    // TH1D* effTF_pt1_EBEE = (TH1D*)effFile.Get("effTF_loose_hadronicOverEm010_pt1_EBEE");
    // TH1D* effTF_pt2_EBEE = (TH1D*)effFile.Get("effTF_loose_hadronicOverEm010_pt2_EBEE");

    // TH1D* effFF_pt1_EBEB = (TH1D*)effFile.Get("effFF_loose_hadronicOverEm010_pt1_EBEB");
    // TH1D* effFF_pt2_EBEB = (TH1D*)effFile.Get("effFF_loose_hadronicOverEm010_pt2_EBEB");
    // TH1D* effFF_pt1_EBEE = (TH1D*)effFile.Get("effFF_loose_hadronicOverEm010_pt1_EBEE");
    // TH1D* effFF_pt2_EBEE = (TH1D*)effFile.Get("effFF_loose_hadronicOverEm010_pt2_EBEE");

    if (fChain == 0) return;

    Long64_t nentries = fChain->GetEntriesFast();

    Long64_t nbytes = 0, nb = 0;
    for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      if (jentry % 1000 == 0) cout << "Now analyzing entry #" << jentry << endl;
      // if (jentry > 800000) break;

      if (TriggerBit_HLT_DoublePhoton60 != 1) continue;

      bool TL = isTF && TFPhoton2_hadronicOverEm < 0.10;
      bool LT = isFT && FTPhoton1_hadronicOverEm < 0.10;
      bool LL = isFF && FFPhoton1_hadronicOverEm < 0.10 && FFPhoton2_hadronicOverEm < 0.10;

      // bool TL = isTF && TFPhoton2_hadronicOverEm < 0.10 && TFPhoton1_isEE;
      // bool LT = isFT && FTPhoton1_hadronicOverEm < 0.10 && FTPhoton1_isEE;
      // bool LL = isFF && FFPhoton1_hadronicOverEm < 0.10 && FFPhoton2_hadronicOverEm < 0.10 && FFPhoton1_isEE;

      // pt cuts
      if (TL && (TFPhoton1_pt<130. || TFPhoton2_pt<130.)) continue;
      if (LT && (FTPhoton1_pt<130. || FTPhoton2_pt<130.)) continue;
      if (LL && (FFPhoton1_pt<130. || FFPhoton2_pt<130.)) continue;

      // mass cuts
      if (TL && TFDiphoton_isEBEB && TFDiphoton_Minv < 230.) continue;
      if (LT && FTDiphoton_isEBEB && FTDiphoton_Minv < 230.) continue;
      if (LL && FFDiphoton_isEBEB && FFDiphoton_Minv < 230.) continue;

      if (TL && (TFDiphoton_isEEEB||TFDiphoton_isEBEE) && TFDiphoton_Minv < 320.) continue;
      if (LT && (FTDiphoton_isEEEB||FTDiphoton_isEBEE) && FTDiphoton_Minv < 320.) continue;
      if (LL && (FFDiphoton_isEEEB||FFDiphoton_isEBEE) && FFDiphoton_Minv < 320.) continue;
      
      // if (TL){
      //   double fakeRate = getFakeRate(TFPhoton2_pt,TFPhoton2_scEta);
      //   double ggMass = TFDiphoton_Minv;
      //   bool isEBEB = TFPhoton1_isEB && TFPhoton2_isEB;
      //   bool isEBEE = (TFPhoton1_isEB && TFPhoton2_isEE) || (TFPhoton1_isEE && TFPhoton2_isEB);
      //   if (isEBEB){
      //     justtlMass_EBEB->Fill(ggMass);
      //     justtlMass_EBEB_varbin->Fill(ggMass);
      //     justtlMass_EBEB_30003500varbin->Fill(ggMass);

      //     justgjMass_EBEB->Fill(ggMass,fakeRate);
      //     justgjMass_EBEB_varbin->Fill(ggMass,fakeRate);
      //     justgjMass_EBEB_30003500varbin->Fill(ggMass,fakeRate);

      //   }
      //   else if (isEBEE){
      //     // cout << "***************************************" << endl;
      //     // cout << "Event #" << jentry << " is TL and EBEE!" << endl;
      //     // cout << "mgg = " << ggMass << endl;
      //     // cout << "fr = " << fakeRate << endl;
      //     // cout << "fake pt,eta = " << TFPhoton2_pt << ", " << TFPhoton2_scEta << endl;
      //     // cout << "***************************************" << endl;
      //     justtlMass_EBEE->Fill(ggMass);
      //     justtlMass_EBEE_varbin->Fill(ggMass);
      //     justtlMass_EBEE_30003500varbin->Fill(ggMass);        

      //     justgjMass_EBEE->Fill(ggMass,fakeRate);
      //     justgjMass_EBEE_varbin->Fill(ggMass,fakeRate);
      //     justgjMass_EBEE_30003500varbin->Fill(ggMass,fakeRate);

      //   }
      // } // end TL contribution
      // if (LT){
      //   double fakeRate = getFakeRate(FTPhoton1_pt,FTPhoton1_scEta);
      //   double ggMass = FTDiphoton_Minv;
      //   bool isEBEB = FTPhoton1_isEB && FTPhoton2_isEB;
      //   bool isEBEE = (FTPhoton1_isEB && FTPhoton2_isEE) || (FTPhoton1_isEE && FTPhoton2_isEB);
      //   if (isEBEB){
      //     ltMass_EBEB->Fill(ggMass);
      //     ltMass_EBEB_varbin->Fill(ggMass);
      //     ltMass_EBEB_30003500varbin->Fill(ggMass);

      //     jgMass_EBEB->Fill(ggMass,fakeRate);
      //     jgMass_EBEB_varbin->Fill(ggMass,fakeRate);
      //     jgMass_EBEB_30003500varbin->Fill(ggMass,fakeRate);

      //   }
      //   else if (isEBEE){
      //     // cout << "***************************************" << endl;
      //     // cout << "Event #" << jentry << " is LT and EBEE!" << endl;
      //     // cout << "mgg = " << ggMass << endl;
      //     // cout << "fr = " << fakeRate << endl;
      //     // cout << "fake pt,eta = " << FTPhoton1_pt << ", " << FTPhoton1_scEta << endl;
      //     // cout << "***************************************" << endl;

      //     ltMass_EBEE->Fill(ggMass);
      //     ltMass_EBEE_varbin->Fill(ggMass);
      //     ltMass_EBEE_30003500varbin->Fill(ggMass);        

      //     jgMass_EBEE->Fill(ggMass,fakeRate);
      //     jgMass_EBEE_varbin->Fill(ggMass,fakeRate);
      //     jgMass_EBEE_30003500varbin->Fill(ggMass,fakeRate);

      //   }
      // } // end LT contribution

      // TL+LT contribution
      int counter = 0;
      if (TL || LT){
        double fakeRate;
        double ggMass;
        bool isEBEB;
        bool isEBEE;
        // bool effCorr = getEffCorr(Photon2_pt,);
        if (TL){
            fakeRate = getFakeRate(TFPhoton2_pt,TFPhoton2_scEta);
            ggMass = TFDiphoton_Minv;
            isEBEB = TFDiphoton_isEBEB;
            // isEBEE = (TFPhoton1_isEB && TFPhoton2_isEE) || (TFPhoton1_isEE && TFPhoton2_isEB);
            isEBEE = TFDiphoton_isEEEB || TFDiphoton_isEBEE;
        }
        else if (LT){
            fakeRate = getFakeRate(FTPhoton1_pt,FTPhoton1_scEta);
            ggMass = FTDiphoton_Minv;
            isEBEB = FTDiphoton_isEBEB;
            // isEBEE = (FTPhoton1_isEB && FTPhoton2_isEE) || (FTPhoton1_isEE && FTPhoton2_isEB);
            isEBEE = FTDiphoton_isEEEB || FTDiphoton_isEBEE;
        }
        if (isEBEB){
            counter++;
            // if (600. < ggMass && ggMass < 1100.) cout << fakeRate << endl;
            tlMass_EBEB->Fill(ggMass);
            tlMass_EBEB_varbin->Fill(ggMass);
            tlMass_EBEB_30003500varbin->Fill(ggMass);

            ffMass_EBEB->Fill(ggMass);
            ffMass_EBEB_varbin->Fill(ggMass);
            ffMass_EBEB_30003500varbin->Fill(ggMass);

            gjMass_EBEB->Fill(ggMass,fakeRate);
            gjMass_EBEB_varbin->Fill(ggMass,fakeRate);
            gjMass_EBEB_30003500varbin->Fill(ggMass,fakeRate);

            fakeMass_EBEB->Fill(ggMass,fakeRate);
            fakeMass_EBEB_varbin->Fill(ggMass,fakeRate);
            fakeMass_EBEB_30003500varbin->Fill(ggMass,fakeRate);

            fakeMass_EBEB_EBUp->Fill(ggMass,fakeRate*sysFactorMap[fakeRateSys::kEBUp]);
            fakeMass_EBEB_EBDown->Fill(ggMass,fakeRate*sysFactorMap[fakeRateSys::kEBDown]);
            fakeMass_EBEB_EBUp_varbin->Fill(ggMass,fakeRate*sysFactorMap[fakeRateSys::kEBUp]);
            fakeMass_EBEB_EBDown_varbin->Fill(ggMass,fakeRate*sysFactorMap[fakeRateSys::kEBDown]);

            // allstream_EBEB << ggMass << " " << fakeRate << "\n";

            if (TL){
              counter++;
              justtlMass_EBEB->Fill(ggMass);
              justtlMass_EBEB_varbin->Fill(ggMass);
              justtlMass_EBEB_30003500varbin->Fill(ggMass);

              justgjMass_EBEB->Fill(ggMass,fakeRate);
              justgjMass_EBEB_varbin->Fill(ggMass,fakeRate);
              justgjMass_EBEB_30003500varbin->Fill(ggMass,fakeRate);

              // gjstream_EBEB << ggMass << " " << fakeRate << "\n";

            }
            else if (LT){
              counter++;
              ltMass_EBEB->Fill(ggMass);
              ltMass_EBEB_varbin->Fill(ggMass);
              ltMass_EBEB_30003500varbin->Fill(ggMass);

              jgMass_EBEB->Fill(ggMass,fakeRate);
              jgMass_EBEB_varbin->Fill(ggMass,fakeRate);
              jgMass_EBEB_30003500varbin->Fill(ggMass,fakeRate);

              // jgstream_EBEB << ggMass << " " << fakeRate << "\n";

            }

        }
        else if (isEBEE){
          // cout << "***************************************" << endl;
          // cout << "Event #" << jentry << " is TL||LT and EBEE!" << endl;
          // cout << "mgg = " << ggMass << endl;
          // cout << "fr = " << fakeRate << endl;
          // cout << "***************************************" << endl;
          // cout << " " << endl;
            counter++;
            tlMass_EBEE->Fill(ggMass);
            tlMass_EBEE_varbin->Fill(ggMass);
            tlMass_EBEE_30003500varbin->Fill(ggMass);

            ffMass_EBEE->Fill(ggMass);
            ffMass_EBEE_varbin->Fill(ggMass);
            ffMass_EBEE_30003500varbin->Fill(ggMass);            

            gjMass_EBEE->Fill(ggMass,fakeRate);
            gjMass_EBEE_varbin->Fill(ggMass,fakeRate);
            gjMass_EBEE_30003500varbin->Fill(ggMass,fakeRate);

            fakeMass_EBEE->Fill(ggMass,fakeRate);
            fakeMass_EBEE_varbin->Fill(ggMass,fakeRate);
            fakeMass_EBEE_30003500varbin->Fill(ggMass,fakeRate);

            // allstream_EBEE << ggMass << " " << fakeRate << "\n";

            if (TL){
              counter++;
              justtlMass_EBEE->Fill(ggMass);
              justtlMass_EBEE_varbin->Fill(ggMass);
              justtlMass_EBEE_30003500varbin->Fill(ggMass);

              justgjMass_EBEE->Fill(ggMass,fakeRate);
              justgjMass_EBEE_varbin->Fill(ggMass,fakeRate);
              justgjMass_EBEE_30003500varbin->Fill(ggMass,fakeRate);

              if (TFDiphoton_isEEEB){
                fakeMass_EBEE_EBUp->Fill(ggMass,fakeRate*sysFactorMap[fakeRateSys::kEBUp]);
                fakeMass_EBEE_EBDown->Fill(ggMass,fakeRate*sysFactorMap[fakeRateSys::kEBDown]);
                fakeMass_EBEE_EBUp_varbin->Fill(ggMass,fakeRate*sysFactorMap[fakeRateSys::kEBUp]);
                fakeMass_EBEE_EBDown_varbin->Fill(ggMass,fakeRate*sysFactorMap[fakeRateSys::kEBDown]);

                fakeMass_EBEE_EEUp->Fill(ggMass,fakeRate);
                fakeMass_EBEE_EEDown->Fill(ggMass,fakeRate);
                fakeMass_EBEE_EEUp_varbin->Fill(ggMass,fakeRate);
                fakeMass_EBEE_EEDown_varbin->Fill(ggMass,fakeRate);

              }
              else if (TFDiphoton_isEBEE){
                fakeMass_EBEE_EEUp->Fill(ggMass,fakeRate*sysFactorMap[fakeRateSys::kEEUp]);
                fakeMass_EBEE_EEDown->Fill(ggMass,fakeRate*sysFactorMap[fakeRateSys::kEEDown]);

                fakeMass_EBEE_EEUp_varbin->Fill(ggMass,fakeRate*sysFactorMap[fakeRateSys::kEEUp]);
                fakeMass_EBEE_EEDown_varbin->Fill(ggMass,fakeRate*sysFactorMap[fakeRateSys::kEEDown]);

                fakeMass_EBEE_EBUp->Fill(ggMass,fakeRate);
                fakeMass_EBEE_EBDown->Fill(ggMass,fakeRate);
                fakeMass_EBEE_EBUp_varbin->Fill(ggMass,fakeRate);
                fakeMass_EBEE_EBDown_varbin->Fill(ggMass,fakeRate);

              }
              // if (TFDiphoton_isEBEE) gjstream_EBEE << ggMass << " " << fakeRate << "\n";
              // else if (TFDiphoton_isEEEB) gjstream_EEEB << ggMass << " " << fakeRate << "\n";

            }
            else if (LT){
              counter++;
              ltMass_EBEE->Fill(ggMass);
              ltMass_EBEE_varbin->Fill(ggMass);
              ltMass_EBEE_30003500varbin->Fill(ggMass);

              jgMass_EBEE->Fill(ggMass,fakeRate);
              jgMass_EBEE_varbin->Fill(ggMass,fakeRate);
              jgMass_EBEE_30003500varbin->Fill(ggMass,fakeRate);

              if (FTDiphoton_isEBEE){
                fakeMass_EBEE_EBUp->Fill(ggMass,fakeRate*sysFactorMap[fakeRateSys::kEBUp]);
                fakeMass_EBEE_EBDown->Fill(ggMass,fakeRate*sysFactorMap[fakeRateSys::kEBDown]);
                fakeMass_EBEE_EBUp_varbin->Fill(ggMass,fakeRate*sysFactorMap[fakeRateSys::kEBUp]);
                fakeMass_EBEE_EBDown_varbin->Fill(ggMass,fakeRate*sysFactorMap[fakeRateSys::kEBDown]);

                fakeMass_EBEE_EEUp->Fill(ggMass,fakeRate);
                fakeMass_EBEE_EEDown->Fill(ggMass,fakeRate);
                fakeMass_EBEE_EEUp_varbin->Fill(ggMass,fakeRate);
                fakeMass_EBEE_EEDown_varbin->Fill(ggMass,fakeRate);

              }
              else if (FTDiphoton_isEEEB){
                fakeMass_EBEE_EEUp->Fill(ggMass,fakeRate*sysFactorMap[fakeRateSys::kEEUp]);
                fakeMass_EBEE_EEDown->Fill(ggMass,fakeRate*sysFactorMap[fakeRateSys::kEEDown]);
                fakeMass_EBEE_EEUp_varbin->Fill(ggMass,fakeRate*sysFactorMap[fakeRateSys::kEEUp]);
                fakeMass_EBEE_EEDown_varbin->Fill(ggMass,fakeRate*sysFactorMap[fakeRateSys::kEEDown]);

                fakeMass_EBEE_EBUp->Fill(ggMass,fakeRate);
                fakeMass_EBEE_EBDown->Fill(ggMass,fakeRate);
                fakeMass_EBEE_EBUp_varbin->Fill(ggMass,fakeRate);
                fakeMass_EBEE_EBDown_varbin->Fill(ggMass,fakeRate);

              }

              // if (FTDiphoton_isEBEE) jgstream_EBEE << ggMass << " " << fakeRate << "\n";
              // else if (FTDiphoton_isEEEB) jgstream_EEEB << ggMass << " " << fakeRate << "\n";
            }
        }
      } // end TL || LT block
      else if (LL){
        double fakeRateProd = getFakeRate(FFPhoton1_pt,FFPhoton1_scEta) * getFakeRate(FFPhoton2_pt,FFPhoton2_scEta);
        double ggMass = FFDiphoton_Minv;
        bool isEBEB = FFDiphoton_isEBEB;
        bool isEBEE = (FFDiphoton_isEBEE) || (FFDiphoton_isEEEB);
        if (isEBEB){
            llMass_EBEB->Fill(ggMass);
            llMass_EBEB_varbin->Fill(ggMass);
            llMass_EBEB_30003500varbin->Fill(ggMass);

            ffMass_EBEB->Fill(ggMass);
            ffMass_EBEB_varbin->Fill(ggMass);
            ffMass_EBEB_30003500varbin->Fill(ggMass);

            // fake-fake contributes to gamma-jet also
            gjMass_EBEB->Fill(ggMass,-2.*fakeRateProd);
            gjMass_EBEB_varbin->Fill(ggMass,-2.*fakeRateProd);
            gjMass_EBEB_30003500varbin->Fill(ggMass,-2.*fakeRateProd);

            jjMass_EBEB->Fill(ggMass,fakeRateProd);
            jjMass_EBEB_varbin->Fill(ggMass,fakeRateProd);
            jjMass_EBEB_30003500varbin->Fill(ggMass,fakeRateProd);

            fakeMass_EBEB->Fill(ggMass,-1.*fakeRateProd);
            fakeMass_EBEB_varbin->Fill(ggMass,-1.*fakeRateProd);
            fakeMass_EBEB_30003500varbin->Fill(ggMass,-1.*fakeRateProd);

            fakeMass_EBEB_EBUp->Fill(ggMass,-1.*fakeRateProd*sysFactorMap[fakeRateSys::kEBUp]*sysFactorMap[fakeRateSys::kEBUp]);
            fakeMass_EBEB_EBDown->Fill(ggMass,-1.*fakeRateProd*sysFactorMap[fakeRateSys::kEBDown]*sysFactorMap[fakeRateSys::kEBDown]);
            fakeMass_EBEB_EBUp_varbin->Fill(ggMass,-1.*fakeRateProd*sysFactorMap[fakeRateSys::kEBUp]*sysFactorMap[fakeRateSys::kEBUp]);
            fakeMass_EBEB_EBDown_varbin->Fill(ggMass,-1.*fakeRateProd*sysFactorMap[fakeRateSys::kEBDown]*sysFactorMap[fakeRateSys::kEBDown]);
            
        }
        else if (isEBEE){
            llMass_EBEE->Fill(ggMass);
            llMass_EBEE_varbin->Fill(ggMass);
            llMass_EBEE_30003500varbin->Fill(ggMass);

            ffMass_EBEE->Fill(ggMass);
            ffMass_EBEE_varbin->Fill(ggMass);
            ffMass_EBEE_30003500varbin->Fill(ggMass);

            // fake-fake contributes to gamma-jet also
            gjMass_EBEE->Fill(ggMass,-2.*fakeRateProd);
            gjMass_EBEE_varbin->Fill(ggMass,-2.*fakeRateProd);
            gjMass_EBEE_30003500varbin->Fill(ggMass,-2.*fakeRateProd);

            jjMass_EBEE->Fill(ggMass,fakeRateProd);
            jjMass_EBEE_varbin->Fill(ggMass,fakeRateProd);
            jjMass_EBEE_30003500varbin->Fill(ggMass,fakeRateProd);

            fakeMass_EBEE->Fill(ggMass,-1.*fakeRateProd);
            fakeMass_EBEE_varbin->Fill(ggMass,-1.*fakeRateProd);
            fakeMass_EBEE_30003500varbin->Fill(ggMass,-1.*fakeRateProd);

            fakeMass_EBEE_EBUp->Fill(ggMass,-1.*fakeRateProd*sysFactorMap[fakeRateSys::kEBUp]);
            fakeMass_EBEE_EBDown->Fill(ggMass,-1.*fakeRateProd*sysFactorMap[fakeRateSys::kEBDown]);
            fakeMass_EBEE_EEUp->Fill(ggMass,-1.*fakeRateProd*sysFactorMap[fakeRateSys::kEEUp]);
            fakeMass_EBEE_EEDown->Fill(ggMass,-1.*fakeRateProd*sysFactorMap[fakeRateSys::kEEDown]);
            fakeMass_EBEE_EBUp_varbin->Fill(ggMass,-1.*fakeRateProd*sysFactorMap[fakeRateSys::kEBUp]);
            fakeMass_EBEE_EBDown_varbin->Fill(ggMass,-1.*fakeRateProd*sysFactorMap[fakeRateSys::kEBDown]);
            fakeMass_EBEE_EEUp_varbin->Fill(ggMass,-1.*fakeRateProd*sysFactorMap[fakeRateSys::kEEUp]);
            fakeMass_EBEE_EEDown_varbin->Fill(ggMass,-1.*fakeRateProd*sysFactorMap[fakeRateSys::kEEDown]);

        }

      } // end LL block
      // if (TL || LT) cout << "Counter = " << counter << " Event = " << Event_evnum << endl;
    } // end event loop

    TFile outfile("deletethis2.root","recreate");
    // TFile outfile("fakePlotsNew_endcapleading.root","recreate");
    // TFile outfile("fakePlotsNew.root","recreate");
    outfile.cd();

    justtlMass_EBEB->Write();
    ltMass_EBEB->Write();
    tlMass_EBEB->Write();
    llMass_EBEB->Write();
    ffMass_EBEB->Write();
    justtlMass_EBEE->Write();
    ltMass_EBEE->Write();
    tlMass_EBEE->Write();
    llMass_EBEE->Write();
    ffMass_EBEE->Write();
    justtlMass_EBEB_30003500varbin->Write();
    ltMass_EBEB_30003500varbin->Write();
    tlMass_EBEB_30003500varbin->Write();
    llMass_EBEB_30003500varbin->Write();
    ffMass_EBEB_30003500varbin->Write();
    justtlMass_EBEE_30003500varbin->Write();
    ltMass_EBEE_30003500varbin->Write();
    tlMass_EBEE_30003500varbin->Write();
    llMass_EBEE_30003500varbin->Write();
    ffMass_EBEE_30003500varbin->Write();
    justtlMass_EBEB_varbin->Write();
    ltMass_EBEB_varbin->Write();
    tlMass_EBEB_varbin->Write();
    llMass_EBEB_varbin->Write();
    ffMass_EBEB_varbin->Write();
    justtlMass_EBEE_varbin->Write();
    ltMass_EBEE_varbin->Write();
    tlMass_EBEE_varbin->Write();
    llMass_EBEE_varbin->Write();
    ffMass_EBEE_varbin->Write();
    justgjMass_EBEB->Write();
    jgMass_EBEB->Write();
    gjMass_EBEB->Write();
    jjMass_EBEB->Write();
    fakeMass_EBEB->Write();
    justgjMass_EBEE->Write();
    jgMass_EBEE->Write();
    gjMass_EBEE->Write();
    jjMass_EBEE->Write();
    fakeMass_EBEE->Write();
    justgjMass_EBEB_30003500varbin->Write();
    jgMass_EBEB_30003500varbin->Write();
    gjMass_EBEB_30003500varbin->Write();
    jjMass_EBEB_30003500varbin->Write();
    fakeMass_EBEB_30003500varbin->Write();
    justgjMass_EBEE_30003500varbin->Write();
    jgMass_EBEE_30003500varbin->Write();
    gjMass_EBEE_30003500varbin->Write();
    jjMass_EBEE_30003500varbin->Write();
    fakeMass_EBEE_30003500varbin->Write();
    justgjMass_EBEB_varbin->Write();
    jgMass_EBEB_varbin->Write();
    gjMass_EBEB_varbin->Write();
    jjMass_EBEB_varbin->Write();
    fakeMass_EBEB_varbin->Write();
    justgjMass_EBEE_varbin->Write();
    jgMass_EBEE_varbin->Write();
    gjMass_EBEE_varbin->Write();
    jjMass_EBEE_varbin->Write();
    fakeMass_EBEE_varbin->Write();

    fakeMass_EBEB_EBUp->Write();
    fakeMass_EBEB_EBDown->Write();
    fakeMass_EBEE_EBUp->Write();
    fakeMass_EBEE_EBDown->Write();
    fakeMass_EBEE_EEUp->Write();
    fakeMass_EBEE_EEDown->Write();
    fakeMass_EBEB_EBUp_varbin->Write();
    fakeMass_EBEB_EBDown_varbin->Write();
    fakeMass_EBEE_EBUp_varbin->Write();
    fakeMass_EBEE_EBDown_varbin->Write();
    fakeMass_EBEE_EEUp_varbin->Write();
    fakeMass_EBEE_EEDown_varbin->Write();

    outfile.Close();
}
