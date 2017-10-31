#! /bin/bash

export SCRAM_ARCH=slc6_amd64_gcc493
source /cvmfs/cms.cern.ch/cmsset_default.sh

cd /uscms_data/d3/skaplan/diphotons/offlineanalysis2016/CMSSW_7_6_4/src
eval `scramv1 runtime -sh`
cd ${_CONDOR_SCRATCH_DIR}

root -l -q -b "driver_extractFakes.C($1)"
