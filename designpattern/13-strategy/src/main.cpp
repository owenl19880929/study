#include <iostream>
#include "Context.h"
#include "Weapon.h"
#include "AK47.h"
#include "M16.h"

int main(int argc, char** argv){
  Weapon* ak47 = new AK47();
  Weapon* m16 = new M16();

  Context* context = new Context();
  context->setWeapon(ak47);
  context->kill();

  context->setWeapon(m16);
  context->kill();

  delete context;
  context = NULL;

  delete  ak47;
  ak47 = NULL;  

  delete  m16;
  m16 = NULL;
 
  return 0;
}
