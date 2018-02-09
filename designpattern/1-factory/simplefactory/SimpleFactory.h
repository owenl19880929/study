#ifndef _SIMPLEFACTORY_
#define _SIMPLEFACTORY_
#include <stdio.h>
#include "AbstractProduct.h"

class AbstractFactory{

public:
  AbstractFactory();
  ~AbstractFactory();

public:
  virtual AbstractProduct* createProduct(int type) = 0;
};

class SimpleFactory: public AbstractFactory{
public:
  SimpleFactory();
  ~SimpleFactory();

public:
  AbstractProduct* createProduct(int type);
};
#endif

