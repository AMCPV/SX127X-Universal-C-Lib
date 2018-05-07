#define SX127X_SET(addr,val,lenght) for(uint8_t x=0;x<lenght;x++)	sx127x_reg_set(addr+x,val>>(8*((lenght-1)-x)))
#define SX127X_GET(addr,val,lenght) for(uint8_t x=0;x<lenght;x++)	val |= sx127x_reg_get(addr+x)>>(8*((lenght-1)-x))
#define SX127X_GET2(addr) ((sx127x_reg_get(addr)<<8)|sx127x_reg_get(addr+1))
#define SX127X_GET3(addr) ((sx127x_reg_get(addr) << 16) | (sx127x_reg_get(addr + 1) << 8) | sx127x_reg_get(addr + 1))
#define SX127X_GET8(addr) ((sx127x_reg_get(addr) << 8*7) | (sx127x_reg_get(addr + 1) << 8*6) | (sx127x_reg_get(addr+2) << 8*5) | (sx127x_reg_get(addr + 3) << 8*4) | (sx127x_reg_get(addr +4 ) << 8*3) | (sx127x_reg_get(addr + 5) << 8*2) | (sx127x_reg_get(addr+6) << 8) | sx127x_reg_get(addr + 7))

#define SX127X_REG_VER 0x42
#define SX127X_VER 0x12
#define SX127X_REG_OP_MODE 0x01

#define SX127X_MODE_LONG_RANGE 0x80
#define SX127X_REG_FRF_MSB 0x06
#define SX127X_REG_FRF_MID 0x07
#define SX127X_REG_FRF_LSB 0x08
#define SX127X_REG_FRF 0x06
#define SX127X_SPI_FILLER 0x00
#define SX127X_REG_FIFO_TX_BASE_ADDR 
#define SX127X_REG_FIFO_RX_BASE_ADDR
#define SX127X_REG_LNA
#define SX127X_REG_MODEM_CFG_3
#define SX127X_REG_
#define SX127X_REG_
#define SX127X_REG_
#define SX127X_REG_
#define SX127X_REG_
#define SX127X_REG_
#define SX127X_REG_
#define SX127X_REG_
#define SX127X_REG_

//MODES
#define SX127X_MODE_SLEEP 0x00
#define SX127X_MODE_STANDBY 0x01
#define SX127X_MODE_FSTX 0x02
#define SX127X_MODE_FSRX 0x04
#define SX127X_MODE_TX 0x03
#define SX127X_MODE_RXCONTINOUS 0x05
#define SX127X_MODE_RXSINGLE 0x06
#define SX127X_MODE_CAD 0x07 //geraten