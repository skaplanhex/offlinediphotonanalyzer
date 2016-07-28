//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Jul 27 16:33:45 2016 by ROOT version 6.02/13
// from TTree tree/
// found on file: basicfaketree_fakefake.root
//////////////////////////////////////////////////////////

#ifndef extractFakeContributions_h
#define extractFakeContributions_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class extractFakeContributions {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Double_t        pt1;
   Double_t        eta1;
   Double_t        phi1;
   Double_t        energy1;
   Double_t        isFakeable1;
   Double_t        pt2;
   Double_t        eta2;
   Double_t        phi2;
   Double_t        energy2;
   Double_t        isFakeable2;
   Double_t        ggMass;
   Int_t           isEBEB;
   Int_t           isEBEE;

   // List of branches
   TBranch        *b_pt1;   //!
   TBranch        *b_eta1;   //!
   TBranch        *b_phi1;   //!
   TBranch        *b_energy1;   //!
   TBranch        *b_isFakeable1;   //!
   TBranch        *b_pt2;   //!
   TBranch        *b_eta2;   //!
   TBranch        *b_phi2;   //!
   TBranch        *b_energy2;   //!
   TBranch        *b_isFakeable2;   //!
   TBranch        *b_ggMass;   //!
   TBranch        *b_isEBEB;   //!
   TBranch        *b_isEBEE;   //!

   extractFakeContributions(TTree *tree=0);
   virtual ~extractFakeContributions();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef extractFakeContributions_cxx
extractFakeContributions::extractFakeContributions(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("basicfaketree_fakefake.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("basicfaketree_fakefake.root");
      }
      f->GetObject("tree",tree);

   }
   Init(tree);
}

extractFakeContributions::~extractFakeContributions()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t extractFakeContributions::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t extractFakeContributions::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void extractFakeContributions::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("pt1", &pt1, &b_pt1);
   fChain->SetBranchAddress("eta1", &eta1, &b_eta1);
   fChain->SetBranchAddress("phi1", &phi1, &b_phi1);
   fChain->SetBranchAddress("energy1", &energy1, &b_energy1);
   fChain->SetBranchAddress("isFakeable1", &isFakeable1, &b_isFakeable1);
   fChain->SetBranchAddress("pt2", &pt2, &b_pt2);
   fChain->SetBranchAddress("eta2", &eta2, &b_eta2);
   fChain->SetBranchAddress("phi2", &phi2, &b_phi2);
   fChain->SetBranchAddress("energy2", &energy2, &b_energy2);
   fChain->SetBranchAddress("isFakeable2", &isFakeable2, &b_isFakeable2);
   fChain->SetBranchAddress("ggMass", &ggMass, &b_ggMass);
   fChain->SetBranchAddress("isEBEB", &isEBEB, &b_isEBEB);
   fChain->SetBranchAddress("isEBEE", &isEBEE, &b_isEBEE);
   Notify();
}

Bool_t extractFakeContributions::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void extractFakeContributions::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t extractFakeContributions::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef extractFakeContributions_cxx
