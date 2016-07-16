// example.cc --- 
// 
// Description: 
// Author: HongyiWu,吴鸿毅
// Email: wuhongyi@qq.com 
// Created: 二 2月 25 19:03:12 2014 (+0800)
// Last-Updated: 六 4月 25 15:11:07 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 11
// URL: http://wuhongyi.github.io 

#include "TRint.h"
#include "TObject.h"
#include "TH2.h"
#include "TH3.h"
#include "TVirtualPad.h"
#include "TCanvas.h"
#include "TH1.h"
#include "TROOT.h"
#include "TF1.h"
#include "TRandom.h"
#include "TPad.h"
#include "TBenchmark.h"
#include "TFormula.h"
#include "TPaveLabel.h"
#include "TFile.h"
#include "TFrame.h"
#include "TStyle.h"
#include "TApplication.h"

#include "TGClient.h"
#include "TGButton.h"
#include "TGFrame.h"
#include "TGLayout.h"
#include "TGWindow.h"
#include "TGLabel.h"
#include "TString.h"
#include "TGButtonGroup.h"

#include "TSystem.h"
#include "TGFrame.h"
#include "TGWindow.h"
#include "TGSpeedo.h"

#include <TGResourcePool.h>

#include "TDatime.h"
#include "TTimeStamp.h"
#include "TGComboBox.h"
#include "TGNumberEntry.h"
#include "TGLabel.h"
#include "TGColorSelect.h"
#include "TGHtml.h"
#include "TApplication.h"
#include "TROOT.h"
#include "TColor.h"
#include <TQObject.h>
#include "TObject.h"
#include "TClass.h"

#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooPlot.h"
#include "TAxis.h"
using namespace RooFit ;
using namespace std;

int main(int argc, char **argv) {
  // Popup the GUI...

   // Create an interactive ROOT application
   TRint *theApp = new TRint("Rint", &argc, argv);

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

   // TCanvas *c1 = new TCanvas("c1","The FillRandom example",200,10,700,900);
   // c1->SetFillColor(18);

   // auto pad1 = new TPad("pad1","The pad with the function",0.05,0.50,0.95,0.95,21);
   // auto pad2 = new TPad("pad2","The pad with the histogram",0.05,0.05,0.95,0.45,21);
   // pad1->Draw();
   // pad2->Draw();
   // pad1->cd();

   // gBenchmark->Start("fillrandom");
   // //
   // // A function (any dimension) or a formula may reference
   // // an already defined formula
   // //
   // auto form1 = new TFormula("form1","abs(sin(x)/x)");
   // auto sqroot = new TF1("sqroot","x*gaus(0) + [3]*form1",0,10);
   // sqroot->SetParameters(10,4,1,20);
   // pad1->SetGridx();
   // pad1->SetGridy();
   // pad1->GetFrame()->SetFillColor(42);
   // pad1->GetFrame()->SetBorderMode(-1);
   // pad1->GetFrame()->SetBorderSize(5);
   // sqroot->SetLineColor(4);
   // sqroot->SetLineWidth(6);
   // sqroot->Draw();
   // auto lfunction = new TPaveLabel(5,39,9.8,46,"The sqroot function");
   // lfunction->SetFillColor(41);
   // lfunction->Draw();
   // c1->Update();

   // //
   // // Create a one dimensional histogram (one float per bin)
   // // and fill it following the distribution in function sqroot.
   // //
   // pad2->cd();
   // pad2->GetFrame()->SetFillColor(42);
   // pad2->GetFrame()->SetBorderMode(-1);
   // pad2->GetFrame()->SetBorderSize(5);
   // auto h1f = new TH1F("h1f","Test random numbers",200,0,10);
   // h1f->SetFillColor(45);
   // h1f->FillRandom("sqroot",10000);
   // h1f->Draw("E3");
   // c1->Update();
   // //
   // // Open a ROOT file and save the formula, function and histogram
   // //
   // TFile myfile("fillrandom.root","RECREATE");
   // form1->Write();
   // sqroot->Write();
   // h1f->Write();
   // gBenchmark->Show("fillrandom");

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// Display a 3D histogram using GL (box option).
//Author: Timur Pocheptsov
   // gStyle->SetCanvasPreferGL(kTRUE);
   // TCanvas *c        = new TCanvas("glc","TH3 Drawing", 100, 10, 850, 400);
   // TPaveLabel *title = new TPaveLabel(0.04, 0.86, 0.96, 0.98,
   // 				      "\"glbox\" and \"glbox1\" options for TH3.");
   // title->SetFillColor(32);
   // title->Draw();

   // TPad *boxPad  = new TPad("box", "box", 0.02, 0.02, 0.48, 0.82);
   // TPad *box1Pad = new TPad("box1", "box1", 0.52, 0.02, 0.98, 0.82);
   // boxPad->Draw();
   // box1Pad->Draw();

   // TH3F *h31 = new TH3F("h31", "h31", 10, -1, 1, 10, -1, 1, 10, -1, 1);
   // h31->FillRandom("gaus");
   // h31->SetFillColor(2);
   // boxPad->cd();
   // h31->Draw("glbox");

   // TH3F *h32 = new TH3F("h32", "h32", 10, -2, 2, 10, -1, 1, 10, -3, 3);
   // h32->FillRandom("gaus");
   // h32->SetFillColor(4);
   // box1Pad->cd();
   // h32->Draw("glbox1");

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
     // S e t u p   m o d e l 
  // ---------------------

  // Declare variables x,mean,sigma with associated name, title, initial value and allowed range
  RooRealVar x("x","x",-10,10) ;
  RooRealVar mean("mean","mean of gaussian",1,-10,10) ;
  RooRealVar sigma("sigma","width of gaussian",1,0.1,10) ;

  // Build gaussian p.d.f in terms of x,mean and sigma
  RooGaussian gauss("gauss","gaussian PDF",x,mean,sigma) ;  

  // Construct plot frame in 'x'
  RooPlot* xframe = x.frame(Title("Gaussian p.d.f.")) ;


  // P l o t   m o d e l   a n d   c h a n g e   p a r a m e t e r   v a l u e s
  // ---------------------------------------------------------------------------

  // Plot gauss in frame (i.e. in x) 
  gauss.plotOn(xframe) ;

  // Change the value of sigma to 3
  sigma.setVal(3) ;

  // Plot gauss in frame (i.e. in x) and draw frame on canvas
  gauss.plotOn(xframe,LineColor(kRed)) ;
  

  // G e n e r a t e   e v e n t s 
  // -----------------------------

  // Generate a dataset of 1000 events in x from gauss
  RooDataSet* data = gauss.generate(x,100000) ;  
  
  // Make a second plot frame in x and draw both the 
  // data and the p.d.f in the frame
  RooPlot* xframe2 = x.frame(Title("Gaussian p.d.f. with data")) ;
  data->plotOn(xframe2) ;
  gauss.plotOn(xframe2) ;
  

  // F i t   m o d e l   t o   d a t a
  // -----------------------------

  // Fit pdf to data
  gauss.fitTo(*data) ;

  // Print values of mean and sigma (that now reflect fitted values and errors)
  // mean.Print() ;
  // sigma.Print() ;

  // Draw all frames on a canvas
  TCanvas* c = new TCanvas("rf101_basics","rf101_basics",800,400) ;
  c->Divide(2) ;
  c->cd(1) ; gPad->SetLeftMargin(0.15) ; xframe->GetYaxis()->SetTitleOffset(1.6) ; xframe->Draw() ;
  c->cd(2) ; gPad->SetLeftMargin(0.15) ; xframe2->GetYaxis()->SetTitleOffset(1.6) ; xframe2->Draw() ;
  
 //....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
  

   // and enter the event loop...
   theApp->Run();

   delete theApp;



  return 0;
}

// 
// example.cc ends here
