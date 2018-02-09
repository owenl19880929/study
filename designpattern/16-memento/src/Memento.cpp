//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Memento
//  @ File Name : Memento.cpp
//  @ Date : 2018/1/1
//  @ Author : Owen-Li
//
//

#include <string>
#include "Memento.h"

using namespace std;

Memento::Memento(const string& state) {
  this->_state = state;
}

Memento::~Memento() {

}

string Memento::getState() {
  return this->_state;
}

void Memento::setState(const string& state) {
  this->_state = state;
}
