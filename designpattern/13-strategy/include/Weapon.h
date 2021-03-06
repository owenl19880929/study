//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Strategy
//  @ File Name : Weapon.h
//  @ Date : 2017/12/28
//  @ Author : Owen-Li
//
//


#if !defined(_WEAPON_H)
#define _WEAPON_H


class Weapon {
public:
        virtual ~Weapon();
	void useWeapon();
	virtual void open() = 0;
	virtual void fire() = 0;
	virtual void close() = 0;
protected:
	Weapon();
};

#endif  //_WEAPON_H
