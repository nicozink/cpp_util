/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

#ifndef FILELOG_H
#define FILELOG_H

// Project Includes
#include <cpp_util/log/log_writer.h>

// External Includes
#include <stdio.h>
#include <string>

// A class which outputs log messages to a file.
class FileLog : public ILogWriter
{
  public:
    
    /*
     * Constructors
     */
    
    // Creates a new instance of the "FileLog" class.
    // @param bitMask Specifies the log level to listen on.
    // @param filePath The path to the file.
    FileLog(LogLevel bitMask, std::string filePath);
    
    // Destroys this instance of the "FileLog" class. 
    ~FileLog();
    
    /*
     * Public Override Methods
     */
    
    // Writes the message to the appropriate output medium.
    // @param message The log message.
    void Log(std::string message);
    
  private:
    
    // Stores a reference to the file.
    FILE* file;
};

#endif
