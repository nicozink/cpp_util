/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

#ifndef LOGOBJECT_H
#define LOGOBJECT_H

// Local Includes
#include <cpp_util/log/log_writer.h>

// Project Includes

// External Includes
#include <cstdarg>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>

// A class which captures output and sends it to connected listeners.
class LogObject
{
  public:
    
    //
    // Constructors
    //
    
    // Creates a new instance of the LogObject class.
    // @param listeners The defined listeners.
    // @param logLevel The log level.
    // @param base The base message.
    LogObject(LogLevel logLevel, std::string base);
    
    // Moves to this instance of the LogObject class.
    // @param other The other object.
    LogObject(LogObject& other) = delete;

    // Moves to this instance of the LogObject class.
    // @param other The other object.
    LogObject(LogObject&& other);

    // Destroys this instance of the LogObject class. 
    ~LogObject();
    
    //
    // Operators
    //
    
    // Writes the object to the log.
    // @param obj The object.
    template<typename T>
    LogObject& operator<< (T obj)
    {
      std::stringstream stream;

      stream << message << obj;

      message = stream.str();

      return *this;
    }

  private:
    
    //
    // Private Variables
    //

    // Stores the log level.
    LogLevel logLevel;
    
    // Stores the message.
    std::string message;

    // Stores a flag which states whether to write to the
    // log on deletion.
    bool writeToLog;
};

#endif
