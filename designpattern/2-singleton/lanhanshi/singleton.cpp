#include "singleton.h"
#include <iostream>

using namespace std;

Singleton::Singleton(){
}

Singleton::~Singleton(){
}

Singleton* Singleton::_instance = 0;

Singleton* Singleton::getInstance(){
    
    if(_instance == NULL){
        _instance = new Singleton();    
    }
    return _instance;
}

void Singleton::show(){
    cout<<"Singleton-> lan han shi"<<endl;
    cout<<"a="<<a<<endl;
}

void Singleton::showa(){
    cout<<"a="<<a<<endl;
}
