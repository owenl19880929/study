#include <iostream>
#include "CharacterFactory.h"
#include "Character.h"

int main(int argc, char** argv){
  CharacterFactory* fc = new CharacterFactory();

  Character* character = fc->getCharacter("A");
  character->display();
  character->setSize(200, 200);
  character->display();  

  Character* character1 = fc->getCharacter("A");
  character->display();
  character->setSize(300, 300);
  character->display();

  Character* characterb = fc->getCharacter("B");
  characterb->display();
  characterb->setSize(200, 200);
  characterb->display();
 
  Character* characterb1 = fc->getCharacter("B");
  characterb1->display();
  characterb1->setSize(300, 300);
  characterb1->display();
  
  return 0;
}
