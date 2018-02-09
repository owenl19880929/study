//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Observer
//  @ File Name : Subject.h
//  @ Date : 2017/12/29
//  @ Author : Owen-Li
//
//


#if !defined(_SUBJECT_H)
#define _SUBJECT_H
#include <iostream>
#include <string>
#include <list>
#include "Observer.h"

using namespace std;

class Subject {
public:
	void Attach(Observer* o);
	void Detach(Observer* o);
	void notifyBoservers(const std::string &msg);
	virtual ~Subject();
private:
	list<Observer*> *observers;
protected:
	Subject();
};

#endif  //_SUBJECT_H