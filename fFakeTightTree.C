#define fFakeTightTree_cxx
#include "fFakeTightTree.h"
#include "helperFunctions.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TTree.h>

void fFakeTightTree::Loop()
{
//   In a ROOT session, you can do:
//      root> .L fFakeTightTree.C
//      root> fFakeTightTree t
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

    Double_t pt1,eta1,phi1,energy1;
    Double_t pt2,eta2,phi2,energy2;
    Double_t isFakeable1,isFakeable2;
    Double_t ggMass;
    Int_t EBEB,EBEE;

    TTree* tree = new TTree("tree","");

    tree->Branch("pt1",&pt1,"pt1/D");
    tree->Branch("eta1",&eta1,"eta1/D");
    tree->Branch("phi1",&phi1,"phi1/D");
    tree->Branch("energy1",&energy1,"energy1/D");
    tree->Branch("isFakeable1",&isFakeable1,"isFakeable1/D");
    tree->Branch("pt2",&pt2,"pt2/D");
    tree->Branch("eta2",&eta2,"eta2/D");
    tree->Branch("phi2",&phi2,"phi2/D");
    tree->Branch("energy2",&energy2,"energy2/D");
    tree->Branch("isFakeable2",&isFakeable2,"isFakeable2/D");
    tree->Branch("ggMass",&ggMass,"ggMass/D");
    tree->Branch("isEBEB",&EBEB,"isEBEB/I");
    tree->Branch("isEBEE",&EBEE,"isEBEE/I");

    if (fChain == 0) return;

    Long64_t nentries = fChain->GetEntriesFast();

    Long64_t nbytes = 0, nb = 0;
    for (Long64_t jentry=0; jentry<nentries;jentry++) {
        Long64_t ientry = LoadTree(jentry);
        if (ientry < 0) break;
        nb = fChain->GetEntry(jentry);   nbytes += nb;

        if (jentry % 1000 == 0) cout << "Now looking at event #" << jentry << endl;
        if (!TrigHLT_HLT_DoublePhoton60_v1) continue; // only admit events that pass HLT_DoublePhoton_60

        pt1 = Photon1_pt;
        eta1 = Photon1_scEta;
        phi1 = Photon1_scPhi;
        energy1 = Photon1_scRawEnergy;
        isFakeable1 = Photon1_isFakeable;
        pt2 = Photon2_pt;
        eta2 = Photon2_scEta;
        phi2 = Photon2_scPhi;
        energy2 = Photon2_scRawEnergy;
        isFakeable2 = Photon2_isFakeable;
        ggMass = Diphoton_Minv;
        EBEB = isEBEB(eta1,eta2);
        EBEE = isEBEE(eta1,eta2);

        tree->Fill();
    }

    TFile* outfile = new TFile("basicfaketree_faketight.root","recreate");
    outfile->cd();
    tree->Write();
    outfile->Close();
}
