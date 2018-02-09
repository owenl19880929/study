#include <iostream>
#include "Observer.h"
#include "Subject.h"
#include "WeiXin.h"
#include "RoomMate.h"

int main(int argc, char** argv){
  Observer* a = new RoomMate("A", "sleeping", "get dressed and run to classroom");
  Observer* b = new RoomMate("B", "gaming", "pay the fee and run to classroom");
  Observer* c = new RoomMate("C", "shopping", "go back to school and be worried about girl friend's angry");
 
  Subject* weixin = new WeiXin();
 
  weixin->Attach(a);
  weixin->Attach(b);
  weixin->Attach(c);

  weixin->notifyBoservers("meidianming");
  weixin->notifyBoservers("dianming");

  weixin->Detach(c);
  weixin->Detach(b);
  weixin->Detach(a);

  delete weixin;
  weixin = NULL;

  delete  c;
  c = NULL;  

  delete b;
  b = NULL;
 
  delete a;
  a = NULL;

  return 0;
}
