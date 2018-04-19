/*
 * Copyright (c) Nico Zink
 * https://github.com/nicozink/cpp_util.git
 * Licensed under GNU General Public License 3.0 or later. 
 */

#pragma once

#ifndef cpp_util_types_singleton_h
#define cpp_util_types_singleton_h

// Stores a singleton class definition.
template <typename T>
class Singleton
{
public:

	//
	// Constructors
	//

	Singleton() = default;
	Singleton(const Singleton&) = delete;

	//
	// Public Static Methods
	//

	// Returns the singleton instance as a reference.
	static T& GetInstance()
	{
		static T& instance = T();
		return instance;
	}
};

#endif
