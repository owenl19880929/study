//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Visitor
//  @ File Name : ConcreteVisitor.cpp
//  @ Date : 2018/1/4
//  @ Author : Owen-Li
//
//

#include <iostream>
#include "ConcreteVisitor.h"

ConcreteVisitor::ConcreteVisitor() {

}

ConcreteVisitor::~ConcreteVisitor() {

}

void ConcreteVisitor::VisitConcreateElement(Element* elem) {
   std::cout<<"new function of Element"<<std::endl;
   std::cout<<"ConcreteVisitor->VisitConcreateElement"<<std::endl;
   std::cout<<"count is: "<<std::endl;
}

