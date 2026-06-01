#include "Cus_ILI9341.h"
#include "Cus_ILI9341_port.h"


/* ********************************** */
typedef struct 
{
  /* 基本属性. */
  const char *dev_name;                // 设备名称.
  uint16_t width;                      // 当前显示宽度（像素）.
  uint16_t height;                     // 当前显示高度（像素）.
  uint8_t pixel_format;                // 像素格式 (0x55 = RGB565, 0x66 = RGB666 等).
  uint8_t MADCTL;                      // 内存访问控制寄存器状态.

  /* 窗口缓存状态. */
  uint16_t windows_x0, windows_y0;     // 当前窗口左上角坐标.
  uint16_t windows_x1, windows_y1;     // 当前窗口右下角坐标.
  bool is_windows_valid;               // 当前窗口缓存是否有效.

  /* 区域刷新模式相关. */
  bool is_partialMode_enable;          // 区域刷新模式是否开启.
  uint16_t partial_startRow;           // 部分刷新起始行.
  uint16_t partial_endRow;             // 部分刷新结束行.
  
} deviceAttr_t;


/* ********************************** */


