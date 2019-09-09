/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

#ifndef LOGGER_H
#define LOGGER_H

// Local Includes
#include <cpp_util/handle/handle.h>
#include <cpp_util/handle/handle_generator.h>
#include <cpp_util/log/log_writer.h>
#include <cpp_util/log/logger_base.h>
#include <cpp_util/log/log_level.h>
#include <cpp_util/log/log_object.h>
#include <cpp_util/log/log_type.h>

// Project Includes
#include <cpp_util/types/bit_mask.h>

// External Includes
#include <memory>
#include <stdarg.h>
#include <stdio.h>
#include <vector>

struct LogWriterHandle : public Handle
{

};

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
  static LogWriterHandle AddListener(std::unique_ptr<ILogWriter>&& listener);
    
  // Removes the listeners from the logger.
  static void RemoveListener(LogWriterHandle handle);
  
  //
  // Public Static Methods
  //

  // Enables the provided log channel with the options specified.
  // @param logType The log type.
  // @param logLevel The log level.
  static void Enable(LogType logType, LogLevel logLevel);

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

  // Writes the log message to the registered listeners.
  // @param logLevel The log level.
  // @param format The log message.
  static void Log(LogLevel logLevel, std::string message);

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
  static std::vector<std::unique_ptr<ILogWriter>> listeners;

  static HandleGenerator<LogWriterHandle> log_writer_generator;
};

#endif
