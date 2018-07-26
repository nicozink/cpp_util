/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

#include <cpp_util/log/log_writer.h>

// Local Includes

// Project Includes

// External Includes

/*
 * Constructors
 */

// Initialises a new instance of the "ILogWriter" class.
// @param bitMask The bit mask.
ILogWriter::ILogWriter(LogLevel bitMask)
{
  this->bitMask = bitMask;
}
