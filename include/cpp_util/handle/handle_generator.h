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

	std::vector<int> handles;
    int last_id;
};

template <typename THandle>
HandleGenerator<THandle>::HandleGenerator()
{
    handles.push_back(-1);
    last_id = 0;
}

template <typename THandle>
THandle HandleGenerator<THandle>::create()
{
    int next_index = handles[0];

    if (next_index == -1)
    {
        THandle handle;
		handle.set_index(handles.size());
		handle.set_id(last_id);
		handles.push_back(last_id);

		++last_id;

		return handle;
    }
    else
    {
        int index = handles[0];
        handles[0] = handles[index];

        handles[index] = last_id;
        
		THandle handle;
		handle.set_index(index);
		handle.set_id(last_id);

		++last_id;

		return handle;
    }
}

template <typename THandle>
bool is_valid(THandle handle)
{
    return handles[handle.get_index()] == handle.get_id();
}

template <typename THandle>
void HandleGenerator<THandle>::remove(THandle handle)
{
    int index = handle.get_index();
	handles[index] = handles[0];
    handles[0] = index;
}

#endif
