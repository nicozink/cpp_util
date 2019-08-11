/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

#include <cpp_util/log/file_log.h>

// Project Includes
#include <cpp_util/log/logger.h>

// Project Includes

// External Includes

/*
 * Constructors
 */

// Creates a new instance of the "FileLog" class.
// @param bitMask Specifies the log level to listen on.
// @param filePath The path to the file.
FileLog::FileLog(LogLevel bitMask, std::string filePath) :
	ILogWriter(bitMask),
	m_file{ filePath }
{
	
}

// Creates a new instance of the "FileLog" class.
// @param filePath The path to the file.
FileLog::~FileLog()
{
	m_file.close();
}

// Writes the message to the appropriate output medium.
// @param message The log message.
void FileLog::Log(std::string message)
{
	m_file << message << std::endl;
}
