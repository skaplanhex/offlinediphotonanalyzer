#define fTree_cxx
#include "fTree.h"
#include "helperFunctions.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>




void fTree::Loop(TString outfilename)
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

    Double_t bins_30003500[6] = {0.,650.,1150.,1800.,2600.,13000.};
    Double_t bins[7] = {0.,650.,1150.,1800.,2600.,3500.,13000.};

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

    // VBF tagged histograms
    TH1D* leadingPhoPt_VBFTagged_EBEB = createTH1D("leadingPhoPt_VBFTagged_EBEB","leadingPhoPt_VBFTagged_EBEB",300.,0.,1500.,"Leading Photon pT (GeV/c)","Events");
    TH1D* subleadingPhoPt_VBFTagged_EBEB = createTH1D("subleadingPhoPt_VBFTagged_EBEB","subleadingPhoPt_VBFTagged_EBEB",300,0.,1500.,"Subleading Photon pT (GeV/c)","Events");
    TH1D* leadingPhoEta_VBFTagged_EBEB = createTH1D("leadingPhoEta_VBFTagged_EBEB","leadingPhoEta_VBFTagged_EBEB",100,-5.,5.,"Leading Photon #eta","Events");
    TH1D* subleadingPhoEta_VBFTagged_EBEB = createTH1D("subleadingPhoEta_VBFTagged_EBEB","subleadingPhoEta_VBFTagged_EBEB",100,-5.,5.,"Subleading Photon #eta","Events");
    TH1D* leadingPhoPhi_VBFTagged_EBEB = createTH1D("leadingPhoPhi_VBFTagged_EBEB","leadingPhoPhi_VBFTagged_EBEB",100,-3.141593,-3.141593,"Leading Photon #phi","Events");
    TH1D* subleadingPhoPhi_VBFTagged_EBEB = createTH1D("subleadingPhoPhi_VBFTagged_EBEB","subleadingPhoPhi_VBFTagged_EBEB",100,-3.141593,-3.141593,"Subleading Photon #phi","Events");
    TH1D* ggMass_VBFTagged_EBEB = createTH1D("ggMass_VBFTagged_EBEB","ggMass_VBFTagged_EBEB",151,-10.,3010.,"m_{#gamma#gamma} (GeV/c^{2})","Events");

    TH1D* leadingPhoPt_VBFTagged_EBEE = createTH1D("leadingPhoPt_VBFTagged_EBEE","leadingPhoPt_VBFTagged_EBEE",300.,0.,1500.,"Leading Photon pT (GeV/c)","Events");
    TH1D* subleadingPhoPt_VBFTagged_EBEE = createTH1D("subleadingPhoPt_VBFTagged_EBEE","subleadingPhoPt_VBFTagged_EBEE",300,0.,1500.,"Subleading Photon pT (GeV/c)","Events");
    TH1D* leadingPhoEta_VBFTagged_EBEE = createTH1D("leadingPhoEta_VBFTagged_EBEE","leadingPhoEta_VBFTagged_EBEE",100,-5.,5.,"Leading Photon #eta","Events");
    TH1D* subleadingPhoEta_VBFTagged_EBEE = createTH1D("subleadingPhoEta_VBFTagged_EBEE","subleadingPhoEta_VBFTagged_EBEE",100,-5.,5.,"Subleading Photon #eta","Events");
    TH1D* leadingPhoPhi_VBFTagged_EBEE = createTH1D("leadingPhoPhi_VBFTagged_EBEE","leadingPhoPhi_VBFTagged_EBEE",100,-3.141593,-3.141593,"Leading Photon #phi","Events");
    TH1D* subleadingPhoPhi_VBFTagged_EBEE = createTH1D("subleadingPhoPhi_VBFTagged_EBEE","subleadingPhoPhi_VBFTagged_EBEE",100,-3.141593,-3.141593,"Subleading Photon #phi","Events");
    TH1D* ggMass_VBFTagged_EBEE = createTH1D("ggMass_VBFTagged_EBEE","ggMass_VBFTagged_EBEE",151,-10.,3010.,"m_{#gamma#gamma} (GeV/c^{2})","Events");

    // Jet histograms
    TH1D* nJets_EBEB = createTH1D("nJets_EBEB","nJets_EBEB",27,-0.5,26.5,"Jet Multiplicity","Number of Jets");
    TH1D* leadingjetPt_EBEB = createTH1D("leadingjetPt_EBEB","leadingjetPt_EBEB",300,0,2500,"Jet pT (GeV/c)","Number of Jets");
    TH1D* leadingjetEta_EBEB = createTH1D("leadingjetEta_EBEB","leadingjetEta_EBEB",300,-5.,5.,"Jet #eta","Number of Jets");
    TH1D* leadingjetPhi_EBEB = createTH1D("leadingjetPhi_EBEB","leadingjetPhi_EBEB",300,-3.1416,3.1416,"Jet #varphi","Number of Jets");
    TH1D* leadingjetET_EBEB = createTH1D("leadingjetET_EBEB","leadingjetET_EBEB",300,0,2500,"Jet E_{T} (GeV)","Number of Jets");
    TH1D* leadingjetMass_EBEB = createTH1D("leadingjetMass_EBEB","leadingjetMass_EBEB",300,0,2500,"Jet Mass (GeV/c^{2})","Number of Jets");

    TH1D* nJets_EBEE = createTH1D("nJets_EBEE","nJets_EBEE",27,-0.5,26.5,"Jet Multiplicity","Number of Jets");
    TH1D* leadingjetPt_EBEE = createTH1D("leadingjetPt_EBEE","leadingjetPt_EBEE",300,0,2500,"Jet pT (GeV/c)","Number of Jets");
    TH1D* leadingjetEta_EBEE = createTH1D("leadingjetEta_EBEE","leadingjetEta_EBEE",300,-5.,5.,"Jet #eta","Number of Jets");
    TH1D* leadingjetPhi_EBEE = createTH1D("leadingjetPhi_EBEE","leadingjetPhi_EBEE",300,-3.1416,3.1416,"Jet #varphi","Number of Jets");
    TH1D* leadingjetET_EBEE = createTH1D("leadingjetET_EBEE","leadingjetET_EBEE",300,0,2500,"Jet E_{T} (GeV)","Number of Jets");
    TH1D* leadingjetMass_EBEE = createTH1D("leadingjetMass_EBEE","leadingjetMass_EBEE",300,0,2500,"Jet Mass (GeV/c^{2})","Number of Jets");

    TH1D* subleadingjetPt_EBEB = createTH1D("subleadingjetPt_EBEB","subleadingjetPt_EBEB",300,0,2500,"Jet pT (GeV/c)","Number of Jets");
    TH1D* subleadingjetEta_EBEB = createTH1D("subleadingjetEta_EBEB","subleadingjetEta_EBEB",300,-5.,5.,"Jet #eta","Number of Jets");
    TH1D* subleadingjetPhi_EBEB = createTH1D("subleadingjetPhi_EBEB","subleadingjetPhi_EBEB",300,-3.1416,3.1416,"Jet #varphi","Number of Jets");
    TH1D* subleadingjetET_EBEB = createTH1D("subleadingjetET_EBEB","subleadingjetET_EBEB",300,0,2500,"Jet E_{T} (GeV)","Number of Jets");
    TH1D* subleadingjetMass_EBEB = createTH1D("subleadingjetMass_EBEB","subleadingjetMass_EBEB",300,0,2500,"Jet Mass (GeV/c^{2})","Number of Jets");

    TH1D* subleadingjetPt_EBEE = createTH1D("subleadingjetPt_EBEE","subleadingjetPt_EBEE",300,0,2500,"Jet pT (GeV/c)","Number of Jets");
    TH1D* subleadingjetEta_EBEE = createTH1D("subleadingjetEta_EBEE","subleadingjetEta_EBEE",300,-5.,5.,"Jet #eta","Number of Jets");
    TH1D* subleadingjetPhi_EBEE = createTH1D("subleadingjetPhi_EBEE","subleadingjetPhi_EBEE",300,-3.1416,3.1416,"Jet #varphi","Number of Jets");
    TH1D* subleadingjetET_EBEE = createTH1D("subleadingjetET_EBEE","subleadingjetET_EBEE",300,0,2500,"Jet E_{T} (GeV)","Number of Jets");
    TH1D* subleadingjetMass_EBEE = createTH1D("subleadingjetMass_EBEE","subleadingjetMass_EBEE",300,0,2500,"Jet Mass (GeV/c^{2})","Number of Jets");

    TH1D* jetDEta_EBEB = createTH1D("jetDEta_EBEB","",200,0.,10.,"|#eta_{leading jet} - #eta_{subleading jet}|","Number Of Events");
    TH1D* dijetMass_EBEB = createTH1D("dijetMass_EBEB","",200,0.,4000.,"m_{jj} (GeV/c^{2})","Number Of Events");
    TH1D* jetPhoEtaDiff_EBEB = createTH1D("jetPhoEtaDiff_EBEB","",200,0.,10.,"|#bar{#eta_{j}} - #eta_{#gamma#gamma}|","Number Of Events");
    TH1D* jetPhoDPhi_EBEB = createTH1D("jetPhoDPhi_EBEB","",200,0.,3.1416,"#Delta#varphi(dijet,diphoton)","Number Of Events");

    TH1D* jetDEta_EBEE = createTH1D("jetDEta_EBEE","",200,0.,10.,"|#eta_{leading jet} - #eta_{subleading jet}|","Number Of Events");
    TH1D* dijetMass_EBEE = createTH1D("dijetMass_EBEE","",200,0.,4000.,"m_{jj} (GeV/c^{2})","Number Of Events");
    TH1D* jetPhoEtaDiff_EBEE = createTH1D("jetPhoEtaDiff_EBEE","",200,0.,10.,"|#bar{#eta_{j}} - #eta_{#gamma#gamma}|","Number Of Events");
    TH1D* jetPhoDPhi_EBEE = createTH1D("jetPhoDPhi_EBEE","",200,0.,3.1416,"#Delta#varphi(dijet,diphoton)","Number Of Events");

    // book conversion based histos
    TH1D* nConversions_allConvType_EB = createTH1D("nConversions_allConvType_EB","nConversions_allConvType_EB",240,0.,10.,"Conversion Multiplicity", "");
    TH1D* nConversions_allConvType_EE = createTH1D("nConversions_allConvType_EE","nConversions_allConvType_EE",240,0.,10.,"Conversion Multiplicity", "");
    TH1D* nConversions_allConvType_allEta = createTH1D("nConversions_allConvType_allEta","nConversions_allConvType_allEta",240,0.,10.,"Conversion Multiplicity", "");
    TH1D* nConversions_arbitratedMerged_EB = createTH1D("nConversions_arbitratedMerged_EB","nConversions_arbitratedMerged_EB",240,0.,10.,"Conversion Multiplicity", "");
    TH1D* nConversions_arbitratedMerged_EE = createTH1D("nConversions_arbitratedMerged_EE","nConversions_arbitratedMerged_EE",240,0.,10.,"Conversion Multiplicity", "");
    TH1D* nConversions_arbitratedMerged_allEta = createTH1D("nConversions_arbitratedMerged_allEta","nConversions_arbitratedMerged_allEta",240,0.,10.,"Conversion Multiplicity", "");
    TH1D* nConversions_highPurity_EB = createTH1D("nConversions_highPurity_EB","nConversions_highPurity_EB",240,0.,10.,"Conversion Multiplicity", "");
    TH1D* nConversions_highPurity_EE = createTH1D("nConversions_highPurity_EE","nConversions_highPurity_EE",240,0.,10.,"Conversion Multiplicity", "");
    TH1D* nConversions_highPurity_allEta = createTH1D("nConversions_highPurity_allEta","nConversions_highPurity_allEta",240,0.,10.,"Conversion Multiplicity", "");
    TH1D* nConversions_generalTracksOnly_EB = createTH1D("nConversions_generalTracksOnly_EB","nConversions_generalTracksOnly_EB",240,0.,10.,"Conversion Multiplicity", "");
    TH1D* nConversions_generalTracksOnly_EE = createTH1D("nConversions_generalTracksOnly_EE","nConversions_generalTracksOnly_EE",240,0.,10.,"Conversion Multiplicity", "");
    TH1D* nConversions_generalTracksOnly_allEta = createTH1D("nConversions_generalTracksOnly_allEta","nConversions_generalTracksOnly_allEta",240,0.,10.,"Conversion Multiplicity", "");

    TH1D* conversionRadius_allConvType_EB = createTH1D("conversionRadius_allConvType_EB","conversionRadius_allConvType_EB",240,0.,120.,"Conversion Radius (cm)", "Number of Conversions");
    TH1D* conversionRadius_allConvType_EE = createTH1D("conversionRadius_allConvType_EE","conversionRadius_allConvType_EE",240,0.,120.,"Conversion Radius (cm)", "Number of Conversions");
    TH1D* conversionRadius_allConvType_allEta = createTH1D("conversionRadius_allConvType_allEta","conversionRadius_allConvType_allEta",240,0.,120.,"Conversion Radius (cm)", "Number of Conversions");
    TH1D* conversionRadius_arbitratedMerged_EB = createTH1D("conversionRadius_arbitratedMerged_EB","conversionRadius_arbitratedMerged_EB",240,0.,120.,"Conversion Radius (cm)", "Number of Conversions");
    TH1D* conversionRadius_arbitratedMerged_EE = createTH1D("conversionRadius_arbitratedMerged_EE","conversionRadius_arbitratedMerged_EE",240,0.,120.,"Conversion Radius (cm)", "Number of Conversions");
    TH1D* conversionRadius_arbitratedMerged_allEta = createTH1D("conversionRadius_arbitratedMerged_allEta","conversionRadius_arbitratedMerged_allEta",240,0.,120.,"Conversion Radius (cm)", "Number of Conversions");
    TH1D* conversionRadius_highPurity_EB = createTH1D("conversionRadius_highPurity_EB","conversionRadius_highPurity_EB",240,0.,120.,"Conversion Radius (cm)", "Number of Conversions");
    TH1D* conversionRadius_highPurity_EE = createTH1D("conversionRadius_highPurity_EE","conversionRadius_highPurity_EE",240,0.,120.,"Conversion Radius (cm)", "Number of Conversions");
    TH1D* conversionRadius_highPurity_allEta = createTH1D("conversionRadius_highPurity_allEta","conversionRadius_highPurity_allEta",240,0.,120.,"Conversion Radius (cm)", "Number of Conversions");
    TH1D* conversionRadius_generalTracksOnly_EB = createTH1D("conversionRadius_generalTracksOnly_EB","conversionRadius_generalTracksOnly_EB",240,0.,120.,"Conversion Radius (cm)", "Number of Conversions");
    TH1D* conversionRadius_generalTracksOnly_EE = createTH1D("conversionRadius_generalTracksOnly_EE","conversionRadius_generalTracksOnly_EE",240,0.,120.,"Conversion Radius (cm)", "Number of Conversions");
    TH1D* conversionRadius_generalTracksOnly_allEta = createTH1D("conversionRadius_generalTracksOnly_allEta","conversionRadius_generalTracksOnly_allEta",240,0.,120.,"Conversion Radius (cm)", "Number of Conversions");

    // TH1D* pairCotThetaSeparation_EB = createTH1D("pairCotThetaSeparation_EB","pairCotThetaSeparation_EB",100,-8.,2.,"pairCotThetaSeparation","Number of Conversions");
    // TH1D* dPhiTracksAtVtx_EB = createTH1D("dPhiTracksAtVtx_EB","dPhiTracksAtVtx_EB",100,-3.1416,3.1416,"#Delta#varphi of Tracks At Vtx","Number of Conversions");
    // TH1D* photonConvdR_EB = createTH1D("photonConvdR_EB","photonConvdR_EB",100,0.,0.2,"#DeltaR(conversion,#gamma)","Number of Conversions");
    // TH1D* nSharedHits_EB = createTH1D("nSharedHits_EB","nSharedHits_EB",21,-0.5,20.5,"Number of Shared Hits","Number of Conversions");

    // TH1D* pairCotThetaSeparation_EE = createTH1D("pairCotThetaSeparation_EE","pairCotThetaSeparation_EE",100,-8.,2.,"pairCotThetaSeparation","Number of Conversions");
    // TH1D* dPhiTracksAtVtx_EE = createTH1D("dPhiTracksAtVtx_EE","dPhiTracksAtVtx_EE",100,-3.1416,3.1416,"#Delta#varphi of Tracks At Vtx","Number of Conversions");
    // TH1D* photonConvdR_EE = createTH1D("photonConvdR_EE","photonConvdR_EE",100,0.,0.2,"#DeltaR(conversion,#gamma)","Number of Conversions");
    // TH1D* nSharedHits_EE = createTH1D("nSharedHits_EE","nSharedHits_EE",21,-0.5,20.5,"Number of Shared Hits","Number of Conversions");

    // conversion vertex maps based on eta location
    TH2D* twoProngConversionXYMap_allConvType_EB = createTH2D("twoProngConversionXYMap_allConvType_EB","twoProngConversionXYMap_allConvType_EB",280,-140.,140.,280,-140.,140.,"x (cm)","y (cm)");
    TH2D* twoProngConversionRZMap_allConvType_EB = createTH2D("twoProngConversionRZMap_allConvType_EB","twoProngConversionRZMap_allConvType_EB",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    TH2D* twoProngConversionXYMap_allConvType_EE = createTH2D("twoProngConversionXYMap_allConvType_EE","twoProngConversionXYMap_allConvType_EE",280,-140.,140.,280,-140.,140.,"x (cm)","y (cm)");
    TH2D* twoProngConversionRZMap_allConvType_EE = createTH2D("twoProngConversionRZMap_allConvType_EE","twoProngConversionRZMap_allConvType_EE",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    TH2D* twoProngConversionXYMap_allConvType_allEta = createTH2D("twoProngConversionXYMap_allConvType_allEta","twoProngConversionXYMap_allConvType_allEta",280,-140.,140.,280,-140.,140.,"x (cm)","y (cm)");
    TH2D* twoProngConversionRZMap_allConvType_allEta = createTH2D("twoProngConversionRZMap_allConvType_allEta","twoProngConversionRZMap_allConvType_allEta",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    TH2D* twoProngConversionXYMap_arbitratedMerged_EB = createTH2D("twoProngConversionXYMap_arbitratedMerged_EB","twoProngConversionXYMap_arbitratedMerged_EB",280,-140.,140.,280,-140.,140.,"x (cm)","y (cm)");
    TH2D* twoProngConversionRZMap_arbitratedMerged_EB = createTH2D("twoProngConversionRZMap_arbitratedMerged_EB","twoProngConversionRZMap_arbitratedMerged_EB",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    TH2D* twoProngConversionXYMap_arbitratedMerged_EE = createTH2D("twoProngConversionXYMap_arbitratedMerged_EE","twoProngConversionXYMap_arbitratedMerged_EE",280,-140.,140.,280,-140.,140.,"x (cm)","y (cm)");
    TH2D* twoProngConversionRZMap_arbitratedMerged_EE = createTH2D("twoProngConversionRZMap_arbitratedMerged_EE","twoProngConversionRZMap_arbitratedMerged_EE",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    TH2D* twoProngConversionXYMap_arbitratedMerged_allEta = createTH2D("twoProngConversionXYMap_arbitratedMerged_allEta","twoProngConversionXYMap_arbitratedMerged_allEta",280,-140.,140.,280,-140.,140.,"x (cm)","y (cm)");
    TH2D* twoProngConversionRZMap_arbitratedMerged_allEta = createTH2D("twoProngConversionRZMap_arbitratedMerged_allEta","twoProngConversionRZMap_arbitratedMerged_allEta",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    TH2D* twoProngConversionXYMap_highPurity_EB = createTH2D("twoProngConversionXYMap_highPurity_EB","twoProngConversionXYMap_highPurity_EB",280,-140.,140.,280,-140.,140.,"x (cm)","y (cm)");
    TH2D* twoProngConversionRZMap_highPurity_EB = createTH2D("twoProngConversionRZMap_highPurity_EB","twoProngConversionRZMap_highPurity_EB",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    TH2D* twoProngConversionXYMap_highPurity_EE = createTH2D("twoProngConversionXYMap_highPurity_EE","twoProngConversionXYMap_highPurity_EE",280,-140.,140.,280,-140.,140.,"x (cm)","y (cm)");
    TH2D* twoProngConversionRZMap_highPurity_EE = createTH2D("twoProngConversionRZMap_highPurity_EE","twoProngConversionRZMap_highPurity_EE",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    TH2D* twoProngConversionXYMap_highPurity_allEta = createTH2D("twoProngConversionXYMap_highPurity_allEta","twoProngConversionXYMap_highPurity_allEta",280,-140.,140.,280,-140.,140.,"x (cm)","y (cm)");
    TH2D* twoProngConversionRZMap_highPurity_allEta = createTH2D("twoProngConversionRZMap_highPurity_allEta","twoProngConversionRZMap_highPurity_allEta",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    TH2D* twoProngConversionXYMap_generalTracksOnly_EB = createTH2D("twoProngConversionXYMap_generalTracksOnly_EB","twoProngConversionXYMap_generalTracksOnly_EB",280,-140.,140.,280,-140.,140.,"x (cm)","y (cm)");
    TH2D* twoProngConversionRZMap_generalTracksOnly_EB = createTH2D("twoProngConversionRZMap_generalTracksOnly_EB","twoProngConversionRZMap_generalTracksOnly_EB",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    TH2D* twoProngConversionXYMap_generalTracksOnly_EE = createTH2D("twoProngConversionXYMap_generalTracksOnly_EE","twoProngConversionXYMap_generalTracksOnly_EE",280,-140.,140.,280,-140.,140.,"x (cm)","y (cm)");
    TH2D* twoProngConversionRZMap_generalTracksOnly_EE = createTH2D("twoProngConversionRZMap_generalTracksOnly_EE","twoProngConversionRZMap_generalTracksOnly_EE",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    TH2D* twoProngConversionXYMap_generalTracksOnly_allEta = createTH2D("twoProngConversionXYMap_generalTracksOnly_allEta","twoProngConversionXYMap_generalTracksOnly_allEta",280,-140.,140.,280,-140.,140.,"x (cm)","y (cm)");
    TH2D* twoProngConversionRZMap_generalTracksOnly_allEta = createTH2D("twoProngConversionRZMap_generalTracksOnly_allEta","twoProngConversionRZMap_generalTracksOnly_allEta",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    // TH2D* oneProngConversionXYMap_allConvType_EB = createTH2D("oneProngConversionXYMap_allConvType_EB","oneProngConversionXYMap_allConvType_EB",280,-140.,140.,280,-140.,140.,"x (cm)","y (cm)");
    // TH2D* oneProngConversionRZMap_allConvType_EB = createTH2D("oneProngConversionRZMap_allConvType_EB","oneProngConversionRZMap_allConvType_EB",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    // TH2D* oneProngConversionXYMap_allConvType_EE = createTH2D("oneProngConversionXYMap_allConvType_EE","oneProngConversionXYMap_allConvType_EE",280,-140.,140.,280,-140.,140.,"x (cm)","y (cm)");
    // TH2D* oneProngConversionRZMap_allConvType_EE = createTH2D("oneProngConversionRZMap_allConvType_EE","oneProngConversionRZMap_allConvType_EE",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    // TH2D* oneProngConversionXYMap_allConvType_allEta = createTH2D("oneProngConversionXYMap_allConvType_allEta","oneProngConversionXYMap_allConvType_allEta",280,-140.,140.,280,-140.,140.,"x (cm)","y (cm)");
    // TH2D* oneProngConversionRZMap_allConvType_allEta = createTH2D("oneProngConversionRZMap_allConvType_allEta","oneProngConversionRZMap_allConvType_allEta",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    // TH2D* oneProngConversionXYMap_arbitratedMerged_EB = createTH2D("oneProngConversionXYMap_arbitratedMerged_EB","oneProngConversionXYMap_arbitratedMerged_EB",280,-140.,140.,280,-140.,140.,"x (cm)","y (cm)");
    // TH2D* oneProngConversionRZMap_arbitratedMerged_EB = createTH2D("oneProngConversionRZMap_arbitratedMerged_EB","oneProngConversionRZMap_arbitratedMerged_EB",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    // TH2D* oneProngConversionXYMap_arbitratedMerged_EE = createTH2D("oneProngConversionXYMap_arbitratedMerged_EE","oneProngConversionXYMap_arbitratedMerged_EE",280,-140.,140.,280,-140.,140.,"x (cm)","y (cm)");
    // TH2D* oneProngConversionRZMap_arbitratedMerged_EE = createTH2D("oneProngConversionRZMap_arbitratedMerged_EE","oneProngConversionRZMap_arbitratedMerged_EE",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    // TH2D* oneProngConversionXYMap_arbitratedMerged_allEta = createTH2D("oneProngConversionXYMap_arbitratedMerged_allEta","oneProngConversionXYMap_arbitratedMerged_allEta",280,-140.,140.,280,-140.,140.,"x (cm)","y (cm)");
    // TH2D* oneProngConversionRZMap_arbitratedMerged_allEta = createTH2D("oneProngConversionRZMap_arbitratedMerged_allEta","oneProngConversionRZMap_arbitratedMerged_allEta",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    // TH2D* oneProngConversionXYMap_highPurity_EB = createTH2D("oneProngConversionXYMap_highPurity_EB","oneProngConversionXYMap_highPurity_EB",280,-140.,140.,280,-140.,140.,"x (cm)","y (cm)");
    // TH2D* oneProngConversionRZMap_highPurity_EB = createTH2D("oneProngConversionRZMap_highPurity_EB","oneProngConversionRZMap_highPurity_EB",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    // TH2D* oneProngConversionXYMap_highPurity_EE = createTH2D("oneProngConversionXYMap_highPurity_EE","oneProngConversionXYMap_highPurity_EE",280,-140.,140.,280,-140.,140.,"x (cm)","y (cm)");
    // TH2D* oneProngConversionRZMap_highPurity_EE = createTH2D("oneProngConversionRZMap_highPurity_EE","oneProngConversionRZMap_highPurity_EE",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    // TH2D* oneProngConversionXYMap_highPurity_allEta = createTH2D("oneProngConversionXYMap_highPurity_allEta","oneProngConversionXYMap_highPurity_allEta",280,-140.,140.,280,-140.,140.,"x (cm)","y (cm)");
    // TH2D* oneProngConversionRZMap_highPurity_allEta = createTH2D("oneProngConversionRZMap_highPurity_allEta","oneProngConversionRZMap_highPurity_allEta",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    // TH2D* oneProngConversionXYMap_generalTracksOnly_EB = createTH2D("oneProngConversionXYMap_generalTracksOnly_EB","oneProngConversionXYMap_generalTracksOnly_EB",280,-140.,140.,280,-140.,140.,"x (cm)","y (cm)");
    // TH2D* oneProngConversionRZMap_generalTracksOnly_EB = createTH2D("oneProngConversionRZMap_generalTracksOnly_EB","oneProngConversionRZMap_generalTracksOnly_EB",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    // TH2D* oneProngConversionXYMap_generalTracksOnly_EE = createTH2D("oneProngConversionXYMap_generalTracksOnly_EE","oneProngConversionXYMap_generalTracksOnly_EE",280,-140.,140.,280,-140.,140.,"x (cm)","y (cm)");
    // TH2D* oneProngConversionRZMap_generalTracksOnly_EE = createTH2D("oneProngConversionRZMap_generalTracksOnly_EE","oneProngConversionRZMap_generalTracksOnly_EE",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    // TH2D* oneProngConversionXYMap_generalTracksOnly_allEta = createTH2D("oneProngConversionXYMap_generalTracksOnly_allEta","oneProngConversionXYMap_generalTracksOnly_allEta",280,-140.,140.,280,-140.,140.,"x (cm)","y (cm)");
    // TH2D* oneProngConversionRZMap_generalTracksOnly_allEta = createTH2D("oneProngConversionRZMap_generalTracksOnly_allEta","oneProngConversionRZMap_generalTracksOnly_allEta",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");

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
        // if (jentry>10) return;
        if (!TrigHLT_HLT_DoublePhoton60_v1) continue; // only admit events that pass HLT_DoublePhoton_60 
        bool EBEB = isEBEB(Photon1_scEta,Photon2_scEta); // fabs is taken in the helper function!
        bool EBEE = isEBEE(Photon1_scEta,Photon2_scEta);

        if (EBEB) nJets_EBEB->Fill(JetInfo_pt->size());
        else if (EBEE) nJets_EBEE->Fill(JetInfo_pt->size());

        // VBFTag
        // first find the two jets highest in ET (need to create 4-vectors for this)
        // also perform basic jet eta cut that was not done online
        // also cut on loose jet ID
        bool haveTwoJets = false;

        int leadingIdx = -1;
        double leadingET = -1.;
        int subleadingIdx = -1;
        double subleadingET = -2.;

        for (unsigned int i=0; i<JetInfo_pt->size(); i++){
            if ( fabs(JetInfo_eta->at(i)) > 4.7 ) continue;
            if ( !JetInfo_passLooseID->at(i) ) continue;
            TLorentzVector vec;
            vec.SetPtEtaPhiE(JetInfo_pt->at(i),JetInfo_eta->at(i),JetInfo_phi->at(i),JetInfo_energy->at(i));
            double et = vec.Et();
            if (et > leadingET){
                subleadingET = leadingET;
                subleadingIdx = leadingIdx;
                leadingIdx = i;
                leadingET = et;
            }
            else if (et < leadingET && et > subleadingET){
                subleadingET = et;
                subleadingIdx = i;
            }

        } // end loop over jets

        if ( leadingIdx<0 || subleadingIdx<0 ){
            haveTwoJets = false; // less than two jets passing eta and jetid cuts
        }
        else{
            haveTwoJets = true;
        }

        if (haveTwoJets){
            // first define and set TLorentzVectors
            TLorentzVector leadingJet;
            TLorentzVector subleadingJet;
            TLorentzVector leadingPhoton;
            TLorentzVector subleadingPhoton;
            TLorentzVector dijet;
            TLorentzVector diphoton;

            leadingJet.SetPtEtaPhiE(JetInfo_pt->at(leadingIdx),JetInfo_eta->at(leadingIdx),JetInfo_phi->at(leadingIdx),JetInfo_energy->at(leadingIdx));
            subleadingJet.SetPtEtaPhiE(JetInfo_pt->at(subleadingIdx),JetInfo_eta->at(subleadingIdx),JetInfo_phi->at(subleadingIdx),JetInfo_energy->at(subleadingIdx));
            leadingPhoton.SetPtEtaPhiM(Photon1_pt,Photon1_scEta,Photon1_phi,0.);
            subleadingPhoton.SetPtEtaPhiM(Photon2_pt,Photon2_scEta,Photon2_phi,0.);
            dijet = leadingJet + subleadingJet;
            diphoton = leadingPhoton + subleadingPhoton;

            // now calculate the variables for the cuts
            double jetDEta = fabs( leadingJet.Eta() - subleadingJet.Eta() );
            double dijetMass = dijet.M();
            double jetAvgEta = ( leadingJet.Eta() + subleadingJet.Eta() ) / 2.;
            double diphotonEta = diphoton.Eta();
            double jetPhoEtaDiff = fabs( jetAvgEta - diphotonEta );
            double jetPhoDPhi = fabs( diphoton.DeltaPhi(dijet) ); // which has higher phi doesn't matter here

            // pre VBF tag plots
            if (EBEB){
                // start with jet kinematics
                leadingjetPt_EBEB->Fill( leadingJet.Pt() );
                leadingjetEta_EBEB->Fill( leadingJet.Eta() );
                leadingjetPhi_EBEB->Fill( leadingJet.Phi() );
                leadingjetMass_EBEB->Fill( leadingJet.M() );
                leadingjetET_EBEB->Fill( leadingET );

                subleadingjetPt_EBEB->Fill( subleadingJet.Pt() );
                subleadingjetEta_EBEB->Fill( subleadingJet.Eta() );
                subleadingjetPhi_EBEB->Fill( subleadingJet.Phi() );
                subleadingjetMass_EBEB->Fill( subleadingJet.M() );
                subleadingjetET_EBEB->Fill( subleadingET );

                // cut variables
                jetDEta_EBEB->Fill(jetDEta);
                dijetMass_EBEB->Fill(dijetMass);
                jetPhoEtaDiff_EBEB->Fill(jetPhoEtaDiff);
                jetPhoDPhi_EBEB->Fill(jetPhoDPhi);
            }
            else if (EBEE){
                leadingjetPt_EBEE->Fill( leadingJet.Pt() );
                leadingjetEta_EBEE->Fill( leadingJet.Eta() );
                leadingjetPhi_EBEE->Fill( leadingJet.Phi() );
                leadingjetMass_EBEE->Fill( leadingJet.M() );
                leadingjetET_EBEE->Fill( leadingET );

                subleadingjetPt_EBEE->Fill( subleadingJet.Pt() );
                subleadingjetEta_EBEE->Fill( subleadingJet.Eta() );
                subleadingjetPhi_EBEE->Fill( subleadingJet.Phi() );
                subleadingjetMass_EBEE->Fill( subleadingJet.M() );
                subleadingjetET_EBEE->Fill( subleadingET );

                // cut variables
                jetDEta_EBEE->Fill(jetDEta);
                dijetMass_EBEE->Fill(dijetMass);
                jetPhoEtaDiff_EBEE->Fill(jetPhoEtaDiff);
                jetPhoDPhi_EBEE->Fill(jetPhoDPhi);                
            }


            
            if (leadingET > 30. && subleadingET > 20.){

                if (jetDEta > 3.5 && dijetMass > 350. && jetPhoEtaDiff < 2.5 && jetPhoDPhi > 2.6){
                // if (jetDEta > 3.5 && dijetMass > 350.){
                    // fill all histograms
                    // if (EBEB) ggMass_VBFTagged_EBEB->Fill(diphoton.M());
                    // else if (EBEE) ggMass_VBFTagged_EBEE->Fill(diphoton.M());
                    if (EBEB){
                        ggMass_VBFTagged_EBEB->Fill(Diphoton_Minv);
                        leadingPhoPt_VBFTagged_EBEB->Fill(Photon1_pt);
                        leadingPhoEta_VBFTagged_EBEB->Fill(Photon1_scEta);
                        leadingPhoPhi_VBFTagged_EBEB->Fill(Photon1_scPhi);
                        subleadingPhoPt_VBFTagged_EBEB->Fill(Photon2_pt);
                        subleadingPhoEta_VBFTagged_EBEB->Fill(Photon2_scEta);
                        subleadingPhoPhi_VBFTagged_EBEB->Fill(Photon2_scPhi);
                    }
                    else if (EBEE){
                        ggMass_VBFTagged_EBEE->Fill(Diphoton_Minv);
                        leadingPhoPt_VBFTagged_EBEE->Fill(Photon1_pt);
                        leadingPhoEta_VBFTagged_EBEE->Fill(Photon1_scEta);
                        leadingPhoPhi_VBFTagged_EBEE->Fill(Photon1_scPhi);
                        subleadingPhoPt_VBFTagged_EBEE->Fill(Photon2_pt);
                        subleadingPhoEta_VBFTagged_EBEE->Fill(Photon2_scEta);
                        subleadingPhoPhi_VBFTagged_EBEE->Fill(Photon2_scPhi);
                    }
                } // end VBF tag block

            } // end ET cuts for VBF tag
        } // end haveTwoJets block

        // now other plots

        if (EBEB){
            leadingPhoPt_EBEB->Fill(Photon1_pt);
            subleadingPhoPt_EBEB->Fill(Photon2_pt);
            leadingPhoEta_EBEB->Fill(Photon1_scEta);
            subleadingPhoEta_EBEB->Fill(Photon2_scEta);
            leadingPhoPhi_EBEB->Fill(Photon1_scPhi);
            subleadingPhoPhi_EBEB->Fill(Photon2_scPhi);
            ggMass_EBEB->Fill(Diphoton_Minv);
            ggMass_EBEB_JPBinning->Fill(Diphoton_Minv);
            ggMass_EBEB_30003500varbin->Fill(Diphoton_Minv);
            ggMass_EBEB_varbin->Fill(Diphoton_Minv);
            // if (700. <= Diphoton_Minv && Diphoton_Minv <= 800.) massFile << Diphoton_Minv << "\n";
        } // end EBEB block

        else if (EBEE){
            leadingPhoPt_EBEE->Fill(Photon1_pt);
            subleadingPhoPt_EBEE->Fill(Photon2_pt);
            leadingPhoEta_EBEE->Fill(Photon1_scEta);
            subleadingPhoEta_EBEE->Fill(Photon2_scEta);
            leadingPhoPhi_EBEE->Fill(Photon1_scPhi);
            subleadingPhoPhi_EBEE->Fill(Photon2_scPhi);
            ggMass_EBEE->Fill(Diphoton_Minv);
            ggMass_EBEE_30003500varbin->Fill(Diphoton_Minv);
            ggMass_EBEE_varbin->Fill(Diphoton_Minv);
        } // end EBEE block

        // fill conversion plots for all eta

        // leading photon contribution
        // nConversions_allConvType_allEta->Fill( 1.*ConvInfo1_r->size() );
        // int nHighPurity = 0;
        // int nArbitratedMerged = 0;
        // int nGenTracksOnly = 0;
        // for (unsigned int i=0; i<ConvInfo1_r->size(); i++){
        //     if (ConvInfo1_vtxChi2->at(i) > 16.2662) continue;

        //     conversionRadius_allConvType_allEta->Fill( ConvInfo1_r->at(i) );
        //     twoProngConversionXYMap_allConvType_allEta->Fill( ConvInfo1_x->at(i), ConvInfo1_y->at(i) );
        //     twoProngConversionRZMap_allConvType_allEta->Fill( ConvInfo1_z->at(i), ConvInfo1_r->at(i) );

        //     bool isHighPurity = ConvInfo1_quality->at(i).at(4);
        //     bool isArbitratedMerged = ConvInfo1_quality->at(i).at(2);
        //     bool isGeneralTracksOnly = ConvInfo1_quality->at(i).at(0);

        //     if (isHighPurity){
        //         nHighPurity++;
        //         conversionRadius_highPurity_allEta->Fill( ConvInfo1_r->at(i) );
        //         twoProngConversionXYMap_highPurity_allEta->Fill( ConvInfo1_x->at(i), ConvInfo1_y->at(i) );
        //         twoProngConversionRZMap_highPurity_allEta->Fill( ConvInfo1_z->at(i), ConvInfo1_r->at(i) );
        //     }
        //     if (isArbitratedMerged){
        //         nArbitratedMerged++;
        //         conversionRadius_arbitratedMerged_allEta->Fill( ConvInfo1_r->at(i) );
        //         twoProngConversionXYMap_arbitratedMerged_allEta->Fill( ConvInfo1_x->at(i), ConvInfo1_y->at(i) );
        //         twoProngConversionRZMap_arbitratedMerged_allEta->Fill( ConvInfo1_z->at(i), ConvInfo1_r->at(i) );   
        //     }
        //     if (isGeneralTracksOnly){
        //         nGenTracksOnly++;
        //         conversionRadius_generalTracksOnly_allEta->Fill( ConvInfo1_r->at(i) );
        //         twoProngConversionXYMap_generalTracksOnly_allEta->Fill( ConvInfo1_x->at(i), ConvInfo1_y->at(i) );
        //         twoProngConversionRZMap_generalTracksOnly_allEta->Fill( ConvInfo1_z->at(i), ConvInfo1_r->at(i) );
        //     }
        // }
        // nConversions_highPurity_allEta->Fill(1.*nHighPurity);
        // nConversions_arbitratedMerged_allEta->Fill(1.*nArbitratedMerged);
        // nConversions_generalTracksOnly_allEta->Fill(1.*nGenTracksOnly);

        // // subleading photon contribution
        // nConversions_allConvType_allEta->Fill( 1.*ConvInfo2_r->size() );
        // // reset counters for the subleading photon
        // nHighPurity = 0;
        // nArbitratedMerged = 0;
        // nGenTracksOnly = 0;
        // for (unsigned int i=0; i<ConvInfo2_r->size(); i++){
        //     if (ConvInfo2_vtxChi2->at(i) > 16.2662) continue;

        //     conversionRadius_allConvType_allEta->Fill( ConvInfo2_r->at(i) );
        //     twoProngConversionXYMap_allConvType_allEta->Fill( ConvInfo2_x->at(i), ConvInfo2_y->at(i) );
        //     twoProngConversionRZMap_allConvType_allEta->Fill( ConvInfo2_z->at(i), ConvInfo2_r->at(i) );

        //     bool isHighPurity = ConvInfo2_quality->at(i).at(4);
        //     bool isArbitratedMerged = ConvInfo2_quality->at(i).at(2);
        //     bool isGeneralTracksOnly = ConvInfo2_quality->at(i).at(0);

        //     if (isHighPurity){
        //         nHighPurity++;
        //         conversionRadius_highPurity_allEta->Fill( ConvInfo2_r->at(i) );
        //         twoProngConversionXYMap_highPurity_allEta->Fill( ConvInfo2_x->at(i), ConvInfo2_y->at(i) );
        //         twoProngConversionRZMap_highPurity_allEta->Fill( ConvInfo2_z->at(i), ConvInfo2_r->at(i) );
        //     }
        //     if (isArbitratedMerged){
        //         nArbitratedMerged++;
        //         conversionRadius_arbitratedMerged_allEta->Fill( ConvInfo2_r->at(i) );
        //         twoProngConversionXYMap_arbitratedMerged_allEta->Fill( ConvInfo2_x->at(i), ConvInfo2_y->at(i) );
        //         twoProngConversionRZMap_arbitratedMerged_allEta->Fill( ConvInfo2_z->at(i), ConvInfo2_r->at(i) );   
        //     }
        //     if (isGeneralTracksOnly){
        //         nGenTracksOnly++;
        //         conversionRadius_generalTracksOnly_allEta->Fill( ConvInfo2_r->at(i) );
        //         twoProngConversionXYMap_generalTracksOnly_allEta->Fill( ConvInfo2_x->at(i), ConvInfo2_y->at(i) );
        //         twoProngConversionRZMap_generalTracksOnly_allEta->Fill( ConvInfo2_z->at(i), ConvInfo2_r->at(i) );
        //     }
        // }
        // nConversions_highPurity_allEta->Fill(1.*nHighPurity);
        // nConversions_arbitratedMerged_allEta->Fill(1.*nArbitratedMerged);
        // nConversions_generalTracksOnly_allEta->Fill(1.*nGenTracksOnly);

        // // fill EB and EE based conversion maps

        // if( isEB(Photon1_scEta) ){
        //     nConversions_allConvType_EB->Fill( 1.*ConvInfo1_r->size() );
        //     int nHighPurity = 0;
        //     int nArbitratedMerged = 0;
        //     int nGenTracksOnly = 0;
        //     for (unsigned int i=0; i<ConvInfo1_r->size(); i++){
        //         if (ConvInfo1_vtxChi2->at(i) > 16.2662) continue;

        //         conversionRadius_allConvType_EB->Fill( ConvInfo1_r->at(i) );
        //         twoProngConversionXYMap_allConvType_EB->Fill( ConvInfo1_x->at(i), ConvInfo1_y->at(i) );
        //         twoProngConversionRZMap_allConvType_EB->Fill( ConvInfo1_z->at(i), ConvInfo1_r->at(i) );

        //         bool isHighPurity = ConvInfo1_quality->at(i).at(4);
        //         bool isArbitratedMerged = ConvInfo1_quality->at(i).at(2);
        //         bool isGeneralTracksOnly = ConvInfo1_quality->at(i).at(0);

        //         if (isHighPurity){
        //             nHighPurity++;
        //             conversionRadius_highPurity_EB->Fill( ConvInfo1_r->at(i) );
        //             twoProngConversionXYMap_highPurity_EB->Fill( ConvInfo1_x->at(i), ConvInfo1_y->at(i) );
        //             twoProngConversionRZMap_highPurity_EB->Fill( ConvInfo1_z->at(i), ConvInfo1_r->at(i) );
        //         }
        //         if (isArbitratedMerged){
        //             nArbitratedMerged++;
        //             conversionRadius_arbitratedMerged_EB->Fill( ConvInfo1_r->at(i) );
        //             twoProngConversionXYMap_arbitratedMerged_EB->Fill( ConvInfo1_x->at(i), ConvInfo1_y->at(i) );
        //             twoProngConversionRZMap_arbitratedMerged_EB->Fill( ConvInfo1_z->at(i), ConvInfo1_r->at(i) );   
        //         }
        //         if (isGeneralTracksOnly){
        //             nGenTracksOnly++;
        //             conversionRadius_generalTracksOnly_EB->Fill( ConvInfo1_r->at(i) );
        //             twoProngConversionXYMap_generalTracksOnly_EB->Fill( ConvInfo1_x->at(i), ConvInfo1_y->at(i) );
        //             twoProngConversionRZMap_generalTracksOnly_EB->Fill( ConvInfo1_z->at(i), ConvInfo1_r->at(i) );
        //         }
        //     }
        //     nConversions_highPurity_EB->Fill(1.*nHighPurity);
        //     nConversions_arbitratedMerged_EB->Fill(1.*nArbitratedMerged);
        //     nConversions_generalTracksOnly_EB->Fill(1.*nGenTracksOnly);

        // }
        // else if ( isEE(Photon1_scEta) ){
        //     nConversions_allConvType_EE->Fill( 1.*ConvInfo1_r->size() );
        //     int nHighPurity = 0;
        //     int nArbitratedMerged = 0;
        //     int nGenTracksOnly = 0;
        //     for (unsigned int i=0; i<ConvInfo1_r->size(); i++){
        //         if (ConvInfo1_vtxChi2->at(i) > 16.2662) continue;

        //         conversionRadius_allConvType_EE->Fill( ConvInfo1_r->at(i) );
        //         twoProngConversionXYMap_allConvType_EE->Fill( ConvInfo1_x->at(i), ConvInfo1_y->at(i) );
        //         twoProngConversionRZMap_allConvType_EE->Fill( ConvInfo1_z->at(i), ConvInfo1_r->at(i) );

        //         bool isHighPurity = ConvInfo1_quality->at(i).at(4);
        //         bool isArbitratedMerged = ConvInfo1_quality->at(i).at(2);
        //         bool isGeneralTracksOnly = ConvInfo1_quality->at(i).at(0);

        //         if (isHighPurity){
        //             nHighPurity++;
        //             conversionRadius_highPurity_EE->Fill( ConvInfo1_r->at(i) );
        //             twoProngConversionXYMap_highPurity_EE->Fill( ConvInfo1_x->at(i), ConvInfo1_y->at(i) );
        //             twoProngConversionRZMap_highPurity_EE->Fill( ConvInfo1_z->at(i), ConvInfo1_r->at(i) );
        //         }
        //         if (isArbitratedMerged){
        //             nArbitratedMerged++;
        //             conversionRadius_arbitratedMerged_EE->Fill( ConvInfo1_r->at(i) );
        //             twoProngConversionXYMap_arbitratedMerged_EE->Fill( ConvInfo1_x->at(i), ConvInfo1_y->at(i) );
        //             twoProngConversionRZMap_arbitratedMerged_EE->Fill( ConvInfo1_z->at(i), ConvInfo1_r->at(i) );   
        //         }
        //         if (isGeneralTracksOnly){
        //             nGenTracksOnly++;
        //             conversionRadius_generalTracksOnly_EE->Fill( ConvInfo1_r->at(i) );
        //             twoProngConversionXYMap_generalTracksOnly_EE->Fill( ConvInfo1_x->at(i), ConvInfo1_y->at(i) );
        //             twoProngConversionRZMap_generalTracksOnly_EE->Fill( ConvInfo1_z->at(i), ConvInfo1_r->at(i) );
        //         }
        //     }
        //     nConversions_highPurity_EE->Fill(1.*nHighPurity);
        //     nConversions_arbitratedMerged_EE->Fill(1.*nArbitratedMerged);
        //     nConversions_generalTracksOnly_EE->Fill(1.*nGenTracksOnly);
        // }
        // if( isEB(Photon2_scEta) ){
        //     nConversions_allConvType_EB->Fill( 1.*ConvInfo2_r->size() );
        //     int nHighPurity = 0;
        //     int nArbitratedMerged = 0;
        //     int nGenTracksOnly = 0;
        //     for (unsigned int i=0; i<ConvInfo2_r->size(); i++){
        //         if (ConvInfo2_vtxChi2->at(i) > 16.2662) continue;

        //         conversionRadius_allConvType_EB->Fill( ConvInfo2_r->at(i) );
        //         twoProngConversionXYMap_allConvType_EB->Fill( ConvInfo2_x->at(i), ConvInfo2_y->at(i) );
        //         twoProngConversionRZMap_allConvType_EB->Fill( ConvInfo2_z->at(i), ConvInfo2_r->at(i) );

        //         bool isHighPurity = ConvInfo2_quality->at(i).at(4);
        //         bool isArbitratedMerged = ConvInfo2_quality->at(i).at(2);
        //         bool isGeneralTracksOnly = ConvInfo2_quality->at(i).at(0);

        //         if (isHighPurity){
        //             nHighPurity++;
        //             conversionRadius_highPurity_EB->Fill( ConvInfo2_r->at(i) );
        //             twoProngConversionXYMap_highPurity_EB->Fill( ConvInfo2_x->at(i), ConvInfo2_y->at(i) );
        //             twoProngConversionRZMap_highPurity_EB->Fill( ConvInfo2_z->at(i), ConvInfo2_r->at(i) );
        //         }
        //         if (isArbitratedMerged){
        //             nArbitratedMerged++;
        //             conversionRadius_arbitratedMerged_EB->Fill( ConvInfo2_r->at(i) );
        //             twoProngConversionXYMap_arbitratedMerged_EB->Fill( ConvInfo2_x->at(i), ConvInfo2_y->at(i) );
        //             twoProngConversionRZMap_arbitratedMerged_EB->Fill( ConvInfo2_z->at(i), ConvInfo2_r->at(i) );   
        //         }
        //         if (isGeneralTracksOnly){
        //             nGenTracksOnly++;
        //             conversionRadius_generalTracksOnly_EB->Fill( ConvInfo2_r->at(i) );
        //             twoProngConversionXYMap_generalTracksOnly_EB->Fill( ConvInfo2_x->at(i), ConvInfo2_y->at(i) );
        //             twoProngConversionRZMap_generalTracksOnly_EB->Fill( ConvInfo2_z->at(i), ConvInfo2_r->at(i) );
        //         }
        //     }
        //     nConversions_highPurity_EB->Fill(1.*nHighPurity);
        //     nConversions_arbitratedMerged_EB->Fill(1.*nArbitratedMerged);
        //     nConversions_generalTracksOnly_EB->Fill(1.*nGenTracksOnly);
        // }
        // else if ( isEE(Photon2_scEta) ){
        //     nConversions_allConvType_EE->Fill( 1.*ConvInfo2_r->size() );
        //     int nHighPurity = 0;
        //     int nArbitratedMerged = 0;
        //     int nGenTracksOnly = 0;
        //     for (unsigned int i=0; i<ConvInfo2_r->size(); i++){
        //         if (ConvInfo2_vtxChi2->at(i) > 16.2662) continue;

        //         conversionRadius_allConvType_EE->Fill( ConvInfo2_r->at(i) );
        //         twoProngConversionXYMap_allConvType_EE->Fill( ConvInfo2_x->at(i), ConvInfo2_y->at(i) );
        //         twoProngConversionRZMap_allConvType_EE->Fill( ConvInfo2_z->at(i), ConvInfo2_r->at(i) );

        //         bool isHighPurity = ConvInfo2_quality->at(i).at(4);
        //         bool isArbitratedMerged = ConvInfo2_quality->at(i).at(2);
        //         bool isGeneralTracksOnly = ConvInfo2_quality->at(i).at(0);

        //         if (isHighPurity){
        //             nHighPurity++;
        //             conversionRadius_highPurity_EE->Fill( ConvInfo2_r->at(i) );
        //             twoProngConversionXYMap_highPurity_EE->Fill( ConvInfo2_x->at(i), ConvInfo2_y->at(i) );
        //             twoProngConversionRZMap_highPurity_EE->Fill( ConvInfo2_z->at(i), ConvInfo2_r->at(i) );
        //         }
        //         if (isArbitratedMerged){
        //             nArbitratedMerged++;
        //             conversionRadius_arbitratedMerged_EE->Fill( ConvInfo2_r->at(i) );
        //             twoProngConversionXYMap_arbitratedMerged_EE->Fill( ConvInfo2_x->at(i), ConvInfo2_y->at(i) );
        //             twoProngConversionRZMap_arbitratedMerged_EE->Fill( ConvInfo2_z->at(i), ConvInfo2_r->at(i) );   
        //         }
        //         if (isGeneralTracksOnly){
        //             nGenTracksOnly++;
        //             conversionRadius_generalTracksOnly_EE->Fill( ConvInfo2_r->at(i) );
        //             twoProngConversionXYMap_generalTracksOnly_EE->Fill( ConvInfo2_x->at(i), ConvInfo2_y->at(i) );
        //             twoProngConversionRZMap_generalTracksOnly_EE->Fill( ConvInfo2_z->at(i), ConvInfo2_r->at(i) );
        //         }
        //     }
        //     nConversions_highPurity_EE->Fill(1.*nHighPurity);
        //     nConversions_arbitratedMerged_EE->Fill(1.*nArbitratedMerged);
        //     nConversions_generalTracksOnly_EE->Fill(1.*nGenTracksOnly);
        // }        

    } // end event loop

    // TCanvas c("c","",800,800);
    // c.cd();
    // c.Clear();
    // leadingPhoPt_EBEB->Draw();
    // c.SaveAs("leadingPhoPt_EBEB.pdf");
    // c.cd();
    // c.Clear();
    // leadingPhoPt_EBEE->Draw();
    // c.SaveAs("leadingPhoPt_EBEE.pdf");
    // c.cd();
    // c.Clear();
    // subleadingPhoPt_EBEB->Draw();
    // c.SaveAs("subleadingPhoPt_EBEB.pdf");
    // c.cd();
    // c.Clear();
    // subleadingPhoPt_EBEE->Draw();
    // c.SaveAs("subleadingPhoPt_EBEE.pdf");
    // c.cd();
    // c.Clear();
    // leadingPhoEta_EBEB->Draw();
    // c.SaveAs("leadingPhoEta_EBEB.pdf");
    // c.cd();
    // c.Clear();
    // leadingPhoEta_EBEE->Draw();
    // c.SaveAs("leadingPhoEta_EBEE.pdf");
    // c.cd();
    // c.Clear();
    // subleadingPhoEta_EBEB->Draw();
    // c.SaveAs("subleadingPhoEta_EBEB.pdf");
    // c.cd();
    // c.Clear();
    // subleadingPhoEta_EBEE->Draw();
    // c.SaveAs("subleadingPhoEta_EBEE.pdf");
    // c.cd();
    // c.Clear();
    // leadingPhoPhi_EBEB->Draw();
    // c.SaveAs("leadingPhoPhi_EBEB.pdf");
    // c.cd();
    // c.Clear();
    // leadingPhoPhi_EBEE->Draw();
    // c.SaveAs("leadingPhoPhi_EBEE.pdf");
    // c.cd();
    // c.Clear();
    // subleadingPhoPhi_EBEB->Draw();
    // c.SaveAs("subleadingPhoPhi_EBEB.pdf");
    // c.cd();
    // c.Clear();
    // subleadingPhoPhi_EBEE->Draw();
    // c.SaveAs("subleadingPhoPhi_EBEE.pdf");
    // c.cd();
    // c.Clear();
    // ggMass_EBEB->Draw();
    // c.SaveAs("ggMass_EBEB.pdf");
    // c.cd();
    // c.Clear();
    // ggMass_EBEE->Draw();
    // c.SaveAs("ggMass_EBEE.pdf");

    TFile f(outfilename,"recreate");
    f.cd();

    leadingPhoPt_EBEB->Write();
    subleadingPhoPt_EBEB->Write();
    leadingPhoEta_EBEB->Write();
    subleadingPhoEta_EBEB->Write();
    leadingPhoPhi_EBEB->Write();
    subleadingPhoPhi_EBEB->Write();
    ggMass_EBEB->Write();
    ggMass_EBEB_JPBinning->Write();
    ggMass_EBEB_30003500varbin->Write();
    ggMass_EBEB_varbin->Write();
    leadingPhoPt_EBEE->Write();
    subleadingPhoPt_EBEE->Write();
    leadingPhoEta_EBEE->Write();
    subleadingPhoEta_EBEE->Write();
    leadingPhoPhi_EBEE->Write();
    subleadingPhoPhi_EBEE->Write();
    ggMass_EBEE->Write();
    ggMass_EBEE_30003500varbin->Write();
    ggMass_EBEE_varbin->Write();
    leadingPhoPt_VBFTagged_EBEB->Write();
    subleadingPhoPt_VBFTagged_EBEB->Write();
    leadingPhoEta_VBFTagged_EBEB->Write();
    subleadingPhoEta_VBFTagged_EBEB->Write();
    leadingPhoPhi_VBFTagged_EBEB->Write();
    subleadingPhoPhi_VBFTagged_EBEB->Write();
    ggMass_VBFTagged_EBEB->Write();
    leadingPhoPt_VBFTagged_EBEE->Write();
    subleadingPhoPt_VBFTagged_EBEE->Write();
    leadingPhoEta_VBFTagged_EBEE->Write();
    subleadingPhoEta_VBFTagged_EBEE->Write();
    leadingPhoPhi_VBFTagged_EBEE->Write();
    subleadingPhoPhi_VBFTagged_EBEE->Write();
    ggMass_VBFTagged_EBEE->Write();
    nJets_EBEB->Write();
    leadingjetPt_EBEB->Write();
    leadingjetEta_EBEB->Write();
    leadingjetPhi_EBEB->Write();
    leadingjetET_EBEB->Write();
    leadingjetMass_EBEB->Write();
    nJets_EBEE->Write();
    leadingjetPt_EBEE->Write();
    leadingjetEta_EBEE->Write();
    leadingjetPhi_EBEE->Write();
    leadingjetET_EBEE->Write();
    leadingjetMass_EBEE->Write();
    subleadingjetPt_EBEB->Write();
    subleadingjetEta_EBEB->Write();
    subleadingjetPhi_EBEB->Write();
    subleadingjetET_EBEB->Write();
    subleadingjetMass_EBEB->Write();
    subleadingjetPt_EBEE->Write();
    subleadingjetEta_EBEE->Write();
    subleadingjetPhi_EBEE->Write();
    subleadingjetET_EBEE->Write();
    subleadingjetMass_EBEE->Write();
    jetDEta_EBEB->Write();
    dijetMass_EBEB->Write();
    jetPhoEtaDiff_EBEB->Write();
    jetPhoDPhi_EBEB->Write();
    jetDEta_EBEE->Write();
    dijetMass_EBEE->Write();
    jetPhoEtaDiff_EBEE->Write();
    jetPhoDPhi_EBEE->Write();
    nConversions_allConvType_EB->Write();
    nConversions_allConvType_EE->Write();
    nConversions_allConvType_allEta->Write();
    nConversions_arbitratedMerged_EB->Write();
    nConversions_arbitratedMerged_EE->Write();
    nConversions_arbitratedMerged_allEta->Write();
    nConversions_highPurity_EB->Write();
    nConversions_highPurity_EE->Write();
    nConversions_highPurity_allEta->Write();
    nConversions_generalTracksOnly_EB->Write();
    nConversions_generalTracksOnly_EE->Write();
    nConversions_generalTracksOnly_allEta->Write();
    conversionRadius_allConvType_EB->Write();
    conversionRadius_allConvType_EE->Write();
    conversionRadius_allConvType_allEta->Write();
    conversionRadius_arbitratedMerged_EB->Write();
    conversionRadius_arbitratedMerged_EE->Write();
    conversionRadius_arbitratedMerged_allEta->Write();
    conversionRadius_highPurity_EB->Write();
    conversionRadius_highPurity_EE->Write();
    conversionRadius_highPurity_allEta->Write();
    conversionRadius_generalTracksOnly_EB->Write();
    conversionRadius_generalTracksOnly_EE->Write();
    conversionRadius_generalTracksOnly_allEta->Write();
    twoProngConversionXYMap_allConvType_EB->Write();
    twoProngConversionRZMap_allConvType_EB->Write();
    twoProngConversionXYMap_allConvType_EE->Write();
    twoProngConversionRZMap_allConvType_EE->Write();
    twoProngConversionXYMap_allConvType_allEta->Write();
    twoProngConversionRZMap_allConvType_allEta->Write();
    twoProngConversionXYMap_arbitratedMerged_EB->Write();
    twoProngConversionRZMap_arbitratedMerged_EB->Write();
    twoProngConversionXYMap_arbitratedMerged_EE->Write();
    twoProngConversionRZMap_arbitratedMerged_EE->Write();
    twoProngConversionXYMap_arbitratedMerged_allEta->Write();
    twoProngConversionRZMap_arbitratedMerged_allEta->Write();
    twoProngConversionXYMap_highPurity_EB->Write();
    twoProngConversionRZMap_highPurity_EB->Write();
    twoProngConversionXYMap_highPurity_EE->Write();
    twoProngConversionRZMap_highPurity_EE->Write();
    twoProngConversionXYMap_highPurity_allEta->Write();
    twoProngConversionRZMap_highPurity_allEta->Write();
    twoProngConversionXYMap_generalTracksOnly_EB->Write();
    twoProngConversionRZMap_generalTracksOnly_EB->Write();
    twoProngConversionXYMap_generalTracksOnly_EE->Write();
    twoProngConversionRZMap_generalTracksOnly_EE->Write();
    twoProngConversionXYMap_generalTracksOnly_allEta->Write();
    twoProngConversionRZMap_generalTracksOnly_allEta->Write();

    // massFile.close();

    f.Close();
} // end fTree::Loop() method
