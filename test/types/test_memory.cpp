/*
Copyright (c) Nico Zink
All rights reserved.
*/

// Local Includes

// Project Includes
#include <cpp_util/types/memory.h>
#include <unittest/test.h>

// External Includes

TEST(Memory, TestSimpleInt)
{
	int i = 0;

	Memory m = Memory::Create(i);

	ASSERT(m.ptr() == &i);
	ASSERT(m.size() == sizeof(i));
}
