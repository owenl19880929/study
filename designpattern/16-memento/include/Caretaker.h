//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Memento
//  @ File Name : Caretaker.h
//  @ Date : 2018/1/1
//  @ Author : Owen-Li
//
//


#if !defined(_CARETAKER_H)
#define _CARETAKER_H

#include "Memento.h"

class Caretaker {
public:
	Caretaker();
	~Caretaker();
	void setMemento(Memento* memento);
	Memento* getMemento();
private:
	Memento *memento;
};

#endif  //_CARETAKER_H
