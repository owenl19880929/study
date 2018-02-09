//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : State
//  @ File Name : Context.h
//  @ Date : 2017/12/29
//  @ Author : Owen-Li
//
//


#if !defined(_CONTEXT_H)
#define _CONTEXT_H


//#include "StateBase.h"
class StateBase;

class Context {
public:
	Context(StateBase* state);
	~Context();
	void request();
        void changeState(StateBase* state);
private:
	StateBase* _state;
};

#endif  //_CONTEXT_H
