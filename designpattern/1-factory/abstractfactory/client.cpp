#include "AbstractFactory.h"

int main(){
  AbstractFactory* factory = new Factory1();
  AbstractProductA* producta = factory->createProductA();
  AbstractProductB* productb = factory->createProductB();
  producta->operationA();
  productb->operationB();
  delete producta;
  producta = NULL;
  delete productb;
  productb = NULL;
  delete factory;
  factory = NULL;

  factory = new Factory2();
  producta = factory->createProductA();
  productb = factory->createProductB();
  producta->operationA();
  productb->operationB();
  delete producta;
  producta = NULL;
  delete productb;
  productb = NULL;
  delete factory;
  factory = NULL;
  return 0;
}
