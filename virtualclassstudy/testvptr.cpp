#include <iostream>

using namespace std;	

class Parent
{
    public:
        Parent(){}
	void Print()
	{
	    cout<<"Parent print\n"<<endl;
	}
};

class Parent1
{
    public:
        Parent1(){}
        virtual void Print()
        {
            cout<<"Parent1 print\n"<<endl;
        }
};
int main(int argc, char** argv)
{
    Parent* p = new Parent();
    Parent1* p1 = new Parent1();
    cout<<"Parent size=" << sizeof(Parent) <<endl;
    cout<<"Parent1 size=" << sizeof(Parent1) <<endl;
    return 0;
}
