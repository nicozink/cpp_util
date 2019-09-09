/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

#include <cpp_util/log/logger_base.h>

// Project Includes
#include <cpp_util/log/logger.h>

// External Includes
#include <cstddef>
#include <string.h>

//
// Constructors
//

//
// Constructors
//

// Creates a new instance of the LoggerBase class.
// @param listeners The defined listeners.
// @param logLevel The log level.
LoggerBase::LoggerBase(LogLevel logLevel)
: logLevel{ logLevel }
{

}

// Destroys this instance of the LoggerBase class. 
LoggerBase::~LoggerBase()
{

}
