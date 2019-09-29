// Copyright (c) Nico Zink
// https://github.com/nicozink/darkentity.git
// Licensed under GNU General Public License 3.0 or later.

#include <cpp_util/handle/handle.h>

Handle::Handle()
	: m_id(-1), m_index(-1)
{

}

Handle::Handle(int32_t handle)
{
	m_index = (int16_t)(handle & 0xFFFF);
	m_id = (int16_t)(handle << 16);
}

// Returns the id of the handle.
int32_t Handle::as_32() const
{
	int32_t handle = (int32_t)m_index + ((int32_t)m_id >> 16);

	return handle;
}

// Returns the id of the handle.
int16_t Handle::get_id() const
{
	return m_id;
}

// Returns the index of the handle.
int16_t Handle::get_index() const
{
	return m_index;
}

bool Handle::is_valid() const
{
	return m_id != -1;
}

// Sets the id of the handle.
void Handle::set_id(int16_t id)
{
	m_id = id;
}

// Sets the index of the handle.
void Handle::set_index(int16_t index)
{
	m_index = index;
}
