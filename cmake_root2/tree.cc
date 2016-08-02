#include<iostream>
#include"TFile.h"
#include"TTree.h"
#include"TCanvas.h"
#include"TGraph.h"
#include<fstream>
#include<cstdlib>

using namespace std;
int main(){

  ofstream myoutput;
  myoutput.open("456.txt");   //打开一个新文件
 
  if(myoutput.fail())
  {
   cout<<"Sorry,couldn't open file"<<endl;
   exit(1);   //from cstdlib
  }
 
 for(int i=1;i<=1000;i++)
 {
  myoutput<<i<<"\t"<<i*i*i<<endl; 
 }
 myoutput.close();

 double num;
 double weight;
 TFile *ff=new TFile("weight.root","RECREATE");
 TTree *t=new TTree("NameOfTree","title:a list of weight and numbers");
 t->Branch("NameOfBranch1",&num,"number/D");
 t->Branch("NameOfBranch2",&weight,"weight/D");
 ifstream data("456.txt");
  if(data.fail())
  {
   cout<<"Sorry,couldn't open file"<<endl;
   exit(1);   //from cstdlib
  }
  for(int i=0;i<5;i++)
    {
      data>>num>>weight;
      cout<<num<<" "<<weight<<endl;
      t->Fill();
    }
  t->Write();
  data.close();
  ff->Close();


  // const Int_t n = 20;
  // Double_t x[n]={5,10,15,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100};
  // Double_t y[n]={17,38,64,82,100,75,55,42,18,21,32,51,79,84,61,43,15,10,5,7};
  // TCanvas *c1 = new TCanvas("c1","Graph Draw Options",200,10,600,400);
  // TGraph *gr = new TGraph(n,x,y);
  // gr->Draw("A*");
  

  return 0;
}
