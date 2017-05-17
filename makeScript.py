# returns list of mass bins for signal with Ms >= 7 TeV
def getMassBins(ms):
    massBinDict  = {
        3000 : ["500To1000","1000To2000","2000To3000"],
        3500 : ["500To1000","1000To2000","2000To3500"],
        4000 : ["500To1000","1000To2000","2000To4000"],
        4500 : ["500To1000","1000To2000","2000To3000","3000To4500"],
        5000 : ["500To1000","1000To2000","2000To3000","3000To5000"],
        5500 : ["500To1000","1000To2000","2000To4000","4000To5500"],
        6000 : ["500To1000","1000To2000","2000To4000","4000To6000"]
    }

    for ms2 in (7000,8000,9000,10000,11000):
        massBinDict[ms2] = ["500To1000","1000To2000","2000To4000","4000To%i"%ms2]
    return massBinDict[ms]

ADDBkgMassBins = ["500To1000","1000To2000","2000To4000","4000To8000","8000To13000"]
GGJetsMassBins = ["60To200","200To500","500To1000","1000To2000","2000To4000","4000To6000","6000To8000","8000To13000"]
GJetsHTBins = ["40To100","100To200","200To400","400To600","600ToInf"]
QCDPtBins = ["5to10","10to15","15to30","30to50","50to80","80to120","120to170","170to300","300to470","470to600","600to800","800to1000","1000to1400","1400to1800","1800to2400","2400to3200","3200toInf"]

msValues = msValues = (3000,3500,4000,4500,5000,5500,6000,7000,8000,9000,10000,11000)

outfile = open("runMCPlots.sh",'w')
# outfile = open("test.sh",'w')

outfile.write("#! /bin/bash\n")
outfile.write("\n")
outfile.write("export SCRAM_ARCH=slc6_amd64_gcc493\n")
outfile.write("source /cvmfs/cms.cern.ch/cmsset_default.sh\n")
outfile.write("\n")
outfile.write("cd /uscms_data/d3/skaplan/diphotons/offlineanalysis/CMSSW_7_6_4/src\n")
outfile.write("eval `scramv1 runtime -sh`\n")
outfile.write("cd ${_CONDOR_SCRATCH_DIR}\n")
outfile.write("\n")
i=0
for ms in msValues:
    for conv in ("GRW","HLZ","Hewett"):
        for massBin in getMassBins(ms):
            if ms > 6000 and conv == "Hewett":
                continue
            word = "elif"
            if i==0:
                word="if"
            outfile.write("%s [ $1 -eq %i ]\n"%(word,i))
            outfile.write("then\n")
            msStr = '"%i_%s"'%(ms,conv)
            massBinStr = '"%s"'%massBin
            outfilename = '"ADDPlots_Ms%i_Mgg%s_%s.root"'%(ms,massBin,conv)
            rootArg = "'driverMC.C(%s,%s,%s,true)'"%(msStr,massBinStr,outfilename)
            outfile.write("    root -l -q -b %s\n"%rootArg)
            i += 1

for massBin in ADDBkgMassBins:

    word = "elif"
    outfile.write("%s [ $1 -eq %i ]\n"%(word,i))
    outfile.write("then\n")
    massBinStr = '"%s"'%massBin
    outfilename = '"ADDPlots_ADDBkg_Mgg%s.root"'%(massBin)
    rootArg = "'driverMC.C(%s,%s,%s,true)'"%('"ADDBkg"',massBinStr,outfilename)
    outfile.write("    root -l -q -b %s\n"%rootArg)
    i+=1

for massBin in GGJetsMassBins:

    word = "elif"
    outfile.write("%s [ $1 -eq %i ]\n"%(word,i))
    outfile.write("then\n")
    massBinStr = '"%s"'%massBin
    outfilename = '"ADDPlots_GGJets_Mgg%s.root"'%(massBin)
    rootArg = "'driverMC.C(%s,%s,%s,true)'"%('"GGJets"',massBinStr,outfilename)
    outfile.write("    root -l -q -b %s\n"%rootArg)
    i+=1

# for massBin in GJetsHTBins:

#     word = "elif"
#     outfile.write("%s [ $1 -eq %i ]\n"%(word,i))
#     outfile.write("then\n")
#     massBinStr = '"%s"'%massBin
#     outfilename = '"ADDPlots_GJets_HT%s.root"'%(massBin)
#     rootArg = "'driverADD.C(%s,%s,%s,true)'"%('"GJets"',massBinStr,outfilename)
#     outfile.write("    root -l -q -b %s\n"%rootArg)
#     i+=1

# for massBin in QCDPtBins:

#     word = "elif"
#     outfile.write("%s [ $1 -eq %i ]\n"%(word,i))
#     outfile.write("then\n")
#     massBinStr = '"%s"'%massBin
#     outfilename = '"ADDPlots_QCD_Pt%s.root"'%(massBin)
#     rootArg = "'driverADD.C(%s,%s,%s,true)'"%('"QCD"',massBinStr,outfilename)
#     outfile.write("    root -l -q -b %s\n"%rootArg)
#     i+=1   

outfile.write("fi\n")
outfile.write("\n")