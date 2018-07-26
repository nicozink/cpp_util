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
// @param listeners The defined listeners.
// @param logLevel The log level.
// @param base The base message.
LogObject::LogObject(std::vector<ILogWriter*>& listeners, LogLevel logLevel, std::string base)
: listeners(listeners), logLevel{ logLevel }, message(base), writeToLog{ true }
{

}

// Moves to this instance of the LogObject class.
// @param other The other object.
LogObject::LogObject(LogObject&& other)
: listeners(other.listeners), logLevel{ other.logLevel }, message(other.message), writeToLog{ true }
{
  other.writeToLog = false;
}

// Destroys this instance of the LogObject class. 
LogObject::~LogObject()
{
  if (writeToLog)
  {
    for (auto it = listeners.begin();
      it != listeners.end(); ++it)
    {
      if (BitMask::IsTrue((*it)->BitMask() & logLevel))
      {
        (*it)->Log(message);
      }
    }
  }
}
