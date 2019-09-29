// Copyright (c) Nico Zink
// https://github.com/nicozink/darkentity.git
// Licensed under GNU General Public License 3.0 or later.

#pragma once

#ifndef cpp_util_handle_handle_h
#define cpp_util_handle_handle_h

// System Includes
#include <cstdint>

class Handle
{
public:

	Handle();

	Handle(int32_t handle);

	// Returns the id of the handle.
	int32_t as_32() const;

    // Returns the id of the handle.
    int16_t get_id() const;

    // Returns the index of the handle.
	int16_t get_index() const;

	bool is_valid() const;

	// Sets the id of the handle.
	void set_id(int16_t id);

	// Sets the index of the handle.
	void set_index(int16_t index);

private:

	int16_t m_id;
    
	int16_t m_index;
};

#endif
