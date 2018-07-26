/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

#ifndef MEMORYLOG_H
#define MEMORYLOG_H

// Local Includes
#include <cpp_util/log/log_writer.h>

// Project Includes

// External Includes
#include <string>

// A class which outputs log messages to a file.
class MemoryLog : public ILogWriter
{
  public:
    
    /*
     * Constructors
     */
    
    // Creates a new instance of the "MemoryLog" class.
    // @param bitMask The log level bit mask.
    // @param maximumHistory The maximum log history to
    // preserve.
    MemoryLog(LogLevel bitMask, int maximumHistory);
    
    // Destroys this instance of the "MemoryLog" class. 
    ~MemoryLog();
    
    /*
     * Operators
     */
    
    // Returns the log message at the defined index.
    // @param index The index.
    std::string operator[] (const int index);
    
    /*
     * Public Override Methods
     */
    
    // Writes the message to the appropriate output medium.
    // @param message The log message.
    void Log(std::string message);
    
    /*
     * Public Methods
     */
    
    // Gets the number of items stored in the log history.
    // @returns The count.
    int Count();
    
    // Gets the index of the first log message.
    // @returns The index.
    int First();
    
  private:
    
    /*
     * Private Variables
     */
    
    // Stores the number of messages currently logged.
    int count;
    
    // Stores an index to the current insert position of the
    // next log message.
    int currentPosition;
    
    // Stores the log history.
    std::string* logHistory;
    
    // Stores the maximum log history to keep.
    int maximumHistory;
};

#endif
