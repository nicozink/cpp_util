/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

// Local Includes

// Project Includes
#include <unittest/test.h>

// External Includes
#include <vector>

// Tests the timing of returning a copy, using as an rvalue, and releasing it.

// Helper Classes
class LogMoveClass
{
public:

  LogMoveClass(std::vector<int>& sequence)
    : sequence(sequence)
  {
    sequence.push_back(0);
  }

  LogMoveClass(LogMoveClass& other)
    : sequence(other.sequence)
  {
    sequence.push_back(2);
  }

  ~LogMoveClass()
  {
    sequence.push_back(4);
  }

  void Touch()
  {
    sequence.push_back(3);
  }

private:

  // A vector which stores the sequence of initialisation.
  std::vector<int>& sequence;
};

class LogMoveFactory
{
public:

  LogMoveFactory(std::vector<int>& sequence)
    : moveClass(sequence), sequence(sequence)
  {
    sequence.push_back(1);
  }

  LogMoveClass GetClass()
  {
    return moveClass;
  }

  void Touch()
  {
    sequence.push_back(5);
  }

private:

  LogMoveClass moveClass;

  std::vector<int>& sequence;
};

// Logs nothing, and checks to make sure that the log is empty.
TEST(LogMove, TestLogMoveClass)
{
  std::vector<int> sequence;

  LogMoveFactory factory(sequence);

  factory.GetClass().Touch();

  factory.Touch();

  ASSERT_EQ(sequence.size(), 6) << "The size of the sequence is incorrect.";

  for (size_t i = 0; i < sequence.size(); ++i)
  {
    ASSERT_EQ(sequence[i], (int)i) << "The exprected sequence happened in an unexpected order.";
  }
}
