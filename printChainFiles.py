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

# returns list of mass bins for signal with Ms >= 7 TeV
def getMassBins(ms):
    massBinDict  = {
        3000 : ["500To1000","1000To2000","2000To3000"],
        3500 : ["500To1000","1000To2000","2000To3500"],
        4000 : ["500To1000","1000To2000","2000To4000"],
        4500 : ["500To1000","1000To2000","2000To3000","3000To4500"],
        5000 : ["500To1000","1000To2000","2000To3000","3000To5000"],
        5500 : ["500To1000","1000To2000","2000To4000","4000To5500"],
        6000 : ["500To1000","1000To2000","2000To4000","4000To6000"],
    }
    if ms in massBinDict.keys():
        return massBinDict[ms]
    else:
        return ["500To1000","1000To2000","2000To4000","4000To%i"%ms]


msValues = (3000,3500,4000,4500,5000,5500,6000,7000,8000,9000,10000,11000)

ADDBkgMassBins = ["500To1000","1000To2000","2000To4000","4000To8000","8000To13000"]
GGJetsMassBins = ["60To200","200To500","500To1000","1000To2000","2000To4000","4000To6000","6000To8000","8000To13000"]
GJetsHTBins = ["40To100","100To200","200To400","400To600","600ToInf"]
QCDPtBins = ["5to10","10to15","15to30","30to50","50to80","80to120","120to170","170to300","300to470","470to600","600to800","800to1000","1000to1400","1400to1800","1800to2400","2400to3200","3200toInf"]

# baseDirec = "/store/user/skaplan/noreplica/NewCodeNtuples_correctGENinfo/"
baseDirec = "/store/user/skaplan/noreplica/FINALNTUPLES/"

kkDict = {
    "NED-4_KK-1" : "GRW",
    "NED-2_KK-1" : "HLZ",
    "NED-2_KK-4" : "Hewett"
}

# Signal
for ms in msValues:
    for kk in kkDict.keys():
        for massBin in getMassBins(ms):
            # print ms,kk,massBin
            # no hewett samples beyond Ms =6 TeV
            if ms > 6000 and kkDict[kk] == "Hewett":
                continue
            procName = "ADDGravToGG_MS-%i_%s_M-%s_13TeV-sherpa"%(ms,kk,massBin)
            direc = "/eos/uscms"+baseDirec+"%s/crab_%s__80XMiniAODv2__MINIAODSIM/"%(procName,procName)
            temp = glob(direc+"*")
            dateDirec = temp[0].replace(direc,"")+"/"
            # print direc+dateDirec
            fullPath = direc+dateDirec+"0000/"
            temp = glob(fullPath+"*root")
            files = []
            for f in temp:
                files.append( f.replace("/eos/uscms","root://cmseos.fnal.gov/") )
            msStr = "%i_%s"%( ms,kkDict[kk] )
            print 'else if ( ms.EqualTo("%s") && massBin.EqualTo("%s") ){'%(msStr,massBin)
            for f in files:
                print '  chain->Add("%s",0);'%f
            print "}"

# ADD bkg subtraction
for massBin in ADDBkgMassBins:
    procName = "GG_M-%s_Pt-70_13TeV-sherpa"%massBin
    # baseDirec = "/store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/"
    # baseDirec = "/store/user/skaplan/noreplica/NewCodeNtuples/"
    direc = "/eos/uscms"+baseDirec+"%s/crab_%s__80XMiniAODv2__MINIAODSIM/"%(procName,procName)
    # direc = "ADDXsecs/%s/crab_%s/"%(procName,procName)
    temp = glob(direc+"*")
    dateDirec = temp[0].replace(direc,"")+"/"
    # print direc+dateDirec
    fullPath = direc+dateDirec+"0000/"
    temp = glob(fullPath+"*root")
    files = []
    for f in temp:
        files.append( f.replace("/eos/uscms","root://cmseos.fnal.gov/") )
    # print "%s %s"%(ms,massBin)
    print 'else if ( ms.EqualTo("ADDBkg") && massBin.EqualTo("%s") ){'%(massBin)
    for f in files:
        print '  chain->Add("%s",0);'%f
    print "}"

# sherpa diphoton
for massBin in GGJetsMassBins:
    procName = "GGJets_M-%s_Pt-50_13TeV-sherpa"%massBin
    # baseDirec = "/store/user/skaplan/noreplica/NewCodeNtuples/"
    direc = glob( "/eos/uscms%s%s/*"%(baseDirec,procName) )[0] + "/"
    temp = glob(direc+"*")
    dateDirec = temp[0].replace(direc,"")+"/"
    # print direc+dateDirec
    fullPath = direc+dateDirec+"0000/"
    temp = glob(fullPath+"*root")
    files = []
    for f in temp:
        files.append( f.replace("/eos/uscms","root://cmseos.fnal.gov/") )
    # print "%s %s"%(ms,massBin)
    print 'else if ( ms.EqualTo("GGJets") && massBin.EqualTo("%s") ){'%(massBin)
    for f in files:
        print '  chain->Add("%s",0);'%f
    print "}"

# # GRW
# for ms in msValues:
#     for massBin in massBinDict[ms]:
#         procName = "ADDGravToGG_MS-%i_NED-4_KK-1_M-%s_13TeV-sherpa"%(ms,massBin)
#         # baseDirec = "/store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/"
#         # baseDirec = "/store/user/skaplan/noreplica/NewCodeNtuples/"
#         direc = "/eos/uscms"+baseDirec+"%s/crab_%s/"%(procName,procName)
#         # direc = "ADDXsecs/%s/crab_%s/"%(procName,procName)
#         temp = glob(direc+"*")
#         dateDirec = temp[0].replace(direc,"")+"/"
#         # print direc+dateDirec
#         fullPath = direc+dateDirec+"0000/"
#         temp = glob(fullPath+"*root")
#         files = []
#         for f in temp:
#             files.append( f.replace("/eos/uscms","root://cmseos.fnal.gov/") )
#         msStr = "%i_GRW"%ms
#         print 'else if ( ms.EqualTo("%s") && massBin.EqualTo("%s") ){'%(msStr,massBin)
#         for f in files:
#             print '  chain->Add("%s",0);'%f
#         print "}"

# # HLZ
# for ms in msValues:
#     for massBin in massBinDict[ms]:
#         procName = "ADDGravToGG_MS-%i_NED-2_KK-1_M-%s_13TeV-sherpa"%(ms,massBin)
#         # baseDirec = "/store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/"
#         # baseDirec = "/store/user/skaplan/noreplica/NewCodeNtuples/"
#         direc = "/eos/uscms"+baseDirec+"%s/crab_%s/"%(procName,procName)
#         # direc = "ADDXsecs/%s/crab_%s/"%(procName,procName)
#         temp = glob(direc+"*")
#         dateDirec = temp[0].replace(direc,"")+"/"
#         # print direc+dateDirec
#         fullPath = direc+dateDirec+"0000/"
#         temp = glob(fullPath+"*root")
#         files = []
#         for f in temp:
#             files.append( f.replace("/eos/uscms","root://cmseos.fnal.gov/") )
#         msStr = "%i_HLZ"%ms
#         print 'else if ( ms.EqualTo("%s") && massBin.EqualTo("%s") ){'%(msStr,massBin)
#         for f in files:
#             print '  chain->Add("%s",0);'%f
#         print "}"

# # Hewett
# for ms in msValues:
#     for massBin in massBinDict[ms]:
#         procName = "ADDGravToGG_MS-%i_NED-2_KK-4_M-%s_13TeV-sherpa"%(ms,massBin)
#         # baseDirec = "/store/user/skaplan/noreplica/ExoDiPhotonNtuples/ADD/"
#         # baseDirec = "/store/user/skaplan/noreplica/NewCodeNtuples/"
#         direc = "/eos/uscms"+baseDirec+"%s/crab_%s/"%(procName,procName)
#         # direc = "ADDXsecs/%s/crab_%s/"%(procName,procName)
#         temp = glob(direc+"*")
#         dateDirec = temp[0].replace(direc,"")+"/"
#         # print direc+dateDirec
#         fullPath = direc+dateDirec+"0000/"
#         temp = glob(fullPath+"*root")
#         files = []
#         for f in temp:
#             files.append( f.replace("/eos/uscms","root://cmseos.fnal.gov/") )
#         msStr = "%i_Hewett"%ms
#         print 'else if ( ms.EqualTo("%s") && massBin.EqualTo("%s") ){'%(msStr,massBin)
#         for f in files:
#             print '  chain->Add("%s",0);'%f
#         print "}"


# for massBin in GJetsHTBins:
#     procName = "GJets_HT-%s_TuneCUETP8M1_13TeV-madgraphMLM-pythia8"%massBin
#     crabName = "crab_"+procName
#     baseDirec = "/store/user/skaplan/noreplica/NewCodeNtuples/"
#     direc = "/eos/uscms"+baseDirec+"%s/%s/"%(procName,crabName)
#     temp = glob(direc+"*")
#     dateDirec = temp[0].replace(direc,"")+"/"
#     fullPath = direc+dateDirec+"0000/"
#     temp = glob(fullPath+"GJets*root")
#     files = []
#     for f in temp:
#         files.append( f.replace("/eos/uscms","root://cmseos.fnal.gov/") )
#     # print "%s %s"%(ms,massBin)
#     print 'else if ( ms.EqualTo("GJets") && massBin.EqualTo("%s") ){'%(massBin)
#     for f in files:
#         print '  chain->Add("%s",0);'%f
#     print "}"

# for massBin in QCDPtBins:
#     procName = "QCD_Pt_%s_TuneCUETP8M1_13TeV_pythia8"%massBin
#     crabName = "crab_"+procName
#     baseDirec = "/store/user/skaplan/noreplica/NewCodeNtuples/"
#     direc = "/eos/uscms"+baseDirec+"%s/%s/"%(procName,crabName)
#     temp = glob(direc+"*")
#     dateDirec = temp[0].replace(direc,"")+"/"
#     fullPath = direc+dateDirec+"0000/"
#     temp = glob(fullPath+"QCD*root")
#     files = []
#     for f in temp:
#         files.append( f.replace("/eos/uscms","root://cmseos.fnal.gov/") )
#     # print "%s %s"%(ms,massBin)
#     print 'else if ( ms.EqualTo("QCD") && massBin.EqualTo("%s") ){'%(massBin)
#     for f in files:
#         print '  chain->Add("%s",0);'%f
#     print "}"












