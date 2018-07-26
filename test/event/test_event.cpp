/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

// Local Includes

// Project Includes
#include <cpp_util/event/event.h>
#include <unittest/test.h>

// External Includes
#include <iostream>

//
// Helper Classes:
//

// A class used to test event functionality.
class EventClass
{
  public:
  
  /*
   * Constructors:
   */
  
  // Constructs a new instance of the "EventClass" class.
  EventClass()
  {
    EventVariable = 0;
  }
  
  // Destroys this instance of the "EventClass" class.
  ~EventClass()
  {
    
  }
  
  // Gets the variable.
  void CallEvent(int var)
  {
    EventVariable = var;
  }
  
  // Stores a variable used to test event functionality.
  int EventVariable;
};

// Tests creating an event class.
TEST(Event, BlankEvent)
{
  Event<int> event;
}

// Tests creating an event class, and firing the event.
// This doesn't test for anything, but ensures that this
// works.
TEST(Event, CallNoListener)
{
  Event<int> event;
  
  event.Fire(5);
}

// Tests creating an event class, adding a listener and firing the event.
TEST(Event, CallSingleListener)
{
  Event<int> event;
  
  EventClass listener;
  
  event.Subscribe<EventClass>(listener, &EventClass::CallEvent);
  
  event.Fire(5);
  
  ASSERT_EQ(listener.EventVariable, 5) << "An incorrect value was returned.";
}

// Tests creating an event class, adding two listeners and firing the event.
TEST(Event, CallTwoListeners)
{
  Event<int> event;
  
  EventClass listener1;
  event.Subscribe(listener1, &EventClass::CallEvent);
    
  EventClass listener2;
  event.Subscribe(listener2, &EventClass::CallEvent);
  
  event.Fire(5);
  
  ASSERT_EQ(listener1.EventVariable, 5) << "An incorrect value was returned.";
  ASSERT_EQ(listener2.EventVariable, 5) << "An incorrect value was returned.";
}

// Tests creating an event class, adding a listeners and then removing it.
TEST(Event, RemoveListener)
{
  Event<int> event;
  
  EventClass eventClass1;
  auto listener1 = event.Subscribe(eventClass1, &EventClass::CallEvent);
    
  EventClass eventClass2;
  auto listener2 = event.Subscribe(eventClass2, &EventClass::CallEvent);
  
  event.Fire(1);
  
  event.Remove(listener1);
  
  event.Fire(5);
  
  ASSERT_EQ(eventClass1.EventVariable, 1) << "An incorrect value was returned.";
  ASSERT_EQ(eventClass2.EventVariable, 5) << "An incorrect value was returned.";
}
