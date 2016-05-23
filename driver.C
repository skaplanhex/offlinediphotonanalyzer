#include "fTree.C"

void driver() {
  // use stopwatch to time
  TStopwatch sw;
  sw.Start();

  // create tchain of all files to loop over
  TChain *chain = new TChain("diphotonAnalyzer/fTree");
  // wildcard not supported when using xrootd
  // added ",0" to print correct number of entries, not entries=1234567890
  // chain->Add("root://cmsxrootd.fnal.gov//store/user/skaplan/noreplica/FakeRateMerged/JetHT_Run2015C_25ns-16Dec2015-v1_MINIAOD/mergedFakeRateNtuple.root",0);
  // chain->Add("root://cmsxrootd.fnal.gov//store/user/skaplan/noreplica/FakeRateMerged/JetHT_Run2015D-16Dec2015-v1_MINIAOD/mergedFakeRateNtuple.root",0);
  // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/CutTable2/Merged/Run2015D-v3.root",0);
  // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/CutTable2/Merged/Run2015D-v4.root",0);
  // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/Merged/DoubleEG_Run2015D-16Dec2015-v2_MINIAOD/merged.root",0);
  chain->Add("root://cmsxrootd.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/ConversionInfo/Merged/DoubleEG_Run2015D-16Dec2015-v2_MINIAOD/merged.root",0);
  chain->ls();
  cout << "Total number of entries: " << chain->GetEntries() << endl; 

  // create instance of class, passing our chain
  fTree t(chain);

  // loop over all entries of our tree
  t.Loop();

  // stop stopwatch
  sw.Stop();

  // convert total time to minutes
  std::cout << "RealTime : " << sw.RealTime() / 60.0 << " minutes" << std::endl;
  std::cout << "CPUTime  : " << sw.CpuTime()  / 60.0 << " minutes" << std::endl;
}