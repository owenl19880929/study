#include <iostream>
#include "Meal.h"

//using namespace std;

Meal::Meal(){
}

Meal::~Meal(){
}

void Meal::showFood(){
    cout<<"mainfood is "+mainfood+", sidefood is "+sidefood+", drink is "+drinkfood+"\n"<<endl;
}

void Meal::setMainFood(string s_mainfood){
    mainfood = s_mainfood;
}

void Meal::setSideFood(string s_sidefood){
    sidefood = s_sidefood;
}

void Meal::setDrinkFood(string s_drinkfood){
    drinkfood = s_drinkfood;
}
