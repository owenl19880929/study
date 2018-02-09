#include "SetMeal.h"
#include "ASetMealBuilder.h"

ASetMealBuilder::ASetMealBuilder(){
    meal = new Meal();
}

ASetMealBuilder::~ASetMealBuilder(){
    delete meal;
    meal = NULL;
}  

void ASetMealBuilder::buildMainFood(){
    cout<<"A setmeal: buildMainFood...\n"<<endl;
    meal->setMainFood(SETMEALA[0]);

}

void ASetMealBuilder::buildSideFood(){
    cout<<"A setmeal: buildSideFood...\n"<<endl;
    meal->setSideFood(SETMEALA[1]);
}

void ASetMealBuilder::buildDrinkFood(){
    cout<<"A setmeal: buildDrinkFood...\n"<<endl;
    meal->setDrinkFood(SETMEALA[2]);
}
