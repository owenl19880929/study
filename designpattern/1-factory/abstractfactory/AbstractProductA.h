#ifndef _ABSTRACTPRODUCTA_
#define _ABSTRACTPRODUCTA_
#include <stdio.h>

class AbstractProductA{

public:
  AbstractProductA();
  ~AbstractProductA();

public:
  virtual void operationA() = 0;
};

class ProductA_1: public AbstractProductA{
public:
  ProductA_1();
  ~ProductA_1();

public:
  void operationA();
};

class ProductA_2: public AbstractProductA{
public:
  ProductA_2();
  ~ProductA_2();

public:
  void operationA();
};

#endif
