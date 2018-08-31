// Copyright (c) Nico Zink
// https://github.com/nicozink/darkentity.git
// Licensed under GNU General Public License 3.0 or later.

#pragma once

#ifndef cpp_util_types_variant_type_helper_h
#define cpp_util_types_variant_type_helper_h

// Local Includes
#include "variant_type.h"

template <typename T>
class VariantTypeHelper
{
public:
	static VariantType Create(T& value)
	{
		VariantType variant_type;
		variant_type.set<T>(value);
		
		return variant_type;
	}

	static VariantType Create(T&& value)
	{
		VariantType variant_type;
		variant_type.set<T>(std::move(value));

		return variant_type;
	}
};

template <typename T>
class VariantTypeHelper<T*>
{
public:
	static VariantType Create(T* value)
	{
		VariantType variant_type;
		variant_type.set<T>(value);

		return variant_type;
	}
};

template <typename T>
class VariantTypeHelper<T&>
{
public:
	static VariantType Create(T& value)
	{
		VariantType variant_type;
		variant_type.set<T>(&value);

		return variant_type;
	}
};

template <typename T>
class VariantTypeHelper<T&&>
{
public:
	static VariantType Create(T&& value)
	{
		VariantType variant_type;
		variant_type.set<T>(std::move(value));

		return variant_type;
	}
};

#endif
