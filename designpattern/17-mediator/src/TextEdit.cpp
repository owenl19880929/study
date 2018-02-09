//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Mediator
//  @ File Name : TextEdit.cpp
//  @ Date : 2018/1/1
//  @ Author : 
//
//

#include "UIControl.h"
#include "TextEdit.h"

TextEdit::TextEdit() {

}

TextEdit::~TextEdit() {

}

void TextEdit::onChangeText() {
  UIControl* pUIControl = getUIControl();
  if(pUIControl){
    pUIControl->onChangeText();
  }
}

