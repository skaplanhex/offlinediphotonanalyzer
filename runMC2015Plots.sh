#! /bin/bash

export SCRAM_ARCH=slc6_amd64_gcc493
source /cvmfs/cms.cern.ch/cmsset_default.sh

cd /uscms_data/d3/skaplan/diphotons/offlineanalysis/CMSSW_7_6_4/src
eval `scramv1 runtime -sh`
cd ${_CONDOR_SCRATCH_DIR}

unzip kFactorFits.zip

if [ $1 -eq 0 ]
then
    root -l -q -b 'driverMC.C("3000_GRW","500To1000","ADDPlots_Ms3000_Mgg500To1000_GRW.root","2015MC")'
elif [ $1 -eq 1 ]
then
    root -l -q -b 'driverMC.C("3000_GRW","1000To2000","ADDPlots_Ms3000_Mgg1000To2000_GRW.root","2015MC")'
elif [ $1 -eq 2 ]
then
    root -l -q -b 'driverMC.C("3000_GRW","2000To3000","ADDPlots_Ms3000_Mgg2000To3000_GRW.root","2015MC")'
elif [ $1 -eq 3 ]
then
    root -l -q -b 'driverMC.C("3000_HLZ","500To1000","ADDPlots_Ms3000_Mgg500To1000_HLZ.root","2015MC")'
elif [ $1 -eq 4 ]
then
    root -l -q -b 'driverMC.C("3000_HLZ","1000To2000","ADDPlots_Ms3000_Mgg1000To2000_HLZ.root","2015MC")'
elif [ $1 -eq 5 ]
then
    root -l -q -b 'driverMC.C("3000_HLZ","2000To3000","ADDPlots_Ms3000_Mgg2000To3000_HLZ.root","2015MC")'
elif [ $1 -eq 6 ]
then
    root -l -q -b 'driverMC.C("3000_Hewett","500To1000","ADDPlots_Ms3000_Mgg500To1000_Hewett.root","2015MC")'
elif [ $1 -eq 7 ]
then
    root -l -q -b 'driverMC.C("3000_Hewett","1000To2000","ADDPlots_Ms3000_Mgg1000To2000_Hewett.root","2015MC")'
elif [ $1 -eq 8 ]
then
    root -l -q -b 'driverMC.C("3000_Hewett","2000To3000","ADDPlots_Ms3000_Mgg2000To3000_Hewett.root","2015MC")'
elif [ $1 -eq 9 ]
then
    root -l -q -b 'driverMC.C("3500_GRW","500To1000","ADDPlots_Ms3500_Mgg500To1000_GRW.root","2015MC")'
elif [ $1 -eq 10 ]
then
    root -l -q -b 'driverMC.C("3500_GRW","1000To2000","ADDPlots_Ms3500_Mgg1000To2000_GRW.root","2015MC")'
elif [ $1 -eq 11 ]
then
    root -l -q -b 'driverMC.C("3500_GRW","2000To3500","ADDPlots_Ms3500_Mgg2000To3500_GRW.root","2015MC")'
elif [ $1 -eq 12 ]
then
    root -l -q -b 'driverMC.C("3500_HLZ","500To1000","ADDPlots_Ms3500_Mgg500To1000_HLZ.root","2015MC")'
elif [ $1 -eq 13 ]
then
    root -l -q -b 'driverMC.C("3500_HLZ","1000To2000","ADDPlots_Ms3500_Mgg1000To2000_HLZ.root","2015MC")'
elif [ $1 -eq 14 ]
then
    root -l -q -b 'driverMC.C("3500_HLZ","2000To3500","ADDPlots_Ms3500_Mgg2000To3500_HLZ.root","2015MC")'
elif [ $1 -eq 15 ]
then
    root -l -q -b 'driverMC.C("3500_Hewett","500To1000","ADDPlots_Ms3500_Mgg500To1000_Hewett.root","2015MC")'
elif [ $1 -eq 16 ]
then
    root -l -q -b 'driverMC.C("3500_Hewett","1000To2000","ADDPlots_Ms3500_Mgg1000To2000_Hewett.root","2015MC")'
elif [ $1 -eq 17 ]
then
    root -l -q -b 'driverMC.C("3500_Hewett","2000To3500","ADDPlots_Ms3500_Mgg2000To3500_Hewett.root","2015MC")'
elif [ $1 -eq 18 ]
then
    root -l -q -b 'driverMC.C("4000_GRW","500To1000","ADDPlots_Ms4000_Mgg500To1000_GRW.root","2015MC")'
elif [ $1 -eq 19 ]
then
    root -l -q -b 'driverMC.C("4000_GRW","1000To2000","ADDPlots_Ms4000_Mgg1000To2000_GRW.root","2015MC")'
elif [ $1 -eq 20 ]
then
    root -l -q -b 'driverMC.C("4000_GRW","2000To4000","ADDPlots_Ms4000_Mgg2000To4000_GRW.root","2015MC")'
elif [ $1 -eq 21 ]
then
    root -l -q -b 'driverMC.C("4000_HLZ","500To1000","ADDPlots_Ms4000_Mgg500To1000_HLZ.root","2015MC")'
elif [ $1 -eq 22 ]
then
    root -l -q -b 'driverMC.C("4000_HLZ","1000To2000","ADDPlots_Ms4000_Mgg1000To2000_HLZ.root","2015MC")'
elif [ $1 -eq 23 ]
then
    root -l -q -b 'driverMC.C("4000_HLZ","2000To4000","ADDPlots_Ms4000_Mgg2000To4000_HLZ.root","2015MC")'
elif [ $1 -eq 24 ]
then
    root -l -q -b 'driverMC.C("4000_Hewett","500To1000","ADDPlots_Ms4000_Mgg500To1000_Hewett.root","2015MC")'
elif [ $1 -eq 25 ]
then
    root -l -q -b 'driverMC.C("4000_Hewett","1000To2000","ADDPlots_Ms4000_Mgg1000To2000_Hewett.root","2015MC")'
elif [ $1 -eq 26 ]
then
    root -l -q -b 'driverMC.C("4000_Hewett","2000To4000","ADDPlots_Ms4000_Mgg2000To4000_Hewett.root","2015MC")'
elif [ $1 -eq 27 ]
then
    root -l -q -b 'driverMC.C("4500_GRW","500To1000","ADDPlots_Ms4500_Mgg500To1000_GRW.root","2015MC")'
elif [ $1 -eq 28 ]
then
    root -l -q -b 'driverMC.C("4500_GRW","1000To2000","ADDPlots_Ms4500_Mgg1000To2000_GRW.root","2015MC")'
elif [ $1 -eq 29 ]
then
    root -l -q -b 'driverMC.C("4500_GRW","2000To3000","ADDPlots_Ms4500_Mgg2000To3000_GRW.root","2015MC")'
elif [ $1 -eq 30 ]
then
    root -l -q -b 'driverMC.C("4500_GRW","3000To4500","ADDPlots_Ms4500_Mgg3000To4500_GRW.root","2015MC")'
elif [ $1 -eq 31 ]
then
    root -l -q -b 'driverMC.C("4500_HLZ","500To1000","ADDPlots_Ms4500_Mgg500To1000_HLZ.root","2015MC")'
elif [ $1 -eq 32 ]
then
    root -l -q -b 'driverMC.C("4500_HLZ","1000To2000","ADDPlots_Ms4500_Mgg1000To2000_HLZ.root","2015MC")'
elif [ $1 -eq 33 ]
then
    root -l -q -b 'driverMC.C("4500_HLZ","2000To3000","ADDPlots_Ms4500_Mgg2000To3000_HLZ.root","2015MC")'
elif [ $1 -eq 34 ]
then
    root -l -q -b 'driverMC.C("4500_HLZ","3000To4500","ADDPlots_Ms4500_Mgg3000To4500_HLZ.root","2015MC")'
elif [ $1 -eq 35 ]
then
    root -l -q -b 'driverMC.C("4500_Hewett","500To1000","ADDPlots_Ms4500_Mgg500To1000_Hewett.root","2015MC")'
elif [ $1 -eq 36 ]
then
    root -l -q -b 'driverMC.C("4500_Hewett","1000To2000","ADDPlots_Ms4500_Mgg1000To2000_Hewett.root","2015MC")'
elif [ $1 -eq 37 ]
then
    root -l -q -b 'driverMC.C("4500_Hewett","2000To3000","ADDPlots_Ms4500_Mgg2000To3000_Hewett.root","2015MC")'
elif [ $1 -eq 38 ]
then
    root -l -q -b 'driverMC.C("4500_Hewett","3000To4500","ADDPlots_Ms4500_Mgg3000To4500_Hewett.root","2015MC")'
elif [ $1 -eq 39 ]
then
    root -l -q -b 'driverMC.C("5000_GRW","500To1000","ADDPlots_Ms5000_Mgg500To1000_GRW.root","2015MC")'
elif [ $1 -eq 40 ]
then
    root -l -q -b 'driverMC.C("5000_GRW","1000To2000","ADDPlots_Ms5000_Mgg1000To2000_GRW.root","2015MC")'
elif [ $1 -eq 41 ]
then
    root -l -q -b 'driverMC.C("5000_GRW","2000To3000","ADDPlots_Ms5000_Mgg2000To3000_GRW.root","2015MC")'
elif [ $1 -eq 42 ]
then
    root -l -q -b 'driverMC.C("5000_GRW","3000To5000","ADDPlots_Ms5000_Mgg3000To5000_GRW.root","2015MC")'
elif [ $1 -eq 43 ]
then
    root -l -q -b 'driverMC.C("5000_HLZ","500To1000","ADDPlots_Ms5000_Mgg500To1000_HLZ.root","2015MC")'
elif [ $1 -eq 44 ]
then
    root -l -q -b 'driverMC.C("5000_HLZ","1000To2000","ADDPlots_Ms5000_Mgg1000To2000_HLZ.root","2015MC")'
elif [ $1 -eq 45 ]
then
    root -l -q -b 'driverMC.C("5000_HLZ","2000To3000","ADDPlots_Ms5000_Mgg2000To3000_HLZ.root","2015MC")'
elif [ $1 -eq 46 ]
then
    root -l -q -b 'driverMC.C("5000_HLZ","3000To5000","ADDPlots_Ms5000_Mgg3000To5000_HLZ.root","2015MC")'
elif [ $1 -eq 47 ]
then
    root -l -q -b 'driverMC.C("5000_Hewett","500To1000","ADDPlots_Ms5000_Mgg500To1000_Hewett.root","2015MC")'
elif [ $1 -eq 48 ]
then
    root -l -q -b 'driverMC.C("5000_Hewett","1000To2000","ADDPlots_Ms5000_Mgg1000To2000_Hewett.root","2015MC")'
elif [ $1 -eq 49 ]
then
    root -l -q -b 'driverMC.C("5000_Hewett","2000To3000","ADDPlots_Ms5000_Mgg2000To3000_Hewett.root","2015MC")'
elif [ $1 -eq 50 ]
then
    root -l -q -b 'driverMC.C("5000_Hewett","3000To5000","ADDPlots_Ms5000_Mgg3000To5000_Hewett.root","2015MC")'
elif [ $1 -eq 51 ]
then
    root -l -q -b 'driverMC.C("5500_GRW","500To1000","ADDPlots_Ms5500_Mgg500To1000_GRW.root","2015MC")'
elif [ $1 -eq 52 ]
then
    root -l -q -b 'driverMC.C("5500_GRW","1000To2000","ADDPlots_Ms5500_Mgg1000To2000_GRW.root","2015MC")'
elif [ $1 -eq 53 ]
then
    root -l -q -b 'driverMC.C("5500_GRW","2000To4000","ADDPlots_Ms5500_Mgg2000To4000_GRW.root","2015MC")'
elif [ $1 -eq 54 ]
then
    root -l -q -b 'driverMC.C("5500_GRW","4000To5500","ADDPlots_Ms5500_Mgg4000To5500_GRW.root","2015MC")'
elif [ $1 -eq 55 ]
then
    root -l -q -b 'driverMC.C("5500_HLZ","500To1000","ADDPlots_Ms5500_Mgg500To1000_HLZ.root","2015MC")'
elif [ $1 -eq 56 ]
then
    root -l -q -b 'driverMC.C("5500_HLZ","1000To2000","ADDPlots_Ms5500_Mgg1000To2000_HLZ.root","2015MC")'
elif [ $1 -eq 57 ]
then
    root -l -q -b 'driverMC.C("5500_HLZ","2000To4000","ADDPlots_Ms5500_Mgg2000To4000_HLZ.root","2015MC")'
elif [ $1 -eq 58 ]
then
    root -l -q -b 'driverMC.C("5500_HLZ","4000To5500","ADDPlots_Ms5500_Mgg4000To5500_HLZ.root","2015MC")'
elif [ $1 -eq 59 ]
then
    root -l -q -b 'driverMC.C("5500_Hewett","500To1000","ADDPlots_Ms5500_Mgg500To1000_Hewett.root","2015MC")'
elif [ $1 -eq 60 ]
then
    root -l -q -b 'driverMC.C("5500_Hewett","1000To2000","ADDPlots_Ms5500_Mgg1000To2000_Hewett.root","2015MC")'
elif [ $1 -eq 61 ]
then
    root -l -q -b 'driverMC.C("5500_Hewett","2000To4000","ADDPlots_Ms5500_Mgg2000To4000_Hewett.root","2015MC")'
elif [ $1 -eq 62 ]
then
    root -l -q -b 'driverMC.C("5500_Hewett","4000To5500","ADDPlots_Ms5500_Mgg4000To5500_Hewett.root","2015MC")'
elif [ $1 -eq 63 ]
then
    root -l -q -b 'driverMC.C("6000_GRW","500To1000","ADDPlots_Ms6000_Mgg500To1000_GRW.root","2015MC")'
elif [ $1 -eq 64 ]
then
    root -l -q -b 'driverMC.C("6000_GRW","1000To2000","ADDPlots_Ms6000_Mgg1000To2000_GRW.root","2015MC")'
elif [ $1 -eq 65 ]
then
    root -l -q -b 'driverMC.C("6000_GRW","2000To4000","ADDPlots_Ms6000_Mgg2000To4000_GRW.root","2015MC")'
elif [ $1 -eq 66 ]
then
    root -l -q -b 'driverMC.C("6000_GRW","4000To6000","ADDPlots_Ms6000_Mgg4000To6000_GRW.root","2015MC")'
elif [ $1 -eq 67 ]
then
    root -l -q -b 'driverMC.C("6000_HLZ","500To1000","ADDPlots_Ms6000_Mgg500To1000_HLZ.root","2015MC")'
elif [ $1 -eq 68 ]
then
    root -l -q -b 'driverMC.C("6000_HLZ","1000To2000","ADDPlots_Ms6000_Mgg1000To2000_HLZ.root","2015MC")'
elif [ $1 -eq 69 ]
then
    root -l -q -b 'driverMC.C("6000_HLZ","2000To4000","ADDPlots_Ms6000_Mgg2000To4000_HLZ.root","2015MC")'
elif [ $1 -eq 70 ]
then
    root -l -q -b 'driverMC.C("6000_HLZ","4000To6000","ADDPlots_Ms6000_Mgg4000To6000_HLZ.root","2015MC")'
elif [ $1 -eq 71 ]
then
    root -l -q -b 'driverMC.C("6000_Hewett","500To1000","ADDPlots_Ms6000_Mgg500To1000_Hewett.root","2015MC")'
elif [ $1 -eq 72 ]
then
    root -l -q -b 'driverMC.C("6000_Hewett","1000To2000","ADDPlots_Ms6000_Mgg1000To2000_Hewett.root","2015MC")'
elif [ $1 -eq 73 ]
then
    root -l -q -b 'driverMC.C("6000_Hewett","2000To4000","ADDPlots_Ms6000_Mgg2000To4000_Hewett.root","2015MC")'
elif [ $1 -eq 74 ]
then
    root -l -q -b 'driverMC.C("6000_Hewett","4000To6000","ADDPlots_Ms6000_Mgg4000To6000_Hewett.root","2015MC")'
elif [ $1 -eq 75 ]
then
    root -l -q -b 'driverMC.C("7000_GRW","500To1000","ADDPlots_Ms7000_Mgg500To1000_GRW.root","2015MC")'
elif [ $1 -eq 76 ]
then
    root -l -q -b 'driverMC.C("7000_GRW","1000To2000","ADDPlots_Ms7000_Mgg1000To2000_GRW.root","2015MC")'
elif [ $1 -eq 77 ]
then
    root -l -q -b 'driverMC.C("7000_GRW","2000To4000","ADDPlots_Ms7000_Mgg2000To4000_GRW.root","2015MC")'
elif [ $1 -eq 78 ]
then
    root -l -q -b 'driverMC.C("7000_GRW","4000To7000","ADDPlots_Ms7000_Mgg4000To7000_GRW.root","2015MC")'
elif [ $1 -eq 79 ]
then
    root -l -q -b 'driverMC.C("7000_HLZ","500To1000","ADDPlots_Ms7000_Mgg500To1000_HLZ.root","2015MC")'
elif [ $1 -eq 80 ]
then
    root -l -q -b 'driverMC.C("7000_HLZ","1000To2000","ADDPlots_Ms7000_Mgg1000To2000_HLZ.root","2015MC")'
elif [ $1 -eq 81 ]
then
    root -l -q -b 'driverMC.C("7000_HLZ","2000To4000","ADDPlots_Ms7000_Mgg2000To4000_HLZ.root","2015MC")'
elif [ $1 -eq 82 ]
then
    root -l -q -b 'driverMC.C("7000_HLZ","4000To7000","ADDPlots_Ms7000_Mgg4000To7000_HLZ.root","2015MC")'
elif [ $1 -eq 83 ]
then
    root -l -q -b 'driverMC.C("8000_GRW","500To1000","ADDPlots_Ms8000_Mgg500To1000_GRW.root","2015MC")'
elif [ $1 -eq 84 ]
then
    root -l -q -b 'driverMC.C("8000_GRW","1000To2000","ADDPlots_Ms8000_Mgg1000To2000_GRW.root","2015MC")'
elif [ $1 -eq 85 ]
then
    root -l -q -b 'driverMC.C("8000_GRW","2000To4000","ADDPlots_Ms8000_Mgg2000To4000_GRW.root","2015MC")'
elif [ $1 -eq 86 ]
then
    root -l -q -b 'driverMC.C("8000_GRW","4000To8000","ADDPlots_Ms8000_Mgg4000To8000_GRW.root","2015MC")'
elif [ $1 -eq 87 ]
then
    root -l -q -b 'driverMC.C("8000_HLZ","500To1000","ADDPlots_Ms8000_Mgg500To1000_HLZ.root","2015MC")'
elif [ $1 -eq 88 ]
then
    root -l -q -b 'driverMC.C("8000_HLZ","1000To2000","ADDPlots_Ms8000_Mgg1000To2000_HLZ.root","2015MC")'
elif [ $1 -eq 89 ]
then
    root -l -q -b 'driverMC.C("8000_HLZ","2000To4000","ADDPlots_Ms8000_Mgg2000To4000_HLZ.root","2015MC")'
elif [ $1 -eq 90 ]
then
    root -l -q -b 'driverMC.C("8000_HLZ","4000To8000","ADDPlots_Ms8000_Mgg4000To8000_HLZ.root","2015MC")'
elif [ $1 -eq 91 ]
then
    root -l -q -b 'driverMC.C("9000_GRW","500To1000","ADDPlots_Ms9000_Mgg500To1000_GRW.root","2015MC")'
elif [ $1 -eq 92 ]
then
    root -l -q -b 'driverMC.C("9000_GRW","1000To2000","ADDPlots_Ms9000_Mgg1000To2000_GRW.root","2015MC")'
elif [ $1 -eq 93 ]
then
    root -l -q -b 'driverMC.C("9000_GRW","2000To4000","ADDPlots_Ms9000_Mgg2000To4000_GRW.root","2015MC")'
elif [ $1 -eq 94 ]
then
    root -l -q -b 'driverMC.C("9000_GRW","4000To9000","ADDPlots_Ms9000_Mgg4000To9000_GRW.root","2015MC")'
elif [ $1 -eq 95 ]
then
    root -l -q -b 'driverMC.C("9000_HLZ","500To1000","ADDPlots_Ms9000_Mgg500To1000_HLZ.root","2015MC")'
elif [ $1 -eq 96 ]
then
    root -l -q -b 'driverMC.C("9000_HLZ","1000To2000","ADDPlots_Ms9000_Mgg1000To2000_HLZ.root","2015MC")'
elif [ $1 -eq 97 ]
then
    root -l -q -b 'driverMC.C("9000_HLZ","2000To4000","ADDPlots_Ms9000_Mgg2000To4000_HLZ.root","2015MC")'
elif [ $1 -eq 98 ]
then
    root -l -q -b 'driverMC.C("9000_HLZ","4000To9000","ADDPlots_Ms9000_Mgg4000To9000_HLZ.root","2015MC")'
elif [ $1 -eq 99 ]
then
    root -l -q -b 'driverMC.C("10000_GRW","500To1000","ADDPlots_Ms10000_Mgg500To1000_GRW.root","2015MC")'
elif [ $1 -eq 100 ]
then
    root -l -q -b 'driverMC.C("10000_GRW","1000To2000","ADDPlots_Ms10000_Mgg1000To2000_GRW.root","2015MC")'
elif [ $1 -eq 101 ]
then
    root -l -q -b 'driverMC.C("10000_GRW","2000To4000","ADDPlots_Ms10000_Mgg2000To4000_GRW.root","2015MC")'
elif [ $1 -eq 102 ]
then
    root -l -q -b 'driverMC.C("10000_GRW","4000To10000","ADDPlots_Ms10000_Mgg4000To10000_GRW.root","2015MC")'
elif [ $1 -eq 103 ]
then
    root -l -q -b 'driverMC.C("10000_HLZ","500To1000","ADDPlots_Ms10000_Mgg500To1000_HLZ.root","2015MC")'
elif [ $1 -eq 104 ]
then
    root -l -q -b 'driverMC.C("10000_HLZ","1000To2000","ADDPlots_Ms10000_Mgg1000To2000_HLZ.root","2015MC")'
elif [ $1 -eq 105 ]
then
    root -l -q -b 'driverMC.C("10000_HLZ","2000To4000","ADDPlots_Ms10000_Mgg2000To4000_HLZ.root","2015MC")'
elif [ $1 -eq 106 ]
then
    root -l -q -b 'driverMC.C("10000_HLZ","4000To10000","ADDPlots_Ms10000_Mgg4000To10000_HLZ.root","2015MC")'
elif [ $1 -eq 107 ]
then
    root -l -q -b 'driverMC.C("11000_GRW","500To1000","ADDPlots_Ms11000_Mgg500To1000_GRW.root","2015MC")'
elif [ $1 -eq 108 ]
then
    root -l -q -b 'driverMC.C("11000_GRW","1000To2000","ADDPlots_Ms11000_Mgg1000To2000_GRW.root","2015MC")'
elif [ $1 -eq 109 ]
then
    root -l -q -b 'driverMC.C("11000_GRW","2000To4000","ADDPlots_Ms11000_Mgg2000To4000_GRW.root","2015MC")'
elif [ $1 -eq 110 ]
then
    root -l -q -b 'driverMC.C("11000_GRW","4000To11000","ADDPlots_Ms11000_Mgg4000To11000_GRW.root","2015MC")'
elif [ $1 -eq 111 ]
then
    root -l -q -b 'driverMC.C("11000_HLZ","500To1000","ADDPlots_Ms11000_Mgg500To1000_HLZ.root","2015MC")'
elif [ $1 -eq 112 ]
then
    root -l -q -b 'driverMC.C("11000_HLZ","1000To2000","ADDPlots_Ms11000_Mgg1000To2000_HLZ.root","2015MC")'
elif [ $1 -eq 113 ]
then
    root -l -q -b 'driverMC.C("11000_HLZ","2000To4000","ADDPlots_Ms11000_Mgg2000To4000_HLZ.root","2015MC")'
elif [ $1 -eq 114 ]
then
    root -l -q -b 'driverMC.C("11000_HLZ","4000To11000","ADDPlots_Ms11000_Mgg4000To11000_HLZ.root","2015MC")'
elif [ $1 -eq 115 ]
then
    root -l -q -b 'driverMC.C("ADDBkg","500To1000","ADDPlots_ADDBkg_Mgg500To1000.root","2015MC")'
elif [ $1 -eq 116 ]
then
    root -l -q -b 'driverMC.C("ADDBkg","1000To2000","ADDPlots_ADDBkg_Mgg1000To2000.root","2015MC")'
elif [ $1 -eq 117 ]
then
    root -l -q -b 'driverMC.C("ADDBkg","2000To4000","ADDPlots_ADDBkg_Mgg2000To4000.root","2015MC")'
elif [ $1 -eq 118 ]
then
    root -l -q -b 'driverMC.C("ADDBkg","4000To8000","ADDPlots_ADDBkg_Mgg4000To8000.root","2015MC")'
elif [ $1 -eq 119 ]
then
    root -l -q -b 'driverMC.C("ADDBkg","8000To13000","ADDPlots_ADDBkg_Mgg8000To13000.root","2015MC")'
elif [ $1 -eq 120 ]
then
    root -l -q -b 'driverMC.C("GGJets","60To200","ADDPlots_GGJets_Mgg60To200.root","2015MC")'
elif [ $1 -eq 121 ]
then
    root -l -q -b 'driverMC.C("GGJets","200To500","ADDPlots_GGJets_Mgg200To500.root","2015MC")'
elif [ $1 -eq 122 ]
then
    root -l -q -b 'driverMC.C("GGJets","500To1000","ADDPlots_GGJets_Mgg500To1000.root","2015MC")'
elif [ $1 -eq 123 ]
then
    root -l -q -b 'driverMC.C("GGJets","1000To2000","ADDPlots_GGJets_Mgg1000To2000.root","2015MC")'
elif [ $1 -eq 124 ]
then
    root -l -q -b 'driverMC.C("GGJets","2000To4000","ADDPlots_GGJets_Mgg2000To4000.root","2015MC")'
elif [ $1 -eq 125 ]
then
    root -l -q -b 'driverMC.C("GGJets","4000To6000","ADDPlots_GGJets_Mgg4000To6000.root","2015MC")'
elif [ $1 -eq 126 ]
then
    root -l -q -b 'driverMC.C("GGJets","6000To8000","ADDPlots_GGJets_Mgg6000To8000.root","2015MC")'
elif [ $1 -eq 127 ]
then
    root -l -q -b 'driverMC.C("GGJets","8000To13000","ADDPlots_GGJets_Mgg8000To13000.root","2015MC")'
fi

