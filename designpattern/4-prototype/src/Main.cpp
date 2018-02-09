//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Prototype
//  @ File Name : main.cpp
//  @ Date : 2017/12/6
//  @ Author : owen.li
//
//

#include "Prototype.h"
#include "ConcretePrototype1.h"
#include "ConcretePrototype2.h"

int main(int argc, char** argv){
    Prototype* p1 = new ConcretePrototype1();
    Prototype* p1_copy = p1->Clone();

    Prototype* p2 = new ConcretePrototype2();
    Prototype* p2_copy = p2->Clone();

    delete p1;
    delete p1_copy;
    delete p2;
    delete p2_copy;

    return 0;
}
