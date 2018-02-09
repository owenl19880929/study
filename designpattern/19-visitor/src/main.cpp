#include <iostream>
#include "ConcreteVisitor.h"
#include "ConcreateElement.h"


using namespace std;

int main(int argc, char** argv){
  
  Visitor* visitor = new ConcreteVisitor();
  Element* ele = new ConcreateElement();
  ele->Accept(visitor);

  delete ele;
  ele = NULL;
  
  delete visitor;
  visitor = NULL;

  return 0;
}
