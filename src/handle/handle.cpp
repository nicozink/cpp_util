// Copyright (c) Nico Zink
// https://github.com/nicozink/darkentity.git
// Licensed under GNU General Public License 3.0 or later.

#include <cpp_util/handle/handle.h>

Handle::Handle()
	: id{ -1 }, index{ -1 }
{

}

// Returns the id of the handle.
int Handle::get_id()
{
	return id;
}

// Returns the index of the handle.
int Handle::get_index()
{
	return index;
}

bool Handle::is_valid()
{
	return id != -1;
}

// Sets the id of the handle.
void Handle::set_id(int id)
{
	this->id = id;
}

// Sets the index of the handle.
void Handle::set_index(int index)
{
	this->index = index;
}
