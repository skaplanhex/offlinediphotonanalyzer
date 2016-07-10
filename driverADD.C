#include "fTree.C"

void driverADD(TString ms, TString massBin, TString outfilename) {
  // use stopwatch to time
  TStopwatch sw;
  sw.Start();

  // create tchain of all files to loop over
  TChain *chain = new TChain("diphotonAnalyzer/fTree");

  cout << "Running over Ms=" << ms << ", massBin=" << massBin << ", and writing out to " << outfilename << endl;  

  if ( ms.EqualTo("4000") && massBin.EqualTo("200To500") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/ADDGravToGG_MS-4000_NED-4_KK-1_M-200To500_13TeV-sherpa/crab_ADDGravToGG_MS-4000_NED-4_KK-1_M-200To500_13TeV-sherpa/160628_214815/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("4000") && massBin.EqualTo("500To1000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/ADDGravToGG_MS-4000_NED-4_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-4000_NED-4_KK-1_M-500To1000_13TeV-sherpa/160630_030436/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("4000") && massBin.EqualTo("1000To2000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/ADDGravToGG_MS-4000_NED-4_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-4000_NED-4_KK-1_M-1000To2000_13TeV-sherpa/160628_214755/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("4000") && massBin.EqualTo("2000To4000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/ADDGravToGG_MS-4000_NED-4_KK-1_M-2000To4000_13TeV-sherpa/crab_ADDGravToGG_MS-4000_NED-4_KK-1_M-2000To4000_13TeV-sherpa/160628_214805/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("5000") && massBin.EqualTo("200To500") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/ADDGravToGG_MS-5000_NED-4_KK-1_M-200To500_13TeV-sherpa/crab_ADDGravToGG_MS-5000_NED-4_KK-1_M-200To500_13TeV-sherpa/160628_214945/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("5000") && massBin.EqualTo("500To1000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/ADDGravToGG_MS-5000_NED-4_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-5000_NED-4_KK-1_M-500To1000_13TeV-sherpa/160628_215005/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("5000") && massBin.EqualTo("1000To2000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/ADDGravToGG_MS-5000_NED-4_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-5000_NED-4_KK-1_M-1000To2000_13TeV-sherpa/160628_214925/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("5000") && massBin.EqualTo("2000To3000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/ADDGravToGG_MS-5000_NED-4_KK-1_M-2000To3000_13TeV-sherpa/crab_ADDGravToGG_MS-5000_NED-4_KK-1_M-2000To3000_13TeV-sherpa/160630_030456/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("5000") && massBin.EqualTo("3000To5000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/ADDGravToGG_MS-5000_NED-4_KK-1_M-3000To5000_13TeV-sherpa/crab_ADDGravToGG_MS-5000_NED-4_KK-1_M-3000To5000_13TeV-sherpa/160628_214955/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("3500") && massBin.EqualTo("200To500") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/ADDGravToGG_MS-3500_NED-4_KK-1_M-200To500_13TeV-sherpa/crab_ADDGravToGG_MS-3500_NED-4_KK-1_M-200To500_13TeV-sherpa/160628_214735/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("3500") && massBin.EqualTo("500To1000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/ADDGravToGG_MS-3500_NED-4_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-3500_NED-4_KK-1_M-500To1000_13TeV-sherpa/160628_214745/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("3500") && massBin.EqualTo("2000To3500") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/ADDGravToGG_MS-3500_NED-4_KK-1_M-2000To3500_13TeV-sherpa/crab_ADDGravToGG_MS-3500_NED-4_KK-1_M-2000To3500_13TeV-sherpa/160628_214725/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("6000") && massBin.EqualTo("200To500") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/ADDGravToGG_MS-6000_NED-4_KK-1_M-200To500_13TeV-sherpa/crab_ADDGravToGG_MS-6000_NED-4_KK-1_M-200To500_13TeV-sherpa/160630_030535/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("6000") && massBin.EqualTo("500To1000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/ADDGravToGG_MS-6000_NED-4_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-6000_NED-4_KK-1_M-500To1000_13TeV-sherpa/160628_215143/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("6000") && massBin.EqualTo("1000To2000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/ADDGravToGG_MS-6000_NED-4_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-6000_NED-4_KK-1_M-1000To2000_13TeV-sherpa/160630_030515/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("6000") && massBin.EqualTo("2000To4000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/ADDGravToGG_MS-6000_NED-4_KK-1_M-2000To4000_13TeV-sherpa/crab_ADDGravToGG_MS-6000_NED-4_KK-1_M-2000To4000_13TeV-sherpa/160630_030525/0000/ExoDiPhotonAnalyzer_1.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/ADDGravToGG_MS-6000_NED-4_KK-1_M-2000To4000_13TeV-sherpa/crab_ADDGravToGG_MS-6000_NED-4_KK-1_M-2000To4000_13TeV-sherpa/160630_030525/0000/ExoDiPhotonAnalyzer_2.root",0);
  }
  else if ( ms.EqualTo("6000") && massBin.EqualTo("4000To6000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/ADDGravToGG_MS-6000_NED-4_KK-1_M-4000To6000_13TeV-sherpa/crab_ADDGravToGG_MS-6000_NED-4_KK-1_M-4000To6000_13TeV-sherpa/160628_215134/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("4500") && massBin.EqualTo("200To500") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/ADDGravToGG_MS-4500_NED-4_KK-1_M-200To500_13TeV-sherpa/crab_ADDGravToGG_MS-4500_NED-4_KK-1_M-200To500_13TeV-sherpa/160630_030446/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("4500") && massBin.EqualTo("500To1000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/ADDGravToGG_MS-4500_NED-4_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-4500_NED-4_KK-1_M-500To1000_13TeV-sherpa/160628_214915/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("4500") && massBin.EqualTo("1000To2000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/ADDGravToGG_MS-4500_NED-4_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-4500_NED-4_KK-1_M-1000To2000_13TeV-sherpa/160628_214834/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("4500") && massBin.EqualTo("2000To3000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/ADDGravToGG_MS-4500_NED-4_KK-1_M-2000To3000_13TeV-sherpa/crab_ADDGravToGG_MS-4500_NED-4_KK-1_M-2000To3000_13TeV-sherpa/160628_214845/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("4500") && massBin.EqualTo("3000To4500") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/ADDGravToGG_MS-4500_NED-4_KK-1_M-3000To4500_13TeV-sherpa/crab_ADDGravToGG_MS-4500_NED-4_KK-1_M-3000To4500_13TeV-sherpa/160628_214905/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("3000") && massBin.EqualTo("200To500") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/ADDGravToGG_MS-3000_NED-4_KK-1_M-200To500_13TeV-sherpa/crab_ADDGravToGG_MS-3000_NED-4_KK-1_M-200To500_13TeV-sherpa/160628_214706/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("3000") && massBin.EqualTo("500To1000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/ADDGravToGG_MS-3000_NED-4_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-3000_NED-4_KK-1_M-500To1000_13TeV-sherpa/160630_030426/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("3000") && massBin.EqualTo("1000To2000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/ADDGravToGG_MS-3000_NED-4_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-3000_NED-4_KK-1_M-1000To2000_13TeV-sherpa/160628_214645/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("3000") && massBin.EqualTo("2000To3000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/ADDGravToGG_MS-3000_NED-4_KK-1_M-2000To3000_13TeV-sherpa/crab_ADDGravToGG_MS-3000_NED-4_KK-1_M-2000To3000_13TeV-sherpa/160628_214656/0000/ExoDiPhotonAnalyzer_1.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/ADDGravToGG_MS-3000_NED-4_KK-1_M-2000To3000_13TeV-sherpa/crab_ADDGravToGG_MS-3000_NED-4_KK-1_M-2000To3000_13TeV-sherpa/160628_214656/0000/ExoDiPhotonAnalyzer_2.root",0);
  }
  else if ( ms.EqualTo("5500") && massBin.EqualTo("200To500") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/ADDGravToGG_MS-5500_NED-4_KK-1_M-200To500_13TeV-sherpa/crab_ADDGravToGG_MS-5500_NED-4_KK-1_M-200To500_13TeV-sherpa/160630_030506/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("5500") && massBin.EqualTo("500To1000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/ADDGravToGG_MS-5500_NED-4_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-5500_NED-4_KK-1_M-500To1000_13TeV-sherpa/160628_215056/0000/ExoDiPhotonAnalyzer_1.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/ADDGravToGG_MS-5500_NED-4_KK-1_M-500To1000_13TeV-sherpa/crab_ADDGravToGG_MS-5500_NED-4_KK-1_M-500To1000_13TeV-sherpa/160628_215056/0000/ExoDiPhotonAnalyzer_2.root",0);
  }
  else if ( ms.EqualTo("5500") && massBin.EqualTo("1000To2000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/ADDGravToGG_MS-5500_NED-4_KK-1_M-1000To2000_13TeV-sherpa/crab_ADDGravToGG_MS-5500_NED-4_KK-1_M-1000To2000_13TeV-sherpa/160628_215016/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("5500") && massBin.EqualTo("2000To4000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/ADDGravToGG_MS-5500_NED-4_KK-1_M-2000To4000_13TeV-sherpa/crab_ADDGravToGG_MS-5500_NED-4_KK-1_M-2000To4000_13TeV-sherpa/160628_215026/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("5500") && massBin.EqualTo("4000To5500") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/ADDGravToGG_MS-5500_NED-4_KK-1_M-4000To5500_13TeV-sherpa/crab_ADDGravToGG_MS-5500_NED-4_KK-1_M-4000To5500_13TeV-sherpa/160628_215046/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("ADDbkg") && massBin.EqualTo("200To500") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/GG_M-200To500_Pt-70_13TeV-sherpa/crab_GG_M-200To500_Pt-70_13TeV-sherpa/160705_185759/0000/ExoDiPhotonAnalyzer_1.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/GG_M-200To500_Pt-70_13TeV-sherpa/crab_GG_M-200To500_Pt-70_13TeV-sherpa/160705_185759/0000/ExoDiPhotonAnalyzer_2.root",0);
  }
  else if ( ms.EqualTo("ADDbkg") && massBin.EqualTo("500To1000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/GG_M-500To1000_Pt-70_13TeV-sherpa/crab_GG_M-500To1000_Pt-70_13TeV-sherpa/160705_185820/0000/ExoDiPhotonAnalyzer_1.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/GG_M-500To1000_Pt-70_13TeV-sherpa/crab_GG_M-500To1000_Pt-70_13TeV-sherpa/160705_185820/0000/ExoDiPhotonAnalyzer_2.root",0);
  }
  else if ( ms.EqualTo("ADDbkg") && massBin.EqualTo("1000To2000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/GG_M-1000To2000_Pt-70_13TeV-sherpa/crab_GG_M-1000To2000_Pt-70_13TeV-sherpa/160705_185736/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("ADDbkg") && massBin.EqualTo("2000To4000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/GG_M-2000To4000_Pt-70_13TeV-sherpa/crab_GG_M-2000To4000_Pt-70_13TeV-sherpa/160705_185747/0000/ExoDiPhotonAnalyzer_1.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/GG_M-2000To4000_Pt-70_13TeV-sherpa/crab_GG_M-2000To4000_Pt-70_13TeV-sherpa/160705_185747/0000/ExoDiPhotonAnalyzer_2.root",0);
  }
  else if ( ms.EqualTo("ADDbkg") && massBin.EqualTo("4000To8000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/GG_M-4000To8000_Pt-70_13TeV-sherpa/crab_GG_M-4000To8000_Pt-70_13TeV-sherpa/160705_185810/0000/ExoDiPhotonAnalyzer_1.root",0);
  }
  else if ( ms.EqualTo("ADDbkg") && massBin.EqualTo("8000To13000") ){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ADD/GG_M-8000To13000_Pt-70_13TeV-sherpa/crab_GG_M-8000To13000_Pt-70_13TeV-sherpa/160705_185830/0000/ExoDiPhotonAnalyzer_1.root",0);
  }


  chain->ls();
  cout << "Total number of entries: " << chain->GetEntries() << endl; 

  // create instance of class, passing our chain
  fTree t(chain);

  // loop over all entries of our tree
  t.Loop(outfilename);

  // stop stopwatch
  sw.Stop();

  // convert total time to minutes
  std::cout << "RealTime : " << sw.RealTime() / 60.0 << " minutes" << std::endl;
  std::cout << "CPUTime  : " << sw.CpuTime()  / 60.0 << " minutes" << std::endl;
}