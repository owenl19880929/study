#include <iostream>

#include "Director.h"

#include "Builder.h"
#include "ASetMealBuilder.h"
#include "BSetMealBuilder.h"
#include "CSetMealBuilder.h"
#include "DSetMealBuilder.h"
#include "SetMeal.h"

Director::Director(){
    builder = NULL;
}

Director::~Director(){
    delete builder;
    builder = NULL;
}

void Director::selectMealSet(int meal_select){
    switch(meal_select){
        case SET_A:
            builder = new ASetMealBuilder();
            break;
        case SET_B:
            builder = new BSetMealBuilder();
            break;
        case SET_C:
            builder = new CSetMealBuilder();
            break;
        case SET_D:
            builder = new DSetMealBuilder();
            break;
        default:
            builder = new ASetMealBuilder();
            break;
    }
}

void Director::buildMealSet(){
    builder->buildMainFood();
    builder->buildSideFood();
    builder->buildDrinkFood();
}

Meal* Director::getMeal(){
    builder->getMealSet();
}
