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
TEST(MemoryLog, NothingLogged)
{
  auto log = std::make_shared<MemoryLog>(LogLevel::Info, 3);
  
  auto handle = Logger::AddListener(log);
  Logger::RemoveListener(handle);
  
  ASSERT_EQ(log->Count(), 0) << "The count of an empty log is incorrect.";
  ASSERT_EQ(log->First(), 0) << "Log first index of an empty log is incorrect.";
}

// Tests logging of a variety of objects.
TEST(MemoryLog, ItemsLogged)
{
  auto log = std::make_shared<MemoryLog>(LogLevel::Debug | LogLevel::Info | LogLevel::Warning |
    LogLevel::Error, 3);
  
  auto handle = Logger::AddListener(log);
  
  Logger::Info << "First!";
  Logger::Warning << "Second!";
  Logger::Error << "Third";
  
  ASSERT_EQ(log->Count(), 3) << "The count of the log is incorrect.";
  ASSERT_EQ(log->First(), 0) << "Log first index of the log is incorrect.";
  
  bool result = (*log)[0] == "First!" &&
	  (*log)[1] == "Second!" && (*log)[2] == "Third";
  
  ASSERT_TRUE(result) << "The log was generated incorrectly.";

  Logger::RemoveListener(handle);
}

// Tests logging of a variety of objects while wrapping.
TEST(MemoryLog, ItemsLoggedWrapped)
{
  auto log = std::make_shared<MemoryLog>(LogLevel::Debug | LogLevel::Info | LogLevel::Warning |
    LogLevel::Error, 3);
  
  auto handle = Logger::AddListener(log);
  
  Logger::Info << "Discarded!";
  Logger::Info << "First!";
  Logger::Warning << "Second!";
  Logger::Error << "Third";
  
  ASSERT_EQ(log->Count(), 4) << "The count of the log is incorrect.";
  ASSERT_EQ(log->First(), 1) << "Log first index of the log is incorrect.";
  
  bool result = (*log)[1] == "First!" &&
	  (*log)[2] == "Second!" && (*log)[3] == "Third";
  
  ASSERT_TRUE(result) << "The log was generated incorrectly.";

  Logger::RemoveListener(handle);
}
