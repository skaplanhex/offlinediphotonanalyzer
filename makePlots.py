import distroConcatenator as dc
from ROOT import *

LUMI = 2.6 #/fb
# sherpa bkg

info60To200_EBEB = ["GGJets_M-60To200_plots.root","ggMass_EBEB",5728.,998353]
info200To500_EBEB = ["GGJets_M-200To500_plots.root","ggMass_EBEB",2214.,2342767]
info500To1000_EBEB = ["GGJets_M-500To1000_plots.root","ggMass_EBEB",151.4,999011]
info1000To2000_EBEB = ["GGJets_M-1000To2000_plots.root","ggMass_EBEB",11.54,599061]
info2000To4000_EBEB = ["GGJets_M-2000To4000_plots.root","ggMass_EBEB",0.3794,299207]
info4000To6000_EBEB = ["GGJets_M-4000To6000_plots.root","ggMass_EBEB",0.002406,297476]
info6000To8000_EBEB = ["GGJets_M-6000To8000_plots.root","ggMass_EBEB",1.879e-5,248234]
info8000To13000_EBEB = ["GGJets_M-8000To13000_plots.root","ggMass_EBEB",7.291e-8,199879]
infos_EBEB = [info60To200_EBEB,info200To500_EBEB,info500To1000_EBEB,info1000To2000_EBEB,info2000To4000_EBEB,info4000To6000_EBEB,info6000To8000_EBEB,info8000To13000_EBEB]
hist_EBEB = dc.concatenate(infos_EBEB,"mgg_EBEB",LUMI)

info60To200_EBEE = ["GGJets_M-60To200_plots.root","ggMass_EBEE",5728.,998353]
info200To500_EBEE = ["GGJets_M-200To500_plots.root","ggMass_EBEE",2214.,2342767]
info500To1000_EBEE = ["GGJets_M-500To1000_plots.root","ggMass_EBEE",151.4,999011]
info1000To2000_EBEE = ["GGJets_M-1000To2000_plots.root","ggMass_EBEE",11.54,599061]
info2000To4000_EBEE = ["GGJets_M-2000To4000_plots.root","ggMass_EBEE",0.3794,299207]
info4000To6000_EBEE = ["GGJets_M-4000To6000_plots.root","ggMass_EBEE",0.002406,297476]
info6000To8000_EBEE = ["GGJets_M-6000To8000_plots.root","ggMass_EBEE",1.879e-5,248234]
info8000To13000_EBEE = ["GGJets_M-8000To13000_plots.root","ggMass_EBEE",7.291e-8,199879]
infos_EBEE = [info60To200_EBEE,info200To500_EBEE,info500To1000_EBEE,info1000To2000_EBEE,info2000To4000_EBEE,info4000To6000_EBEE,info6000To8000_EBEE,info8000To13000_EBEE]
hist_EBEE = dc.concatenate(infos_EBEE,"mgg_EBEE",LUMI)

info60To200_30003500varbin_EBEB = ["GGJets_M-60To200_plots.root","ggMass_EBEB_30003500varbin",5728.,998353]
info200To500_30003500varbin_EBEB = ["GGJets_M-200To500_plots.root","ggMass_EBEB_30003500varbin",2214.,2342767]
info500To1000_30003500varbin_EBEB = ["GGJets_M-500To1000_plots.root","ggMass_EBEB_30003500varbin",151.4,999011]
info1000To2000_30003500varbin_EBEB = ["GGJets_M-1000To2000_plots.root","ggMass_EBEB_30003500varbin",11.54,599061]
info2000To4000_30003500varbin_EBEB = ["GGJets_M-2000To4000_plots.root","ggMass_EBEB_30003500varbin",0.3794,299207]
info4000To6000_30003500varbin_EBEB = ["GGJets_M-4000To6000_plots.root","ggMass_EBEB_30003500varbin",0.002406,297476]
info6000To8000_30003500varbin_EBEB = ["GGJets_M-6000To8000_plots.root","ggMass_EBEB_30003500varbin",1.879e-5,248234]
info8000To13000_30003500varbin_EBEB = ["GGJets_M-8000To13000_plots.root","ggMass_EBEB_30003500varbin",7.291e-8,199879]
infos_30003500varbin_EBEB = [info60To200_30003500varbin_EBEB,info200To500_30003500varbin_EBEB,info500To1000_30003500varbin_EBEB,info1000To2000_30003500varbin_EBEB,info2000To4000_30003500varbin_EBEB,info4000To6000_30003500varbin_EBEB,info6000To8000_30003500varbin_EBEB,info8000To13000_30003500varbin_EBEB]
hist_30003500varbin_EBEB = dc.concatenate(infos_30003500varbin_EBEB,"mgg_30003500varbin_EBEB",LUMI)

info60To200_30003500varbin_EBEE = ["GGJets_M-60To200_plots.root","ggMass_EBEE_30003500varbin",5728.,998353]
info200To500_30003500varbin_EBEE = ["GGJets_M-200To500_plots.root","ggMass_EBEE_30003500varbin",2214.,2342767]
info500To1000_30003500varbin_EBEE = ["GGJets_M-500To1000_plots.root","ggMass_EBEE_30003500varbin",151.4,999011]
info1000To2000_30003500varbin_EBEE = ["GGJets_M-1000To2000_plots.root","ggMass_EBEE_30003500varbin",11.54,599061]
info2000To4000_30003500varbin_EBEE = ["GGJets_M-2000To4000_plots.root","ggMass_EBEE_30003500varbin",0.3794,299207]
info4000To6000_30003500varbin_EBEE = ["GGJets_M-4000To6000_plots.root","ggMass_EBEE_30003500varbin",0.002406,297476]
info6000To8000_30003500varbin_EBEE = ["GGJets_M-6000To8000_plots.root","ggMass_EBEE_30003500varbin",1.879e-5,248234]
info8000To13000_30003500varbin_EBEE = ["GGJets_M-8000To13000_plots.root","ggMass_EBEE_30003500varbin",7.291e-8,199879]
infos_30003500varbin_EBEE = [info60To200_30003500varbin_EBEE,info200To500_30003500varbin_EBEE,info500To1000_30003500varbin_EBEE,info1000To2000_30003500varbin_EBEE,info2000To4000_30003500varbin_EBEE,info4000To6000_30003500varbin_EBEE,info6000To8000_30003500varbin_EBEE,info8000To13000_30003500varbin_EBEE]
hist_30003500varbin_EBEE = dc.concatenate(infos_30003500varbin_EBEE,"mgg_30003500varbin_EBEE",LUMI)

info60To200_varbin_EBEB = ["GGJets_M-60To200_plots.root","ggMass_EBEB_varbin",5728.,998353]
info200To500_varbin_EBEB = ["GGJets_M-200To500_plots.root","ggMass_EBEB_varbin",2214.,2342767]
info500To1000_varbin_EBEB = ["GGJets_M-500To1000_plots.root","ggMass_EBEB_varbin",151.4,999011]
info1000To2000_varbin_EBEB = ["GGJets_M-1000To2000_plots.root","ggMass_EBEB_varbin",11.54,599061]
info2000To4000_varbin_EBEB = ["GGJets_M-2000To4000_plots.root","ggMass_EBEB_varbin",0.3794,299207]
info4000To6000_varbin_EBEB = ["GGJets_M-4000To6000_plots.root","ggMass_EBEB_varbin",0.002406,297476]
info6000To8000_varbin_EBEB = ["GGJets_M-6000To8000_plots.root","ggMass_EBEB_varbin",1.879e-5,248234]
info8000To13000_varbin_EBEB = ["GGJets_M-8000To13000_plots.root","ggMass_EBEB_varbin",7.291e-8,199879]
infos_varbin_EBEB = [info60To200_varbin_EBEB,info200To500_varbin_EBEB,info500To1000_varbin_EBEB,info1000To2000_varbin_EBEB,info2000To4000_varbin_EBEB,info4000To6000_varbin_EBEB,info6000To8000_varbin_EBEB,info8000To13000_varbin_EBEB]
hist_varbin_EBEB = dc.concatenate(infos_varbin_EBEB,"mgg_varbin_EBEB",LUMI)

info60To200_varbin_EBEE = ["GGJets_M-60To200_plots.root","ggMass_EBEE_varbin",5728.,998353]
info200To500_varbin_EBEE = ["GGJets_M-200To500_plots.root","ggMass_EBEE_varbin",2214.,2342767]
info500To1000_varbin_EBEE = ["GGJets_M-500To1000_plots.root","ggMass_EBEE_varbin",151.4,999011]
info1000To2000_varbin_EBEE = ["GGJets_M-1000To2000_plots.root","ggMass_EBEE_varbin",11.54,599061]
info2000To4000_varbin_EBEE = ["GGJets_M-2000To4000_plots.root","ggMass_EBEE_varbin",0.3794,299207]
info4000To6000_varbin_EBEE = ["GGJets_M-4000To6000_plots.root","ggMass_EBEE_varbin",0.002406,297476]
info6000To8000_varbin_EBEE = ["GGJets_M-6000To8000_plots.root","ggMass_EBEE_varbin",1.879e-5,248234]
info8000To13000_varbin_EBEE = ["GGJets_M-8000To13000_plots.root","ggMass_EBEE_varbin",7.291e-8,199879]
infos_varbin_EBEE = [info60To200_varbin_EBEE,info200To500_varbin_EBEE,info500To1000_varbin_EBEE,info1000To2000_varbin_EBEE,info2000To4000_varbin_EBEE,info4000To6000_varbin_EBEE,info6000To8000_varbin_EBEE,info8000To13000_varbin_EBEE]
hist_varbin_EBEE = dc.concatenate(infos_varbin_EBEE,"mgg_varbin_EBEE",LUMI)

outfile = TFile("GGJets_stitched.root","recreate")
outfile.cd()
hist_EBEB.Write()
hist_EBEE.Write()
hist_30003500varbin_EBEB.Write()
hist_30003500varbin_EBEE.Write()
hist_varbin_EBEB.Write()
hist_varbin_EBEE.Write()
outfile.Close()