/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

#include <cpp_util/log/logger.h>

// Project Includes
#include <cpp_util/log/terminal_log.h>

// External Includes
#include <algorithm>

namespace
{
	std::vector<std::unique_ptr<ILogWriter>> GetDefaultLogs(HandleGenerator<LogWriterHandle>& handle_generator)
	{
		handle_generator.create();

		std::vector<std::unique_ptr<ILogWriter>> result;

		result.push_back(std::make_unique<TerminalLog>(LogLevel::Info));

		return result;
	}
	
}

/*
 * Public Static Methods
 */

// Searches for the string as a word, separated by a space
// from the rest of the text.
// @param strList A space-separated list of words.
// @param str The string to search for.
LogWriterHandle Logger::AddListener(std::unique_ptr<ILogWriter>&& listener)
{
  auto handle = log_writer_generator.create();
  listeners.insert(listeners.begin() + handle.get_index(), std::move(listener));

  return handle;
}

// Writes the log message to the registered listeners.
// @param logLevel The log level.
// @param format The log message.
void Logger::Enable(LogType logType, LogLevel logLevel)
{
	auto& listener = listeners[(int)logType];
	
	listener->set_enabled(true);
	listener->set_bit_mask(logLevel);
}

// Writes the log message to the registered listeners.
// @param logLevel The log level.
// @param format The log message.
void Logger::Log(LogLevel logLevel, std::string message)
{
	for (auto it = listeners.begin(); it != listeners.end(); ++it)
	{
		if ((*it)->get_enabled() && BitMask::IsTrue((*it)->get_bit_mask() & logLevel))
		{
			(*it)->Log(message);
		}
	}
}

// Removes the listener from the logger.
// @param listener The listener.
void Logger::RemoveListener(LogWriterHandle handle)
{
  listeners.erase(listeners.begin() + handle.get_index());

  log_writer_generator.remove(handle);
}

//
// Public Static Variables
//

// Stores the debug logging object.
LoggerBase Logger::Debug{ LogLevel::Debug };

// Stores the error logging object.
LoggerBase Logger::Error{ LogLevel::Error };

// Stores the info logging object.
LoggerBase Logger::Info{ LogLevel::Info };

// Stores the warning logging object.
LoggerBase Logger::Warning{ LogLevel::Warning };

/*
 * Private Static Variables
 */

HandleGenerator<LogWriterHandle> Logger::log_writer_generator;

// Stores the available listeners.
std::vector<std::unique_ptr<ILogWriter>> Logger::listeners = std::move(GetDefaultLogs(log_writer_generator));