//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Observer
//  @ File Name : Subject.cpp
//  @ Date : 2017/12/29
//  @ Author : Owen-Li
//
//
#include <iostream>
#include <string>
#include <list>
#include "Subject.h"
#include "Observer.h"

void Subject::Attach(Observer* o) {
  if(NULL != o){
    observers->push_back(o);  
  }
}

void Subject::Detach(Observer* o) {
  if(NULL != o && observers->size()>0){
    observers->remove(o);
  }
}

void Subject::notifyBoservers(const std::string &msg) {
  std::list<Observer*>::iterator it = observers->begin();
  for(;it != observers->end(); ++it){
    if((*it) != NULL){
      (*it)->update(msg);
    }
  }
}

Subject::~Subject() {
  delete observers;
}

Subject::Subject() {
  observers = new std::list<Observer*>();
}

