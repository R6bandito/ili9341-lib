#ifndef __CUS_ILI9341_H__
#define __CUS_ILI9341_H__

#include <stdint.h>
#include <stdbool.h>


/* **************** Font Conf **************** */
  #define ILI9341_FONT_12                 (1)
  #define ILI9341_FONT_16                 (0)
  #define ILI9341_FONT_24                 (0)
  #define ILI9341_FONT_32                 (0)
/* **************** Font Conf **************** */

/* **************** Resolution Conf **************** */
  /* 屏幕分辨率. 一般无需手动改动. */
  #define LCD_SCREEN_WIDTH                (240)
  #define LCD_SCREEN_HEIGHT               (320)
/* **************** Resolution Conf **************** */

/* **************** Defines **************** */
  /* 以下旋转方向均按顺时针进行组织. */
  #define ILI9341_ROTATION_0               (0)
  #define ILI9341_ROTATION_90              (1)
  #define ILI9341_ROTATION_180             (2)
  #define ILI9341_ROTATION_270             (3)

  #define ID_ILI9341                       (0x9341UL)
  #define ID_ST7789                        (0x7789UL)

  #define CUS_COLOR_WHITE                  (0xFFFFUL)
  #define CUS_COLOR_BLACK                  (0x0000UL)
/* **************** Defines **************** */

/* *********************** ILI9341_Device_Struct *********************** */
typedef struct tftDevice tftDevice_HandleTypeDef;
struct tftDevice
{
  /* 基本属性(不对外开放) */
  /* 若需获取当前设备属性. 请使用公共API. */
  void *Attr;

  int8_t (*displayInit)( tftDevice_HandleTypeDef *dev, uint8_t rotation );
  void (*displayOn)( void );
  void (*setWindow)( tftDevice_HandleTypeDef *dev, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2 );      // 开窗回调.
  void (*lcd_fill)( tftDevice_HandleTypeDef *dev, uint16_t color );
};
/* *********************** ILI9341_Device_Struct *********************** */


/* *********************** Public API *********************** */
void Cus_ILI9341_InitHandle( tftDevice_HandleTypeDef *dev );
/* *********************** Public API *********************** */

#endif /* __CUS_ILI9341_H__ */

