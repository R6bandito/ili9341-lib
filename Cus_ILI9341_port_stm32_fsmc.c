#include "Cus_ILI9341_port_stm32_fsmc.h"


/* ******************************************* */
void Cus_fsmc_init( void );
static fsmc_gpio_init( void );
/* ******************************************* */


/* ******************************************* */
typedef struct 
{
  GPIO_TypeDef *gpioPort;
  uint16_t gpioPin;

} lcd_pin_t;

static const lcd_pin_t ctrl_pins[] = {
  {.gpioPort = LCD_CS_PORT, .gpioPin = LCD_CS_PIN},
  {.gpioPort = LCD_WR_PORT, .gpioPin = LCD_WR_PIN},
  {.gpioPort = LCD_RS_PORT, .gpioPin = LCD_RS_PIN},
  {.gpioPort = LCD_RD_PORT, .gpioPin = LCD_RD_PIN},
};

static const lcd_pin_t data_pins[] = {
  {.gpioPort = LCD_D0_PORT, .gpioPin = LCD_D0_PIN},
  {.gpioPort = LCD_D1_PORT, .gpioPin = LCD_D1_PIN},
  {.gpioPort = LCD_D2_PORT, .gpioPin = LCD_D2_PIN},
  {.gpioPort = LCD_D3_PORT, .gpioPin = LCD_D3_PIN},
  {.gpioPort = LCD_D4_PORT, .gpioPin = LCD_D4_PIN},
  {.gpioPort = LCD_D5_PORT, .gpioPin = LCD_D5_PIN},
  {.gpioPort = LCD_D6_PORT, .gpioPin = LCD_D6_PIN},
  {.gpioPort = LCD_D7_PORT, .gpioPin = LCD_D7_PIN},
  {.gpioPort = LCD_D8_PORT, .gpioPin = LCD_D8_PIN},
  {.gpioPort = LCD_D9_PORT, .gpioPin = LCD_D9_PIN},
  {.gpioPort = LCD_D10_PORT, .gpioPin = LCD_D10_PIN},
  {.gpioPort = LCD_D11_PORT, .gpioPin = LCD_D11_PIN},
  {.gpioPort = LCD_D12_PORT, .gpioPin = LCD_D12_PIN},
  {.gpioPort = LCD_D13_PORT, .gpioPin = LCD_D13_PIN},
  {.gpioPort = LCD_D14_PORT, .gpioPin = LCD_D14_PIN},
  {.gpioPort = LCD_D15_PORT, .gpioPin = LCD_D15_PIN}
};
/* ******************************************* */


static fsmc_gpio_init( void )
{
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();

  GPIO_InitTypeDef GpioInitStructure = {0};
  GpioInitStructure.Mode = GPIO_MODE_AF_PP;
  GpioInitStructure.Speed = GPIO_SPEED_FREQ_HIGH;
  GpioInitStructure.Pull = GPIO_NOPULL;

  for( uint8_t i = 0; i < 4; i++ )
  {
    /* 循环初始化所有控制引脚. */
    GpioInitStructure.Pin = ctrl_pins[i].gpioPin;
    HAL_GPIO_Init(ctrl_pins[i].gpioPort, &GpioInitStructure);
  }

  for( uint8_t i = 0; i < 16; i++ )
  {
    /* 循环初始化所有数据引脚.s */
    GpioInitStructure.Pin = data_pins[i].gpioPin;
    HAL_GPIO_Init(data_pins[i].gpioPort, &GpioInitStructure);
  }
}



void Cus_fsmc_init( void )
{ 
  /* 使能 FSMC 时钟. */
  __HAL_RCC_FSMC_CLK_ENABLE();

  /* 配置GPIO. */
  fsmc_gpio_init();

  FSMC_NORSRAM_InitTypeDef fsmc_init;
  fsmc_init.AsynchronousWait    =   FSMC_ASYNCHRONOUS_WAIT_DISABLE;
  fsmc_init.BurstAccessMode     =   FSMC_BURST_ACCESS_MODE_DISABLE;
  fsmc_init.DataAddressMux      =   FSMC_DATA_ADDRESS_MUX_DISABLE;
  fsmc_init.ExtendedMode        =   FSMC_EXTENDED_MODE_ENABLE;
  fsmc_init.MemoryDataWidth     =   FSMC_NORSRAM_MEM_BUS_WIDTH_16;
  fsmc_init.MemoryType          =   FSMC_MEMORY_TYPE_SRAM;
  fsmc_init.NSBank              =   FSMC_NSBANK;
  fsmc_init.PageSize            =   FSMC_PAGE_SIZE_NONE;
  fsmc_init.WaitSignal          =   FSMC_WAIT_SIGNAL_DISABLE;
  fsmc_init.WaitSignalActive    =   FSMC_WAIT_TIMING_BEFORE_WS;
  fsmc_init.WaitSignalPolarity  = FSMC_WAIT_SIGNAL_POLARITY_LOW;
  fsmc_init.WrapMode            = FSMC_WRAP_MODE_DISABLE;
  fsmc_init.WriteBurst          = FSMC_WRITE_BURST_DISABLE;
  fsmc_init.WriteOperation      = FSMC_WRITE_OPERATION_ENABLE;

  /* 填充FSMC读时序参数. */
  FSMC_NORSRAM_TimingTypeDef fsmc_readtiming;
  fsmc_readtiming.AccessMode                = FSMC_ACCESS_MODE_A;                      
  fsmc_readtiming.AddressHoldTime           = FSMC_READ_ADDR_HOLD_TIME;
  fsmc_readtiming.AddressSetupTime          = FSMC_READ_ADDR_SETUP_TIME;
  fsmc_readtiming.BusTurnAroundDuration     = FSMC_BUS_AROUND_DURATION;
  fsmc_readtiming.DataSetupTime             = FSMC_READ_DATA_SETUP_TIME;

  /* 填充FSMC写时序. */
  FSMC_NORSRAM_TimingTypeDef fsmc_writetiming;
  fsmc_writetiming.AccessMode = ;
  fsmc_writetiming.AddressHoldTime = ;
  fsmc_writetiming.AddressSetupTime = ;
  fsmc_writetiming.BusTurnAroundDuration = ;
  fsmc_writetiming.DataSetupTime = ;

}






