//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Memento
//  @ File Name : Caretaker.cpp
//  @ Date : 2018/1/1
//  @ Author : Owen-Li
//
//

#include "Memento.h"
#include "Caretaker.h"

Caretaker::Caretaker() {

}

Caretaker::~Caretaker() {
}

void Caretaker::setMemento(Memento* memento) {
  this->memento = memento;
}

Memento* Caretaker::getMemento() {
  return this->memento;
}

