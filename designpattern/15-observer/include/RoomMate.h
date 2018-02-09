//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Observer
//  @ File Name : RoomMate.h
//  @ Date : 2017/12/29
//  @ Author : Owen-Li
//
//


#if !defined(_ROOMMATE_H)
#define _ROOMMATE_H
#include <string>
#include "Observer.h"
#include "WeiXin.h"

class RoomMate : public Observer {
public:
	RoomMate(string name, string now, string next);
	~RoomMate();
	void update(const std::string &msg);
private:
	string _name;
	string _now;
	string _next;
};

#endif  //_ROOMMATE_H
