#include <iostream>
#include <vector> 

using namespace std;

/*
 Observer is a behavioral design pattern that lets you define a one-to-many dependency
 between objects so that when one object changes state, all its dependents are notified
 and updated automatically.
 */

class Observer {
  /* Observer subscribe to updates from Subject */

  int id; // assign unique ID to observer
 
public:
  Observer( int id ) {
    this->id = id;
  }

  int getId() {
    return id;
  }
  
  void update( int data ) {
    cout<< "Observer "<< this->id << " received notification for update data " << data << endl;
  }
};


class Subject {
  /* Subject keep track of all subscribed observers and notifies them about 
   any change to data */

private:
  int data;
  vector< Observer *> notifyList; // list of observers to be notified

public:
  void subscribe( Observer *observer ) {
    notifyList.push_back( observer );
    cout<< "Observer " << observer->getId() << " subscribed for update" << endl;
  }

  void unsubscribe( Observer *observer ) {
    vector< Observer *>::iterator it;
    it = find( notifyList.begin(), notifyList.end(), observer );
    if( it != notifyList.end() ) {
      notifyList.erase( it );
      cout<< "Observer " << observer->getId() << " un-subscribed for update" << endl;
    }
  }

  void setData( int _data ) {
    this->data = _data;
    notify();
  }
  
  void notify() {
    vector< Observer *>::iterator it;
    for( it = notifyList.begin(); it != notifyList.end(); ++it ) {
      (**it).update( data );
    }
  }
};

int main() {
  cout<< "Observer design pattern" << endl;

  Subject *subject = new Subject();
  subject->setData( 100 );

  Observer *o1 = new Observer( 1 );
  subject->subscribe( o1 );
  subject->setData( 200 );

  Observer *o2 = new Observer( 2 );
  subject->subscribe( o2 );
  subject->setData( 300 );

  subject->unsubscribe( o2 );
  subject->setData( 400 );
  return 0;
}
