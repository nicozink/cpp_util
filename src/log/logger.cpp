/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

#include <cpp_util/log/logger.h>

// Local Includes

// Project Includes

// External Includes
#include <algorithm>

/*
 * Public Static Methods
 */

// Searches for the string as a word, separated by a space
// from the rest of the text.
// @param strList A space-separated list of words.
// @param str The string to search for.
void Logger::AddListener(ILogWriter& listener)
{
  listeners.push_back(&listener);
}

// Removes the listener from the logger.
// @param listener The listener.
void Logger::RemoveListener(ILogWriter& listener)
{
  auto position = std::find(listeners.begin(), listeners.end(), &listener);

  if (position != listeners.end())
  {
    listeners.erase(position);
  }
}

//
// Public Static Variables
//

// Stores the debug logging object.
LoggerBase Logger::Debug{ Logger::listeners, LogLevel::Debug };

// Stores the error logging object.
LoggerBase Logger::Error{ Logger::listeners, LogLevel::Error };

// Stores the info logging object.
LoggerBase Logger::Info{ Logger::listeners, LogLevel::Info };

// Stores the warning logging object.
LoggerBase Logger::Warning{ Logger::listeners, LogLevel::Warning };

/*
 * Private Static Variables
 */

// Stores the available listeners.
std::vector<ILogWriter*> Logger::listeners;
