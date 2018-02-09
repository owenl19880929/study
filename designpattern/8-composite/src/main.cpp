#include <iostream>
#include <string>

#include "Component.h"
#include "Composite.h"
#include "Leaf.h"


int main(int argc, char** argv){
  
  Component* headquarter = new Composite("zhong guo");
  
  Component* headquarterBJ = new Leaf("bei jing human resource department");
  
  Component* subheadSH = new Composite("shang hai fen bu");
  Component* subheadNJ = new Composite("nan jing fen bu");
  Component* subheadSZ = new Composite("shen zhen fen bu");
  
  headquarter->Add(headquarterBJ);
  headquarter->Add(subheadSH);
  headquarter->Add(subheadNJ);
  headquarter->Add(subheadSZ);
  
  headquarter->Print();
  std::cout<<"-------------------------------------"<<std::endl;

  Component* subheadSHHR = new Leaf("shang hai human resource department");
  Component* subheadSHCG = new Leaf("shang hai purchasing  department");
  Component* subheadSHSL = new Leaf("shang hai sales department");

  subheadSH->Add(subheadSHHR);
  subheadSH->Add(subheadSHCG);
  subheadSH->Add(subheadSHSL);

  headquarter->Print();
  subheadSH->Print(); 
  std::cout<<"-------------------------------------"<<std::endl;  

  subheadSH->Remove(subheadSHHR);
  headquarter->Print();
  subheadSH->Print();


  if(headquarter != NULL){
    std::cout<<"delete headquarter"<<std::endl;
    delete headquarter;
    headquarter = NULL;
  }

  return 0;
}
