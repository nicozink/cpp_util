/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

#ifndef BITMASK_H
#define BITMASK_H

// Local Includes

// Project Includes

// External Includes

// A class which contains static utility methods.
class BitMask
{
public:

  //
  // Public Static Methods
  //

  // Checks the validity of the bit mask object.
  // @returns The integer value.
  template<typename T>
  static inline int IsTrue(T obj)
  {
    return static_cast<int>(obj);
  }
};

#endif
