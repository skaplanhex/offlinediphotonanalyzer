#! /bin/bash

export SCRAM_ARCH=slc6_amd64_gcc493
source /cvmfs/cms.cern.ch/cmsset_default.sh

cd /uscms_data/d3/skaplan/diphotons/offlineanalysis/CMSSW_7_6_4/src
eval `scramv1 runtime -sh`
cd ${_CONDOR_SCRATCH_DIR}

if [ $1 -eq 0 ]
then
    root -l -q -b 'driverMC.C("4000_GRW","200To500","ADDPlots_Ms4000_Mgg200To500_GRW.root",true)'
elif [ $1 -eq 1 ]
then
    root -l -q -b 'driverMC.C("4000_GRW","500To1000","ADDPlots_Ms4000_Mgg500To1000_GRW.root",true)'
elif [ $1 -eq 2 ]
then
    root -l -q -b 'driverMC.C("4000_GRW","1000To2000","ADDPlots_Ms4000_Mgg1000To2000_GRW.root",true)'
elif [ $1 -eq 3 ]
then
    root -l -q -b 'driverMC.C("4000_GRW","2000To4000","ADDPlots_Ms4000_Mgg2000To4000_GRW.root",true)'
elif [ $1 -eq 4 ]
then
    root -l -q -b 'driverMC.C("4000_HLZ","500To1000","ADDPlots_Ms4000_Mgg500To1000_HLZ.root",true)'
elif [ $1 -eq 5 ]
then
    root -l -q -b 'driverMC.C("4000_HLZ","1000To2000","ADDPlots_Ms4000_Mgg1000To2000_HLZ.root",true)'
elif [ $1 -eq 6 ]
then
    root -l -q -b 'driverMC.C("4000_HLZ","2000To4000","ADDPlots_Ms4000_Mgg2000To4000_HLZ.root",true)'
elif [ $1 -eq 7 ]
then
    root -l -q -b 'driverMC.C("4000_Hewett","500To1000","ADDPlots_Ms4000_Mgg500To1000_Hewett.root",true)'
elif [ $1 -eq 8 ]
then
    root -l -q -b 'driverMC.C("4000_Hewett","1000To2000","ADDPlots_Ms4000_Mgg1000To2000_Hewett.root",true)'
elif [ $1 -eq 9 ]
then
    root -l -q -b 'driverMC.C("4000_Hewett","2000To4000","ADDPlots_Ms4000_Mgg2000To4000_Hewett.root",true)'
elif [ $1 -eq 10 ]
then
    root -l -q -b 'driverMC.C("5000_GRW","200To500","ADDPlots_Ms5000_Mgg200To500_GRW.root",true)'
elif [ $1 -eq 11 ]
then
    root -l -q -b 'driverMC.C("5000_GRW","500To1000","ADDPlots_Ms5000_Mgg500To1000_GRW.root",true)'
elif [ $1 -eq 12 ]
then
    root -l -q -b 'driverMC.C("5000_GRW","1000To2000","ADDPlots_Ms5000_Mgg1000To2000_GRW.root",true)'
elif [ $1 -eq 13 ]
then
    root -l -q -b 'driverMC.C("5000_GRW","2000To3000","ADDPlots_Ms5000_Mgg2000To3000_GRW.root",true)'
elif [ $1 -eq 14 ]
then
    root -l -q -b 'driverMC.C("5000_GRW","3000To5000","ADDPlots_Ms5000_Mgg3000To5000_GRW.root",true)'
elif [ $1 -eq 15 ]
then
    root -l -q -b 'driverMC.C("5000_HLZ","500To1000","ADDPlots_Ms5000_Mgg500To1000_HLZ.root",true)'
elif [ $1 -eq 16 ]
then
    root -l -q -b 'driverMC.C("5000_HLZ","1000To2000","ADDPlots_Ms5000_Mgg1000To2000_HLZ.root",true)'
elif [ $1 -eq 17 ]
then
    root -l -q -b 'driverMC.C("5000_HLZ","2000To3000","ADDPlots_Ms5000_Mgg2000To3000_HLZ.root",true)'
elif [ $1 -eq 18 ]
then
    root -l -q -b 'driverMC.C("5000_HLZ","3000To5000","ADDPlots_Ms5000_Mgg3000To5000_HLZ.root",true)'
elif [ $1 -eq 19 ]
then
    root -l -q -b 'driverMC.C("5000_Hewett","500To1000","ADDPlots_Ms5000_Mgg500To1000_Hewett.root",true)'
elif [ $1 -eq 20 ]
then
    root -l -q -b 'driverMC.C("5000_Hewett","1000To2000","ADDPlots_Ms5000_Mgg1000To2000_Hewett.root",true)'
elif [ $1 -eq 21 ]
then
    root -l -q -b 'driverMC.C("5000_Hewett","2000To3000","ADDPlots_Ms5000_Mgg2000To3000_Hewett.root",true)'
elif [ $1 -eq 22 ]
then
    root -l -q -b 'driverMC.C("5000_Hewett","3000To5000","ADDPlots_Ms5000_Mgg3000To5000_Hewett.root",true)'
elif [ $1 -eq 23 ]
then
    root -l -q -b 'driverMC.C("3500_GRW","200To500","ADDPlots_Ms3500_Mgg200To500_GRW.root",true)'
elif [ $1 -eq 24 ]
then
    root -l -q -b 'driverMC.C("3500_GRW","500To1000","ADDPlots_Ms3500_Mgg500To1000_GRW.root",true)'
elif [ $1 -eq 25 ]
then
    root -l -q -b 'driverMC.C("3500_GRW","1000To2000","ADDPlots_Ms3500_Mgg1000To2000_GRW.root",true)'
elif [ $1 -eq 26 ]
then
    root -l -q -b 'driverMC.C("3500_GRW","2000To3500","ADDPlots_Ms3500_Mgg2000To3500_GRW.root",true)'
elif [ $1 -eq 27 ]
then
    root -l -q -b 'driverMC.C("3500_HLZ","500To1000","ADDPlots_Ms3500_Mgg500To1000_HLZ.root",true)'
elif [ $1 -eq 28 ]
then
    root -l -q -b 'driverMC.C("3500_HLZ","1000To2000","ADDPlots_Ms3500_Mgg1000To2000_HLZ.root",true)'
elif [ $1 -eq 29 ]
then
    root -l -q -b 'driverMC.C("3500_HLZ","2000To3500","ADDPlots_Ms3500_Mgg2000To3500_HLZ.root",true)'
elif [ $1 -eq 30 ]
then
    root -l -q -b 'driverMC.C("3500_Hewett","500To1000","ADDPlots_Ms3500_Mgg500To1000_Hewett.root",true)'
elif [ $1 -eq 31 ]
then
    root -l -q -b 'driverMC.C("3500_Hewett","1000To2000","ADDPlots_Ms3500_Mgg1000To2000_Hewett.root",true)'
elif [ $1 -eq 32 ]
then
    root -l -q -b 'driverMC.C("3500_Hewett","2000To3500","ADDPlots_Ms3500_Mgg2000To3500_Hewett.root",true)'
elif [ $1 -eq 33 ]
then
    root -l -q -b 'driverMC.C("6000_GRW","200To500","ADDPlots_Ms6000_Mgg200To500_GRW.root",true)'
elif [ $1 -eq 34 ]
then
    root -l -q -b 'driverMC.C("6000_GRW","500To1000","ADDPlots_Ms6000_Mgg500To1000_GRW.root",true)'
elif [ $1 -eq 35 ]
then
    root -l -q -b 'driverMC.C("6000_GRW","1000To2000","ADDPlots_Ms6000_Mgg1000To2000_GRW.root",true)'
elif [ $1 -eq 36 ]
then
    root -l -q -b 'driverMC.C("6000_GRW","2000To4000","ADDPlots_Ms6000_Mgg2000To4000_GRW.root",true)'
elif [ $1 -eq 37 ]
then
    root -l -q -b 'driverMC.C("6000_GRW","4000To6000","ADDPlots_Ms6000_Mgg4000To6000_GRW.root",true)'
elif [ $1 -eq 38 ]
then
    root -l -q -b 'driverMC.C("6000_HLZ","500To1000","ADDPlots_Ms6000_Mgg500To1000_HLZ.root",true)'
elif [ $1 -eq 39 ]
then
    root -l -q -b 'driverMC.C("6000_HLZ","1000To2000","ADDPlots_Ms6000_Mgg1000To2000_HLZ.root",true)'
elif [ $1 -eq 40 ]
then
    root -l -q -b 'driverMC.C("6000_HLZ","2000To4000","ADDPlots_Ms6000_Mgg2000To4000_HLZ.root",true)'
elif [ $1 -eq 41 ]
then
    root -l -q -b 'driverMC.C("6000_HLZ","4000To6000","ADDPlots_Ms6000_Mgg4000To6000_HLZ.root",true)'
elif [ $1 -eq 42 ]
then
    root -l -q -b 'driverMC.C("6000_Hewett","500To1000","ADDPlots_Ms6000_Mgg500To1000_Hewett.root",true)'
elif [ $1 -eq 43 ]
then
    root -l -q -b 'driverMC.C("6000_Hewett","1000To2000","ADDPlots_Ms6000_Mgg1000To2000_Hewett.root",true)'
elif [ $1 -eq 44 ]
then
    root -l -q -b 'driverMC.C("6000_Hewett","2000To4000","ADDPlots_Ms6000_Mgg2000To4000_Hewett.root",true)'
elif [ $1 -eq 45 ]
then
    root -l -q -b 'driverMC.C("6000_Hewett","4000To6000","ADDPlots_Ms6000_Mgg4000To6000_Hewett.root",true)'
elif [ $1 -eq 46 ]
then
    root -l -q -b 'driverMC.C("4500_GRW","200To500","ADDPlots_Ms4500_Mgg200To500_GRW.root",true)'
elif [ $1 -eq 47 ]
then
    root -l -q -b 'driverMC.C("4500_GRW","500To1000","ADDPlots_Ms4500_Mgg500To1000_GRW.root",true)'
elif [ $1 -eq 48 ]
then
    root -l -q -b 'driverMC.C("4500_GRW","1000To2000","ADDPlots_Ms4500_Mgg1000To2000_GRW.root",true)'
elif [ $1 -eq 49 ]
then
    root -l -q -b 'driverMC.C("4500_GRW","2000To3000","ADDPlots_Ms4500_Mgg2000To3000_GRW.root",true)'
elif [ $1 -eq 50 ]
then
    root -l -q -b 'driverMC.C("4500_GRW","3000To4500","ADDPlots_Ms4500_Mgg3000To4500_GRW.root",true)'
elif [ $1 -eq 51 ]
then
    root -l -q -b 'driverMC.C("4500_HLZ","500To1000","ADDPlots_Ms4500_Mgg500To1000_HLZ.root",true)'
elif [ $1 -eq 52 ]
then
    root -l -q -b 'driverMC.C("4500_HLZ","1000To2000","ADDPlots_Ms4500_Mgg1000To2000_HLZ.root",true)'
elif [ $1 -eq 53 ]
then
    root -l -q -b 'driverMC.C("4500_HLZ","2000To3000","ADDPlots_Ms4500_Mgg2000To3000_HLZ.root",true)'
elif [ $1 -eq 54 ]
then
    root -l -q -b 'driverMC.C("4500_HLZ","3000To4500","ADDPlots_Ms4500_Mgg3000To4500_HLZ.root",true)'
elif [ $1 -eq 55 ]
then
    root -l -q -b 'driverMC.C("4500_Hewett","500To1000","ADDPlots_Ms4500_Mgg500To1000_Hewett.root",true)'
elif [ $1 -eq 56 ]
then
    root -l -q -b 'driverMC.C("4500_Hewett","1000To2000","ADDPlots_Ms4500_Mgg1000To2000_Hewett.root",true)'
elif [ $1 -eq 57 ]
then
    root -l -q -b 'driverMC.C("4500_Hewett","2000To3000","ADDPlots_Ms4500_Mgg2000To3000_Hewett.root",true)'
elif [ $1 -eq 58 ]
then
    root -l -q -b 'driverMC.C("4500_Hewett","3000To4500","ADDPlots_Ms4500_Mgg3000To4500_Hewett.root",true)'
elif [ $1 -eq 59 ]
then
    root -l -q -b 'driverMC.C("3000_GRW","200To500","ADDPlots_Ms3000_Mgg200To500_GRW.root",true)'
elif [ $1 -eq 60 ]
then
    root -l -q -b 'driverMC.C("3000_GRW","500To1000","ADDPlots_Ms3000_Mgg500To1000_GRW.root",true)'
elif [ $1 -eq 61 ]
then
    root -l -q -b 'driverMC.C("3000_GRW","1000To2000","ADDPlots_Ms3000_Mgg1000To2000_GRW.root",true)'
elif [ $1 -eq 62 ]
then
    root -l -q -b 'driverMC.C("3000_GRW","2000To3000","ADDPlots_Ms3000_Mgg2000To3000_GRW.root",true)'
elif [ $1 -eq 63 ]
then
    root -l -q -b 'driverMC.C("3000_HLZ","500To1000","ADDPlots_Ms3000_Mgg500To1000_HLZ.root",true)'
elif [ $1 -eq 64 ]
then
    root -l -q -b 'driverMC.C("3000_HLZ","1000To2000","ADDPlots_Ms3000_Mgg1000To2000_HLZ.root",true)'
elif [ $1 -eq 65 ]
then
    root -l -q -b 'driverMC.C("3000_HLZ","2000To3000","ADDPlots_Ms3000_Mgg2000To3000_HLZ.root",true)'
elif [ $1 -eq 66 ]
then
    root -l -q -b 'driverMC.C("3000_Hewett","500To1000","ADDPlots_Ms3000_Mgg500To1000_Hewett.root",true)'
elif [ $1 -eq 67 ]
then
    root -l -q -b 'driverMC.C("3000_Hewett","1000To2000","ADDPlots_Ms3000_Mgg1000To2000_Hewett.root",true)'
elif [ $1 -eq 68 ]
then
    root -l -q -b 'driverMC.C("3000_Hewett","2000To3000","ADDPlots_Ms3000_Mgg2000To3000_Hewett.root",true)'
elif [ $1 -eq 69 ]
then
    root -l -q -b 'driverMC.C("5500_GRW","200To500","ADDPlots_Ms5500_Mgg200To500_GRW.root",true)'
elif [ $1 -eq 70 ]
then
    root -l -q -b 'driverMC.C("5500_GRW","500To1000","ADDPlots_Ms5500_Mgg500To1000_GRW.root",true)'
elif [ $1 -eq 71 ]
then
    root -l -q -b 'driverMC.C("5500_GRW","1000To2000","ADDPlots_Ms5500_Mgg1000To2000_GRW.root",true)'
elif [ $1 -eq 72 ]
then
    root -l -q -b 'driverMC.C("5500_GRW","2000To4000","ADDPlots_Ms5500_Mgg2000To4000_GRW.root",true)'
elif [ $1 -eq 73 ]
then
    root -l -q -b 'driverMC.C("5500_GRW","4000To5500","ADDPlots_Ms5500_Mgg4000To5500_GRW.root",true)'
elif [ $1 -eq 74 ]
then
    root -l -q -b 'driverMC.C("5500_HLZ","500To1000","ADDPlots_Ms5500_Mgg500To1000_HLZ.root",true)'
elif [ $1 -eq 75 ]
then
    root -l -q -b 'driverMC.C("5500_HLZ","1000To2000","ADDPlots_Ms5500_Mgg1000To2000_HLZ.root",true)'
elif [ $1 -eq 76 ]
then
    root -l -q -b 'driverMC.C("5500_HLZ","2000To4000","ADDPlots_Ms5500_Mgg2000To4000_HLZ.root",true)'
elif [ $1 -eq 77 ]
then
    root -l -q -b 'driverMC.C("5500_HLZ","4000To5500","ADDPlots_Ms5500_Mgg4000To5500_HLZ.root",true)'
elif [ $1 -eq 78 ]
then
    root -l -q -b 'driverMC.C("5500_Hewett","500To1000","ADDPlots_Ms5500_Mgg500To1000_Hewett.root",true)'
elif [ $1 -eq 79 ]
then
    root -l -q -b 'driverMC.C("5500_Hewett","1000To2000","ADDPlots_Ms5500_Mgg1000To2000_Hewett.root",true)'
elif [ $1 -eq 80 ]
then
    root -l -q -b 'driverMC.C("5500_Hewett","2000To4000","ADDPlots_Ms5500_Mgg2000To4000_Hewett.root",true)'
elif [ $1 -eq 81 ]
then
    root -l -q -b 'driverMC.C("5500_Hewett","4000To5500","ADDPlots_Ms5500_Mgg4000To5500_Hewett.root",true)'
elif [ $1 -eq 82 ]
then
    root -l -q -b 'driverMC.C("ADDBkg","200To500","ADDPlots_ADDBkg_Mgg200To500.root",true)'
elif [ $1 -eq 83 ]
then
    root -l -q -b 'driverMC.C("ADDBkg","500To1000","ADDPlots_ADDBkg_Mgg500To1000.root",true)'
elif [ $1 -eq 84 ]
then
    root -l -q -b 'driverMC.C("ADDBkg","1000To2000","ADDPlots_ADDBkg_Mgg1000To2000.root",true)'
elif [ $1 -eq 85 ]
then
    root -l -q -b 'driverMC.C("ADDBkg","2000To4000","ADDPlots_ADDBkg_Mgg2000To4000.root",true)'
elif [ $1 -eq 86 ]
then
    root -l -q -b 'driverMC.C("ADDBkg","4000To8000","ADDPlots_ADDBkg_Mgg4000To8000.root",true)'
elif [ $1 -eq 87 ]
then
    root -l -q -b 'driverMC.C("ADDBkg","8000To13000","ADDPlots_ADDBkg_Mgg8000To13000.root",true)'
elif [ $1 -eq 88 ]
then
    root -l -q -b 'driverMC.C("GGJets","60To200","ADDPlots_GGJets_Mgg60To200.root",true)'
elif [ $1 -eq 89 ]
then
    root -l -q -b 'driverMC.C("GGJets","200To500","ADDPlots_GGJets_Mgg200To500.root",true)'
elif [ $1 -eq 90 ]
then
    root -l -q -b 'driverMC.C("GGJets","500To1000","ADDPlots_GGJets_Mgg500To1000.root",true)'
elif [ $1 -eq 91 ]
then
    root -l -q -b 'driverMC.C("GGJets","1000To2000","ADDPlots_GGJets_Mgg1000To2000.root",true)'
elif [ $1 -eq 92 ]
then
    root -l -q -b 'driverMC.C("GGJets","2000To4000","ADDPlots_GGJets_Mgg2000To4000.root",true)'
elif [ $1 -eq 93 ]
then
    root -l -q -b 'driverMC.C("GGJets","4000To6000","ADDPlots_GGJets_Mgg4000To6000.root",true)'
elif [ $1 -eq 94 ]
then
    root -l -q -b 'driverMC.C("GGJets","6000To8000","ADDPlots_GGJets_Mgg6000To8000.root",true)'
elif [ $1 -eq 95 ]
then
    root -l -q -b 'driverMC.C("GGJets","8000To13000","ADDPlots_GGJets_Mgg8000To13000.root",true)'
fi

