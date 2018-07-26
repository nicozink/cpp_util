/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

// Local Includes

// Project Includes
#include <cpp_util/log/logger.h>
#include <cpp_util/log/log_level.h>
#include <cpp_util/log/memory_log.h>

// External Includes
#include <unittest/test.h>
#include <cstring>

// Logs nothing, and checks to make sure that the log is empty.
TEST(Logger, NothingLogged)
{
  MemoryLog log(LogLevel::Info, 3);
  
  Logger::AddListener(log);
  Logger::RemoveListener(log);
  
  ASSERT_EQ(log.Count(), 0) << "Log elements present before log start.";
}

// Tests logging of a variety of objects using direct logging calls.
TEST(Logger, ItemsLoggedDirect)
{
  MemoryLog log(LogLevel::Debug | LogLevel::Info | LogLevel::Warning |
    LogLevel::Error, 3);
  
  Logger::AddListener(log);
  
  Logger::Log(LogLevel::Info) << "Hello World!";
  Logger::Log(LogLevel::Warning) << "Integer: " << 1;
  Logger::Log(LogLevel::Error) << "Double: " << 0.5;
  
  Logger::RemoveListener(log);
  
  ASSERT_EQ(log.Count(), 3) << "Some logging elements are missing.";
  
  bool result = log[0] == "Hello World!" &&
    log[1] == "Integer: 1" && log[2] == "Double: 0.5";
  
  ASSERT_TRUE(result) << "The log was generated incorrectly.";
}

// Tests logging of a variety of objects using normal logging calls.
TEST(Logger, ItemsLogged)
{
  MemoryLog log(LogLevel::Debug | LogLevel::Info | LogLevel::Warning |
    LogLevel::Error, 3);
  
  Logger::AddListener(log);
  
  Logger::Info << "Hello World!";
  Logger::Warning << "Integer: " << 1;
  Logger::Error << "Double: " << 0.5;
  
  Logger::RemoveListener(log);
  
  ASSERT_EQ(log.Count(), 3) << "Some logging elements are missing.";
  
  bool result = log[0] == "Hello World!" &&
    log[1] == "Integer: 1" && log[2] == "Double: 0.5";
  
  ASSERT_TRUE(result) << "The log was generated incorrectly.";
}

// Tests logging of a debug message.
TEST(Logger, DebugLogged)
{
  MemoryLog log(LogLevel::Debug, 3);
  
  Logger::AddListener(log);
  
  #ifdef DEBUG
  
  Logger::Debug << "Hello World!";
  
  #else
  
  Logger::Log(LogLevel::Debug) << "Hello World!";
  
  #endif
  
  Logger::RemoveListener(log);
  
  ASSERT_EQ(log.Count(), 1) << "The debug message is missing.";
  
  bool result = log[0] == "Hello World!";
  
  ASSERT_TRUE(result) << "The log was generated incorrectly.";
}

// Tests logging of a debug message without listening.
TEST(Logger, DebugLoggedWithoutListen)
{
  MemoryLog log(LogLevel::Info | LogLevel::Warning | LogLevel::Error, 3);
  
  Logger::AddListener(log);
  
  #ifdef DEBUG
  
  Logger::Debug << "Hello World!";
  
  #else
  
  Logger::Log(LogLevel::Debug) << "Hello World!";
  
  #endif
  
  Logger::RemoveListener(log);
  
  ASSERT_EQ(log.Count(), 0) << "Log elements present before log start.";
}

// Tests logging of an info message.
TEST(Logger, InfoLogged)
{
  MemoryLog log(LogLevel::Info, 3);
  
  Logger::AddListener(log);
  
  Logger::Info << "Hello World!";
  
  Logger::RemoveListener(log);
  
  ASSERT_EQ(log.Count(), 1) << "The debug message is missing.";
  
  bool result = log[0] == "Hello World!";
  
  ASSERT_TRUE(result) << "The log was generated incorrectly.";
}

// Tests logging of a info message without listening.
TEST(Logger, InfoLoggedWithoutListen)
{
  MemoryLog log(LogLevel::Debug | LogLevel::Warning | LogLevel::Error, 3);
  
  Logger::AddListener(log);
  
  Logger::Info << "Hello World!";
  
  Logger::RemoveListener(log);
  
  ASSERT_EQ(log.Count(), 0) << "Log elements present before log start.";
}

// Tests logging of a warning message.
TEST(Logger, WarningLogged)
{
  MemoryLog log(LogLevel::Warning, 3);
  
  Logger::AddListener(log);
  
  Logger::Warning << "Hello World!";
  
  Logger::RemoveListener(log);
  
  ASSERT_EQ(log.Count(), 1) << "The debug message is missing.";
  
  bool result = log[0] == "Hello World!";
  
  ASSERT_TRUE(result) << "The log was generated incorrectly.";
}

// Tests logging of a warning message without listening.
TEST(Logger, WarningLoggedWithoutListen)
{
  MemoryLog log(LogLevel::Debug | LogLevel::Info | LogLevel::Error, 3);
  
  Logger::AddListener(log);
  
  Logger::Warning << "Hello World!";
  
  Logger::RemoveListener(log);
  
  ASSERT_EQ(log.Count(), 0) << "Log elements present before log start.";
}

// Tests logging of an error message.
TEST(Logger, ErrorLogged)
{
  MemoryLog log(LogLevel::Error, 3);
  
  Logger::AddListener(log);
  
  Logger::Error << "Hello World!";
  
  Logger::RemoveListener(log);
  
  ASSERT_EQ(log.Count(), 1) << "The debug message is missing.";
  
  bool result = log[0] == "Hello World!";
  
  ASSERT_TRUE(result) << "The log was generated incorrectly.";
}

// Tests logging of an error message without listening.
TEST(Logger, ErrorLoggedWithoutListen)
{
  MemoryLog log(LogLevel::Debug | LogLevel::Info | LogLevel::Warning, 3);
  
  Logger::AddListener(log);
  
  Logger::Error << "Hello World!";
  
  Logger::RemoveListener(log);
  
  ASSERT_EQ(log.Count(), 0) << "Log elements present before log start.";
}

