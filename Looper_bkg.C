template <class classInst, class HistogramCreater> class Looper_bkg{
public:

void Loop(TChain *tr,classInst& read,HistogramCreater hs, string ProcessName);

bool Baseline(TChain *tr,classInst& read,string ProcessName,int iEvent);

bool ProcessCuts(TChain *tr,classInst& read,string ProcessName,int iEvent);

bool ZZM12TLM(TChain *tr,classInst& read,string ProcessName,int iEvent);

bool ZZM22TLM(TChain *tr,classInst& read,string ProcessName,int iEvent);

bool ZZM32TLM(TChain *tr,classInst& read,string ProcessName,int iEvent);

bool ZZM11TLM(TChain *tr,classInst& read,string ProcessName,int iEvent);

bool ZZM21TLM(TChain *tr,classInst& read,string ProcessName,int iEvent);

bool ZZM31TLM(TChain *tr,classInst& read,string ProcessName,int iEvent);

bool ZZM12TTM(TChain *tr,classInst& read,string ProcessName,int iEvent);

bool ZZM22TTM(TChain *tr,classInst& read,string ProcessName,int iEvent);

bool ZZM32TTM(TChain *tr,classInst& read,string ProcessName,int iEvent);

bool ZZM11TTM(TChain *tr,classInst& read,string ProcessName,int iEvent);

bool ZZM21TTM(TChain *tr,classInst& read,string ProcessName,int iEvent);

bool ZZM31TTM(TChain *tr,classInst& read,string ProcessName,int iEvent);

};

template <class classInst,class HistogramCreater> void Looper_bkg<classInst,HistogramCreater>::Loop(TChain *tr,classInst& read,HistogramCreater hs,string ProcessName)

{//looper definition

string processes[7]={ "T5qqqqZH_mG1300"  , "T5qqqqZH_mG1700"  , "QCD"  , "TTJets"  , "WJets"  , "ZJets"  , "HTMHT"  };
string dataprocesses[1]={ "HTMHT"  };
const int processesSize=7;
            auto it=std::find(processes,processes+processesSize,ProcessName);
            int processInt=it-processes;
       std::cout<<"Total number of entries: "<<tr->GetEntries()<<std::endl;

       for(int iEv=0;iEv<tr->GetEntries();iEv++){// event loop

       tr->GetEntry(iEv);
if(processInt==4 && iEv>384742 && read.madHT>600.) continue;
          if(iEv % 1000==0)std::cout<<"Running on "<<ProcessName<<" event no: "<<iEv<<"---completed : "<<(float(iEv)/float(tr->GetEntries()))*100<<" %"<<"\r"<<std::flush;

            if(Baseline(tr,read,ProcessName,iEv)  && ProcessCuts(tr,read,ProcessName, iEv)){ //Baseline for this processn

            double EventWeight=1;
            EventWeight=read.Weight*35900;
if(ZZM12TLM(tr,read,ProcessName,iEv)){
         hs.h_[0][processInt][0]->Fill(read.JetsAK8_prunedMass->at(0),EventWeight); 
         hs.h_[1][processInt][0]->Fill(read.JetsAK8_NsubjettinessTau2->at(0)/read.JetsAK8_NsubjettinessTau1->at(0),EventWeight); 
         hs.h_[2][processInt][0]->Fill(read.JetsAK8_prunedMass->at(1),EventWeight); 
         hs.h_[3][processInt][0]->Fill(read.JetsAK8_NsubjettinessTau2->at(1)/read.JetsAK8_NsubjettinessTau1->at(1),EventWeight); 
}

if(ZZM22TLM(tr,read,ProcessName,iEv)){
         hs.h_[0][processInt][1]->Fill(read.JetsAK8_prunedMass->at(0),EventWeight); 
         hs.h_[1][processInt][1]->Fill(read.JetsAK8_NsubjettinessTau2->at(0)/read.JetsAK8_NsubjettinessTau1->at(0),EventWeight); 
         hs.h_[2][processInt][1]->Fill(read.JetsAK8_prunedMass->at(1),EventWeight); 
         hs.h_[3][processInt][1]->Fill(read.JetsAK8_NsubjettinessTau2->at(1)/read.JetsAK8_NsubjettinessTau1->at(1),EventWeight); 
}

if(ZZM32TLM(tr,read,ProcessName,iEv)){
         hs.h_[0][processInt][2]->Fill(read.JetsAK8_prunedMass->at(0),EventWeight); 
         hs.h_[1][processInt][2]->Fill(read.JetsAK8_NsubjettinessTau2->at(0)/read.JetsAK8_NsubjettinessTau1->at(0),EventWeight); 
         hs.h_[2][processInt][2]->Fill(read.JetsAK8_prunedMass->at(1),EventWeight); 
         hs.h_[3][processInt][2]->Fill(read.JetsAK8_NsubjettinessTau2->at(1)/read.JetsAK8_NsubjettinessTau1->at(1),EventWeight); 
}

if(ZZM11TLM(tr,read,ProcessName,iEv)){
         hs.h_[0][processInt][3]->Fill(read.JetsAK8_prunedMass->at(0),EventWeight); 
         hs.h_[1][processInt][3]->Fill(read.JetsAK8_NsubjettinessTau2->at(0)/read.JetsAK8_NsubjettinessTau1->at(0),EventWeight); 
         hs.h_[2][processInt][3]->Fill(read.JetsAK8_prunedMass->at(1),EventWeight); 
         hs.h_[3][processInt][3]->Fill(read.JetsAK8_NsubjettinessTau2->at(1)/read.JetsAK8_NsubjettinessTau1->at(1),EventWeight); 
}

if(ZZM21TLM(tr,read,ProcessName,iEv)){
         hs.h_[0][processInt][4]->Fill(read.JetsAK8_prunedMass->at(0),EventWeight); 
         hs.h_[1][processInt][4]->Fill(read.JetsAK8_NsubjettinessTau2->at(0)/read.JetsAK8_NsubjettinessTau1->at(0),EventWeight); 
         hs.h_[2][processInt][4]->Fill(read.JetsAK8_prunedMass->at(1),EventWeight); 
         hs.h_[3][processInt][4]->Fill(read.JetsAK8_NsubjettinessTau2->at(1)/read.JetsAK8_NsubjettinessTau1->at(1),EventWeight); 
}

if(ZZM31TLM(tr,read,ProcessName,iEv)){
         hs.h_[0][processInt][5]->Fill(read.JetsAK8_prunedMass->at(0),EventWeight); 
         hs.h_[1][processInt][5]->Fill(read.JetsAK8_NsubjettinessTau2->at(0)/read.JetsAK8_NsubjettinessTau1->at(0),EventWeight); 
         hs.h_[2][processInt][5]->Fill(read.JetsAK8_prunedMass->at(1),EventWeight); 
         hs.h_[3][processInt][5]->Fill(read.JetsAK8_NsubjettinessTau2->at(1)/read.JetsAK8_NsubjettinessTau1->at(1),EventWeight); 
}

if(ZZM12TTM(tr,read,ProcessName,iEv)){
         hs.h_[0][processInt][6]->Fill(read.JetsAK8_prunedMass->at(0),EventWeight); 
         hs.h_[1][processInt][6]->Fill(read.JetsAK8_NsubjettinessTau2->at(0)/read.JetsAK8_NsubjettinessTau1->at(0),EventWeight); 
         hs.h_[2][processInt][6]->Fill(read.JetsAK8_prunedMass->at(1),EventWeight); 
         hs.h_[3][processInt][6]->Fill(read.JetsAK8_NsubjettinessTau2->at(1)/read.JetsAK8_NsubjettinessTau1->at(1),EventWeight); 
}

if(ZZM22TTM(tr,read,ProcessName,iEv)){
         hs.h_[0][processInt][7]->Fill(read.JetsAK8_prunedMass->at(0),EventWeight); 
         hs.h_[1][processInt][7]->Fill(read.JetsAK8_NsubjettinessTau2->at(0)/read.JetsAK8_NsubjettinessTau1->at(0),EventWeight); 
         hs.h_[2][processInt][7]->Fill(read.JetsAK8_prunedMass->at(1),EventWeight); 
         hs.h_[3][processInt][7]->Fill(read.JetsAK8_NsubjettinessTau2->at(1)/read.JetsAK8_NsubjettinessTau1->at(1),EventWeight); 
}

if(ZZM32TTM(tr,read,ProcessName,iEv)){
         hs.h_[0][processInt][8]->Fill(read.JetsAK8_prunedMass->at(0),EventWeight); 
         hs.h_[1][processInt][8]->Fill(read.JetsAK8_NsubjettinessTau2->at(0)/read.JetsAK8_NsubjettinessTau1->at(0),EventWeight); 
         hs.h_[2][processInt][8]->Fill(read.JetsAK8_prunedMass->at(1),EventWeight); 
         hs.h_[3][processInt][8]->Fill(read.JetsAK8_NsubjettinessTau2->at(1)/read.JetsAK8_NsubjettinessTau1->at(1),EventWeight); 
}

if(ZZM11TTM(tr,read,ProcessName,iEv)){
         hs.h_[0][processInt][9]->Fill(read.JetsAK8_prunedMass->at(0),EventWeight); 
         hs.h_[1][processInt][9]->Fill(read.JetsAK8_NsubjettinessTau2->at(0)/read.JetsAK8_NsubjettinessTau1->at(0),EventWeight); 
         hs.h_[2][processInt][9]->Fill(read.JetsAK8_prunedMass->at(1),EventWeight); 
         hs.h_[3][processInt][9]->Fill(read.JetsAK8_NsubjettinessTau2->at(1)/read.JetsAK8_NsubjettinessTau1->at(1),EventWeight); 
}

if(ZZM21TTM(tr,read,ProcessName,iEv)){
         hs.h_[0][processInt][10]->Fill(read.JetsAK8_prunedMass->at(0),EventWeight); 
         hs.h_[1][processInt][10]->Fill(read.JetsAK8_NsubjettinessTau2->at(0)/read.JetsAK8_NsubjettinessTau1->at(0),EventWeight); 
         hs.h_[2][processInt][10]->Fill(read.JetsAK8_prunedMass->at(1),EventWeight); 
         hs.h_[3][processInt][10]->Fill(read.JetsAK8_NsubjettinessTau2->at(1)/read.JetsAK8_NsubjettinessTau1->at(1),EventWeight); 
}

if(ZZM31TTM(tr,read,ProcessName,iEv)){
         hs.h_[0][processInt][11]->Fill(read.JetsAK8_prunedMass->at(0),EventWeight); 
         hs.h_[1][processInt][11]->Fill(read.JetsAK8_NsubjettinessTau2->at(0)/read.JetsAK8_NsubjettinessTau1->at(0),EventWeight); 
         hs.h_[2][processInt][11]->Fill(read.JetsAK8_prunedMass->at(1),EventWeight); 
         hs.h_[3][processInt][11]->Fill(read.JetsAK8_NsubjettinessTau2->at(1)/read.JetsAK8_NsubjettinessTau1->at(1),EventWeight); 
}

               }//Baseline for this process

       }//event loop

}//looper definition

template <class classInst,class HistogramCreater> bool Looper_bkg<classInst,HistogramCreater>::Baseline(TChain *tr,classInst& read,string ProcessName,int iEvent){

if(
read. HT>600 && 
read. MET>300 && 
read. NJets>=2 && 
read. JetsAK8->size()>1 && 
read. DeltaPhi1>0.5 && 
read. DeltaPhi2>0.5 && 
read. DeltaPhi3>0.3 && 
read. DeltaPhi4>0.3 && 
read. Muons->size() == 0 && 
read. Electrons->size() == 0 && 
read. isoMuonTracks == 0 && 
read. isoElectronTracks == 0 && 
read. isoPionTracks == 0 && 
read. JetsAK8->at(0).Pt()>170 &&
read. JetsAK8->at(1).Pt()>170
){

return true;

}
else{
return false;

}
}

template <class classInst,class HistogramCreater> bool Looper_bkg<classInst,HistogramCreater>::ProcessCuts(TChain *tr,classInst& read,string ProcessName,int iEvent){

if(ProcessName=="T5qqqqZH_mG1700"){

return true;
}

if(ProcessName=="T5qqqqZH_mG1300"){

return true;
}

if(ProcessName=="TTJets"){

return true;
}

if(ProcessName=="ZJets"){

return true;
}

if(ProcessName=="WJets"){

return true;
}

if(ProcessName=="QCD"){

return true;
}

if(ProcessName=="HTMHT"){

return true;
}

return false;
}

template <class classInst,class HistogramCreater> bool Looper_bkg<classInst,HistogramCreater>::ZZM12TLM(TChain *tr,classInst& read,string ProcessName,int iEvent){

if(/*read. JetsAK8_prunedMass->at(0)>50 &&*/
read.MET>300 &&
read.MET<500 &&
////read. JetsAK8_prunedMass->at(0)<200 &&
//read. JetsAK8_prunedMass->at(1)>50 &&
//read. JetsAK8_prunedMass->at(1)<200 &&
((read. JetsAK8_NsubjettinessTau2->at(0)/read.JetsAK8_NsubjettinessTau1->at(0)<0.6) &&
(read. JetsAK8_NsubjettinessTau2->at(1)/read.JetsAK8_NsubjettinessTau1->at(1)<0.6 ))
){
return true;
}

else{
return false;
}

}

template <class classInst,class HistogramCreater> bool Looper_bkg<classInst,HistogramCreater>::ZZM22TLM(TChain *tr,classInst& read,string ProcessName,int iEvent){

if(/*read. JetsAK8_prunedMass->at(0)>50 &&*/
read.MET>500 &&
read.MET<700 &&
//read. JetsAK8_prunedMass->at(0)<200 &&
//read. JetsAK8_prunedMass->at(1)>50 &&
//read. JetsAK8_prunedMass->at(1)<200 &&
((read. JetsAK8_NsubjettinessTau2->at(0)/read.JetsAK8_NsubjettinessTau1->at(0)<0.6) &&
(read. JetsAK8_NsubjettinessTau2->at(1)/read.JetsAK8_NsubjettinessTau1->at(1)<0.6 ))
){
return true;
}

else{
return false;
}

}

template <class classInst,class HistogramCreater> bool Looper_bkg<classInst,HistogramCreater>::ZZM32TLM(TChain *tr,classInst& read,string ProcessName,int iEvent){

if(/*read. JetsAK8_prunedMass->at(0)>50 &&*/
read.MET>700 &&
read.MET<1500 &&
//read. JetsAK8_prunedMass->at(0)<200 &&
//read. JetsAK8_prunedMass->at(1)>50 &&
//read. JetsAK8_prunedMass->at(1)<200 &&
((read. JetsAK8_NsubjettinessTau2->at(0)/read.JetsAK8_NsubjettinessTau1->at(0)<0.6) &&
(read. JetsAK8_NsubjettinessTau2->at(1)/read.JetsAK8_NsubjettinessTau1->at(1)<0.6 ))
){
return true;
}

else{
return false;
}


}

template <class classInst,class HistogramCreater> bool Looper_bkg<classInst,HistogramCreater>::ZZM11TLM(TChain *tr,classInst& read,string ProcessName,int iEvent){

if(
read.MET>300 &&
read.MET<500 &&
read. JetsAK8_prunedMass->at(0)>50 &&
read. JetsAK8_prunedMass->at(1)>50 &&
((read. JetsAK8_NsubjettinessTau2->at(0)/read.JetsAK8_NsubjettinessTau1->at(0)<0.6 && read. JetsAK8_NsubjettinessTau2->at(1)/read.JetsAK8_NsubjettinessTau1->at(1)<0.6) ||
(read. JetsAK8_NsubjettinessTau2->at(1)/read.JetsAK8_NsubjettinessTau1->at(1)<0.6 && read. JetsAK8_NsubjettinessTau2->at(0)/read.JetsAK8_NsubjettinessTau1->at(0)>0.6))
){
return true;
}

else{
return false;
}

}

template <class classInst,class HistogramCreater> bool Looper_bkg<classInst,HistogramCreater>::ZZM21TLM(TChain *tr,classInst& read,string ProcessName,int iEvent){

if(/*read. JetsAK8_prunedMass->at(0)>50 &&*/
read.MET>500 &&
read.MET<700 &&
//read. JetsAK8_prunedMass->at(0)<200 &&
//read. JetsAK8_prunedMass->at(1)>50 &&
//read. JetsAK8_prunedMass->at(1)<200 &&
((read. JetsAK8_NsubjettinessTau2->at(0)/read.JetsAK8_NsubjettinessTau1->at(0)<0.6 && read. JetsAK8_NsubjettinessTau2->at(1)/read.JetsAK8_NsubjettinessTau1->at(1)<0.6) ||
(read. JetsAK8_NsubjettinessTau2->at(1)/read.JetsAK8_NsubjettinessTau1->at(1)<0.6 && read. JetsAK8_NsubjettinessTau2->at(0)/read.JetsAK8_NsubjettinessTau1->at(0)>0.6))
){
return true;
}

else{
return false;
}

}

template <class classInst,class HistogramCreater> bool Looper_bkg<classInst,HistogramCreater>::ZZM31TLM(TChain *tr,classInst& read,string ProcessName,int iEvent){

if(/*read. JetsAK8_prunedMass->at(0)>50 &&*/
read.MET>700 &&
read.MET<1500 &&
//read. JetsAK8_prunedMass->at(0)<200 &&
//read. JetsAK8_prunedMass->at(1)>50 &&
//read. JetsAK8_prunedMass->at(1)<200 &&
((read. JetsAK8_NsubjettinessTau2->at(0)/read.JetsAK8_NsubjettinessTau1->at(0)<0.6 && read. JetsAK8_NsubjettinessTau2->at(1)/read.JetsAK8_NsubjettinessTau1->at(1)<0.6) ||
(read. JetsAK8_NsubjettinessTau2->at(1)/read.JetsAK8_NsubjettinessTau1->at(1)<0.6 && read. JetsAK8_NsubjettinessTau2->at(0)/read.JetsAK8_NsubjettinessTau1->at(0)>0.6))
){
return true;
}

else{
return false;
}

}

template <class classInst,class HistogramCreater> bool Looper_bkg<classInst,HistogramCreater>::ZZM12TTM(TChain *tr,classInst& read,string ProcessName,int iEvent){

if(read. JetsAK8_prunedMass->at(0)>75 &&
read.MET>300 &&
read.MET<500 &&
read. JetsAK8_prunedMass->at(0)<105 &&
read. JetsAK8_prunedMass->at(1)>75 &&
read. JetsAK8_prunedMass->at(1)<105 &&
((read. JetsAK8_NsubjettinessTau2->at(0)/read.JetsAK8_NsubjettinessTau1->at(0)<0.6) &&
(read. JetsAK8_NsubjettinessTau2->at(1)/read.JetsAK8_NsubjettinessTau1->at(1)<0.6 ))
){
return true;
}

else{
return false;
}

}

template <class classInst,class HistogramCreater> bool Looper_bkg<classInst,HistogramCreater>::ZZM22TTM(TChain *tr,classInst& read,string ProcessName,int iEvent){

if(read. JetsAK8_prunedMass->at(0)>75 &&
read.MET>500 &&
read.MET<700 &&
read. JetsAK8_prunedMass->at(0)<105 &&
read. JetsAK8_prunedMass->at(1)>75 &&
read. JetsAK8_prunedMass->at(1)<105 &&
((read. JetsAK8_NsubjettinessTau2->at(0)/read.JetsAK8_NsubjettinessTau1->at(0)<0.6) &&
(read. JetsAK8_NsubjettinessTau2->at(1)/read.JetsAK8_NsubjettinessTau1->at(1)<0.6 ))
){
return true;
}

else{
return false;
}

}

template <class classInst,class HistogramCreater> bool Looper_bkg<classInst,HistogramCreater>::ZZM32TTM(TChain *tr,classInst& read,string ProcessName,int iEvent){

if(read. JetsAK8_prunedMass->at(0)>75 &&
read.MET>700 &&
read.MET<1500 &&
read. JetsAK8_prunedMass->at(0)<105 &&
read. JetsAK8_prunedMass->at(1)>75 &&
read. JetsAK8_prunedMass->at(1)<105 &&
((read. JetsAK8_NsubjettinessTau2->at(0)/read.JetsAK8_NsubjettinessTau1->at(0)<0.6) &&
(read. JetsAK8_NsubjettinessTau2->at(1)/read.JetsAK8_NsubjettinessTau1->at(1)<0.6 ))
){
return true;
}

else{
return false;
}
}

template <class classInst,class HistogramCreater> bool Looper_bkg<classInst,HistogramCreater>::ZZM11TTM(TChain *tr,classInst& read,string ProcessName,int iEvent){


if(read. JetsAK8_prunedMass->at(0)>75 &&
read.MET>300 &&
read.MET<500 &&
read. JetsAK8_prunedMass->at(0)<105 &&
read. JetsAK8_prunedMass->at(1)>75 &&
read. JetsAK8_prunedMass->at(1)<105 &&
((read. JetsAK8_NsubjettinessTau2->at(0)/read.JetsAK8_NsubjettinessTau1->at(0)<0.6 && read. JetsAK8_NsubjettinessTau2->at(1)/read.JetsAK8_NsubjettinessTau1->at(1)<0.6) ||
(read. JetsAK8_NsubjettinessTau2->at(1)/read.JetsAK8_NsubjettinessTau1->at(1)<0.6 && read. JetsAK8_NsubjettinessTau2->at(0)/read.JetsAK8_NsubjettinessTau1->at(0)>0.6))
){
return true;
}

else{
return false;
}

}

template <class classInst,class HistogramCreater> bool Looper_bkg<classInst,HistogramCreater>::ZZM21TTM(TChain *tr,classInst& read,string ProcessName,int iEvent){

if(read. JetsAK8_prunedMass->at(0)>75 &&
read.MET>500 &&
read.MET<700 &&
read. JetsAK8_prunedMass->at(0)<105 &&
read. JetsAK8_prunedMass->at(1)>75 &&
read. JetsAK8_prunedMass->at(1)<105 &&
((read. JetsAK8_NsubjettinessTau2->at(0)/read.JetsAK8_NsubjettinessTau1->at(0)<0.6 && read. JetsAK8_NsubjettinessTau2->at(1)/read.JetsAK8_NsubjettinessTau1->at(1)<0.6) ||
(read. JetsAK8_NsubjettinessTau2->at(1)/read.JetsAK8_NsubjettinessTau1->at(1)<0.6 && read. JetsAK8_NsubjettinessTau2->at(0)/read.JetsAK8_NsubjettinessTau1->at(0)>0.6))
){
return true;
}

else{
return false;
}

}

template <class classInst,class HistogramCreater> bool Looper_bkg<classInst,HistogramCreater>::ZZM31TTM(TChain *tr,classInst& read,string ProcessName,int iEvent){

if(read. JetsAK8_prunedMass->at(0)>75 &&
read.MET>700 &&
read.MET<1500 &&
read. JetsAK8_prunedMass->at(0)<105 &&
read. JetsAK8_prunedMass->at(1)>75 &&
read. JetsAK8_prunedMass->at(1)<105 &&
((read. JetsAK8_NsubjettinessTau2->at(0)/read.JetsAK8_NsubjettinessTau1->at(0)<0.6 && read. JetsAK8_NsubjettinessTau2->at(1)/read.JetsAK8_NsubjettinessTau1->at(1)<0.6) ||
(read. JetsAK8_NsubjettinessTau2->at(1)/read.JetsAK8_NsubjettinessTau1->at(1)<0.6 && read. JetsAK8_NsubjettinessTau2->at(0)/read.JetsAK8_NsubjettinessTau1->at(0)>0.6))
){
return true;
}

else{
return false;
}

}

