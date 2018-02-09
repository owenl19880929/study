#include <iostream>
#include "Target.h"
#include "Adapter.h"

int main(int argc, char** argv)
{
    Target* target = new Adapter();
    target->Request();
   
    delete target;
    target = NULL;

    return 0;
}
