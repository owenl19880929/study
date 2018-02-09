//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : flyweight
//  @ File Name : Character.cpp
//  @ Date : 2017/12/27
//  @ Author : Owen-Li
//
//


#include "Character.h"

Character::Character() {

}

Character::~Character() {

}

void Character::display(){
    std::cout<<"Character "<<this->name<<",width = "<<this->_width<<",height = "<< this->_height<<std::endl;
}

void Character::setSize(int width, int height) {
  this->_width = width;
  this->_height = height;
}
