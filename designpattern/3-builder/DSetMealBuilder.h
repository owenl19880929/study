#ifndef _DSETMEALBUILDER_H_
#define _DSETMEALBUILDER_H_
#include <iostream>
#include "Builder.h"
#include "Meal.h"
#include "SetMeal.h"

class DSetMealBuilder: public Builder{
public:
    DSetMealBuilder();
    ~DSetMealBuilder();
    virtual void buildMainFood();
    virtual void buildSideFood();
    virtual void buildDrinkFood();
};

#endif
