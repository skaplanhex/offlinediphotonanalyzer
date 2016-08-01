print "importing ROOT..."
from ROOT import *
print "done."

gROOT.SetBatch()

def getHist(fFile,histName):
    fFile.cd()
    h = fFile.Get(histName)
    h2 = h.Clone()
    return h2
def subtractHistos(sigplusbkg,bkg,newName):
    newHisto = sigplusbkg.Clone()
    newHisto.Add(bkg,-1.)
    newHisto.SetName(newName)
    return newHisto
def formatGraph(graph, graphNum):
    colors = [ kGreen+2, kRed, kBlue, kBlack, kMagenta, kOrange+2, kCyan, kYellow+1 ]
    graphColor = colors[graphNum % 8]
    lineStyle = (graphNum % 11) + 1
    graph.SetLineColor(graphColor)
    graph.SetLineStyle(lineStyle)
    graph.SetLineWidth(2)
    graph.GetXaxis().SetRangeUser(0.,6000.)
def plotMultipleHistos(graphs,legendheader,labels,outname,logy=False):
    c = TCanvas("c", "",800,800)
    c.cd()
    # bkg = TH2D("bkg","",100,fXmin,fXmax,100,fYmin,fYmax)
    # bkg.GetXaxis().SetTitle(fXAxisTitle)
    # bkg.GetYaxis().SetTitle(fYAxisTitle)
    # bkg.SetTitleOffset(1.2,"X")
    # bkg.SetTitleOffset(1.5,"Y")
    # bkg.Draw()
    legend = TLegend(.56,.64,.86,.82)
    legend.SetBorderSize(0)
    legend.SetFillColor(0)
    legend.SetFillStyle(0)
    legend.SetTextFont(42)
    legend.SetTextSize(0.021)
    legend.SetHeader(legendheader)

    graphCounter = 0
    for i,iLabel in enumerate(labels):
        # if graphCounter>1:
        #     continue
        graph = graphs[i]
        legend.AddEntry(graph, iLabel,"l")
        formatGraph(graph,graphCounter)
        drawString = ""
        if graphCounter>0:
            drawString="same"
        graph.Draw(drawString)
        graphCounter += 1

    legend.Draw()
    # c.SetLogx()
    if logy:
        c.SetLogy()
    c.SaveAs(outname)




#input histogram file
infile = TFile("ADDMergedHistos_witherrorbars.root","read")

# get all the histograms

#first the background
bkg_EBEB = getHist(infile,"ggMass_ADDBkg_EBEB")
bkg_EBEB_varbin = getHist(infile,"ggMass_ADDBkg_EBEB_varbin")
bkg_EBEB_30003500varbin = getHist(infile,"ggMass_ADDBkg_EBEB_30003500varbin")

bkg_EBEE = getHist(infile,"ggMass_ADDBkg_EBEE")
bkg_EBEE_varbin = getHist(infile,"ggMass_ADDBkg_EBEE_varbin")
bkg_EBEE_30003500varbin = getHist(infile,"ggMass_ADDBkg_EBEE_30003500varbin")

#now the signal plus background
sigplusbkg_Ms3000_EBEB = getHist(infile,"ggMass_Ms3000_EBEB")
sigplusbkg_Ms3000_EBEB_varbin = getHist(infile,"ggMass_Ms3000_EBEB_varbin")
sigplusbkg_Ms3000_EBEB_30003500varbin = getHist(infile,"ggMass_Ms3000_EBEB_30003500varbin")
sigplusbkg_Ms3500_EBEB = getHist(infile,"ggMass_Ms3500_EBEB")
sigplusbkg_Ms3500_EBEB_varbin = getHist(infile,"ggMass_Ms3500_EBEB_varbin")
sigplusbkg_Ms3500_EBEB_30003500varbin = getHist(infile,"ggMass_Ms3500_EBEB_30003500varbin")
sigplusbkg_Ms4000_EBEB = getHist(infile,"ggMass_Ms4000_EBEB")
sigplusbkg_Ms4000_EBEB_varbin = getHist(infile,"ggMass_Ms4000_EBEB_varbin")
sigplusbkg_Ms4500_EBEB = getHist(infile,"ggMass_Ms4500_EBEB")
sigplusbkg_Ms4500_EBEB_varbin = getHist(infile,"ggMass_Ms4500_EBEB_varbin")
sigplusbkg_Ms5000_EBEB = getHist(infile,"ggMass_Ms5000_EBEB")
sigplusbkg_Ms5000_EBEB_varbin = getHist(infile,"ggMass_Ms5000_EBEB_varbin")
sigplusbkg_Ms5500_EBEB = getHist(infile,"ggMass_Ms5500_EBEB")
sigplusbkg_Ms5500_EBEB_varbin = getHist(infile,"ggMass_Ms5500_EBEB_varbin")
sigplusbkg_Ms6000_EBEB = getHist(infile,"ggMass_Ms6000_EBEB")
sigplusbkg_Ms6000_EBEB_varbin = getHist(infile,"ggMass_Ms6000_EBEB_varbin")

sigplusbkg_Ms3000_EBEE = getHist(infile,"ggMass_Ms3000_EBEE")
sigplusbkg_Ms3000_EBEE_varbin = getHist(infile,"ggMass_Ms3000_EBEE_varbin")
sigplusbkg_Ms3000_EBEE_30003500varbin = getHist(infile,"ggMass_Ms3000_EBEE_30003500varbin")
sigplusbkg_Ms3500_EBEE = getHist(infile,"ggMass_Ms3500_EBEE")
sigplusbkg_Ms3500_EBEE_varbin = getHist(infile,"ggMass_Ms3500_EBEE_varbin")
sigplusbkg_Ms3500_EBEE_30003500varbin = getHist(infile,"ggMass_Ms3500_EBEE_30003500varbin")
sigplusbkg_Ms4000_EBEE = getHist(infile,"ggMass_Ms4000_EBEE")
sigplusbkg_Ms4000_EBEE_varbin = getHist(infile,"ggMass_Ms4000_EBEE_varbin")
sigplusbkg_Ms4500_EBEE = getHist(infile,"ggMass_Ms4500_EBEE")
sigplusbkg_Ms4500_EBEE_varbin = getHist(infile,"ggMass_Ms4500_EBEE_varbin")
sigplusbkg_Ms5000_EBEE = getHist(infile,"ggMass_Ms5000_EBEE")
sigplusbkg_Ms5000_EBEE_varbin = getHist(infile,"ggMass_Ms5000_EBEE_varbin")
sigplusbkg_Ms5500_EBEE = getHist(infile,"ggMass_Ms5500_EBEE")
sigplusbkg_Ms5500_EBEE_varbin = getHist(infile,"ggMass_Ms5500_EBEE_varbin")
sigplusbkg_Ms6000_EBEE = getHist(infile,"ggMass_Ms6000_EBEE")
sigplusbkg_Ms6000_EBEE_varbin = getHist(infile,"ggMass_Ms6000_EBEE_varbin")

#now we'll subtract the background from sig+bkg to get the signal histograms

sig_Ms3000_EBEB = subtractHistos(sigplusbkg_Ms3000_EBEB,bkg_EBEB,"sig_Ms3000_EBEB")
sig_Ms3000_EBEB_varbin = subtractHistos(sigplusbkg_Ms3000_EBEB_varbin,bkg_EBEB_varbin,"sig_Ms3000_EBEB_varbin")
sig_Ms3000_EBEB_30003500varbin = subtractHistos(sigplusbkg_Ms3000_EBEB_30003500varbin,bkg_EBEB_30003500varbin,"sig_Ms3000_EBEB_30003500varbin")
sig_Ms3500_EBEB = subtractHistos(sigplusbkg_Ms3500_EBEB,bkg_EBEB,"sig_Ms3500_EBEB")
sig_Ms3500_EBEB_varbin = subtractHistos(sigplusbkg_Ms3500_EBEB_varbin,bkg_EBEB_varbin,"sig_Ms3500_EBEB_varbin")
sig_Ms3500_EBEB_30003500varbin = subtractHistos(sigplusbkg_Ms3500_EBEB_30003500varbin,bkg_EBEB_30003500varbin,"sig_Ms3500_EBEB_30003500varbin")
sig_Ms4000_EBEB = subtractHistos(sigplusbkg_Ms4000_EBEB,bkg_EBEB,"sig_Ms4000_EBEB")
sig_Ms4000_EBEB_varbin = subtractHistos(sigplusbkg_Ms4000_EBEB_varbin,bkg_EBEB_varbin,"sig_Ms4000_EBEB_varbin")
sig_Ms4500_EBEB = subtractHistos(sigplusbkg_Ms4500_EBEB,bkg_EBEB,"sig_Ms4500_EBEB")
sig_Ms4500_EBEB_varbin = subtractHistos(sigplusbkg_Ms4500_EBEB_varbin,bkg_EBEB_varbin,"sig_Ms4500_EBEB_varbin")
sig_Ms5000_EBEB = subtractHistos(sigplusbkg_Ms5000_EBEB,bkg_EBEB,"sig_Ms5000_EBEB")
sig_Ms5000_EBEB_varbin = subtractHistos(sigplusbkg_Ms5000_EBEB_varbin,bkg_EBEB_varbin,"sig_Ms5000_EBEB_varbin")
sig_Ms5500_EBEB = subtractHistos(sigplusbkg_Ms5500_EBEB,bkg_EBEB,"sig_Ms5500_EBEB")
sig_Ms5500_EBEB_varbin = subtractHistos(sigplusbkg_Ms5500_EBEB_varbin,bkg_EBEB_varbin,"sig_Ms5500_EBEB_varbin")
sig_Ms6000_EBEB = subtractHistos(sigplusbkg_Ms6000_EBEB,bkg_EBEB,"sig_Ms6000_EBEB")
sig_Ms6000_EBEB_varbin = subtractHistos(sigplusbkg_Ms6000_EBEB_varbin,bkg_EBEB_varbin,"sig_Ms6000_EBEB_varbin")

sig_Ms3000_EBEE = subtractHistos(sigplusbkg_Ms3000_EBEE,bkg_EBEE,"sig_Ms3000_EBEE")
sig_Ms3000_EBEE_varbin = subtractHistos(sigplusbkg_Ms3000_EBEE_varbin,bkg_EBEE_varbin,"sig_Ms3000_EBEE_varbin")
sig_Ms3000_EBEE_30003500varbin = subtractHistos(sigplusbkg_Ms3000_EBEE_30003500varbin,bkg_EBEE_30003500varbin,"sig_Ms3000_EBEE_30003500varbin")
sig_Ms3500_EBEE = subtractHistos(sigplusbkg_Ms3500_EBEE,bkg_EBEE,"sig_Ms3500_EBEE")
sig_Ms3500_EBEE_varbin = subtractHistos(sigplusbkg_Ms3500_EBEE_varbin,bkg_EBEE_varbin,"sig_Ms3500_EBEE_varbin")
sig_Ms3500_EBEE_30003500varbin = subtractHistos(sigplusbkg_Ms3500_EBEE_30003500varbin,bkg_EBEE_30003500varbin,"sig_Ms3500_EBEE_30003500varbin")
sig_Ms4000_EBEE = subtractHistos(sigplusbkg_Ms4000_EBEE,bkg_EBEE,"sig_Ms4000_EBEE")
sig_Ms4000_EBEE_varbin = subtractHistos(sigplusbkg_Ms4000_EBEE_varbin,bkg_EBEE_varbin,"sig_Ms4000_EBEE_varbin")
sig_Ms4500_EBEE = subtractHistos(sigplusbkg_Ms4500_EBEE,bkg_EBEE,"sig_Ms4500_EBEE")
sig_Ms4500_EBEE_varbin = subtractHistos(sigplusbkg_Ms4500_EBEE_varbin,bkg_EBEE_varbin,"sig_Ms4500_EBEE_varbin")
sig_Ms5000_EBEE = subtractHistos(sigplusbkg_Ms5000_EBEE,bkg_EBEE,"sig_Ms5000_EBEE")
sig_Ms5000_EBEE_varbin = subtractHistos(sigplusbkg_Ms5000_EBEE_varbin,bkg_EBEE_varbin,"sig_Ms5000_EBEE_varbin")
sig_Ms5500_EBEE = subtractHistos(sigplusbkg_Ms5500_EBEE,bkg_EBEE,"sig_Ms5500_EBEE")
sig_Ms5500_EBEE_varbin = subtractHistos(sigplusbkg_Ms5500_EBEE_varbin,bkg_EBEE_varbin,"sig_Ms5500_EBEE_varbin")
sig_Ms6000_EBEE = subtractHistos(sigplusbkg_Ms6000_EBEE,bkg_EBEE,"sig_Ms6000_EBEE")
sig_Ms6000_EBEE_varbin = subtractHistos(sigplusbkg_Ms6000_EBEE_varbin,bkg_EBEE_varbin,"sig_Ms6000_EBEE_varbin")

#now let's make some plots!



# plotMultipleHistos(graphs,legendheader,labels,outname,logy=False):

#plot bkg and all sigplusbkg at once
graphsEBEB = [bkg_EBEB,sigplusbkg_Ms3000_EBEB,sigplusbkg_Ms3500_EBEB,sigplusbkg_Ms4000_EBEB,sigplusbkg_Ms4500_EBEB,sigplusbkg_Ms5000_EBEB,sigplusbkg_Ms5500_EBEB,sigplusbkg_Ms6000_EBEB]
legendheader = "Signal+Background Comparison (EBEB)"
labelsEBEB = ["SM #gamma#gamma (0 jet)","ADD Ms=3000","ADD Ms=3500","ADD Ms=4000","ADD Ms=4500","ADD Ms=5000","ADD Ms=5500","ADD Ms=6000"]
plotMultipleHistos(graphsEBEB,legendheader,labelsEBEB,"sigplusbkgcomp_EBEB.png",True)

graphsEBEE = [bkg_EBEE,sigplusbkg_Ms3000_EBEE,sigplusbkg_Ms3500_EBEE,sigplusbkg_Ms4000_EBEE,sigplusbkg_Ms4500_EBEE,sigplusbkg_Ms5000_EBEE,sigplusbkg_Ms5500_EBEE,sigplusbkg_Ms6000_EBEE]
legendheader = "Signal+Background Comparison (EBEE)"
labelsEBEE = ["SM #gamma#gamma (0 jet)","ADD Ms=3000","ADD Ms=3500","ADD Ms=4000","ADD Ms=4500","ADD Ms=5000","ADD Ms=5500","ADD Ms=6000"]
plotMultipleHistos(graphsEBEE,legendheader,labelsEBEE,"sigplusbkgcomp_EBEE.png",True)

#plot signal together
graphsEBEB = [sig_Ms3000_EBEB,sig_Ms3500_EBEB,sig_Ms4000_EBEB,sig_Ms4500_EBEB,sig_Ms5000_EBEB,sig_Ms5500_EBEB,sig_Ms6000_EBEB]
legendheader = "Signal Comparison (EBEB)"
labelsEBEB = ["ADD Ms=3000","ADD Ms=3500","ADD Ms=4000","ADD Ms=4500","ADD Ms=5000","ADD Ms=5500","ADD Ms=6000"]
plotMultipleHistos(graphsEBEB,legendheader,labelsEBEB,"sigcomp_EBEB.png",True)

graphsEBEE = [sig_Ms3000_EBEE,sig_Ms3500_EBEE,sig_Ms4000_EBEE,sig_Ms4500_EBEE,sig_Ms5000_EBEE,sig_Ms5500_EBEE,sig_Ms6000_EBEE]
legendheader = "Signal Comparison (EBEE)"
labelsEBEE = ["ADD Ms=3000","ADD Ms=3500","ADD Ms=4000","ADD Ms=4500","ADD Ms=5000","ADD Ms=5500","ADD Ms=6000"]
plotMultipleHistos(graphsEBEE,legendheader,labelsEBEE,"sigcomp_EBEE.png",True)


outfile = TFile("ADDFinalHistos.root","recreate")
outfile.cd()
sigplusbkg_Ms3000_EBEB.Write()
sigplusbkg_Ms3000_EBEB_varbin.Write()
sigplusbkg_Ms3000_EBEB_30003500varbin.Write()
sigplusbkg_Ms3000_EBEE.Write()
sigplusbkg_Ms3000_EBEE_varbin.Write()
sigplusbkg_Ms3000_EBEE_30003500varbin.Write()
sigplusbkg_Ms3500_EBEB.Write()
sigplusbkg_Ms3500_EBEB_varbin.Write()
sigplusbkg_Ms3500_EBEB_30003500varbin.Write()
sigplusbkg_Ms3500_EBEE.Write()
sigplusbkg_Ms3500_EBEE_varbin.Write()
sigplusbkg_Ms3500_EBEE_30003500varbin.Write()
sigplusbkg_Ms4000_EBEB.Write()
sigplusbkg_Ms4000_EBEB_varbin.Write()
sigplusbkg_Ms4000_EBEE.Write()
sigplusbkg_Ms4000_EBEE_varbin.Write()
sigplusbkg_Ms4500_EBEB.Write()
sigplusbkg_Ms4500_EBEB_varbin.Write()
sigplusbkg_Ms4500_EBEE.Write()
sigplusbkg_Ms4500_EBEE_varbin.Write()
sigplusbkg_Ms5000_EBEB.Write()
sigplusbkg_Ms5000_EBEB_varbin.Write()
sigplusbkg_Ms5000_EBEE.Write()
sigplusbkg_Ms5000_EBEE_varbin.Write()
sigplusbkg_Ms5500_EBEB.Write()
sigplusbkg_Ms5500_EBEB_varbin.Write()
sigplusbkg_Ms5500_EBEE.Write()
sigplusbkg_Ms5500_EBEE_varbin.Write()
sigplusbkg_Ms6000_EBEB.Write()
sigplusbkg_Ms6000_EBEB_varbin.Write()
sigplusbkg_Ms6000_EBEE.Write()
sigplusbkg_Ms6000_EBEE_varbin.Write()
sig_Ms3000_EBEB.Write()
sig_Ms3000_EBEB_varbin.Write()
sig_Ms3000_EBEB_30003500varbin.Write()
sig_Ms3000_EBEE.Write()
sig_Ms3000_EBEE_varbin.Write()
sig_Ms3000_EBEE_30003500varbin.Write()
sig_Ms3500_EBEB.Write()
sig_Ms3500_EBEB_varbin.Write()
sig_Ms3500_EBEB_30003500varbin.Write()
sig_Ms3500_EBEE.Write()
sig_Ms3500_EBEE_varbin.Write()
sig_Ms3500_EBEE_30003500varbin.Write()
sig_Ms4000_EBEB.Write()
sig_Ms4000_EBEB_varbin.Write()
sig_Ms4000_EBEE.Write()
sig_Ms4000_EBEE_varbin.Write()
sig_Ms4500_EBEB.Write()
sig_Ms4500_EBEB_varbin.Write()
sig_Ms4500_EBEE.Write()
sig_Ms4500_EBEE_varbin.Write()
sig_Ms5000_EBEB.Write()
sig_Ms5000_EBEB_varbin.Write()
sig_Ms5000_EBEE.Write()
sig_Ms5000_EBEE_varbin.Write()
sig_Ms5500_EBEB.Write()
sig_Ms5500_EBEB_varbin.Write()
sig_Ms5500_EBEE.Write()
sig_Ms5500_EBEE_varbin.Write()
sig_Ms6000_EBEB.Write()
sig_Ms6000_EBEB_varbin.Write()
sig_Ms6000_EBEE.Write()
sig_Ms6000_EBEE_varbin.Write()
bkg_EBEB.Write()
bkg_EBEB_varbin.Write()
bkg_EBEB_30003500varbin.Write()
bkg_EBEE.Write()
bkg_EBEE_varbin.Write()
bkg_EBEE_30003500varbin.Write()

