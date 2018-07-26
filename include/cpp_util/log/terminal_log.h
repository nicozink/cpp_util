/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

#ifndef TERMINALLOG_H
#define TERMINALLOG_H

// Project Includes
#include <cpp_util/log/log_writer.h>

// External Includes

// A class which outputs log messages to a file.
class TerminalLog : public ILogWriter
{
  public:
    
    /*
     * Constructors
     */
    
    // Creates a new instance of the "TerminalLog" class.
    // @param bitMask Specifies the log level to listen on.
    TerminalLog(LogLevel bitMask);
    
    // Destroys this instance of the "TerminalLog" class.
    ~TerminalLog();
    
    /*
     * Public Override Methods
     */
    
    // Writes the message to the appropriate output medium.
    // @param message The log message.
    void Log(std::string message);
};

#endif
