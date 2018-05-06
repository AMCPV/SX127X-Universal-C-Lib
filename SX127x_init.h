//MAX SPI 10MHz
//void needs sx127x_reg_set(uint8_t,uint8_t)
//uint8_t sx127x_reg_get(uint8_t)
//void sx127x_reset
//sx127x_
void spi_init();
void sx127x_reg_set(uint8_t,uint8_t);//spi write addr,val
uint8_t sx127x_reg_get(uint8_t);//spi write addr and 0x00 for getting val
void sx127x_reset();//10ms low 10ms high beeing high
void error_out(const char*);

#define sx127x_sleep() sx127x_reg_set(SX127X_REG_OP_MODE,SX127X_MODE_LONG_RANGE | SX127X_MODE_SLEEP)
#define sx127x_standby() sx127x_reg_set(SX127X_REG_OP_MODE,SX127X_MODE_LONG_RANGE | SX127X_MODE_STANDBY)

int sx127x_init(uint8_t freq[3]){
	spi_init();
	sx127x_reset();
	if(sx127x_reg_get(SX127X_REG_VER) != SX127X_VER){//check for sx127X
		error_out("wrong_version");
		return -1;
	}
	sx127x_sleep();
	//TODO
	sx127x_freq_set(freq);
	sx127x_reg_set(SX127X_REG_FIFO_TX_BASE_ADDR, 0);
	sx127x_reg_set(SX127X_REG_FIFO_RX_BASE_ADDR, 0);
	sx127x_reg_set(SX127X_REG_LNA, sx127x_reg_get(SX127X_REG_LNA) | 0x03); //setup LNA BOOST
	sx127x_reg_set(SX127X_REG_MODEM_CFG_3, 0x04);
}

void sx127x_freq_set(uint8_t freq[3]){
	for(uint8_t x = 0; x < 3; x++)
		sx127x_reg_set(SX127X_REG_FRF + x, freq[x]);
}