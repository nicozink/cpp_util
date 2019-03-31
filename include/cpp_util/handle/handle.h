// Copyright (c) Nico Zink
// https://github.com/nicozink/darkentity.git
// Licensed under GNU General Public License 3.0 or later.

#pragma once

#ifndef cpp_util_handle_handle_h
#define cpp_util_handle_handle_h

class Handle
{
public:

	Handle();

    // Returns the id of the handle.
    int get_id() const;

    // Returns the index of the handle.
    int get_index() const;

	bool is_valid() const;

	// Sets the id of the handle.
	void set_id(int id);

	// Sets the index of the handle.
	void set_index(int index);

private:

    int index;

    int id;
};

#endif
