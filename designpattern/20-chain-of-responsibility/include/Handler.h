//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Chain
//  @ File Name : Handler.h
//  @ Date : 2018/1/4
//  @ Author : Owen-Li
//
//


#if !defined(_HANDLER_H)
#define _HANDLER_H

#include <string>
using namespace std;

class Handler {
public:
	virtual void HandleRequest(string str);
	virtual ~Handler();
	void setSuccessor(Handler* successor);
	string getName();
protected:
	string name;
	Handler();
	Handler *mSuccessor;
};

#endif  //_HANDLER_H
