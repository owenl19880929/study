#include <iostream>
#include "Director.h"
#include "SetMeal.h"

int main(int argc, char** argv){
    Director* director = new Director();
    int i;
    for(i = 0; i < SET_D+1; i++){

        director->selectMealSet(i);
        director->buildMealSet();
        director->getMeal()->showFood();
    }
    return 0;
}

