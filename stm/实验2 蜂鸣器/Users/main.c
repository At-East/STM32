/**
 ******************************************************************************
 * @file     main.c
 * @author   正点原子团队(ALIENTEK)
 * @version  V1.0
 * @date     2023-08-01
 * @brief    ???
 * @license  Copyright (c) 2020-2032, 广州市星翼电子科技有限公司
 ******************************************************************************
 * @attention
 * 
 * 实验平台:正点原子 M48Z-M3最小系统板STM32F103版
 * 在线视频:www.yuanzige.com
 * 技术论坛:www.openedv.com
 * 公司网址:www.alientek.com
 * 购买地址:openedv.taobao.com
 ******************************************************************************
 */

#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LED/led.h"
#include "./BSP/KEY/key.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/ATK_BUZZER/atk_buzzer.h"


int main(void)
{
	
	HAL_Init();
	sys_stm32_clock_init(RCC_PLL_MUL9); //对时钟进行初始化
	delay_init(72); //延时
	usart_init(115200); //串口
	led_init(); //LED
	key_init();
	atk_buzzer_init();
	
	
	/**这个是不对蜂鸣器控制
	while(1)
	{
		
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,GPIO_PIN_SET);
		delay_ms(100);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,GPIO_PIN_RESET);
		delay_ms(100);
		
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,GPIO_PIN_SET);
		delay_ms(100);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,GPIO_PIN_RESET);
		delay_ms(100);
		
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,GPIO_PIN_SET);
		delay_ms(100);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,GPIO_PIN_RESET);
		delay_ms(1000);
	}
	**/
	
	while(1)
	{
		if(key_scan()== 1)
			{
				ATK_BUZZER_TOGGLE();
			}
	}
	
}
