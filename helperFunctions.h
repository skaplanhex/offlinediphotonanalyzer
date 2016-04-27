void formatHist(TH1* hist, TString xTitle, TString yTitle){
    hist->GetXaxis()->SetTitle(xTitle);
    hist->GetYaxis()->SetTitle(yTitle);
}


bool isEB(Double_t eta){
    if (fabs(eta) < 1.4442) return true;
    else return false;
}
bool isEE(Double_t eta){
    if (1.566 < fabs(eta) && fabs(eta) < 2.5) return true;
    else return false;
}

bool isEBEB(Double_t eta1, Double_t eta2){
    if (isEB(eta1) && isEB(eta2)) return true;
    else return false;
}

bool isEBEE(Double_t eta1, Double_t eta2){
    if ( isEB(eta1) && isEE(eta2) ) return true;
    else if ( isEB(eta2) && isEE(eta1) ) return true;
    else return false;
}