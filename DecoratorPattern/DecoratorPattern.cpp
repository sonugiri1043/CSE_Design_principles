#include <iostream>
#include <string>

using namespace std;

/*
 * Decorator Design Pattern
 *
 * Decorator pattern allows a user to add new functionality to an existing
 * object without altering its structure. 
 */

class Window {
public:
  virtual string desc() = 0;
};

class SimpleWindow : public Window {
  /* Object we are going to dynamically add new behaviour to */
public:
  string desc() {
    return "Window glass \n";
  }
};

class WindowDecorator : public Window {
protected:
  Window *window; // has-a relationship

public:
  WindowDecorator( Window *w ) : window(w) {}
};

class WoodenWindow : public WindowDecorator {
public:
  WoodenWindow( Window *w ) : WindowDecorator(w) {}

  string desc() {
    return window->desc() + "with wooden frame \n";
  }
};

class SteelWindow : public WindowDecorator {
public:
  SteelWindow( Window *w ) : WindowDecorator(w) {}

  string desc() {
    return window->desc() + "with steel frame\n";
  }
};

int main() {
  cout<< "Decorator design pattern" << endl;
  Window *simple = new SimpleWindow();
  cout<< simple->desc() << endl;

  Window *wooden = new WoodenWindow( new SimpleWindow() );
  cout<< wooden->desc() << endl;

  Window *custom = new SteelWindow( new WoodenWindow( new SimpleWindow() ) );
  cout<< custom->desc() << endl;

  Window *doubleWooden = new WoodenWindow( new WoodenWindow( new SimpleWindow() ) );
  cout<< doubleWooden->desc() << endl;

  return 0;
}
