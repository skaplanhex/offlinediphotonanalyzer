#include "fTree.C"

void driverData(int jobNum) {
  // use stopwatch to time
  TStopwatch sw;
  sw.Start();

  // create tchain of all files to loop over
  TChain *chain = new TChain("diphoton/fTree");
  // added ",0" to print correct number of entries, not entries=1234567890


  // for thesis
  // if (jobNum == 0){
  //   chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_VertexUnique/DoubleEG/crab_DoubleEG__Run2016B-03Feb2017_ver2-v2__MINIAOD/170818_022544/0000/*.root",0);
  // }
  // else if (jobNum == 1){
  //   chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_VertexUnique/DoubleEG/crab_DoubleEG__Run2016C-03Feb2017-v1__MINIAOD/170818_022719/0000/*.root",0);
  // }
  // else if (jobNum == 2){
  //   chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_VertexUnique/DoubleEG/crab_DoubleEG__Run2016D-03Feb2017-v1__MINIAOD/170818_022900/0000/*.root",0);
  // }
  // else if (jobNum == 3){
  //   chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_VertexUnique/DoubleEG/crab_DoubleEG__Run2016E-03Feb2017-v1__MINIAOD/170818_023043/0000/*.root",0);
  // }
  // else if (jobNum == 4){
  //   chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_VertexUnique/DoubleEG/crab_DoubleEG__Run2016F-03Feb2017-v1__MINIAOD/170818_023214/0000/*.root",0);
  // }
  // else if (jobNum == 5){
  //   chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_VertexUnique/DoubleEG/crab_DoubleEG__Run2016G-03Feb2017-v1__MINIAOD/170818_023353/0000/*.root",0);
  // }
  // else if (jobNum == 6){
  //   chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_VertexUnique/DoubleEG/crab_DoubleEG__Run2016H-03Feb2017_ver2-v1__MINIAOD/170818_023535/0000/*.root",0);
  //   chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_VertexUnique/DoubleEG/crab_DoubleEG__Run2016H-03Feb2017_ver3-v1__MINIAOD/170818_023710/0000/*.root",0);
  // }
  // else if (jobNum == 7){
  //   cout << "not using 2015 data anymore!" << endl;
  // }

  // for resonant sync
  // if (jobNum == 0){
  //   chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_FinalCheck/DoubleEG/crab_DoubleEG__Run2016B-03Feb2017_ver2-v2__MINIAOD/171029_235227/0000/*.root",0);
  // }
  // else if (jobNum == 1){
  //   chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_FinalCheck/DoubleEG/crab_DoubleEG__Run2016C-03Feb2017-v1__MINIAOD/171029_235641/0000/*.root",0);
  // }
  // else if (jobNum == 2){
  //   chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_FinalCheck/DoubleEG/crab_DoubleEG__Run2016D-03Feb2017-v1__MINIAOD/171030_000054/0000/*.root",0);
  // }
  // else if (jobNum == 3){
  //   chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_FinalCheck/DoubleEG/crab_DoubleEG__Run2016E-03Feb2017-v1__MINIAOD/171030_000513/0000/*.root",0);
  // }
  // else if (jobNum == 4){
  //   chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_FinalCheck/DoubleEG/crab_DoubleEG__Run2016F-03Feb2017-v1__MINIAOD/171030_000935/0000/*.root",0);
  // }
  // else if (jobNum == 5){
  //   chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_FinalCheck/DoubleEG/crab_DoubleEG__Run2016G-03Feb2017-v1__MINIAOD/171030_001348/0000/*.root",0);
  // }
  // else if (jobNum == 6){
  //   chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_FinalCheck/DoubleEG/crab_DoubleEG__Run2016H-03Feb2017_ver2-v1__MINIAOD/171030_001534/0000/*.root",0);
  //   chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_FinalCheck/DoubleEG/crab_DoubleEG__Run2016H-03Feb2017_ver3-v1__MINIAOD/171030_001957/0000/*.root",0);
  // }
  // else if (jobNum == 7){
  //   cout << "not using 2015 data anymore!" << endl;
  // }

  // for resonant sync with bug fix
  // if (jobNum == 0){
  //   chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_FinalCheck2/DoubleEG/crab_DoubleEG__Run2016B-03Feb2017_ver2-v2__MINIAOD/171113_183327/0000/*.root",0);
  // }
  // else if (jobNum == 1){
  //   chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_FinalCheck2/DoubleEG/crab_DoubleEG__Run2016C-03Feb2017-v1__MINIAOD/171113_183511/0000/*.root",0);
  // }
  // else if (jobNum == 2){
  //   chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_FinalCheck2/DoubleEG/crab_DoubleEG__Run2016D-03Feb2017-v1__MINIAOD/171113_183706/0000/*.root",0);
  // }
  // else if (jobNum == 3){
  //   chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_FinalCheck2/DoubleEG/crab_DoubleEG__Run2016E-03Feb2017-v1__MINIAOD/171113_183849/0000/*.root",0);
  // }
  // else if (jobNum == 4){
  //   chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_FinalCheck2/DoubleEG/crab_DoubleEG__Run2016F-03Feb2017-v1__MINIAOD/171113_184118/0000/*.root",0);
  // }
  // else if (jobNum == 5){
  //   chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_FinalCheck2/DoubleEG/crab_DoubleEG__Run2016G-03Feb2017-v1__MINIAOD/171113_184322/0000/*.root",0);
  // }
  // else if (jobNum == 6){
  //   chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_FinalCheck2/DoubleEG/crab_DoubleEG__Run2016H-03Feb2017_ver2-v1__MINIAOD/171113_184524/0000/*.root",0);
  //   chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_FinalCheck2/DoubleEG/crab_DoubleEG__Run2016H-03Feb2017_ver3-v1__MINIAOD/171113_184720/0000/*.root",0);
  // }
  // else if (jobNum == 7){
  //   cout << "not using 2015 data anymore!" << endl;
  // }

  // // for resonant sync with more bug fixes and Iso_ch sync
  // if (jobNum == 0){
  //   chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_elecvetofix/DoubleEG/crab_DoubleEG__Run2016B-03Feb2017_ver2-v2__MINIAOD/171201_041718/0000/*.root",0);
  // }
  // else if (jobNum == 1){
  //   chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_elecvetofix/DoubleEG/crab_DoubleEG__Run2016C-03Feb2017-v1__MINIAOD/171201_041911/0000/*.root",0);
  // }
  // else if (jobNum == 2){
  //   chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_elecvetofix/DoubleEG/crab_DoubleEG__Run2016D-03Feb2017-v1__MINIAOD/171201_042119/0000/*.root",0);
  // }
  // else if (jobNum == 3){
  //   chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_elecvetofix/DoubleEG/crab_DoubleEG__Run2016E-03Feb2017-v1__MINIAOD/171201_042256/0000/*.root",0);
  // }
  // else if (jobNum == 4){
  //   chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_elecvetofix/DoubleEG/crab_DoubleEG__Run2016F-03Feb2017-v1__MINIAOD/171201_042450/0000/*.root",0);
  // }
  // else if (jobNum == 5){
  //   chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_elecvetofix/DoubleEG/crab_DoubleEG__Run2016G-03Feb2017-v1__MINIAOD/171201_042656/0000/*.root",0);
  // }
  // else if (jobNum == 6){
  //   chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_elecvetofix/DoubleEG/crab_DoubleEG__Run2016H-03Feb2017_ver2-v1__MINIAOD/171201_042833/0000/*.root",0);
  //   chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_elecvetofix/DoubleEG/crab_DoubleEG__Run2016H-03Feb2017_ver3-v1__MINIAOD/171201_043004/0000/*.root",0);
  // }
  // else if (jobNum == 7){
  //   cout << "not using 2015 data anymore!" << endl;
  // }

  // 2ND TRY for resonant sync with more bug fixes and Iso_ch sync
  if (jobNum == 0){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_elecvetofix_removeOverlappingCandsTrue/DoubleEG/crab_DoubleEG__Run2016B-03Feb2017_ver2-v2__MINIAOD/171206_222515/0000/*.root",0);
  }
  else if (jobNum == 1){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_elecvetofix_removeOverlappingCandsTrue/DoubleEG/crab_DoubleEG__Run2016C-03Feb2017-v1__MINIAOD/171206_222659/0000/*.root",0);
  }
  else if (jobNum == 2){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_elecvetofix_removeOverlappingCandsTrue/DoubleEG/crab_DoubleEG__Run2016D-03Feb2017-v1__MINIAOD/171206_222845/0000/*.root",0);
  }
  else if (jobNum == 3){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_elecvetofix_removeOverlappingCandsTrue/DoubleEG/crab_DoubleEG__Run2016E-03Feb2017-v1__MINIAOD/171206_223025/0000/*.root",0);
  }
  else if (jobNum == 4){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_elecvetofix_removeOverlappingCandsTrue/DoubleEG/crab_DoubleEG__Run2016F-03Feb2017-v1__MINIAOD/171206_223244/0000/*.root",0);
  }
  else if (jobNum == 5){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_elecvetofix_removeOverlappingCandsTrue/DoubleEG/crab_DoubleEG__Run2016G-03Feb2017-v1__MINIAOD/171206_223428/0000/*.root",0);
  }
  else if (jobNum == 6){
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_elecvetofix_removeOverlappingCandsTrue/DoubleEG/crab_DoubleEG__Run2016H-03Feb2017_ver2-v1__MINIAOD/171206_223631/0000/*.root",0);
    chain->Add("root://cmseos.fnal.gov//store/user/skaplan/noreplica/SimoneCheck_elecvetofix_removeOverlappingCandsTrue/DoubleEG/crab_DoubleEG__Run2016H-03Feb2017_ver3-v1__MINIAOD/171206_223826/0000/*.root",0);
  }
  else if (jobNum == 7){
    cout << "not using 2015 data anymore!" << endl;
  }


  chain->ls();
  cout << "Total number of entries: " << chain->GetEntries() << endl; 

  // create instance of class, passing our chain
  fTree t(chain);

  // loop over all entries of our tree
  t.Loop(TString::Format("dataplots_%i.root",jobNum),"DATA");

  // stop stopwatch
  sw.Stop();

  // convert total time to minutes
  std::cout << "RealTime : " << sw.RealTime() / 60.0 << " minutes" << std::endl;
  std::cout << "CPUTime  : " << sw.CpuTime()  / 60.0 << " minutes" << std::endl;
}
