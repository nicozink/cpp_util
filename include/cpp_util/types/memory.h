/*
Copyright (c) Nico Zink
All rights reserved.
*/

#pragma once

#ifndef cpp_util_types_memory_h
#define cpp_util_types_memory_h

// Local Includes

// Project Includes

// External Includes
#include <cstddef>
#include <functional>
#include <memory>

class Memory
{
public:

	typedef std::function<void(void*)> deleter;
	typedef std::unique_ptr<void, deleter> deletable_pointer;

	template <typename T>
	static Memory Create(T* ptr);

	template <typename T>
	static Memory Create(T& ptr);

	Memory();

	Memory(void* ptr);

	Memory(void* ptr, std::size_t size);

	Memory(void* ptr, std::size_t size, deleter deleter);

	std::size_t size();

	void* ptr();

private:

	deletable_pointer m_ptr;

	std::size_t m_size;
};

template <typename T>
Memory Memory::Create(T* ptr)
{
	return Memory(ptr, sizeof(*ptr));
}

template <typename T>
Memory Memory::Create(T& ptr)
{
	return Memory(&ptr, sizeof(ptr));
}

#endif
