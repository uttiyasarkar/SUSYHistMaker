#include<iostream>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "TLorentzVector.h"
#include<vector>
#include "TTree.h"
#include "stackPlotter.C"
#include "HistCreater.C"
#include "HistClone.C"
using namespace std;


void Stacking(){

HistClone hl;

//sample tav text could be used as argument to the stack plotter  
TPaveText *tpav_txt = new TPaveText(0.57043478,0.548342,0.8652174,0.9210471,"brNDC");
    tpav_txt->SetBorderSize(0);
    tpav_txt->SetFillStyle(0);
    tpav_txt->SetTextAlign(11);
    tpav_txt->SetTextFont(42);
    tpav_txt->SetTextSize(0.04);
    tpav_txt->AddText("HT >600");
    tpav_txt->AddText("NJets >=2");
    tpav_txt->AddText("MET>300");
    tpav_txt->AddText("BTags=0");
    tpav_txt->AddText("dPhi1,dPhi2>0.5");
    tpav_txt->AddText("dPhi3,dPhi4>0.3");
    tpav_txt->AddText("electron,muon veto,isolated electron,muon,pion track veto");
//Example of how to use stack plotter
StackPlotter stack;

//uncomment the following line. put histogram names correctly
//sample arguments if you want to plot one signal,5 background and no data then use the function plotS1B5D0
//if you want to use data then use the function plotS1B5D1, this way you can use all possible combinations 
//use following procees nums
stack.plotS0B4D0("LeadJetprunedMass(GeV)",tpav_txt,hl.h_[0][2][0],"QCD",hl.h_[0][3][0],"TTJets",hl.h_[0][4][0],"WJets",hl.h_[0][5][0],"ZJets");

stack.plotS2B4D0("LeadJetprunedMass(GeV)",tpav_txt,hl.h_[0][0][0],"ZH_mG1300",hl.h_[0][1][0],"ZH_mG1700",hl.h_[0][2][0],"QCD",hl.h_[0][3][0],"TTJets",hl.h_[0][4][0],"WJets",hl.h_[0][5][0],"ZJets");

stack.plotS0B4D0("LeadNsubjettiness(GeV)",tpav_txt,hl.h_[1][2][0],"QCD",hl.h_[1][3][0],"TTJets",hl.h_[1][4][0],"WJets",hl.h_[1][5][0],"ZJets");

stack.plotS2B4D0("LeadNsubjettiness(GeV)",tpav_txt,hl.h_[1][0][0],"ZH_mG1300",hl.h_[1][1][0],"ZH_mG1700",hl.h_[1][2][0],"QCD",hl.h_[1][3][0],"TTJets",hl.h_[1][4][0],"WJets",hl.h_[1][5][0],"ZJets");

stack.plotS0B4D0("subLeadJetprunedMass(GeV)",tpav_txt,hl.h_[2][2][0],"QCD",hl.h_[2][3][0],"TTJets",hl.h_[2][4][0],"WJets",hl.h_[2][5][0],"ZJets");

stack.plotS2B4D0("subLeadJetprunedMass(GeV)",tpav_txt,hl.h_[2][0][0],"ZH_mG1300",hl.h_[2][1][0],"ZH_mG1700",hl.h_[2][2][0],"QCD",hl.h_[2][3][0],"TTJets",hl.h_[2][4][0],"WJets",hl.h_[2][5][0],"ZJets");

stack.plotS0B4D0("subLeadNsubjettiness(GeV)",tpav_txt,hl.h_[3][2][0],"QCD",hl.h_[3][3][0],"TTJets",hl.h_[3][4][0],"WJets",hl.h_[3][5][0],"ZJets");

stack.plotS2B4D0("subLeadNsubjettiness(GeV)",tpav_txt,hl.h_[3][0][0],"ZH_mG1300",hl.h_[3][1][0],"ZH_mG1700",hl.h_[3][2][0],"QCD",hl.h_[3][3][0],"TTJets",hl.h_[3][4][0],"WJets",hl.h_[3][5][0],"ZJets");

stack.plotS0B4D0("LeadJetprunedMass(GeV)",tpav_txt,hl.h_[0][2][1],"QCD",hl.h_[0][3][1],"TTJets",hl.h_[0][4][1],"WJets",hl.h_[0][5][1],"ZJets");

stack.plotS2B4D0("LeadJetprunedMass(GeV)",tpav_txt,hl.h_[0][0][1],"ZH_mG1300",hl.h_[0][1][1],"ZH_mG1700",hl.h_[0][2][1],"QCD",hl.h_[0][3][1],"TTJets",hl.h_[0][4][1],"WJets",hl.h_[0][5][1],"ZJets");

stack.plotS0B4D0("LeadNsubjettiness(GeV)",tpav_txt,hl.h_[1][2][1],"QCD",hl.h_[1][3][1],"TTJets",hl.h_[1][4][1],"WJets",hl.h_[1][5][1],"ZJets");

stack.plotS2B4D0("LeadNsubjettiness(GeV)",tpav_txt,hl.h_[1][0][1],"ZH_mG1300",hl.h_[1][1][1],"ZH_mG1700",hl.h_[1][2][1],"QCD",hl.h_[1][3][1],"TTJets",hl.h_[1][4][1],"WJets",hl.h_[1][5][1],"ZJets");

stack.plotS0B4D0("subLeadJetprunedMass(GeV)",tpav_txt,hl.h_[2][2][1],"QCD",hl.h_[2][3][1],"TTJets",hl.h_[2][4][1],"WJets",hl.h_[2][5][1],"ZJets");

stack.plotS2B4D0("subLeadJetprunedMass(GeV)",tpav_txt,hl.h_[2][0][1],"ZH_mG1300",hl.h_[2][1][1],"ZH_mG1700",hl.h_[2][2][1],"QCD",hl.h_[2][3][1],"TTJets",hl.h_[2][4][1],"WJets",hl.h_[2][5][1],"ZJets");

stack.plotS0B4D0("subLeadNsubjettiness(GeV)",tpav_txt,hl.h_[3][2][1],"QCD",hl.h_[3][3][1],"TTJets",hl.h_[3][4][1],"WJets",hl.h_[3][5][1],"ZJets");

stack.plotS2B4D0("subLeadNsubjettiness(GeV)",tpav_txt,hl.h_[3][0][1],"ZH_mG1300",hl.h_[3][1][1],"ZH_mG1700",hl.h_[3][2][1],"QCD",hl.h_[3][3][1],"TTJets",hl.h_[3][4][1],"WJets",hl.h_[3][5][1],"ZJets");

stack.plotS0B4D0("LeadJetprunedMass(GeV)",tpav_txt,hl.h_[0][2][2],"QCD",hl.h_[0][3][2],"TTJets",hl.h_[0][4][2],"WJets",hl.h_[0][5][2],"ZJets");

stack.plotS2B4D0("LeadJetprunedMass(GeV)",tpav_txt,hl.h_[0][0][2],"ZH_mG1300",hl.h_[0][1][2],"ZH_mG1700",hl.h_[0][2][2],"QCD",hl.h_[0][3][2],"TTJets",hl.h_[0][4][2],"WJets",hl.h_[0][5][2],"ZJets");

stack.plotS0B4D0("LeadNsubjettiness(GeV)",tpav_txt,hl.h_[1][2][2],"QCD",hl.h_[1][3][2],"TTJets",hl.h_[1][4][2],"WJets",hl.h_[1][5][2],"ZJets");

stack.plotS2B4D0("LeadNsubjettiness(GeV)",tpav_txt,hl.h_[1][0][2],"ZH_mG1300",hl.h_[1][1][2],"ZH_mG1700",hl.h_[1][2][2],"QCD",hl.h_[1][3][2],"TTJets",hl.h_[1][4][2],"WJets",hl.h_[1][5][2],"ZJets");

stack.plotS0B4D0("subLeadJetprunedMass(GeV)",tpav_txt,hl.h_[2][2][2],"QCD",hl.h_[2][3][2],"TTJets",hl.h_[2][4][2],"WJets",hl.h_[2][5][2],"ZJets");

stack.plotS2B4D0("subLeadJetprunedMass(GeV)",tpav_txt,hl.h_[2][0][2],"ZH_mG1300",hl.h_[2][1][2],"ZH_mG1700",hl.h_[2][2][2],"QCD",hl.h_[2][3][2],"TTJets",hl.h_[2][4][2],"WJets",hl.h_[2][5][2],"ZJets");

stack.plotS0B4D0("subLeadNsubjettiness(GeV)",tpav_txt,hl.h_[3][2][2],"QCD",hl.h_[3][3][2],"TTJets",hl.h_[3][4][2],"WJets",hl.h_[3][5][2],"ZJets");

stack.plotS2B4D0("subLeadNsubjettiness(GeV)",tpav_txt,hl.h_[3][0][2],"ZH_mG1300",hl.h_[3][1][2],"ZH_mG1700",hl.h_[3][2][2],"QCD",hl.h_[3][3][2],"TTJets",hl.h_[3][4][2],"WJets",hl.h_[3][5][2],"ZJets");

stack.plotS0B4D0("LeadJetprunedMass(GeV)",tpav_txt,hl.h_[0][2][3],"QCD",hl.h_[0][3][3],"TTJets",hl.h_[0][4][3],"WJets",hl.h_[0][5][3],"ZJets");

stack.plotS2B4D0("LeadJetprunedMass(GeV)",tpav_txt,hl.h_[0][0][3],"ZH_mG1300",hl.h_[0][1][3],"ZH_mG1700",hl.h_[0][2][3],"QCD",hl.h_[0][3][3],"TTJets",hl.h_[0][4][3],"WJets",hl.h_[0][5][3],"ZJets");

stack.plotS0B4D0("LeadNsubjettiness(GeV)",tpav_txt,hl.h_[1][2][3],"QCD",hl.h_[1][3][3],"TTJets",hl.h_[1][4][3],"WJets",hl.h_[1][5][3],"ZJets");

stack.plotS2B4D0("LeadNsubjettiness(GeV)",tpav_txt,hl.h_[1][0][3],"ZH_mG1300",hl.h_[1][1][3],"ZH_mG1700",hl.h_[1][2][3],"QCD",hl.h_[1][3][3],"TTJets",hl.h_[1][4][3],"WJets",hl.h_[1][5][3],"ZJets");

stack.plotS0B4D0("subLeadJetprunedMass(GeV)",tpav_txt,hl.h_[2][2][3],"QCD",hl.h_[2][3][3],"TTJets",hl.h_[2][4][3],"WJets",hl.h_[2][5][3],"ZJets");

stack.plotS2B4D0("subLeadJetprunedMass(GeV)",tpav_txt,hl.h_[2][0][3],"ZH_mG1300",hl.h_[2][1][3],"ZH_mG1700",hl.h_[2][2][3],"QCD",hl.h_[2][3][3],"TTJets",hl.h_[2][4][3],"WJets",hl.h_[2][5][3],"ZJets");

stack.plotS0B4D0("subLeadNsubjettiness(GeV)",tpav_txt,hl.h_[3][2][3],"QCD",hl.h_[3][3][3],"TTJets",hl.h_[3][4][3],"WJets",hl.h_[3][5][3],"ZJets");

stack.plotS2B4D0("subLeadNsubjettiness(GeV)",tpav_txt,hl.h_[3][0][3],"ZH_mG1300",hl.h_[3][1][3],"ZH_mG1700",hl.h_[3][2][3],"QCD",hl.h_[3][3][3],"TTJets",hl.h_[3][4][3],"WJets",hl.h_[3][5][3],"ZJets");

stack.plotS0B4D0("LeadJetprunedMass(GeV)",tpav_txt,hl.h_[0][2][4],"QCD",hl.h_[0][3][4],"TTJets",hl.h_[0][4][4],"WJets",hl.h_[0][5][4],"ZJets");

stack.plotS2B4D0("LeadJetprunedMass(GeV)",tpav_txt,hl.h_[0][0][4],"ZH_mG1300",hl.h_[0][1][4],"ZH_mG1700",hl.h_[0][2][4],"QCD",hl.h_[0][3][4],"TTJets",hl.h_[0][4][4],"WJets",hl.h_[0][5][4],"ZJets");

stack.plotS0B4D0("LeadNsubjettiness(GeV)",tpav_txt,hl.h_[1][2][4],"QCD",hl.h_[1][3][4],"TTJets",hl.h_[1][4][4],"WJets",hl.h_[1][5][4],"ZJets");

stack.plotS2B4D0("LeadNsubjettiness(GeV)",tpav_txt,hl.h_[1][0][4],"ZH_mG1300",hl.h_[1][1][4],"ZH_mG1700",hl.h_[1][2][4],"QCD",hl.h_[1][3][4],"TTJets",hl.h_[1][4][4],"WJets",hl.h_[1][5][4],"ZJets");

stack.plotS0B4D0("subLeadJetprunedMass(GeV)",tpav_txt,hl.h_[2][2][4],"QCD",hl.h_[2][3][4],"TTJets",hl.h_[2][4][4],"WJets",hl.h_[2][5][4],"ZJets");

stack.plotS2B4D0("subLeadJetprunedMass(GeV)",tpav_txt,hl.h_[2][0][4],"ZH_mG1300",hl.h_[2][1][4],"ZH_mG1700",hl.h_[2][2][4],"QCD",hl.h_[2][3][4],"TTJets",hl.h_[2][4][4],"WJets",hl.h_[2][5][4],"ZJets");

stack.plotS0B4D0("subLeadNsubjettiness(GeV)",tpav_txt,hl.h_[3][2][4],"QCD",hl.h_[3][3][4],"TTJets",hl.h_[3][4][4],"WJets",hl.h_[3][5][4],"ZJets");

stack.plotS2B4D0("subLeadNsubjettiness(GeV)",tpav_txt,hl.h_[3][0][4],"ZH_mG1300",hl.h_[3][1][4],"ZH_mG1700",hl.h_[3][2][4],"QCD",hl.h_[3][3][4],"TTJets",hl.h_[3][4][4],"WJets",hl.h_[3][5][4],"ZJets");

stack.plotS0B4D0("LeadJetprunedMass(GeV)",tpav_txt,hl.h_[0][2][5],"QCD",hl.h_[0][3][5],"TTJets",hl.h_[0][4][5],"WJets",hl.h_[0][5][5],"ZJets");

stack.plotS2B4D0("LeadJetprunedMass(GeV)",tpav_txt,hl.h_[0][0][5],"ZH_mG1300",hl.h_[0][1][5],"ZH_mG1700",hl.h_[0][2][5],"QCD",hl.h_[0][3][5],"TTJets",hl.h_[0][4][5],"WJets",hl.h_[0][5][5],"ZJets");

stack.plotS0B4D0("LeadNsubjettiness(GeV)",tpav_txt,hl.h_[1][2][5],"QCD",hl.h_[1][3][5],"TTJets",hl.h_[1][4][5],"WJets",hl.h_[1][5][5],"ZJets");

stack.plotS2B4D0("LeadNsubjettiness(GeV)",tpav_txt,hl.h_[1][0][5],"ZH_mG1300",hl.h_[1][1][5],"ZH_mG1700",hl.h_[1][2][5],"QCD",hl.h_[1][3][5],"TTJets",hl.h_[1][4][5],"WJets",hl.h_[1][5][5],"ZJets");

stack.plotS0B4D0("subLeadJetprunedMass(GeV)",tpav_txt,hl.h_[2][2][5],"QCD",hl.h_[2][3][5],"TTJets",hl.h_[2][4][5],"WJets",hl.h_[2][5][5],"ZJets");

stack.plotS2B4D0("subLeadJetprunedMass(GeV)",tpav_txt,hl.h_[2][0][5],"ZH_mG1300",hl.h_[2][1][5],"ZH_mG1700",hl.h_[2][2][5],"QCD",hl.h_[2][3][5],"TTJets",hl.h_[2][4][5],"WJets",hl.h_[2][5][5],"ZJets");

stack.plotS0B4D0("subLeadNsubjettiness(GeV)",tpav_txt,hl.h_[3][2][5],"QCD",hl.h_[3][3][5],"TTJets",hl.h_[3][4][5],"WJets",hl.h_[3][5][5],"ZJets");

stack.plotS2B4D0("subLeadNsubjettiness(GeV)",tpav_txt,hl.h_[3][0][5],"ZH_mG1300",hl.h_[3][1][5],"ZH_mG1700",hl.h_[3][2][5],"QCD",hl.h_[3][3][5],"TTJets",hl.h_[3][4][5],"WJets",hl.h_[3][5][5],"ZJets");

stack.plotS0B4D0("LeadJetprunedMass(GeV)",tpav_txt,hl.h_[0][2][6],"QCD",hl.h_[0][3][6],"TTJets",hl.h_[0][4][6],"WJets",hl.h_[0][5][6],"ZJets");

stack.plotS2B4D0("LeadJetprunedMass(GeV)",tpav_txt,hl.h_[0][0][6],"ZH_mG1300",hl.h_[0][1][6],"ZH_mG1700",hl.h_[0][2][6],"QCD",hl.h_[0][3][6],"TTJets",hl.h_[0][4][6],"WJets",hl.h_[0][5][6],"ZJets");

stack.plotS0B4D0("LeadNsubjettiness(GeV)",tpav_txt,hl.h_[1][2][6],"QCD",hl.h_[1][3][6],"TTJets",hl.h_[1][4][6],"WJets",hl.h_[1][5][6],"ZJets");

stack.plotS2B4D0("LeadNsubjettiness(GeV)",tpav_txt,hl.h_[1][0][6],"ZH_mG1300",hl.h_[1][1][6],"ZH_mG1700",hl.h_[1][2][6],"QCD",hl.h_[1][3][6],"TTJets",hl.h_[1][4][6],"WJets",hl.h_[1][5][6],"ZJets");

stack.plotS0B4D0("subLeadJetprunedMass(GeV)",tpav_txt,hl.h_[2][2][6],"QCD",hl.h_[2][3][6],"TTJets",hl.h_[2][4][6],"WJets",hl.h_[2][5][6],"ZJets");

stack.plotS2B4D0("subLeadJetprunedMass(GeV)",tpav_txt,hl.h_[2][0][6],"ZH_mG1300",hl.h_[2][1][6],"ZH_mG1700",hl.h_[2][2][6],"QCD",hl.h_[2][3][6],"TTJets",hl.h_[2][4][6],"WJets",hl.h_[2][5][6],"ZJets");

stack.plotS0B4D0("subLeadNsubjettiness(GeV)",tpav_txt,hl.h_[3][2][6],"QCD",hl.h_[3][3][6],"TTJets",hl.h_[3][4][6],"WJets",hl.h_[3][5][6],"ZJets");

stack.plotS2B4D0("subLeadNsubjettiness(GeV)",tpav_txt,hl.h_[3][0][6],"ZH_mG1300",hl.h_[3][1][6],"ZH_mG1700",hl.h_[3][2][6],"QCD",hl.h_[3][3][6],"TTJets",hl.h_[3][4][6],"WJets",hl.h_[3][5][6],"ZJets");

stack.plotS0B4D0("LeadJetprunedMass(GeV)",tpav_txt,hl.h_[0][2][7],"QCD",hl.h_[0][3][7],"TTJets",hl.h_[0][4][7],"WJets",hl.h_[0][5][7],"ZJets");

stack.plotS2B4D0("LeadJetprunedMass(GeV)",tpav_txt,hl.h_[0][0][7],"ZH_mG1300",hl.h_[0][1][7],"ZH_mG1700",hl.h_[0][2][7],"QCD",hl.h_[0][3][7],"TTJets",hl.h_[0][4][7],"WJets",hl.h_[0][5][7],"ZJets");

stack.plotS0B4D0("LeadNsubjettiness(GeV)",tpav_txt,hl.h_[1][2][7],"QCD",hl.h_[1][3][7],"TTJets",hl.h_[1][4][7],"WJets",hl.h_[1][5][7],"ZJets");

stack.plotS2B4D0("LeadNsubjettiness(GeV)",tpav_txt,hl.h_[1][0][7],"ZH_mG1300",hl.h_[1][1][7],"ZH_mG1700",hl.h_[1][2][7],"QCD",hl.h_[1][3][7],"TTJets",hl.h_[1][4][7],"WJets",hl.h_[1][5][7],"ZJets");

stack.plotS0B4D0("subLeadJetprunedMass(GeV)",tpav_txt,hl.h_[2][2][7],"QCD",hl.h_[2][3][7],"TTJets",hl.h_[2][4][7],"WJets",hl.h_[2][5][7],"ZJets");

stack.plotS2B4D0("subLeadJetprunedMass(GeV)",tpav_txt,hl.h_[2][0][7],"ZH_mG1300",hl.h_[2][1][7],"ZH_mG1700",hl.h_[2][2][7],"QCD",hl.h_[2][3][7],"TTJets",hl.h_[2][4][7],"WJets",hl.h_[2][5][7],"ZJets");

stack.plotS0B4D0("subLeadNsubjettiness(GeV)",tpav_txt,hl.h_[3][2][7],"QCD",hl.h_[3][3][7],"TTJets",hl.h_[3][4][7],"WJets",hl.h_[3][5][7],"ZJets");

stack.plotS2B4D0("subLeadNsubjettiness(GeV)",tpav_txt,hl.h_[3][0][7],"ZH_mG1300",hl.h_[3][1][7],"ZH_mG1700",hl.h_[3][2][7],"QCD",hl.h_[3][3][7],"TTJets",hl.h_[3][4][7],"WJets",hl.h_[3][5][7],"ZJets");

stack.plotS0B4D0("LeadJetprunedMass(GeV)",tpav_txt,hl.h_[0][2][8],"QCD",hl.h_[0][3][8],"TTJets",hl.h_[0][4][8],"WJets",hl.h_[0][5][8],"ZJets");

stack.plotS2B4D0("LeadJetprunedMass(GeV)",tpav_txt,hl.h_[0][0][8],"ZH_mG1300",hl.h_[0][1][8],"ZH_mG1700",hl.h_[0][2][8],"QCD",hl.h_[0][3][8],"TTJets",hl.h_[0][4][8],"WJets",hl.h_[0][5][8],"ZJets");

stack.plotS0B4D0("LeadNsubjettiness(GeV)",tpav_txt,hl.h_[1][2][8],"QCD",hl.h_[1][3][8],"TTJets",hl.h_[1][4][8],"WJets",hl.h_[1][5][8],"ZJets");

stack.plotS2B4D0("LeadNsubjettiness(GeV)",tpav_txt,hl.h_[1][0][8],"ZH_mG1300",hl.h_[1][1][8],"ZH_mG1700",hl.h_[1][2][8],"QCD",hl.h_[1][3][8],"TTJets",hl.h_[1][4][8],"WJets",hl.h_[1][5][8],"ZJets");

stack.plotS0B4D0("subLeadJetprunedMass(GeV)",tpav_txt,hl.h_[2][2][8],"QCD",hl.h_[2][3][8],"TTJets",hl.h_[2][4][8],"WJets",hl.h_[2][5][8],"ZJets");

stack.plotS2B4D0("subLeadJetprunedMass(GeV)",tpav_txt,hl.h_[2][0][8],"ZH_mG1300",hl.h_[2][1][8],"ZH_mG1700",hl.h_[2][2][8],"QCD",hl.h_[2][3][8],"TTJets",hl.h_[2][4][8],"WJets",hl.h_[2][5][8],"ZJets");

stack.plotS0B4D0("subLeadNsubjettiness(GeV)",tpav_txt,hl.h_[3][2][8],"QCD",hl.h_[3][3][8],"TTJets",hl.h_[3][4][8],"WJets",hl.h_[3][5][8],"ZJets");

stack.plotS2B4D0("subLeadNsubjettiness(GeV)",tpav_txt,hl.h_[3][0][8],"ZH_mG1300",hl.h_[3][1][8],"ZH_mG1700",hl.h_[3][2][8],"QCD",hl.h_[3][3][8],"TTJets",hl.h_[3][4][8],"WJets",hl.h_[3][5][8],"ZJets");

stack.plotS0B4D0("LeadJetprunedMass(GeV)",tpav_txt,hl.h_[0][2][9],"QCD",hl.h_[0][3][9],"TTJets",hl.h_[0][4][9],"WJets",hl.h_[0][5][9],"ZJets");

stack.plotS2B4D0("LeadJetprunedMass(GeV)",tpav_txt,hl.h_[0][0][9],"ZH_mG1300",hl.h_[0][1][9],"ZH_mG1700",hl.h_[0][2][9],"QCD",hl.h_[0][3][9],"TTJets",hl.h_[0][4][9],"WJets",hl.h_[0][5][9],"ZJets");

stack.plotS0B4D0("LeadNsubjettiness(GeV)",tpav_txt,hl.h_[1][2][9],"QCD",hl.h_[1][3][9],"TTJets",hl.h_[1][4][9],"WJets",hl.h_[1][5][9],"ZJets");

stack.plotS2B4D0("LeadNsubjettiness(GeV)",tpav_txt,hl.h_[1][0][9],"ZH_mG1300",hl.h_[1][1][9],"ZH_mG1700",hl.h_[1][2][9],"QCD",hl.h_[1][3][9],"TTJets",hl.h_[1][4][9],"WJets",hl.h_[1][5][9],"ZJets");

stack.plotS0B4D0("subLeadJetprunedMass(GeV)",tpav_txt,hl.h_[2][2][9],"QCD",hl.h_[2][3][9],"TTJets",hl.h_[2][4][9],"WJets",hl.h_[2][5][9],"ZJets");

stack.plotS2B4D0("subLeadJetprunedMass(GeV)",tpav_txt,hl.h_[2][0][9],"ZH_mG1300",hl.h_[2][1][9],"ZH_mG1700",hl.h_[2][2][9],"QCD",hl.h_[2][3][9],"TTJets",hl.h_[2][4][9],"WJets",hl.h_[2][5][9],"ZJets");

stack.plotS0B4D0("subLeadNsubjettiness(GeV)",tpav_txt,hl.h_[3][2][9],"QCD",hl.h_[3][3][9],"TTJets",hl.h_[3][4][9],"WJets",hl.h_[3][5][9],"ZJets");

stack.plotS2B4D0("subLeadNsubjettiness(GeV)",tpav_txt,hl.h_[3][0][9],"ZH_mG1300",hl.h_[3][1][9],"ZH_mG1700",hl.h_[3][2][9],"QCD",hl.h_[3][3][9],"TTJets",hl.h_[3][4][9],"WJets",hl.h_[3][5][9],"ZJets");

stack.plotS0B4D0("LeadJetprunedMass(GeV)",tpav_txt,hl.h_[0][2][10],"QCD",hl.h_[0][3][10],"TTJets",hl.h_[0][4][10],"WJets",hl.h_[0][5][10],"ZJets");

stack.plotS2B4D0("LeadJetprunedMass(GeV)",tpav_txt,hl.h_[0][0][10],"ZH_mG1300",hl.h_[0][1][10],"ZH_mG1700",hl.h_[0][2][10],"QCD",hl.h_[0][3][10],"TTJets",hl.h_[0][4][10],"WJets",hl.h_[0][5][10],"ZJets");

stack.plotS0B4D0("LeadNsubjettiness(GeV)",tpav_txt,hl.h_[1][2][10],"QCD",hl.h_[1][3][10],"TTJets",hl.h_[1][4][10],"WJets",hl.h_[1][5][10],"ZJets");

stack.plotS2B4D0("LeadNsubjettiness(GeV)",tpav_txt,hl.h_[1][0][10],"ZH_mG1300",hl.h_[1][1][10],"ZH_mG1700",hl.h_[1][2][10],"QCD",hl.h_[1][3][10],"TTJets",hl.h_[1][4][10],"WJets",hl.h_[1][5][10],"ZJets");

stack.plotS0B4D0("subLeadJetprunedMass(GeV)",tpav_txt,hl.h_[2][2][10],"QCD",hl.h_[2][3][10],"TTJets",hl.h_[2][4][10],"WJets",hl.h_[2][5][10],"ZJets");

stack.plotS2B4D0("subLeadJetprunedMass(GeV)",tpav_txt,hl.h_[2][0][10],"ZH_mG1300",hl.h_[2][1][10],"ZH_mG1700",hl.h_[2][2][10],"QCD",hl.h_[2][3][10],"TTJets",hl.h_[2][4][10],"WJets",hl.h_[2][5][10],"ZJets");

stack.plotS0B4D0("subLeadNsubjettiness(GeV)",tpav_txt,hl.h_[3][2][10],"QCD",hl.h_[3][3][10],"TTJets",hl.h_[3][4][10],"WJets",hl.h_[3][5][10],"ZJets");

stack.plotS2B4D0("subLeadNsubjettiness(GeV)",tpav_txt,hl.h_[3][0][10],"ZH_mG1300",hl.h_[3][1][10],"ZH_mG1700",hl.h_[3][2][10],"QCD",hl.h_[3][3][10],"TTJets",hl.h_[3][4][10],"WJets",hl.h_[3][5][10],"ZJets");

stack.plotS0B4D0("LeadJetprunedMass(GeV)",tpav_txt,hl.h_[0][2][11],"QCD",hl.h_[0][3][11],"TTJets",hl.h_[0][4][11],"WJets",hl.h_[0][5][11],"ZJets");

stack.plotS2B4D0("LeadJetprunedMass(GeV)",tpav_txt,hl.h_[0][0][11],"ZH_mG1300",hl.h_[0][1][11],"ZH_mG1700",hl.h_[0][2][11],"QCD",hl.h_[0][3][11],"TTJets",hl.h_[0][4][11],"WJets",hl.h_[0][5][11],"ZJets");

stack.plotS0B4D0("LeadNsubjettiness(GeV)",tpav_txt,hl.h_[1][2][11],"QCD",hl.h_[1][3][11],"TTJets",hl.h_[1][4][11],"WJets",hl.h_[1][5][11],"ZJets");

stack.plotS2B4D0("LeadNsubjettiness(GeV)",tpav_txt,hl.h_[1][0][11],"ZH_mG1300",hl.h_[1][1][11],"ZH_mG1700",hl.h_[1][2][11],"QCD",hl.h_[1][3][11],"TTJets",hl.h_[1][4][11],"WJets",hl.h_[1][5][11],"ZJets");

stack.plotS0B4D0("subLeadJetprunedMass(GeV)",tpav_txt,hl.h_[2][2][11],"QCD",hl.h_[2][3][11],"TTJets",hl.h_[2][4][11],"WJets",hl.h_[2][5][11],"ZJets");

stack.plotS2B4D0("subLeadJetprunedMass(GeV)",tpav_txt,hl.h_[2][0][11],"ZH_mG1300",hl.h_[2][1][11],"ZH_mG1700",hl.h_[2][2][11],"QCD",hl.h_[2][3][11],"TTJets",hl.h_[2][4][11],"WJets",hl.h_[2][5][11],"ZJets");

stack.plotS0B4D0("subLeadNsubjettiness(GeV)",tpav_txt,hl.h_[3][2][11],"QCD",hl.h_[3][3][11],"TTJets",hl.h_[3][4][11],"WJets",hl.h_[3][5][11],"ZJets");

stack.plotS2B4D0("subLeadNsubjettiness(GeV)",tpav_txt,hl.h_[3][0][11],"ZH_mG1300",hl.h_[3][1][11],"ZH_mG1700",hl.h_[3][2][11],"QCD",hl.h_[3][3][11],"TTJets",hl.h_[3][4][11],"WJets",hl.h_[3][5][11],"ZJets");





f->Write();

}
