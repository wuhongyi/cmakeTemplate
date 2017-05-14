// wuMainFrame.hh --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 三 4月 22 19:33:52 2015 (+0800)
// Last-Updated: 一 4月 27 13:03:07 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 54
// URL: http://wuhongyi.cn 

#ifndef _WUMAINFRAME_H_
#define _WUMAINFRAME_H_

#include <TGClient.h>
#include <TGButton.h>

#include "TBuffer.h"

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

#include <TApplication.h>
#include <TGClient.h>
#include <TGButton.h>
#include <TGFrame.h>
#include <TFrame.h>
#include <TRootEmbeddedCanvas.h>
#include <TGStatusBar.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TRandom.h>
#include <TGraph.h>
#include <TAxis.h>


#include "TQObject.h"
#include "RQ_OBJECT.h"


// class wuMainFrame : public TGMainFrame {

// private:
//    TGTextButton *test, *draw, *help, *ok, *cancel, *exit;

// public:
//    wuMainFrame(const TGWindow *p, UInt_t w, UInt_t h);
//    virtual ~wuMainFrame();

//   // ClassDef(wuMainFrame, 0);
// };

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......


class wuMainFrame : public TGMainFrame {
  // RQ_OBJECT("wuMainFrame")
private:
   TRootEmbeddedCanvas  *fEcan;
   TGStatusBar          *fStatusBar;

public:
   wuMainFrame(const TGWindow *p, UInt_t w, UInt_t h);
   virtual ~wuMainFrame();
   void DoExit();
   void DoDraw();
   void SetStatusText(const char *txt, Int_t pi);
   void EventInfo(Int_t event, Int_t px, Int_t py, TObject *selected);


  ClassDef(wuMainFrame, 1);
};

// R__EXTERN wuMainFrame *wup;

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// class wuMainFrame : public TGMainFrame {

// private:
//    TGCompositeFrame    *fHor1;
//    TGTextButton        *fExit;
//    TGGroupFrame        *fGframe;
//    TGNumberEntry       *fNumber;
//    TGLabel             *fLabel;

// public:
//    wuMainFrame(const TGWindow *p, UInt_t w, UInt_t h);
//    virtual ~wuMainFrame();
//    void DoSetlabel();

//   // ClassDef(wuMainFrame, 0);
// };


#endif /* _WUMAINFRAME_H_ */

// 
// wuMainFrame.hh ends here
