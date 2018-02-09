#include <iostream>
#include "Originator.h"
#include "Caretaker.h"
#include "Memento.h"

using namespace std;

int main(int argc, char** argv){
  
  Originator* o = new Originator("state-1");
  cout<<"old state: "<<o->getState()<<endl;

  Caretaker* ct = new Caretaker();
  ct->setMemento(o->createMemento());

  o->setState("state-2");
  cout<<"new state: "<<o->getState()<<endl;

  o->restoreFromMemento(ct->getMemento());
  cout<<"restore state: "<<o->getState()<<endl;

  o->destroyMemento(ct->getMemento());

  delete ct;
  ct = NULL;

  delete o;
  o = NULL;
  
  return 0;
}
