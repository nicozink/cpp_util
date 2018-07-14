/*
 * Copyright (c) Nico Zink
 * https://github.com/nicozink/cpp_util.git
 * Licensed under GNU General Public License 3.0 or later. 
 */

#pragma once

#ifndef cpp_util_types_automatic_singleton_h
#define cpp_util_types_automatic_singleton_h

// Stores a singleton class definition.
template <typename T>
class AutomaticSingleton
{
public:

	//
	// Constructors
	//

	AutomaticSingleton() = default;
	AutomaticSingleton(const AutomaticSingleton&) = delete;

	//
	// Public Static Methods
	//

	// Returns the singleton instance as a reference.
	static T& GetInstance()
	{
		static T instance;

		return instance;
	}
};

#endif
