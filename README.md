# Cheksum-Calculations
This libary is designed to calculate and verify checksums used in RTU HPR Software.

Currently available checksum types:
* CCITT_16 - 16 byte cheksum (uses polynomial 0x8408 for the calculation)

## Usage
To calculate the cheksum call the chosen cheksum calculation function:
```cpp
Checksum_XXXXXX::calculate(data, sizeof(data));
```

To verify the cheksum call the chosen cheksum verify function:
```cpp
Checksum_XXXXXX::verify(data, sizeof(data));
```

#### Appending cheksum to data array
The user is responisble for appending of checksum to the data array.

## Example
Example usage with the CCITT_16 checksum:
```cpp
uint8_t data[] = {0x01, 0x02, 0x03, 0x04};
uint16_t checksum = Checksum_CCITT_16::calculate(data, sizeof(data));

uint8_t data_with_cheksum[sizeof(data) + 2] = {};
memcpy(data_with_cheksum, data, sizeof(data));
data_with_cheksum[sizeof(data_with_cheksum) - 2] = checksum >> 8;   // Add the high byte
data_with_cheksum[sizeof(data_with_cheksum) - 1] = checksum & 0xFF; // Add the low byte

bool checksum_correct = Checksum_CCITT_16::verify(data_with_cheksum, sizeof(data_with_cheksum));
```
