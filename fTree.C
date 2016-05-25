#define fTree_cxx
#include "fTree.h"
#include "helperFunctions.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>




void fTree::Loop()
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

    // declare histograms
    // TH1D *hist = new TH1D("hist","",2000,0,2000);
    // formatHist(hist,"xtitle","ytitle");

    TH1D* leadingPhoPt_EBEB = new TH1D("leadingPhoPt_EBEB","leadingPhoPt_EBEB",300.,0.,1500.);
    TH1D* subleadingPhoPt_EBEB = new TH1D("subleadingPhoPt_EBEB","subleadingPhoPt_EBEB",300,0.,1500.);
    TH1D* leadingPhoEta_EBEB = new TH1D("leadingPhoEta_EBEB","leadingPhoEta_EBEB",100,-5.,5.);
    TH1D* subleadingPhoEta_EBEB = new TH1D("subleadingPhoEta_EBEB","subleadingPhoEta_EBEB",100,-5.,5.);
    TH1D* leadingPhoPhi_EBEB = new TH1D("leadingPhoPhi_EBEB","leadingPhoPhi_EBEB",100,-3.141593,-3.141593);
    TH1D* subleadingPhoPhi_EBEB = new TH1D("subleadingPhoPhi_EBEB","subleadingPhoPhi_EBEB",100,-3.141593,-3.141593);
    TH1D* ggMass_EBEB = new TH1D("ggMass_EBEB","ggMass_EBEB",151,-10.,3010.);

    formatHist(leadingPhoPt_EBEB,"Leading Photon pT (GeV/c)","Events");
    formatHist(subleadingPhoPt_EBEB,"Subleading Photon pT (GeV/c)","Events");
    formatHist(leadingPhoEta_EBEB,"Leading Photon #eta","Events");
    formatHist(subleadingPhoEta_EBEB,"Subleading Photon #eta","Events");
    formatHist(leadingPhoPhi_EBEB,"Leading Photon #phi","Events");
    formatHist(subleadingPhoPhi_EBEB,"Subleading Photon #phi","Events");
    formatHist(ggMass_EBEB,"m_{#gamma#gamma} (GeV/c^{2})","Events");

    TH1D* leadingPhoPt_EBEE = new TH1D("leadingPhoPt_EBEE","leadingPhoPt_EBEE",300.,0.,1500.);
    TH1D* subleadingPhoPt_EBEE = new TH1D("subleadingPhoPt_EBEE","subleadingPhoPt_EBEE",300,0.,1500.);
    TH1D* leadingPhoEta_EBEE = new TH1D("leadingPhoEta_EBEE","leadingPhoEta_EBEE",100,-5.,5.);
    TH1D* subleadingPhoEta_EBEE = new TH1D("subleadingPhoEta_EBEE","subleadingPhoEta_EBEE",100,-5.,5.);
    TH1D* leadingPhoPhi_EBEE = new TH1D("leadingPhoPhi_EBEE","leadingPhoPhi_EBEE",100,-3.141593,-3.141593);
    TH1D* subleadingPhoPhi_EBEE = new TH1D("subleadingPhoPhi_EBEE","subleadingPhoPhi_EBEE",100,-3.141593,-3.141593);
    TH1D* ggMass_EBEE = new TH1D("ggMass_EBEE","ggMass_EBEE",151,-10.,3010.);

    formatHist(leadingPhoPt_EBEE,"Leading Photon pT (GeV/c)","Events");
    formatHist(subleadingPhoPt_EBEE,"Subleading Photon pT (GeV/c)","Events");
    formatHist(leadingPhoEta_EBEE,"Leading Photon #eta","Events");
    formatHist(subleadingPhoEta_EBEE,"Subleading Photon #eta","Events");
    formatHist(leadingPhoPhi_EBEE,"Leading Photon #phi","Events");
    formatHist(subleadingPhoPhi_EBEE,"Subleading Photon #phi","Events");
    formatHist(ggMass_EBEE,"m_{#gamma#gamma} (GeV/c^{2})","Events");

    // VBF tagged histograms
    TH1D* leadingPhoPt_VBFTagged_EBEB = new TH1D("leadingPhoPt_VBFTagged_EBEB","leadingPhoPt_VBFTagged_EBEB",300.,0.,1500.);
    TH1D* subleadingPhoPt_VBFTagged_EBEB = new TH1D("subleadingPhoPt_VBFTagged_EBEB","subleadingPhoPt_VBFTagged_EBEB",300,0.,1500.);
    TH1D* leadingPhoEta_VBFTagged_EBEB = new TH1D("leadingPhoEta_VBFTagged_EBEB","leadingPhoEta_VBFTagged_EBEB",100,-5.,5.);
    TH1D* subleadingPhoEta_VBFTagged_EBEB = new TH1D("subleadingPhoEta_VBFTagged_EBEB","subleadingPhoEta_VBFTagged_EBEB",100,-5.,5.);
    TH1D* leadingPhoPhi_VBFTagged_EBEB = new TH1D("leadingPhoPhi_VBFTagged_EBEB","leadingPhoPhi_VBFTagged_EBEB",100,-3.141593,-3.141593);
    TH1D* subleadingPhoPhi_VBFTagged_EBEB = new TH1D("subleadingPhoPhi_VBFTagged_EBEB","subleadingPhoPhi_VBFTagged_EBEB",100,-3.141593,-3.141593);
    TH1D* ggMass_VBFTagged_EBEB = new TH1D("ggMass_VBFTagged_EBEB","ggMass_VBFTagged_EBEB",151,-10.,3010.);

    formatHist(leadingPhoPt_VBFTagged_EBEB,"Leading Photon pT (GeV/c)","Events");
    formatHist(subleadingPhoPt_VBFTagged_EBEB,"Subleading Photon pT (GeV/c)","Events");
    formatHist(leadingPhoEta_VBFTagged_EBEB,"Leading Photon #eta","Events");
    formatHist(subleadingPhoEta_VBFTagged_EBEB,"Subleading Photon #eta","Events");
    formatHist(leadingPhoPhi_VBFTagged_EBEB,"Leading Photon #phi","Events");
    formatHist(subleadingPhoPhi_VBFTagged_EBEB,"Subleading Photon #phi","Events");
    formatHist(ggMass_VBFTagged_EBEB,"m_{#gamma#gamma} (GeV/c^{2})","Events");

    TH1D* leadingPhoPt_VBFTagged_EBEE = new TH1D("leadingPhoPt_VBFTagged_EBEE","leadingPhoPt_VBFTagged_EBEE",300.,0.,1500.);
    TH1D* subleadingPhoPt_VBFTagged_EBEE = new TH1D("subleadingPhoPt_VBFTagged_EBEE","subleadingPhoPt_VBFTagged_EBEE",300,0.,1500.);
    TH1D* leadingPhoEta_VBFTagged_EBEE = new TH1D("leadingPhoEta_VBFTagged_EBEE","leadingPhoEta_VBFTagged_EBEE",100,-5.,5.);
    TH1D* subleadingPhoEta_VBFTagged_EBEE = new TH1D("subleadingPhoEta_VBFTagged_EBEE","subleadingPhoEta_VBFTagged_EBEE",100,-5.,5.);
    TH1D* leadingPhoPhi_VBFTagged_EBEE = new TH1D("leadingPhoPhi_VBFTagged_EBEE","leadingPhoPhi_VBFTagged_EBEE",100,-3.141593,-3.141593);
    TH1D* subleadingPhoPhi_VBFTagged_EBEE = new TH1D("subleadingPhoPhi_VBFTagged_EBEE","subleadingPhoPhi_VBFTagged_EBEE",100,-3.141593,-3.141593);
    TH1D* ggMass_VBFTagged_EBEE = new TH1D("ggMass_VBFTagged_EBEE","ggMass_VBFTagged_EBEE",151,-10.,3010.);

    formatHist(leadingPhoPt_VBFTagged_EBEE,"Leading Photon pT (GeV/c)","Events");
    formatHist(subleadingPhoPt_VBFTagged_EBEE,"Subleading Photon pT (GeV/c)","Events");
    formatHist(leadingPhoEta_VBFTagged_EBEE,"Leading Photon #eta","Events");
    formatHist(subleadingPhoEta_VBFTagged_EBEE,"Subleading Photon #eta","Events");
    formatHist(leadingPhoPhi_VBFTagged_EBEE,"Leading Photon #phi","Events");
    formatHist(subleadingPhoPhi_VBFTagged_EBEE,"Subleading Photon #phi","Events");
    formatHist(ggMass_VBFTagged_EBEE,"m_{#gamma#gamma} (GeV/c^{2})","Events");

    // Jet histograms
    TH1D* nJets_EBEB = new TH1D("nJets_EBEB","nJets_EBEB",27,-0.5,26.5);
    TH1D* leadingjetPt_EBEB = new TH1D("leadingjetPt_EBEB","leadingjetPt_EBEB",300,0,2500);
    TH1D* leadingjetEta_EBEB = new TH1D("leadingjetEta_EBEB","leadingjetEta_EBEB",300,-5.,5.);
    TH1D* leadingjetPhi_EBEB = new TH1D("leadingjetPhi_EBEB","leadingjetPhi_EBEB",300,-3.1416,3.1416);
    TH1D* leadingjetET_EBEB = new TH1D("leadingjetET_EBEB","leadingjetET_EBEB",300,0,2500);
    TH1D* leadingjetMass_EBEB = new TH1D("leadingjetMass_EBEB","leadingjetMass_EBEB",300,0,2500);

    formatHist(nJets_EBEB,"Jet Multiplicity","Number of Jets");
    formatHist(leadingjetPt_EBEB,"Jet pT (GeV/c)","Number of Jets");
    formatHist(leadingjetEta_EBEB,"Jet #eta","Number of Jets");
    formatHist(leadingjetPhi_EBEB,"Jet #varphi","Number of Jets");
    formatHist(leadingjetET_EBEB,"Jet E_{T} (GeV)","Number of Jets");
    formatHist(leadingjetMass_EBEB,"Jet Mass (GeV/c^{2})","Number of Jets");

    TH1D* nJets_EBEE = new TH1D("nJets_EBEE","nJets_EBEE",27,-0.5,26.5);
    TH1D* leadingjetPt_EBEE = new TH1D("leadingjetPt_EBEE","leadingjetPt_EBEE",300,0,2500);
    TH1D* leadingjetEta_EBEE = new TH1D("leadingjetEta_EBEE","leadingjetEta_EBEE",300,-5.,5.);
    TH1D* leadingjetPhi_EBEE = new TH1D("leadingjetPhi_EBEE","leadingjetPhi_EBEE",300,-3.1416,3.1416);
    TH1D* leadingjetET_EBEE = new TH1D("leadingjetET_EBEE","leadingjetET_EBEE",300,0,2500);
    TH1D* leadingjetMass_EBEE = new TH1D("leadingjetMass_EBEE","leadingjetMass_EBEE",300,0,2500);

    formatHist(nJets_EBEE,"Jet Multiplicity","Number of Jets");
    formatHist(leadingjetPt_EBEE,"Jet pT (GeV/c)","Number of Jets");
    formatHist(leadingjetEta_EBEE,"Jet #eta","Number of Jets");
    formatHist(leadingjetPhi_EBEE,"Jet #varphi","Number of Jets");
    formatHist(leadingjetET_EBEE,"Jet E_{T} (GeV)","Number of Jets");
    formatHist(leadingjetMass_EBEE,"Jet Mass (GeV/c^{2})","Number of Jets");

    TH1D* subleadingjetPt_EBEB = new TH1D("subleadingjetPt_EBEB","subleadingjetPt_EBEB",300,0,2500);
    TH1D* subleadingjetEta_EBEB = new TH1D("subleadingjetEta_EBEB","subleadingjetEta_EBEB",300,-5.,5.);
    TH1D* subleadingjetPhi_EBEB = new TH1D("subleadingjetPhi_EBEB","subleadingjetPhi_EBEB",300,-3.1416,3.1416);
    TH1D* subleadingjetET_EBEB = new TH1D("subleadingjetET_EBEB","subleadingjetET_EBEB",300,0,2500);
    TH1D* subleadingjetMass_EBEB = new TH1D("subleadingjetMass_EBEB","subleadingjetMass_EBEB",300,0,2500);

    formatHist(subleadingjetPt_EBEB,"Jet pT (GeV/c)","Number of Jets");
    formatHist(subleadingjetEta_EBEB,"Jet #eta","Number of Jets");
    formatHist(subleadingjetPhi_EBEB,"Jet #varphi","Number of Jets");
    formatHist(subleadingjetET_EBEB,"Jet E_{T} (GeV)","Number of Jets");
    formatHist(subleadingjetMass_EBEB,"Jet Mass (GeV/c^{2})","Number of Jets");

    TH1D* subleadingjetPt_EBEE = new TH1D("subleadingjetPt_EBEE","subleadingjetPt_EBEE",300,0,2500);
    TH1D* subleadingjetEta_EBEE = new TH1D("subleadingjetEta_EBEE","subleadingjetEta_EBEE",300,-5.,5.);
    TH1D* subleadingjetPhi_EBEE = new TH1D("subleadingjetPhi_EBEE","subleadingjetPhi_EBEE",300,-3.1416,3.1416);
    TH1D* subleadingjetET_EBEE = new TH1D("subleadingjetET_EBEE","subleadingjetET_EBEE",300,0,2500);
    TH1D* subleadingjetMass_EBEE = new TH1D("subleadingjetMass_EBEE","subleadingjetMass_EBEE",300,0,2500);

    formatHist(subleadingjetPt_EBEE,"Jet pT (GeV/c)","Number of Jets");
    formatHist(subleadingjetEta_EBEE,"Jet #eta","Number of Jets");
    formatHist(subleadingjetPhi_EBEE,"Jet #varphi","Number of Jets");
    formatHist(subleadingjetET_EBEE,"Jet E_{T} (GeV)","Number of Jets");
    formatHist(subleadingjetMass_EBEE,"Jet Mass (GeV/c^{2})","Number of Jets");

    TH1D* jetDEta_EBEB = new TH1D("jetDEta_EBEB","",200,0.,10.);
    TH1D* dijetMass_EBEB = new TH1D("dijetMass_EBEB","",200,0.,4000.);
    TH1D* jetPhoEtaDiff_EBEB = new TH1D("jetPhoEtaDiff_EBEB","",200,0.,10.);
    TH1D* jetPhoDPhi_EBEB = new TH1D("jetPhoDPhi_EBEB","",200,0.,3.1416);

    formatHist(jetDEta_EBEB,"|#eta_{leading jet} - #eta_{subleading jet}|","Number Of Events");
    formatHist(dijetMass_EBEB,"m_{jj} (GeV/c^{2})","Number Of Events");
    formatHist(jetPhoEtaDiff_EBEB,"|#bar{#eta_{j}} - #eta_{#gamma#gamma}|","Number Of Events");
    formatHist(jetPhoDPhi_EBEB,"#Delta#varphi(dijet,diphoton)","Number Of Events");

    TH1D* jetDEta_EBEE = new TH1D("jetDEta_EBEE","",200,0.,10.);
    TH1D* dijetMass_EBEE = new TH1D("dijetMass_EBEE","",200,0.,4000.);
    TH1D* jetPhoEtaDiff_EBEE = new TH1D("jetPhoEtaDiff_EBEE","",200,0.,10.);
    TH1D* jetPhoDPhi_EBEE = new TH1D("jetPhoDPhi_EBEE","",200,0.,3.1416);

    formatHist(jetDEta_EBEE,"|#eta_{leading jet} - #eta_{subleading jet}|","Number Of Events");
    formatHist(dijetMass_EBEE,"m_{jj} (GeV/c^{2})","Number Of Events");
    formatHist(jetPhoEtaDiff_EBEE,"|#bar{#eta_{j}} - #eta_{#gamma#gamma}|","Number Of Events");
    formatHist(jetPhoDPhi_EBEE,"#Delta#varphi(dijet,diphoton)","Number Of Events");

    // book conversion based histos

    TH1D* conversionRadius = createTH1D("conversionRadius","conversionRadius",240,0.,120.,"Conversion Radius (cm)", "Number of Conversions");
    TH1D* conversionRadius_arbitratedMerged = createTH1D("conversionRadius_arbitratedMerged","conversionRadius_arbitratedMerged",240,0.,120.,"Conversion Radius (cm)", "Number of Conversions");

    TH1D* nTwoProngConversions_EBEB = createTH1D("nTwoProngConversions_EBEB","nTwoProngConversions_EBEB",11,-0.5,10.5,"Number of Conversions","Number of Events");
    TH1D* nOneProngConversions_EBEB = createTH1D("nOneProngConversions_EBEB","nOneProngConversions_EBEB",11,-0.5,10.5,"Number of Conversions","Number of Events");
    TH2D* twoProngConversionRZMap_EBEB = createTH2D("twoProngConversionRZMap_EBEB","twoProngConversionRZMap_EBEB",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    TH2D* twoProngConversionRPhiMap_EBEB = createTH2D("twoProngConversionRPhiMap_EBEB","twoProngConversionRPhiMap_EBEB",100,-3.1416,3.1416,240,0.,120.,"#varphi","r (cm)");
    TH2D* oneProngConversionRZMap_EBEB = createTH2D("oneProngConversionRZMap_EBEB","oneProngConversionRZMap_EBEB",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    TH2D* oneProngConversionRPhiMap_EBEB = createTH2D("oneProngConversionRPhiMap_EBEB","oneProngConversionRPhiMap_EBEB",100,-3.1416,3.1416,240,0.,120.,"#varphi","r (cm)");
    TH1D* pairCotThetaSeparation_EBEB = createTH1D("pairCotThetaSeparation_EBEB","pairCotThetaSeparation_EBEB",100,-8.,2.,"pairCotThetaSeparation","Number of Conversions");
    TH1D* dPhiTracksAtVtx_EBEB = createTH1D("dPhiTracksAtVtx_EBEB","dPhiTracksAtVtx_EBEB",100,-3.1416,3.1416,"#Delta#varphi of Tracks At Vtx","Number of Conversions");
    TH1D* photonConvdR_EBEB = createTH1D("photonConvdR_EBEB","photonConvdR_EBEB",100,0.,0.2,"#DeltaR(conversion,#gamma)","Number of Conversions");
    TH1D* nSharedHits_EBEB = createTH1D("nSharedHits_EBEB","nSharedHits_EBEB",21,-0.5,20.5,"Number of Shared Hits","Number of Conversions");


    TH1D* nTwoProngConversions_EBEE = createTH1D("nTwoProngConversions_EBEE","nTwoProngConversions_EBEE",11,-0.5,10.5,"Number of Conversions","Number of Events");
    TH1D* nOneProngConversions_EBEE = createTH1D("nOneProngConversions_EBEE","nOneProngConversions_EBEE",11,-0.5,10.5,"Number of Conversions","Number of Events");
    TH2D* twoProngConversionRZMap_EBEE = createTH2D("twoProngConversionRZMap_EBEE","twoProngConversionRZMap_EBEE",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    TH2D* twoProngConversionRPhiMap_EBEE = createTH2D("twoProngConversionRPhiMap_EBEE","twoProngConversionRPhiMap_EBEE",100,-3.1416,3.1416,240,0.,120.,"#varphi","r (cm)");
    TH2D* oneProngConversionRZMap_EBEE = createTH2D("oneProngConversionRZMap_EBEE","oneProngConversionRZMap_EBEE",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    TH2D* oneProngConversionRPhiMap_EBEE = createTH2D("oneProngConversionRPhiMap_EBEE","oneProngConversionRPhiMap_EBEE",100,-3.1416,3.1416,240,0.,120.,"#varphi","r (cm)");
    TH1D* pairCotThetaSeparation_EBEE = createTH1D("pairCotThetaSeparation_EBEE","pairCotThetaSeparation_EBEE",100,-8.,2.,"pairCotThetaSeparation","Number of Conversions");
    TH1D* dPhiTracksAtVtx_EBEE = createTH1D("dPhiTracksAtVtx_EBEE","dPhiTracksAtVtx_EBEE",100,-3.1416,3.1416,"#Delta#varphi of Tracks At Vtx","Number of Conversions");
    TH1D* photonConvdR_EBEE = createTH1D("photonConvdR_EBEE","photonConvdR_EBEE",100,0.,0.2,"#DeltaR(conversion,#gamma)","Number of Conversions");
    TH1D* nSharedHits_EBEE = createTH1D("nSharedHits_EBEE","nSharedHits_EBEE",21,-0.5,20.5,"Number of Shared Hits","Number of Conversions");

    // conversion vertex maps based on eta location and not on event type
    TH2D* twoProngConversionRZMap_EB = createTH2D("twoProngConversionRZMap_EB","twoProngConversionRZMap_EB",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    TH2D* twoProngConversionRPhiMap_EB = createTH2D("twoProngConversionRPhiMap_EB","twoProngConversionRPhiMap_EB",100,-3.1416,3.1416,240,0.,120.,"#varphi","r (cm)");
    TH2D* oneProngConversionRZMap_EB = createTH2D("oneProngConversionRZMap_EB","oneProngConversionRZMap_EB",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    TH2D* oneProngConversionRPhiMap_EB = createTH2D("oneProngConversionRPhiMap_EB","oneProngConversionRPhiMap_EB",100,-3.1416,3.1416,240,0.,120.,"#varphi","r (cm)");

    TH2D* twoProngConversionRZMap_EE = createTH2D("twoProngConversionRZMap_EE","twoProngConversionRZMap_EE",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    TH2D* twoProngConversionRPhiMap_EE = createTH2D("twoProngConversionRPhiMap_EE","twoProngConversionRPhiMap_EE",100,-3.1416,3.1416,240,0.,120.,"#varphi","r (cm)");
    TH2D* oneProngConversionRZMap_EE = createTH2D("oneProngConversionRZMap_EE","oneProngConversionRZMap_EE",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    TH2D* oneProngConversionRPhiMap_EE = createTH2D("oneProngConversionRPhiMap_EE","oneProngConversionRPhiMap_EE",100,-3.1416,3.1416,240,0.,120.,"#varphi","r (cm)");

    TH2D* twoProngConversionRZMap_arbitratedMerged_EB = createTH2D("twoProngConversionRZMap_arbitratedMerged_EB","twoProngConversionRZMap_arbitratedMerged_EB",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    TH2D* twoProngConversionRPhiMap_arbitratedMerged_EB = createTH2D("twoProngConversionRPhiMap_arbitratedMerged_EB","twoProngConversionRPhiMap_arbitratedMerged_EB",100,-3.1416,3.1416,240,0.,120.,"#varphi","r (cm)");
    TH2D* oneProngConversionRZMap_arbitratedMerged_EB = createTH2D("oneProngConversionRZMap_arbitratedMerged_EB","oneProngConversionRZMap_arbitratedMerged_EB",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    TH2D* oneProngConversionRPhiMap_arbitratedMerged_EB = createTH2D("oneProngConversionRPhiMap_arbitratedMerged_EB","oneProngConversionRPhiMap_arbitratedMerged_EB",100,-3.1416,3.1416,240,0.,120.,"#varphi","r (cm)");

    TH2D* twoProngConversionRZMap_arbitratedMerged_EE = createTH2D("twoProngConversionRZMap_arbitratedMerged_EE","twoProngConversionRZMap_arbitratedMerged_EE",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    TH2D* twoProngConversionRPhiMap_arbitratedMerged_EE = createTH2D("twoProngConversionRPhiMap_arbitratedMerged_EE","twoProngConversionRPhiMap_arbitratedMerged_EE",100,-3.1416,3.1416,240,0.,120.,"#varphi","r (cm)");
    TH2D* oneProngConversionRZMap_arbitratedMerged_EE = createTH2D("oneProngConversionRZMap_arbitratedMerged_EE","oneProngConversionRZMap_arbitratedMerged_EE",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    TH2D* oneProngConversionRPhiMap_arbitratedMerged_EE = createTH2D("oneProngConversionRPhiMap_arbitratedMerged_EE","oneProngConversionRPhiMap_arbitratedMerged_EE",100,-3.1416,3.1416,240,0.,120.,"#varphi","r (cm)");

    TH2D* twoProngConversionRZMap_highPurity_EB = createTH2D("twoProngConversionRZMap_highPurity_EB","twoProngConversionRZMap_highPurity_EB",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    TH2D* twoProngConversionRPhiMap_highPurity_EB = createTH2D("twoProngConversionRPhiMap_highPurity_EB","twoProngConversionRPhiMap_highPurity_EB",100,-3.1416,3.1416,240,0.,120.,"#varphi","r (cm)");
    TH2D* oneProngConversionRZMap_highPurity_EB = createTH2D("oneProngConversionRZMap_highPurity_EB","oneProngConversionRZMap_highPurity_EB",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    TH2D* oneProngConversionRPhiMap_highPurity_EB = createTH2D("oneProngConversionRPhiMap_highPurity_EB","oneProngConversionRPhiMap_highPurity_EB",100,-3.1416,3.1416,240,0.,120.,"#varphi","r (cm)");

    TH2D* twoProngConversionRZMap_highPurity_EE = createTH2D("twoProngConversionRZMap_highPurity_EE","twoProngConversionRZMap_highPurity_EE",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    TH2D* twoProngConversionRPhiMap_highPurity_EE = createTH2D("twoProngConversionRPhiMap_highPurity_EE","twoProngConversionRPhiMap_highPurity_EE",100,-3.1416,3.1416,240,0.,120.,"#varphi","r (cm)");
    TH2D* oneProngConversionRZMap_highPurity_EE = createTH2D("oneProngConversionRZMap_highPurity_EE","oneProngConversionRZMap_highPurity_EE",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    TH2D* oneProngConversionRPhiMap_highPurity_EE = createTH2D("oneProngConversionRPhiMap_highPurity_EE","oneProngConversionRPhiMap_highPurity_EE",100,-3.1416,3.1416,240,0.,120.,"#varphi","r (cm)");

    TH2D* twoProngConversionRZMap_oneEcalMatch_EB = createTH2D("twoProngConversionRZMap_oneEcalMatch_EB","twoProngConversionRZMap_oneEcalMatch_EB",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    TH2D* twoProngConversionRPhiMap_oneEcalMatch_EB = createTH2D("twoProngConversionRPhiMap_oneEcalMatch_EB","twoProngConversionRPhiMap_oneEcalMatch_EB",100,-3.1416,3.1416,240,0.,120.,"#varphi","r (cm)");
    TH2D* oneProngConversionRZMap_oneEcalMatch_EB = createTH2D("oneProngConversionRZMap_oneEcalMatch_EB","oneProngConversionRZMap_oneEcalMatch_EB",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    TH2D* oneProngConversionRPhiMap_oneEcalMatch_EB = createTH2D("oneProngConversionRPhiMap_oneEcalMatch_EB","oneProngConversionRPhiMap_oneEcalMatch_EB",100,-3.1416,3.1416,240,0.,120.,"#varphi","r (cm)");

    TH2D* twoProngConversionRZMap_oneEcalMatch_EE = createTH2D("twoProngConversionRZMap_oneEcalMatch_EE","twoProngConversionRZMap_oneEcalMatch_EE",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    TH2D* twoProngConversionRPhiMap_oneEcalMatch_EE = createTH2D("twoProngConversionRPhiMap_oneEcalMatch_EE","twoProngConversionRPhiMap_oneEcalMatch_EE",100,-3.1416,3.1416,240,0.,120.,"#varphi","r (cm)");
    TH2D* oneProngConversionRZMap_oneEcalMatch_EE = createTH2D("oneProngConversionRZMap_oneEcalMatch_EE","oneProngConversionRZMap_oneEcalMatch_EE",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    TH2D* oneProngConversionRPhiMap_oneEcalMatch_EE = createTH2D("oneProngConversionRPhiMap_oneEcalMatch_EE","oneProngConversionRPhiMap_oneEcalMatch_EE",100,-3.1416,3.1416,240,0.,120.,"#varphi","r (cm)");
        TH2D* twoProngConversionRZMap_twoEcalMatch_EB = createTH2D("twoProngConversionRZMap_twoEcalMatch_EB","twoProngConversionRZMap_twoEcalMatch_EB",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    TH2D* twoProngConversionRPhiMap_twoEcalMatch_EB = createTH2D("twoProngConversionRPhiMap_twoEcalMatch_EB","twoProngConversionRPhiMap_twoEcalMatch_EB",100,-3.1416,3.1416,240,0.,120.,"#varphi","r (cm)");
    TH2D* oneProngConversionRZMap_twoEcalMatch_EB = createTH2D("oneProngConversionRZMap_twoEcalMatch_EB","oneProngConversionRZMap_twoEcalMatch_EB",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    TH2D* oneProngConversionRPhiMap_twoEcalMatch_EB = createTH2D("oneProngConversionRPhiMap_twoEcalMatch_EB","oneProngConversionRPhiMap_twoEcalMatch_EB",100,-3.1416,3.1416,240,0.,120.,"#varphi","r (cm)");

    TH2D* twoProngConversionRZMap_twoEcalMatch_EE = createTH2D("twoProngConversionRZMap_twoEcalMatch_EE","twoProngConversionRZMap_twoEcalMatch_EE",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    TH2D* twoProngConversionRPhiMap_twoEcalMatch_EE = createTH2D("twoProngConversionRPhiMap_twoEcalMatch_EE","twoProngConversionRPhiMap_twoEcalMatch_EE",100,-3.1416,3.1416,240,0.,120.,"#varphi","r (cm)");
    TH2D* oneProngConversionRZMap_twoEcalMatch_EE = createTH2D("oneProngConversionRZMap_twoEcalMatch_EE","oneProngConversionRZMap_twoEcalMatch_EE",100,-300.,300.,240,0.,120.,"z (cm)","r (cm)");
    TH2D* oneProngConversionRPhiMap_twoEcalMatch_EE = createTH2D("oneProngConversionRPhiMap_twoEcalMatch_EE","oneProngConversionRPhiMap_twoEcalMatch_EE",100,-3.1416,3.1416,240,0.,120.,"#varphi","r (cm)");



    gROOT->SetBatch();

    if (fChain == 0) return;

    Long64_t nentries = fChain->GetEntriesFast();

    Long64_t nbytes = 0, nb = 0;
    for (Long64_t jentry=0; jentry<nentries;jentry++) {
        Long64_t ientry = LoadTree(jentry);
        if (ientry < 0) break;
        nb = fChain->GetEntry(jentry);   nbytes += nb;
        // if (Cut(ientry) < 0) continue;
        if (jentry % 1000 == 0) cout << "Now looking at event #" << jentry << endl;
        // Photon1 is the leading photon, Photon2 is the second leading
        // if (jentry>10) return;
        if (!TrigHLT_HLT_DoublePhoton60_v1) continue;
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

        // conversion r
        for (unsigned int i=0; i<ConvInfo1_r->size(); i++){
            conversionRadius->Fill( ConvInfo1_r->at(i) );
            bool isArbitratedMerged = ConvInfo1_quality->at(i).at(2);
            if (isArbitratedMerged) conversionRadius_arbitratedMerged->Fill( ConvInfo1_r->at(i) );
        }
        for (unsigned int i=0; i<ConvInfo2_r->size(); i++){
            conversionRadius->Fill( ConvInfo2_r->at(i) );
            bool isArbitratedMerged = ConvInfo2_quality->at(i).at(2);
            if (isArbitratedMerged) conversionRadius_arbitratedMerged->Fill( ConvInfo2_r->at(i) );
        }

        if (EBEB){
            leadingPhoPt_EBEB->Fill(Photon1_pt);
            subleadingPhoPt_EBEB->Fill(Photon2_pt);
            leadingPhoEta_EBEB->Fill(Photon1_scEta);
            subleadingPhoEta_EBEB->Fill(Photon2_scEta);
            leadingPhoPhi_EBEB->Fill(Photon1_scPhi);
            subleadingPhoPhi_EBEB->Fill(Photon2_scPhi);
            ggMass_EBEB->Fill(Diphoton_Minv);

            // conversion stuff
            nTwoProngConversions_EBEB->Fill(1.*ConvInfo1_r->size());
            nOneProngConversions_EBEB->Fill(1.*ConvInfo_OneLeg1_r->size());
            for (unsigned int i=0; i<ConvInfo1_r->size(); i++){
                twoProngConversionRZMap_EBEB->Fill(ConvInfo1_z->at(i),ConvInfo1_r->at(i));
                twoProngConversionRPhiMap_EBEB->Fill(ConvInfo1_phi->at(i),ConvInfo1_r->at(i));
                pairCotThetaSeparation_EBEB->Fill(ConvInfo1_pairCotThetaSeparation->at(i));
                dPhiTracksAtVtx_EBEB->Fill(ConvInfo1_dPhiTracksAtVtx->at(i));
                photonConvdR_EBEB->Fill(ConvInfo1_dRToSc->at(i));
                nSharedHits_EBEB->Fill(1.*ConvInfo1_nSharedHits->at(i));
            }
            for (unsigned int i=0; i<ConvInfo_OneLeg1_r->size(); i++){
                oneProngConversionRZMap_EBEB->Fill(ConvInfo_OneLeg1_z->at(i),ConvInfo_OneLeg1_r->at(i));
                oneProngConversionRPhiMap_EBEB->Fill(ConvInfo_OneLeg1_phi->at(i),ConvInfo_OneLeg1_r->at(i));
            }
        } // end EBEB block

        else if (EBEE){
            leadingPhoPt_EBEE->Fill(Photon1_pt);
            subleadingPhoPt_EBEE->Fill(Photon2_pt);
            leadingPhoEta_EBEE->Fill(Photon1_scEta);
            subleadingPhoEta_EBEE->Fill(Photon2_scEta);
            leadingPhoPhi_EBEE->Fill(Photon1_scPhi);
            subleadingPhoPhi_EBEE->Fill(Photon2_scPhi);
            ggMass_EBEE->Fill(Diphoton_Minv);
            // conversion stuff
            nTwoProngConversions_EBEE->Fill(1.*ConvInfo1_r->size());
            nOneProngConversions_EBEE->Fill(1.*ConvInfo_OneLeg1_r->size());
            for (unsigned int i=0; i<ConvInfo1_r->size(); i++){
                twoProngConversionRZMap_EBEE->Fill(ConvInfo1_z->at(i),ConvInfo1_r->at(i));
                twoProngConversionRPhiMap_EBEE->Fill(ConvInfo1_phi->at(i),ConvInfo1_r->at(i));
                pairCotThetaSeparation_EBEE->Fill(ConvInfo1_pairCotThetaSeparation->at(i));
                dPhiTracksAtVtx_EBEE->Fill(ConvInfo1_dPhiTracksAtVtx->at(i));
                photonConvdR_EBEE->Fill(ConvInfo1_dRToSc->at(i));
                nSharedHits_EBEE->Fill(1.*ConvInfo1_nSharedHits->at(i));
            }
            for (unsigned int i=0; i<ConvInfo_OneLeg1_r->size(); i++){
                oneProngConversionRZMap_EBEE->Fill(ConvInfo_OneLeg1_z->at(i),ConvInfo_OneLeg1_r->at(i));
                oneProngConversionRPhiMap_EBEE->Fill(ConvInfo_OneLeg1_phi->at(i),ConvInfo_OneLeg1_r->at(i));
            }
        } // end EBEE block

        // fill EB and EE based conversion maps

        if( isEB(Photon1_scEta) ){
            for (unsigned int i=0; i<ConvInfo1_r->size(); i++){
                twoProngConversionRZMap_EB->Fill( ConvInfo1_z->at(i), ConvInfo1_r->at(i) );
                twoProngConversionRPhiMap_EB->Fill( ConvInfo1_phi->at(i), ConvInfo1_r->at(i) );

                bool isHighPurity = ConvInfo1_quality->at(i).at(4);
                bool isArbitratedMerged = ConvInfo1_quality->at(i).at(2);
                bool oneEcalMatch = ConvInfo1_quality->at(i).at(6);
                bool twoEcalMatch = ConvInfo1_quality->at(i).at(7);

                if (isHighPurity){
                    twoProngConversionRZMap_highPurity_EB->Fill( ConvInfo1_z->at(i), ConvInfo1_r->at(i) );
                    twoProngConversionRPhiMap_highPurity_EB->Fill( ConvInfo1_phi->at(i), ConvInfo1_r->at(i) );
                }
                if (isArbitratedMerged){
                    twoProngConversionRZMap_arbitratedMerged_EB->Fill( ConvInfo1_z->at(i), ConvInfo1_r->at(i) );
                    twoProngConversionRPhiMap_arbitratedMerged_EB->Fill( ConvInfo1_phi->at(i), ConvInfo1_r->at(i) );   
                }
                if (oneEcalMatch){
                    twoProngConversionRZMap_oneEcalMatch_EB->Fill( ConvInfo1_z->at(i), ConvInfo1_r->at(i) );
                    twoProngConversionRPhiMap_oneEcalMatch_EB->Fill( ConvInfo1_phi->at(i), ConvInfo1_r->at(i) );
                }
                if (twoEcalMatch){
                    twoProngConversionRZMap_twoEcalMatch_EB->Fill( ConvInfo1_z->at(i), ConvInfo1_r->at(i) );
                    twoProngConversionRPhiMap_twoEcalMatch_EB->Fill( ConvInfo1_phi->at(i), ConvInfo1_r->at(i) );
                }
            }
            for (unsigned int i=0; i<ConvInfo_OneLeg1_r->size(); i++){
                oneProngConversionRZMap_EB->Fill( ConvInfo_OneLeg1_z->at(i), ConvInfo_OneLeg1_r->at(i) );
                oneProngConversionRPhiMap_EB->Fill( ConvInfo_OneLeg1_phi->at(i), ConvInfo_OneLeg1_r->at(i) );

                bool isHighPurity = ConvInfo_OneLeg1_quality->at(i).at(4);
                bool isArbitratedMerged = ConvInfo_OneLeg1_quality->at(i).at(2);
                bool oneEcalMatch = ConvInfo_OneLeg1_quality->at(i).at(6);
                bool twoEcalMatch = ConvInfo_OneLeg1_quality->at(i).at(7);

                if (isHighPurity){
                    oneProngConversionRZMap_highPurity_EB->Fill( ConvInfo_OneLeg1_z->at(i), ConvInfo_OneLeg1_r->at(i) );
                    oneProngConversionRPhiMap_highPurity_EB->Fill( ConvInfo_OneLeg1_phi->at(i), ConvInfo_OneLeg1_r->at(i) );
                }
                if (isArbitratedMerged){
                    oneProngConversionRZMap_arbitratedMerged_EB->Fill( ConvInfo_OneLeg1_z->at(i), ConvInfo_OneLeg1_r->at(i) );
                    oneProngConversionRPhiMap_arbitratedMerged_EB->Fill( ConvInfo_OneLeg1_phi->at(i), ConvInfo_OneLeg1_r->at(i) );   
                }
                if (oneEcalMatch){
                    oneProngConversionRZMap_oneEcalMatch_EB->Fill( ConvInfo_OneLeg1_z->at(i), ConvInfo_OneLeg1_r->at(i) );
                    oneProngConversionRPhiMap_oneEcalMatch_EB->Fill( ConvInfo_OneLeg1_phi->at(i), ConvInfo_OneLeg1_r->at(i) );
                }
                if (twoEcalMatch){
                    oneProngConversionRZMap_twoEcalMatch_EB->Fill( ConvInfo_OneLeg1_z->at(i), ConvInfo_OneLeg1_r->at(i) );
                    oneProngConversionRPhiMap_twoEcalMatch_EB->Fill( ConvInfo_OneLeg1_phi->at(i), ConvInfo_OneLeg1_r->at(i) );
                }
            }
        }
        else if ( isEE(Photon1_scEta) ){
            for (unsigned int i=0; i<ConvInfo1_r->size(); i++){
                twoProngConversionRZMap_EE->Fill( ConvInfo1_z->at(i), ConvInfo1_r->at(i) );
                twoProngConversionRPhiMap_EE->Fill( ConvInfo1_phi->at(i), ConvInfo1_r->at(i) );

                bool isHighPurity = ConvInfo1_quality->at(i).at(4);
                bool isArbitratedMerged = ConvInfo1_quality->at(i).at(2);
                bool oneEcalMatch = ConvInfo1_quality->at(i).at(6);
                bool twoEcalMatch = ConvInfo1_quality->at(i).at(7);

                if (isHighPurity){
                    twoProngConversionRZMap_highPurity_EE->Fill( ConvInfo1_z->at(i), ConvInfo1_r->at(i) );
                    twoProngConversionRPhiMap_highPurity_EE->Fill( ConvInfo1_phi->at(i), ConvInfo1_r->at(i) );
                }
                if (isArbitratedMerged){
                    twoProngConversionRZMap_arbitratedMerged_EE->Fill( ConvInfo1_z->at(i), ConvInfo1_r->at(i) );
                    twoProngConversionRPhiMap_arbitratedMerged_EE->Fill( ConvInfo1_phi->at(i), ConvInfo1_r->at(i) );   
                }
                if (oneEcalMatch){
                    twoProngConversionRZMap_oneEcalMatch_EE->Fill( ConvInfo1_z->at(i), ConvInfo1_r->at(i) );
                    twoProngConversionRPhiMap_oneEcalMatch_EE->Fill( ConvInfo1_phi->at(i), ConvInfo1_r->at(i) );
                }
                if (twoEcalMatch){
                    twoProngConversionRZMap_twoEcalMatch_EE->Fill( ConvInfo1_z->at(i), ConvInfo1_r->at(i) );
                    twoProngConversionRPhiMap_twoEcalMatch_EE->Fill( ConvInfo1_phi->at(i), ConvInfo1_r->at(i) );
                }               
            }
            for (unsigned int i=0; i<ConvInfo_OneLeg1_r->size(); i++){
                oneProngConversionRZMap_EE->Fill( ConvInfo_OneLeg1_z->at(i), ConvInfo_OneLeg1_r->at(i) );
                oneProngConversionRPhiMap_EE->Fill( ConvInfo_OneLeg1_phi->at(i), ConvInfo_OneLeg1_r->at(i) );

                bool isHighPurity = ConvInfo_OneLeg1_quality->at(i).at(4);
                bool isArbitratedMerged = ConvInfo_OneLeg1_quality->at(i).at(2);
                bool oneEcalMatch = ConvInfo_OneLeg1_quality->at(i).at(6);
                bool twoEcalMatch = ConvInfo_OneLeg1_quality->at(i).at(7);

                if (isHighPurity){
                    oneProngConversionRZMap_highPurity_EE->Fill( ConvInfo_OneLeg1_z->at(i), ConvInfo_OneLeg1_r->at(i) );
                    oneProngConversionRPhiMap_highPurity_EE->Fill( ConvInfo_OneLeg1_phi->at(i), ConvInfo_OneLeg1_r->at(i) );
                }
                if (isArbitratedMerged){
                    oneProngConversionRZMap_arbitratedMerged_EE->Fill( ConvInfo_OneLeg1_z->at(i), ConvInfo_OneLeg1_r->at(i) );
                    oneProngConversionRPhiMap_arbitratedMerged_EE->Fill( ConvInfo_OneLeg1_phi->at(i), ConvInfo_OneLeg1_r->at(i) );   
                }
                if (oneEcalMatch){
                    oneProngConversionRZMap_oneEcalMatch_EE->Fill( ConvInfo_OneLeg1_z->at(i), ConvInfo_OneLeg1_r->at(i) );
                    oneProngConversionRPhiMap_oneEcalMatch_EE->Fill( ConvInfo_OneLeg1_phi->at(i), ConvInfo_OneLeg1_r->at(i) );
                }
                if (twoEcalMatch){
                    oneProngConversionRZMap_twoEcalMatch_EE->Fill( ConvInfo_OneLeg1_z->at(i), ConvInfo_OneLeg1_r->at(i) );
                    oneProngConversionRPhiMap_twoEcalMatch_EE->Fill( ConvInfo_OneLeg1_phi->at(i), ConvInfo_OneLeg1_r->at(i) );
                }                
            }
        }

        if( isEB(Photon2_scEta) ){
            for (unsigned int i=0; i<ConvInfo2_r->size(); i++){
                twoProngConversionRZMap_EB->Fill( ConvInfo2_z->at(i), ConvInfo2_r->at(i) );
                twoProngConversionRPhiMap_EB->Fill( ConvInfo2_phi->at(i), ConvInfo2_r->at(i) );

                bool isHighPurity = ConvInfo2_quality->at(i).at(4);
                bool isArbitratedMerged = ConvInfo2_quality->at(i).at(2);
                bool oneEcalMatch = ConvInfo2_quality->at(i).at(6);
                bool twoEcalMatch = ConvInfo2_quality->at(i).at(7);

                if (isHighPurity){
                    twoProngConversionRZMap_highPurity_EB->Fill( ConvInfo2_z->at(i), ConvInfo2_r->at(i) );
                    twoProngConversionRPhiMap_highPurity_EB->Fill( ConvInfo2_phi->at(i), ConvInfo2_r->at(i) );
                }
                if (isArbitratedMerged){
                    twoProngConversionRZMap_arbitratedMerged_EB->Fill( ConvInfo2_z->at(i), ConvInfo2_r->at(i) );
                    twoProngConversionRPhiMap_arbitratedMerged_EB->Fill( ConvInfo2_phi->at(i), ConvInfo2_r->at(i) );   
                }
                if (oneEcalMatch){
                    twoProngConversionRZMap_oneEcalMatch_EB->Fill( ConvInfo2_z->at(i), ConvInfo2_r->at(i) );
                    twoProngConversionRPhiMap_oneEcalMatch_EB->Fill( ConvInfo2_phi->at(i), ConvInfo2_r->at(i) );
                }
                if (twoEcalMatch){
                    twoProngConversionRZMap_twoEcalMatch_EB->Fill( ConvInfo2_z->at(i), ConvInfo2_r->at(i) );
                    twoProngConversionRPhiMap_twoEcalMatch_EB->Fill( ConvInfo2_phi->at(i), ConvInfo2_r->at(i) );
                }
            }
            for (unsigned int i=0; i<ConvInfo_OneLeg2_r->size(); i++){
                oneProngConversionRZMap_EB->Fill( ConvInfo_OneLeg2_z->at(i), ConvInfo_OneLeg2_r->at(i) );
                oneProngConversionRPhiMap_EB->Fill( ConvInfo_OneLeg2_phi->at(i), ConvInfo_OneLeg2_r->at(i) );

                bool isHighPurity = ConvInfo_OneLeg2_quality->at(i).at(4);
                bool isArbitratedMerged = ConvInfo_OneLeg2_quality->at(i).at(2);
                bool oneEcalMatch = ConvInfo_OneLeg2_quality->at(i).at(6);
                bool twoEcalMatch = ConvInfo_OneLeg2_quality->at(i).at(7);

                if (isHighPurity){
                    oneProngConversionRZMap_highPurity_EB->Fill( ConvInfo_OneLeg2_z->at(i), ConvInfo_OneLeg2_r->at(i) );
                    oneProngConversionRPhiMap_highPurity_EB->Fill( ConvInfo_OneLeg2_phi->at(i), ConvInfo_OneLeg2_r->at(i) );
                }
                if (isArbitratedMerged){
                    oneProngConversionRZMap_arbitratedMerged_EB->Fill( ConvInfo_OneLeg2_z->at(i), ConvInfo_OneLeg2_r->at(i) );
                    oneProngConversionRPhiMap_arbitratedMerged_EB->Fill( ConvInfo_OneLeg2_phi->at(i), ConvInfo_OneLeg2_r->at(i) );   
                }
                if (oneEcalMatch){
                    oneProngConversionRZMap_oneEcalMatch_EB->Fill( ConvInfo_OneLeg2_z->at(i), ConvInfo_OneLeg2_r->at(i) );
                    oneProngConversionRPhiMap_oneEcalMatch_EB->Fill( ConvInfo_OneLeg2_phi->at(i), ConvInfo_OneLeg2_r->at(i) );
                }
                if (twoEcalMatch){
                    oneProngConversionRZMap_twoEcalMatch_EB->Fill( ConvInfo_OneLeg2_z->at(i), ConvInfo_OneLeg2_r->at(i) );
                    oneProngConversionRPhiMap_twoEcalMatch_EB->Fill( ConvInfo_OneLeg2_phi->at(i), ConvInfo_OneLeg2_r->at(i) );
                }
            }
        }
        else if ( isEE(Photon2_scEta) ){
            for (unsigned int i=0; i<ConvInfo2_r->size(); i++){
                twoProngConversionRZMap_EE->Fill( ConvInfo2_z->at(i), ConvInfo2_r->at(i) );
                twoProngConversionRPhiMap_EE->Fill( ConvInfo2_phi->at(i), ConvInfo2_r->at(i) );

                bool isHighPurity = ConvInfo2_quality->at(i).at(4);
                bool isArbitratedMerged = ConvInfo2_quality->at(i).at(2);
                bool oneEcalMatch = ConvInfo2_quality->at(i).at(6);
                bool twoEcalMatch = ConvInfo2_quality->at(i).at(7);

                if (isHighPurity){
                    twoProngConversionRZMap_highPurity_EE->Fill( ConvInfo2_z->at(i), ConvInfo2_r->at(i) );
                    twoProngConversionRPhiMap_highPurity_EE->Fill( ConvInfo2_phi->at(i), ConvInfo2_r->at(i) );
                }
                if (isArbitratedMerged){
                    twoProngConversionRZMap_arbitratedMerged_EE->Fill( ConvInfo2_z->at(i), ConvInfo2_r->at(i) );
                    twoProngConversionRPhiMap_arbitratedMerged_EE->Fill( ConvInfo2_phi->at(i), ConvInfo2_r->at(i) );   
                }
                if (oneEcalMatch){
                    twoProngConversionRZMap_oneEcalMatch_EE->Fill( ConvInfo2_z->at(i), ConvInfo2_r->at(i) );
                    twoProngConversionRPhiMap_oneEcalMatch_EE->Fill( ConvInfo2_phi->at(i), ConvInfo2_r->at(i) );
                }
                if (twoEcalMatch){
                    twoProngConversionRZMap_twoEcalMatch_EE->Fill( ConvInfo2_z->at(i), ConvInfo2_r->at(i) );
                    twoProngConversionRPhiMap_twoEcalMatch_EE->Fill( ConvInfo2_phi->at(i), ConvInfo2_r->at(i) );
                }               
            }
            for (unsigned int i=0; i<ConvInfo_OneLeg2_r->size(); i++){
                oneProngConversionRZMap_EE->Fill( ConvInfo_OneLeg2_z->at(i), ConvInfo_OneLeg2_r->at(i) );
                oneProngConversionRPhiMap_EE->Fill( ConvInfo_OneLeg2_phi->at(i), ConvInfo_OneLeg2_r->at(i) );

                bool isHighPurity = ConvInfo_OneLeg2_quality->at(i).at(4);
                bool isArbitratedMerged = ConvInfo_OneLeg2_quality->at(i).at(2);
                bool oneEcalMatch = ConvInfo_OneLeg2_quality->at(i).at(6);
                bool twoEcalMatch = ConvInfo_OneLeg2_quality->at(i).at(7);

                if (isHighPurity){
                    oneProngConversionRZMap_highPurity_EE->Fill( ConvInfo_OneLeg2_z->at(i), ConvInfo_OneLeg2_r->at(i) );
                    oneProngConversionRPhiMap_highPurity_EE->Fill( ConvInfo_OneLeg2_phi->at(i), ConvInfo_OneLeg2_r->at(i) );
                }
                if (isArbitratedMerged){
                    oneProngConversionRZMap_arbitratedMerged_EE->Fill( ConvInfo_OneLeg2_z->at(i), ConvInfo_OneLeg2_r->at(i) );
                    oneProngConversionRPhiMap_arbitratedMerged_EE->Fill( ConvInfo_OneLeg2_phi->at(i), ConvInfo_OneLeg2_r->at(i) );   
                }
                if (oneEcalMatch){
                    oneProngConversionRZMap_oneEcalMatch_EE->Fill( ConvInfo_OneLeg2_z->at(i), ConvInfo_OneLeg2_r->at(i) );
                    oneProngConversionRPhiMap_oneEcalMatch_EE->Fill( ConvInfo_OneLeg2_phi->at(i), ConvInfo_OneLeg2_r->at(i) );
                }
                if (twoEcalMatch){
                    oneProngConversionRZMap_twoEcalMatch_EE->Fill( ConvInfo_OneLeg2_z->at(i), ConvInfo_OneLeg2_r->at(i) );
                    oneProngConversionRPhiMap_twoEcalMatch_EE->Fill( ConvInfo_OneLeg2_phi->at(i), ConvInfo_OneLeg2_r->at(i) );
                }                
            }
        }
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

    TFile f("dataplots.root","recreate");
    f.cd();
    leadingPhoPt_EBEB->Write();
    leadingPhoPt_EBEE->Write();
    subleadingPhoPt_EBEB->Write();
    subleadingPhoPt_EBEE->Write();
    leadingPhoEta_EBEB->Write();
    leadingPhoEta_EBEE->Write();
    subleadingPhoEta_EBEB->Write();
    subleadingPhoEta_EBEE->Write();
    leadingPhoPhi_EBEB->Write();
    leadingPhoPhi_EBEE->Write();
    subleadingPhoPhi_EBEB->Write();
    subleadingPhoPhi_EBEE->Write();
    ggMass_EBEB->Write();
    ggMass_EBEE->Write();
    nJets_EBEB->Write();
    nJets_EBEE->Write();

    leadingjetPt_EBEB->Write();
    leadingjetEta_EBEB->Write();
    leadingjetPhi_EBEB->Write();
    leadingjetMass_EBEB->Write();
    leadingjetET_EBEB->Write();
    subleadingjetPt_EBEB->Write();
    subleadingjetEta_EBEB->Write();
    subleadingjetPhi_EBEB->Write();
    subleadingjetMass_EBEB->Write();
    subleadingjetET_EBEB->Write();

    leadingjetPt_EBEE->Write();
    leadingjetEta_EBEE->Write();
    leadingjetPhi_EBEE->Write();
    leadingjetMass_EBEE->Write();
    leadingjetET_EBEE->Write();
    subleadingjetPt_EBEE->Write();
    subleadingjetEta_EBEE->Write();
    subleadingjetPhi_EBEE->Write();
    subleadingjetMass_EBEE->Write();
    subleadingjetET_EBEE->Write();

    jetDEta_EBEB->Write();
    dijetMass_EBEB->Write();
    jetPhoEtaDiff_EBEB->Write();
    jetPhoDPhi_EBEB->Write();

    jetDEta_EBEE->Write();
    dijetMass_EBEE->Write();
    jetPhoEtaDiff_EBEE->Write();
    jetPhoDPhi_EBEE->Write();

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

    nTwoProngConversions_EBEB->Write();
    nOneProngConversions_EBEB->Write();
    twoProngConversionRZMap_EBEB->Write();
    twoProngConversionRPhiMap_EBEB->Write();
    oneProngConversionRZMap_EBEB->Write();
    oneProngConversionRPhiMap_EBEB->Write();
    pairCotThetaSeparation_EBEB->Write();
    dPhiTracksAtVtx_EBEB->Write();
    photonConvdR_EBEB->Write();
    nSharedHits_EBEB->Write();
    nTwoProngConversions_EBEE->Write();
    nOneProngConversions_EBEE->Write();
    twoProngConversionRZMap_EBEE->Write();
    twoProngConversionRPhiMap_EBEE->Write();
    oneProngConversionRZMap_EBEE->Write();
    oneProngConversionRPhiMap_EBEE->Write();
    pairCotThetaSeparation_EBEE->Write();
    dPhiTracksAtVtx_EBEE->Write();
    photonConvdR_EBEE->Write();
    nSharedHits_EBEE->Write();
    twoProngConversionRZMap_EB->Write();
    twoProngConversionRPhiMap_EB->Write();
    oneProngConversionRZMap_EB->Write();
    oneProngConversionRPhiMap_EB->Write();
    twoProngConversionRZMap_EE->Write();
    twoProngConversionRPhiMap_EE->Write();
    oneProngConversionRZMap_EE->Write();
    oneProngConversionRPhiMap_EE->Write();

    twoProngConversionRZMap_arbitratedMerged_EB->Write();
    twoProngConversionRPhiMap_arbitratedMerged_EB->Write();
    oneProngConversionRZMap_arbitratedMerged_EB->Write();
    oneProngConversionRPhiMap_arbitratedMerged_EB->Write();
    twoProngConversionRZMap_arbitratedMerged_EE->Write();
    twoProngConversionRPhiMap_arbitratedMerged_EE->Write();
    oneProngConversionRZMap_arbitratedMerged_EE->Write();
    oneProngConversionRPhiMap_arbitratedMerged_EE->Write();
    twoProngConversionRZMap_highPurity_EB->Write();
    twoProngConversionRPhiMap_highPurity_EB->Write();
    oneProngConversionRZMap_highPurity_EB->Write();
    oneProngConversionRPhiMap_highPurity_EB->Write();
    twoProngConversionRZMap_highPurity_EE->Write();
    twoProngConversionRPhiMap_highPurity_EE->Write();
    oneProngConversionRZMap_highPurity_EE->Write();
    oneProngConversionRPhiMap_highPurity_EE->Write();
    conversionRadius->Write();
    conversionRadius_arbitratedMerged->Write();
    // twoProngConversionRZMap_oneEcalMatch_EB->Write();
    // twoProngConversionRPhiMap_oneEcalMatch_EB->Write();
    // oneProngConversionRZMap_oneEcalMatch_EB->Write();
    // oneProngConversionRPhiMap_oneEcalMatch_EB->Write();
    // twoProngConversionRZMap_oneEcalMatch_EE->Write();
    // twoProngConversionRPhiMap_oneEcalMatch_EE->Write();
    // oneProngConversionRZMap_oneEcalMatch_EE->Write();
    // oneProngConversionRPhiMap_oneEcalMatch_EE->Write();
    // twoProngConversionRZMap_twoEcalMatch_EB->Write();
    // twoProngConversionRPhiMap_twoEcalMatch_EB->Write();
    // oneProngConversionRZMap_twoEcalMatch_EB->Write();
    // oneProngConversionRPhiMap_twoEcalMatch_EB->Write();
    // twoProngConversionRZMap_twoEcalMatch_EE->Write();
    // twoProngConversionRPhiMap_twoEcalMatch_EE->Write();
    // oneProngConversionRZMap_twoEcalMatch_EE->Write();
    // oneProngConversionRPhiMap_twoEcalMatch_EE->Write();

    f.Close();
} // end fTree::Loop() method
