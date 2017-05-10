from ROOT import *
import numpy as np

def bkgPdfCT10SystematicName(pdfNum):
    nameDict = {}
    counter = 1
    for i in range(1,27):
        nameDict[counter] = "BkgCT10Var%i__plus"%i
        # print counter,"BkgCT10Var%i__plus"%i
        counter += 1
        nameDict[counter] = "BkgCT10Var%i__minus"%i
        # print counter,"BkgCT10Var%i__minus"%i
        counter += 1
    return nameDict[pdfNum]

for conv in ("GRW","HLZ","Hewett"):
    print "Now making sanity check file for %s"%conv
    outfile = TFile("thetainput_%s_20GeVbinning.root"%conv,"recreate")

    # first write signal
    msVals = [3000,3500,4000,4500,5000,5500,6000]
    for ms in msVals:
        sigFileName = "ADD_Ms%i_signal_%s.root"%(ms,conv)
        f = TFile(sigFileName,"read")
        f.cd()
        EBEB = f.Get("ggMass_EBEB")
        # EBEB_30003500 = f.Get("ggMass_EBEB_30003500varbin")
        EBEE = f.Get("ggMass_EBEE")
        # EBEE_30003500 = f.Get("ggMass_EBEE_30003500varbin")

        EBEB.SetName("mggEBEB__Ms%i"%ms)
        # EBEB_30003500.SetName("mgg30003500EBEB__Ms%i"%ms)
        EBEE.SetName("mggEBEE__Ms%i"%ms)
        # EBEE_30003500.SetName("mgg30003500EBEE__Ms%i"%ms)
        outfile.cd()
        EBEB.Write()
        # EBEB_30003500.Write()
        EBEE.Write()
        # EBEE_30003500.Write()
        f.cd()
        for i in range(1,53):
            EBEBs = f.Get("ggMass_EBEB_CT10_%i"%i)
            EBEEs = f.Get("ggMass_EBEE_CT10_%i"%i)

            sysName = bkgPdfCT10SystematicName(i)
            EBEBs.SetName("mggEBEB__Ms%i__"%ms+sysName)
            EBEEs.SetName("mggEBEE__Ms%i__"%ms+sysName)

            outfile.cd()
            EBEBs.Write()
            EBEEs.Write()

    #now write background
    bkgFile = TFile("GGJets_merged.root","read")
    bkgFile.cd()
    EBEBbkg = bkgFile.Get("ggMass_EBEB")
    # EBEB_30003500bkg = bkgFile.Get("ggMass_EBEB_30003500varbin")
    EBEEbkg = bkgFile.Get("ggMass_EBEE")
    # EBEE_30003500bkg = bkgFile.Get("ggMass_EBEE_30003500varbin")

    EBEBbkg.SetName("mggEBEB__SMDiphoton")
    # EBEB_30003500bkg.SetName("mgg30003500EBEB__SMDiphoton")
    EBEEbkg.SetName("mggEBEE__SMDiphoton")
    # EBEE_30003500bkg.SetName("mgg30003500EBEE__SMDiphoton")
    outfile.cd()
    EBEBbkg.Write()
    # EBEB_30003500bkg.Write()
    EBEEbkg.Write()
    # EBEE_30003500bkg.Write()

    ## bkg normalization uncertainty
    # EBEBbkg_low = EBEBbkg.Clone()
    # EBEBbkg_high= EBEBbkg.Clone()
    # EBEEbkg_low = EBEEbkg.Clone()
    # EBEEbkg_high= EBEEbkg.Clone()

    # EBEBbkg_low.SetName("mggEBEB__SMDiphoton__Normalization5__minus")
    # EBEBbkg_high.SetName("mggEBEB__SMDiphoton__Normalization5__plus")
    # EBEEbkg_low.SetName("mggEBEE__SMDiphoton__Normalization5__minus")
    # EBEEbkg_high.SetName("mggEBEE__SMDiphoton__Normalization5__plus")

    # EBEBbkg_low.Scale(0.2)
    # EBEBbkg_high.Scale(5.)
    # EBEEbkg_low.Scale(0.2)
    # EBEEbkg_high.Scale(5.)

    # outfile.cd()
    # EBEBbkg_low.Write()
    # EBEBbkg_high.Write()
    # EBEEbkg_low.Write()
    # EBEEbkg_high.Write()

    # EBEBbkg_lowalt = EBEBbkg.Clone()
    # EBEBbkg_highalt= EBEBbkg.Clone()
    # EBEEbkg_lowalt = EBEEbkg.Clone()
    # EBEEbkg_highalt= EBEEbkg.Clone()

    # EBEBbkg_lowalt.SetName("mggEBEB__SMDiphoton__Normalization0p5__minus")
    # EBEBbkg_highalt.SetName("mggEBEB__SMDiphoton__Normalization0p5__plus")
    # EBEEbkg_lowalt.SetName("mggEBEE__SMDiphoton__Normalization0p5__minus")
    # EBEEbkg_highalt.SetName("mggEBEE__SMDiphoton__Normalization0p5__plus")

    # EBEBbkg_lowalt.Scale(0.5)
    # EBEBbkg_highalt.Scale(1.5)
    # EBEEbkg_lowalt.Scale(0.5)
    # EBEEbkg_highalt.Scale(1.5)

    # outfile.cd()
    # EBEBbkg_lowalt.Write()
    # EBEBbkg_highalt.Write()
    # EBEEbkg_lowalt.Write()
    # EBEEbkg_highalt.Write()

    ## bkg pdf systematics
    bkgFile.cd()
    for i in range(1,53):
        EBEB = bkgFile.Get("ggMass_EBEB_CT10_%i"%i)
        # EBEB_30003500 = bkgFile.Get("ggMass_EBEB_30003500varbin_CT10_%i"%i)
        EBEE = bkgFile.Get("ggMass_EBEE_CT10_%i"%i)
        # EBEE_30003500 = bkgFile.Get("ggMass_EBEE_30003500varbin_CT10_%i"%i)

        sysName = bkgPdfCT10SystematicName(i)
        EBEB.SetName("mggEBEB__SMDiphoton__"+sysName)
        # EBEB_30003500.SetName("mgg30003500EBEB__SMDiphoton__"+sysName)
        EBEE.SetName("mggEBEE__SMDiphoton__"+sysName)
        # EBEE_30003500.SetName("mgg30003500EBEE__SMDiphoton__"+sysName)

        outfile.cd()
        EBEB.Write()
        # EBEB_30003500.Write()
        EBEE.Write()
        # EBEE_30003500.Write()

    ## bkg pdf scale variation
    bkgFile.cd()
    for sys in ("fs","renor"):

        EBEBlow = bkgFile.Get("ggMass_"+sys+"0p5"+"_EBEB")
        EBEElow = bkgFile.Get("ggMass_"+sys+"0p5"+"_EBEE")
        EBEBhigh = bkgFile.Get("ggMass_"+sys+"2"+"_EBEB")
        EBEEhigh = bkgFile.Get("ggMass_"+sys+"2"+"_EBEE")

        EBEBlow.SetName("mggEBEB__SMDiphoton__"+sys+"__minus")
        EBEElow.SetName("mggEBEE__SMDiphoton__"+sys+"__minus")
        EBEBhigh.SetName("mggEBEB__SMDiphoton__"+sys+"__plus")
        EBEEhigh.SetName("mggEBEE__SMDiphoton__"+sys+"__plus")

        outfile.cd()
        EBEBlow.Write()
        EBEBhigh.Write()
        EBEElow.Write()
        EBEEhigh.Write()

    # NLO shape systematic
    bkgFile.cd()
    EBEBdown = bkgFile.Get("ggMass_NLODown_EBEB")
    EBEBup = bkgFile.Get("ggMass_NLOUp_EBEB")
    EBEEdown = bkgFile.Get("ggMass_NLODown_EBEE")
    EBEEup = bkgFile.Get("ggMass_NLOUp_EBEE")

    EBEBdown.SetName("mggEBEB__SMDiphoton__NLO__minus")
    EBEBup.SetName("mggEBEB__SMDiphoton__NLO__plus")
    EBEEdown.SetName("mggEBEE__SMDiphoton__NLO__minus")
    EBEEup.SetName("mggEBEE__SMDiphoton__NLO__plus")

    outfile.cd()
    EBEBdown.Write()
    EBEBup.Write()
    EBEEdown.Write()
    EBEEup.Write()


    fakeFile = TFile("fakeplots20152016_pt75_mgg500.root","read")
    fakeFile.cd()
    EBEBfake = fakeFile.Get("fakeMass_EBEB")
    # EBEB_30003500fake = fakeFile.Get("fakeMass_EBEB_30003500varbin")
    EBEEfake = fakeFile.Get("fakeMass_EBEE")
    # EBEE_30003500fake = fakeFile.Get("fakeMass_EBEE_30003500varbin")

    # fake systematics
    EBEBfake_EBDown = fakeFile.Get("fakeMass_EBEB_EBDown")
    EBEBfake_EBUp = fakeFile.Get("fakeMass_EBEB_EBUp")
    EBEEfake_EBDown = fakeFile.Get("fakeMass_EBEE_EBDown")
    EBEEfake_EBUp = fakeFile.Get("fakeMass_EBEE_EBUp")
    EBEEfake_EEDown = fakeFile.Get("fakeMass_EBEE_EEDown")
    EBEEfake_EEUp = fakeFile.Get("fakeMass_EBEE_EEUp")

    EBEBfake.SetName("mggEBEB__Fake")
    # EBEB_30003500fake.SetName("mgg30003500EBEB__Fake")
    EBEEfake.SetName("mggEBEE__Fake")
    # EBEE_30003500fake.SetName("mgg30003500EBEE__Fake")
    EBEBfake_EBDown.SetName("mggEBEB__Fake__EBFakeRate__minus")
    EBEBfake_EBUp.SetName("mggEBEB__Fake__EBFakeRate__plus")
    EBEEfake_EBDown.SetName("mggEBEE__Fake__EBFakeRate__minus")
    EBEEfake_EBUp.SetName("mggEBEE__Fake__EBFakeRate__plus")
    EBEEfake_EEDown.SetName("mggEBEE__Fake__EEFakeRate__minus")
    EBEEfake_EEUp.SetName("mggEBEE__Fake__EEFakeRate__plus")

    outfile.cd()
    EBEBfake.Write()
    # EBEB_30003500fake.Write()
    EBEEfake.Write()
    # EBEE_30003500fake.Write()
    EBEBfake_EBDown.Write()
    EBEBfake_EBUp.Write()
    EBEEfake_EBDown.Write()
    EBEEfake_EBUp.Write()
    EBEEfake_EEDown.Write()
    EBEEfake_EEUp.Write()

    # dataFile = TFile("data2015plots_new3.root","read")
    dataFile = TFile("dataplots20152016_pt75_mgg500.root","read")
    dataFile.cd()

    EBEBdata = dataFile.Get("ggMass_EBEB")
    # EBEB_30003500data = dataFile.Get("ggMass_EBEB_30003500varbin")
    EBEEdata = dataFile.Get("ggMass_EBEE")
    # EBEE_30003500data = dataFile.Get("ggMass_EBEE_30003500varbin")

    EBEBdata.SetName("mggEBEB__DATA")
    # EBEB_30003500data.SetName("mgg30003500EBEB__DATA")
    EBEEdata.SetName("mggEBEE__DATA")
    # EBEE_30003500data.SetName("mgg30003500EBEE__DATA")
    outfile.cd()
    EBEBdata.Write()
    # EBEB_30003500data.Write()
    EBEEdata.Write()
    # EBEE_30003500data.Write()


    outfile.Close()




# f = TFile("ADDHistos_sherpahighstats.root","read")
# fCT10 = TFile("ct10.root","read")
# outfile = TFile("thetainput_new.root","recreate")


# h2500 = f.Get("signal_LambdaT2500_sherpa")
# h3000 = f.Get("signal_LambdaT3000_sherpa")
# h3500 = f.Get("signal_LambdaT3500_sherpa")
# h4000 = f.Get("signal_LambdaT4000_sherpa")
# h4500 = f.Get("signal_LambdaT4500_sherpa")
# h5000 = f.Get("signal_LambdaT5000_sherpa")
# h5500 = f.Get("signal_LambdaT5500_sherpa")
# h6000 = f.Get("signal_LambdaT6000_sherpa")
# h6500 = f.Get("signal_LambdaT6500_sherpa")
# h7000 = f.Get("signal_LambdaT7000_sherpa")
# hbkg = f.Get("sigplusbkg_LambdaT100000_sherpa")
# hvar2500 = f.Get("signal_LambdaT2500_sherpa")
# hvar3000 = f.Get("signal_LambdaT3000_sherpa")
# hvar3500 = f.Get("signal_LambdaT3500_sherpa")
# hvar4000 = f.Get("signal_LambdaT4000_sherpa")
# hvar4500 = f.Get("signal_LambdaT4500_sherpa")
# hvar5000 = f.Get("signal_LambdaT5000_sherpa")
# hvar5500 = f.Get("signal_LambdaT5500_sherpa")
# hvar6000 = f.Get("signal_LambdaT6000_sherpa")
# hvar6500 = f.Get("signal_LambdaT6500_sherpa")
# hvar7000 = f.Get("signal_LambdaT7000_sherpa")
# # hbkgvar = f.Get("sigplusbkg_LambdaT100000_sherpa")
# hbkgvar = fCT10.Get("BB0")
# sigDict = {
#     2500 : h2500,
#     3000 : h3000,
#     3500 : h3500,
#     4000 : h4000,
#     4500 : h4500,
#     5000 : h5000,
#     5500 : h5500,
#     6000 : h6000,
#     6500 : h6500,
#     7000 : h7000
# }
# sigDictVar = {
#     2500 : hvar2500,
#     3000 : hvar3000,
#     3500 : hvar3500,
#     4000 : hvar4000,
#     4500 : hvar4500,
#     5000 : hvar5000,
#     5500 : hvar5500,
#     6000 : hvar6000,
#     6500 : hvar6500,
#     7000 : hvar7000
# }

# def fixHist(hist,ms,name="DUMMY",title="",isData=False):

#     bins = np.array([650.,1150.,1800.,2600.,3500.,13000.])
#     bins2500 = np.array([650.,1150.,1800.,13000.])
#     bins30003500 = np.array([650.,1150.,1800.,2600.,13000.])

#     # assume we're dealing with signal unless told otherwise
#     histName = "mgg__ADDMs%i"%ms
#     currentBins = bins
#     if ms == 2500:
#         currentBins = bins2500
#         histName = "mgg2500__ADDMs%i"%ms
#     elif ms == 3000 or ms == 3500:
#         currentBins = bins30003500
#         histName = "mgg30003500__ADDMs%i"%ms
#     if name != "DUMMY":
#         histName = name
#     htemp = TH1D(histName,title,len(currentBins)-1,currentBins)

#     if ms == 2500:
#         htemp.SetBinContent(1, hist.GetBinContent(2) )
#         htemp.SetBinContent(2, hist.GetBinContent(3) )
#         binThreeContent = hist.GetBinContent(4) + hist.GetBinContent(5) + hist.GetBinContent(6)
#         htemp.SetBinContent(3,binThreeContent)
#         if isData:
#             for i in (1,2,3):
#                 htemp.SetBinContent(i, round(htemp.GetBinContent(i)) )

#     elif ms == 3000 or ms == 3500:
#         htemp.SetBinContent(1, hist.GetBinContent(2) )
#         htemp.SetBinContent(2, hist.GetBinContent(3) )
#         htemp.SetBinContent(3, hist.GetBinContent(4) )
#         binFourContent = hist.GetBinContent(5) + hist.GetBinContent(6)
#         htemp.SetBinContent(4,binFourContent)
#         if isData:
#             for i in (1,2,3,4):
#                 htemp.SetBinContent(i, round(htemp.GetBinContent(i)) )
#     else:
#         for bin in (2,3,4,5,6):
#             htemp.SetBinContent( bin-1, hist.GetBinContent(bin) )
#             if isData:
#                 htemp.SetBinContent(bin-1,round(htemp.GetBinContent(bin-1)) )
#     return htemp

    

# for ms64 in np.arange(2500,7500,500):
#     ms = int(ms64)
#     htemp = fixHist( sigDictVar[ms],ms )
#     htemp.Write()

# hdata2500 = fixHist(hbkgvar,2500,"mgg2500__DATA","",True)
# hdata30003500 = fixHist(hbkgvar,3000,"mgg30003500__DATA","",True)
# hdata = fixHist(hbkgvar,0,"mgg__DATA","",True)

# hbkg2500 = fixHist(hbkgvar,2500,"mgg2500__SMDiphoton","",False)
# hbkg30003500 = fixHist(hbkgvar,3000,"mgg30003500__SMDiphoton","",False)
# hbkgNew = fixHist(hbkgvar,0,"mgg__SMDiphoton","",False)

# outfile.cd()
# # for h in (hdata2500,hdata30003500,hdata):
# for h in (hdata2500,hdata30003500,hdata,hbkg2500,hbkg30003500,hbkgNew):
#     h.Write()

# # write multibin background and data histograms
# # for bin in (1,2,3,4,5):
# #     print "Now creating background and data histograms for bin=%i"%bin
# #     htemp = TH1D("mgg%i__SMDiphoton"%(bin),"",1,bins[bin-1],bins[bin])
# #     hdata = TH1D("mgg%i__DATA"%(bin),"",1,bins[bin-1],bins[bin])
# #     htemp.SetBinContent( 1, hbkgvar.GetBinContent(bin+1) )
# #     outfile.cd()
# #     htemp.Write()
# #     hdata.Write()

# f.Close()

# #################################
# # write systematics from Haran
# #################################

# # bins2500 = np.array([650.,1150.,1800.,13000.])
# # bins30003500 = np.array([650.,1150.,1800.,2600.,13000.])
# # bins = np.array([650.,1150.,1800.,2600.,3500.,13000.])

# # fCT10 = TFile("ct10.root","read")

# # def bkgPdfCT10SystematicName(pdfNum):
# #     nameDict = {}
# #     counter = 1
# #     for i in range(1,27):
# #         nameDict[counter] = "BkgCT10Var%i__plus"%i
# #         # print counter,"BkgCT10Var%i__plus"%i
# #         counter += 1
# #         nameDict[counter] = "BkgCT10Var%i__minus"%i
# #         # print counter,"BkgCT10Var%i__minus"%i
# #         counter += 1
# #     return nameDict[pdfNum]
# def bkgPdfMSTWSystematicName(pdfNum):
#     nameDict = {}
#     counter = 1
#     for i in range(1,21):
#         nameDict[counter] = "BkgMSTWVar%i__plus"%i
#         counter += 1
#         nameDict[counter] = "BkgMSTWVar%i__minus"%i
#         counter += 1
#     return nameDict[pdfNum]
# def bkgPdfNNPDFSystematicName(pdfNum):
#     nameDict = {}
#     counter = 1
#     for i in range(1,51):
#         nameDict[counter] = "BkgNNPDFVar%i__plus"%i
#         counter += 1
#         nameDict[counter] = "BkgNNPDFVar%i__minus"%i
#         counter += 1
#     return nameDict[pdfNum]
# #############
# # Write CT10    
# #############

# # write the file containing a dictionary for the posterior:
# # dictFile = open("posteriorDict.py",'w')
# # dictFile.write("postDict = {\n")
# # for i in range(1,27):
# #     dictFile.write('    "BkgCT10Var%i" : (100,-3.,3.),\n'%i)
# # dictFile.write("}\n")
# # dictFile.close()
# for pdfNum in range(0,53):

#     if pdfNum == 0:
#         continue # adding central value as bkg above!

#         # print "Now adding central value"
#         # currentSystName = "SMDiphoton"
#         # ct10hist = fCT10.Get("BB0")
#         # histName2500 = "mgg2500__%s"%(currentSystName)
#         # histName30003500 = "mgg30003500__%s"%(currentSystName)
#         # histName = "mgg__%s"%(currentSystName)

#         # hist2500 = fixHist(ct10hist,2500,histName2500,"",False)
#         # hist30003500 = fixHist(ct10hist,3000,histName30003500,"",False)
#         # hist = fixHist(ct10hist,0,histName,"",False)

#         # outfile.cd()
#         # hist2500.Write()
#         # hist30003500.Write()
#         # hist.Write()
        
#     else:
#         currentSystName = bkgPdfCT10SystematicName(pdfNum)
#         print "Now adding systematic %s"%currentSystName


#         ct10hist = fCT10.Get("BB%i"%pdfNum)
#         histName2500 = "mgg2500__SMDiphoton__%s"%(currentSystName)
#         histName30003500 = "mgg30003500__SMDiphoton__%s"%(currentSystName)
#         histName = "mgg__SMDiphoton__%s"%(currentSystName)

#         hist2500 = fixHist(ct10hist,2500,histName2500,"",False)
#         hist30003500 = fixHist(ct10hist,3000,histName30003500,"",False)
#         hist = fixHist(ct10hist,0,histName,"",False)

#         outfile.cd()
#         hist2500.Write()
#         hist30003500.Write()
#         hist.Write()

#     # hist1 = fCT10.Get("BB%i_1"%pdfNum)
#     # hist2 = fCT10.Get("BB%i_2"%pdfNum)
#     # hist3 = fCT10.Get("BB%i_3"%pdfNum)
#     # hist4 = fCT10.Get("BB%i_4"%pdfNum)
#     # hist5 = fCT10.Get("BB%i_5"%pdfNum)

#     # for h in (hist1,hist2,hist3,hist4,hist5):
#     #     h.SetTitle("")

#     # ###############
#     # # for ms=2500
#     # ###############

#     # pdfVarBkg_ms2500binning_1 = hist1.Clone()
#     # pdfVarBkg_ms2500binning_1.SetName("Ms2500mgg1__SMDiphoton__%s"%( currentSystName ))
#     # pdfVarBkg_ms2500binning_2 = hist2.Clone()
#     # pdfVarBkg_ms2500binning_2.SetName("Ms2500mgg2__SMDiphoton__%s"%( currentSystName ))
#     # pdfVarBkg_ms2500binning_3 = TH1D("Ms2500mgg3__SMDiphoton__%s"%( currentSystName ),"",1,bins2500[-2],bins2500[-1])
#     # # fill third bin histo
#     # for h in (hist3,hist4,hist5):
#     #     pdfVarBkg_ms2500binning_3.Fill( h.GetBinCenter(1),h.GetBinContent(1) )

#     # outfile.cd()
#     # for h in (pdfVarBkg_ms2500binning_1,pdfVarBkg_ms2500binning_2,pdfVarBkg_ms2500binning_3):
#     #     h.Write()

#     # ######################
#     # # for ms = 3000,3500
#     # ######################

#     # pdfVarBkg_ms30003500binning_1 = hist1.Clone()
#     # pdfVarBkg_ms30003500binning_1.SetName("Ms30003500mgg1__SMDiphoton__%s"%( currentSystName ))
#     # pdfVarBkg_ms30003500binning_2 = hist2.Clone()
#     # pdfVarBkg_ms30003500binning_2.SetName("Ms30003500mgg2__SMDiphoton__%s"%( currentSystName ))
#     # pdfVarBkg_ms30003500binning_3 = hist3.Clone()
#     # pdfVarBkg_ms30003500binning_3.SetName("Ms30003500mgg3__SMDiphoton__%s"%( currentSystName ))
#     # pdfVarBkg_ms30003500binning_4 = TH1D("Ms30003500mgg4__SMDiphoton__%s"%(currentSystName),"",1,bins30003500[-2],bins30003500[-1])

#     # #fill fourth bin histo
#     # for h in (hist4,hist5):
#     #     pdfVarBkg_ms30003500binning_4.Fill( h.GetBinCenter(1),h.GetBinContent(1) )

#     # outfile.cd()
#     # for h in (pdfVarBkg_ms30003500binning_1,pdfVarBkg_ms30003500binning_2,pdfVarBkg_ms30003500binning_3,pdfVarBkg_ms30003500binning_4):
#     #     h.Write()

#     # #########################
#     # # for ms = 4000 to 7000
#     # #########################

#     # pdfVarBkg_regularbinning_1 = hist1.Clone()
#     # pdfVarBkg_regularbinning_2 = hist2.Clone()
#     # pdfVarBkg_regularbinning_3 = hist3.Clone()
#     # pdfVarBkg_regularbinning_4 = hist4.Clone()
#     # pdfVarBkg_regularbinning_5 = hist5.Clone()

#     # pdfVarBkg_regularbinning_1.SetName("mgg1__SMDiphoton__%s"%( currentSystName ))
#     # pdfVarBkg_regularbinning_2.SetName("mgg2__SMDiphoton__%s"%( currentSystName ))
#     # pdfVarBkg_regularbinning_3.SetName("mgg3__SMDiphoton__%s"%( currentSystName ))
#     # pdfVarBkg_regularbinning_4.SetName("mgg4__SMDiphoton__%s"%( currentSystName ))
#     # pdfVarBkg_regularbinning_5.SetName("mgg5__SMDiphoton__%s"%( currentSystName ))

#     # outfile.cd()
#     # for h in (pdfVarBkg_regularbinning_1,pdfVarBkg_regularbinning_2,pdfVarBkg_regularbinning_3,pdfVarBkg_regularbinning_4,pdfVarBkg_regularbinning_5):
#     #     h.Write()

# fCT10.Close()

########
# MSTW
########
# fMSTW = TFile("mstw.root","read")
# for pdfNum in range(1,41):

#     currentSystName = bkgPdfMSTWSystematicName(pdfNum)
#     print "Now adding systematic %s"%currentSystName

#     hist1 = fMSTW.Get("BB%i_1"%pdfNum)
#     hist2 = fMSTW.Get("BB%i_2"%pdfNum)
#     hist3 = fMSTW.Get("BB%i_3"%pdfNum)
#     hist4 = fMSTW.Get("BB%i_4"%pdfNum)
#     hist5 = fMSTW.Get("BB%i_5"%pdfNum)

#     for h in (hist1,hist2,hist3,hist4,hist5):
#         h.SetTitle("")

#     ###############
#     # for ms=2500
#     ###############

#     pdfVarBkg_ms2500binning_1 = hist1.Clone()
#     pdfVarBkg_ms2500binning_1.SetName("Ms2500mgg1__SMDiphoton__%s"%( currentSystName ))
#     pdfVarBkg_ms2500binning_2 = hist2.Clone()
#     pdfVarBkg_ms2500binning_2.SetName("Ms2500mgg2__SMDiphoton__%s"%( currentSystName ))
#     pdfVarBkg_ms2500binning_3 = TH1D("Ms2500mgg3__SMDiphoton__%s"%( currentSystName ),"",1,bins2500[-2],bins2500[-1])
#     # fill third bin histo
#     for h in (hist3,hist4,hist5):
#         pdfVarBkg_ms2500binning_3.Fill( h.GetBinCenter(1),h.GetBinContent(1) )

#     outfile.cd()
#     for h in (pdfVarBkg_ms2500binning_1,pdfVarBkg_ms2500binning_2,pdfVarBkg_ms2500binning_3):
#         h.Write()

#     ######################
#     # for ms = 3000,3500
#     ######################

#     pdfVarBkg_ms30003500binning_1 = hist1.Clone()
#     pdfVarBkg_ms30003500binning_1.SetName("Ms30003500mgg1__SMDiphoton__%s"%( currentSystName ))
#     pdfVarBkg_ms30003500binning_2 = hist2.Clone()
#     pdfVarBkg_ms30003500binning_2.SetName("Ms30003500mgg2__SMDiphoton__%s"%( currentSystName ))
#     pdfVarBkg_ms30003500binning_3 = hist3.Clone()
#     pdfVarBkg_ms30003500binning_3.SetName("Ms30003500mgg3__SMDiphoton__%s"%( currentSystName ))
#     pdfVarBkg_ms30003500binning_4 = TH1D("Ms30003500mgg4__SMDiphoton__%s"%(currentSystName),"",1,bins30003500[-2],bins30003500[-1])

#     #fill fourth bin histo
#     for h in (hist4,hist5):
#         pdfVarBkg_ms30003500binning_4.Fill( h.GetBinCenter(1),h.GetBinContent(1) )

#     outfile.cd()
#     for h in (pdfVarBkg_ms30003500binning_1,pdfVarBkg_ms30003500binning_2,pdfVarBkg_ms30003500binning_3,pdfVarBkg_ms30003500binning_4):
#         h.Write()

#     #########################
#     # for ms = 4000 to 7000
#     #########################

#     pdfVarBkg_regularbinning_1 = hist1.Clone()
#     pdfVarBkg_regularbinning_2 = hist2.Clone()
#     pdfVarBkg_regularbinning_3 = hist3.Clone()
#     pdfVarBkg_regularbinning_4 = hist4.Clone()
#     pdfVarBkg_regularbinning_5 = hist5.Clone()

#     pdfVarBkg_regularbinning_1.SetName("mgg1__SMDiphoton__%s"%( currentSystName ))
#     pdfVarBkg_regularbinning_2.SetName("mgg2__SMDiphoton__%s"%( currentSystName ))
#     pdfVarBkg_regularbinning_3.SetName("mgg3__SMDiphoton__%s"%( currentSystName ))
#     pdfVarBkg_regularbinning_4.SetName("mgg4__SMDiphoton__%s"%( currentSystName ))
#     pdfVarBkg_regularbinning_5.SetName("mgg5__SMDiphoton__%s"%( currentSystName ))

#     outfile.cd()
#     for h in (pdfVarBkg_regularbinning_1,pdfVarBkg_regularbinning_2,pdfVarBkg_regularbinning_3,pdfVarBkg_regularbinning_4,pdfVarBkg_regularbinning_5):
#         h.Write()
# fMSTW.Close()

# ########
# # NNPDF
# ########
# fNNPDF = TFile("nnpdf.root","read")
# for pdfNum in range(1,101):

#     currentSystName = bkgPdfNNPDFSystematicName(pdfNum)
#     print "Now adding systematic %s"%currentSystName

#     hist1 = fNNPDF.Get("BB%i_1"%pdfNum)
#     hist2 = fNNPDF.Get("BB%i_2"%pdfNum)
#     hist3 = fNNPDF.Get("BB%i_3"%pdfNum)
#     hist4 = fNNPDF.Get("BB%i_4"%pdfNum)
#     hist5 = fNNPDF.Get("BB%i_5"%pdfNum)

#     for h in (hist1,hist2,hist3,hist4,hist5):
#         h.SetTitle("")

#     ###############
#     # for ms=2500
#     ###############

#     pdfVarBkg_ms2500binning_1 = hist1.Clone()
#     pdfVarBkg_ms2500binning_1.SetName("Ms2500mgg1__SMDiphoton__%s"%( currentSystName ))
#     pdfVarBkg_ms2500binning_2 = hist2.Clone()
#     pdfVarBkg_ms2500binning_2.SetName("Ms2500mgg2__SMDiphoton__%s"%( currentSystName ))
#     pdfVarBkg_ms2500binning_3 = TH1D("Ms2500mgg3__SMDiphoton__%s"%( currentSystName ),"",1,bins2500[-2],bins2500[-1])
#     # fill third bin histo
#     for h in (hist3,hist4,hist5):
#         pdfVarBkg_ms2500binning_3.Fill( h.GetBinCenter(1),h.GetBinContent(1) )

#     outfile.cd()
#     for h in (pdfVarBkg_ms2500binning_1,pdfVarBkg_ms2500binning_2,pdfVarBkg_ms2500binning_3):
#         h.Write()

#     ######################
#     # for ms = 3000,3500
#     ######################

#     pdfVarBkg_ms30003500binning_1 = hist1.Clone()
#     pdfVarBkg_ms30003500binning_1.SetName("Ms30003500mgg1__SMDiphoton__%s"%( currentSystName ))
#     pdfVarBkg_ms30003500binning_2 = hist2.Clone()
#     pdfVarBkg_ms30003500binning_2.SetName("Ms30003500mgg2__SMDiphoton__%s"%( currentSystName ))
#     pdfVarBkg_ms30003500binning_3 = hist3.Clone()
#     pdfVarBkg_ms30003500binning_3.SetName("Ms30003500mgg3__SMDiphoton__%s"%( currentSystName ))
#     pdfVarBkg_ms30003500binning_4 = TH1D("Ms30003500mgg4__SMDiphoton__%s"%(currentSystName),"",1,bins30003500[-2],bins30003500[-1])

#     #fill fourth bin histo
#     for h in (hist4,hist5):
#         pdfVarBkg_ms30003500binning_4.Fill( h.GetBinCenter(1),h.GetBinContent(1) )

#     outfile.cd()
#     for h in (pdfVarBkg_ms30003500binning_1,pdfVarBkg_ms30003500binning_2,pdfVarBkg_ms30003500binning_3,pdfVarBkg_ms30003500binning_4):
#         h.Write()

#     #########################
#     # for ms = 4000 to 7000
#     #########################

#     pdfVarBkg_regularbinning_1 = hist1.Clone()
#     pdfVarBkg_regularbinning_2 = hist2.Clone()
#     pdfVarBkg_regularbinning_3 = hist3.Clone()
#     pdfVarBkg_regularbinning_4 = hist4.Clone()
#     pdfVarBkg_regularbinning_5 = hist5.Clone()

#     pdfVarBkg_regularbinning_1.SetName("mgg1__SMDiphoton__%s"%( currentSystName ))
#     pdfVarBkg_regularbinning_2.SetName("mgg2__SMDiphoton__%s"%( currentSystName ))
#     pdfVarBkg_regularbinning_3.SetName("mgg3__SMDiphoton__%s"%( currentSystName ))
#     pdfVarBkg_regularbinning_4.SetName("mgg4__SMDiphoton__%s"%( currentSystName ))
#     pdfVarBkg_regularbinning_5.SetName("mgg5__SMDiphoton__%s"%( currentSystName ))

#     outfile.cd()
#     for h in (pdfVarBkg_regularbinning_1,pdfVarBkg_regularbinning_2,pdfVarBkg_regularbinning_3,pdfVarBkg_regularbinning_4,pdfVarBkg_regularbinning_5):
#         h.Write()

# fNNPDF.Close()
# outfile.Close()














