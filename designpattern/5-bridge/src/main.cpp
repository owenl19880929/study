#include <iostream>
#include "Abstraction.h"
#include "RefinedAbstraction.h"

#include "AbstractionImplement.h"
#include "ConcreatAbstractionImplementA.h"
#include "ConcreatAbstractionImplementB.h"

using namespace std;

int main(int argc, char** argv)
{
    AbstractionImplement* abstractionimpl;
    Abstraction* abstraction;
    
    abstractionimpl = new ConcreatAbstractionImplementA();
    abstraction = new RefinedAbstraction(*abstractionimpl);
    abstraction->Operation1();

    delete abstractionimpl;
    abstractionimpl = NULL;
    delete abstraction;
    abstraction = NULL;

    abstractionimpl = new ConcreatAbstractionImplementB();
    abstraction = new RefinedAbstraction(*abstractionimpl);
    abstraction->Operation1();

    delete abstractionimpl;
    abstractionimpl = NULL;
    delete abstraction;
    abstraction = NULL;
}


