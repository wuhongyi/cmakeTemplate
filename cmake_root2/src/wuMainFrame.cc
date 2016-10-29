// wuMainFrame.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 三 4月 22 19:36:49 2015 (+0800)
// Last-Updated: 一 4月 27 10:37:16 2015 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 51
// URL: http://wuhongyi.cn 

#include "wuMainFrame.hh"
#include <cmath>
ClassImp(wuMainFrame);
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// wuMainFrame::wuMainFrame(const TGWindow *p, UInt_t w, UInt_t h) :
//   TGMainFrame(p, w, h)
// {
//    // Create a container frames containing buttons

//    // one button is resized up to the parent width.
//    // Note! this width should be fixed!
//    TGVerticalFrame *hframe1 = new TGVerticalFrame(this, 170, 50, kFixedWidth);
//    test = new TGTextButton(hframe1, "&Test ");
//    // to take whole space we need to use kLHintsExpandX layout hints
//    hframe1->AddFrame(test, new TGLayoutHints(kLHintsTop | kLHintsExpandX,
//                                              2, 0, 2, 2));
//    AddFrame(hframe1, new TGLayoutHints(kLHintsCenterX, 2, 2, 5, 1));

//    // two buttons are resized up to the parent width.
//    // Note! this width should be fixed!
//    TGCompositeFrame *cframe1 = new TGCompositeFrame(this, 170, 20,
//                                              kHorizontalFrame | kFixedWidth);
//    draw = new TGTextButton(cframe1, "&Draw");
//    // to share whole parent space we need to use kLHintsExpandX layout hints
//    cframe1->AddFrame(draw, new TGLayoutHints(kLHintsTop | kLHintsExpandX,
//                                              2, 2, 2, 2));

//    // button background will be set to yellow
//    ULong_t yellow;
//    gClient->GetColorByName("yellow", yellow);
//    help = new TGTextButton(cframe1, "&Help");
//    help->ChangeBackground(yellow);
//    cframe1->AddFrame(help, new TGLayoutHints(kLHintsTop | kLHintsExpandX,
//                                              2, 2, 2, 2));
//    AddFrame(cframe1, new TGLayoutHints(kLHintsCenterX, 2, 2, 5, 1));

//    // three buttons are resized up to the parent width.
//    // Note! this width should be fixed!
//    TGCompositeFrame *cframe2 = new TGCompositeFrame(this, 170, 20,
//                                              kHorizontalFrame | kFixedWidth);
//    ok = new TGTextButton(cframe2, "OK");
//    // to share whole parent space we need to use kLHintsExpandX layout hints
//    cframe2->AddFrame(ok, new TGLayoutHints(kLHintsTop | kLHintsExpandX,
//                                            3, 2, 2, 2));

//    cancel = new TGTextButton(cframe2, "Cancel ");
//    cframe2->AddFrame(cancel, new TGLayoutHints(kLHintsTop | kLHintsExpandX,
//                                                3, 2, 2, 2));

//    exit = new TGTextButton(cframe2, "&Exit ","gApplication->Terminate(0)");
//    cframe2->AddFrame(exit, new TGLayoutHints(kLHintsTop | kLHintsExpandX,
//                                              2, 0, 2, 2));

//    AddFrame(cframe2, new TGLayoutHints(kLHintsCenterX, 2, 2, 5, 1));

//    SetWindowName("Buttons' Layout");

//    // gives min/max window size + a step of x,y incrementing
//    // between the given sizes
//    SetWMSizeHints(200, 80, 320, 320, 1, 1);
//    MapSubwindows();
//    // important for layout algorithm
//    Resize(GetDefaultSize());
//    MapWindow();
// }


// wuMainFrame::~wuMainFrame()
// {
//    // Clean up all widgets, frames and layouthints that were used
//    Cleanup();
// }


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// wuMainFrame *wup=0;
void wuMainFrame::DoDraw()
{
   // Draw something in the canvas

   Printf("Slot DoDraw()");

   TCanvas *c1 = fEcan->GetCanvas();
   c1->SetFillColor(42);
   c1->SetGrid();
   const Int_t n = 20;
   Double_t x[n], y[n];
   for (Int_t i=0;i<n;i++) {
     x[i] = i*0.1;
     y[i] = 10*sin(x[i]+0.2);
     printf(" i %i %f %f \n",i,x[i],y[i]);
   }
   TGraph *gr = new TGraph(n,x,y);
   gr->SetLineColor(2);
   gr->SetLineWidth(4);
   gr->SetMarkerColor(4);
   gr->SetMarkerStyle(21);
   gr->SetTitle("a simple graph");
   gr->GetXaxis()->SetTitle("X title");
   gr->GetYaxis()->SetTitle("Y title");
   gr->Draw("ACP");

   // TCanvas::Update() draws the frame, after which it can be changed
   c1->Update();
   c1->GetFrame()->SetFillColor(21);
   c1->GetFrame()->SetBorderSize(12);
   c1->Modified();
   c1->Update();
}

void wuMainFrame::DoExit()
{
   printf("Exit application...");
   gApplication->Terminate(0);
}

void wuMainFrame::SetStatusText(const char *txt, Int_t pi)
{
   // Set text in status bar.
   fStatusBar->SetText(txt,pi);
}

void wuMainFrame::EventInfo(Int_t event, Int_t px, Int_t py, TObject *selected)
{
//  Writes the event status in the status bar parts

   const char *text0, *text1, *text3;
   char text2[50];
   text0 = selected->GetTitle();
   SetStatusText(text0,0);
   text1 = selected->GetName();
   SetStatusText(text1,1);
   if (event == kKeyPress)
      sprintf(text2, "%c", (char) px);
   else
      sprintf(text2, "%d,%d", px, py);
   SetStatusText(text2,2);
   text3 = selected->GetObjectInfo(px,py);
   SetStatusText(text3,3);
}

wuMainFrame::wuMainFrame(const TGWindow *p, UInt_t w, UInt_t h) :
   TGMainFrame(p, w, h)
{
   // Create the embedded canvas
   fEcan = new TRootEmbeddedCanvas(0,this,500,400);
   Int_t wid = fEcan->GetCanvasWindowId();
   TCanvas *myc = new TCanvas("MyCanvas", 10,10,wid);
   fEcan->AdoptCanvas(myc);
   myc->Connect("ProcessedEvent(Int_t,Int_t,Int_t,TObject*)","wuMainFrame",this,
               "EventInfo(Int_t,Int_t,Int_t,TObject*)");

   AddFrame(fEcan, new TGLayoutHints(kLHintsTop | kLHintsLeft |
                                     kLHintsExpandX  | kLHintsExpandY,0,0,1,1));
   // status bar
   Int_t parts[] = {45, 15, 10, 30};
   fStatusBar = new TGStatusBar(this, 50, 10, kVerticalFrame);
   fStatusBar->SetParts(parts, 4);
   fStatusBar->Draw3DCorner(kFALSE);
   AddFrame(fStatusBar, new TGLayoutHints(kLHintsExpandX, 0, 0, 10, 0));

   // Create a horizontal frame containing two buttons
   TGHorizontalFrame *hframe = new TGHorizontalFrame(this, 200, 40);
   
   // TGTextButton *draw = new TGTextButton(this, "&Draw","DoDraw()");
   // AddFrame(draw, new TGLayoutHints(kLHintsCenterX, 5, 5, 3, 4));
   TGTextButton *draw = new TGTextButton(hframe, "&Draw");
   draw->Connect("Clicked()", "wuMainFrame", this, "DoDraw()");
   hframe->AddFrame(draw, new TGLayoutHints(kLHintsCenterX, 5, 5, 3, 4));
   // TGTextButton *exit = new TGTextButton(this, "&Exit ","gApplication->Terminate(0)");
   // AddFrame(exit, new TGLayoutHints(kLHintsCenterX, 5, 5, 3, 4));
   TGTextButton *exit = new TGTextButton(hframe, "&Exit");
   exit->Connect("Pressed()", "wuMainFrame", this, "DoExit()");//"gApplication->Terminate(0)"  "DoExit()"
   hframe->AddFrame(exit, new TGLayoutHints(kLHintsCenterX, 5, 5, 3, 4));

   AddFrame(hframe, new TGLayoutHints(kLHintsCenterX, 2, 2, 2, 2));

   // Set a name to the main frame
   SetWindowName("Embedded Canvas Status Info");
   MapSubwindows();

   // Initialize the layout algorithm via Resize()
   Resize(GetDefaultSize());

   // Map main frame
   MapWindow();
}


wuMainFrame::~wuMainFrame()
{
   // Clean up main frame...
   Cleanup();
   delete fEcan;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// void wuMainFrame::DoSetlabel()
// {
//    // Slot method connected to the ValueSet(Long_t) signal.
//    // It displays the value set in TGNumberEntry widget.

//    fLabel->SetText(Form("%ld",fNumber->GetNumberEntry()->GetIntNumber()));

//    // Parent frame Layout() method will redraw the label showing the new value.
//    fGframe->Layout();
// }

// wuMainFrame::wuMainFrame(const TGWindow *p, UInt_t w, UInt_t h)
//    : TGMainFrame(p, w, h)
// {

//    fHor1 = new TGHorizontalFrame(this, 60, 20, kFixedWidth);
//    fExit = new TGTextButton(fHor1, "&Exit", "gApplication->Terminate(0)");
//    fHor1->AddFrame(fExit, new TGLayoutHints(kLHintsTop | kLHintsLeft |
//                                             kLHintsExpandX, 4, 4, 4, 4));
//    AddFrame(fHor1,new TGLayoutHints(kLHintsBottom | kLHintsRight, 2, 2, 5, 1));

//    fNumber = new TGNumberEntry(this, 0, 9,999, TGNumberFormat::kNESInteger,
//                                                TGNumberFormat::kNEANonNegative,
//                                                TGNumberFormat::kNELLimitMinMax,
//                                                0, 99999);
//    fNumber->Connect("ValueSet(Long_t)", "wuMainFrame", this, "DoSetlabel()");
//    (fNumber->GetNumberEntry())->Connect("ReturnPressed()", "wuMainFrame", this,
//                                         "DoSetlabel()");
//    AddFrame(fNumber, new TGLayoutHints(kLHintsTop | kLHintsLeft, 5, 5, 5, 5));
//    fGframe = new TGGroupFrame(this, "Value");
//    fLabel = new TGLabel(fGframe, "No input.");
//    fGframe->AddFrame(fLabel, new TGLayoutHints(kLHintsTop | kLHintsLeft,
//                                                5, 5, 5, 5));
//    AddFrame(fGframe, new TGLayoutHints(kLHintsExpandX, 2, 2, 1, 1));

//    SetCleanup(kDeepCleanup);
//    SetWindowName("Number Entry");
//    MapSubwindows();
//    Resize(GetDefaultSize());
//    MapWindow();
// }

// wuMainFrame::~wuMainFrame()
// {
//    // Destructor.

//    Cleanup();
// }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......



// 
// wuMainFrame.cc ends here
