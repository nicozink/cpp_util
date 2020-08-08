/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

#ifndef EVENT_H
#define EVENT_H

// Local Includes
#include "listener.h"

// Project Includes

// External Includes
#include <algorithm>
#include <vector>

// Stores a class which handles passing of events.
template <typename... TParams>
class Event
{
public:
    
	//
	// Type Definitions
	//
    
	// Stores the type used as the callback delegate.
	template <typename TInstanceType>
	using TMethodType = void (TInstanceType::*)(TParams...);
    
	//
	// Constructors
	//
    
	// Creates a new instance of the Event class.
	Event()
	{
		listenerIdCounter = 0;
	}

	// Destroys this instance of the Event class.
	virtual ~Event()
	{
    
	}
    
	//
	// Public Methods
	//
    
	// Fires the event.
	// @param param The parameter passed to the listeners.
	void Fire(TParams... params)
	{
		for (auto& listener : listeners)
		{
			listener(params...);
		}
	}
    
	// Removes the listener from the event.
	// @param listener The listener.
	void Remove(Listener<TParams...> listener)
	{
		// Find the iterator to be removed.
		auto toRemove = std::remove(listeners.begin(), listeners.end(), listener);

		// Erase it.
		listeners.erase(toRemove, listeners.end());
	}
    
	// Adds the listener to the event.
	// @param instance The instance listening for the event.
	// @param callback The callback which is called when the event
	// is fired.
	// @returns The listener.
	template <typename TInstanceType>
	Listener<TParams...> Subscribe(TInstanceType& instance, TMethodType<TInstanceType> callback)
	{
		std::function<void(TParams...)> callback_function = [&instance, callback](TParams... params) {
			(instance.*callback)(params...);
		};

		Listener<TParams...> listener(++listenerIdCounter, callback_function);
       
		listeners.push_back(listener);
      
		return listener;
	}
    
private:
  
	//
	// Private Variables
	//
    
	// Stores a counter which is used to generate unique Ids
	// for the listeners linked to this event.
	int listenerIdCounter;
    
	// Stores the listeners associated with the event.
	std::vector<Listener<TParams...> > listeners;
};

#endif
