#ifndef _BUILDER_H_
#define _BUILDER_H_

#include "Meal.h"

class Builder{
protected: 
    Meal* meal;

public:
    Builder(){}
    ~Builder(){}
    virtual void buildMainFood() = 0;
    virtual void buildSideFood() = 0;
    virtual void buildDrinkFood() = 0;

     Meal* getMealSet(){
        return meal;
     }
};
#endif
