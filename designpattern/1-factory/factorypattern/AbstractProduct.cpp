#include "AbstractProduct.h"

AbstractProduct::AbstractProduct(){
}

AbstractProduct::~AbstractProduct(){
}

ProductA::ProductA(){
}

ProductA::~ProductA(){
}

void ProductA::operation(){
  fprintf(stderr, "ProductA operation\n");
}

ProductB::ProductB(){
}

ProductB::~ProductB(){
}

void ProductB::operation(){
  fprintf(stderr, "ProductB operation \n");
}

