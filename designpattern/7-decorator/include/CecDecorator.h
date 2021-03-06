//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : decorator
//  @ File Name : CecDecorator.h
//  @ Date : 2017/12/15
//  @ Author : Owen.Li
//
//


#if !defined(_CECDECORATOR_H)
#define _CECDECORATOR_H

#include "Decorator.h"
#include "TV.h"

class CecDecorator : public Decorator {
public:
	CecDecorator(TV* tv);
	~CecDecorator();
	void Operation();
private:
	void CecPlay();
};

#endif  //_CECDECORATOR_H
