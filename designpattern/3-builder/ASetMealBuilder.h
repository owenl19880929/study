#ifndef _ASETMEALBUILDER_H_
#define _ASETMEALBUILDER_H_
#include <iostream>
#include "Builder.h"
#include "Meal.h"
#include "SetMeal.h"

class ASetMealBuilder: public Builder{

public:
    ASetMealBuilder();
    ~ASetMealBuilder();
    virtual void buildMainFood();
    virtual void buildSideFood();
    virtual void buildDrinkFood();
};

#endif

