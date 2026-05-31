#ifndef __CUS_ILI9341_CMDS_H__
#define __CUS_ILI9341_CMDS_H__



/* **************** ILI9341_Write_Command **************** */
  #define ILI9341_SOFTWARE_RESET                    (0x01)            // 软件复位.
  #define ILI9341_MEM_ACCESS_CTRL                   (0x36)            // 内存访问控制（方向/颜色顺序）.
  #define ILI9341_COL_ADDR_SET                      (0x2A)            // 列地址范围设置.
  #define ILI9341_PAGES_ADDR_SET                    (0x2B)            // 页地址范围设置.
  #define ILI9341_MEM_WRITE                         (0x2C)            // 写入显存.
  #define ILI9341_SLEEP_OUT                         (0x11)            // 退出睡眠模式.
  #define ILI9341_PIXEL_FORMAT_SET                  (0x3A)            // 设置像素格式.
  #define ILI9341_DISPLAY_ON                        (0x29)            // 开启显示.
  #define ILI9341_DISPLAY_OFF                       (0x28)            // 关闭显示.
/* **************** ILI9341_Write_Command **************** */


/* **************** ILI9341_Read_Command **************** */
  #define ILI9341_READ_IDENTIFICATION_INFO          (0x04)              // 读取芯片 ID.
  #define ILI9341_READ_DISPLAY_STATUS               (0x09)              // 读取显示状态.
  #define ILI9341_READ_DISPLAY_PWR_MODE             (0x0A)              // 读取电源模式.
  #define ILI9341_READ_DISPLAY_MADCTL               (0x0B)              // 读取 MADCTL 值.
  #define ILI9341_READ_DISPLAY_PIXEL_FORMAT         (0x0C)              // 读取读取像素格式.
  #define ILI9341_READ_LCD_MODULE                   (0xD3)              // 读取模块信息.
  #define ILI9341_READ_MEM                          (0x2E)              // 读取显存.


/* **************** ILI9341_Read_Command **************** */

#endif /* __CUS_ILI9341_CMDS_H__ */
