#include <iostream>
#include "UIWindow.h"
#include "UIControl.h"

using namespace std;

int main(int argc, char** argv){
  

  UIControl* uicontrol = new UIControl();
  
  TextEdit* textedit = new TextEdit();
  ListView* listview = new ListView();
  ListCtrl* listctrl = new ListCtrl();

  textedit->setUIControl(uicontrol);
  listview->setUIControl(uicontrol);
  listctrl->setUIControl(uicontrol);

  uicontrol->setTextEdit(textedit);
  uicontrol->setListView(listview);
  uicontrol->setListCtrl(listctrl);
  cout<<"---textedit->onChangeText"<<endl;
  textedit->onChangeText();
  cout<<"---listview->onListViewDoubleClick"<<endl;
  listview->onListViewDoubleClick();
  cout<<"---listctrl->onListCtrlClick"<<endl;
  listctrl->onListCtrlClick();

  delete listctrl;
  listctrl = NULL;
  
  delete listview;
  listview = NULL;

  delete textedit;
  textedit = NULL;

  delete uicontrol; 
  uicontrol = NULL;

  return 0;
}
