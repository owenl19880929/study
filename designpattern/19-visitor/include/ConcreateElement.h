//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Visitor
//  @ File Name : ConcreateElement.h
//  @ Date : 2018/1/4
//  @ Author : Owen-Li
//
//


#if !defined(_CONCREATEELEMENT_H)
#define _CONCREATEELEMENT_H

#include "Element.h"

class ConcreateElement : public Element {
public:
	ConcreateElement();
	~ConcreateElement();
	void Accept(Visitor* v);

};

#endif  //_CONCREATEELEMENT_H
