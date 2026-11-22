#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LED/led.h"

int main(void)
{
	
	HAL_Init ();
	delay_init (72);
	usart_init (115200);
	sys_stm32_clock_init (RCC_PLL_MUL9) ;
	led_init();
	
	
	while(1)
	{
		
		
		}
	
	
	
	
}
