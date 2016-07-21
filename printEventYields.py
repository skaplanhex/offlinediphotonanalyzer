print "Loading ROOT..."
from ROOT import *
print "done."

infile = TFile("ADDFinalHistos.root","read")

#first get the background info
bkg30003500EBEBstr=""
bkg30003500EBEEstr=""
histbkg30003500EBEB = infile.Get("ggMass_ADDBkg_EBEB_30003500varbin")
histbkg30003500EBEE = infile.Get("ggMass_ADDBkg_EBEE_30003500varbin")
for i in (2,3,4,5):
    valueEBEB = histbkg30003500EBEB.GetBinContent(i)
    valueEBEE = histbkg30003500EBEE.GetBinContent(i)

    errorEBEB = histbkg30003500EBEB.GetBinError(i)
    errorEBEE = histbkg30003500EBEE.GetBinError(i)

    tempEBEB = "%.4f+-%.4f,"%(valueEBEB,errorEBEB)
    tempEBEE = "%.4f+-%.4f,"%(valueEBEE,errorEBEE)

    bkg30003500EBEBstr += tempEBEB
    bkg30003500EBEEstr += tempEBEE

bkgEBEBstr=""
bkgEBEEstr=""
histbkgEBEB = infile.Get("ggMass_ADDBkg_EBEB_varbin")
histbkgEBEE = infile.Get("ggMass_ADDBkg_EBEE_varbin")
for i in (2,3,4,5,6):
    valueEBEB = histbkgEBEB.GetBinContent(i)
    valueEBEE = histbkgEBEE.GetBinContent(i)

    errorEBEB = histbkgEBEB.GetBinError(i)
    errorEBEE = histbkgEBEE.GetBinError(i)

    tempEBEB = "%.4f+-%.4f,"%(valueEBEB,errorEBEB)
    tempEBEE = "%.4f+-%.4f,"%(valueEBEE,errorEBEE)

    bkgEBEBstr += tempEBEB
    bkgEBEEstr += tempEBEE

# first 30003500
sigEBEB30003500vec=[]
sigEBEE30003500vec=[]

for ms in (3000,3500):
    histNameEBEB = "sig_Ms%i_EBEB_30003500varbin"%ms
    histNameEBEE = "sig_Ms%i_EBEE_30003500varbin"%ms

    histEBEB = infile.Get(histNameEBEB)
    histEBEE = infile.Get(histNameEBEE)

    stringEBEB = ""
    stringEBEE = ""

    for i in (2,3,4,5):
        valueEBEB = histEBEB.GetBinContent(i)
        valueEBEE = histEBEE.GetBinContent(i)

        errorEBEB = histEBEB.GetBinError(i)
        errorEBEE = histEBEE.GetBinError(i)

        tempEBEB = "%.4f+-%.4f,"%(valueEBEB,errorEBEB)
        tempEBEE = "%.4f+-%.4f,"%(valueEBEE,errorEBEE)

        stringEBEB += tempEBEB
        stringEBEE += tempEBEE
        
    sigEBEB30003500vec.append(stringEBEB)
    sigEBEE30003500vec.append(stringEBEE)



sigEBEBvec=[]
sigEBEEvec=[]
for ms in (4000,4500,5000,5500,6000):
    histNameEBEB = "sig_Ms%i_EBEB_varbin"%ms
    histNameEBEE = "sig_Ms%i_EBEE_varbin"%ms

    histEBEB = infile.Get(histNameEBEB)
    histEBEE = infile.Get(histNameEBEE)

    stringEBEB = ""
    stringEBEE = ""

    for i in (2,3,4,5,6):
        valueEBEB = histEBEB.GetBinContent(i)
        valueEBEE = histEBEE.GetBinContent(i)

        errorEBEB = histEBEB.GetBinError(i)
        errorEBEE = histEBEE.GetBinError(i)

        tempEBEB = "%.4f+-%.4f,"%(valueEBEB,errorEBEB)
        tempEBEE = "%.4f+-%.4f,"%(valueEBEE,errorEBEE)

        stringEBEB += tempEBEB
        stringEBEE += tempEBEE

    sigEBEBvec.append(stringEBEB)
    sigEBEEvec.append(stringEBEE)

# print 3000-3500 blocks first
print "EBEB (Ms < 4 TeV)"
print bkg30003500EBEBstr
for i in range(len(sigEBEB30003500vec)):
    print sigEBEB30003500vec[i]

print ""
print "EBEE (Ms < 4 TeV)"
print bkg30003500EBEEstr
for i in range(len(sigEBEE30003500vec)):
    print sigEBEE30003500vec[i]

# now print >=4000 blocks
print ""
print "EBEB (Ms >= 4 TeV)"
print bkgEBEBstr
for i in range(len(sigEBEBvec)):
    print sigEBEBvec[i]

print ""
print "EBEE (Ms >= 4 TeV)"
print bkgEBEEstr
for i in range(len(sigEBEEvec)):
    print sigEBEEvec[i]