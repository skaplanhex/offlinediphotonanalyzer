#! /bin/bash

root -l -q 'driver.C("GGJets_M-60To200_Pt-50_13TeV-sherpa.root")'
mv dataplots2.root GGJets_M-60To200_plots.root

root -l -q 'driver.C("GGJets_M-200To500_Pt-50_13TeV-sherpa.root")'
mv dataplots2.root GGJets_M-200To500_plots.root

root -l -q 'driver.C("GGJets_M-500To1000_Pt-50_13TeV-sherpa.root")'
mv dataplots2.root GGJets_M-500To1000_plots.root

root -l -q 'driver.C("GGJets_M-1000To2000_Pt-50_13TeV-sherpa.root")'
mv dataplots2.root GGJets_M-1000To2000_plots.root

root -l -q 'driver.C("GGJets_M-2000To4000_Pt-50_13TeV-sherpa.root")'
mv dataplots2.root GGJets_M-2000To4000_plots.root

root -l -q 'driver.C("GGJets_M-4000To6000_Pt-50_13TeV-sherpa.root")'
mv dataplots2.root GGJets_M-4000To6000_plots.root

root -l -q 'driver.C("GGJets_M-6000To8000_Pt-50_13TeV-sherpa.root")'
mv dataplots2.root GGJets_M-6000To8000_plots.root

root -l -q 'driver.C("GGJets_M-8000To13000_Pt-50_13TeV-sherpa.root")'
mv dataplots2.root GGJets_M-8000To13000_plots.root