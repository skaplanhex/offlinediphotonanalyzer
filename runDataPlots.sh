#! /bin/bash

export SCRAM_ARCH=slc6_amd64_gcc493
source /cvmfs/cms.cern.ch/cmsset_default.sh
export SCRAM_ARCH=slc6_amd64_gcc493
eval `scramv1 project CMSSW CMSSW_7_6_4`
cd CMSSW_7_6_4/src/
eval `scramv1 runtime -sh` # cmsenv is an alias not on the workers
echo "CMSSW: "$CMSSW_BASE


cd ${_CONDOR_SCRATCH_DIR}

root -l -q -b "driverData.C($1)"
