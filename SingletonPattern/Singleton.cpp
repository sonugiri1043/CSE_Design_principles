#include <iostream>

using namespace std;

/*
 * The singleton pattern is a design pattern that restricts the instantiation
 * of a class to one object.
 *
 * NOTE: Not handing thread safety and memory leak.
 */

class Singleton {

private:
  static Singleton *obj; /* stores the instance */

  Singleton() {} /* private constructor prevent object instantiation */

public:
  Singleton( const Singleton& ) = delete;
  Singleton& operator= ( const Singleton& ) = delete;

  static Singleton* getInstance() {
    if( obj == NULL ) {
      // not thread safe
      obj = new Singleton();
    }
    return obj;
  }
   
};

Singleton* Singleton::obj = NULL;

int main() {
  cout<< "Singletone design pattern" << endl;

  Singleton* objA = Singleton::getInstance();
  Singleton* objB = Singleton::getInstance();

  // Both ObjA and ObjB point to same instance
  cout << objA << endl;
  cout << objB << endl;

  return 0;
}
