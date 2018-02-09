#ifndef _SINGLETON_H_
#define _SINGLETON_H_

class Singleton{
private:
  Singleton();
  ~Singleton();
private:
  static Singleton* _instance;
  void showa();
  int a;
public:
  static Singleton* getInstance();
  void show();
};

#endif
