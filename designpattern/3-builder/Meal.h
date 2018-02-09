#ifndef _MEAL_H_
#define _MEAL_H_

#include <string>

using namespace std;

class Meal{
private:
    string mainfood;
    string sidefood;
    string drinkfood;

public:
    Meal();
    ~Meal();
    void showFood();
    void setMainFood(string s_mainfood);
    void setSideFood(string s_sidefood);
    void setDrinkFood(string s_drinkfood);
};

#endif
