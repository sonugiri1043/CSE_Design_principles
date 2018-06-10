/*Factory Design Pattern
 *
 * Define an interface for creating an object, but let subclasses decide
 * which class to instantiate.
*/

#include <iostream>
using namespace std;

class Animal {
public:
  virtual void speak() = 0;
};

class Dog : public Animal {
public:
  void speak() {
    cout<< "Bhaw Bhaw" << endl;
  }
};

class Cat : public Animal { 
public:
  void speak() {
    cout<< "Meow Meow" << endl;
  }
};

class AbstractFactory {
public:
  virtual Animal * getAnimal( int type ) = 0;
};

class AnimalFactory : AbstractFactory {
public:
  Animal * getAnimal( int type ) {
    if( type == 0 ) {
      return new Dog();
    } else if ( type == 1 ) {
      return new Cat();
    }
    else 
      return NULL;
  }
};

int main() {
  cout<< "Factory design pattern" << endl;
  AnimalFactory *factory = new AnimalFactory();

  Animal *a = factory->getAnimal( 0 );
  Animal *b = factory->getAnimal( 1 );
  a->speak();
  b->speak();

  return 0;
}
