//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Jun 14 14:19:52 2016 by ROOT version 6.02/13
// from TTree fTree/PhotonTree
// found on file: root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/BrandonSteveMerged/DoubleEG_Run2016B_V2.root
//////////////////////////////////////////////////////////

#ifndef fTree_h
#define fTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "vector"
#include "vector"
#include "vector"

class fTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Long64_t        Event_run;
   Long64_t        Event_LS;
   Long64_t        Event_evnum;
   Long64_t        Event_processid;
   Float_t         Event_pthat;
   Float_t         Event_alphaqcd;
   Float_t         Event_alphaqed;
   Float_t         Event_qscale;
   Float_t         Event_weight;
   Double_t        Vtx_vx;
   Double_t        Vtx_vy;
   Double_t        Vtx_vz;
   Double_t        Vtx_sumPtTracks;
   Double_t        Vtx_ndof;
   Double_t        Vtx_d0;
   Int_t           Vtx_Nvtx;
   Int_t           Vtx_Ntracks;
   Bool_t          Vtx_isFake;
   Double_t        Vtx2_vx;
   Double_t        Vtx2_vy;
   Double_t        Vtx2_vz;
   Double_t        Vtx2_sumPtTracks;
   Double_t        Vtx2_ndof;
   Double_t        Vtx2_d0;
   Int_t           Vtx2_Nvtx;
   Int_t           Vtx2_Ntracks;
   Bool_t          Vtx2_isFake;
   Double_t        Vtx3_vx;
   Double_t        Vtx3_vy;
   Double_t        Vtx3_vz;
   Double_t        Vtx3_sumPtTracks;
   Double_t        Vtx3_ndof;
   Double_t        Vtx3_d0;
   Int_t           Vtx3_Nvtx;
   Int_t           Vtx3_Ntracks;
   Bool_t          Vtx3_isFake;
   Double_t        VtxGEN_vx;
   Double_t        VtxGEN_vy;
   Double_t        VtxGEN_vz;
   Double_t        VtxGEN_sumPtTracks;
   Double_t        VtxGEN_ndof;
   Double_t        VtxGEN_d0;
   Int_t           VtxGEN_Nvtx;
   Int_t           VtxGEN_Ntracks;
   Bool_t          VtxGEN_isFake;
   Double_t        rho25;
   Int_t           pu_n;
   Int_t           old_pu_n;
   Double_t        MCPUWeight;
   Double_t        BeamSpot_x0;
   Double_t        BeamSpot_y0;
   Double_t        BeamSpot_z0;
   Double_t        BeamSpot_sigmaZ;
   Double_t        BeamSpot_x0error;
   Double_t        BeamSpot_y0error;
   Double_t        BeamSpot_z0error;
   Double_t        BeamSpot_sigmaZ0error;
   Bool_t          L1trg_L1_Tech0;
   Bool_t          L1trg_L1_Tech36;
   Bool_t          L1trg_L1_Tech37;
   Bool_t          L1trg_L1_Tech38;
   Bool_t          L1trg_L1_Tech39;
   Bool_t          L1trg_L1_Tech40;
   Bool_t          L1trg_L1_Tech41;
   Bool_t          L1trg_L1_Tech42;
   Bool_t          L1trg_L1_Tech43;
   Bool_t          L1trg_L1_EG2;
   Bool_t          L1trg_L1_EG5;
   Bool_t          L1trg_L1_EG8;
   Int_t           TrigHLT_HLT_MinBiasBSC;
   Int_t           TrigHLT_HLT_MinBiasBSC_NoBPTX;
   Int_t           TrigHLT_HLT_MinBiasBSC_OR;
   Int_t           TrigHLT_HLT_L1_BscMinBiasOR_BptxPlusORMinus;
   Int_t           TrigHLT_HLT_L1SingleEG2;
   Int_t           TrigHLT_HLT_L1SingleEG5;
   Int_t           TrigHLT_HLT_L1SingleEG8;
   Int_t           TrigHLT_HLT_L1DoubleEG5;
   Int_t           TrigHLT_HLT_Photon10_L1R;
   Int_t           TrigHLT_HLT_Photon10_Cleaned_L1R;
   Int_t           TrigHLT_HLT_Photon15_L1R;
   Int_t           TrigHLT_HLT_Photon15_Cleaned_L1R;
   Int_t           TrigHLT_HLT_Photon15_LooseEcalIso_L1R;
   Int_t           TrigHLT_HLT_Photon15_LooseEcalIso_Cleaned_L1R;
   Int_t           TrigHLT_HLT_Photon15_TrackIso_L1R;
   Int_t           TrigHLT_HLT_Photon15_TrackIso_Cleaned_L1R;
   Int_t           TrigHLT_HLT_Photon17_Isol_SC17HE_L1R_v1;
   Int_t           TrigHLT_HLT_Photon17_SC17HE_L1R_v1;
   Int_t           TrigHLT_HLT_Photon20_L1R;
   Int_t           TrigHLT_HLT_Photon20_Cleaned_L1R;
   Int_t           TrigHLT_HLT_Photon20_NoHE_L1R;
   Int_t           TrigHLT_HLT_Photon22_SC22HE_L1R_v1;
   Int_t           TrigHLT_HLT_Photon25_Cleaned_L1R;
   Int_t           TrigHLT_HLT_Photon30_L1R;
   Int_t           TrigHLT_HLT_Photon30_Cleaned_L1R;
   Int_t           TrigHLT_HLT_Photon30_L1R_8E29;
   Int_t           TrigHLT_HLT_Photon30_Isol_EBOnly_Cleaned_L1R_v1;
   Int_t           TrigHLT_HLT_Photon35_Isol_Cleaned_L1R_v1;
   Int_t           TrigHLT_HLT_Photon40_CaloId_Cleaned_L1R_v1;
   Int_t           TrigHLT_HLT_Photon40_Isol_Cleaned_L1R_v1;
   Int_t           TrigHLT_HLT_Photon50_L1R;
   Int_t           TrigHLT_HLT_Photon50_Cleaned_L1R;
   Int_t           TrigHLT_HLT_Photon50_Cleaned_L1R_v1;
   Int_t           TrigHLT_HLT_Photon50_NoHE_L1R;
   Int_t           TrigHLT_HLT_Photon50_NoHE_Cleaned_L1R;
   Int_t           TrigHLT_HLT_Photon70_Cleaned_L1R_v1;
   Int_t           TrigHLT_HLT_Photon70_NoHE_Cleaned_L1R_v1;
   Int_t           TrigHLT_HLT_Photon100_NoHE_Cleaned_L1R_v1;
   Int_t           TrigHLT_HLT_Photon110_NoHE_Cleaned_L1R_v1;
   Int_t           TrigHLT_HLT_DoublePhoton5_L1R;
   Int_t           TrigHLT_HLT_DoublePhoton5_CEP_L1R;
   Int_t           TrigHLT_HLT_DoublePhoton5_CEP_L1R_v3;
   Int_t           TrigHLT_HLT_DoublePhoton5_Jpsi_L1R;
   Int_t           TrigHLT_HLT_DoublePhoton5_Upsilon_L1R;
   Int_t           TrigHLT_HLT_DoublePhoton10_L1R;
   Int_t           TrigHLT_HLT_DoublePhoton15_L1R;
   Int_t           TrigHLT_HLT_DoublePhoton17_L1R;
   Int_t           TrigHLT_HLT_DoublePhoton17_SingleIsol_L1R_v1;
   Int_t           TrigHLT_HLT_DoublePhoton20_L1R;
   Int_t           TrigHLT_HLT_DoublePhoton22_L1R_v1;
   Int_t           TrigHLT_HLT_DoublePhoton33_v1;
   Int_t           TrigHLT_HLT_DoublePhoton33_v2;
   Int_t           TrigHLT_HLT_DoublePhoton33_v3;
   Int_t           TrigHLT_HLT_DoublePhoton33_v5;
   Int_t           TrigHLT_HLT_DoublePhoton33_HEVT_v2;
   Int_t           TrigHLT_HLT_DoublePhoton5_IsoVL_CEP_v1;
   Int_t           TrigHLT_HLT_DoublePhoton5_IsoVL_CEP_v2;
   Int_t           TrigHLT_HLT_Photon125_NoSpikeFilter_v1;
   Int_t           TrigHLT_HLT_Photon125_NoSpikeFilter_v2;
   Int_t           TrigHLT_HLT_Photon125_NoSpikeFilter_v3;
   Int_t           TrigHLT_HLT_Photon20_CaloIdVL_IsoL_v1;
   Int_t           TrigHLT_HLT_Photon20_CaloIdVL_IsoL_v2;
   Int_t           TrigHLT_HLT_Photon20_CaloIdVT_IsoT_Ele8_CaloIdL_CaloIsoVL_v1;
   Int_t           TrigHLT_HLT_Photon20_CaloIdVT_IsoT_Ele8_CaloIdL_CaloIsoVL_v2;
   Int_t           TrigHLT_HLT_Photon20_CaloIdVT_IsoT_Ele8_CaloIdL_CaloIsoVL_v3;
   Int_t           TrigHLT_HLT_Photon20_EBOnly_NoSpikeFilter_v1;
   Int_t           TrigHLT_HLT_Photon20_NoSpikeFilter_v1;
   Int_t           TrigHLT_HLT_Photon20_R9Id_Photon18_R9Id_v1;
   Int_t           TrigHLT_HLT_Photon20_R9Id_Photon18_R9Id_v2;
   Int_t           TrigHLT_HLT_Photon20_R9Id_Photon18_R9Id_v3;
   Int_t           TrigHLT_HLT_Photon26_CaloIdL_IsoVL_Photon18_CaloIdL_IsoVL_v1;
   Int_t           TrigHLT_HLT_Photon26_CaloIdL_IsoVL_Photon18_CaloIdL_IsoVL_v2;
   Int_t           TrigHLT_HLT_Photon26_CaloIdL_IsoVL_Photon18_CaloIdL_IsoVL_v3;
   Int_t           TrigHLT_HLT_Photon26_CaloIdL_IsoVL_Photon18_R9Id_v1;
   Int_t           TrigHLT_HLT_Photon26_CaloIdL_IsoVL_Photon18_R9Id_v2;
   Int_t           TrigHLT_HLT_Photon26_CaloIdL_IsoVL_Photon18_v1;
   Int_t           TrigHLT_HLT_Photon26_CaloIdL_IsoVL_Photon18_v2;
   Int_t           TrigHLT_HLT_Photon26_CaloIdL_IsoVL_Photon18_v3;
   Int_t           TrigHLT_HLT_Photon26_IsoVL_Photon18_IsoVL_v1;
   Int_t           TrigHLT_HLT_Photon26_IsoVL_Photon18_IsoVL_v2;
   Int_t           TrigHLT_HLT_Photon26_IsoVL_Photon18_IsoVL_v3;
   Int_t           TrigHLT_HLT_Photon26_IsoVL_Photon18_v1;
   Int_t           TrigHLT_HLT_Photon26_IsoVL_Photon18_v2;
   Int_t           TrigHLT_HLT_Photon26_IsoVL_Photon18_v3;
   Int_t           TrigHLT_HLT_Photon26_Photon18_v1;
   Int_t           TrigHLT_HLT_Photon26_Photon18_v2;
   Int_t           TrigHLT_HLT_Photon26_Photon18_v3;
   Int_t           TrigHLT_HLT_Photon26_R9Id_Photon18_CaloIdL_IsoVL_v1;
   Int_t           TrigHLT_HLT_Photon26_R9Id_Photon18_CaloIdL_IsoVL_v2;
   Int_t           TrigHLT_HLT_Photon30_CaloIdVL_IsoL_v1;
   Int_t           TrigHLT_HLT_Photon30_CaloIdVL_IsoL_v2;
   Int_t           TrigHLT_HLT_Photon30_CaloIdVL_IsoL_v3;
   Int_t           TrigHLT_HLT_Photon30_CaloIdVL_v1;
   Int_t           TrigHLT_HLT_Photon30_CaloIdVL_v2;
   Int_t           TrigHLT_HLT_Photon30_CaloIdVL_v3;
   Int_t           TrigHLT_HLT_Photon32_CaloIdL_Photon26_CaloIdL_v1;
   Int_t           TrigHLT_HLT_Photon32_CaloIdL_Photon26_CaloIdL_v2;
   Int_t           TrigHLT_HLT_Photon32_CaloIdL_Photon26_CaloIdL_v3;
   Int_t           TrigHLT_HLT_Photon36_CaloIdL_Photon22_CaloIdL_v1;
   Int_t           TrigHLT_HLT_Photon36_CaloIdL_Photon22_CaloIdL_v2;
   Int_t           TrigHLT_HLT_Photon50_CaloIdVL_IsoL_v1;
   Int_t           TrigHLT_HLT_Photon50_CaloIdVL_IsoL_v2;
   Int_t           TrigHLT_HLT_Photon75_CaloIdVL_IsoL_v1;
   Int_t           TrigHLT_HLT_Photon75_CaloIdVL_IsoL_v2;
   Int_t           TrigHLT_HLT_Photon75_CaloIdVL_IsoL_v3;
   Int_t           TrigHLT_HLT_Photon75_CaloIdVL_v1;
   Int_t           TrigHLT_HLT_Photon75_CaloIdVL_v2;
   Int_t           TrigHLT_HLT_Photon75_CaloIdVL_v3;
   Int_t           TrigHLT_HLT_DoublePhoton40_MR150_v3;
   Int_t           TrigHLT_HLT_DoublePhoton40_R014_MR150_v3;
   Int_t           TrigHLT_HLT_DoublePhoton50_v2;
   Int_t           TrigHLT_HLT_DoublePhoton5_IsoVL_CEP_v4;
   Int_t           TrigHLT_HLT_DoublePhoton60_v2;
   Int_t           TrigHLT_HLT_Mu15_DoublePhoton15_CaloIdL_v6;
   Int_t           TrigHLT_HLT_Mu15_Photon20_CaloIdL_v6;
   Int_t           TrigHLT_HLT_Mu8_Photon20_CaloIdVT_IsoT_v5;
   Int_t           TrigHLT_HLT_Photon125_v2;
   Int_t           TrigHLT_HLT_Photon200_NoHE_v2;
   Int_t           TrigHLT_HLT_Photon20_CaloIdVL_IsoL_v4;
   Int_t           TrigHLT_HLT_Photon20_CaloIdVT_IsoT_Ele8_CaloIdL_CaloIsoVL_v5;
   Int_t           TrigHLT_HLT_Photon20_R9Id_Photon18_R9Id_v5;
   Int_t           TrigHLT_HLT_Photon26_CaloIdL_IsoVL_Photon18_CaloIdL_IsoVL_v5;
   Int_t           TrigHLT_HLT_Photon26_CaloIdL_IsoVL_Photon18_R9Id_v4;
   Int_t           TrigHLT_HLT_Photon26_CaloIdL_IsoVL_Photon18_v5;
   Int_t           TrigHLT_HLT_Photon26_IsoVL_Photon18_IsoVL_v5;
   Int_t           TrigHLT_HLT_Photon26_IsoVL_Photon18_v5;
   Int_t           TrigHLT_HLT_Photon26_Photon18_v5;
   Int_t           TrigHLT_HLT_Photon26_R9Id_Photon18_CaloIdL_IsoVL_v4;
   Int_t           TrigHLT_HLT_Photon26_R9Id_Photon18_R9Id_v2;
   Int_t           TrigHLT_HLT_Photon30_CaloIdVL_IsoL_v5;
   Int_t           TrigHLT_HLT_Photon30_CaloIdVL_v5;
   Int_t           TrigHLT_HLT_Photon36_CaloIdL_IsoVL_Photon22_CaloIdL_IsoVL_v1;
   Int_t           TrigHLT_HLT_Photon36_CaloIdL_IsoVL_Photon22_CaloIdL_v1;
   Int_t           TrigHLT_HLT_Photon36_CaloIdL_IsoVL_Photon22_v2;
   Int_t           TrigHLT_HLT_Photon36_CaloIdL_Photon22_CaloIdL_v4;
   Int_t           TrigHLT_HLT_Photon36_CaloId_IsoVL_Photon22_R9Id_v1;
   Int_t           TrigHLT_HLT_Photon36_IsoVL_Photon22_v2;
   Int_t           TrigHLT_HLT_Photon36_R9Id_Photon22_CaloIdL_IsoVL_v1;
   Int_t           TrigHLT_HLT_Photon36_R9Id_Photon22_R9Id_v1;
   Int_t           TrigHLT_HLT_Photon40_CaloIdL_Photon28_CaloIdL_v2;
   Int_t           TrigHLT_HLT_Photon40_R005_MR150_v3;
   Int_t           TrigHLT_HLT_Photon40_R014_MR450_v3;
   Int_t           TrigHLT_HLT_Photon40_R020_MR300_v3;
   Int_t           TrigHLT_HLT_Photon40_R025_MR200_v3;
   Int_t           TrigHLT_HLT_Photon40_R038_MR150_v3;
   Int_t           TrigHLT_HLT_Photon50_CaloIdVL_IsoL_v4;
   Int_t           TrigHLT_HLT_Photon50_CaloIdVL_v2;
   Int_t           TrigHLT_HLT_Photon70_CaloIdL_HT300_v6;
   Int_t           TrigHLT_HLT_Photon70_CaloIdL_HT350_v5;
   Int_t           TrigHLT_HLT_Photon70_CaloIdL_MHT50_v6;
   Int_t           TrigHLT_HLT_Photon70_CaloIdL_MHT70_v5;
   Int_t           TrigHLT_HLT_Photon75_CaloIdVL_IsoL_v5;
   Int_t           TrigHLT_HLT_Photon75_CaloIdVL_v5;
   Int_t           TrigHLT_HLT_Photon90_CaloIdVL_IsoL_v2;
   Int_t           TrigHLT_HLT_Photon90_CaloIdVL_v2;
   Int_t           TrigHLT_HLT_DoublePhoton33_HEVT_v1;
   Int_t           TrigHLT_HLT_DoublePhoton33_v4;
   Int_t           TrigHLT_HLT_DoublePhoton50_v1;
   Int_t           TrigHLT_HLT_DoublePhoton5_IsoVL_CEP_v3;
   Int_t           TrigHLT_HLT_DoublePhoton60_v1;
   Int_t           TrigHLT_HLT_Photon125_v1;
   Int_t           TrigHLT_HLT_Photon200_NoHE_v1;
   Int_t           TrigHLT_HLT_Photon20_CaloIdVL_IsoL_v3;
   Int_t           TrigHLT_HLT_Photon20_CaloIdVT_IsoT_Ele8_CaloIdL_CaloIsoVL_v4;
   Int_t           TrigHLT_HLT_Photon20_R9Id_Photon18_R9Id_v4;
   Int_t           TrigHLT_HLT_Photon26_CaloIdL_IsoVL_Photon18_CaloIdL_IsoVL_v4;
   Int_t           TrigHLT_HLT_Photon26_CaloIdL_IsoVL_Photon18_R9Id_v3;
   Int_t           TrigHLT_HLT_Photon26_CaloIdL_IsoVL_Photon18_v4;
   Int_t           TrigHLT_HLT_Photon26_IsoVL_Photon18_IsoVL_v4;
   Int_t           TrigHLT_HLT_Photon26_IsoVL_Photon18_v4;
   Int_t           TrigHLT_HLT_Photon26_Photon18_v4;
   Int_t           TrigHLT_HLT_Photon26_R9Id_Photon18_CaloIdL_IsoVL_v3;
   Int_t           TrigHLT_HLT_Photon26_R9Id_Photon18_R9Id_v1;
   Int_t           TrigHLT_HLT_Photon30_CaloIdVL_IsoL_v4;
   Int_t           TrigHLT_HLT_Photon30_CaloIdVL_v4;
   Int_t           TrigHLT_HLT_Photon32_CaloIdL_Photon26_CaloIdL_v4;
   Int_t           TrigHLT_HLT_Photon36_CaloIdL_IsoVL_Photon22_v1;
   Int_t           TrigHLT_HLT_Photon36_CaloIdL_Photon22_CaloIdL_v3;
   Int_t           TrigHLT_HLT_Photon36_IsoVL_Photon22_v1;
   Int_t           TrigHLT_HLT_Photon40_CaloIdL_Photon28_CaloIdL_v1;
   Int_t           TrigHLT_HLT_Photon50_CaloIdVL_IsoL_v3;
   Int_t           TrigHLT_HLT_Photon50_CaloIdVL_v1;
   Int_t           TrigHLT_HLT_Photon75_CaloIdVL_IsoL_v4;
   Int_t           TrigHLT_HLT_Photon75_CaloIdVL_v4;
   Int_t           TrigHLT_HLT_Photon90_CaloIdVL_IsoL_v1;
   Int_t           TrigHLT_HLT_Photon90_CaloIdVL_v1;
   Int_t           TrigHLT_HLT_Photon20_CaloIdVL_IsoL_v5;
   Int_t           TrigHLT_HLT_Photon20_R9Id_Photon18_R9Id_v6;
   Int_t           TrigHLT_HLT_Photon20_CaloIdVT_IsoT_Ele8_CaloIdL_CaloIsoVL_v6;
   Int_t           TrigHLT_HLT_Photon26_Photon18_v6;
   Int_t           TrigHLT_HLT_Photon26_IsoVL_Photon18_v6;
   Int_t           TrigHLT_HLT_Photon26_IsoVL_Photon18_IsoVL_v6;
   Int_t           TrigHLT_HLT_Photon26_CaloIdL_IsoVL_Photon18_v6;
   Int_t           TrigHLT_HLT_Photon26_CaloIdL_IsoVL_Photon18_R9Id_v5;
   Int_t           TrigHLT_HLT_Photon26_CaloIdL_IsoVL_Photon18_CaloIdL_IsoVL_v6;
   Int_t           TrigHLT_HLT_Photon26_R9Id_Photon18_CaloIdL_IsoVL_v5;
   Int_t           TrigHLT_HLT_Photon26_R9Id_Photon18_R9Id_v3;
   Int_t           TrigHLT_HLT_Photon30_CaloIdVL_v6;
   Int_t           TrigHLT_HLT_Photon30_CaloIdVL_IsoL_v6;
   Int_t           TrigHLT_HLT_Photon36_IsoVL_Photon22_v3;
   Int_t           TrigHLT_HLT_Photon36_CaloIdVL_Photon22_CaloIdVL_v1;
   Int_t           TrigHLT_HLT_Photon36_CaloIdL_Photon22_CaloIdL_v5;
   Int_t           TrigHLT_HLT_Photon36_CaloIdL_IsoVL_Photon22_v3;
   Int_t           TrigHLT_HLT_Photon36_CaloIdL_IsoVL_Photon22_CaloIdL_v2;
   Int_t           TrigHLT_HLT_Photon36_CaloIdL_IsoVL_Photon22_CaloIdL_IsoVL_v2;
   Int_t           TrigHLT_HLT_Photon36_CaloIdL_IsoVL_Photon22_R9Id_v1;
   Int_t           TrigHLT_HLT_Photon36_R9Id_Photon22_CaloIdL_IsoVL_v2;
   Int_t           TrigHLT_HLT_Photon36_R9Id_Photon22_R9Id_v2;
   Int_t           TrigHLT_HLT_Photon40_CaloIdL_Photon28_CaloIdL_v3;
   Int_t           TrigHLT_HLT_Photon44_CaloIdL_Photon34_CaloIdL_v1;
   Int_t           TrigHLT_HLT_Photon48_CaloIdL_Photon38_CaloIdL_v1;
   Int_t           TrigHLT_HLT_Photon50_CaloIdVL_v3;
   Int_t           TrigHLT_HLT_Photon50_CaloIdVL_IsoL_v5;
   Int_t           TrigHLT_HLT_Photon70_CaloIdL_HT350_v6;
   Int_t           TrigHLT_HLT_Photon70_CaloIdL_HT400_v1;
   Int_t           TrigHLT_HLT_Photon70_CaloIdL_MHT70_v6;
   Int_t           TrigHLT_HLT_Photon70_CaloIdL_MHT90_v1;
   Int_t           TrigHLT_HLT_Photon75_CaloIdVL_v6;
   Int_t           TrigHLT_HLT_Photon75_CaloIdVL_IsoL_v6;
   Int_t           TrigHLT_HLT_Photon90_CaloIdVL_v3;
   Int_t           TrigHLT_HLT_Photon90_CaloIdVL_IsoL_v3;
   Int_t           TrigHLT_HLT_Photon135_v1;
   Int_t           TrigHLT_HLT_Photon225_NoHE_v1;
   Int_t           TrigHLT_HLT_Photon400_v1;
   Int_t           TrigHLT_HLT_Photon200_NoHE_v3;
   Int_t           TrigHLT_HLT_DoublePhoton33_HEVT_v3;
   Int_t           TrigHLT_HLT_DoublePhoton38_HEVT_v2;
   Int_t           TrigHLT_HLT_DoublePhoton60_v3;
   Int_t           TrigHLT_HLT_DoublePhoton80_v1;
   Int_t           TrigHLT_HLT_DoublePhoton5_IsoVL_CEP_v5;
   Int_t           TrigHLT_HLT_Photon26_CaloId10_Iso50_Photon18_CaloId10_Iso50_Mass60_v5;
   Int_t           TrigHLT_HLT_Photon26_CaloId10_Iso50_Photon18_CaloId10_Iso50_Mass60_v6;
   Int_t           TrigHLT_HLT_Photon26_CaloId10_Iso50_Photon18_R9Id85_Mass60_v5;
   Int_t           TrigHLT_HLT_Photon26_CaloId10_Iso50_Photon18_R9Id85_Mass60_v6;
   Int_t           TrigHLT_HLT_Photon26_Photon18_v11;
   Int_t           TrigHLT_HLT_Photon26_Photon18_v12;
   Int_t           TrigHLT_HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass60_v5;
   Int_t           TrigHLT_HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass60_v6;
   Int_t           TrigHLT_HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass70_v1;
   Int_t           TrigHLT_HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_R9Id85_OR_CaloId10_Iso50_Mass70_v2;
   Int_t           TrigHLT_HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_v4;
   Int_t           TrigHLT_HLT_Photon26_R9Id85_OR_CaloId10_Iso50_Photon18_v5;
   Int_t           TrigHLT_HLT_Photon26_R9Id85_Photon18_CaloId10_Iso50_Mass60_v5;
   Int_t           TrigHLT_HLT_Photon26_R9Id85_Photon18_CaloId10_Iso50_Mass60_v6;
   Int_t           TrigHLT_HLT_Photon26_R9Id85_Photon18_R9Id85_Mass60_v3;
   Int_t           TrigHLT_HLT_Photon26_R9Id85_Photon18_R9Id85_Mass60_v4;
   Int_t           TrigHLT_HLT_Photon36_CaloId10_Iso50_Photon22_CaloId10_Iso50_v5;
   Int_t           TrigHLT_HLT_Photon36_CaloId10_Iso50_Photon22_CaloId10_Iso50_v6;
   Int_t           TrigHLT_HLT_Photon36_CaloId10_Iso50_Photon22_R9Id85_v5;
   Int_t           TrigHLT_HLT_Photon36_CaloId10_Iso50_Photon22_R9Id85_v6;
   Int_t           TrigHLT_HLT_Photon36_Photon22_v5;
   Int_t           TrigHLT_HLT_Photon36_Photon22_v6;
   Int_t           TrigHLT_HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_R9Id85_OR_CaloId10_Iso50_v5;
   Int_t           TrigHLT_HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_R9Id85_OR_CaloId10_Iso50_v6;
   Int_t           TrigHLT_HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_v4;
   Int_t           TrigHLT_HLT_Photon36_R9Id85_OR_CaloId10_Iso50_Photon22_v5;
   Int_t           TrigHLT_HLT_Photon36_R9Id85_Photon22_CaloId10_Iso50_v5;
   Int_t           TrigHLT_HLT_Photon36_R9Id85_Photon22_CaloId10_Iso50_v6;
   Int_t           TrigHLT_HLT_Photon36_R9Id85_Photon22_R9Id85_v3;
   Int_t           TrigHLT_HLT_Photon36_R9Id85_Photon22_R9Id85_v4;
   Int_t           TrigHLT_HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v6;
   Int_t           TrigHLT_HLT_DoubleEle33_CaloIdL_GsfTrkIdVL_v7;
   Int_t           TrigHLT_HLT_DoubleEle33_CaloIdL_v13;
   Int_t           TrigHLT_HLT_DoubleEle33_CaloIdL_v14;
   Int_t           TrigHLT_HLT_DoubleEle33_CaloIdT_v10;
   Int_t           TrigHLT_HLT_DoubleEle33_CaloIdT_v9;
   Int_t           TrigHLT_HLT_DoublePhoton40_CaloIdL_Rsq0p035_v3;
   Int_t           TrigHLT_HLT_DoublePhoton40_CaloIdL_Rsq0p035_v4;
   Int_t           TrigHLT_HLT_DoublePhoton40_CaloIdL_Rsq0p035_v5;
   Int_t           TrigHLT_HLT_DoublePhoton40_CaloIdL_Rsq0p035_v6;
   Int_t           TrigHLT_HLT_DoublePhoton40_CaloIdL_Rsq0p06_v3;
   Int_t           TrigHLT_HLT_DoublePhoton40_CaloIdL_Rsq0p06_v4;
   Int_t           TrigHLT_HLT_DoublePhoton40_CaloIdL_Rsq0p06_v5;
   Int_t           TrigHLT_HLT_DoublePhoton40_CaloIdL_Rsq0p06_v6;
   Int_t           TrigHLT_HLT_DoublePhoton48_HEVT_v7;
   Int_t           TrigHLT_HLT_DoublePhoton48_HEVT_v8;
   Int_t           TrigHLT_HLT_DoublePhoton53_HEVT_v1;
   Int_t           TrigHLT_HLT_DoublePhoton53_HEVT_v2;
   Int_t           TrigHLT_HLT_DoublePhoton70_v3;
   Int_t           TrigHLT_HLT_DoublePhoton70_v4;
   Int_t           TrigHLT_HLT_DoublePhoton70_v5;
   Int_t           TrigHLT_HLT_DoublePhoton70_v6;
   Int_t           TrigHLT_HLT_DoublePhoton80_v4;
   Int_t           TrigHLT_HLT_DoublePhoton80_v5;
   Int_t           TrigHLT_HLT_DoublePhoton80_v6;
   Int_t           TrigHLT_HLT_DoublePhoton80_v7;
   Int_t           TrigHLT_HLT_DoublePhoton85_v1;
   Int_t           TrigHLT_HLT_DoublePhoton85_v2;
   Int_t           nTightPhotons;
   Int_t           nFakeablePhotons;
   Double_t        Photon1_pt;
   Double_t        Photon1_eta;
   Double_t        Photon1_phi;
   Double_t        Photon1_detEta;
   Double_t        Photon1_detPhi;
   Double_t        Photon1_r9;
   Double_t        Photon1_sigmaIetaIeta;
   Double_t        Photon1_sigmaEtaEta;
   Double_t        Photon1_sigmaIphiIphi;
   Double_t        Photon1_sigmaPhiPhi;
   Double_t        Photon1_maxEnergyXtal;
   Double_t        Photon1_e1x5;
   Double_t        Photon1_e2x5;
   Double_t        Photon1_e3x3;
   Double_t        Photon1_e5x5;
   Double_t        Photon1_r1x5;
   Double_t        Photon1_r2x5;
   Double_t        Photon1_swisscross;
   Double_t        Photon1_eMax;
   Double_t        Photon1_eLeft;
   Double_t        Photon1_eRight;
   Double_t        Photon1_eTop;
   Double_t        Photon1_eBottom;
   Double_t        Photon1_eSecond;
   Double_t        Photon1_e2x2;
   Double_t        Photon1_e4x4;
   Double_t        Photon1_e2e9;
   Double_t        Photon1_maxRecHitTime;
   Double_t        Photon1_sumRecHitsEnergiesNoKGood;
   Double_t        Photon1_RecHitsNoKGoodEnergyRatio;
   Double_t        Photon1_hadOverEm;
   Double_t        Photon1_hadTowerOverEm;
   Double_t        Photon1_hadDepth1OverEm;
   Double_t        Photon1_hadDepth2OverEm;
   Double_t        Photon1_hcalIso04;
   Double_t        Photon1_hcalIso03;
   Double_t        Photon1_ecalIso04;
   Double_t        Photon1_ecalIso03;
   Double_t        Photon1_trkIsoSumPtHollow04;
   Double_t        Photon1_trkIsoSumPtSolid04;
   Double_t        Photon1_trkIsoSumPtHollow03;
   Double_t        Photon1_trkIsoSumPtSolid03;
   Double_t        Photon1_PFIsoCharged04;
   Double_t        Photon1_PFIsoNeutral04;
   Double_t        Photon1_PFIsoPhoton04;
   Double_t        Photon1_PFIsoAll04;
   Double_t        Photon1_PFIsoCharged03;
   Double_t        Photon1_PFIsoNeutral03;
   Double_t        Photon1_PFIsoPhoton03;
   Double_t        Photon1_PFIsoAll03;
   Double_t        Photon1_PFIsoCharged02;
   Double_t        Photon1_PFIsoNeutral02;
   Double_t        Photon1_PFIsoPhoton02;
   Double_t        Photon1_PFIsoAll02;
   Double_t        Photon1_rhocorPFIsoCharged04;
   Double_t        Photon1_rhocorPFIsoNeutral04;
   Double_t        Photon1_rhocorPFIsoPhoton04;
   Double_t        Photon1_rhocorPFIsoAll04;
   Double_t        Photon1_rhocorPFIsoCharged03;
   Double_t        Photon1_rhocorPFIsoNeutral03;
   Double_t        Photon1_rhocorPFIsoPhoton03;
   Double_t        Photon1_rhocorPFIsoAll03;
   Double_t        Photon1_rhocorPFIsoCharged02;
   Double_t        Photon1_rhocorPFIsoNeutral02;
   Double_t        Photon1_rhocorPFIsoPhoton02;
   Double_t        Photon1_rhocorPFIsoAll02;
   Double_t        Photon1_EAPhotonHighPtID;
   Double_t        Photon1_alphaPhotonHighPtID;
   Double_t        Photon1_kappaPhotonHighPtID;
   Double_t        Photon1_corPhotonIsoHighPtID;
   Double_t        Photon1_esRatio;
   Double_t        Photon1_scEta;
   Double_t        Photon1_scPhi;
   Double_t        Photon1_scRawEnergy;
   Double_t        Photon1_scPreshowerEnergy;
   Double_t        Photon1_scPhiWidth;
   Double_t        Photon1_scEtaWidth;
   Double_t        Photon1_seedEnergy;
   Double_t        Photon1_satSeedEnergy;
   Int_t           Photon1_scNumBasicClusters;
   Int_t           Photon1_trkIsoNtrksHollow04;
   Int_t           Photon1_trkIsoNtrksSolid04;
   Int_t           Photon1_trkIsoNtrksHollow03;
   Int_t           Photon1_trkIsoNtrksSolid03;
   Int_t           Photon1_severityLevel;
   Int_t           Photon1_recHitFlag;
   Int_t           Photon1_detId;
   Int_t           Photon1_iEtaY;
   Int_t           Photon1_iPhiX;
   Int_t           Photon1_numRecHitsNoKGood;
   Int_t           Photon1_nSatCells;
   Bool_t          Photon1_isEB;
   Bool_t          Photon1_isEE;
   Bool_t          Photon1_isEBEtaGap;
   Bool_t          Photon1_isEBPhiGap;
   Bool_t          Photon1_isEERingGap;
   Bool_t          Photon1_isEEDeeGap;
   Bool_t          Photon1_isEBEEGap;
   Bool_t          Photon1_hasPixelSeed;
   Bool_t          Photon1_hasMatchedPromptElec;
   Bool_t          Photon1_isFakeable;
   Bool_t          Photon1_isTightDetPhoton;
   Bool_t          Photon1_isTightPFPhoton;
   Bool_t          Photon1_isMediumPFPhoton;
   Bool_t          Photon1_isLoosePFPhoton;
   Bool_t          Photon1_isHighPtPFPhoton;
   Bool_t          Photon1_hasGoodRecHits;
   Bool_t          Photon1_isSaturated;
   Double_t        Photon2_pt;
   Double_t        Photon2_eta;
   Double_t        Photon2_phi;
   Double_t        Photon2_detEta;
   Double_t        Photon2_detPhi;
   Double_t        Photon2_r9;
   Double_t        Photon2_sigmaIetaIeta;
   Double_t        Photon2_sigmaEtaEta;
   Double_t        Photon2_sigmaIphiIphi;
   Double_t        Photon2_sigmaPhiPhi;
   Double_t        Photon2_maxEnergyXtal;
   Double_t        Photon2_e1x5;
   Double_t        Photon2_e2x5;
   Double_t        Photon2_e3x3;
   Double_t        Photon2_e5x5;
   Double_t        Photon2_r1x5;
   Double_t        Photon2_r2x5;
   Double_t        Photon2_swisscross;
   Double_t        Photon2_eMax;
   Double_t        Photon2_eLeft;
   Double_t        Photon2_eRight;
   Double_t        Photon2_eTop;
   Double_t        Photon2_eBottom;
   Double_t        Photon2_eSecond;
   Double_t        Photon2_e2x2;
   Double_t        Photon2_e4x4;
   Double_t        Photon2_e2e9;
   Double_t        Photon2_maxRecHitTime;
   Double_t        Photon2_sumRecHitsEnergiesNoKGood;
   Double_t        Photon2_RecHitsNoKGoodEnergyRatio;
   Double_t        Photon2_hadOverEm;
   Double_t        Photon2_hadTowerOverEm;
   Double_t        Photon2_hadDepth1OverEm;
   Double_t        Photon2_hadDepth2OverEm;
   Double_t        Photon2_hcalIso04;
   Double_t        Photon2_hcalIso03;
   Double_t        Photon2_ecalIso04;
   Double_t        Photon2_ecalIso03;
   Double_t        Photon2_trkIsoSumPtHollow04;
   Double_t        Photon2_trkIsoSumPtSolid04;
   Double_t        Photon2_trkIsoSumPtHollow03;
   Double_t        Photon2_trkIsoSumPtSolid03;
   Double_t        Photon2_PFIsoCharged04;
   Double_t        Photon2_PFIsoNeutral04;
   Double_t        Photon2_PFIsoPhoton04;
   Double_t        Photon2_PFIsoAll04;
   Double_t        Photon2_PFIsoCharged03;
   Double_t        Photon2_PFIsoNeutral03;
   Double_t        Photon2_PFIsoPhoton03;
   Double_t        Photon2_PFIsoAll03;
   Double_t        Photon2_PFIsoCharged02;
   Double_t        Photon2_PFIsoNeutral02;
   Double_t        Photon2_PFIsoPhoton02;
   Double_t        Photon2_PFIsoAll02;
   Double_t        Photon2_rhocorPFIsoCharged04;
   Double_t        Photon2_rhocorPFIsoNeutral04;
   Double_t        Photon2_rhocorPFIsoPhoton04;
   Double_t        Photon2_rhocorPFIsoAll04;
   Double_t        Photon2_rhocorPFIsoCharged03;
   Double_t        Photon2_rhocorPFIsoNeutral03;
   Double_t        Photon2_rhocorPFIsoPhoton03;
   Double_t        Photon2_rhocorPFIsoAll03;
   Double_t        Photon2_rhocorPFIsoCharged02;
   Double_t        Photon2_rhocorPFIsoNeutral02;
   Double_t        Photon2_rhocorPFIsoPhoton02;
   Double_t        Photon2_rhocorPFIsoAll02;
   Double_t        Photon2_EAPhotonHighPtID;
   Double_t        Photon2_alphaPhotonHighPtID;
   Double_t        Photon2_kappaPhotonHighPtID;
   Double_t        Photon2_corPhotonIsoHighPtID;
   Double_t        Photon2_esRatio;
   Double_t        Photon2_scEta;
   Double_t        Photon2_scPhi;
   Double_t        Photon2_scRawEnergy;
   Double_t        Photon2_scPreshowerEnergy;
   Double_t        Photon2_scPhiWidth;
   Double_t        Photon2_scEtaWidth;
   Double_t        Photon2_seedEnergy;
   Double_t        Photon2_satSeedEnergy;
   Int_t           Photon2_scNumBasicClusters;
   Int_t           Photon2_trkIsoNtrksHollow04;
   Int_t           Photon2_trkIsoNtrksSolid04;
   Int_t           Photon2_trkIsoNtrksHollow03;
   Int_t           Photon2_trkIsoNtrksSolid03;
   Int_t           Photon2_severityLevel;
   Int_t           Photon2_recHitFlag;
   Int_t           Photon2_detId;
   Int_t           Photon2_iEtaY;
   Int_t           Photon2_iPhiX;
   Int_t           Photon2_numRecHitsNoKGood;
   Int_t           Photon2_nSatCells;
   Bool_t          Photon2_isEB;
   Bool_t          Photon2_isEE;
   Bool_t          Photon2_isEBEtaGap;
   Bool_t          Photon2_isEBPhiGap;
   Bool_t          Photon2_isEERingGap;
   Bool_t          Photon2_isEEDeeGap;
   Bool_t          Photon2_isEBEEGap;
   Bool_t          Photon2_hasPixelSeed;
   Bool_t          Photon2_hasMatchedPromptElec;
   Bool_t          Photon2_isFakeable;
   Bool_t          Photon2_isTightDetPhoton;
   Bool_t          Photon2_isTightPFPhoton;
   Bool_t          Photon2_isMediumPFPhoton;
   Bool_t          Photon2_isLoosePFPhoton;
   Bool_t          Photon2_isHighPtPFPhoton;
   Bool_t          Photon2_hasGoodRecHits;
   Bool_t          Photon2_isSaturated;
   vector<double>  *JetInfo_pt;
   vector<double>  *JetInfo_eta;
   vector<double>  *JetInfo_phi;
   vector<double>  *JetInfo_mass;
   vector<double>  *JetInfo_energy;
   vector<int>     *JetInfo_passLooseID;
   vector<int>     *JetInfo_passTightID;
   Double_t        JetInfo_HT;
   Double_t        JetInfo_missingHT;
   vector<double>  *ConvInfo1_x;
   vector<double>  *ConvInfo1_y;
   vector<double>  *ConvInfo1_z;
   vector<double>  *ConvInfo1_r;
   vector<double>  *ConvInfo1_phi;
   vector<double>  *ConvInfo1_dPhiTracksAtVtx;
   vector<double>  *ConvInfo1_nTracks;
   vector<double>  *ConvInfo1_dxy;
   vector<double>  *ConvInfo1_dz;
   vector<double>  *ConvInfo1_vtxChi2;
   vector<double>  *ConvInfo1_vtxNdof;
   vector<double>  *ConvInfo1_pairCotThetaSeparation;
   vector<double>  *ConvInfo1_photonPt;
   vector<double>  *ConvInfo1_track1InnerPx;
   vector<double>  *ConvInfo1_track1InnerPy;
   vector<double>  *ConvInfo1_track1InnerPz;
   vector<double>  *ConvInfo1_track2InnerPx;
   vector<double>  *ConvInfo1_track2InnerPy;
   vector<double>  *ConvInfo1_track2InnerPz;
   vector<double>  *ConvInfo1_dRToSc;
   vector<unsigned char> *ConvInfo1_nSharedHits;
   vector<double>  *ConvInfo1_MVAout;
   vector<vector<float> > *ConvInfo1_oneLegMVA;
   vector<vector<unsigned char> > *ConvInfo1_nHitsBeforeVtx;
   vector<int>     *ConvInfo1_isUndefinedAlgo;
   vector<int>     *ConvInfo1_isEcalSeededAlgo;
   vector<int>     *ConvInfo1_isTrackerOnlyAlgo;
   vector<int>     *ConvInfo1_isMixedAlgo;
   vector<int>     *ConvInfo1_isPflowAlgo;
   vector<int>     *ConvInfo1_isGeneralTracksOnly;
   vector<int>     *ConvInfo1_isArbitratedEcalSeeded;
   vector<int>     *ConvInfo1_isArbitratedMerged;
   vector<int>     *ConvInfo1_isArbitratedMergedEcalGeneral;
   vector<int>     *ConvInfo1_isHighPurity;
   vector<int>     *ConvInfo1_isHighEfficiency;
   vector<int>     *ConvInfo1_isEcalMatched1Track;
   vector<int>     *ConvInfo1_isEcalMatched2Track;
   vector<double>  *ConvInfo2_x;
   vector<double>  *ConvInfo2_y;
   vector<double>  *ConvInfo2_z;
   vector<double>  *ConvInfo2_r;
   vector<double>  *ConvInfo2_phi;
   vector<double>  *ConvInfo2_dPhiTracksAtVtx;
   vector<double>  *ConvInfo2_nTracks;
   vector<double>  *ConvInfo2_dxy;
   vector<double>  *ConvInfo2_dz;
   vector<double>  *ConvInfo2_vtxChi2;
   vector<double>  *ConvInfo2_vtxNdof;
   vector<double>  *ConvInfo2_pairCotThetaSeparation;
   vector<double>  *ConvInfo2_photonPt;
   vector<double>  *ConvInfo2_track1InnerPx;
   vector<double>  *ConvInfo2_track1InnerPy;
   vector<double>  *ConvInfo2_track1InnerPz;
   vector<double>  *ConvInfo2_track2InnerPx;
   vector<double>  *ConvInfo2_track2InnerPy;
   vector<double>  *ConvInfo2_track2InnerPz;
   vector<double>  *ConvInfo2_dRToSc;
   vector<unsigned char> *ConvInfo2_nSharedHits;
   vector<double>  *ConvInfo2_MVAout;
   vector<vector<float> > *ConvInfo2_oneLegMVA;
   vector<vector<unsigned char> > *ConvInfo2_nHitsBeforeVtx;
   vector<int>     *ConvInfo2_isUndefinedAlgo;
   vector<int>     *ConvInfo2_isEcalSeededAlgo;
   vector<int>     *ConvInfo2_isTrackerOnlyAlgo;
   vector<int>     *ConvInfo2_isMixedAlgo;
   vector<int>     *ConvInfo2_isPflowAlgo;
   vector<int>     *ConvInfo2_isGeneralTracksOnly;
   vector<int>     *ConvInfo2_isArbitratedEcalSeeded;
   vector<int>     *ConvInfo2_isArbitratedMerged;
   vector<int>     *ConvInfo2_isArbitratedMergedEcalGeneral;
   vector<int>     *ConvInfo2_isHighPurity;
   vector<int>     *ConvInfo2_isHighEfficiency;
   vector<int>     *ConvInfo2_isEcalMatched1Track;
   vector<int>     *ConvInfo2_isEcalMatched2Track;
   vector<double>  *ConvInfo_OneLeg1_x;
   vector<double>  *ConvInfo_OneLeg1_y;
   vector<double>  *ConvInfo_OneLeg1_z;
   vector<double>  *ConvInfo_OneLeg1_r;
   vector<double>  *ConvInfo_OneLeg1_phi;
   vector<double>  *ConvInfo_OneLeg1_dPhiTracksAtVtx;
   vector<double>  *ConvInfo_OneLeg1_nTracks;
   vector<double>  *ConvInfo_OneLeg1_dxy;
   vector<double>  *ConvInfo_OneLeg1_dz;
   vector<double>  *ConvInfo_OneLeg1_vtxChi2;
   vector<double>  *ConvInfo_OneLeg1_vtxNdof;
   vector<double>  *ConvInfo_OneLeg1_pairCotThetaSeparation;
   vector<double>  *ConvInfo_OneLeg1_photonPt;
   vector<double>  *ConvInfo_OneLeg1_track1InnerPx;
   vector<double>  *ConvInfo_OneLeg1_track1InnerPy;
   vector<double>  *ConvInfo_OneLeg1_track1InnerPz;
   vector<double>  *ConvInfo_OneLeg1_track2InnerPx;
   vector<double>  *ConvInfo_OneLeg1_track2InnerPy;
   vector<double>  *ConvInfo_OneLeg1_track2InnerPz;
   vector<double>  *ConvInfo_OneLeg1_dRToSc;
   vector<unsigned char> *ConvInfo_OneLeg1_nSharedHits;
   vector<double>  *ConvInfo_OneLeg1_MVAout;
   vector<vector<float> > *ConvInfo_OneLeg1_oneLegMVA;
   vector<vector<unsigned char> > *ConvInfo_OneLeg1_nHitsBeforeVtx;
   vector<int>     *ConvInfo_OneLeg1_isUndefinedAlgo;
   vector<int>     *ConvInfo_OneLeg1_isEcalSeededAlgo;
   vector<int>     *ConvInfo_OneLeg1_isTrackerOnlyAlgo;
   vector<int>     *ConvInfo_OneLeg1_isMixedAlgo;
   vector<int>     *ConvInfo_OneLeg1_isPflowAlgo;
   vector<int>     *ConvInfo_OneLeg1_isGeneralTracksOnly;
   vector<int>     *ConvInfo_OneLeg1_isArbitratedEcalSeeded;
   vector<int>     *ConvInfo_OneLeg1_isArbitratedMerged;
   vector<int>     *ConvInfo_OneLeg1_isArbitratedMergedEcalGeneral;
   vector<int>     *ConvInfo_OneLeg1_isHighPurity;
   vector<int>     *ConvInfo_OneLeg1_isHighEfficiency;
   vector<int>     *ConvInfo_OneLeg1_isEcalMatched1Track;
   vector<int>     *ConvInfo_OneLeg1_isEcalMatched2Track;
   vector<double>  *ConvInfo_OneLeg2_x;
   vector<double>  *ConvInfo_OneLeg2_y;
   vector<double>  *ConvInfo_OneLeg2_z;
   vector<double>  *ConvInfo_OneLeg2_r;
   vector<double>  *ConvInfo_OneLeg2_phi;
   vector<double>  *ConvInfo_OneLeg2_dPhiTracksAtVtx;
   vector<double>  *ConvInfo_OneLeg2_nTracks;
   vector<double>  *ConvInfo_OneLeg2_dxy;
   vector<double>  *ConvInfo_OneLeg2_dz;
   vector<double>  *ConvInfo_OneLeg2_vtxChi2;
   vector<double>  *ConvInfo_OneLeg2_vtxNdof;
   vector<double>  *ConvInfo_OneLeg2_pairCotThetaSeparation;
   vector<double>  *ConvInfo_OneLeg2_photonPt;
   vector<double>  *ConvInfo_OneLeg2_track1InnerPx;
   vector<double>  *ConvInfo_OneLeg2_track1InnerPy;
   vector<double>  *ConvInfo_OneLeg2_track1InnerPz;
   vector<double>  *ConvInfo_OneLeg2_track2InnerPx;
   vector<double>  *ConvInfo_OneLeg2_track2InnerPy;
   vector<double>  *ConvInfo_OneLeg2_track2InnerPz;
   vector<double>  *ConvInfo_OneLeg2_dRToSc;
   vector<unsigned char> *ConvInfo_OneLeg2_nSharedHits;
   vector<double>  *ConvInfo_OneLeg2_MVAout;
   vector<vector<float> > *ConvInfo_OneLeg2_oneLegMVA;
   vector<vector<unsigned char> > *ConvInfo_OneLeg2_nHitsBeforeVtx;
   vector<int>     *ConvInfo_OneLeg2_isUndefinedAlgo;
   vector<int>     *ConvInfo_OneLeg2_isEcalSeededAlgo;
   vector<int>     *ConvInfo_OneLeg2_isTrackerOnlyAlgo;
   vector<int>     *ConvInfo_OneLeg2_isMixedAlgo;
   vector<int>     *ConvInfo_OneLeg2_isPflowAlgo;
   vector<int>     *ConvInfo_OneLeg2_isGeneralTracksOnly;
   vector<int>     *ConvInfo_OneLeg2_isArbitratedEcalSeeded;
   vector<int>     *ConvInfo_OneLeg2_isArbitratedMerged;
   vector<int>     *ConvInfo_OneLeg2_isArbitratedMergedEcalGeneral;
   vector<int>     *ConvInfo_OneLeg2_isHighPurity;
   vector<int>     *ConvInfo_OneLeg2_isHighEfficiency;
   vector<int>     *ConvInfo_OneLeg2_isEcalMatched1Track;
   vector<int>     *ConvInfo_OneLeg2_isEcalMatched2Track;
   Double_t        Diphoton_Minv;
   Double_t        Diphoton_qt;
   Double_t        Diphoton_deltaPhi;
   Double_t        Diphoton_deltaEta;
   Double_t        Diphoton_deltaR;
   Double_t        Diphoton_deltaROld;
   Double_t        Diphoton_cosThetaStar;
   Double_t        Diphoton_cosThetaStarOld;
   Double_t        DiphotonVtx2_Minv;
   Double_t        DiphotonVtx2_qt;
   Double_t        DiphotonVtx2_deltaPhi;
   Double_t        DiphotonVtx2_deltaEta;
   Double_t        DiphotonVtx2_deltaR;
   Double_t        DiphotonVtx2_deltaROld;
   Double_t        DiphotonVtx2_cosThetaStar;
   Double_t        DiphotonVtx2_cosThetaStarOld;
   Double_t        DiphotonVtx3_Minv;
   Double_t        DiphotonVtx3_qt;
   Double_t        DiphotonVtx3_deltaPhi;
   Double_t        DiphotonVtx3_deltaEta;
   Double_t        DiphotonVtx3_deltaR;
   Double_t        DiphotonVtx3_deltaROld;
   Double_t        DiphotonVtx3_cosThetaStar;
   Double_t        DiphotonVtx3_cosThetaStarOld;

   // List of branches
   TBranch        *b_Event;   //!
   TBranch        *b_Vtx;   //!
   TBranch        *b_Vtx2;   //!
   TBranch        *b_Vtx3;   //!
   TBranch        *b_VtxGEN;   //!
   TBranch        *b_rho25;   //!
   TBranch        *b_pu_n;   //!
   TBranch        *b_old_pu_n;   //!
   TBranch        *b_MCPUWeight;   //!
   TBranch        *b_BeamSpot;   //!
   TBranch        *b_L1trg;   //!
   TBranch        *b_TrigHLT;   //!
   TBranch        *b_nTightPhotons;   //!
   TBranch        *b_nFakeablePhotons;   //!
   TBranch        *b_Photon1;   //!
   TBranch        *b_Photon2;   //!
   TBranch        *b_JetInfo_pt;   //!
   TBranch        *b_JetInfo_eta;   //!
   TBranch        *b_JetInfo_phi;   //!
   TBranch        *b_JetInfo_mass;   //!
   TBranch        *b_JetInfo_energy;   //!
   TBranch        *b_JetInfo_passLooseID;   //!
   TBranch        *b_JetInfo_passTightID;   //!
   TBranch        *b_JetInfo_HT;   //!
   TBranch        *b_JetInfo_missingHT;   //!
   TBranch        *b_ConvInfo1_x;   //!
   TBranch        *b_ConvInfo1_y;   //!
   TBranch        *b_ConvInfo1_z;   //!
   TBranch        *b_ConvInfo1_r;   //!
   TBranch        *b_ConvInfo1_phi;   //!
   TBranch        *b_ConvInfo1_dPhiTracksAtVtx;   //!
   TBranch        *b_ConvInfo1_nTracks;   //!
   TBranch        *b_ConvInfo1_dxy;   //!
   TBranch        *b_ConvInfo1_dz;   //!
   TBranch        *b_ConvInfo1_vtxChi2;   //!
   TBranch        *b_ConvInfo1_vtxNdof;   //!
   TBranch        *b_ConvInfo1_pairCotThetaSeparation;   //!
   TBranch        *b_ConvInfo1_photonPt;   //!
   TBranch        *b_ConvInfo1_track1InnerPx;   //!
   TBranch        *b_ConvInfo1_track1InnerPy;   //!
   TBranch        *b_ConvInfo1_track1InnerPz;   //!
   TBranch        *b_ConvInfo1_track2InnerPx;   //!
   TBranch        *b_ConvInfo1_track2InnerPy;   //!
   TBranch        *b_ConvInfo1_track2InnerPz;   //!
   TBranch        *b_ConvInfo1_dRToSc;   //!
   TBranch        *b_ConvInfo1_nSharedHits;   //!
   TBranch        *b_ConvInfo1_MVAout;   //!
   TBranch        *b_ConvInfo1_oneLegMVA;   //!
   TBranch        *b_ConvInfo1_nHitsBeforeVtx;   //!
   TBranch        *b_ConvInfo1_isUndefinedAlgo;   //!
   TBranch        *b_ConvInfo1_isEcalSeededAlgo;   //!
   TBranch        *b_ConvInfo1_isTrackerOnlyAlgo;   //!
   TBranch        *b_ConvInfo1_isMixedAlgo;   //!
   TBranch        *b_ConvInfo1_isPflowAlgo;   //!
   TBranch        *b_ConvInfo1_isGeneralTracksOnly;   //!
   TBranch        *b_ConvInfo1_isArbitratedEcalSeeded;   //!
   TBranch        *b_ConvInfo1_isArbitratedMerged;   //!
   TBranch        *b_ConvInfo1_isArbitratedMergedEcalGeneral;   //!
   TBranch        *b_ConvInfo1_isHighPurity;   //!
   TBranch        *b_ConvInfo1_isHighEfficiency;   //!
   TBranch        *b_ConvInfo1_isEcalMatched1Track;   //!
   TBranch        *b_ConvInfo1_isEcalMatched2Track;   //!
   TBranch        *b_ConvInfo2_x;   //!
   TBranch        *b_ConvInfo2_y;   //!
   TBranch        *b_ConvInfo2_z;   //!
   TBranch        *b_ConvInfo2_r;   //!
   TBranch        *b_ConvInfo2_phi;   //!
   TBranch        *b_ConvInfo2_dPhiTracksAtVtx;   //!
   TBranch        *b_ConvInfo2_nTracks;   //!
   TBranch        *b_ConvInfo2_dxy;   //!
   TBranch        *b_ConvInfo2_dz;   //!
   TBranch        *b_ConvInfo2_vtxChi2;   //!
   TBranch        *b_ConvInfo2_vtxNdof;   //!
   TBranch        *b_ConvInfo2_pairCotThetaSeparation;   //!
   TBranch        *b_ConvInfo2_photonPt;   //!
   TBranch        *b_ConvInfo2_track1InnerPx;   //!
   TBranch        *b_ConvInfo2_track1InnerPy;   //!
   TBranch        *b_ConvInfo2_track1InnerPz;   //!
   TBranch        *b_ConvInfo2_track2InnerPx;   //!
   TBranch        *b_ConvInfo2_track2InnerPy;   //!
   TBranch        *b_ConvInfo2_track2InnerPz;   //!
   TBranch        *b_ConvInfo2_dRToSc;   //!
   TBranch        *b_ConvInfo2_nSharedHits;   //!
   TBranch        *b_ConvInfo2_MVAout;   //!
   TBranch        *b_ConvInfo2_oneLegMVA;   //!
   TBranch        *b_ConvInfo2_nHitsBeforeVtx;   //!
   TBranch        *b_ConvInfo2_isUndefinedAlgo;   //!
   TBranch        *b_ConvInfo2_isEcalSeededAlgo;   //!
   TBranch        *b_ConvInfo2_isTrackerOnlyAlgo;   //!
   TBranch        *b_ConvInfo2_isMixedAlgo;   //!
   TBranch        *b_ConvInfo2_isPflowAlgo;   //!
   TBranch        *b_ConvInfo2_isGeneralTracksOnly;   //!
   TBranch        *b_ConvInfo2_isArbitratedEcalSeeded;   //!
   TBranch        *b_ConvInfo2_isArbitratedMerged;   //!
   TBranch        *b_ConvInfo2_isArbitratedMergedEcalGeneral;   //!
   TBranch        *b_ConvInfo2_isHighPurity;   //!
   TBranch        *b_ConvInfo2_isHighEfficiency;   //!
   TBranch        *b_ConvInfo2_isEcalMatched1Track;   //!
   TBranch        *b_ConvInfo2_isEcalMatched2Track;   //!
   TBranch        *b_ConvInfo_OneLeg1_x;   //!
   TBranch        *b_ConvInfo_OneLeg1_y;   //!
   TBranch        *b_ConvInfo_OneLeg1_z;   //!
   TBranch        *b_ConvInfo_OneLeg1_r;   //!
   TBranch        *b_ConvInfo_OneLeg1_phi;   //!
   TBranch        *b_ConvInfo_OneLeg1_dPhiTracksAtVtx;   //!
   TBranch        *b_ConvInfo_OneLeg1_nTracks;   //!
   TBranch        *b_ConvInfo_OneLeg1_dxy;   //!
   TBranch        *b_ConvInfo_OneLeg1_dz;   //!
   TBranch        *b_ConvInfo_OneLeg1_vtxChi2;   //!
   TBranch        *b_ConvInfo_OneLeg1_vtxNdof;   //!
   TBranch        *b_ConvInfo_OneLeg1_pairCotThetaSeparation;   //!
   TBranch        *b_ConvInfo_OneLeg1_photonPt;   //!
   TBranch        *b_ConvInfo_OneLeg1_track1InnerPx;   //!
   TBranch        *b_ConvInfo_OneLeg1_track1InnerPy;   //!
   TBranch        *b_ConvInfo_OneLeg1_track1InnerPz;   //!
   TBranch        *b_ConvInfo_OneLeg1_track2InnerPx;   //!
   TBranch        *b_ConvInfo_OneLeg1_track2InnerPy;   //!
   TBranch        *b_ConvInfo_OneLeg1_track2InnerPz;   //!
   TBranch        *b_ConvInfo_OneLeg1_dRToSc;   //!
   TBranch        *b_ConvInfo_OneLeg1_nSharedHits;   //!
   TBranch        *b_ConvInfo_OneLeg1_MVAout;   //!
   TBranch        *b_ConvInfo_OneLeg1_oneLegMVA;   //!
   TBranch        *b_ConvInfo_OneLeg1_nHitsBeforeVtx;   //!
   TBranch        *b_ConvInfo_OneLeg1_isUndefinedAlgo;   //!
   TBranch        *b_ConvInfo_OneLeg1_isEcalSeededAlgo;   //!
   TBranch        *b_ConvInfo_OneLeg1_isTrackerOnlyAlgo;   //!
   TBranch        *b_ConvInfo_OneLeg1_isMixedAlgo;   //!
   TBranch        *b_ConvInfo_OneLeg1_isPflowAlgo;   //!
   TBranch        *b_ConvInfo_OneLeg1_isGeneralTracksOnly;   //!
   TBranch        *b_ConvInfo_OneLeg1_isArbitratedEcalSeeded;   //!
   TBranch        *b_ConvInfo_OneLeg1_isArbitratedMerged;   //!
   TBranch        *b_ConvInfo_OneLeg1_isArbitratedMergedEcalGeneral;   //!
   TBranch        *b_ConvInfo_OneLeg1_isHighPurity;   //!
   TBranch        *b_ConvInfo_OneLeg1_isHighEfficiency;   //!
   TBranch        *b_ConvInfo_OneLeg1_isEcalMatched1Track;   //!
   TBranch        *b_ConvInfo_OneLeg1_isEcalMatched2Track;   //!
   TBranch        *b_ConvInfo_OneLeg2_x;   //!
   TBranch        *b_ConvInfo_OneLeg2_y;   //!
   TBranch        *b_ConvInfo_OneLeg2_z;   //!
   TBranch        *b_ConvInfo_OneLeg2_r;   //!
   TBranch        *b_ConvInfo_OneLeg2_phi;   //!
   TBranch        *b_ConvInfo_OneLeg2_dPhiTracksAtVtx;   //!
   TBranch        *b_ConvInfo_OneLeg2_nTracks;   //!
   TBranch        *b_ConvInfo_OneLeg2_dxy;   //!
   TBranch        *b_ConvInfo_OneLeg2_dz;   //!
   TBranch        *b_ConvInfo_OneLeg2_vtxChi2;   //!
   TBranch        *b_ConvInfo_OneLeg2_vtxNdof;   //!
   TBranch        *b_ConvInfo_OneLeg2_pairCotThetaSeparation;   //!
   TBranch        *b_ConvInfo_OneLeg2_photonPt;   //!
   TBranch        *b_ConvInfo_OneLeg2_track1InnerPx;   //!
   TBranch        *b_ConvInfo_OneLeg2_track1InnerPy;   //!
   TBranch        *b_ConvInfo_OneLeg2_track1InnerPz;   //!
   TBranch        *b_ConvInfo_OneLeg2_track2InnerPx;   //!
   TBranch        *b_ConvInfo_OneLeg2_track2InnerPy;   //!
   TBranch        *b_ConvInfo_OneLeg2_track2InnerPz;   //!
   TBranch        *b_ConvInfo_OneLeg2_dRToSc;   //!
   TBranch        *b_ConvInfo_OneLeg2_nSharedHits;   //!
   TBranch        *b_ConvInfo_OneLeg2_MVAout;   //!
   TBranch        *b_ConvInfo_OneLeg2_oneLegMVA;   //!
   TBranch        *b_ConvInfo_OneLeg2_nHitsBeforeVtx;   //!
   TBranch        *b_ConvInfo_OneLeg2_isUndefinedAlgo;   //!
   TBranch        *b_ConvInfo_OneLeg2_isEcalSeededAlgo;   //!
   TBranch        *b_ConvInfo_OneLeg2_isTrackerOnlyAlgo;   //!
   TBranch        *b_ConvInfo_OneLeg2_isMixedAlgo;   //!
   TBranch        *b_ConvInfo_OneLeg2_isPflowAlgo;   //!
   TBranch        *b_ConvInfo_OneLeg2_isGeneralTracksOnly;   //!
   TBranch        *b_ConvInfo_OneLeg2_isArbitratedEcalSeeded;   //!
   TBranch        *b_ConvInfo_OneLeg2_isArbitratedMerged;   //!
   TBranch        *b_ConvInfo_OneLeg2_isArbitratedMergedEcalGeneral;   //!
   TBranch        *b_ConvInfo_OneLeg2_isHighPurity;   //!
   TBranch        *b_ConvInfo_OneLeg2_isHighEfficiency;   //!
   TBranch        *b_ConvInfo_OneLeg2_isEcalMatched1Track;   //!
   TBranch        *b_ConvInfo_OneLeg2_isEcalMatched2Track;   //!
   TBranch        *b_Diphoton;   //!
   TBranch        *b_DiphotonVtx2;   //!
   TBranch        *b_DiphotonVtx3;   //!

   fTree(TTree *tree=0);
   virtual ~fTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(TString outfilename);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef fTree_cxx
fTree::fTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/BrandonSteveMerged/DoubleEG_Run2016B_V2.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/BrandonSteveMerged/DoubleEG_Run2016B_V2.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/BrandonSteveMerged/DoubleEG_Run2016B_V2.root:/diphotonAnalyzer");
      dir->GetObject("fTree",tree);

   }
   Init(tree);
}

fTree::~fTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t fTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t fTree::LoadTree(Long64_t entry)
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

void fTree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   JetInfo_pt = 0;
   JetInfo_eta = 0;
   JetInfo_phi = 0;
   JetInfo_mass = 0;
   JetInfo_energy = 0;
   JetInfo_passLooseID = 0;
   JetInfo_passTightID = 0;
   ConvInfo1_x = 0;
   ConvInfo1_y = 0;
   ConvInfo1_z = 0;
   ConvInfo1_r = 0;
   ConvInfo1_phi = 0;
   ConvInfo1_dPhiTracksAtVtx = 0;
   ConvInfo1_nTracks = 0;
   ConvInfo1_dxy = 0;
   ConvInfo1_dz = 0;
   ConvInfo1_vtxChi2 = 0;
   ConvInfo1_vtxNdof = 0;
   ConvInfo1_pairCotThetaSeparation = 0;
   ConvInfo1_photonPt = 0;
   ConvInfo1_track1InnerPx = 0;
   ConvInfo1_track1InnerPy = 0;
   ConvInfo1_track1InnerPz = 0;
   ConvInfo1_track2InnerPx = 0;
   ConvInfo1_track2InnerPy = 0;
   ConvInfo1_track2InnerPz = 0;
   ConvInfo1_dRToSc = 0;
   ConvInfo1_nSharedHits = 0;
   ConvInfo1_MVAout = 0;
   ConvInfo1_oneLegMVA = 0;
   ConvInfo1_nHitsBeforeVtx = 0;
   ConvInfo1_isUndefinedAlgo = 0;
   ConvInfo1_isEcalSeededAlgo = 0;
   ConvInfo1_isTrackerOnlyAlgo = 0;
   ConvInfo1_isMixedAlgo = 0;
   ConvInfo1_isPflowAlgo = 0;
   ConvInfo1_isGeneralTracksOnly = 0;
   ConvInfo1_isArbitratedEcalSeeded = 0;
   ConvInfo1_isArbitratedMerged = 0;
   ConvInfo1_isArbitratedMergedEcalGeneral = 0;
   ConvInfo1_isHighPurity = 0;
   ConvInfo1_isHighEfficiency = 0;
   ConvInfo1_isEcalMatched1Track = 0;
   ConvInfo1_isEcalMatched2Track = 0;
   ConvInfo2_x = 0;
   ConvInfo2_y = 0;
   ConvInfo2_z = 0;
   ConvInfo2_r = 0;
   ConvInfo2_phi = 0;
   ConvInfo2_dPhiTracksAtVtx = 0;
   ConvInfo2_nTracks = 0;
   ConvInfo2_dxy = 0;
   ConvInfo2_dz = 0;
   ConvInfo2_vtxChi2 = 0;
   ConvInfo2_vtxNdof = 0;
   ConvInfo2_pairCotThetaSeparation = 0;
   ConvInfo2_photonPt = 0;
   ConvInfo2_track1InnerPx = 0;
   ConvInfo2_track1InnerPy = 0;
   ConvInfo2_track1InnerPz = 0;
   ConvInfo2_track2InnerPx = 0;
   ConvInfo2_track2InnerPy = 0;
   ConvInfo2_track2InnerPz = 0;
   ConvInfo2_dRToSc = 0;
   ConvInfo2_nSharedHits = 0;
   ConvInfo2_MVAout = 0;
   ConvInfo2_oneLegMVA = 0;
   ConvInfo2_nHitsBeforeVtx = 0;
   ConvInfo2_isUndefinedAlgo = 0;
   ConvInfo2_isEcalSeededAlgo = 0;
   ConvInfo2_isTrackerOnlyAlgo = 0;
   ConvInfo2_isMixedAlgo = 0;
   ConvInfo2_isPflowAlgo = 0;
   ConvInfo2_isGeneralTracksOnly = 0;
   ConvInfo2_isArbitratedEcalSeeded = 0;
   ConvInfo2_isArbitratedMerged = 0;
   ConvInfo2_isArbitratedMergedEcalGeneral = 0;
   ConvInfo2_isHighPurity = 0;
   ConvInfo2_isHighEfficiency = 0;
   ConvInfo2_isEcalMatched1Track = 0;
   ConvInfo2_isEcalMatched2Track = 0;
   ConvInfo_OneLeg1_x = 0;
   ConvInfo_OneLeg1_y = 0;
   ConvInfo_OneLeg1_z = 0;
   ConvInfo_OneLeg1_r = 0;
   ConvInfo_OneLeg1_phi = 0;
   ConvInfo_OneLeg1_dPhiTracksAtVtx = 0;
   ConvInfo_OneLeg1_nTracks = 0;
   ConvInfo_OneLeg1_dxy = 0;
   ConvInfo_OneLeg1_dz = 0;
   ConvInfo_OneLeg1_vtxChi2 = 0;
   ConvInfo_OneLeg1_vtxNdof = 0;
   ConvInfo_OneLeg1_pairCotThetaSeparation = 0;
   ConvInfo_OneLeg1_photonPt = 0;
   ConvInfo_OneLeg1_track1InnerPx = 0;
   ConvInfo_OneLeg1_track1InnerPy = 0;
   ConvInfo_OneLeg1_track1InnerPz = 0;
   ConvInfo_OneLeg1_track2InnerPx = 0;
   ConvInfo_OneLeg1_track2InnerPy = 0;
   ConvInfo_OneLeg1_track2InnerPz = 0;
   ConvInfo_OneLeg1_dRToSc = 0;
   ConvInfo_OneLeg1_nSharedHits = 0;
   ConvInfo_OneLeg1_MVAout = 0;
   ConvInfo_OneLeg1_oneLegMVA = 0;
   ConvInfo_OneLeg1_nHitsBeforeVtx = 0;
   ConvInfo_OneLeg1_isUndefinedAlgo = 0;
   ConvInfo_OneLeg1_isEcalSeededAlgo = 0;
   ConvInfo_OneLeg1_isTrackerOnlyAlgo = 0;
   ConvInfo_OneLeg1_isMixedAlgo = 0;
   ConvInfo_OneLeg1_isPflowAlgo = 0;
   ConvInfo_OneLeg1_isGeneralTracksOnly = 0;
   ConvInfo_OneLeg1_isArbitratedEcalSeeded = 0;
   ConvInfo_OneLeg1_isArbitratedMerged = 0;
   ConvInfo_OneLeg1_isArbitratedMergedEcalGeneral = 0;
   ConvInfo_OneLeg1_isHighPurity = 0;
   ConvInfo_OneLeg1_isHighEfficiency = 0;
   ConvInfo_OneLeg1_isEcalMatched1Track = 0;
   ConvInfo_OneLeg1_isEcalMatched2Track = 0;
   ConvInfo_OneLeg2_x = 0;
   ConvInfo_OneLeg2_y = 0;
   ConvInfo_OneLeg2_z = 0;
   ConvInfo_OneLeg2_r = 0;
   ConvInfo_OneLeg2_phi = 0;
   ConvInfo_OneLeg2_dPhiTracksAtVtx = 0;
   ConvInfo_OneLeg2_nTracks = 0;
   ConvInfo_OneLeg2_dxy = 0;
   ConvInfo_OneLeg2_dz = 0;
   ConvInfo_OneLeg2_vtxChi2 = 0;
   ConvInfo_OneLeg2_vtxNdof = 0;
   ConvInfo_OneLeg2_pairCotThetaSeparation = 0;
   ConvInfo_OneLeg2_photonPt = 0;
   ConvInfo_OneLeg2_track1InnerPx = 0;
   ConvInfo_OneLeg2_track1InnerPy = 0;
   ConvInfo_OneLeg2_track1InnerPz = 0;
   ConvInfo_OneLeg2_track2InnerPx = 0;
   ConvInfo_OneLeg2_track2InnerPy = 0;
   ConvInfo_OneLeg2_track2InnerPz = 0;
   ConvInfo_OneLeg2_dRToSc = 0;
   ConvInfo_OneLeg2_nSharedHits = 0;
   ConvInfo_OneLeg2_MVAout = 0;
   ConvInfo_OneLeg2_oneLegMVA = 0;
   ConvInfo_OneLeg2_nHitsBeforeVtx = 0;
   ConvInfo_OneLeg2_isUndefinedAlgo = 0;
   ConvInfo_OneLeg2_isEcalSeededAlgo = 0;
   ConvInfo_OneLeg2_isTrackerOnlyAlgo = 0;
   ConvInfo_OneLeg2_isMixedAlgo = 0;
   ConvInfo_OneLeg2_isPflowAlgo = 0;
   ConvInfo_OneLeg2_isGeneralTracksOnly = 0;
   ConvInfo_OneLeg2_isArbitratedEcalSeeded = 0;
   ConvInfo_OneLeg2_isArbitratedMerged = 0;
   ConvInfo_OneLeg2_isArbitratedMergedEcalGeneral = 0;
   ConvInfo_OneLeg2_isHighPurity = 0;
   ConvInfo_OneLeg2_isHighEfficiency = 0;
   ConvInfo_OneLeg2_isEcalMatched1Track = 0;
   ConvInfo_OneLeg2_isEcalMatched2Track = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Event", &Event_run, &b_Event);
   fChain->SetBranchAddress("Vtx", &Vtx_vx, &b_Vtx);
   fChain->SetBranchAddress("Vtx2", &Vtx2_vx, &b_Vtx2);
   fChain->SetBranchAddress("Vtx3", &Vtx3_vx, &b_Vtx3);
   fChain->SetBranchAddress("VtxGEN", &VtxGEN_vx, &b_VtxGEN);
   fChain->SetBranchAddress("rho25", &rho25, &b_rho25);
   fChain->SetBranchAddress("pu_n", &pu_n, &b_pu_n);
   fChain->SetBranchAddress("old_pu_n", &old_pu_n, &b_old_pu_n);
   fChain->SetBranchAddress("MCPUWeight", &MCPUWeight, &b_MCPUWeight);
   fChain->SetBranchAddress("BeamSpot", &BeamSpot_x0, &b_BeamSpot);
   fChain->SetBranchAddress("L1trg", &L1trg_L1_Tech0, &b_L1trg);
   fChain->SetBranchAddress("TrigHLT", &TrigHLT_HLT_MinBiasBSC, &b_TrigHLT);
   fChain->SetBranchAddress("nTightPhotons", &nTightPhotons, &b_nTightPhotons);
   fChain->SetBranchAddress("nFakeablePhotons", &nFakeablePhotons, &b_nFakeablePhotons);
   fChain->SetBranchAddress("Photon1", &Photon1_pt, &b_Photon1);
   fChain->SetBranchAddress("Photon2", &Photon2_pt, &b_Photon2);
   fChain->SetBranchAddress("JetInfo.pt", &JetInfo_pt, &b_JetInfo_pt);
   fChain->SetBranchAddress("JetInfo.eta", &JetInfo_eta, &b_JetInfo_eta);
   fChain->SetBranchAddress("JetInfo.phi", &JetInfo_phi, &b_JetInfo_phi);
   fChain->SetBranchAddress("JetInfo.mass", &JetInfo_mass, &b_JetInfo_mass);
   fChain->SetBranchAddress("JetInfo.energy", &JetInfo_energy, &b_JetInfo_energy);
   fChain->SetBranchAddress("JetInfo.passLooseID", &JetInfo_passLooseID, &b_JetInfo_passLooseID);
   fChain->SetBranchAddress("JetInfo.passTightID", &JetInfo_passTightID, &b_JetInfo_passTightID);
   fChain->SetBranchAddress("JetInfo.HT", &JetInfo_HT, &b_JetInfo_HT);
   fChain->SetBranchAddress("JetInfo.missingHT", &JetInfo_missingHT, &b_JetInfo_missingHT);
   fChain->SetBranchAddress("ConvInfo1.x", &ConvInfo1_x, &b_ConvInfo1_x);
   fChain->SetBranchAddress("ConvInfo1.y", &ConvInfo1_y, &b_ConvInfo1_y);
   fChain->SetBranchAddress("ConvInfo1.z", &ConvInfo1_z, &b_ConvInfo1_z);
   fChain->SetBranchAddress("ConvInfo1.r", &ConvInfo1_r, &b_ConvInfo1_r);
   fChain->SetBranchAddress("ConvInfo1.phi", &ConvInfo1_phi, &b_ConvInfo1_phi);
   fChain->SetBranchAddress("ConvInfo1.dPhiTracksAtVtx", &ConvInfo1_dPhiTracksAtVtx, &b_ConvInfo1_dPhiTracksAtVtx);
   fChain->SetBranchAddress("ConvInfo1.nTracks", &ConvInfo1_nTracks, &b_ConvInfo1_nTracks);
   fChain->SetBranchAddress("ConvInfo1.dxy", &ConvInfo1_dxy, &b_ConvInfo1_dxy);
   fChain->SetBranchAddress("ConvInfo1.dz", &ConvInfo1_dz, &b_ConvInfo1_dz);
   fChain->SetBranchAddress("ConvInfo1.vtxChi2", &ConvInfo1_vtxChi2, &b_ConvInfo1_vtxChi2);
   fChain->SetBranchAddress("ConvInfo1.vtxNdof", &ConvInfo1_vtxNdof, &b_ConvInfo1_vtxNdof);
   fChain->SetBranchAddress("ConvInfo1.pairCotThetaSeparation", &ConvInfo1_pairCotThetaSeparation, &b_ConvInfo1_pairCotThetaSeparation);
   fChain->SetBranchAddress("ConvInfo1.photonPt", &ConvInfo1_photonPt, &b_ConvInfo1_photonPt);
   fChain->SetBranchAddress("ConvInfo1.track1InnerPx", &ConvInfo1_track1InnerPx, &b_ConvInfo1_track1InnerPx);
   fChain->SetBranchAddress("ConvInfo1.track1InnerPy", &ConvInfo1_track1InnerPy, &b_ConvInfo1_track1InnerPy);
   fChain->SetBranchAddress("ConvInfo1.track1InnerPz", &ConvInfo1_track1InnerPz, &b_ConvInfo1_track1InnerPz);
   fChain->SetBranchAddress("ConvInfo1.track2InnerPx", &ConvInfo1_track2InnerPx, &b_ConvInfo1_track2InnerPx);
   fChain->SetBranchAddress("ConvInfo1.track2InnerPy", &ConvInfo1_track2InnerPy, &b_ConvInfo1_track2InnerPy);
   fChain->SetBranchAddress("ConvInfo1.track2InnerPz", &ConvInfo1_track2InnerPz, &b_ConvInfo1_track2InnerPz);
   fChain->SetBranchAddress("ConvInfo1.dRToSc", &ConvInfo1_dRToSc, &b_ConvInfo1_dRToSc);
   fChain->SetBranchAddress("ConvInfo1.nSharedHits", &ConvInfo1_nSharedHits, &b_ConvInfo1_nSharedHits);
   fChain->SetBranchAddress("ConvInfo1.MVAout", &ConvInfo1_MVAout, &b_ConvInfo1_MVAout);
   fChain->SetBranchAddress("ConvInfo1.oneLegMVA", &ConvInfo1_oneLegMVA, &b_ConvInfo1_oneLegMVA);
   fChain->SetBranchAddress("ConvInfo1.nHitsBeforeVtx", &ConvInfo1_nHitsBeforeVtx, &b_ConvInfo1_nHitsBeforeVtx);
   fChain->SetBranchAddress("ConvInfo1.isUndefinedAlgo", &ConvInfo1_isUndefinedAlgo, &b_ConvInfo1_isUndefinedAlgo);
   fChain->SetBranchAddress("ConvInfo1.isEcalSeededAlgo", &ConvInfo1_isEcalSeededAlgo, &b_ConvInfo1_isEcalSeededAlgo);
   fChain->SetBranchAddress("ConvInfo1.isTrackerOnlyAlgo", &ConvInfo1_isTrackerOnlyAlgo, &b_ConvInfo1_isTrackerOnlyAlgo);
   fChain->SetBranchAddress("ConvInfo1.isMixedAlgo", &ConvInfo1_isMixedAlgo, &b_ConvInfo1_isMixedAlgo);
   fChain->SetBranchAddress("ConvInfo1.isPflowAlgo", &ConvInfo1_isPflowAlgo, &b_ConvInfo1_isPflowAlgo);
   fChain->SetBranchAddress("ConvInfo1.isGeneralTracksOnly", &ConvInfo1_isGeneralTracksOnly, &b_ConvInfo1_isGeneralTracksOnly);
   fChain->SetBranchAddress("ConvInfo1.isArbitratedEcalSeeded", &ConvInfo1_isArbitratedEcalSeeded, &b_ConvInfo1_isArbitratedEcalSeeded);
   fChain->SetBranchAddress("ConvInfo1.isArbitratedMerged", &ConvInfo1_isArbitratedMerged, &b_ConvInfo1_isArbitratedMerged);
   fChain->SetBranchAddress("ConvInfo1.isArbitratedMergedEcalGeneral", &ConvInfo1_isArbitratedMergedEcalGeneral, &b_ConvInfo1_isArbitratedMergedEcalGeneral);
   fChain->SetBranchAddress("ConvInfo1.isHighPurity", &ConvInfo1_isHighPurity, &b_ConvInfo1_isHighPurity);
   fChain->SetBranchAddress("ConvInfo1.isHighEfficiency", &ConvInfo1_isHighEfficiency, &b_ConvInfo1_isHighEfficiency);
   fChain->SetBranchAddress("ConvInfo1.isEcalMatched1Track", &ConvInfo1_isEcalMatched1Track, &b_ConvInfo1_isEcalMatched1Track);
   fChain->SetBranchAddress("ConvInfo1.isEcalMatched2Track", &ConvInfo1_isEcalMatched2Track, &b_ConvInfo1_isEcalMatched2Track);
   fChain->SetBranchAddress("ConvInfo2.x", &ConvInfo2_x, &b_ConvInfo2_x);
   fChain->SetBranchAddress("ConvInfo2.y", &ConvInfo2_y, &b_ConvInfo2_y);
   fChain->SetBranchAddress("ConvInfo2.z", &ConvInfo2_z, &b_ConvInfo2_z);
   fChain->SetBranchAddress("ConvInfo2.r", &ConvInfo2_r, &b_ConvInfo2_r);
   fChain->SetBranchAddress("ConvInfo2.phi", &ConvInfo2_phi, &b_ConvInfo2_phi);
   fChain->SetBranchAddress("ConvInfo2.dPhiTracksAtVtx", &ConvInfo2_dPhiTracksAtVtx, &b_ConvInfo2_dPhiTracksAtVtx);
   fChain->SetBranchAddress("ConvInfo2.nTracks", &ConvInfo2_nTracks, &b_ConvInfo2_nTracks);
   fChain->SetBranchAddress("ConvInfo2.dxy", &ConvInfo2_dxy, &b_ConvInfo2_dxy);
   fChain->SetBranchAddress("ConvInfo2.dz", &ConvInfo2_dz, &b_ConvInfo2_dz);
   fChain->SetBranchAddress("ConvInfo2.vtxChi2", &ConvInfo2_vtxChi2, &b_ConvInfo2_vtxChi2);
   fChain->SetBranchAddress("ConvInfo2.vtxNdof", &ConvInfo2_vtxNdof, &b_ConvInfo2_vtxNdof);
   fChain->SetBranchAddress("ConvInfo2.pairCotThetaSeparation", &ConvInfo2_pairCotThetaSeparation, &b_ConvInfo2_pairCotThetaSeparation);
   fChain->SetBranchAddress("ConvInfo2.photonPt", &ConvInfo2_photonPt, &b_ConvInfo2_photonPt);
   fChain->SetBranchAddress("ConvInfo2.track1InnerPx", &ConvInfo2_track1InnerPx, &b_ConvInfo2_track1InnerPx);
   fChain->SetBranchAddress("ConvInfo2.track1InnerPy", &ConvInfo2_track1InnerPy, &b_ConvInfo2_track1InnerPy);
   fChain->SetBranchAddress("ConvInfo2.track1InnerPz", &ConvInfo2_track1InnerPz, &b_ConvInfo2_track1InnerPz);
   fChain->SetBranchAddress("ConvInfo2.track2InnerPx", &ConvInfo2_track2InnerPx, &b_ConvInfo2_track2InnerPx);
   fChain->SetBranchAddress("ConvInfo2.track2InnerPy", &ConvInfo2_track2InnerPy, &b_ConvInfo2_track2InnerPy);
   fChain->SetBranchAddress("ConvInfo2.track2InnerPz", &ConvInfo2_track2InnerPz, &b_ConvInfo2_track2InnerPz);
   fChain->SetBranchAddress("ConvInfo2.dRToSc", &ConvInfo2_dRToSc, &b_ConvInfo2_dRToSc);
   fChain->SetBranchAddress("ConvInfo2.nSharedHits", &ConvInfo2_nSharedHits, &b_ConvInfo2_nSharedHits);
   fChain->SetBranchAddress("ConvInfo2.MVAout", &ConvInfo2_MVAout, &b_ConvInfo2_MVAout);
   fChain->SetBranchAddress("ConvInfo2.oneLegMVA", &ConvInfo2_oneLegMVA, &b_ConvInfo2_oneLegMVA);
   fChain->SetBranchAddress("ConvInfo2.nHitsBeforeVtx", &ConvInfo2_nHitsBeforeVtx, &b_ConvInfo2_nHitsBeforeVtx);
   fChain->SetBranchAddress("ConvInfo2.isUndefinedAlgo", &ConvInfo2_isUndefinedAlgo, &b_ConvInfo2_isUndefinedAlgo);
   fChain->SetBranchAddress("ConvInfo2.isEcalSeededAlgo", &ConvInfo2_isEcalSeededAlgo, &b_ConvInfo2_isEcalSeededAlgo);
   fChain->SetBranchAddress("ConvInfo2.isTrackerOnlyAlgo", &ConvInfo2_isTrackerOnlyAlgo, &b_ConvInfo2_isTrackerOnlyAlgo);
   fChain->SetBranchAddress("ConvInfo2.isMixedAlgo", &ConvInfo2_isMixedAlgo, &b_ConvInfo2_isMixedAlgo);
   fChain->SetBranchAddress("ConvInfo2.isPflowAlgo", &ConvInfo2_isPflowAlgo, &b_ConvInfo2_isPflowAlgo);
   fChain->SetBranchAddress("ConvInfo2.isGeneralTracksOnly", &ConvInfo2_isGeneralTracksOnly, &b_ConvInfo2_isGeneralTracksOnly);
   fChain->SetBranchAddress("ConvInfo2.isArbitratedEcalSeeded", &ConvInfo2_isArbitratedEcalSeeded, &b_ConvInfo2_isArbitratedEcalSeeded);
   fChain->SetBranchAddress("ConvInfo2.isArbitratedMerged", &ConvInfo2_isArbitratedMerged, &b_ConvInfo2_isArbitratedMerged);
   fChain->SetBranchAddress("ConvInfo2.isArbitratedMergedEcalGeneral", &ConvInfo2_isArbitratedMergedEcalGeneral, &b_ConvInfo2_isArbitratedMergedEcalGeneral);
   fChain->SetBranchAddress("ConvInfo2.isHighPurity", &ConvInfo2_isHighPurity, &b_ConvInfo2_isHighPurity);
   fChain->SetBranchAddress("ConvInfo2.isHighEfficiency", &ConvInfo2_isHighEfficiency, &b_ConvInfo2_isHighEfficiency);
   fChain->SetBranchAddress("ConvInfo2.isEcalMatched1Track", &ConvInfo2_isEcalMatched1Track, &b_ConvInfo2_isEcalMatched1Track);
   fChain->SetBranchAddress("ConvInfo2.isEcalMatched2Track", &ConvInfo2_isEcalMatched2Track, &b_ConvInfo2_isEcalMatched2Track);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.x", &ConvInfo_OneLeg1_x, &b_ConvInfo_OneLeg1_x);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.y", &ConvInfo_OneLeg1_y, &b_ConvInfo_OneLeg1_y);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.z", &ConvInfo_OneLeg1_z, &b_ConvInfo_OneLeg1_z);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.r", &ConvInfo_OneLeg1_r, &b_ConvInfo_OneLeg1_r);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.phi", &ConvInfo_OneLeg1_phi, &b_ConvInfo_OneLeg1_phi);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.dPhiTracksAtVtx", &ConvInfo_OneLeg1_dPhiTracksAtVtx, &b_ConvInfo_OneLeg1_dPhiTracksAtVtx);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.nTracks", &ConvInfo_OneLeg1_nTracks, &b_ConvInfo_OneLeg1_nTracks);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.dxy", &ConvInfo_OneLeg1_dxy, &b_ConvInfo_OneLeg1_dxy);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.dz", &ConvInfo_OneLeg1_dz, &b_ConvInfo_OneLeg1_dz);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.vtxChi2", &ConvInfo_OneLeg1_vtxChi2, &b_ConvInfo_OneLeg1_vtxChi2);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.vtxNdof", &ConvInfo_OneLeg1_vtxNdof, &b_ConvInfo_OneLeg1_vtxNdof);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.pairCotThetaSeparation", &ConvInfo_OneLeg1_pairCotThetaSeparation, &b_ConvInfo_OneLeg1_pairCotThetaSeparation);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.photonPt", &ConvInfo_OneLeg1_photonPt, &b_ConvInfo_OneLeg1_photonPt);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.track1InnerPx", &ConvInfo_OneLeg1_track1InnerPx, &b_ConvInfo_OneLeg1_track1InnerPx);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.track1InnerPy", &ConvInfo_OneLeg1_track1InnerPy, &b_ConvInfo_OneLeg1_track1InnerPy);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.track1InnerPz", &ConvInfo_OneLeg1_track1InnerPz, &b_ConvInfo_OneLeg1_track1InnerPz);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.track2InnerPx", &ConvInfo_OneLeg1_track2InnerPx, &b_ConvInfo_OneLeg1_track2InnerPx);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.track2InnerPy", &ConvInfo_OneLeg1_track2InnerPy, &b_ConvInfo_OneLeg1_track2InnerPy);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.track2InnerPz", &ConvInfo_OneLeg1_track2InnerPz, &b_ConvInfo_OneLeg1_track2InnerPz);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.dRToSc", &ConvInfo_OneLeg1_dRToSc, &b_ConvInfo_OneLeg1_dRToSc);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.nSharedHits", &ConvInfo_OneLeg1_nSharedHits, &b_ConvInfo_OneLeg1_nSharedHits);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.MVAout", &ConvInfo_OneLeg1_MVAout, &b_ConvInfo_OneLeg1_MVAout);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.oneLegMVA", &ConvInfo_OneLeg1_oneLegMVA, &b_ConvInfo_OneLeg1_oneLegMVA);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.nHitsBeforeVtx", &ConvInfo_OneLeg1_nHitsBeforeVtx, &b_ConvInfo_OneLeg1_nHitsBeforeVtx);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.isUndefinedAlgo", &ConvInfo_OneLeg1_isUndefinedAlgo, &b_ConvInfo_OneLeg1_isUndefinedAlgo);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.isEcalSeededAlgo", &ConvInfo_OneLeg1_isEcalSeededAlgo, &b_ConvInfo_OneLeg1_isEcalSeededAlgo);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.isTrackerOnlyAlgo", &ConvInfo_OneLeg1_isTrackerOnlyAlgo, &b_ConvInfo_OneLeg1_isTrackerOnlyAlgo);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.isMixedAlgo", &ConvInfo_OneLeg1_isMixedAlgo, &b_ConvInfo_OneLeg1_isMixedAlgo);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.isPflowAlgo", &ConvInfo_OneLeg1_isPflowAlgo, &b_ConvInfo_OneLeg1_isPflowAlgo);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.isGeneralTracksOnly", &ConvInfo_OneLeg1_isGeneralTracksOnly, &b_ConvInfo_OneLeg1_isGeneralTracksOnly);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.isArbitratedEcalSeeded", &ConvInfo_OneLeg1_isArbitratedEcalSeeded, &b_ConvInfo_OneLeg1_isArbitratedEcalSeeded);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.isArbitratedMerged", &ConvInfo_OneLeg1_isArbitratedMerged, &b_ConvInfo_OneLeg1_isArbitratedMerged);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.isArbitratedMergedEcalGeneral", &ConvInfo_OneLeg1_isArbitratedMergedEcalGeneral, &b_ConvInfo_OneLeg1_isArbitratedMergedEcalGeneral);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.isHighPurity", &ConvInfo_OneLeg1_isHighPurity, &b_ConvInfo_OneLeg1_isHighPurity);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.isHighEfficiency", &ConvInfo_OneLeg1_isHighEfficiency, &b_ConvInfo_OneLeg1_isHighEfficiency);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.isEcalMatched1Track", &ConvInfo_OneLeg1_isEcalMatched1Track, &b_ConvInfo_OneLeg1_isEcalMatched1Track);
   fChain->SetBranchAddress("ConvInfo_OneLeg1.isEcalMatched2Track", &ConvInfo_OneLeg1_isEcalMatched2Track, &b_ConvInfo_OneLeg1_isEcalMatched2Track);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.x", &ConvInfo_OneLeg2_x, &b_ConvInfo_OneLeg2_x);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.y", &ConvInfo_OneLeg2_y, &b_ConvInfo_OneLeg2_y);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.z", &ConvInfo_OneLeg2_z, &b_ConvInfo_OneLeg2_z);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.r", &ConvInfo_OneLeg2_r, &b_ConvInfo_OneLeg2_r);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.phi", &ConvInfo_OneLeg2_phi, &b_ConvInfo_OneLeg2_phi);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.dPhiTracksAtVtx", &ConvInfo_OneLeg2_dPhiTracksAtVtx, &b_ConvInfo_OneLeg2_dPhiTracksAtVtx);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.nTracks", &ConvInfo_OneLeg2_nTracks, &b_ConvInfo_OneLeg2_nTracks);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.dxy", &ConvInfo_OneLeg2_dxy, &b_ConvInfo_OneLeg2_dxy);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.dz", &ConvInfo_OneLeg2_dz, &b_ConvInfo_OneLeg2_dz);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.vtxChi2", &ConvInfo_OneLeg2_vtxChi2, &b_ConvInfo_OneLeg2_vtxChi2);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.vtxNdof", &ConvInfo_OneLeg2_vtxNdof, &b_ConvInfo_OneLeg2_vtxNdof);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.pairCotThetaSeparation", &ConvInfo_OneLeg2_pairCotThetaSeparation, &b_ConvInfo_OneLeg2_pairCotThetaSeparation);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.photonPt", &ConvInfo_OneLeg2_photonPt, &b_ConvInfo_OneLeg2_photonPt);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.track1InnerPx", &ConvInfo_OneLeg2_track1InnerPx, &b_ConvInfo_OneLeg2_track1InnerPx);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.track1InnerPy", &ConvInfo_OneLeg2_track1InnerPy, &b_ConvInfo_OneLeg2_track1InnerPy);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.track1InnerPz", &ConvInfo_OneLeg2_track1InnerPz, &b_ConvInfo_OneLeg2_track1InnerPz);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.track2InnerPx", &ConvInfo_OneLeg2_track2InnerPx, &b_ConvInfo_OneLeg2_track2InnerPx);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.track2InnerPy", &ConvInfo_OneLeg2_track2InnerPy, &b_ConvInfo_OneLeg2_track2InnerPy);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.track2InnerPz", &ConvInfo_OneLeg2_track2InnerPz, &b_ConvInfo_OneLeg2_track2InnerPz);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.dRToSc", &ConvInfo_OneLeg2_dRToSc, &b_ConvInfo_OneLeg2_dRToSc);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.nSharedHits", &ConvInfo_OneLeg2_nSharedHits, &b_ConvInfo_OneLeg2_nSharedHits);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.MVAout", &ConvInfo_OneLeg2_MVAout, &b_ConvInfo_OneLeg2_MVAout);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.oneLegMVA", &ConvInfo_OneLeg2_oneLegMVA, &b_ConvInfo_OneLeg2_oneLegMVA);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.nHitsBeforeVtx", &ConvInfo_OneLeg2_nHitsBeforeVtx, &b_ConvInfo_OneLeg2_nHitsBeforeVtx);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.isUndefinedAlgo", &ConvInfo_OneLeg2_isUndefinedAlgo, &b_ConvInfo_OneLeg2_isUndefinedAlgo);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.isEcalSeededAlgo", &ConvInfo_OneLeg2_isEcalSeededAlgo, &b_ConvInfo_OneLeg2_isEcalSeededAlgo);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.isTrackerOnlyAlgo", &ConvInfo_OneLeg2_isTrackerOnlyAlgo, &b_ConvInfo_OneLeg2_isTrackerOnlyAlgo);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.isMixedAlgo", &ConvInfo_OneLeg2_isMixedAlgo, &b_ConvInfo_OneLeg2_isMixedAlgo);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.isPflowAlgo", &ConvInfo_OneLeg2_isPflowAlgo, &b_ConvInfo_OneLeg2_isPflowAlgo);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.isGeneralTracksOnly", &ConvInfo_OneLeg2_isGeneralTracksOnly, &b_ConvInfo_OneLeg2_isGeneralTracksOnly);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.isArbitratedEcalSeeded", &ConvInfo_OneLeg2_isArbitratedEcalSeeded, &b_ConvInfo_OneLeg2_isArbitratedEcalSeeded);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.isArbitratedMerged", &ConvInfo_OneLeg2_isArbitratedMerged, &b_ConvInfo_OneLeg2_isArbitratedMerged);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.isArbitratedMergedEcalGeneral", &ConvInfo_OneLeg2_isArbitratedMergedEcalGeneral, &b_ConvInfo_OneLeg2_isArbitratedMergedEcalGeneral);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.isHighPurity", &ConvInfo_OneLeg2_isHighPurity, &b_ConvInfo_OneLeg2_isHighPurity);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.isHighEfficiency", &ConvInfo_OneLeg2_isHighEfficiency, &b_ConvInfo_OneLeg2_isHighEfficiency);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.isEcalMatched1Track", &ConvInfo_OneLeg2_isEcalMatched1Track, &b_ConvInfo_OneLeg2_isEcalMatched1Track);
   fChain->SetBranchAddress("ConvInfo_OneLeg2.isEcalMatched2Track", &ConvInfo_OneLeg2_isEcalMatched2Track, &b_ConvInfo_OneLeg2_isEcalMatched2Track);
   fChain->SetBranchAddress("Diphoton", &Diphoton_Minv, &b_Diphoton);
   fChain->SetBranchAddress("DiphotonVtx2", &DiphotonVtx2_Minv, &b_DiphotonVtx2);
   fChain->SetBranchAddress("DiphotonVtx3", &DiphotonVtx3_Minv, &b_DiphotonVtx3);
   Notify();
}

Bool_t fTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void fTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t fTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef fTree_cxx
