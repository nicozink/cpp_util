/*
 * Copyright (c) Nico Zink
 * https://github.com/nicozink/cpp_util.git
 * Licensed under GNU General Public License 3.0 or later. 
 */

#pragma once

#ifndef cpp_util_debug_assert_h
#define cpp_util_debug_assert_h

// Local Includes

// Project Includes

// External Includes
#include <cassert>

// Macro Definitions

// Asserts the condition, and prints the error otherwise.
#define D4_ASSERT(condition, message) \
  assert(condition && message);
#endif
