//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Mediator
//  @ File Name : ListCtrl.cpp
//  @ Date : 2018/1/1
//  @ Author : 
//
//

#include <iostream>
#include "UIControl.h"
#include "ListCtrl.h"

ListCtrl::ListCtrl() {

}

ListCtrl::~ListCtrl() {

}

void ListCtrl::onListCtrlClick() {
  UIControl* pUIControl = getUIControl();
  if(pUIControl){
    pUIControl->onListCtrlClick();
  }
}

void ListCtrl::updateImage() {
  std::cout<<"ListCtrl is updaing image..."<<std::endl;
}

