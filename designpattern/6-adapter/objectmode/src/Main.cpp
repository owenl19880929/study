#include <iostream>
#include "Target.h"
#include "Adapter.h"

int main(int argc, char** argv)
{
    Adaptee* adaptee = new Adaptee();
    Target* target = new Adapter(adaptee);
    
    target->Request();
   
    delete target;
    target = NULL;
    delete adaptee;
    adaptee = NULL;

    return 0;
}
