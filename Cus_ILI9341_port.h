#ifndef __CUS_ILI9341_PORT_H__
#define __CUS_ILI9341_PORT_H__


#include <stdint.h>



/* ****************** ILI9341_PORT ****************** */
/* 通信原语层. 上层通过该基本API与LCD设备进行通信. */
/* 请根据实际运行环境及通信接口(FSMC / SPI). 正确实现以下方法. */
__weak void lcd_write_cmd( uint8_t cmd );


__weak void lcd_write_data( uint8_t data );


__weak void lcd_write_data16( uint16_t data );


__weak uint8_t lcd_read_data( void );


__weak uint16_t lcd_read_data16( void );
/* ****************** ILI9341_PORT ****************** */


/* ****************** ILI9341_PORT ****************** */
/* 底层通信接口驱动. 此函数只配置通信环境，不发送 LCD 初始化命令。*/
__weak void lcd_driver_init( void );
/* ****************** ILI9341_PORT ****************** */

#endif /* __CUS_ILI9341_PORT_H__ */


