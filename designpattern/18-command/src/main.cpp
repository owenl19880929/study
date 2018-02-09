#include <iostream>
#include "Invoker.h"
#include "ConcreteCommand.h"
#include "Receiver.h"

using namespace std;

int main(int argc, char** argv){
  
  Receiver* receiver = new Receiver();
  Command* command = new ConcreteCommand(receiver);
  Invoker* pInvoker = new Invoker(command);

  pInvoker->invoke();
 
  delete pInvoker;
  pInvoker = NULL;
  
  delete command;
  command = NULL;

  delete receiver;
  receiver = NULL;

  return 0;
}
