/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

#include <cpp_util/log/log_object.h>

// Project Includes
#include <cpp_util/log/logger.h>

// External Includes
#include <cstddef>
#include <string.h>

//
// Constructors
//

//
// Constructors
//

// Creates a new instance of the LogObject class.
// @param logLevel The log level.
// @param base The base message.
LogObject::LogObject(LogLevel logLevel, std::string base)
: logLevel{ logLevel }, message(base), writeToLog{ true }
{

}

// Moves to this instance of the LogObject class.
// @param other The other object.
LogObject::LogObject(LogObject&& other)
: logLevel{ other.logLevel }, message(other.message), writeToLog{ true }
{
  other.writeToLog = false;
}

// Destroys this instance of the LogObject class. 
LogObject::~LogObject()
{
  if (writeToLog)
  {
    Logger::Log(logLevel, message);
  }
}
