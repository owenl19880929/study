#include "AbstractProductA.h"

AbstractProductA::AbstractProductA(){
}

AbstractProductA::~AbstractProductA(){
}

ProductA_1::ProductA_1(){
}

ProductA_1::~ProductA_1(){
}

void ProductA_1::operationA(){
  fprintf(stderr, "ProductA_1 operation\n");
}

ProductA_2::ProductA_2(){
}

ProductA_2::~ProductA_2(){
}

void ProductA_2::operationA(){
  fprintf(stderr, "ProductA_2 operation\n");
}
