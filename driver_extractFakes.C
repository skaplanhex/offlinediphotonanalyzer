#include "extractFakeContributions.C"

void driver_extractFakes(int jobNum) {
  // use stopwatch to time
  TStopwatch sw;
  sw.Start();

  // create tchain of all files to loop over
  TChain *chain = new TChain("diphoton/fTree");
  TString mode = "2016";
  
  if (jobNum == 0){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_VertexUnique/DoubleEG/crab_DoubleEG__Run2016B-03Feb2017_ver2-v2__MINIAOD/170818_022544/0000/*.root",0);
  }
  else if (jobNum == 1){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_VertexUnique/DoubleEG/crab_DoubleEG__Run2016C-03Feb2017-v1__MINIAOD/170818_022719/0000/*.root",0);
  }
  else if (jobNum == 2){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_VertexUnique/DoubleEG/crab_DoubleEG__Run2016D-03Feb2017-v1__MINIAOD/170818_022900/0000/*.root",0);
  }
  else if (jobNum == 3){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_VertexUnique/DoubleEG/crab_DoubleEG__Run2016E-03Feb2017-v1__MINIAOD/170818_023043/0000/*.root",0);
  }
  else if (jobNum == 4){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_VertexUnique/DoubleEG/crab_DoubleEG__Run2016F-03Feb2017-v1__MINIAOD/170818_023214/0000/*.root",0);
  }
  else if (jobNum == 5){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_VertexUnique/DoubleEG/crab_DoubleEG__Run2016G-03Feb2017-v1__MINIAOD/170818_023353/0000/*.root",0);
  }
  else if (jobNum == 6){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_VertexUnique/DoubleEG/crab_DoubleEG__Run2016H-03Feb2017_ver2-v1__MINIAOD/170818_023535/0000/*.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_VertexUnique/DoubleEG/crab_DoubleEG__Run2016H-03Feb2017_ver3-v1__MINIAOD/170818_023710/0000/*.root",0);
  }
  // else if (jobNum == 7){
  //   chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/FINALNTUPLES/DoubleEG/crab_DoubleEG__Run2015C_25ns-16Dec2015-v1__MINIAOD/170505_202139/0000/*.root",0);
  //   chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/FINALNTUPLES/DoubleEG/crab_DoubleEG__Run2015D-16Dec2015-v2__MINIAOD/170505_202213/0000/*.root",0);
  //   mode.ReplaceAll("2016","2015");
  // }
  chain->ls();
  cout << "Total number of entries: " << chain->GetEntries() << endl;
  cout << "Mode: " << mode.Data() << endl;

  // create instance of class, passing our chain
  extractFakeContributions t(chain);

  // loop over all entries of our tree
  TString outname = TString::Format("fakeplots_%i.root",jobNum);
  t.Loop(outname,mode);

  // stop stopwatch
  sw.Stop();

  // convert total time to minutes
  std::cout << "RealTime : " << sw.RealTime() / 60.0 << " minutes" << std::endl;
  std::cout << "CPUTime  : " << sw.CpuTime()  / 60.0 << " minutes" << std::endl;
}