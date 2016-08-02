// wuROOT.hh --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 二 3月 17 19:43:12 2015 (+0800)
// Last-Updated: 六 4月 23 14:53:09 2016 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 137
// URL: http://wuhongyi.github.io 

#ifndef _WUROOT_H_
#define _WUROOT_H_

//A B C D E F G H I J K L M N O P Q R S T U V W X Y Z

#include <RooDataSet.h>
#include <RooRealVar.h>

#include "TAxis.h"
#include "TCanvas.h"
#include "TChain.h"
#include "TCutG.h"
#include "TGaxis.h"
#include "TGraph.h"
#include "TF1.h"
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include "THStack.h"

#include "TLatex.h"
#include "TLegend.h"
#include "TLine.h"
#include "TList.h"
#include "TMath.h"
#include "TObject.h"
#include "TPad.h"
#include "TPaveLabel.h"
#include "TPaveStats.h"
#include "TROOT.h"
#include "TSlider.h"
#include "TString.h"
#include "TStyle.h"
#include "TSystem.h"
#include "TTree.h"
#include "TVirtualPad.h"

#include <vector>

// #include <TH1F.h>
// #include <TH2F.h>
// #include <TH3F.h>
// #include <TVector3.h>
// #include <TLorentzVector.h>
// #include <TColor.h>
// #include <THStack.h>
// #include <TGraphErrors.h>

// #include <TClonesArray.h>
// #include <TParticle.h>
// #include <TImage.h>
// using namespace RooFit;
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// Color:

// 1=black
// 2=red
// 3=bright green
// 4=bright blue
// 5=yellow
// 6=hot pink
// 7=aqua 浅绿色，水绿色
// 8=green
// 9=blue
// 0->9:basic colors
// 10->19:gray shades
// 20->29:brown shades
// 30->39:blue shades
// 40->49:red shades

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// LineStyle：

// 1=solid
// 2=dash
// 3=dot
// 4=dash-dot

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

//MarkerStyle:

// 1=小点
// 2=+
// 3=*
// 4=空心圆
// 5=X
// 6=小+
// 7=小实心正方形
// 8=实心圆
// 9=小短线
// 10=小短线
// 11=小短线
// 20=实心圆
// 21=实心正方形
// 22=实心正三角形
// 23=实心倒三角形
// 24=空心圆
// 25=空心正方形
// 26=空心正三角形
// 27=空心菱形
// 28=空心十字架
// 29=实心五角星
// 30=空心五角星

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// Text Font:

// Use TAttText::SetTextFont to set the font. The parameter font is the font code, combining the font and precision:
// font = 10 * fontID + precision
// root[] la->SetTextFont(font)
// The table below lists the available fonts. The font IDs must be between 1 and 14. The precision can be:
// • Precision = 0 fast hardware fonts (steps in the size)
// • Precision = 1 scalable and rotate-able hardware fonts (see below)
// • Precision = 2 scalable and rotate-able hardware fonts

// Font   ID X11                         True Type name       Is italic     “boldness”
// 1      times-medium-i-normal          “Times New Roman”    Yes           4
// 2      times-bold-r-normal            “Times New Roman”    No            7
// 3      times-bold-i-normal            “Times New Roman”    Yes           7
// 4      helvetica-medium-r-normal      “Arial”              No            4
// 5      helvetica-medium-o-normal      “Arial”              Yes           4
// 6      helvetica-bold-r-normal        “Arial”              No            7
// 7      helvetica-bold-o-normal        “Arial”              Yes           7
// 8      courier-medium-r-normal        “Courier New”        No            4
// 9      courier-medium-o-normal        “Courier New”        Yes           4
// 10     courier-bold-r-normal          “Courier New”        No            7
// 11     courier-bold-o-normal          “Courier New”        Yes           7
// 12     symbol-medium-r-normal         “Symbol”             No            6
// 13     times-medium-r-normal          “Times New Roman”    No            4
// 14                                    “Wingdings”          No            4

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// Text Size:
// Use TAttText::SetTextSize to set the text size.
// root[] la->SetTextSize(size)
// The size is the text size expressed in percentage of the current pad size.
// The text size in pixels will be:
// • If current pad is horizontal, the size in pixels = textsize * canvas_height
// • If current pad is vertical, the size in pixels = textsize * canvas_width

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


//Histograms  Graph

namespace wuROOT{

  //设置 stats 统计框位置、大小、颜色
void MoveStat(TH1* h,Double_t x0,Double_t y0,Double_t x1, Double_t y1,Int_t icolor=1)
{
  gPad->Modified();
  gPad->Update();
  TPaveStats *pstmp = (TPaveStats*)h->GetListOfFunctions()->FindObject("stats");
  pstmp->SetX1NDC(x0);
  pstmp->SetX2NDC(x1);
  pstmp->SetY1NDC(y0); 
  pstmp->SetY2NDC(y1);
  pstmp->SetTextColor(icolor);
  gPad->Modified();
  gPad->Update();
}

void MoveStat(TCanvas *ctmp,TH1* h,Double_t x0,Double_t y0,Double_t x1, Double_t y1,Int_t icolor=1)
{
  ctmp->Modified();
  ctmp->Update();
  TPaveStats *pstmp = (TPaveStats*)h->GetListOfFunctions()->FindObject("stats");
  pstmp->SetX1NDC(x0);
  pstmp->SetX2NDC(x1);
  pstmp->SetY1NDC(y0); 
  pstmp->SetY2NDC(y1);
  pstmp->SetTextColor(icolor);
  ctmp->Modified();
  ctmp->Update();
}

void MoveStat(TCanvas *ctmp,TH2* h,Double_t x0,Double_t y0,Double_t x1, Double_t y1,Int_t icolor=1)
{
  ctmp->Modified();
  ctmp->Update();
  TPaveStats *pstmp = (TPaveStats*)h->GetListOfFunctions()->FindObject("stats");
  pstmp->SetX1NDC(x0);
  pstmp->SetX2NDC(x1);
  pstmp->SetY1NDC(y0); 
  pstmp->SetY2NDC(y1);
  pstmp->SetTextColor(icolor);
  ctmp->Modified();
  ctmp->Update();
}





//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//
//    Histograms
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

  //一维直方图中只Fill在坐标范围的数据，超出范围的不填充
  template <class T> //TH1F TH1D
  Bool_t FillTH1InRange(T fin,TH1 *histtmp, Double_t w = 1.0)
  {
    if(histtmp->GetXaxis()->GetXmin()<= fin && fin <histtmp->GetXaxis()->GetXmax()){
      histtmp->Fill(Double_t(fin),w);
      return true;
    }else return false;
  }
  //二维直方图中只Fill在坐标范围的数据，超出范围的不填充
  template <class T> //TH2F TH2D
  Bool_t FillTH2InRange(T finx,T finy, TH2 *histtmp, Double_t w = 1.0)
  {
    if(!(histtmp->GetXaxis()->GetXmin()<= finx && finx <histtmp->GetXaxis()->GetXmax())) return false;
    if(!(histtmp->GetYaxis()->GetXmin()<= finy && finy <histtmp->GetYaxis()->GetXmax())) return false;
    histtmp->Fill(Double_t(finx),Double_t(finy),w);
    return true;
  }
  //三维直方图中只Fill在坐标范围的数据，超出范围的不填充
  template <class T>
  Bool_t FillTH3InRange(T finx,T finy,T finz, TH3 *histtmp, Double_t w = 1.0)
  {
    if(!(histtmp->GetXaxis()->GetXmin()<= finx && finx <histtmp->GetXaxis()->GetXmax())) return false;
    if(!(histtmp->GetYaxis()->GetXmin()<= finy && finy <histtmp->GetYaxis()->GetXmax())) return false;
    if(!(histtmp->GetZaxis()->GetXmin()<= finz && finz <histtmp->GetZaxis()->GetXmax())) return false;
    histtmp->Fill(Double_t(finx),Double_t(finy),Double_t(finz),w);
    return true;
  }

  //在画板上显示直方图总计数
  void TextTH1Count(Double_t x0,Double_t y0,TH1 *h,const Char_t *sName="N=%.0f",Double_t TextSize=0.06,Int_t TextColor=1,Int_t TextFont=22)
  {
    //x0,y0为【0，1】之间数值，为在画板上的相对位置。x0=0为靠近左边界，y0=0为靠近底边界
    //   TextTH1Count(0.1,0.9,h1,"The Total Count : %.0f",0.03,1,22);

    h->SetStats(kFALSE);
    TLatex *ltx=new TLatex();
    ltx->SetNDC(kTRUE);
    ltx->SetTextColor(TextColor);
    ltx->SetTextFont(TextFont);
    ltx->SetTextSize(TextSize);
    ltx->DrawLatex(x0,y0,Form(sName,h->GetEntries()));
    gPad->Modified();
    gPad->Update();
  }

  //在每个bin上方显示其计数
  void TH1ShowCountEveryBin(TH1 *h, Int_t itxtColor=kRed, Double_t txtSize=0.07, Double_t fangle=45,Bool_t NoZeroBin=kTRUE){
    for(Int_t i=0; i<h->GetNbinsX();i++){
      Double_t x0 = h->GetBinCenter(i+1);
      Double_t y0 = h->GetBinContent(i+1);
    
      TLatex *ltx = new TLatex();
      ltx->SetNDC(kFALSE);
      ltx->SetTextColor(itxtColor);
      ltx -> SetTextFont(22);
      ltx->SetTextSize(txtSize);
      ltx->SetTextAngle(fangle);
      if(NoZeroBin ) {
	if(!(y0==0)) ltx->DrawLatex(x0,y0,Form("%.0f",y0));
      }else{
	if(!(y0==0)) ltx->DrawLatex(x0,y0,Form("%.0f",y0));
      }
    }
  }

  //将直方图 在范围内的Entries计数代替原来的Entries数
  void SetEntries(TH1 *h)
  {
    Int_t nBin = h->GetNbinsX();
    printf("nBin=%d\n",nBin);
    Double_t tot=0;
    for(Int_t i=0; i<nBin; i++){
      tot = tot + h->GetBinContent(i+1);
    }
    Double_t oldN = h->GetEntries();
    h->SetEntries(tot);
    printf("TH1 %s has been set entries from %.0f to %.0f\n",h->GetName(),oldN,h->GetEntries());
  }

  Int_t GetNumDigsFromErr(Double_t num)
  {
    Double_t thr = 4.9999;
    for(Int_t i=0; i<25; i++){
      if(num >= thr) {
	return i;
      }
      else thr *= 0.1;  
    }
    return -1;
  }
  Char_t *OutVal(Double_t Val,Double_t Err,Double_t factor=1)
  {
    Val= Val*factor;
    Err=Err*factor;
    Int_t ndig = GetNumDigsFromErr(Err);

    Char_t sFormat[100];
    sprintf(sFormat,"%%.%df#pm%%.%df",ndig,ndig);
  
    Char_t *VVerr= new Char_t[100];
    sprintf(VVerr,sFormat,Val,Err);
    return VVerr;
  }

  void TextEntries(Double_t x0, Double_t y0,TH1 *h,const char *sName="N=%.0f",Double_t sizeTxt=0.06)
  {
    h->SetStats(kFALSE);
    TLatex *ltx = new TLatex();
    ltx->SetNDC(kTRUE);
    ltx->SetTextColor(h->GetLineColor());
    ltx -> SetTextFont(22);
    ltx->SetTextSize(sizeTxt);
    ltx->DrawLatex(x0,y0,Form(sName,h->GetEntries()));
    gPad->Modified();
    gPad->Update();
  }


  void TextMean(Double_t x0, Double_t y0,TH1 *h,const char *sFormat="Mean=%.2f",Double_t fsize = 0.06)
  {
    h->SetStats(kFALSE);
    TLatex *ltx = new TLatex();
    ltx->SetNDC(kTRUE);
    ltx->SetTextColor(h->GetLineColor());
    ltx -> SetTextFont(22);
    ltx->SetTextSize(fsize);
    ltx->DrawLatex(x0,y0,Form(sFormat,h->GetMean()));
    gPad->Modified();
    gPad->Update();
  }

  void TextMeanAndMeanError(Double_t x0, Double_t y0,TH1 *h,const char *sFormat="Mean=%s",Double_t fsize = 0.06)
  {
    h->SetStats(kFALSE);
    TLatex *ltx = new TLatex();
    ltx->SetNDC(kTRUE);
    ltx->SetTextColor(h->GetLineColor());
    ltx -> SetTextFont(22);
    ltx->SetTextSize(fsize);
    ltx->DrawLatex(x0,y0,Form(sFormat,OutVal(h->GetMean(),h->GetMeanError())));
    gPad->Modified();
    gPad->Update();
  }

  void TextRMS(Double_t x0, Double_t y0,TH1 *h,const char *sFormat="RMS=%.2f",Double_t fsize = 0.06)
  {
    h->SetStats(kFALSE);
    TLatex *ltx = new TLatex();
    ltx->SetNDC(kTRUE);
    ltx->SetTextColor(h->GetLineColor());
    ltx -> SetTextFont(22);
    ltx->SetTextSize(fsize);
    ltx->DrawLatex(x0,y0,Form(sFormat,h->GetRMS()));
    gPad->Modified();
    gPad->Update();
  }

  void TextRMSAndRMSError(Double_t x0, Double_t y0,TH1 *h,const char *sFormat="RMS=%s",Double_t fsize = 0.06)
  {
    h->SetStats(kFALSE);
    TLatex *ltx = new TLatex();
    ltx->SetNDC(kTRUE);
    ltx->SetTextColor(h->GetLineColor());
    ltx -> SetTextFont(22);
    ltx->SetTextSize(fsize);
    ltx->DrawLatex(x0,y0,Form(sFormat,OutVal(h->GetRMS(),h->GetRMSError())));
    gPad->Modified();
    gPad->Update();
  }

  void TextR(Double_t x0, Double_t y0,TH1 *h,const char *sName="RMS/Mean=%s",Double_t sizeTxt=0.06)
  {
    h->SetStats(kFALSE);
    TLatex *ltx = new TLatex();
    ltx->SetNDC(kTRUE);
    ltx->SetTextColor(h->GetLineColor());
    ltx -> SetTextFont(22);
    ltx->SetTextSize(sizeTxt);

    Double_t M = h->GetMean();
    Double_t MErr = h->GetMeanError();

    Double_t RMS = h->GetRMS();
    Double_t RMSErr = h->GetRMSError();

    Double_t R = RMS/M;
    Double_t RErr = R*TMath::Sqrt( TMath::Power(MErr/M,2)+ TMath::Power(RMSErr/RMS,2));
    ltx->DrawLatex(x0,y0,Form(sName,OutVal(R,RErr)));
    gPad->Modified();
    gPad->Update();
  }



  void DrawTH2RainBowAndPalette(TH2* h,const char* opt="",double range = 10.)
  {
    // Draw a 2D histo with the rainbow colors and the palette besides
    TString options = "colz"; options += opt;
    if(gPad->GetLogz() == 0 && h->GetMaximum()<range) h->SetAxisRange(0.,range,"Z");
    h->SetStats(kFALSE);
    h->SetTitleOffset(0.8,"T");
    gPad->SetRightMargin(0.16);
    h->DrawCopy(options.Data());
  }




  //在 X 处画一条垂直 x 轴的线
  void LineX(Double_t X,Int_t iColor=kRed,Int_t iStyle=1,Double_t iWidth=1)
  {
    gPad->Modified();
    gPad->Update();
    TLine *ll=new TLine(X,gPad->GetUymin(),X,gPad->GetUymax());
    ll->SetLineColor(iColor);
    ll->SetLineStyle(iStyle);
    ll->SetLineWidth((Width_t)iWidth);
    ll->Draw();
  }
  //在 Y 处画一条垂直 y 轴的线
  void LineY(Double_t Y, Int_t iColor=kRed,Int_t iStyle=1,Double_t iWidth=1,const char *canvasName="c1"){
    TCanvas *ctmp =(TCanvas *)gROOT->GetListOfCanvases()->FindObject(canvasName);
    if(ctmp){
      ctmp->Modified();
      ctmp->Update();
      TLine *l1 = new TLine(gPad->GetUxmin(),Y,gPad->GetUxmax(),Y);
      l1->SetLineColor(iColor);
      l1->SetLineStyle(iStyle);
      l1->SetLineWidth((Width_t)iWidth);
      l1->Draw();
    }else{
      TLine *l1 = new TLine(gPad->GetUxmin(),Y,gPad->GetUxmax(),Y);
      l1->SetLineColor(iColor);
      l1->SetLineStyle(iStyle);
      l1->SetLineWidth((Width_t)iWidth);
      l1->Draw();
    } 
  }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//
//    Graph
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

  void GraphStyle(TGraph *gr,Int_t LineColor=1,Int_t LineWidth=1,Int_t LineStyle=1,Int_t MarkerColor=1,Int_t MarkerStyle=1,Double_t MarkerSize=1)
  {//Graph 样式设置
    gr->SetLineColor(LineColor);
    gr->SetLineWidth(LineWidth);
    gr->SetLineStyle(LineStyle);
    gr->SetMarkerColor(MarkerColor);
    gr->SetMarkerStyle(MarkerStyle);
    gr->SetMarkerSize(MarkerSize);
  }
  void GraphTitle(TGraph *gr,const char *Title="",const char *TitleX="",const char *TitleY="")
  {//Graph添加标题
    gr->SetTitle(Title);
    gr->GetXaxis()->SetTitle(TitleX);
    gr->GetYaxis()->SetTitle(TitleY);
  }


  void GraphDrawTextEachPoint(Double_t deltaX=0,Double_t deltaY=0,Double_t TextSize=0.025,Int_t TextFont=42,Int_t TextAlign=21)
  {// Draw a graph with text attached to each point.
   // TExec *ex = new TExec("ex","wuTStyle::drawtext(0,2);");
   // gr->GetListOfFunctions()->Add(ex);
    //为了避免数字被遮住，设置了deltaX、deltaY为偏离该点的位置。

    Int_t i,n;
    Double_t x,y;
    TLatex *l;

    TGraph *g = (TGraph*)gPad->GetListOfPrimitives()->FindObject("Graph");
    n = g->GetN();
    for (i=0; i<n; i++) 
      {
	g->GetPoint(i,x,y);
	//std::cout<<x<<"  "<<y<<std::endl;
	l = new TLatex(x+deltaX,y+deltaY,Form("%4.2f",y));
	l->SetTextSize(TextSize);
	l->SetTextFont(TextFont);
	l->SetTextAlign(TextAlign);
	l->Paint();
      }
  }


  void TH1TwoScales(TH1 *h)
  {
    //在图上有两个TH1时，将h刻度标在右边
    //scale h to the pad coordinates
    Float_t rightmax = 1.1*h->GetMaximum();
    Float_t scale = gPad->GetUymax()/rightmax;
    h->SetLineColor(kRed);
    h->Scale(scale);
    h->Draw("same");

    //draw an axis on the right side
    TGaxis *axis = new TGaxis(gPad->GetUxmax(),gPad->GetUymin(),
			      gPad->GetUxmax(), gPad->GetUymax(),0,rightmax,510,"+L");
    axis->SetLineColor(kRed);
    axis->SetLabelColor(kRed);
    axis->Draw();
  }

void TH1DrawNormalized(TH1 *h1, TH1 *h2)
{
  if (h1->GetEntries()==0) return;
  if (h2->GetEntries()==0) return;
  h1->SetStats(kFALSE);
  h2->SetStats(kFALSE);
  if(h1->GetMaximum()/h1->GetEntries()>h2->GetMaximum()/h2->GetEntries()){
    h1->DrawNormalized();
    h2->DrawNormalized("SAME");
  }else{
    h2->DrawNormalized();
    h1->DrawNormalized("SAME");
  }
}

void TH1DrawSame(TH1 *h1, TH1 *h2,Char_t Option1[],Char_t Option2[])
{
  if (h1->GetEntries()==0) return;
  if (h2->GetEntries()==0) return;
  h1->SetStats(kFALSE);
  h2->SetStats(kFALSE);
  if(h1->GetMaximum()>h2->GetMaximum()){
    h1->Draw(Option1);
    h2->Draw(Form("SAME,%s",Option2));
  }else{
    h2->Draw(Option2);
    h1->Draw(Form("SAME,%s",Option1));
  }

}

void THStackAddTH1(THStack *hs,TH1 *h1, TH1* h2,Bool_t setstyle = kTRUE,Bool_t norm = kTRUE)
{
  if(setstyle){
    h1->SetMarkerColor(kRed);
    h1->SetMarkerStyle(21);
    h1->SetLineColor(kRed);
    h2->SetMarkerColor(kBlue);
    h2->SetMarkerStyle(22);
    h2->SetLineColor(kBlue);
  }
  if(norm){
    h1->Sumw2();
    h1->Scale(1./h1->GetEntries());
    h2->Sumw2();
    h2->Scale(1./h2->GetEntries());
  }
  hs->Add(h1);
  hs->Add(h2);
}


THStack * THStackAddTH1(TH1 *h1, TH1* h2,Bool_t setstyle = kTRUE,Bool_t norm = kTRUE){
  THStack *hs = new THStack("hs",Form(";%s;%s",h1->GetXaxis()->GetTitle(),h1->GetYaxis()->GetTitle()));
  if(setstyle){
    h1->SetMarkerColor(kRed);
    h1->SetMarkerStyle(21);
    h1->SetLineColor(kRed);
    h2->SetMarkerColor(kBlue);
    h2->SetMarkerStyle(22);
    h2->SetLineColor(kBlue);
  }
  if(norm){
    h1->Sumw2();
    h1->Scale(1./h1->GetEntries());
    h2->Sumw2();
    h2->Scale(1./h2->GetEntries());
  }
  hs->Add(h1);
  hs->Add(h2);
  return hs;

}

THStack *THStackAddTH1(TH1 *h1, TH1* h2, TH1 *h3,Bool_t setstyle = kTRUE,Bool_t norm = kTRUE)
{
  THStack *hs = new THStack("hAll",Form(";%s;%s",h1->GetXaxis()->GetTitle(),h1->GetYaxis()->GetTitle()));
  if(setstyle){
    h1->SetMarkerColor(kRed);
    h1->SetMarkerStyle(21);
    h1->SetLineColor(kRed);
    h2->SetMarkerColor(kBlue);
    h2->SetMarkerStyle(25);
    h2->SetLineColor(kBlue);
    h3->SetMarkerColor(kBlack);
    h3->SetMarkerStyle(20);
    h3->SetLineColor(kBlack);
  }
  if(norm){
    h1->Sumw2();
    h1->Scale(1./h1->GetEntries());
    h2->Sumw2();
    h2->Scale(1./h2->GetEntries());
    h3->Sumw2();
    h3->Scale(1./h3->GetEntries());
  }
  hs->Add(h1);
  hs->Add(h2);
  hs->Add(h3);

  return hs;
}


THStack *THStackAddTH1(TH1 *h1, TH1* h2, TH1 *h3, TH1 *h4,Bool_t setstyle = kTRUE,Bool_t norm = kTRUE)
{
  THStack *hs = new THStack("hAll",Form(";%s;%s",h1->GetXaxis()->GetTitle(),h1->GetYaxis()->GetTitle()));
  if(setstyle){
    h1->SetMarkerColor(kRed);
    h1->SetMarkerStyle(21);
    h1->SetLineColor(kRed);
    h2->SetMarkerColor(kBlue);
    h2->SetMarkerStyle(25);
    h2->SetLineColor(kBlue);
    h3->SetMarkerColor(kBlack);
    h3->SetMarkerStyle(20);
    h3->SetLineColor(kBlack);
    h4->SetMarkerColor(kPink);
    h4->SetMarkerStyle(4);
    h4->SetLineColor(kPink);
  }
  if(norm){
    h1->Sumw2();
    h1->Scale(1./h1->GetEntries());
    h2->Sumw2();
    h2->Scale(1./h2->GetEntries());
    h3->Sumw2();
    h3->Scale(1./h3->GetEntries());
    h4->Sumw2();
    h4->Scale(1./h4->GetEntries());
  }
  hs->Add(h1);
  hs->Add(h2);
  hs->Add(h3);
  hs->Add(h4);

  return hs;
}


THStack *THStackAddTH1(TH1 *h1, TH1* h2, TH1 *h3, TH1 *h4,TH1 *h5,Bool_t setstyle = kTRUE,Bool_t norm = kTRUE)
{
  THStack *hs = new THStack("hAll",Form(";%s;%s",h1->GetXaxis()->GetTitle(),h1->GetYaxis()->GetTitle()));
  if(setstyle){
    h1->SetMarkerColor(kRed);
    h1->SetMarkerStyle(21);
    h1->SetLineColor(kRed);
    h2->SetMarkerColor(kBlue);
    h2->SetMarkerStyle(25);
    h2->SetLineColor(kBlue);
    h3->SetMarkerColor(kBlack);
    h3->SetMarkerStyle(20);
    h3->SetLineColor(kBlack);
    h4->SetMarkerColor(kPink);
    h4->SetMarkerStyle(4);
    h4->SetLineColor(kPink);
    h5->SetMarkerColor(kViolet);
    h5->SetMarkerStyle(29);
    h5->SetMarkerSize(1.2);
    h5->SetLineColor(kViolet);
  }
  if(norm){
    h1->Sumw2();
    h1->Scale(1./h1->GetEntries());
    h2->Sumw2();
    h2->Scale(1./h2->GetEntries());
    h3->Sumw2();
    h3->Scale(1./h3->GetEntries());
    h4->Sumw2();
    h4->Scale(1./h4->GetEntries());
    h5->Sumw2();
    h5->Scale(1./h5->GetEntries());
  }
  hs->Add(h1);
  hs->Add(h2);
  hs->Add(h3);
  hs->Add(h4);
  hs->Add(h5);

  return hs;
}



THStack *THStackAddTH1(TH1 *h1, TH1* h2, TH1 *h3, TH1 *h4,TH1 *h5,TH1 *h6,Bool_t setstyle = kTRUE,Bool_t norm = kTRUE)
{
  THStack *hs = new THStack("hAll",Form(";%s;%s",h1->GetXaxis()->GetTitle(),h1->GetYaxis()->GetTitle()));
  if(setstyle){
    h1->SetMarkerColor(kRed);
    h1->SetMarkerStyle(21);
    h1->SetLineColor(kRed);
    h2->SetMarkerColor(kBlue);
    h2->SetMarkerStyle(25);
    h2->SetLineColor(kBlue);
    h3->SetMarkerColor(kBlack);
    h3->SetMarkerStyle(20);
    h3->SetLineColor(kBlack);
    h4->SetMarkerColor(kPink);
    h4->SetMarkerStyle(4);
    h4->SetLineColor(kPink);
    h5->SetMarkerColor(kViolet);
    h5->SetMarkerStyle(29);
    h5->SetMarkerSize(1.2);
    h5->SetLineColor(kViolet);
    h6->SetMarkerColor(kBlue);
    h6->SetMarkerStyle(22);
    h6->SetMarkerSize(1.2);
    h6->SetLineColor(kBlue);
  }
  if(norm){
    h1->Sumw2();
    h1->Scale(1./h1->GetEntries());
    h2->Sumw2();
    h2->Scale(1./h2->GetEntries());
    h3->Sumw2();
    h3->Scale(1./h3->GetEntries());
    h4->Sumw2();
    h4->Scale(1./h4->GetEntries());
    h5->Sumw2();
    h5->Scale(1./h5->GetEntries());
    h6->Sumw2();
    h6->Scale(1./h6->GetEntries());
  }
  hs->Add(h1);
  hs->Add(h2);
  hs->Add(h3);
  hs->Add(h4);
  hs->Add(h5);
  hs->Add(h6);

  return hs;
}


void ReverseXAxis(TH1 *h,Int_t ndiv=510)
{
  //重新标X轴刻度，x从大到小。这样会导致错误的坐标表示
  // Remove the current axis
  h->GetXaxis()->SetLabelOffset(999);
  h->GetXaxis()->SetTickLength(0);

  // Redraw the new axis
  gPad->Update();
  TGaxis *newaxis = new TGaxis(gPad->GetUxmax(),
			       gPad->GetUymin(),
			       gPad->GetUxmin(),
			       gPad->GetUymin(),
			       h->GetXaxis()->GetXmin(),
			       h->GetXaxis()->GetXmax(),
			       ndiv,"-");
  newaxis->SetLabelOffset(-0.03);
  newaxis->Draw();
}

void ReverseYAxis(TH1 *h,Int_t ndiv=510)
{
  //重新标Y轴刻度，y从大到小。这样会导致错误的坐标表示
  // Remove the current axis
  h->GetYaxis()->SetLabelOffset(999);
  h->GetYaxis()->SetTickLength(0);

  // Redraw the new axis
  gPad->Update();
  TGaxis *newaxis = new TGaxis(gPad->GetUxmin(),
			       gPad->GetUymax(),
			       gPad->GetUxmin()-0.001,
			       gPad->GetUymin(),
			       h->GetYaxis()->GetXmin(),
			       h->GetYaxis()->GetXmax(),
			       ndiv,"+");
  newaxis->SetLabelOffset(-0.03);
  newaxis->Draw();
}

void SliderInLoop(Int_t i,Int_t total,TSlider *slider,TPad *pad)
{
  //动态显示 进度条
  //i/total  为当前百分比
  //使用前先参考以下三行创建TSlider，其中 4.2、4.6 为进度条在x轴的位置
  //TSlider *slider = 0;
  //slider = new TSlider("slider","test",4.2,0,4.6,total->GetMaximum(),38);
  //slider->SetFillColor(46);

  //Slider(1,10000,slider,c1);//循环时候使用
  //slider->SetRange(0,1);//循环结束时调用，因为i经常不是遍历。
  if (slider) slider->SetRange(0,Float_t(i)/Float_t(total));
  pad->Modified();
  pad->Update();

}

void PadRefresh(TPad *pad,int flag=0)
{
  //刷新画板
  //TCanvas 是从 TPad 继承来的
  //padRefresh(c1)；

  if (!pad) return;
  pad->Modified();
  pad->Update();
  TList *tl = pad->GetListOfPrimitives();
  if (!tl) return;
  TListIter next(tl);
  TObject *to;
  while ((to=next())) {
    if (to->InheritsFrom(TPad::Class())) PadRefresh((TPad*)to,1);}
  if (flag) return;
  gSystem->ProcessEvents();
}


void DrawText(Double_t posX = 0., Double_t posY = 0., const char* text = "",
	      Double_t size=0.08, Int_t col=1)
{
  // Drawing some text
  TLatex* pText=new TLatex(posX,posY,text);
  pText->SetNDC(kTRUE);
  pText->SetTextColor(col); pText->SetTextSize(size);
  pText->Draw();
}


  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
  //  Data
  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void FillCutG(TCutG *cutg,std::vector<Double_t> x,std::vector<Double_t> y)
{
  cutg->Clear();
  Int_t iSize = (Int_t)x.size();
  for(Int_t i=0; i<iSize; i++){
    cutg->SetPoint(i,x[i],y[i]);
    printf("cutG: %d %f %f\n",i,x[i],y[i]);
  }
  return;
}

//一维直方图中在阈值以下的计数占总计数的比例
Double_t TH1PercentInLeft(Double_t Thre, TH1 *h)
{
  Double_t tot = 0;
  Double_t less = 0;
  Int_t nBin = h->GetNbinsX();
  for(Int_t i=0; i<nBin; i++){
    Double_t d = h->GetBinContent(i+1);
    Double_t x = h->GetBinCenter(i+1);
    tot += d;
    if(x<Thre) less +=d;
  }
  if(tot==0) return 0;
  else return less/tot; 
}

void VectorToTH1(std::vector<Double_t> *v,TH1 *h,Bool_t rangeLim=kTRUE)
{
  Double_t xmin = h->GetXaxis()->GetXmin();
  Double_t xmax = h->GetXaxis()->GetXmax();
  Int_t n = v->size();
  for(Int_t i=0; i<n; i++){
    if(rangeLim){
      if( (*v)[i]>=xmin && (*v)[i]<xmax) h->Fill((*v)[i]);
    }else{
      h->Fill((*v)[i]);
    }
  }
}


void WriteVectorToDataSet(std::vector <Double_t> *v,RooRealVar x,RooDataSet *data, Bool_t rangeLim=kTRUE)
{
  Double_t xmin = x.getMin();
  Double_t xmax = x.getMax();
  Int_t n = v->size();
  Double_t tmp;
  for(Int_t i=0; i<n; i++){
    tmp = (*v)[i];
    x = tmp;
    if(rangeLim){
      if(tmp>=xmin && tmp<xmax)data->add(x);
    }else{
      data->add(x);
    }
  }
} 

TH1 *ReadTH1InFile(Char_t rootName[],Char_t histName[])
{
  printf("read %s from %s\n",histName,rootName);
  TH1 *htmpTH1 = NULL;
  TFile fin(rootName,"READ");
  htmpTH1 = (TH1 *) fin.Get(histName);
  htmpTH1->SetDirectory(0);
  fin.Close();
  if(htmpTH1 == NULL){
    printf("Can not find %s in %s\n",histName,rootName);
  }
  return htmpTH1;
}

//Read roots in dirName to TChain with treeName
TChain *ReadFilesToChain(Char_t dirName[],Char_t treeName[]){
  TChain *chain = new TChain(treeName);
  Char_t fileName[1000];
  Int_t n = 1;
  FILE *pf = fopen(dirName,"rt");
  if(pf==NULL) {
    printf("%s Open Error\n",dirName);
    return NULL;
  }
  Int_t itotal = 0;
  while(n==1){
    n = fscanf(pf,"%s\n",fileName);
    if(n==1){
      chain->Add(fileName);
      printf("%s Added No.%d\n",fileName,itotal);
      itotal++;
    }
  }
  return chain;
}

//从TFile读取Tree中某个Branch的数据填充到直方图
void ReadDoubleDataFromFileToTH1(TH1 *h,Char_t FileName[], Char_t TreeName[], Char_t BranchName[])
{
  TFile f(FileName);
  TTree *pTreeName = (TTree *)f.Get(TreeName);
  Double_t dBran;
  pTreeName -> SetBranchAddress(BranchName,&dBran);
  Long64_t nentries = pTreeName->GetEntries();

  Long64_t nbytes = 0;
  Double_t xmin = h->GetXaxis()->GetXmin();
  Double_t xmax = h->GetXaxis()->GetXmax();
  printf("read %s from tree %s in %s with Entries=%lld\n",BranchName,TreeName,FileName,nentries);
  Double_t nBefore = h->GetEntries();
  Long64_t Step = nentries/10;
  for (Long64_t i=0; i<nentries;i++) {
    nbytes += pTreeName->GetEntry(i);
    if(i % Step == 1) printf("%lld of %lld in %s\n",i,nentries,FileName);
    if(xmin<= dBran && dBran<xmax){
      h->Fill(dBran);
    }
  }
  Double_t nAfter = h->GetEntries();
  printf("in ReadDoubleDataFromFileToTH1: Finish Read in Hist %s with Entries from %.0f to %.0f\n",h->GetName(),nBefore,nAfter);
  f.Close();
  return;
}

void ReadDoubleDataFromFileToTH1AndVector(TH1 *h,std::vector<Double_t> *toV,Char_t FileName[], Char_t TreeName[], Char_t BranchName[])
{
  TFile f(FileName);
  TTree *pTreeName = (TTree *)f.Get(TreeName);
  Double_t dBran;
  pTreeName -> SetBranchAddress(BranchName,&dBran);
  Long64_t nentries = pTreeName->GetEntries();

  Long64_t nbytes = 0;
  Double_t xmin = h->GetXaxis()->GetXmin();
  Double_t xmax = h->GetXaxis()->GetXmax();
  printf("read %s from tree %s in %s with Entries=%lld\n",BranchName,TreeName,FileName,nentries);
  Double_t nBefore = h->GetEntries();
  Long64_t Step = nentries/10;
  for (Long64_t i=0; i<nentries;i++) {
    nbytes += pTreeName->GetEntry(i);
    if(i % Step == 1) printf("%lld of %lld in %s\n",i,nentries,FileName);
    if(xmin<= dBran && dBran<xmax){
      h->Fill(dBran);
      toV->push_back(dBran);
    }
  }
  Double_t nAfter = h->GetEntries();
  printf("in ReadDoubleDataFromFileToTH1AndVector: Finish Read in Hist %s with Entries from %.0f to %.0f\n",h->GetName(),nBefore,nAfter);
  f.Close();
  return;
}

Double_t ReadTxtToTH1(Char_t filename[],TH1 *v,Bool_t clearH=kTRUE)
{
  if(clearH) v->Clear();
  Double_t xmin = v->GetXaxis()->GetXmin();
  Double_t xmax = v->GetXaxis()->GetXmax();
  FILE *pf = fopen(filename,"rt");
  Int_t n=1;
  Double_t d;
  while(n==1){
    n = fscanf(pf,"%lf\n",&d);
    if(n==1){
      if(d< xmax && d>=xmin)v->Fill(d);
    }
  }
  fclose(pf);
  printf("%ld data read from %s\n",(Long_t) v->GetEntries(),filename);
  return v->GetEntries();
}

Int_t ReadTxtToVector(Char_t filename[],std::vector <Double_t> *v)
{
  FILE *pf = fopen(filename,"rt");
  Int_t n=1;
  Double_t d;
  while(n==1){
    n = fscanf(pf,"%lf\n",&d);
    if(n==1){
      v->push_back(d);
    }
  }
  fclose(pf);
  printf("%ld data read from %s\n",(Long_t) v->size(),filename);
  return v->size();
}

Int_t ReadTxtToVector(Char_t filename[],std::vector <Double_t> *v1,std::vector <Double_t> *v2)
{
  FILE *pf = fopen(filename,"rt");
  Int_t n=2;
  Double_t d1,d2;
  while(n==2){
    n = fscanf(pf,"%lf %lf\n",&d1,&d2);
    if(n==2){
      v1->push_back(d1);
      v2->push_back(d2);
    }
  }
  fclose(pf);
  printf("%ld data read from %s\n",v1->size(),filename);
  return v1->size();
}

void WriteVectorToTxtFile(std::vector<Float_t> *fromV, Char_t toFile[])
{
  FILE *pf = fopen(toFile,"wt");
  Int_t n = fromV->size();
  for(Int_t i=0; i<n; i++){
    fprintf(pf,"%f\n",(*fromV)[i]);
  }
  fclose(pf);
}


  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
  //  分析使用
  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

  //排序
  template <class T>//int float double 
  void SortArray(Int_t num,T *array_original,T *array_sorted,Bool_t down=kTRUE)
  {
    Int_t *index=new Int_t[num];
    Int_t num64 = num;
    TMath::Sort(num64,array_original,index,down);
    for(Int_t i=0;i<num;i++){
      array_sorted[i]=array_original[ index[i] ];
      // printf("%f\n",array_sorted[i]);
    }
    delete[] index;
    return ;
  }

  //sort array_original to array_sorted WHILE 
  //copy array_original2 to array_sorted2 acorrding to the order 
  template <class T>//int float double 
  void SortArray(Int_t num,T *array_original,T *array_original2,T *array_sorted,T *array_sorted2,Bool_t down=kTRUE)
  {
    Int_t *index=new Int_t[num];
    Int_t num64 = num;
    TMath::Sort(num64,array_original,index,down);
    for(Int_t i=0;i<num;i++){
      array_sorted[i]=array_original[ index[i] ];
      array_sorted2[i]=array_original2[ index[i] ];
      // printf("%f\n",array_sorted[i]);
    }
    delete[] index;
    return ;
  }

  template <class T>//int float double 
  Int_t  rmSameVal(Int_t nOrg,T nOrgA[],T nNewA[])
  {
    Int_t n;
    if(nOrg<1) return nOrg;
    nNewA[0] = nOrgA[0];
    n=1;
    for(Int_t i=1; i<nOrg; i++){
      if(nNewA[n-1] ==  nOrgA[i]) continue;
      nNewA[n] = nOrgA[i];
      n++;
    }
    return n;
  }


  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
  //  下面的需要在交互界面下才能使用，而且对版本有要求 ！！！
  //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

  void TH2DynamicSliceX()
  {
   //Add a TExec object to the canvas
   //c1->AddExec("dynamic","TH2DynamicSliceX()");

    //交互界面下：  TH2上动态显示X轴每个bin的图像,只能在CINT下使用

    TObject *select = gPad->GetSelected();
    if(!select) return;
    if (!select->InheritsFrom(TH2::Class())) {gPad->SetUniqueID(0); return;}
    TH2 *h = (TH2*)select;
    gPad->GetCanvas()->FeedbackMode(kTRUE);

    //erase old position and draw a line at current position
    int pyold = gPad->GetUniqueID();
    int px = gPad->GetEventX();
    int py = gPad->GetEventY();
    float uymin = gPad->GetUymin();
    float uymax = gPad->GetUymax();
    int pymin = gPad->YtoAbsPixel(uymin);
    int pymax = gPad->YtoAbsPixel(uymax);
    if(pyold) gVirtualX->DrawLine(pymin,pyold,pymax,pyold);
    gVirtualX->DrawLine(pymin,px,pymax,px);
    gPad->SetUniqueID(px);
    Float_t upx = gPad->AbsPixeltoX(px);
    Float_t x = gPad->PadtoX(upx);

    //create or set the new canvas c2
    TVirtualPad *padsav = gPad;
    TCanvas *c2 = (TCanvas*)gROOT->GetListOfCanvases()->FindObject("c2");
    if(c2) delete c2->GetPrimitive("Projection");
    else   c2 = new TCanvas("c2","Projection Canvas",710,10,700,500);
    c2->SetGrid();
    c2->cd();

    //draw slice corresponding to mouse position
    Int_t binx = h->GetXaxis()->FindBin(x);
    TH1D *hp = h->ProjectionY("",binx,binx);
    hp->SetFillColor(38);
    char title[80];
    sprintf(title,"Projection of binx=%d",binx);
    hp->SetName("Projection");
    hp->SetTitle(title);
    hp->Fit("gaus","ql");
    hp->GetFunction("gaus")->SetLineColor(kRed);
    hp->GetFunction("gaus")->SetLineWidth(6);
    c2->Update();
    padsav->cd();
  }

  void TH2DynamicSliceY()
  {
    // Example of function called when a mouse event occurs in a pad.
    // When moving the mouse in the canvas, a second canvas shows the
    // projection along X of the bin corresponding to the Y position
    // of the mouse. The resulting histogram is fitted with a gaussian.
    // A "dynamic" line shows the current bin position in Y.
    // This more elaborated example can be used as a starting point
    // to develop more powerful interactive applications exploiting CINT
    // as a development engine.
    //
    // Author:  Rene Brun

    TObject *select = gPad->GetSelected();
    if(!select) return;
    if (!select->InheritsFrom(TH2::Class())) {gPad->SetUniqueID(0); return;}
    TH2 *h = (TH2*)select;
    gPad->GetCanvas()->FeedbackMode(kTRUE);

    //erase old position and draw a line at current position
    int pyold = gPad->GetUniqueID();
    int px = gPad->GetEventX();
    int py = gPad->GetEventY();
    float uxmin = gPad->GetUxmin();
    float uxmax = gPad->GetUxmax();
    int pxmin = gPad->XtoAbsPixel(uxmin);
    int pxmax = gPad->XtoAbsPixel(uxmax);
    if(pyold) gVirtualX->DrawLine(pxmin,pyold,pxmax,pyold);
    gVirtualX->DrawLine(pxmin,py,pxmax,py);
    gPad->SetUniqueID(py);
    Float_t upy = gPad->AbsPixeltoY(py);
    Float_t y = gPad->PadtoY(upy);

    //create or set the new canvas c2
    TVirtualPad *padsav = gPad;
    TCanvas *c2 = (TCanvas*)gROOT->GetListOfCanvases()->FindObject("c2");
    if(c2) delete c2->GetPrimitive("Projection");
    else   c2 = new TCanvas("c2","Projection Canvas",710,10,700,500);
    c2->SetGrid();
    c2->cd();

    //draw slice corresponding to mouse position
    Int_t biny = h->GetYaxis()->FindBin(y);
    TH1D *hp = h->ProjectionX("",biny,biny);
    hp->SetFillColor(38);
    char title[80];
    sprintf(title,"Projection of biny=%d",biny);
    hp->SetName("Projection");
    hp->SetTitle(title);
    hp->Fit("gaus","ql");
    hp->GetFunction("gaus")->SetLineColor(kRed);
    hp->GetFunction("gaus")->SetLineWidth(6);
    c2->Update();
    padsav->cd();
  }

}

#endif /* _WUROOT_H_ */
// 
// wuROOT.hh ends here
