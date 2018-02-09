#include <iostream>

#include "TV.h"
#include "TVPlay.h"
#include "Decorator.h"
#include "ArcDecorator.h"
#include "HdmiDecorator.h"
#include "CecDecorator.h"

int main(int argc, char** argv)
{
    TV* tv = new TVPlay();
    
    Decorator* customer1 = NULL;
    customer1 = new ArcDecorator(tv);
    std::cout<<"customer->1"<<std::endl;
    customer1->Operation();
    delete customer1;
    customer1 = NULL;


    Decorator* customer2 =NULL;
    std::cout<<"customer->2"<<std::endl;
    customer2 = new HdmiDecorator(tv);
    customer2 = new ArcDecorator(customer2);
    customer2->Operation();
    delete customer2;
    customer2 = NULL;


   
    
    Decorator* customer3 =NULL;
    std::cout<<"customer->3"<<std::endl;
    customer3 = new HdmiDecorator(tv);
    customer3 = new ArcDecorator(customer3);
    customer3 = new CecDecorator(customer3);
    customer3->Operation();
    delete customer3;
    customer3 = NULL;

    delete tv;
    tv = NULL;
        
    return 0;
}
