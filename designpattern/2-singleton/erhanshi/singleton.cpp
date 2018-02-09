#include "singleton.h"
#include <iostream>

using namespace std;

Singleton::Singleton(){
}

Singleton::~Singleton(){
}

Singleton* Singleton::_instance = new Singleton();

Singleton* Singleton::getInstance(){
    return _instance;
}

void Singleton::show(){
    cout<<"Singleton-> er han shi"<<endl;
}
