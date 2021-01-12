
#ifndef _GPIO_I2C_H
#define _GPIO_I2C_H

#if 1
#define GPIO_I2C_MAGIC_BASE	'I'
#define GPIO_I2C_READ_BYTE   _IOR(GPIO_I2C_MAGIC_BASE,0x01,int)
#define GPIO_I2C_WRITE_BYTE  _IOW(GPIO_I2C_MAGIC_BASE,0x02,int)

#define GPIO_I2C_READ_DWORD   _IOR(GPIO_I2C_MAGIC_BASE,0x03,int)
#define GPIO_I2C_WRITE_DWORD  _IOR(GPIO_I2C_MAGIC_BASE,0x04,int)
#else
#define GPIO_I2C_READ_BYTE    0x01
#define GPIO_I2C_WRITE_BYTE   0x02

#define GPIO_I2C_READ_DWORD   0x03
#define GPIO_I2C_WRITE_DWORD  0x04
#endif

typedef struct _cx25838_regs_data
{
	unsigned int chip;	//0x88 or 0x8a
	unsigned int addr;	//reg address
	unsigned int hibit;
	unsigned int lobit;
	unsigned int data;
} cx25838_regs_data;


unsigned char gpio_i2c_read(unsigned char devaddress, unsigned char address);
unsigned char gpio_i2c_read_sp(unsigned char devaddress, unsigned char address);
void          gpio_i2c_write(unsigned char devaddress, unsigned char address, unsigned char value);
void          gpio_i2c_write_sp(unsigned char devaddress, unsigned char address, unsigned char value);
unsigned int  gpio_i2c2_read(unsigned char devaddress, unsigned short address, int num_bytes);
void          gpio_i2c2_write(unsigned char devaddress, unsigned short address, unsigned int data, int num_bytes);

unsigned int  gpio_i2c2_read_1bytesubaddr(unsigned char devaddress, unsigned char address, int num_bytes);
void          gpio_i2c2_write_1bytesubaddr(unsigned char devaddress, unsigned char address, unsigned int data, int num_bytes);

#endif
