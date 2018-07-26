/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

#ifndef LOGGER_H
#define LOGGER_H

// Local Includes
#include <cpp_util/log/log_writer.h>
#include <cpp_util/log/logger_base.h>
#include <cpp_util/log/log_level.h>
#include <cpp_util/log/log_object.h>

// Project Includes
#include <cpp_util/types/bit_mask.h>

// External Includes
#include <stdarg.h>
#include <stdio.h>
#include <vector>

// A logging class which accepts log messages
// and broadcasts them to registered listenenrs.
class Logger
{
public:
    
  //
  // Public Static Methods
  //
    
  // Adds the listener to the logger.
  // @param listener The listener.
  static void AddListener(ILogWriter& listener);
    
  // Removes the listener from the logger.
  // @param listener The listener.
  static void RemoveListener(ILogWriter& listener);
    
  //
  // Public Static Methods
  //

  // Writes the log message to the registered listeners.
  // @param logLevel The log level.
  // @param format The log message.
  static LoggerBase& Log(LogLevel logLevel)
  {
    switch (logLevel)
    {
    case LogLevel::Debug:
      return Debug;
    case LogLevel::Error:
      return Error;
    case LogLevel::Info:
        return Info;
    case LogLevel::Warning:
      return Warning;
    default:
      return Error;
    }
  }

  //
  // Public Static Variables
  //
    
  // Stores the debug logging object.
  static LoggerBase Debug;

  // Stores the error logging object.
  static LoggerBase Error;

  // Stores the info logging object.
  static LoggerBase Info;

  // Stores the warning logging object.
  static LoggerBase Warning;
    
private:
    
  //
  // Private Static Variables
  //
    
  // Stores the available listeners.
  static std::vector<ILogWriter*> listeners;
};

#endif
