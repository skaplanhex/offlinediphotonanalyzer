#! /bin/bash

export SCRAM_ARCH=slc6_amd64_gcc493
source /cvmfs/cms.cern.ch/cmsset_default.sh

cd /uscms_data/d3/skaplan/diphotons/offlineanalysis/CMSSW_7_6_4/src
eval `scramv1 runtime -sh`
cd ${_CONDOR_SCRATCH_DIR}

if [ $1 -eq 0 ]
then
    root -l -q -b 'driverADD.C("4000","200To500","ADDPlots_Ms4000_Mgg200To500.root",true)'
elif [ $1 -eq 1 ]
then
    root -l -q -b 'driverADD.C("4000","500To1000","ADDPlots_Ms4000_Mgg500To1000.root",true)'
elif [ $1 -eq 2 ]
then
    root -l -q -b 'driverADD.C("4000","1000To2000","ADDPlots_Ms4000_Mgg1000To2000.root",true)'
elif [ $1 -eq 3 ]
then
    root -l -q -b 'driverADD.C("4000","2000To4000","ADDPlots_Ms4000_Mgg2000To4000.root",true)'
elif [ $1 -eq 4 ]
then
    root -l -q -b 'driverADD.C("5000","200To500","ADDPlots_Ms5000_Mgg200To500.root",true)'
elif [ $1 -eq 5 ]
then
    root -l -q -b 'driverADD.C("5000","500To1000","ADDPlots_Ms5000_Mgg500To1000.root",true)'
elif [ $1 -eq 6 ]
then
    root -l -q -b 'driverADD.C("5000","1000To2000","ADDPlots_Ms5000_Mgg1000To2000.root",true)'
elif [ $1 -eq 7 ]
then
    root -l -q -b 'driverADD.C("5000","2000To3000","ADDPlots_Ms5000_Mgg2000To3000.root",true)'
elif [ $1 -eq 8 ]
then
    root -l -q -b 'driverADD.C("5000","3000To5000","ADDPlots_Ms5000_Mgg3000To5000.root",true)'
elif [ $1 -eq 9 ]
then
    root -l -q -b 'driverADD.C("3500","200To500","ADDPlots_Ms3500_Mgg200To500.root",true)'
elif [ $1 -eq 10 ]
then
    root -l -q -b 'driverADD.C("3500","500To1000","ADDPlots_Ms3500_Mgg500To1000.root",true)'
elif [ $1 -eq 11 ]
then
    root -l -q -b 'driverADD.C("3500","1000To2000","ADDPlots_Ms3500_Mgg1000To2000.root",true)'
elif [ $1 -eq 12 ]
then
    root -l -q -b 'driverADD.C("3500","2000To3500","ADDPlots_Ms3500_Mgg2000To3500.root",true)'
elif [ $1 -eq 13 ]
then
    root -l -q -b 'driverADD.C("6000","200To500","ADDPlots_Ms6000_Mgg200To500.root",true)'
elif [ $1 -eq 14 ]
then
    root -l -q -b 'driverADD.C("6000","500To1000","ADDPlots_Ms6000_Mgg500To1000.root",true)'
elif [ $1 -eq 15 ]
then
    root -l -q -b 'driverADD.C("6000","1000To2000","ADDPlots_Ms6000_Mgg1000To2000.root",true)'
elif [ $1 -eq 16 ]
then
    root -l -q -b 'driverADD.C("6000","2000To4000","ADDPlots_Ms6000_Mgg2000To4000.root",true)'
elif [ $1 -eq 17 ]
then
    root -l -q -b 'driverADD.C("6000","4000To6000","ADDPlots_Ms6000_Mgg4000To6000.root",true)'
elif [ $1 -eq 18 ]
then
    root -l -q -b 'driverADD.C("4500","200To500","ADDPlots_Ms4500_Mgg200To500.root",true)'
elif [ $1 -eq 19 ]
then
    root -l -q -b 'driverADD.C("4500","500To1000","ADDPlots_Ms4500_Mgg500To1000.root",true)'
elif [ $1 -eq 20 ]
then
    root -l -q -b 'driverADD.C("4500","1000To2000","ADDPlots_Ms4500_Mgg1000To2000.root",true)'
elif [ $1 -eq 21 ]
then
    root -l -q -b 'driverADD.C("4500","2000To3000","ADDPlots_Ms4500_Mgg2000To3000.root",true)'
elif [ $1 -eq 22 ]
then
    root -l -q -b 'driverADD.C("4500","3000To4500","ADDPlots_Ms4500_Mgg3000To4500.root",true)'
elif [ $1 -eq 23 ]
then
    root -l -q -b 'driverADD.C("3000","200To500","ADDPlots_Ms3000_Mgg200To500.root",true)'
elif [ $1 -eq 24 ]
then
    root -l -q -b 'driverADD.C("3000","500To1000","ADDPlots_Ms3000_Mgg500To1000.root",true)'
elif [ $1 -eq 25 ]
then
    root -l -q -b 'driverADD.C("3000","1000To2000","ADDPlots_Ms3000_Mgg1000To2000.root",true)'
elif [ $1 -eq 26 ]
then
    root -l -q -b 'driverADD.C("3000","2000To3000","ADDPlots_Ms3000_Mgg2000To3000.root",true)'
elif [ $1 -eq 27 ]
then
    root -l -q -b 'driverADD.C("5500","200To500","ADDPlots_Ms5500_Mgg200To500.root",true)'
elif [ $1 -eq 28 ]
then
    root -l -q -b 'driverADD.C("5500","500To1000","ADDPlots_Ms5500_Mgg500To1000.root",true)'
elif [ $1 -eq 29 ]
then
    root -l -q -b 'driverADD.C("5500","1000To2000","ADDPlots_Ms5500_Mgg1000To2000.root",true)'
elif [ $1 -eq 30 ]
then
    root -l -q -b 'driverADD.C("5500","2000To4000","ADDPlots_Ms5500_Mgg2000To4000.root",true)'
elif [ $1 -eq 31 ]
then
    root -l -q -b 'driverADD.C("5500","4000To5500","ADDPlots_Ms5500_Mgg4000To5500.root",true)'
elif [ $1 -eq 32 ]
then
    root -l -q -b 'driverADD.C("ADDBkg","200To500","ADDPlots_ADDBkg_Mgg200To500.root",true)'
elif [ $1 -eq 33 ]
then
    root -l -q -b 'driverADD.C("ADDBkg","500To1000","ADDPlots_ADDBkg_Mgg500To1000.root",true)'
elif [ $1 -eq 34 ]
then
    root -l -q -b 'driverADD.C("ADDBkg","1000To2000","ADDPlots_ADDBkg_Mgg1000To2000.root",true)'
elif [ $1 -eq 35 ]
then
    root -l -q -b 'driverADD.C("ADDBkg","2000To4000","ADDPlots_ADDBkg_Mgg2000To4000.root",true)'
elif [ $1 -eq 36 ]
then
    root -l -q -b 'driverADD.C("ADDBkg","4000To8000","ADDPlots_ADDBkg_Mgg4000To8000.root",true)'
elif [ $1 -eq 37 ]
then
    root -l -q -b 'driverADD.C("ADDBkg","8000To13000","ADDPlots_ADDBkg_Mgg8000To13000.root",true)'
fi

