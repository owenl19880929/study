//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Proxy
//  @ File Name : ProxyTom.h
//  @ Date : 2017/12/28
//  @ Author : Owen-Li
//
//


#if !defined(_PROXYTOM_H)
#define _PROXYTOM_H

#include "Person.h"
#include "Tom.h"

class ProxyTom : public Person {
public:
	ProxyTom();
	~ProxyTom();
	void Request();
private:
	Tom *tom;
};

#endif  //_PROXYTOM_H
