#include "CSetMealBuilder.h"

CSetMealBuilder::CSetMealBuilder(){
    meal = new Meal();
}

CSetMealBuilder::~CSetMealBuilder(){
    delete meal;
    meal = NULL;
}  

void CSetMealBuilder::buildMainFood(){
    cout<<"C setmeal: buildMainFood...\n"<<endl;
    meal->setMainFood(SETMEALC[0]);

}

void CSetMealBuilder::buildSideFood(){
    cout<<"C setmeal: buildSideFood...\n"<<endl;
    meal->setSideFood(SETMEALC[1]);
}

void CSetMealBuilder::buildDrinkFood(){
    cout<<"C setmeal: buildDrinkFood...\n"<<endl;
    meal->setDrinkFood(SETMEALC[2]);
}
