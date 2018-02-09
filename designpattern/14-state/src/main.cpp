#include <iostream>
#include "Context.h"
#include "StateBase.h"
#include "ConcreteStateA.h"
#include "ConcreteStateB.h"

int main(int argc, char** argv){
  StateBase* stateA = new ConcreteStateA();
  StateBase* stateB = new ConcreteStateB();

  Context* context = new Context(stateA);
  context->request();
  
  context->changeState(stateB);

  context->request();

  delete context;
  context = NULL;

  delete  stateB;
  stateB = NULL;  

  delete  stateA;
  stateA = NULL;
 
  return 0;
}
