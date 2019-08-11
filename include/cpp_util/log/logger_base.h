/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

#ifndef LOGGERBASE_H
#define LOGGERBASE_H

// Local Includes
#include <cpp_util/log/log_writer.h>
#include <cpp_util/log/log_object.h>

// Project Includes

// External Includes
#include <string>
#include <sstream>
#include <stdarg.h>
#include <vector>

// A class which initialises a new log entry when the streaming operator is
// called.
class LoggerBase
{
public:
    
  //
  // Constructors
  //
    
  // Creates a new instance of the LoggerBase class.
  // @param listeners The defined listeners.
  // @param logLevel The log level.
  LoggerBase(std::vector<ILogWriter*>& listeners, LogLevel logLevel);
    
  // Destroys this instance of the LoggerBase class. 
  ~LoggerBase();
    
  //
  // Operators
  //
    
  // Sends the log message to the input stream.
  // @param obj The log message object.
  // @returns The logging object.
  template<typename T>
  LogObject operator<< (T obj)
  {
    std::stringstream stream;
      
    stream << obj;

    return LogObject(listeners, logLevel, stream.str());
  }
  
private:
    
  //
  // Private Variables
  //

  // Stores the listeners which need to receive log messages.
  std::vector<ILogWriter*>& listeners;

  // Stores the log level.
  LogLevel logLevel;
};

#endif
