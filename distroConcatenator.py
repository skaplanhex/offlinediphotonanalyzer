# This module takes distributions that are binned, reweights them, adds them together, and returns the result.  

from ROOT import *
from numpy import array

# info is a list of lists, where the lists contain the following information in this order:
# [
#   TH1D histogram of the distribution for that particular bin,
#   cross section of the process (must be in the same units as 1/luminosity!),
#   number of events
# ]
#
# The number of lists needed is equal to the number of bins that need to be summed.
# finalHistoName is, as expected, the name of the histogram to be returned.
# lumi is the integrated luminosity, needs to be in units of 1/(xs unit).
def concatenate(info,finalHistoName,lumi):

    fileNames=[]
    histoLocations=[]
    crossSections=[]
    nEventsList=[]
    for i in info:
        fileNames.append( i[0] )
        histoLocations.append( i[1] )
        crossSections.append( float(i[2]) )
        nEventsList.append( int(i[3]) )

    # assume explicitly that the binning is the same (which it should be)
    tempFile = TFile(fileNames[0],"read")
    tempHist = tempFile.Get(histoLocations[0])

    nBins = tempHist.GetNbinsX()
    # lowEdge = tempHist.GetBinLowEdge(1)
    # upperEdge = tempHist.GetBinLowEdge( nBins + 1 )
    binBorders = []
    for i in range( 1,nBins + 2 ): # last i in loop is the overflow bin
        binBorders.append( tempHist.GetBinLowEdge(i) )

    tempFile.Close()
    binBorders = array(binBorders)
    finalHisto = TH1D( finalHistoName, "", len(binBorders)-1, binBorders )
    for binNum,bin in enumerate(info):
        tempFile = TFile( fileNames[binNum], "read" )
        histo = tempFile.Get( histoLocations[binNum] )
        xs = crossSections[binNum]
        nevents = nEventsList[binNum]
        # histo.Sumw2()
        histo.Scale( (xs/nevents)*lumi )
        finalHisto.Add(histo,1.)
    return finalHisto
        