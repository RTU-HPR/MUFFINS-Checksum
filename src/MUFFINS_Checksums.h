#pragma once
#include <Arduino.h>

namespace Checksum_CCITT_16 {
  /**
   * @brief Calculate CCITT-16 checksum
   * @param data Pointer to data to calculate checksum for
   * @param length Length of data
   * @return The calculated checksum
  */
  uint16_t calculate(const uint8_t* data, size_t length);
  
  /**
   * @brief Verify CCITT-16 checksum
   * @param data Pointer to data to verify checksum for
   * @param length Length of data
   * @return True if the checksum is valid, false otherwise
  */
  bool verify(const uint8_t* data, size_t length);
}