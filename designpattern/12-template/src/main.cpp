#include <iostream>
#include "TvMaker.h"
#include "PptvBand.h"
#include "LetvBand.h"

int main(int argc, char** argv){
  TvMaker* tv = new PptvBand();
  tv->makeFlow();

  delete tv;
  tv = NULL;

  tv = new LetvBand();
  tv->makeFlow();
  
  delete tv;
  tv = NULL;  
  return 0;
}
