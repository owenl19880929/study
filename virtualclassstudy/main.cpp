#include <iostream>

using namespace std;

class A{
public:  
  A(){}
  ~A(){}

private:
  int a;

public:
  int b;
};


int main(int argc, char**argv){

  cout<<sizeof(A)<<endl;
  return 0;
}

