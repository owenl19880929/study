#ifndef _SIMPLEFACTORY_
#define _SIMPLEFACTORY_
#include <stdio.h>
#include "AbstractProduct.h"

class AbstractFactory{

public:
  AbstractFactory();
  ~AbstractFactory();

public:
  virtual AbstractProduct* createProduct()=0;
};

class FactoryA: public AbstractFactory{
public:
  FactoryA();
  ~FactoryA();

public:
  AbstractProduct* createProduct();
};

class FactoryB: public AbstractFactory{
public:
  FactoryB();
  ~FactoryB();

public:
  AbstractProduct* createProduct();
};
#endif

