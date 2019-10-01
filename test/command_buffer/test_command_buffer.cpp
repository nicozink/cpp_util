// Copyright (c) Nico Zink
// https://github.com/nicozink/darkentity.git
// Licensed under GNU General Public License 3.0 or later.

// Local Includes

// Project Includes
#include <cpp_util/command_buffer/command_buffer.h>
#include <unittest/test.h>

// System Includes
#include <functional>

TEST(CommandBuffer, TestCreate)
{
	CommandBuffer<int> command_buffer;

	ASSERT_EQ(command_buffer.has_next(), false);
}

TEST(CommandBuffer, TestAdd)
{
	CommandBuffer<int> command_buffer;

	int& value = command_buffer.add<int>(100);
	value = 200;

	auto command = command_buffer.get_next<int>();

	ASSERT_EQ(command.first, 100);
	ASSERT_EQ(command.second, 200);
}

TEST(CommandBuffer, TestAddExecute)
{
	CommandBuffer<int> command_buffer;

	int val1 = 0;

	auto& func1 = command_buffer.add<std::function<void()>>(1);
	func1 = [&val1]() {
		val1 = 100;
	};

	int val2 = 0;

	auto& func2 = command_buffer.add<std::function<void()>>(2);
	func2 = [&val2]() {
		val2 = 200;
	};

	auto command1 = command_buffer.get_next<std::function<void()>>();
	command1.second();

	auto command2 = command_buffer.get_next<std::function<void()>>();
	command2.second();

	ASSERT_EQ(command1.first, 1);
	ASSERT_EQ(command2.first, 2);

	ASSERT_EQ(val1, 100);
	ASSERT_EQ(val2, 200);
}
