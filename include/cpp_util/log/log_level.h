/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

#ifndef LOGLEVEL_H
#define LOGLEVEL_H

// Local Includes

// Project Includes

// External Includes

/*
 * Contains the log level types.
 */
enum class LogLevel : int
{
  Debug = (1 << 1),
  Info = (1 << 2),
  Warning = (1 << 3),
  Error = (1 << 4),
};

//
// Bitmask Operations
//

inline LogLevel operator&(LogLevel x, LogLevel y)
{
  return static_cast<LogLevel>(static_cast<int>(x)& static_cast<int>(y));
}

inline LogLevel operator|(LogLevel x, LogLevel y)
{
  return static_cast<LogLevel> (static_cast<int>(x) | static_cast<int>(y));
}

#endif
