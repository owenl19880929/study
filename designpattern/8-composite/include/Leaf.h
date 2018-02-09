//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : composite
//  @ File Name : Leaf.h
//  @ Date : 2017/12/25
//  @ Author : Owen-Li
//
//


#if !defined(_LEAF_H)
#define _LEAF_H

#include "Component.h"
#include <string>

class Leaf : public Component {
public:
	Leaf(string compname);
	~Leaf();
	void Operation();
	void Add(Component* component);
	void Remove(Component* component);
	Component* GetChild(int index);
	void Print();
};

#endif  //_LEAF_H