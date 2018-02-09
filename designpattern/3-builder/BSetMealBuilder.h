#ifndef _BSETMEALBUILDER_H_
#define _BSETMEALBUILDER_H_
#include <iostream>
#include "Builder.h"
#include "Meal.h"
#include "SetMeal.h"

class 
BSetMealBuilder: public Builder{
public:
    BSetMealBuilder();
    ~BSetMealBuilder();
    virtual void buildMainFood();
    virtual void buildSideFood();
    virtual void buildDrinkFood();
};

#endif
