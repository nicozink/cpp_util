/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

#ifndef ILOGWRITER_H
#define ILOGWRITER_H

// Local Includes
#include <cpp_util/log/log_level.h>

// Project Includes

// External Includes
#include <string>

// A virtual interface which provides a
// framework for listeners to the logging
// system.
class ILogWriter
{
  public:
    
    /*
     * Constructors
     */
    
    // Initialises a new instance of the "ILogWriter" class.
    // @param bitMask The bit mask.
    ILogWriter(LogLevel bitMask, bool is_enabled);

    /*
     * Public Virtual Methods
     */
    
    // Writes the message to the appropriate output medium.
    // @param message The log message.
    virtual void Log(std::string message) = 0;
    
    /*
     * Public Inline Methods
     */
    
    // Returns the log writer's bit mask.
    // @returns The bit mask.
    inline LogLevel get_bit_mask()
    {
      return m_bit_mask;
    }
    
	// Returns the log writer's enabled state.
	// @returns The bit mask.
	inline bool get_enabled()
	{
	  return m_is_enabled;
	}

	// Sets the log writer's bit mask.
	// @param bit_mask The bit mask.
	inline void set_bit_mask(LogLevel bit_mask)
	{
		m_bit_mask = bit_mask;
	}

	// Returns the log writer's enabled state.
	// @returns The bit mask.
	inline void set_enabled(bool is_enabled)
	{
		m_is_enabled = is_enabled;
	}

  private:
    
    /*
     * Private Variables
     */
    
	// Stores whether the log writer is enabled.
	bool m_is_enabled;

    // Stores the log level bit mask.
    LogLevel m_bit_mask;
};

#endif
