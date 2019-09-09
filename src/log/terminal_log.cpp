/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

#include <cpp_util/log/terminal_log.h>

// Local Includes

// Project Includes

// External Includes
#include <stdio.h>

/*
 * Constructors
 */

// Creates a new instance of the "TerminalLog" class.
// @param bitMask Specifies the log level to listen on.
// @param filePath The path to the file.
TerminalLog::TerminalLog(LogLevel bitMask)
  : ILogWriter(bitMask, false)
{
  
}

// Creates a new instance of the "TerminalLog" class.
// @param filePath The path to the file.
TerminalLog::~TerminalLog()
{
  
}

// Writes the message to the appropriate output medium.
// @param message The log message.
void TerminalLog::Log(std::string message)
{
  fprintf(stdout, "%s\n", message.c_str());
}
