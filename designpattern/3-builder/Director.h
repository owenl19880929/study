#ifndef _DIRECTOR_H_
#define _DIRECTOR_H_

#include "Builder.h"
#include "Meal.h"

class Director{
private:
    Builder* builder;

public:
    Director();
    ~Director();

    void selectMealSet(int meal_select);
    void buildMealSet();
    Meal* getMeal();

};
#endif
