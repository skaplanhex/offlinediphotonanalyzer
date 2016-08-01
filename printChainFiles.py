import os
from glob import glob

#returns string representations of the XS and uncertainty
def getXSAndUncert(filepath):
    f = open(filepath,'r')
    for line in f:
        s = line.split()
        if len(s) < 9:
            continue
        elif s[0] == "Before" and s[1] == "Filtrer:": #found the XS!
            xs = s[6]
            uncert = s[8]
            return (xs,uncert)

massBinDict  = {
    3000 : ["200To500","500To1000","1000To2000","2000To3000"],
    3500 : ["200To500","500To1000","1000To2000","2000To3500"],
    4000 : ["200To500","500To1000","1000To2000","2000To4000"],
    4500 : ["200To500","500To1000","1000To2000","2000To3000","3000To4500"],
    5000 : ["200To500","500To1000","1000To2000","2000To3000","3000To5000"],
    5500 : ["200To500","500To1000","1000To2000","2000To4000","4000To5500"],
    6000 : ["200To500","500To1000","1000To2000","2000To4000","4000To6000"],
}

ADDBkgMassBins = ["200To500","500To1000","1000To2000","2000To4000","4000To8000","8000To13000"]
GGJetsMassBins = ["60To200","200To500","500To1000","1000To2000","2000To4000","4000To6000","6000To8000","8000To13000"]

msValues = massBinDict.keys()


# this system of loops creates a text file with the cross sections
for ms in msValues:
    for massBin in massBinDict[ms]:
        procName = "ADDGravToGG_MS-%i_NED-4_KK-1_M-%s_13TeV-sherpa"%(ms,massBin)
        baseDirec = "/store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/"
        direc = "/eos/uscms"+baseDirec+"%s/crab_%s/"%(procName,procName)
        # direc = "ADDXsecs/%s/crab_%s/"%(procName,procName)
        temp = glob(direc+"*")
        dateDirec = temp[0].replace(direc,"")+"/"
        # print direc+dateDirec
        fullPath = direc+dateDirec+"0000/"
        temp = glob(fullPath+"Exo*root")
        files = []
        for f in temp:
            files.append( f.replace("/eos/uscms","root://cmseos.fnal.gov/") )
        # print "%s %s"%(ms,massBin)
        print 'else if ( ms.EqualTo("%i") && massBin.EqualTo("%s") ){'%(ms,massBin)
        for f in files:
            print '  chain->Add("%s",0);'%f
        print "}"

for massBin in ADDBkgMassBins:
    procName = "GG_M-%s_Pt-70_13TeV-sherpa"%massBin
    baseDirec = "/store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/"
    direc = "/eos/uscms"+baseDirec+"%s/crab_%s/"%(procName,procName)
    # direc = "ADDXsecs/%s/crab_%s/"%(procName,procName)
    temp = glob(direc+"*")
    dateDirec = temp[0].replace(direc,"")+"/"
    # print direc+dateDirec
    fullPath = direc+dateDirec+"0000/"
    temp = glob(fullPath+"Exo*root")
    files = []
    for f in temp:
        files.append( f.replace("/eos/uscms","root://cmseos.fnal.gov/") )
    # print "%s %s"%(ms,massBin)
    print 'else if ( ms.EqualTo("ADDBkg") && massBin.EqualTo("%s") ){'%(massBin)
    for f in files:
        print '  chain->Add("%s",0);'%f
    print "}"

for massBin in GGJetsMassBins:
    procName = "GGJets_M-%s_Pt-50_13TeV-sherpa"%massBin
    crabName = "crab_GGJets_M-%s_Pt-50"%massBin
    baseDirec = "/store/user/skaplan/noreplica/ExoDiPhotonNtuples/GGJets/"
    direc = "/eos/uscms"+baseDirec+"%s/%s/"%(procName,crabName)
    # direc = "ADDXsecs/%s/crab_%s/"%(procName,procName)
    temp = glob(direc+"*")
    dateDirec = temp[0].replace(direc,"")+"/"
    # print direc+dateDirec
    fullPath = direc+dateDirec+"0000/"
    temp = glob(fullPath+"Exo*root")
    files = []
    for f in temp:
        files.append( f.replace("/eos/uscms","root://cmseos.fnal.gov/") )
    # print "%s %s"%(ms,massBin)
    print 'else if ( ms.EqualTo("GGJets") && massBin.EqualTo("%s") ){'%(massBin)
    for f in files:
        print '  chain->Add("%s",0);'%f
    print "}"













