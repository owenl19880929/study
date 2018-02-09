#ifndef _ABSTRACTPRODUCT_
#define _ABSTRACTPRODUCT_
#include <stdio.h>

class AbstractProduct{

public:
  AbstractProduct();
  ~AbstractProduct();

public:
  virtual void operation() = 0;
};

class ProductA: public AbstractProduct{
public:
  ProductA();
  ~ProductA();

public:
  void operation();
};

class ProductB: public AbstractProduct{
public:
  ProductB();
  ~ProductB();

public:
  void operation();
};

#endif
