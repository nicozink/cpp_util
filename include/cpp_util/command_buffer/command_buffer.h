// Copyright (c) Nico Zink
// https://github.com/nicozink/darkentity.git
// Licensed under GNU General Public License 3.0 or later.

#pragma once

#ifndef cpp_util_command_buffer_h
#define cpp_util_command_buffer_h

// System Includes
#include <any>
#include <stdexcept>
#include <vector>

template <typename TCommandKey>
class CommandBuffer
{
public:

    CommandBuffer();

    template <typename TCommand>
    TCommand& add(TCommandKey key);

    template <typename TCommand>
    std::pair<TCommandKey, TCommand&> get_next();

    bool has_next();

    TCommandKey peek();

private:

	std::vector<TCommandKey> m_commands;
    int m_current_command;
	std::vector<std::any> m_data;
};

template <typename TCommandKey>
CommandBuffer<TCommandKey>::CommandBuffer() :
    m_current_command{ 0 }
{

}

template <typename TCommandKey>
template <typename TCommand>
TCommand& CommandBuffer<TCommandKey>::add(TCommandKey key)
{
	auto command_data = std::make_any<TCommand>();

	m_commands.push_back(key);
	m_data.push_back(std::move(command_data));

	return *std::any_cast<TCommand>(&m_data.back());
}

template <typename TCommandKey>
template <typename TCommand>
std::pair<TCommandKey, TCommand&> CommandBuffer<TCommandKey>::get_next()
{
	if (!has_next())
	{
		throw std::runtime_error("Attempt to access empty command");
	}

	auto key = m_commands[m_current_command];
	auto& data = *std::any_cast<TCommand>(&m_data[m_current_command]);
	
	++m_current_command;

	return { key, data };
}

template <typename TCommandKey>
bool CommandBuffer<TCommandKey>::has_next()
{
	return (m_current_command < m_commands.size());
}

template <typename TCommandKey>
TCommandKey CommandBuffer<TCommandKey>::peek()
{
    if (!has_next())
    {
        throw std::runtime_error("Attempt to access empty command");
    }

    return m_commands[m_current_command];
}

#endif
