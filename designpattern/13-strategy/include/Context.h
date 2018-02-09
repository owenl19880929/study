//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Strategy
//  @ File Name : Context.h
//  @ Date : 2017/12/28
//  @ Author : Owen-Li
//
//


#if !defined(_CONTEXT_H)
#define _CONTEXT_H

#include "Weapon.h"

class Context {
public:
	Context();
	~Context();
	void setWeapon(Weapon* weapon);
	void kill();
private:
	Weapon *_weapon;
};

#endif  //_CONTEXT_H
