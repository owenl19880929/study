//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Prototype
//  @ File Name : ConcretePrototype1.cpp
//  @ Date : 2017/12/6
//  @ Author : owen.li
//
//

#include<iostream>
#include "ConcretePrototype1.h"
#include "Prototype.h"

ConcretePrototype1::ConcretePrototype1(){
   std::cout<<"construct ConcretePrototype1"<<std::endl;
}

ConcretePrototype1::ConcretePrototype1(const ConcretePrototype1& p1 ){
   std::cout<<"copy construct ConcretePrototype1"<<std::endl;
}

Prototype* ConcretePrototype1::Clone() {
  return new ConcretePrototype1(*this);
}
