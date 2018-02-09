#ifndef _SETMEAL_H_
#define _SETMEAL_H_
#include <string>

using namespace std;

const int SETMEAL_MAX = 3;
/*
class SetMeal{
public:
  static  int SET_A;
  static  int SET_B;
  static  int SET_C;
  static  int SET_D;

  static const string SETMEALA[SETMEAL_MAX];
  static const string SETMEALB[SETMEAL_MAX];
  static const string SETMEALC[SETMEAL_MAX];
  static const string SETMEALD[SETMEAL_MAX];
};
*/
const int SET_A = 0;
const int SET_B = 1;
const int SET_C = 2;
const int SET_D = 3;

const string SETMEALA[SETMEAL_MAX] = {"mantou", "haidaisi", "kele"};
const string SETMEALB[SETMEAL_MAX] = {"shuijiao", "tudou", "cha"};
const string SETMEALC[SETMEAL_MAX] = {"mifan", "jitui", "xuedi"};
const string SETMEALD[SETMEAL_MAX] = {"miamtiao", "yatui", "kaishui"};


/*
class SetMeal{

public:

    static const int SET_A = 0;
    static const int SET_B = 1;
    static const int SET_C = 2;
    static const int SET_D = 3;
    
    static const int SETMEAL_MAX = 4;
    static const int ITEMS_COUNT = 3;
    static string setmeals[SETMEAL_MAX][ITEMS_COUNT] = {
        {"mantou", "haidaisi", "kele"},
        {"shuijiao", "tudou", "cha"},
        {"mifan", "jitui", "xuedi"},
        {"miamtiao", "yatui", "kaishui"}
    };
    
    static SetMeal* getDefinedSetMeal(int select){
        return &setmeals[select];
    }

};
*/
#endif
