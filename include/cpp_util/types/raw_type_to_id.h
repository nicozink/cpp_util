/*
Copyright (c) Nico Zink
All rights reserved.
*/

#pragma once

// Local includes
#include "type_to_id.h"

template <typename T>
class RawTypeToId
{
public:

	static TypeToId::type_id get_id()
	{
		return TypeToId::get_id<T>();
	}
};

template <typename T>
class RawTypeToId<T*>
{
public:

	static TypeToId::type_id get_id()
	{
		return TypeToId::get_id<T>();
	}
};

template <typename T>
class RawTypeToId<T&>
{
public:

	static TypeToId::type_id get_id()
	{
		return TypeToId::get_id<T>();
	}
};