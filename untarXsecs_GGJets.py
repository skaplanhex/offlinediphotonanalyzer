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

bkgMassBins = ["60To200","200To500","500To1000","1000To2000","2000To4000","4000To6000","6000To8000","8000To13000"]

# first untar the files
# for massBin in bkgMassBins:
#     procName = "GGJets_M-%s_Pt-50_13TeV-sherpa"%massBin
#     direc = "GGJetsXsecs/%s/crab_%s_76X_AOD/"%(procName,procName)
#     temp = glob(direc+"*")
#     dateDirec = temp[0].replace(direc,"")+"/"
#     # print direc+dateDirec
#     fullPath = direc+dateDirec+"0000/log/cmsRun_1.log.tar.gz"
#     cmd = "tar -xzvf %s -C %s"%(fullPath,fullPath.replace("cmsRun_1.log.tar.gz",""))
#     print cmd
#     os.system(cmd)

# this system of loops creates a text file with the cross sections
print "writing XS text file"
o = open("GGJetsXsecs_sherpa.txt",'w')
o.write("massbin   XS(pb)   XSuncertainty(pb)\n")

for massBin in bkgMassBins:
    procName = "GGJets_M-%s_Pt-50_13TeV-sherpa"%massBin
    direc = "GGJetsXsecs/%s/crab_%s_76X_AOD/"%(procName,procName)
    temp = glob(direc+"*")
    dateDirec = temp[0].replace(direc,"")+"/"
    # print direc+dateDirec
    fullPath = direc+dateDirec+"0000/log/cmsRun-stdout-1.log"

    xs,uncert = getXSAndUncert(fullPath)
    line = "%s %s %s\n"%(massBin,xs,uncert)
    o.write(line)

o.close()












