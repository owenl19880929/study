#include <iostream>
#include "Facade.h"

int main(int argc, char** argv){
  Facade* facade;
  facade->tv();
  facade->onlineplay();
  facade->sourcein();
  return 0;
}
