/*
Copyright (c) Nico Zink
All rights reserved.
*/

#include <cpp_util/types/memory.h>

// Local Includes

// Project Includes

// External Includes

Memory::Memory()
{
	m_ptr = Memory::deletable_pointer(nullptr, [](void*) {});
	m_size = 0;
}

Memory::Memory(void* ptr, std::size_t size)
{
	m_ptr = Memory::deletable_pointer(ptr, [](void*) { });
	m_size = size;
}

Memory::Memory(void* ptr, std::size_t size, Memory::deleter deleter)
{
	m_ptr = Memory::deletable_pointer(ptr, deleter);
	m_size = size;
}

Memory::Memory(Memory&& other) noexcept
{
	m_ptr = std::move(other.m_ptr);
	m_size = other.m_size;
}

Memory::~Memory()
{
	
}

std::size_t Memory::size()
{
	return m_size;
}

void* Memory::ptr()
{
	return m_ptr.get();
}
