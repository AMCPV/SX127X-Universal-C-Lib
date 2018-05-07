#define SX127X_REG_FIFO 0x00
#define SX127X_REG_OP_MODE 0x01
	#define SX127X_MODE_SLEEP 0x00
	#define SX127X_MODE_STDBY 0x01
	#define SX127X_MODE_FSTX 0x02
	#define SX127X_MODE_TX 0x03
	#define SX127X_MODE_FSRX 0x04
	#define SX127X_MODE_RX 0x05
void sx127x_set_op_mode(uint8_t mode) {
	sx127x_reg_set(SX127X_REG_OP_MODE,(sx127x_reg_get(SX127X_REG_OP_MODE) & 0xF8) | (mode & 0x7))
}
void sx127x_get_op_mode() {
	return sx127x_reg_get(SX127X_REG_OP_MODE) & 0x07;
}
void sx127x_set_loRa_mode(bool on) {
	uint8_t current_mode = sx127x_reg_get(SX127X_REG_OP_MODE);
	sx127x_reg_set(SX127X_REG_OP_MODE, (current_mode & 0xF8) | (mode & 0x7));
	sx127x_reg_set(SX127X_REG_OP_MODE, (current_mode & 0x7F) | (on << 7));
}
bool sx127x_get_loRa_mode() {
	return sx127x_reg_get(SX127X_REG_OP_MODE) >> 7;
}
	#define SX127X_TYPE_FSK 0x00
	#define SX127X_TYPE_OOK 0x50
void sx127x_set_modulation_type(uint8_t type) {
	sx127x_reg_set(SX127X_REG_OP_MODE, (sx127x_reg_get(SX127X_REG_OP_MODE) & 0x9F) | (type & 0x60));
}
void sx127x_set_access_shared_reg(bool on) {
	sx127x_reg_set(SX127X_REG_OP_MODE, (sx127x_reg_get(SX127X_REG_OP_MODE) & 0xF7) | (on << 6));
}
bool sx127x_get_access_shared_reg() {
	return sx127x_reg_get(SX127X_REG_OP_MODE) & 0x40?true:false;
}
void sx127x_set_low_frequency_mode(bool on) {
	sx127x_reg_set(SX127X_REG_OP_MODE, (sx127x_reg_get(SX127X_REG_OP_MODE) & 0xF7) | (on << 3));
}
bool sx127x_get_low_frequency_mode() {
	return sx127x_reg_get(SX127X_REG_OP_MODE) & 0x4 ? true : false;
}
#define SX127X_REG_BITRATE 0x02
#define SX127X_REG_BITRATE_MSB 0x02
#define SX127X_REG_BITRATE_LSB 0x03
#define SX127X_REG_FDEV 0x04
#define SX127X_REG_FDEV_MSB 0x04
#define SX127X_REG_FDEV_LSB 0x05
#define SX127X_REG_FRF 0x06
#define SX127X_REG_FRF_MSB 0x06
#define SX127X_REG_FRF_MID 0x07
#define SX127X_REG_FRF_LSB 0x08
#define SX127X_REG_PA_CONFIG 0x09
#define SX127X_REG_PA_RAMP 0x0A
#define SX127X_REG_OCP 0x0B
#define SX127X_REG_LNA 0x0C
#define SX127X_REG_RX_CONFIG 0x0D
#define SX127X_REG_RSSI_CONFIG 0x0E
#define SX127X_REG_RSSI_COLLISION 0x0F
#define SX127X_REG_RSSI_THRESH 0x10
#define SX127X_REG_RSSI_VALUE 0x11
#define SX127X_REG_RX_BW 0x12
#define SX127X_REG_AFC_BW 0x13
#define SX127X_REG_OOK_PEAK 0x14
#define SX127X_REG_OOK_FIX 0x15
#define SX127X_REG_OOK_AVG 0x16
#define SX127X_REG_AFC_FEI 0x1A
#define SX127X_REG_AFC 0x1B
#define SX127X_REG_AFC_MSB 0x1B
#define SX127X_REG_AFC_LSB 0x1C
#define SX127X_REG_FEI 0x1D
#define SX127X_REG_FEI_MSB 0x1D
#define SX127X_REG_FEI_LSB 0x1E
#define SX127X_REG_PREAMBLE_DETECT 0x1F
#define SX127X_REG_RX_TIMEOUT_1 0x20
#define SX127X_REG_RX_TIMEOUT_2 0x21
#define SX127X_REG_RX_TIMEOUT_3 0x22
#define SX127X_REG_RX_DELAY 0x23

//RC Oscillator registers
#define SX127X_REG_OSC 0x24

//Packet Handling registers
#define SX127X_REG_PREAMBLE 0x25
#define SX127X_REG_PREAMBLE_MSB 0x25
#define SX127X_REG_PREAMBLE_LSB 0x26
#define SX127X_REG_SYNC_CONFIG 0x27
#define SX127X_REG_SYNC_VALUE 0x28
#define SX127X_REG_SYNC_VALUE_1 0x28
#define SX127X_REG_SYNC_VALUE_2 0x29
#define SX127X_REG_SYNC_VALUE_3 0x2A
#define SX127X_REG_SYNC_VALUE_4 0x2B
#define SX127X_REG_SYNC_VALUE_5 0x2C
#define SX127X_REG_SYNC_VALUE_6 0x2D
#define SX127X_REG_SYNC_VALUE_7 0x2E
#define SX127X_REG_SYNC_VALUE_8 0x2F
uint64_t sx127x_get_sync_value() {
	unit64_t val=0;
	for (unit8_t x = 0; x < 8; x++)
#if sizeof(uint8_t)==1 && sizeof(uint64_t)==8
		(*uint8_t)(&val)[7 - x] = sx127x_reg_get(SX127X_REG_SYNC_VALUE + x);
#else
		val |= sx127x_reg_get(SX127X_REG_SYNC_VALUE + x) << 8*(7 - x);
#endif
	return val;
}

void sx127x_set_sync_value(uint64_t val) {
	for (uint8_t x = 0; x < 8; x++)
#if sizeof(uint8_t)==1&&sizeof(uint64_t)==8
		sx127x_reg_set(addr + x, (*uint8_t)(&val)[7-x]);
#else
		sx127x_reg_set(addr + x, (val >> (8 * (7 - x))) & 0xFF);
#endif
}

#define SX127X_REG_PACKET_CONFIG_1 0x30
#define SX127X_REG_PACKET_CONFIG_2 0x31
#define SX127X_REG_PAYLOAD_LENGTH 0x32
#define SX127X_REG_NODE_ADRS 0x33
#define SX127X_REG_BROADCAST_ADRS 0x34
#define SX127X_REG_FIFO_THRESH 0x35

//Sequencer registers
#define SX127X_REG_SEQ_CONFIG_1 0x36
#define SX127X_REG_SEQ_CONFIG_2 0x37
#define SX127X_REG_TIMER_RESOL 0x38
#define SX127X_REG_TIMER_1_COEF 0x39
#define SX127X_REG_TIMER_2_COEF 0x3A
//Service registers
#define SX127X_REG_IMAGE_CAL 0x3B
#define SX127X_REG_TEMP 0x3C
#define SX127X_REG_LOW_BAT 0x3D
//Status registers
#define SX127X_REG_IRQ_FLAGS_1 0x3E
#define SX127X_REG_IRQ_FLAGS_2 0x3F
//IO control registers
#define SX127X_REG_DIO_MAPPING_1 0x40
#define SX127X_REG_DIO_MAPPING_2 0x41
//Version register
#define SX127X_REG_VERSION 0x42
//Additon registers
#define SX127X_REG_PLL_HOP 0x44
#define SX127X_REG_TCXO 0x4B
#define SX127X_REG_PA_DAC 0x4D
#define SX127X_REG_FORMER_TEMP 0x5B
#define SX127X_REG_BITRATE_FRAC 0x5D
#define SX127X_REG_AGC_REF 0x61
#define SX127X_REG_AGC_THRESH_1 0x62
#define SX127X_REG_AGC_THRESH_2 0x63
#define SX127X_REG_AGC_THRESH_3 0x64
#define SX127X_REG_PLL 0x70

//Low Frequency Additional Registers
#define SX127X_REG_AGC_REF_LF 0x61
#define SX127X_REG_AGC_THRESH_1_LF 0x62
#define SX127X_REG_AGC_THRESH_2_LF 0x63
#define SX127X_REG_AGC_THRESH_3_LF 0x64
#define SX127X_REG_PLL_LF 0x70

//High Frequency Additional Registers
#define SX127X_REG_AGC_REF_HF 0x61
#define SX127X_REG_AGC_THRESH_1_HF 0x62
#define SX127X_REG_AGC_THRESH_2_HF 0x63
#define SX127X_REG_AGC_THRESH_3_HF 0x64
#define SX127X_REG_PLL_HF 0x70