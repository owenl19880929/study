#include "AbstractProductB.h"

AbstractProductB::AbstractProductB(){
}

AbstractProductB::~AbstractProductB(){
}

ProductB_1::ProductB_1(){
}

ProductB_1::~ProductB_1(){
}

void ProductB_1::operationB(){
  fprintf(stderr, "ProductB_1 operation\n");
}

ProductB_2::ProductB_2(){
}

ProductB_2::~ProductB_2(){
}

void ProductB_2::operationB(){
  fprintf(stderr, "ProductB_2 operation\n");
}
