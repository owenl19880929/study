//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Bridge
//  @ File Name : RefinedAbstractionA.h
//  @ Date : 2017/12/8
//  @ Author : owen.li
//
//


#if !defined(_REFINEDABSTRACTIONA_H)
#define _REFINEDABSTRACTIONA_H

#include "Abstraction.h"
#include "AbstractionImplement.h"

class RefinedAbstraction : public Abstraction {
public:
    RefinedAbstraction(AbstractionImplement& impl);
    void Operation1();

private:
    AbstractionImplement* _impl;
};

#endif  //_REFINEDABSTRACTIONA_H