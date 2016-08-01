#define extractFakeContributions_cxx
#include "extractFakeContributions.h"
#include "helperFunctions.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

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

    TH1D* tlMass_EBEB = createTH1D("tlMass_EBEB","tlMass_EBEB",651,-10.,13000.,"m_{Tight-Loose} (GeV/c^{2})","Events");
    TH1D* llMass_EBEB = createTH1D("llMass_EBEB","llMass_EBEB",651,-10.,13000.,"m_{Loose-Loose} (GeV/c^{2})","Events");
    TH1D* ffMass_EBEB = createTH1D("ffMass_EBEB","ffMass_EBEB",651,-10.,13000.,"m_{fake} (GeV/c^{2})","Events");
    TH1D* tlMass_EBEE = createTH1D("tlMass_EBEE","tlMass_EBEE",651,-10.,13000.,"m_{Tight-Loose} (GeV/c^{2})","Events");
    TH1D* llMass_EBEE = createTH1D("llMass_EBEE","llMass_EBEE",651,-10.,13000.,"m_{Loose-Loose} (GeV/c^{2})","Events");
    TH1D* ffMass_EBEE = createTH1D("ffMass_EBEE","ffMass_EBEE",651,-10.,13000.,"m_{fake} (GeV/c^{2})","Events");

    TH1D* tlMass_EBEB_30003500varbin = createTH1D("tlMass_EBEB_30003500varbin","tlMass_EBEB",5,bins_30003500,"m_{Tight-Loose} (GeV/c^{2})","Events");
    TH1D* llMass_EBEB_30003500varbin = createTH1D("llMass_EBEB_30003500varbin","llMass_EBEB",5,bins_30003500,"m_{Loose-Loose} (GeV/c^{2})","Events");
    TH1D* ffMass_EBEB_30003500varbin = createTH1D("ffMass_EBEB_30003500varbin","ffMass_EBEB",5,bins_30003500,"m_{fake} (GeV/c^{2})","Events");
    TH1D* tlMass_EBEE_30003500varbin = createTH1D("tlMass_EBEE_30003500varbin","tlMass_EBEE",5,bins_30003500,"m_{Tight-Loose} (GeV/c^{2})","Events");
    TH1D* llMass_EBEE_30003500varbin = createTH1D("llMass_EBEE_30003500varbin","llMass_EBEE",5,bins_30003500,"m_{Loose-Loose} (GeV/c^{2})","Events");
    TH1D* ffMass_EBEE_30003500varbin = createTH1D("ffMass_EBEE_30003500varbin","ffMass_EBEE",5,bins_30003500,"m_{fake} (GeV/c^{2})","Events");

    TH1D* tlMass_EBEB_varbin = createTH1D("tlMass_EBEB_varbin","tlMass_EBEB",6,bins,"m_{Tight-Loose} (GeV/c^{2})","Events");
    TH1D* llMass_EBEB_varbin = createTH1D("llMass_EBEB_varbin","llMass_EBEB",6,bins,"m_{Loose-Loose} (GeV/c^{2})","Events");
    TH1D* ffMass_EBEB_varbin = createTH1D("ffMass_EBEB_varbin","ffMass_EBEB",6,bins,"m_{fake} (GeV/c^{2})","Events");
    TH1D* tlMass_EBEE_varbin = createTH1D("tlMass_EBEE_varbin","tlMass_EBEE",6,bins,"m_{Tight-Loose} (GeV/c^{2})","Events");
    TH1D* llMass_EBEE_varbin = createTH1D("llMass_EBEE_varbin","llMass_EBEE",6,bins,"m_{Loose-Loose} (GeV/c^{2})","Events");
    TH1D* ffMass_EBEE_varbin = createTH1D("ffMass_EBEE_varbin","ffMass_EBEE",6,bins,"m_{fake} (GeV/c^{2})","Events");

    TH1D* gjMass_EBEB = createTH1D("gjMass_EBEB","gjMass_EBEB",651,-10.,13000.,"m_{#gamma+jet} (GeV/c^{2})","Events");
    TH1D* jjMass_EBEB = createTH1D("jjMass_EBEB","jjMass_EBEB",651,-10.,13000.,"m_{jet+jet} (GeV/c^{2})","Events");
    TH1D* fakeMass_EBEB = createTH1D("fakeMass_EBEB","fakeMass_EBEB",651,-10.,13000.,"m_{fake} (GeV/c^{2})","Events");
    TH1D* gjMass_EBEE = createTH1D("gjMass_EBEE","gjMass_EBEE",651,-10.,13000.,"m_{#gamma+jet} (GeV/c^{2})","Events");
    TH1D* jjMass_EBEE = createTH1D("jjMass_EBEE","jjMass_EBEE",651,-10.,13000.,"m_{jet+jet} (GeV/c^{2})","Events");
    TH1D* fakeMass_EBEE = createTH1D("fakeMass_EBEE","fakeMass_EBEE",651,-10.,13000.,"m_{fake} (GeV/c^{2})","Events");

    TH1D* gjMass_EBEB_30003500varbin = createTH1D("gjMass_EBEB_30003500varbin","gjMass_EBEB",5,bins_30003500,"m_{#gamma+jet} (GeV/c^{2})","Events");
    TH1D* jjMass_EBEB_30003500varbin = createTH1D("jjMass_EBEB_30003500varbin","jjMass_EBEB",5,bins_30003500,"m_{jet+jet} (GeV/c^{2})","Events");
    TH1D* fakeMass_EBEB_30003500varbin = createTH1D("fakeMass_EBEB_30003500varbin","fakeMass_EBEB",5,bins_30003500,"m_{fake} (GeV/c^{2})","Events");
    TH1D* gjMass_EBEE_30003500varbin = createTH1D("gjMass_EBEE_30003500varbin","gjMass_EBEE",5,bins_30003500,"m_{#gamma+jet} (GeV/c^{2})","Events");
    TH1D* jjMass_EBEE_30003500varbin = createTH1D("jjMass_EBEE_30003500varbin","jjMass_EBEE",5,bins_30003500,"m_{jet+jet} (GeV/c^{2})","Events");
    TH1D* fakeMass_EBEE_30003500varbin = createTH1D("fakeMass_EBEE_30003500varbin","fakeMass_EBEE",5,bins_30003500,"m_{fake} (GeV/c^{2})","Events");

    TH1D* gjMass_EBEB_varbin = createTH1D("gjMass_EBEB_varbin","gjMass_EBEB",6,bins,"m_{#gamma+jet} (GeV/c^{2})","Events");
    TH1D* jjMass_EBEB_varbin = createTH1D("jjMass_EBEB_varbin","jjMass_EBEB",6,bins,"m_{jet+jet} (GeV/c^{2})","Events");
    TH1D* fakeMass_EBEB_varbin = createTH1D("fakeMass_EBEB_varbin","fakeMass_EBEB",6,bins,"m_{fake} (GeV/c^{2})","Events");
    TH1D* gjMass_EBEE_varbin = createTH1D("gjMass_EBEE_varbin","gjMass_EBEE",6,bins,"m_{#gamma+jet} (GeV/c^{2})","Events");
    TH1D* jjMass_EBEE_varbin = createTH1D("jjMass_EBEE_varbin","jjMass_EBEE",6,bins,"m_{jet+jet} (GeV/c^{2})","Events");
    TH1D* fakeMass_EBEE_varbin = createTH1D("fakeMass_EBEE_varbin","fakeMass_EBEE",6,bins,"m_{fake} (GeV/c^{2})","Events");

    if (fChain == 0) return;

    Long64_t nentries = fChain->GetEntriesFast();

    Long64_t nbytes = 0, nb = 0;
    for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      if (jentry % 1000 == 0) cout << "Now analyzing entry #" << jentry << endl;

      // distinguising between fake-tight and tight-fake only to know which photon to evaluate the fake rate for
      // bool isTT = !isFakeable1 && !isFakeable2;
      bool TL = !isFakeable1 && isFakeable2;
      bool LT = isFakeable1 && !isFakeable2;
      bool LL = isFakeable1 && isFakeable2;

      if (!TL && !LT && !LL){
        cout << "No fake found in entry " << jentry << ". Investigate!!" << endl;
        return;
      }
      else if (TL || LT){
        double fakeRate;
        if (TL) fakeRate = getFakeRate(pt2,eta2);
        else if (LT) fakeRate = getFakeRate(pt1,eta1);
        if (isEBEB){
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
        }
        else if (isEBEE){
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
        }
      } // end TL || LT block
      else if (LL){
        double fakeRateProd = getFakeRate(pt1,eta1) * getFakeRate(pt2,eta2);
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

        }

      } // end LL block
    } // end event loop

    TFile outfile("fakePlots.root","recreate");
    outfile.cd();

    tlMass_EBEB->Write();
    llMass_EBEB->Write();
    ffMass_EBEB->Write();
    tlMass_EBEE->Write();
    llMass_EBEE->Write();
    ffMass_EBEE->Write();
    tlMass_EBEB_30003500varbin->Write();
    llMass_EBEB_30003500varbin->Write();
    ffMass_EBEB_30003500varbin->Write();
    tlMass_EBEE_30003500varbin->Write();
    llMass_EBEE_30003500varbin->Write();
    ffMass_EBEE_30003500varbin->Write();
    tlMass_EBEB_varbin->Write();
    llMass_EBEB_varbin->Write();
    ffMass_EBEB_varbin->Write();
    tlMass_EBEE_varbin->Write();
    llMass_EBEE_varbin->Write();
    ffMass_EBEE_varbin->Write();
    gjMass_EBEB->Write();
    jjMass_EBEB->Write();
    fakeMass_EBEB->Write();
    gjMass_EBEE->Write();
    jjMass_EBEE->Write();
    fakeMass_EBEE->Write();
    gjMass_EBEB_30003500varbin->Write();
    jjMass_EBEB_30003500varbin->Write();
    fakeMass_EBEB_30003500varbin->Write();
    gjMass_EBEE_30003500varbin->Write();
    jjMass_EBEE_30003500varbin->Write();
    fakeMass_EBEE_30003500varbin->Write();
    gjMass_EBEB_varbin->Write();
    jjMass_EBEB_varbin->Write();
    fakeMass_EBEB_varbin->Write();
    gjMass_EBEE_varbin->Write();
    jjMass_EBEE_varbin->Write();
    fakeMass_EBEE_varbin->Write();

    outfile.Close();

}
