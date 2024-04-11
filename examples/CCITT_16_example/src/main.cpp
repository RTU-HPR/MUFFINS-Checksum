uint8_t data[] = {0x01, 0x02, 0x03, 0x04};
uint16_t checksum = Checksum_CCITT_16::calculate(data, sizeof(data));

uint8_t data_with_cheksum[sizeof(data) + 2] = {};
memcpy(data_with_cheksum, data, sizeof(data));
data_with_cheksum[sizeof(data_with_cheksum) - 2] = checksum >> 8;   // Add the high byte
data_with_cheksum[sizeof(data_with_cheksum) - 1] = checksum & 0xFF; // Add the low byte

bool checksum_correct = Checksum_CCITT_16::verify(data_with_cheksum, sizeof(data_with_cheksum));