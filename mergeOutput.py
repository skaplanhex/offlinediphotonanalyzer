import os
from glob import glob

msvals = (3000,3500,4000,4500,5000,5500,6000,7000,8000,9000,10000,11000)
convs = ("GRW","HLZ","Hewett")

# merge signal+bkg
for conv in convs:
    for ms in msvals:
        if conv == "Hewett" and ms > 6000:
            continue
        cmd = "hadd ADD_Ms%i_sigbkg_%s.root ADDPlots_Ms%i*%s_20152016LUMI.root"%(ms,conv,ms,conv)
        print "Now issuing the command: %s"%cmd
        os.system(cmd)

# merge ADD subtraction bkg
os.system("hadd ADD_Bkg.root ADDPlots_ADDBkg*_20152016LUMI.root")

# merge GGJets
os.system("hadd GGJets_merged.root ADDPlots_GGJets*20152016LUMI.root")

# subtract ADD bkg from signal+bkg
for conv in convs:
    for ms in msvals:
        mergecmd = "./haddws/haddws ADD_Ms%i_sigbkg_%s.root ADD_Bkg.root 1.0 -1.0"%(ms,conv)
        newname = "ADD_Ms%i_signal_%s.root"%(ms,conv)
        os.system(mergecmd)
        os.system("mv result.root %s"%newname)