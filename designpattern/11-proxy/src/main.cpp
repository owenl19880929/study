#include <iostream>
#include "Person.h"
#include "ProxyTom.h"

int main(int argc, char** argv){
  ProxyTom* proxy = new ProxyTom();
  proxy->Request();
  
  return 0;
}
