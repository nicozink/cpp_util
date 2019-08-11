// Copyright (c) Nico Zink
// https://github.com/nicozink/darkentity.git
// Licensed under GNU General Public License 3.0 or later.

#include <cpp_util/handle/handle.h>

Handle::Handle()
	: m_id(-1), m_index(-1)
{

}

// Returns the id of the handle.
int Handle::get_id() const
{
	return m_id;
}

// Returns the index of the handle.
int Handle::get_index() const
{
	return m_index;
}

bool Handle::is_valid() const
{
	return m_id != -1;
}

// Sets the id of the handle.
void Handle::set_id(int id)
{
	m_id = id;
}

// Sets the index of the handle.
void Handle::set_index(int index)
{
	m_index = index;
}
