#include <iostream>
#include "Handler.h"
#include "FootballPlayer.h"


using namespace std;

int main(int argc, char** argv){
  
  Handler* xiaoli = new FootballPlayer("打字员小李");
  Handler* xiaozhang = new FootballPlayer("玩游戏小张");
  Handler* laoli = new FootballPlayer("主任老李");

  xiaoli->setSuccessor(xiaozhang);
  xiaozhang->setSuccessor(laoli);
  laoli->setSuccessor(NULL);
  xiaoli->HandleRequest("办个事");

  xiaoli->HandleRequest("主任老李");
  
  xiaoli->HandleRequest("玩游戏小张");
  delete xiaoli;
  xiaoli = NULL;
  
  delete xiaozhang;
  xiaozhang = NULL;

  delete laoli;
  laoli = NULL;

  return 0;
}
