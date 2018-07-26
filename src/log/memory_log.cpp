/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

#include <cpp_util/log/memory_log.h>

// Local Includes
#include <cpp_util/log/logger.h>

// Project Includes

// External Includes
#include <cstddef>
#include <string.h>

/*
 * Constructors
 */

// Creates a new instance of the "MemoryLog" class.
// @param bitMask The log level bit mask.
// @param maximumHistory The maximum log history to
// preserve.
MemoryLog::MemoryLog(LogLevel bitMask, int maximumHistory)
  : ILogWriter(bitMask)
{
  logHistory = new std::string[maximumHistory];
  
  for (int i = 0; i < maximumHistory; i++)
  {
    logHistory[i] = std::string();
  }
  
  this->maximumHistory = maximumHistory;
  
  count = 0;
  currentPosition = 0;
}

// Creates a new instance of the "MemoryLog" class.
// @param filePath The path to the file.
MemoryLog::~MemoryLog()
{
  delete[] logHistory;
}

/*
 * Operators
 */

// Returns the log message at the defined index.
// @param index The index.
std::string MemoryLog::operator[](const int index)
{
  int bufferedCount = count - First();
  int startPosition = (currentPosition - bufferedCount + maximumHistory) % maximumHistory;
  
  int relativeIndex = index - First();
  
  std::string message = logHistory[(startPosition + relativeIndex) % maximumHistory];

  return message;
}

/*
 * Public Override Methods
 */

// Writes the message to the appropriate output medium.
// @param message The log message.
void MemoryLog::Log(std::string message)
{
  logHistory[currentPosition] = message;
  
  count++;
  
  currentPosition = (currentPosition + 1) % maximumHistory;
}

/*
 * Public Methods
 */

// Gets the number of items stored in the log history.
// @returns The count.
int MemoryLog::Count()
{
  return count;
}

// Gets the index of the first log message.
// @returns The index.
int MemoryLog::First()
{
  if (count < maximumHistory)
  {
    return 0;
  }
  else
  {
    return count - maximumHistory;
  }
}
