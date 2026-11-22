#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LED/led.h"

UART_HandleTypeDef g_uart_init_handle;

void usart_init(void)
{
   __HAL_RCC_GPIOA_CLK_ENABLE();
   __HAL_RCC_USART1_CLK_ENABLE();

   GPIO_InitTypeDef gpio_init_struct;
   gpio_init_struct.Pin = GPIO_PIN_9;          
   gpio_init_struct.Mode = GPIO_MODE_AF_PP;    
   gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH; 
   HAL_GPIO_Init(GPIOA, &gpio_init_struct);    

   gpio_init_struct.Pin = GPIO_PIN_10;         
   gpio_init_struct.Mode = GPIO_MODE_AF_INPUT; 
   HAL_GPIO_Init(GPIOA, &gpio_init_struct);    
	 
	 
	 g_uart_init_handle.Instance = USART1;
	 g_uart_init_handle.Init.BaudRate = 115200;
	 g_uart_init_handle.Init.WordLength = UART_WORDLENGTH_8B;
	 g_uart_init_handle.Init.StopBits = UART_STOPBITS_1;
	 g_uart_init_handle.Init.Parity = UART_PARITY_NONE;
	 g_uart_init_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	 g_uart_init_handle.Init.Mode = UART_MODE_TX_RX;

	 HAL_UART_Init(&g_uart_init_handle);

}

int main(void)
{
	uint8_t rx_data;
//	uint8_t buf_a[5]={'H','E','L','L','O'}; 发送用的
	HAL_Init ();
	sys_stm32_clock_init(RCC_PLL_MUL9);
	delay_init (72);
	usart_init ();
	led_init();
	
	while(1)
	{
    if(HAL_UART_Receive(&g_uart_init_handle,&rx_data,1,100) == HAL_OK)
    {
        if(rx_data == 0x01)
        {
            LED0_TOGGLE();
            HAL_UART_Transmit(&g_uart_init_handle,&rx_data,1,100);
        }

    }

    delay_ms(10);
	}
//	while(1)
//	 {
//		HAL_UART_Transmit(&g_uart_init_handle,buf_a,5,100);
//		delay_ms(500);
//	 }         发送用的

}
