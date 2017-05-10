#! /bin/bash

export SCRAM_ARCH=slc6_amd64_gcc493
source /cvmfs/cms.cern.ch/cmsset_default.sh

cd /uscms_data/d3/skaplan/diphotons/offlineanalysis/CMSSW_7_6_4/src
eval `scramv1 runtime -sh`
cd ${_CONDOR_SCRATCH_DIR}

unzip kFactorFits.zip

if [ $1 -eq 0 ]
then
    root -l -q -b 'driverMC.C("GGJets","60To200","ADDPlots_GGJets_Mgg60To200.root",true)'
elif [ $1 -eq 1 ]
then
    root -l -q -b 'driverMC.C("GGJets","200To500","ADDPlots_GGJets_Mgg200To500.root",true)'
elif [ $1 -eq 2 ]
then
    root -l -q -b 'driverMC.C("GGJets","500To1000","ADDPlots_GGJets_Mgg500To1000.root",true)'
elif [ $1 -eq 3 ]
then
    root -l -q -b 'driverMC.C("GGJets","1000To2000","ADDPlots_GGJets_Mgg1000To2000.root",true)'
elif [ $1 -eq 4 ]
then
    root -l -q -b 'driverMC.C("GGJets","2000To4000","ADDPlots_GGJets_Mgg2000To4000.root",true)'
elif [ $1 -eq 5 ]
then
    root -l -q -b 'driverMC.C("GGJets","4000To6000","ADDPlots_GGJets_Mgg4000To6000.root",true)'
elif [ $1 -eq 6 ]
then
    root -l -q -b 'driverMC.C("GGJets","6000To8000","ADDPlots_GGJets_Mgg6000To8000.root",true)'
elif [ $1 -eq 7 ]
then
    root -l -q -b 'driverMC.C("GGJets","8000To13000","ADDPlots_GGJets_Mgg8000To13000.root",true)'
fi

