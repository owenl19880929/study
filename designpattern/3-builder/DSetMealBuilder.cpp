#include <iostream>
#include "Builder.h"
#include "DSetMealBuilder.h"

using namespace std;

DSetMealBuilder::DSetMealBuilder(){
    meal = new Meal();
}

DSetMealBuilder::~DSetMealBuilder(){
    delete meal;
    meal = NULL;
}  

void DSetMealBuilder::buildMainFood(){
    cout<<"D setmeal: buildMainFood...\n"<<endl;
    meal->setMainFood(SETMEALD[0]);
}

void DSetMealBuilder::buildSideFood(){
    cout<<"D setmeal: buildSideFood...\n"<<endl;
    meal->setSideFood(SETMEALD[1]);
}

void DSetMealBuilder::buildDrinkFood(){
    cout<<"D setmeal: buildDrinkFood...\n"<<endl;
    meal->setDrinkFood(SETMEALD[2]);
}
