#ifndef _CSETMEALBUILDER_H_
#define _CSETMEALBUILDER_H_
#include <iostream>
#include "Builder.h"
#include "Meal.h"
#include "SetMeal.h"

class 
CSetMealBuilder: public Builder{
public:
    CSetMealBuilder();
    ~CSetMealBuilder();
    virtual void buildMainFood();
    virtual void buildSideFood();
    virtual void buildDrinkFood();
};

#endif
