//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Iteratro
//  @ File Name : Aggregate.h
//  @ Date : 2018/1/10
//  @ Author : Owen-Li
//
//


#if !defined(_AGGREGATE_H)
#define _AGGREGATE_H

#include "Iterator.h"

template<class Item>
class Aggregate {
public:
	virtual ~Aggregate();
	virtual Iterator<Item>* createIterator() = 0;
protected:
	Aggregate();
};

template <class Item>
Aggregate<Item >::~Aggregate() {

}

template <class Item>
Aggregate<Item >::Aggregate() {

}

#endif  //_AGGREGATE_H
