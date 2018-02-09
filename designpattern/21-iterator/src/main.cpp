#include <iostream>
#include "Aggregate.h"
#include "ConcreteAggregate.h"
#include "Iterator.h"
#include "ConcreteIterator.h"

using namespace std;

int main(int argc, char** argv){
  
  Aggregate<int> * aggr = new ConcreteAggregate<int>();  
  Iterator<int> *it = aggr->createIterator();  
  
  for(it->First();!it->IsDone();it->Next())  
  {  
        cout<<*(it->CurrentItem())<<endl;  
  }  
  delete it;  
  delete aggr; 
  
  return 0;
}
