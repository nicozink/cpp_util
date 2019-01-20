// Copyright (c) Nico Zink
// https://github.com/nicozink/darkentity.git
// Licensed under GNU General Public License 3.0 or later.

#pragma once

#ifndef cpp_util_event_observable_h
#define cpp_util_event_observable_h

// Local Includes
#include "listener.h"

// Project Includes

// External Includes
#include <algorithm>
#include <boost/signals2.hpp>
#include <vector>

template<typename TSignal>
class Observable
{
public:
    
	void add(std::function<TSignal> func);

	template <typename... Args>
	void fire(Args... args);

private:

	boost::signals2::signal<TSignal> signal;
};

template<typename TSignal>
void Observable<TSignal>::add(std::function<TSignal> func)
{
	signal.connect(func);
}

template<typename TSignal>
template <typename... Args>
void Observable<TSignal>::fire(Args... args)
{
	signal(std::forward<Args>(args)...);
}

#endif
