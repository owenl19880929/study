//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Memento
//  @ File Name : Originator.h
//  @ Date : 2018/1/1
//  @ Author : Owen-Li
//
//


#if !defined(_ORIGINATOR_H)
#define _ORIGINATOR_H

#include "Memento.h"
#include <string>

using namespace std;

class Originator {
public:
	Originator(const string& state);
	~Originator();
	void restoreFromMemento(Memento* m);
	Memento* createMemento();
	void setState(const string & state);
	string getState();
        void destroyMemento(Memento* m);
private:
	string _state;
};

#endif  //_ORIGINATOR_H