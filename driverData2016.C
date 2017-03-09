#include "fTree2016.C"

void driverData2016(int jobNum) {
  // use stopwatch to time
  TStopwatch sw;
  sw.Start();

  // create tchain of all files to loop over
  TChain *chain = new TChain("diphoton/fTree");
  // wildcard not supported when using xrootd
  // added ",0" to print correct number of entries, not entries=1234567890
  // chain->Add("root://cmsxrootd.fnal.gov//store/user/skaplan/noreplica/FakeRateMerged/JetHT_Run2015C_25ns-16Dec2015-v1_MINIAOD/mergedFakeRateNtuple.root",0);
  // chain->Add("root://cmsxrootd.fnal.gov//store/user/skaplan/noreplica/FakeRateMerged/JetHT_Run2015D-16Dec2015-v1_MINIAOD/mergedFakeRateNtuple.root",0);
  // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/CutTable2/Merged/Run2015D-v3.root",0);
  // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/CutTable2/Merged/Run2015D-v4.root",0);
  // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/Merged/DoubleEG_Run2015D-16Dec2015-v2_MINIAOD/merged.root",0);
  // chain->Add("root://cmsxrootd.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/WithConversionInfo/DoubleEG_Run2015D-16Dec2015-v2_MINIAOD/DoubleEG_Run2015D-16Dec2015-v2_MINIAOD.root",0);
  // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/BrandonSteveMerged/DoubleEG_Run2015D.root",0);
  // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/BrandonSteveMerged/DoubleEG_Run2016B_V2.root",0);
  // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/750GeVResonanceNtuples/BrandonSteveMerged/GGJets_M-60To200_Pt-50_13TeV-sherpa.root",0);
  // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/Data2015/DoubleEG_Run2015C.root",0);
  // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/Data2015/DoubleEG_Run2015D.root",0);
  // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/Data2016/DoubleEG_Run2016BV2.root",0);
  // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/Data2016/DoubleEG_Run2016CV2.root",0);
  // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ExoDiPhotonNtuples/Data2016/DoubleEG_Run2016DV2.root",0);
  // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/NewCodeNtuples/DoubleEG_Run2015C.root",0);
  // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/NewCodeNtuples/DoubleEG_Run2015D.root",0);
  if (jobNum == 0){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016B-03Feb2017_ver2-v2__MINIAOD/170224_200238/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016C-03Feb2017-v1__MINIAOD/170224_200300/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016D-03Feb2017-v1__MINIAOD/170224_200325/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016E-03Feb2017-v1__MINIAOD/170224_200351/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016F-03Feb2017-v1__MINIAOD/170224_200417/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016G-03Feb2017-v1__MINIAOD/170224_200448/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016H-03Feb2017_ver2-v1__MINIAOD/170224_200525/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016H-03Feb2017_ver3-v1__MINIAOD/170224_200549/0000/*.root",0);
  }
  else if (jobNum == 1){
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016B-03Feb2017_ver2-v2__MINIAOD/170224_200238/0000/*.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016C-03Feb2017-v1__MINIAOD/170224_200300/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016D-03Feb2017-v1__MINIAOD/170224_200325/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016E-03Feb2017-v1__MINIAOD/170224_200351/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016F-03Feb2017-v1__MINIAOD/170224_200417/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016G-03Feb2017-v1__MINIAOD/170224_200448/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016H-03Feb2017_ver2-v1__MINIAOD/170224_200525/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016H-03Feb2017_ver3-v1__MINIAOD/170224_200549/0000/*.root",0);
  }
  else if (jobNum == 2){
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016B-03Feb2017_ver2-v2__MINIAOD/170224_200238/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016C-03Feb2017-v1__MINIAOD/170224_200300/0000/*.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016D-03Feb2017-v1__MINIAOD/170224_200325/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016E-03Feb2017-v1__MINIAOD/170224_200351/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016F-03Feb2017-v1__MINIAOD/170224_200417/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016G-03Feb2017-v1__MINIAOD/170224_200448/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016H-03Feb2017_ver2-v1__MINIAOD/170224_200525/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016H-03Feb2017_ver3-v1__MINIAOD/170224_200549/0000/*.root",0);
  }
  else if (jobNum == 3){
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016B-03Feb2017_ver2-v2__MINIAOD/170224_200238/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016C-03Feb2017-v1__MINIAOD/170224_200300/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016D-03Feb2017-v1__MINIAOD/170224_200325/0000/*.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016E-03Feb2017-v1__MINIAOD/170224_200351/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016F-03Feb2017-v1__MINIAOD/170224_200417/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016G-03Feb2017-v1__MINIAOD/170224_200448/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016H-03Feb2017_ver2-v1__MINIAOD/170224_200525/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016H-03Feb2017_ver3-v1__MINIAOD/170224_200549/0000/*.root",0);
  }
  else if (jobNum == 4){
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016B-03Feb2017_ver2-v2__MINIAOD/170224_200238/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016C-03Feb2017-v1__MINIAOD/170224_200300/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016D-03Feb2017-v1__MINIAOD/170224_200325/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016E-03Feb2017-v1__MINIAOD/170224_200351/0000/*.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016F-03Feb2017-v1__MINIAOD/170224_200417/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016G-03Feb2017-v1__MINIAOD/170224_200448/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016H-03Feb2017_ver2-v1__MINIAOD/170224_200525/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016H-03Feb2017_ver3-v1__MINIAOD/170224_200549/0000/*.root",0);
  }
  else if (jobNum == 5){
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016B-03Feb2017_ver2-v2__MINIAOD/170224_200238/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016C-03Feb2017-v1__MINIAOD/170224_200300/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016D-03Feb2017-v1__MINIAOD/170224_200325/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016E-03Feb2017-v1__MINIAOD/170224_200351/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016F-03Feb2017-v1__MINIAOD/170224_200417/0000/*.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016G-03Feb2017-v1__MINIAOD/170224_200448/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016H-03Feb2017_ver2-v1__MINIAOD/170224_200525/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016H-03Feb2017_ver3-v1__MINIAOD/170224_200549/0000/*.root",0);
  }

  else if (jobNum == 6){
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016B-03Feb2017_ver2-v2__MINIAOD/170224_200238/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016C-03Feb2017-v1__MINIAOD/170224_200300/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016D-03Feb2017-v1__MINIAOD/170224_200325/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016E-03Feb2017-v1__MINIAOD/170224_200351/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016F-03Feb2017-v1__MINIAOD/170224_200417/0000/*.root",0);
    // chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016G-03Feb2017-v1__MINIAOD/170224_200448/0000/*.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016H-03Feb2017_ver2-v1__MINIAOD/170224_200525/0000/*.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/ReMINIAOD/DoubleEG/crab_DoubleEG__Run2016H-03Feb2017_ver3-v1__MINIAOD/170224_200549/0000/*.root",0);
  }
  chain->ls();
  cout << "Total number of entries: " << chain->GetEntries() << endl; 

  // create instance of class, passing our chain
  fTree2016 t(chain);

  // loop over all entries of our tree
  t.Loop(TString::Format("data2016plots_%i.root",jobNum),false);

  // stop stopwatch
  sw.Stop();

  // convert total time to minutes
  std::cout << "RealTime : " << sw.RealTime() / 60.0 << " minutes" << std::endl;
  std::cout << "CPUTime  : " << sw.CpuTime()  / 60.0 << " minutes" << std::endl;
}
