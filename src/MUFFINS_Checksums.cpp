#include <MUFFINS_Checksums.h>

uint16_t Checksum_CCITT_16::calculate(const uint8_t *data, size_t length)
{
  uint16_t crc = 0xFFFF; // Initial value

  for (uint16_t i = 0; i < length; i++)
  {
    crc ^= data[i]; // XOR with current byte

    for (uint8_t j = 0; j < 8; j++)
    {
      if (crc & 0x0001) // If LSB is 1
      {
        crc >>= 1;     // Right shift by 1
        crc ^= 0x8408; // XOR with polynomial 0x8408
      }
      else
      {
        crc >>= 1; // Right shift by 1
      }
    }
  }

  return crc;
}

bool Checksum_CCITT_16::verify(const uint8_t *data, size_t length)
{
  uint16_t crc = Checksum_CCITT_16::calculate(data, length - 2); // Ignore the data checksum bytes at the end

  // Check checksum
  if (data[length - 2] == ((crc >> 8) & 0xFF) && data[length - 1] == (crc & 0xFF))
  {
    return true;
  }
  
  return false;
}
