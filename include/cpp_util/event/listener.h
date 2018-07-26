/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

#ifndef LISTENER_H
#define LISTENER_H

// System Includes
#include <functional>

// Stores a class which contains a listener for an event.
template <typename... TParams>
class Listener
{
  public:
  
    //
    // Type Definitions
    //
    
    // Stores the type used as the callback delegate.
    using MethodType = void (TParams...);
    
    //
    // Constructors
    //
    
    // Creates a new instance of the Listener class.
    // @param listenerId The unique identifier.
    // @param instance The instance.
    // @param callback The callback.
    Listener(int listenerId, std::function<MethodType> callback)
      : callback(callback), listenerId(listenerId)
    {
      
    }

    // Destroys this instance of the Listener class.
    virtual ~Listener()
    {
    
    }

    //
    // Operators
    //
    
    // Assigns the properties of another object to this one.
    // @rhs The parameter passed to the assignment.
    Listener& operator=(const Listener& rhs)
    {
      callback = rhs.callback;
      listenerId = rhs.listenerId;
      
      return *this;
    }
    
    // Compares the listeners for equality.
    // @rhs The parameter passed to the assignment.
    bool operator==(const Listener& param)
    {
      return listenerId == param.listenerId;
    }
    
    // Executes the callback linked to the event.
    // @param The parameter passed to the callback.
    void operator()(TParams... params) const
    {
      callback(params...);
    }

  private:

    //
    // Private Variables
    //
    
    // Stores the callback which is called when the
    // associated event fires.
    std::function<MethodType> callback;
    
    // Stores a value which uniquely identifies
    // a listener.
    int listenerId;
};

#endif
