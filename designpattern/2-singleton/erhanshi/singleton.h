#ifndef _SINGLETON_H_
#define _SINGLETON_H_

class Singleton{
protected:
  Singleton();
  ~Singleton();
private:
  static Singleton* _instance;
public:
  static Singleton* getInstance();
  void show();
};

#endif
