#include "fTree.C"

void driverADD(TString ms, TString massBin, TString outfilename, bool applyEventWeights=false) {
  // use stopwatch to time
  TStopwatch sw;
  sw.Start();

  // create tchain of all files to loop over
  TChain *chain = new TChain("diphotonAnalyzer/fTree");

  cout << "Running over Ms=" << ms << ", massBin=" << massBin << ", and writing out to " << outfilename << endl;  
  cout << "applyEventWeights = " << applyEventWeights << endl;
  
  if ( ms.EqualTo("4000") && massBin.EqualTo("200To500") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-4000_NED-4_KK-1_M-200To500_13TeV-sherpa/crab_ADDGravToGG_MS-4000_NED-4_KK-1_M-200To500_13TeV-sherpa/160727_034414/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("4000") && massBin.EqualTo("500To1000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-4000_NED-4_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-4000_NED-4_KK-1_M-500To1000_13TeV-sherpa/160727_034428/0000/ExoDiPhotonAnalyzer_1.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-4000_NED-4_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-4000_NED-4_KK-1_M-500To1000_13TeV-sherpa/160727_034428/0000/ExoDiPhotonAnalyzer_2.root",0);
  }
  else if ( ms.EqualTo("4000") && massBin.EqualTo("1000To2000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-4000_NED-4_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-4000_NED-4_KK-1_M-1000To2000_13TeV-sherpa/160727_034351/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("4000") && massBin.EqualTo("2000To4000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-4000_NED-4_KK-1_M-2000To4000_13TeV-sherpa/crab_ADDGravToGG_MS-4000_NED-4_KK-1_M-2000To4000_13TeV-sherpa/160727_034403/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("5000") && massBin.EqualTo("200To500") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-5000_NED-4_KK-1_M-200To500_13TeV-sherpa/crab_ADDGravToGG_MS-5000_NED-4_KK-1_M-200To500_13TeV-sherpa/160727_034614/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("5000") && massBin.EqualTo("500To1000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-5000_NED-4_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-5000_NED-4_KK-1_M-500To1000_13TeV-sherpa/160727_034642/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("5000") && massBin.EqualTo("1000To2000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-5000_NED-4_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-5000_NED-4_KK-1_M-1000To2000_13TeV-sherpa/160727_034548/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("5000") && massBin.EqualTo("2000To3000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-5000_NED-4_KK-1_M-2000To3000_13TeV-sherpa/crab_ADDGravToGG_MS-5000_NED-4_KK-1_M-2000To3000_13TeV-sherpa/160727_034600/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("5000") && massBin.EqualTo("3000To5000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-5000_NED-4_KK-1_M-3000To5000_13TeV-sherpa/crab_ADDGravToGG_MS-5000_NED-4_KK-1_M-3000To5000_13TeV-sherpa/160727_034628/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("3500") && massBin.EqualTo("200To500") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-3500_NED-4_KK-1_M-200To500_13TeV-sherpa/crab_ADDGravToGG_MS-3500_NED-4_KK-1_M-200To500_13TeV-sherpa/160727_034316/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("3500") && massBin.EqualTo("500To1000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-3500_NED-4_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-3500_NED-4_KK-1_M-500To1000_13TeV-sherpa/160727_035453/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("3500") && massBin.EqualTo("1000To2000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-3500_NED-4_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-3500_NED-4_KK-1_M-1000To2000_13TeV-sherpa/160727_034251/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("3500") && massBin.EqualTo("2000To3500") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-3500_NED-4_KK-1_M-2000To3500_13TeV-sherpa/crab_ADDGravToGG_MS-3500_NED-4_KK-1_M-2000To3500_13TeV-sherpa/160727_034304/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("6000") && massBin.EqualTo("200To500") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-6000_NED-4_KK-1_M-200To500_13TeV-sherpa/crab_ADDGravToGG_MS-6000_NED-4_KK-1_M-200To500_13TeV-sherpa/160727_034834/0000/ExoDiPhotonAnalyzer_1.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-6000_NED-4_KK-1_M-200To500_13TeV-sherpa/crab_ADDGravToGG_MS-6000_NED-4_KK-1_M-200To500_13TeV-sherpa/160727_034834/0000/ExoDiPhotonAnalyzer_2.root",0);
  }
  else if ( ms.EqualTo("6000") && massBin.EqualTo("500To1000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-6000_NED-4_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-6000_NED-4_KK-1_M-500To1000_13TeV-sherpa/160727_034858/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("6000") && massBin.EqualTo("1000To2000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-6000_NED-4_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-6000_NED-4_KK-1_M-1000To2000_13TeV-sherpa/160727_034805/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("6000") && massBin.EqualTo("2000To4000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-6000_NED-4_KK-1_M-2000To4000_13TeV-sherpa/crab_ADDGravToGG_MS-6000_NED-4_KK-1_M-2000To4000_13TeV-sherpa/160727_034821/0000/ExoDiPhotonAnalyzer_1.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-6000_NED-4_KK-1_M-2000To4000_13TeV-sherpa/crab_ADDGravToGG_MS-6000_NED-4_KK-1_M-2000To4000_13TeV-sherpa/160727_034821/0000/ExoDiPhotonAnalyzer_2.root",0);
  }
  else if ( ms.EqualTo("6000") && massBin.EqualTo("4000To6000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-6000_NED-4_KK-1_M-4000To6000_13TeV-sherpa/crab_ADDGravToGG_MS-6000_NED-4_KK-1_M-4000To6000_13TeV-sherpa/160727_034846/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("4500") && massBin.EqualTo("200To500") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-4500_NED-4_KK-1_M-200To500_13TeV-sherpa/crab_ADDGravToGG_MS-4500_NED-4_KK-1_M-200To500_13TeV-sherpa/160727_034510/0000/ExoDiPhotonAnalyzer_1.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-4500_NED-4_KK-1_M-200To500_13TeV-sherpa/crab_ADDGravToGG_MS-4500_NED-4_KK-1_M-200To500_13TeV-sherpa/160727_034510/0000/ExoDiPhotonAnalyzer_2.root",0);
  }
  else if ( ms.EqualTo("4500") && massBin.EqualTo("500To1000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-4500_NED-4_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-4500_NED-4_KK-1_M-500To1000_13TeV-sherpa/160727_034535/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("4500") && massBin.EqualTo("1000To2000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-4500_NED-4_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-4500_NED-4_KK-1_M-1000To2000_13TeV-sherpa/160727_034445/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("4500") && massBin.EqualTo("2000To3000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-4500_NED-4_KK-1_M-2000To3000_13TeV-sherpa/crab_ADDGravToGG_MS-4500_NED-4_KK-1_M-2000To3000_13TeV-sherpa/160727_034457/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("4500") && massBin.EqualTo("3000To4500") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-4500_NED-4_KK-1_M-3000To4500_13TeV-sherpa/crab_ADDGravToGG_MS-4500_NED-4_KK-1_M-3000To4500_13TeV-sherpa/160727_034523/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("3000") && massBin.EqualTo("200To500") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-3000_NED-4_KK-1_M-200To500_13TeV-sherpa/crab_ADDGravToGG_MS-3000_NED-4_KK-1_M-200To500_13TeV-sherpa/160727_034214/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("3000") && massBin.EqualTo("500To1000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-3000_NED-4_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-3000_NED-4_KK-1_M-500To1000_13TeV-sherpa/160727_033847/0000/ExoDiPhotonAnalyzer_1.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-3000_NED-4_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-3000_NED-4_KK-1_M-500To1000_13TeV-sherpa/160727_033847/0000/ExoDiPhotonAnalyzer_2.root",0);
  }
  else if ( ms.EqualTo("3000") && massBin.EqualTo("1000To2000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-3000_NED-4_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-3000_NED-4_KK-1_M-1000To2000_13TeV-sherpa/160727_034146/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("3000") && massBin.EqualTo("2000To3000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-3000_NED-4_KK-1_M-2000To3000_13TeV-sherpa/crab_ADDGravToGG_MS-3000_NED-4_KK-1_M-2000To3000_13TeV-sherpa/160727_034202/0000/ExoDiPhotonAnalyzer_1.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-3000_NED-4_KK-1_M-2000To3000_13TeV-sherpa/crab_ADDGravToGG_MS-3000_NED-4_KK-1_M-2000To3000_13TeV-sherpa/160727_034202/0000/ExoDiPhotonAnalyzer_2.root",0);
  }
  else if ( ms.EqualTo("5500") && massBin.EqualTo("200To500") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-5500_NED-4_KK-1_M-200To500_13TeV-sherpa/crab_ADDGravToGG_MS-5500_NED-4_KK-1_M-200To500_13TeV-sherpa/160727_034725/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("5500") && massBin.EqualTo("500To1000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-5500_NED-4_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-5500_NED-4_KK-1_M-500To1000_13TeV-sherpa/160727_034752/0000/ExoDiPhotonAnalyzer_1.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-5500_NED-4_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-5500_NED-4_KK-1_M-500To1000_13TeV-sherpa/160727_034752/0000/ExoDiPhotonAnalyzer_2.root",0);
  }
  else if ( ms.EqualTo("5500") && massBin.EqualTo("1000To2000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-5500_NED-4_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-5500_NED-4_KK-1_M-1000To2000_13TeV-sherpa/160727_034656/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("5500") && massBin.EqualTo("2000To4000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-5500_NED-4_KK-1_M-2000To4000_13TeV-sherpa/crab_ADDGravToGG_MS-5500_NED-4_KK-1_M-2000To4000_13TeV-sherpa/160727_034712/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("5500") && massBin.EqualTo("4000To5500") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/ADDGravToGG_MS-5500_NED-4_KK-1_M-4000To5500_13TeV-sherpa/crab_ADDGravToGG_MS-5500_NED-4_KK-1_M-4000To5500_13TeV-sherpa/160727_034740/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("ADDBkg") && massBin.EqualTo("200To500") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/GG_M-200To500_Pt-70_13TeV-sherpa/crab_GG_M-200To500_Pt-70_13TeV-sherpa/160727_034939/0000/ExoDiPhotonAnalyzer_1.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/GG_M-200To500_Pt-70_13TeV-sherpa/crab_GG_M-200To500_Pt-70_13TeV-sherpa/160727_034939/0000/ExoDiPhotonAnalyzer_2.root",0);
  }
  else if ( ms.EqualTo("ADDBkg") && massBin.EqualTo("500To1000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/GG_M-500To1000_Pt-70_13TeV-sherpa/crab_GG_M-500To1000_Pt-70_13TeV-sherpa/160727_035003/0000/ExoDiPhotonAnalyzer_1.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/GG_M-500To1000_Pt-70_13TeV-sherpa/crab_GG_M-500To1000_Pt-70_13TeV-sherpa/160727_035003/0000/ExoDiPhotonAnalyzer_2.root",0);
  }
  else if ( ms.EqualTo("ADDBkg") && massBin.EqualTo("1000To2000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/GG_M-1000To2000_Pt-70_13TeV-sherpa/crab_GG_M-1000To2000_Pt-70_13TeV-sherpa/160727_034909/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("ADDBkg") && massBin.EqualTo("2000To4000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/GG_M-2000To4000_Pt-70_13TeV-sherpa/crab_GG_M-2000To4000_Pt-70_13TeV-sherpa/160727_034925/0000/ExoDiPhotonAnalyzer_1.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/GG_M-2000To4000_Pt-70_13TeV-sherpa/crab_GG_M-2000To4000_Pt-70_13TeV-sherpa/160727_034925/0000/ExoDiPhotonAnalyzer_2.root",0);
  }
  else if ( ms.EqualTo("ADDBkg") && massBin.EqualTo("4000To8000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/GG_M-4000To8000_Pt-70_13TeV-sherpa/crab_GG_M-4000To8000_Pt-70_13TeV-sherpa/160727_034950/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("ADDBkg") && massBin.EqualTo("8000To13000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/GG_M-8000To13000_Pt-70_13TeV-sherpa/crab_GG_M-8000To13000_Pt-70_13TeV-sherpa/160727_035016/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("GGJets") && massBin.EqualTo("60To200") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-60To200_Pt-50_13TeV-sherpa/crab_GGJets_M-60To200_Pt-50/160727_044859/0000/ExoDiPhotonAnalyzer_1.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-60To200_Pt-50_13TeV-sherpa/crab_GGJets_M-60To200_Pt-50/160727_044859/0000/ExoDiPhotonAnalyzer_10.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-60To200_Pt-50_13TeV-sherpa/crab_GGJets_M-60To200_Pt-50/160727_044859/0000/ExoDiPhotonAnalyzer_2.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-60To200_Pt-50_13TeV-sherpa/crab_GGJets_M-60To200_Pt-50/160727_044859/0000/ExoDiPhotonAnalyzer_3.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-60To200_Pt-50_13TeV-sherpa/crab_GGJets_M-60To200_Pt-50/160727_044859/0000/ExoDiPhotonAnalyzer_4.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-60To200_Pt-50_13TeV-sherpa/crab_GGJets_M-60To200_Pt-50/160727_044859/0000/ExoDiPhotonAnalyzer_5.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-60To200_Pt-50_13TeV-sherpa/crab_GGJets_M-60To200_Pt-50/160727_044859/0000/ExoDiPhotonAnalyzer_6.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-60To200_Pt-50_13TeV-sherpa/crab_GGJets_M-60To200_Pt-50/160727_044859/0000/ExoDiPhotonAnalyzer_7.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-60To200_Pt-50_13TeV-sherpa/crab_GGJets_M-60To200_Pt-50/160727_044859/0000/ExoDiPhotonAnalyzer_8.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-60To200_Pt-50_13TeV-sherpa/crab_GGJets_M-60To200_Pt-50/160727_044859/0000/ExoDiPhotonAnalyzer_9.root",0);
  }
  else if ( ms.EqualTo("GGJets") && massBin.EqualTo("200To500") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50/160727_172604/0000/ExoDiPhotonAnalyzer_1.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50/160727_172604/0000/ExoDiPhotonAnalyzer_10.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50/160727_172604/0000/ExoDiPhotonAnalyzer_11.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50/160727_172604/0000/ExoDiPhotonAnalyzer_12.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50/160727_172604/0000/ExoDiPhotonAnalyzer_13.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50/160727_172604/0000/ExoDiPhotonAnalyzer_14.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50/160727_172604/0000/ExoDiPhotonAnalyzer_15.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50/160727_172604/0000/ExoDiPhotonAnalyzer_16.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50/160727_172604/0000/ExoDiPhotonAnalyzer_17.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50/160727_172604/0000/ExoDiPhotonAnalyzer_18.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50/160727_172604/0000/ExoDiPhotonAnalyzer_19.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50/160727_172604/0000/ExoDiPhotonAnalyzer_2.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50/160727_172604/0000/ExoDiPhotonAnalyzer_20.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50/160727_172604/0000/ExoDiPhotonAnalyzer_21.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50/160727_172604/0000/ExoDiPhotonAnalyzer_22.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50/160727_172604/0000/ExoDiPhotonAnalyzer_23.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50/160727_172604/0000/ExoDiPhotonAnalyzer_24.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50/160727_172604/0000/ExoDiPhotonAnalyzer_3.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50/160727_172604/0000/ExoDiPhotonAnalyzer_4.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50/160727_172604/0000/ExoDiPhotonAnalyzer_5.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50/160727_172604/0000/ExoDiPhotonAnalyzer_6.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50/160727_172604/0000/ExoDiPhotonAnalyzer_7.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50/160727_172604/0000/ExoDiPhotonAnalyzer_8.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-200To500_Pt-50_13TeV-sherpa/crab_GGJets_M-200To500_Pt-50/160727_172604/0000/ExoDiPhotonAnalyzer_9.root",0);
  }
  else if ( ms.EqualTo("GGJets") && massBin.EqualTo("500To1000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-500To1000_Pt-50_13TeV-sherpa/crab_GGJets_M-500To1000_Pt-50/160727_044925/0000/ExoDiPhotonAnalyzer_1.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-500To1000_Pt-50_13TeV-sherpa/crab_GGJets_M-500To1000_Pt-50/160727_044925/0000/ExoDiPhotonAnalyzer_10.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-500To1000_Pt-50_13TeV-sherpa/crab_GGJets_M-500To1000_Pt-50/160727_044925/0000/ExoDiPhotonAnalyzer_11.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-500To1000_Pt-50_13TeV-sherpa/crab_GGJets_M-500To1000_Pt-50/160727_044925/0000/ExoDiPhotonAnalyzer_2.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-500To1000_Pt-50_13TeV-sherpa/crab_GGJets_M-500To1000_Pt-50/160727_044925/0000/ExoDiPhotonAnalyzer_3.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-500To1000_Pt-50_13TeV-sherpa/crab_GGJets_M-500To1000_Pt-50/160727_044925/0000/ExoDiPhotonAnalyzer_4.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-500To1000_Pt-50_13TeV-sherpa/crab_GGJets_M-500To1000_Pt-50/160727_044925/0000/ExoDiPhotonAnalyzer_5.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-500To1000_Pt-50_13TeV-sherpa/crab_GGJets_M-500To1000_Pt-50/160727_044925/0000/ExoDiPhotonAnalyzer_6.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-500To1000_Pt-50_13TeV-sherpa/crab_GGJets_M-500To1000_Pt-50/160727_044925/0000/ExoDiPhotonAnalyzer_7.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-500To1000_Pt-50_13TeV-sherpa/crab_GGJets_M-500To1000_Pt-50/160727_044925/0000/ExoDiPhotonAnalyzer_8.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-500To1000_Pt-50_13TeV-sherpa/crab_GGJets_M-500To1000_Pt-50/160727_044925/0000/ExoDiPhotonAnalyzer_9.root",0);
  }
  else if ( ms.EqualTo("GGJets") && massBin.EqualTo("1000To2000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-1000To2000_Pt-50_13TeV-sherpa/crab_GGJets_M-1000To2000_Pt-50/160727_044936/0000/ExoDiPhotonAnalyzer_1.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-1000To2000_Pt-50_13TeV-sherpa/crab_GGJets_M-1000To2000_Pt-50/160727_044936/0000/ExoDiPhotonAnalyzer_2.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-1000To2000_Pt-50_13TeV-sherpa/crab_GGJets_M-1000To2000_Pt-50/160727_044936/0000/ExoDiPhotonAnalyzer_3.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-1000To2000_Pt-50_13TeV-sherpa/crab_GGJets_M-1000To2000_Pt-50/160727_044936/0000/ExoDiPhotonAnalyzer_4.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-1000To2000_Pt-50_13TeV-sherpa/crab_GGJets_M-1000To2000_Pt-50/160727_044936/0000/ExoDiPhotonAnalyzer_5.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-1000To2000_Pt-50_13TeV-sherpa/crab_GGJets_M-1000To2000_Pt-50/160727_044936/0000/ExoDiPhotonAnalyzer_6.root",0);
  }
  else if ( ms.EqualTo("GGJets") && massBin.EqualTo("2000To4000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-2000To4000_Pt-50_13TeV-sherpa/crab_GGJets_M-2000To4000_Pt-50/160727_044949/0000/ExoDiPhotonAnalyzer_1.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-2000To4000_Pt-50_13TeV-sherpa/crab_GGJets_M-2000To4000_Pt-50/160727_044949/0000/ExoDiPhotonAnalyzer_2.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-2000To4000_Pt-50_13TeV-sherpa/crab_GGJets_M-2000To4000_Pt-50/160727_044949/0000/ExoDiPhotonAnalyzer_3.root",0);
  }
  else if ( ms.EqualTo("GGJets") && massBin.EqualTo("4000To6000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-4000To6000_Pt-50_13TeV-sherpa/crab_GGJets_M-4000To6000_Pt-50/160727_045000/0000/ExoDiPhotonAnalyzer_1.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-4000To6000_Pt-50_13TeV-sherpa/crab_GGJets_M-4000To6000_Pt-50/160727_045000/0000/ExoDiPhotonAnalyzer_2.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-4000To6000_Pt-50_13TeV-sherpa/crab_GGJets_M-4000To6000_Pt-50/160727_045000/0000/ExoDiPhotonAnalyzer_3.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-4000To6000_Pt-50_13TeV-sherpa/crab_GGJets_M-4000To6000_Pt-50/160727_045000/0000/ExoDiPhotonAnalyzer_4.root",0);
  }
  else if ( ms.EqualTo("GGJets") && massBin.EqualTo("6000To8000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-6000To8000_Pt-50_13TeV-sherpa/crab_GGJets_M-6000To8000_Pt-50/160727_045014/0000/ExoDiPhotonAnalyzer_1.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-6000To8000_Pt-50_13TeV-sherpa/crab_GGJets_M-6000To8000_Pt-50/160727_045014/0000/ExoDiPhotonAnalyzer_2.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-6000To8000_Pt-50_13TeV-sherpa/crab_GGJets_M-6000To8000_Pt-50/160727_045014/0000/ExoDiPhotonAnalyzer_3.root",0);
  }
  else if ( ms.EqualTo("GGJets") && massBin.EqualTo("8000To13000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-8000To13000_Pt-50_13TeV-sherpa/crab_GGJets_M-8000To13000_Pt-50/160727_045026/0000/ExoDiPhotonAnalyzer_1.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/GGJets_M-8000To13000_Pt-50_13TeV-sherpa/crab_GGJets_M-8000To13000_Pt-50/160727_045026/0000/ExoDiPhotonAnalyzer_2.root",0);
  }


  chain->ls();
  cout << "Total number of entries: " << chain->GetEntries() << endl; 

  // create instance of class, passing our chain
  fTree t(chain);

  // loop over all entries of our tree
  t.Loop(outfilename, applyEventWeights);

  // stop stopwatch
  sw.Stop();

  // convert total time to minutes
  std::cout << "RealTime : " << sw.RealTime() / 60.0 << " minutes" << std::endl;
  std::cout << "CPUTime  : " << sw.CpuTime()  / 60.0 << " minutes" << std::endl;
}