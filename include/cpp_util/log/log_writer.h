/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

#ifndef ILOGWRITER_H
#define ILOGWRITER_H

// Local Includes
#include <cpp_util/log/log_level.h>

// Project Includes

// External Includes
#include <string>

// A virtual interface which provides a
// framework for listeners to the logging
// system.
class ILogWriter
{
  public:
    
    /*
     * Constructors
     */
    
    // Initialises a new instance of the "ILogWriter" class.
    // @param bitMask The bit mask.
    ILogWriter(LogLevel bitMask);

    /*
     * Public Virtual Methods
     */
    
    // Writes the message to the appropriate output medium.
    // @param message The log message.
    virtual void Log(std::string message) = 0;
    
    /*
     * Public Inline Methods
     */
    
    // Returns the log writer's bit mask.
    // @returns The bit mask.
    inline LogLevel BitMask()
    {
      return bitMask;
    }
    
  private:
    
    /*
     * Private Variables
     */
    
    // Stores the log level bit mask.
    LogLevel bitMask;
};

#endif
