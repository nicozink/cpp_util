// Copyright (c) Nico Zink
// https://github.com/nicozink/darkentity.git
// Licensed under GNU General Public License 3.0 or later.

#pragma once

#ifndef cpp_util_types_variant_type_h
#define cpp_util_types_variant_type_h

// System Includes
#include <memory>
#include <type_traits>

namespace
{
	template <typename T>
	class VariantStorage
	{
	public:
		static T Get(const std::shared_ptr<void>& variant_item)
		{
			return *std::static_pointer_cast<T>(variant_item);
		}
	};

	template <typename T>
	class VariantStorage<T*>
	{
	public:
		static T* Get(const std::shared_ptr<void>& variant_item)
		{
			return std::static_pointer_cast<T>(variant_item).get();
		}
	};

	template <typename T>
	class VariantStorage<T&>
	{
	public:
		static T& Get(const std::shared_ptr<void>& variant_item)
		{
			return *std::static_pointer_cast<T>(variant_item);
		}
	};

	template <typename T>
	class VariantStorage<std::shared_ptr<T>>
	{
	public:
		static std::shared_ptr<T> Get(const std::shared_ptr<void>& variant_item)
		{
			return std::static_pointer_cast<T>(variant_item);
		}
	};
}

class VariantType
{
public:

	// Static Variables

	static VariantType Null;

	// Constructors

	VariantType();

	~VariantType();

	// Operators

	bool operator ==(const VariantType &b) const;
	bool operator !=(const VariantType &b) const;

	// Public Methods

	template <typename T>
	T get() const;

	template <typename T>
	void set(T* item);

	template <typename T>
	void set(T& item);

	template <typename T>
	void set(T&& item);

	template <typename T>
	void set(std::shared_ptr<T> item);

private:

	// Private Static Variables

	static void* null_ptr;

	// Private Variables

	std::shared_ptr<void> variant_ptr;
};

template <typename T>
T VariantType::get() const
{
	return VariantStorage<T>::Get(variant_ptr);
}

template <typename T>
void VariantType::set(T* item)
{
	variant_ptr = std::shared_ptr<void>((void*)item, [](void*) { });
}

template <typename T>
void VariantType::set(T& item)
{
    typename std::remove_reference<T>::type* item_ptr = new T(item);

	variant_ptr = std::shared_ptr<void>((void*)item_ptr, [](void* p) {
		delete static_cast<T*>(p);
	});
}

template <typename T>
void VariantType::set(T&& item)
{
	T* item_ptr = new T(std::move(item));

	variant_ptr = std::shared_ptr<void>((void*)item_ptr, [](void* p) {
		delete static_cast<T*>(p);
	});
}

template <typename T>
void VariantType::set(std::shared_ptr<T> item)
{
	variant_ptr = item;
}

#endif
