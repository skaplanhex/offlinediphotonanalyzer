void formatHist(TH1* hist, TString xTitle, TString yTitle){
    hist->GetXaxis()->SetTitle(xTitle);
    hist->GetYaxis()->SetTitle(yTitle);
}
void formatHist2(TH2* hist, TString xTitle, TString yTitle){
    hist->GetXaxis()->SetTitle(xTitle);
    hist->GetYaxis()->SetTitle(yTitle);
}

TH1D* createTH1D(TString name, TString title, Int_t nBins, Double_t lowEdge, Double_t highEdge, TString xTitle, TString yTitle){

    TH1D* hist = new TH1D(name,title,nBins,lowEdge,highEdge);
    formatHist(hist,xTitle,yTitle);
    return hist;
}
TH1D* createTH1D(TString name, TString title, Int_t nBins, Double_t binEdges[], TString xTitle, TString yTitle){

    TH1D* hist = new TH1D(name,title,nBins,binEdges);
    formatHist(hist,xTitle,yTitle);
    return hist;
}
TH2D* createTH2D(TString name, TString title, Int_t nBinsX, Double_t lowEdgeX, Double_t highEdgeX, Int_t nBinsY, Double_t lowEdgeY, Double_t highEdgeY, TString xTitle, TString yTitle){

    TH2D* hist = new TH2D(name,title,nBinsX,lowEdgeX,highEdgeX,nBinsY,lowEdgeY,highEdgeY);
    formatHist2(hist,xTitle,yTitle);
    return hist;
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

// double getFakeRate(double pt, double eta, int sysNum = 0){

//     enum fakeRateSys{
//       kNoSys  = 0,
//       kEBDown = 1,
//       kEBUp   = 2,
//       kEEDown = 3,
//       kEEUp   = 4
//     };

//     std::map<int,double> sysFactorMap;
//     sysFactorMap[0] = 1.:
//     sysFactorMap[1] = 0.65:
//     sysFactorMap[2] = 1.16:
//     sysFactorMap[3] = 0.7:
//     sysFactorMap[4] = 1.08:
//     // fake rate in the barrel
//     if ( isEB(eta) ){
//        // double P0 = 0.00225252571161;
//        // double P1 = 30882.04375711645480;
//        // double P2 = 3.25285076412319;
//        double P0 = 0.02854062423359;
//        double P1 = 1054.67561386442435;
//        double P2 = 2.43255894722459;
//        return P0 + ( P1 / TMath::Power(pt,P2) );
//     }
//     // fake rate in the endcaps
//     else if ( isEE(eta) ){
//         if (pt <= 175.){
//       // double P0 = 0.00984487675098;
//       // double P1 = 0.00001462335960;
//       // double P2 = 0.00000249248908;
//       double P0 = 0.07583295145724;
//       double P1 = 0.00003927399330;
//       double P2 = 0.00000255676015;
//       return P0 + P1*(pt-175.) + P2*(pt-175.)*(pt-175.);
//         }
//         else{
//       // double slope = 0.00001462335960;
//       // double yint = 0.00728578882033;
//       double slope = 0.00003927399330;
//       double yint = 0.06896000263001;
//       return yint + slope*pt;
//         }
//     }
//     else return -1.; // something is wrong then...
// }

