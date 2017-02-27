print "Loading ROOT..."
from ROOT import *
print "done."

def makeHistStr(fname,histname,firstcol):
    f = TFile(fname,"read")
    h = f.Get(histname)
    s = firstcol+","
    for i in (1,2,3,4,5,6):
        value = h.GetBinContent(i)
        s += "%.4f,"%value
    return s

infile = TFile("thetainput_Hewett.root","read")
fakefile = TFile("fakePlotsNew5.root","read")

dataEBEBstr="Data,"
dataEBEEstr="Data,"

histdataEBEB = infile.Get("mggEBEB__DATA")
histdataEBEE = infile.Get("mggEBEE__DATA")
for i in (1,2,3,4,5,6):
    valueEBEB = histdataEBEB.GetBinContent(i)
    valueEBEE = histdataEBEE.GetBinContent(i)

    errorEBEB = histdataEBEB.GetBinError(i)
    errorEBEE = histdataEBEE.GetBinError(i)

    tempEBEB = "%.4f,"%(valueEBEB)
    tempEBEE = "%.4f,"%(valueEBEE)

    dataEBEBstr += tempEBEB
    dataEBEEstr += tempEBEE

bkgEBEBstr="SMDiphoton,"
bkgEBEEstr="SMDiphoton,"
histbkgEBEB = infile.Get("mggEBEB__SMDiphoton")
histbkgEBEE = infile.Get("mggEBEE__SMDiphoton")
for i in (1,2,3,4,5,6):
    valueEBEB = histbkgEBEB.GetBinContent(i)
    valueEBEE = histbkgEBEE.GetBinContent(i)

    errorEBEB = histbkgEBEB.GetBinError(i)
    errorEBEE = histbkgEBEE.GetBinError(i)

    tempEBEB = "%.4f,"%(valueEBEB)
    tempEBEE = "%.4f,"%(valueEBEE)

    bkgEBEBstr += tempEBEB
    bkgEBEEstr += tempEBEE

fakeEBEBstr="Fake,"
fakeEBEEstr="Fake,"
histfakeEBEB = infile.Get("mggEBEB__Fake")
histfakeEBEE = infile.Get("mggEBEE__Fake")
for i in (1,2,3,4,5,6):
    valueEBEB = histfakeEBEB.GetBinContent(i)
    valueEBEE = histfakeEBEE.GetBinContent(i)

    errorEBEB = histfakeEBEB.GetBinError(i)
    errorEBEE = histfakeEBEE.GetBinError(i)

    tempEBEB = "%.4f,"%(valueEBEB)
    tempEBEE = "%.4f,"%(valueEBEE)

    fakeEBEBstr += tempEBEB
    fakeEBEEstr += tempEBEE

# LT, LL
LTEBEBstr = "Loose-Tight,"
LTEBEEstr = "Loose-Tight,"
LLEBEBstr = "Loose-Loose,"
LLEBEEstr = "Loose-Loose,"
histtlEBEB = fakefile.Get("tlMass_EBEB_varbin")
histtlEBEE = fakefile.Get("tlMass_EBEE_varbin")
histllEBEB = fakefile.Get("llMass_EBEB_varbin")
histllEBEE = fakefile.Get("llMass_EBEE_varbin")
for i in (1,2,3,4,5,6):
    val_tl_EBEB = histtlEBEB.GetBinContent(i)
    val_tl_EBEE = histtlEBEE.GetBinContent(i)
    val_ll_EBEB = histllEBEB.GetBinContent(i)
    val_ll_EBEE = histllEBEE.GetBinContent(i)

    LTEBEBstr += "%.4f,"%val_tl_EBEB
    LTEBEEstr += "%.4f,"%val_tl_EBEE
    LLEBEBstr += "%.4f,"%val_ll_EBEB
    LLEBEEstr += "%.4f,"%val_ll_EBEE

# signal

sigEBEBvec=[]
sigEBEEvec=[]
for ms in (3000,3500,4000,4500,5000,5500,6000):
    histNameEBEB = "mggEBEB__Ms%i"%ms
    histNameEBEE = "mggEBEE__Ms%i"%ms

    histEBEB = infile.Get(histNameEBEB)
    histEBEE = infile.Get(histNameEBEE)

    stringEBEB = "ADD_Ms%i,"%ms
    stringEBEE = "ADD_Ms%i,"%ms

    for i in (1,2,3,4,5,6):
        valueEBEB = histEBEB.GetBinContent(i)
        valueEBEE = histEBEE.GetBinContent(i)

        errorEBEB = histEBEB.GetBinError(i)
        errorEBEE = histEBEE.GetBinError(i)

        tempEBEB = "%.4f,"%(valueEBEB)
        tempEBEE = "%.4f,"%(valueEBEE)

        stringEBEB += tempEBEB
        stringEBEE += tempEBEE

    sigEBEBvec.append(stringEBEB)
    sigEBEEvec.append(stringEBEE)

# fake systematics


fakeEBEB_EBUpstr= makeHistStr("thetainput_Hewett.root","mggEBEB__Fake__EBFakeRate__plus","FakeEBEB_EBUp")
fakeEBEB_EBDownstr=makeHistStr("thetainput_Hewett.root","mggEBEB__Fake__EBFakeRate__minus","FakeEBEB_EBDown")
fakeEBEE_EBUpstr=makeHistStr("thetainput_Hewett.root","mggEBEE__Fake__EBFakeRate__plus","FakeEBEE_EBUp")
fakeEBEE_EBDownstr=makeHistStr("thetainput_Hewett.root","mggEBEE__Fake__EBFakeRate__minus","FakeEBEE_EBDown")
fakeEBEE_EEUpstr=makeHistStr("thetainput_Hewett.root","mggEBEE__Fake__EEFakeRate__plus","FakeEBEE_EEUp")
fakeEBEE_EEDownstr=makeHistStr("thetainput_Hewett.root","mggEBEE__Fake__EEFakeRate__minus","FakeEBEE_EEDown")


# print event yields
print "EBEB"
print bkgEBEBstr
print fakeEBEBstr
for i in range(len(sigEBEBvec)):
    print sigEBEBvec[i]
print dataEBEBstr
print LTEBEBstr
print LLEBEBstr

print ""
print "EBEE"
print bkgEBEEstr
print fakeEBEEstr
for i in range(len(sigEBEEvec)):
    print sigEBEEvec[i]
print dataEBEEstr
print LTEBEEstr
print LLEBEEstr

# print ""
print "Fake Systematics"
print fakeEBEBstr.replace("Fake","FakeEBEB")
print fakeEBEB_EBUpstr
print fakeEBEB_EBDownstr
print fakeEBEEstr.replace("Fake","FakeEBEE")
print fakeEBEE_EBUpstr
print fakeEBEE_EBDownstr
print fakeEBEE_EEUpstr
print fakeEBEE_EEDownstr