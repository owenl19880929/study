#include "BSetMealBuilder.h"

BSetMealBuilder::BSetMealBuilder(){
    meal = new Meal();
}

BSetMealBuilder::~BSetMealBuilder(){
    delete meal;
    meal = NULL;
}  

void BSetMealBuilder::buildMainFood(){
    cout<<"B setmeal: buildMainFood...\n"<<endl;
    meal->setMainFood(SETMEALB[0]);

}

void BSetMealBuilder::buildSideFood(){
    cout<<"B setmeal: buildSideFood...\n"<<endl;
    meal->setSideFood(SETMEALB[1]);
}

void BSetMealBuilder::buildDrinkFood(){
    cout<<"B setmeal: buildDrinkFood...\n"<<endl;
    meal->setDrinkFood(SETMEALB[2]);
}
