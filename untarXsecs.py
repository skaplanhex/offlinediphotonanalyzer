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
    3500 : ["200To500","500To1000","2000To3500"], # no 1000-2000 bin for some reason??
    4000 : ["200To500","500To1000","1000To2000","2000To4000"],
    4500 : ["200To500","500To1000","1000To2000","2000To3000","3000To4500"],
    5000 : ["200To500","500To1000","1000To2000","2000To3000","3000To5000"],
    5500 : ["200To500","500To1000","1000To2000","2000To4000","4000To5500"],
    6000 : ["200To500","500To1000","1000To2000","2000To4000","4000To6000"],
}

bkgMassBins = ["200To500","500To1000","1000To2000","2000To4000","4000To8000","8000To13000"]

msValues = massBinDict.keys()

# this system of loops untars the log files for ADD Signal
# for ms in msValues:
#     for massBin in massBinDict[ms]:
#         procName = "ADDGravToGG_MS-%i_NED-4_KK-1_M-%s_13TeV-sherpa"%(ms,massBin)
#         direc = "ADDXsecs/%s/crab_%s/"%(procName,procName)
#         temp = glob(direc+"*")
#         dateDirec = temp[0].replace(direc,"")+"/"
#         # print direc+dateDirec
#         fullPath = direc+dateDirec+"0000/log/cmsRun_1.log.tar.gz"
#         cmd = "tar -xzvf %s -C %s"%(fullPath,fullPath.replace("cmsRun_1.log.tar.gz",""))
#         print cmd
#         os.system(cmd)

# for ADD background
# for massBin in bkgMassBins:
#     procName = "GG_M-%s_Pt-70_13TeV-sherpa"%(massBin)
#     direc = "ADDXsecs/%s/crab_%s/"%(procName,procName)
#     temp = glob(direc+"*")
#     dateDirec = temp[0].replace(direc,"")+"/"
#     # print direc+dateDirec
#     fullPath = direc+dateDirec+"0000/log/cmsRun_1.log.tar.gz"
#     cmd = "tar -xzvf %s -C %s"%(fullPath,fullPath.replace("cmsRun_1.log.tar.gz",""))
#     print cmd
#     os.system(cmd)

# this system of loops creates a text file with the cross sections
print "writing XS text file"
o = open("ADDXsecs_sherpa.txt",'w')
o.write("#modelpoint   massbin   XS(pb)   XSuncertainty(pb)\n")
for ms in msValues:
    for massBin in massBinDict[ms]:
        procName = "ADDGravToGG_MS-%i_NED-4_KK-1_M-%s_13TeV-sherpa"%(ms,massBin)
        direc = "ADDXsecs/%s/crab_%s/"%(procName,procName)
        temp = glob(direc+"*")
        dateDirec = temp[0].replace(direc,"")+"/"
        # print direc+dateDirec
        fullPath = direc+dateDirec+"0000/log/cmsRun-stdout-1.log"

        xs,uncert = getXSAndUncert(fullPath)
        line = "%i %s %s %s\n"%(ms,massBin,xs,uncert)
        o.write(line)

for massBin in bkgMassBins:
    procName = "GG_M-%s_Pt-70_13TeV-sherpa"%(massBin)
    direc = "ADDXsecs/%s/crab_%s/"%(procName,procName)
    temp = glob(direc+"*")
    dateDirec = temp[0].replace(direc,"")+"/"
    # print direc+dateDirec
    fullPath = direc+dateDirec+"0000/log/cmsRun-stdout-1.log"

    xs,uncert = getXSAndUncert(fullPath)
    line = "ADDbkg %s %s %s\n"%(massBin,xs,uncert)
    o.write(line)

o.close()












