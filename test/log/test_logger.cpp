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
  auto log = std::make_shared<MemoryLog>(LogLevel::Info, 3);
  
  auto handle = Logger::AddListener(log);
  Logger::RemoveListener(handle);
  
  ASSERT_EQ(log->Count(), 0) << "Log elements present before log start.";
}

// Tests logging of a variety of objects using direct logging calls.
TEST(Logger, ItemsLoggedDirect)
{
  auto log = std::make_shared<MemoryLog>(LogLevel::Debug | LogLevel::Info | LogLevel::Warning |
    LogLevel::Error, 3);
  
  auto handle = Logger::AddListener(log);
  
  Logger::Log(LogLevel::Info) << "Hello World!";
  Logger::Log(LogLevel::Warning) << "Integer: " << 1;
  Logger::Log(LogLevel::Error) << "Double: " << 0.5;
  
  ASSERT_EQ(log->Count(), 3) << "Some logging elements are missing.";
  
  bool result = (*log)[0] == "Hello World!" &&
	(*log)[1] == "Integer: 1" && (*log)[2] == "Double: 0.5";
  
  ASSERT_TRUE(result) << "The log was generated incorrectly.";

  Logger::RemoveListener(handle);
}

// Tests logging of a variety of objects using normal logging calls.
TEST(Logger, ItemsLogged)
{
  auto log = std::make_shared<MemoryLog>(LogLevel::Debug | LogLevel::Info | LogLevel::Warning |
    LogLevel::Error, 3);
  
  auto handle = Logger::AddListener(log);
  
  Logger::Info << "Hello World!";
  Logger::Warning << "Integer: " << 1;
  Logger::Error << "Double: " << 0.5;
  
  ASSERT_EQ(log->Count(), 3) << "Some logging elements are missing.";
  
  bool result = (*log)[0] == "Hello World!" &&
	  (*log)[1] == "Integer: 1" && (*log)[2] == "Double: 0.5";
  
  ASSERT_TRUE(result) << "The log was generated incorrectly.";

  Logger::RemoveListener(handle);
}

// Tests logging of a debug message.
TEST(Logger, DebugLogged)
{
  auto log = std::make_shared<MemoryLog>(LogLevel::Debug, 3);
  
  auto handle = Logger::AddListener(log);
  
  #ifdef DEBUG
  
  Logger::Debug << "Hello World!";
  
  #else
  
  Logger::Log(LogLevel::Debug) << "Hello World!";
  
  #endif
  
  ASSERT_EQ(log->Count(), 1) << "The debug message is missing.";
  
  bool result = (*log)[0] == "Hello World!";
  
  ASSERT_TRUE(result) << "The log was generated incorrectly.";

  Logger::RemoveListener(handle);
}

// Tests logging of a debug message without listening.
TEST(Logger, DebugLoggedWithoutListen)
{
  auto log = std::make_shared<MemoryLog>(LogLevel::Info | LogLevel::Warning | LogLevel::Error, 3);
  
  auto handle = Logger::AddListener(log);
  
  #ifdef DEBUG
  
  Logger::Debug << "Hello World!";
  
  #else
  
  Logger::Log(LogLevel::Debug) << "Hello World!";
  
  #endif
  
  ASSERT_EQ(log->Count(), 0) << "Log elements present before log start.";

  Logger::RemoveListener(handle);
}

// Tests logging of an info message.
TEST(Logger, InfoLogged)
{
  auto log = std::make_shared<MemoryLog>(LogLevel::Info, 3);
  
  auto handle = Logger::AddListener(log);
  
  Logger::Info << "Hello World!";
  
  ASSERT_EQ(log->Count(), 1) << "The debug message is missing.";
  
  bool result = (*log)[0] == "Hello World!";
  
  ASSERT_TRUE(result) << "The log was generated incorrectly.";

  Logger::RemoveListener(handle);
}

// Tests logging of a info message without listening.
TEST(Logger, InfoLoggedWithoutListen)
{
  auto log = std::make_shared<MemoryLog>(LogLevel::Debug | LogLevel::Warning | LogLevel::Error, 3);
  
  auto handle = Logger::AddListener(log);
  
  Logger::Info << "Hello World!";
  
  ASSERT_EQ(log->Count(), 0) << "Log elements present before log start.";

  Logger::RemoveListener(handle);
}

// Tests logging of a warning message.
TEST(Logger, WarningLogged)
{
  auto log = std::make_shared<MemoryLog>(LogLevel::Warning, 3);
  
  auto handle = Logger::AddListener(log);
  
  Logger::Warning << "Hello World!";
  
  ASSERT_EQ(log->Count(), 1) << "The debug message is missing.";
  
  bool result = (*log)[0] == "Hello World!";
  
  ASSERT_TRUE(result) << "The log was generated incorrectly.";

  Logger::RemoveListener(handle);
}

// Tests logging of a warning message without listening.
TEST(Logger, WarningLoggedWithoutListen)
{
  auto log = std::make_shared<MemoryLog>(LogLevel::Debug | LogLevel::Info | LogLevel::Error, 3);
  
  auto handle = Logger::AddListener(log);
  
  Logger::Warning << "Hello World!";
  
  ASSERT_EQ(log->Count(), 0) << "Log elements present before log start.";

  Logger::RemoveListener(handle);
}

// Tests logging of an error message.
TEST(Logger, ErrorLogged)
{
  auto log = std::make_shared<MemoryLog>(LogLevel::Error, 3);
  
  auto handle = Logger::AddListener(log);
  
  Logger::Error << "Hello World!";
  
  ASSERT_EQ(log->Count(), 1) << "The debug message is missing.";
  
  bool result = (*log)[0] == "Hello World!";
  
  ASSERT_TRUE(result) << "The log was generated incorrectly.";

  Logger::RemoveListener(handle);
}

// Tests logging of an error message without listening.
TEST(Logger, ErrorLoggedWithoutListen)
{
  auto log = std::make_shared<MemoryLog>(LogLevel::Debug | LogLevel::Info | LogLevel::Warning, 3);
  
  auto handle = Logger::AddListener(log);
  
  Logger::Error << "Hello World!";
  
  ASSERT_EQ(log->Count(), 0) << "Log elements present before log start.";

  Logger::RemoveListener(handle);
}

