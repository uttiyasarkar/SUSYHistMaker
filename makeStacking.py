def getVarFromFile(filename):
    import imp
    f = open(filename)
    global data
    data = imp.load_source('data', '', f)
    f.close()

getVarFromFile('InputDetails.dat')
import os

import sys

sys.stdout = open('Stacking.C','w')
############    include Header files    ##########################
print '#include<iostream>\n#include <TROOT.h>\n#include <TChain.h>\n#include <TFile.h>\n#include "TLorentzVector.h"\n#include<vector>\n#include "TTree.h"\n#include "stackPlotter.C"\n#include "HistCreater.C"\n#include "HistClone.C"\nusing namespace std;\n\n'

print 'void Stacking(){\n'

print 'HistClone hl;'

print ''

print '//sample tav text could be used as argument to the stack plotter  '


print 'TPaveText *tpav_txt = new TPaveText(0.57043478,0.548342,0.8652174,0.9210471,"brNDC");'

print '    tpav_txt->SetBorderSize(0);'
print '    tpav_txt->SetFillStyle(0);'
print '    tpav_txt->SetTextAlign(11);'
print '    tpav_txt->SetTextFont(42);'
print '    tpav_txt->SetTextSize(0.04);'
print '    tpav_txt->AddText("HT >600");'
print '    tpav_txt->AddText("NJets >=2");'
print '    tpav_txt->AddText("MET>300");'
print '    tpav_txt->AddText("BTags=0");'
print '    tpav_txt->AddText("dPhi1,dPhi2>0.5");'
print '    tpav_txt->AddText("dPhi3,dPhi4>0.3");'
print '    tpav_txt->AddText("electron,muon veto,isolated electron,muon,pion track veto");'




print '//Example of how to use stack plotter'

print 'StackPlotter stack;\n'

print '//uncomment the following line. put histogram names correctly'
print '//sample arguments if you want to plot one signal,5 background and no data then use the function plotS1B5D0'
print '//if you want to use data then use the function plotS1B5D1, this way you can use all possible combinations '


print '//use following procees nums'

for icat in range(0,len(data.list_Categories)):
  for ivar in range(0,len(data.list_oneVariables)):
   # print 'stack.plotS1B4D0("%s(GeV)",tpav_txt,hl.h_[%s][0][%s],"ZH_mG1300",hl.h_[%s][2][%s],"QCD",hl.h_[%s][3][%s],"TTJets",hl.h_[%s][4][%s],"WJets",hl.h_[%s][5][%s],"ZJets");\n'%(data.list_oneVariables[ivar],ivar,icat,ivar,icat,ivar,icat,ivar,icat,ivar,icat)
   # print 'stack.plotS1B4D0("%s(GeV)",tpav_txt,hl.h_[%s][1][%s],"ZH_mG1700",hl.h_[%s][2][%s],"QCD",hl.h_[%s][3][%s],"TTJets",hl.h_[%s][4][%s],"WJets",hl.h_[%s][5][%s],"ZJets");\n'%(data.list_oneVariables[ivar],ivar,icat,ivar,icat,ivar,icat,ivar,icat,ivar,icat)
    print 'stack.plotS0B4D0("%s(GeV)",tpav_txt,hl.h_[%s][2][%s],"QCD",hl.h_[%s][3][%s],"TTJets",hl.h_[%s][4][%s],"WJets",hl.h_[%s][5][%s],"ZJets");\n'%(data.list_oneVariables[ivar],ivar,icat,ivar,icat,ivar,icat,ivar,icat)
    print 'stack.plotS2B4D0("%s(GeV)",tpav_txt,hl.h_[%s][0][%s],"ZH_mG1300",hl.h_[%s][1][%s],"ZH_mG1700",hl.h_[%s][2][%s],"QCD",hl.h_[%s][3][%s],"TTJets",hl.h_[%s][4][%s],"WJets",hl.h_[%s][5][%s],"ZJets");\n'%(data.list_oneVariables[ivar],ivar,icat,ivar,icat,ivar,icat,ivar,icat,ivar,icat,ivar,icat)

print '\n'

print '\n'
print 'f->Write();'

print '\n}'


sys.stdout.close()


