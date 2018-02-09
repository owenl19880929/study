#include<iostream>
using namespace std;

class BASE
{
public:
   int a; 
   virtual void show(){
        cout<< "BASE"<<endl;
    }
private:
   int b;
};

class BASEA: public BASE
{
public:
    virtual void show(){
        cout<< "BASEA"<<endl;
    }
};

class BASEB:  public BASE
{
public:
    virtual void show(){
        cout<<"BASEB"<<endl;
    }
};


class BASEC
{
public:
    void show(){
        cout<<"BASEB"<<endl;
    }
};


int main(int argc, char** argv)
{
    BASE* base = new BASE;
    base->show();

    BASE* basea = new BASEA;
    basea->show();
    
    BASEB* baseb = new BASEB;
    baseb->show();

    

    cout<<sizeof(BASE)<<endl;
    cout<<sizeof(BASEA)<<endl; 
    cout<<sizeof(BASEB)<<endl;
    cout<<sizeof(BASEC)<<endl;
    return 0;
}
