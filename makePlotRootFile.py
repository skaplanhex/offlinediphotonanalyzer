print "Loading ROOT..."
from ROOT import *
import distroConcatenator as dc
print "done."

XSdict={}
xsfile = open("ADDXsecs_sherpa.txt",'r')
for line in xsfile:
    s = line.split()
    if len(s)<2:
        continue
    if s[0] == "model":
        continue
    tempKey = "%s %s"%(s[0],s[1])
    tempValue = float(s[2])
    XSdict[tempKey] = tempValue

NEventsDict={}
neventsfile = open("ADD_nevents.txt",'r')
for line in neventsfile:
    s = line.split()
    if len(s)<2:
        continue
    tempKey = "%s %s"%(s[0],s[1])
    tempValue = float(s[2])
    NEventsDict[tempKey] = tempValue

def getXS(mgg,ms):
    tempKey = "%s %s"%(str(ms),mgg)
    return XSdict[tempKey]
def getNEvents(mgg,ms):
    tempKey = "%s %s"%(str(ms),mgg)
    return NEventsDict[tempKey]

## this file will load the output of fTree.C for all bins, merge and normalize to LUMI, then write it to another root file.  Another script will take that root file and make pretty plots, etc.

def getFileName(mgg,ms="ADDBkg"):
    if ms == "ADDBkg":
        return "ADDPlots_ADDBkg_Mgg%s.root"%(mgg)
    else:
        return "ADDPlots_Ms%s_Mgg%s.root"%(str(ms),mgg) #cast ms as string in case of signal

massBinDict  = {
    3000 : ["200To500","500To1000","1000To2000","2000To3000"],
    3500 : ["200To500","500To1000","1000To2000","2000To3500"],
    4000 : ["200To500","500To1000","1000To2000","2000To4000"],
    4500 : ["200To500","500To1000","1000To2000","2000To3000","3000To4500"],
    5000 : ["200To500","500To1000","1000To2000","2000To3000","3000To5000"],
    5500 : ["200To500","500To1000","1000To2000","2000To4000","4000To5500"],
    6000 : ["200To500","500To1000","1000To2000","2000To4000","4000To6000"],
    "ADDBkg" : ["200To500","500To1000","1000To2000","2000To4000","4000To8000","8000To13000"]
}

bkgMassBins = ["200To500","500To1000","1000To2000","2000To4000","4000To8000","8000To13000"]

msValues = massBinDict.keys()

modelPoints = []
for ms in msValues:
    modelPoints.append(ms)
modelPoints.append("ADDBkg")

LUMI = (2.6+12.9)*1000. #/pb
outfile = TFile("ADDMergedHistos_witherrorbars.root","recreate")

for ms in modelPoints:
    infos_EBEB=[]
    infos_EBEB_varbin=[]
    infos_EBEB_30003500varbin = []
    infos_EBEE=[]
    infos_EBEE_varbin=[]
    infos_EBEE_30003500varbin = []
    for massBin in massBinDict[ms]:
        currentFileName = getFileName(massBin,ms)
        xs = getXS(massBin,ms)
        nevents = getNEvents(massBin,ms)
        print currentFileName,xs,nevents
        infos_EBEB.append( [currentFileName,"ggMass_EBEB",xs,nevents] )
        infos_EBEB_varbin.append( [currentFileName,"ggMass_EBEB_varbin",xs,nevents] )
        infos_EBEB_30003500varbin.append( [currentFileName,"ggMass_EBEB_30003500varbin",xs,nevents] )
        infos_EBEE.append( [currentFileName,"ggMass_EBEE",xs,nevents] )
        infos_EBEE_varbin.append( [currentFileName,"ggMass_EBEE_varbin",xs,nevents] )
        infos_EBEE_30003500varbin.append( [currentFileName,"ggMass_EBEE_30003500varbin",xs,nevents] )
    word = "Ms%s"%ms
    if ms == "ADDBkg":
        word = "ADDBkg"
    hist_EBEB=dc.concatenate(infos_EBEB,"ggMass_%s_EBEB"%word,LUMI)
    hist_EBEB_varbin=dc.concatenate(infos_EBEB_varbin,"ggMass_%s_EBEB_varbin"%word,LUMI)
    hist_EBEB_30003500varbin = dc.concatenate(infos_EBEB_30003500varbin,"ggMass_%s_EBEB_30003500varbin"%word,LUMI)
    hist_EBEE=dc.concatenate(infos_EBEE,"ggMass_%s_EBEE"%word,LUMI)
    hist_EBEE_varbin=dc.concatenate(infos_EBEE_varbin,"ggMass_%s_EBEE_varbin"%word,LUMI)
    hist_EBEE_30003500varbin = dc.concatenate(infos_EBEE_30003500varbin,"ggMass_%s_EBEE_30003500varbin"%word,LUMI)

    outfile.cd()
    hist_EBEB.Write()
    hist_EBEB_varbin.Write()
    hist_EBEB_30003500varbin.Write()
    hist_EBEE.Write()
    hist_EBEE_varbin.Write()
    hist_EBEE_30003500varbin.Write()
outfile.Close()














