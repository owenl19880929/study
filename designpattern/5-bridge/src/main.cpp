#include <iostream>
#include "Abstraction.h"
#include "RefinedAbstractionA.h"
#include "RefinedAbstractionB.h"
#include "AbstractionImplement.h"
#include "ConcreatAbstractionImplementA.h"
#include "ConcreatAbstractionImplementB.h"

using namespace std;

int main(int argc, char** argv)
{
    AbstractionImplement* abstractionimpl;
    Abstraction* abstraction;
    
    abstractionimpl = new ConcreatAbstractionImplementA();
    abstraction = new RefinedAbstractionA(*abstractionimpl);
    abstraction->Operation1();

    delete abstractionimpl;
    abstractionimpl = NULL;
    delete abstraction;
    abstraction = NULL;

    abstractionimpl = new ConcreatAbstractionImplementB();
    abstraction = new RefinedAbstractionA(*abstractionimpl);
    abstraction->Operation1();

    delete abstractionimpl;
    abstractionimpl = NULL;
    delete abstraction;
    abstraction = NULL;

    abstractionimpl = new ConcreatAbstractionImplementA();
    abstraction = new RefinedAbstractionB(*abstractionimpl);
    abstraction->Operation1();

    delete abstractionimpl;
    abstractionimpl = NULL;
    delete abstraction;
    abstraction = NULL;

    abstractionimpl = new ConcreatAbstractionImplementB();
    abstraction = new RefinedAbstractionB(*abstractionimpl);
    abstraction->Operation1();

    delete abstractionimpl;
    abstractionimpl = NULL;
    delete abstraction;
    abstraction = NULL;

}


