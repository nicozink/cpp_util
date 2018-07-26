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
    
  // Writes the message to the log.
  // @param format The format.
  // @param ... The log data.
  LogObject operator()(std::string format, ...)
  {
    const int LOG_BUFFER_LENGTH = 512;

    char cmessage[LOG_BUFFER_LENGTH];

    va_list args;

    va_start(args, format);

    vsnprintf(cmessage, LOG_BUFFER_LENGTH, format.c_str(), args);

    va_end(args);

    return LogObject(listeners, logLevel, cmessage);
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
