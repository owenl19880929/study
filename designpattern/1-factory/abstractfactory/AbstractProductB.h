#ifndef _ABSTRACTPRODUCTB_
#define _ABSTRACTPRODUCTB_
#include <stdio.h>

class AbstractProductB{

public:
  AbstractProductB();
  ~AbstractProductB();

public:
  virtual void operationB() = 0;
};

class ProductB_1: public AbstractProductB{
public:
  ProductB_1();
  ~ProductB_1();

public:
  void operationB();
};

class ProductB_2: public AbstractProductB{
public:
  ProductB_2();
  ~ProductB_2();

public:
  void operationB();
};

#endif
