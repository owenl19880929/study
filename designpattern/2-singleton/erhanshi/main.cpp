#include<iostream>
#include"singleton.h"

using namespace std;

int main(int argc, char**argv){
  cout<<"owen start singleton test!"<<endl;
  Singleton* sgn = Singleton::getInstance(); 
  sgn->show();
  return 0;
}
