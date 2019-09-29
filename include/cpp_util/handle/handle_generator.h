// Copyright (c) Nico Zink
// https://github.com/nicozink/darkentity.git
// Licensed under GNU General Public License 3.0 or later.

#pragma once

#ifndef cpp_util_handle_handle_generator_h
#define cpp_util_handle_handle_generator_h

// System Includes
#include <vector>

template <typename THandle>
class HandleGenerator
{
public:

    HandleGenerator();

	THandle create();

    bool is_valid(THandle handle);

	void remove(THandle handle);

private:

	std::vector<int16_t> handles;
	int16_t next_id;
	int16_t next_index;
};

template <typename THandle>
HandleGenerator<THandle>::HandleGenerator()
{
    next_index = -1;
	next_id = 0;
}

template <typename THandle>
THandle HandleGenerator<THandle>::create()
{
	if (next_index == -1)
    {
        THandle handle;
		handle.set_index((int16_t)handles.size());
		handle.set_id(next_id);
		handles.push_back(next_id);

		++next_id;

		return handle;
    }
    else
    {
		int16_t index = next_index;
		next_index = handles[index];

        handles[index] = next_id;
        
		THandle handle;
		handle.set_index(index);
		handle.set_id(next_id);

		++next_id;

		return handle;
    }
}

template <typename THandle>
bool HandleGenerator<THandle>::is_valid(THandle handle)
{
    return handles[handle.get_index()] == handle.get_id();
}

template <typename THandle>
void HandleGenerator<THandle>::remove(THandle handle)
{
	int16_t index = handle.get_index();
	handles[index] = next_index;
	next_index = index;
}

#endif
