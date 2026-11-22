/**
 ******************************************************************************
 * @file     main.c
 * @author   正点原子团队(ALIENTEK)
 * @version  V1.0
 * @date     2024-11-01
 * @brief    光敏传感器 实验
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
#include "demo.h"


/**
 * @brief       显示实验信息
 * @param       无
 * @retval      无
 */
void show_mesg(void)
{
    /* 串口输出实验信息 */
    printf("\n");
    printf("********************************\r\n");
    printf("Light Sensor\r\n");
    printf("ATK-MB001\r\n");
    printf("ATOM@ALIENTEK\r\n");
    printf("********************************\r\n");
    printf("\r\n");
}

int main(void)
{
	HAL_Init();
	sys_stm32_clock_init(RCC_PLL_MUL9);
	delay_init(72);
	usart_init(115200);
	led_init();
	show_mesg();
	demo_run();
	
	
	/* 定义引脚数组，放在 while(1) 之前 */
	const uint16_t led_pins[8] = {
  GPIO_PIN_8,  GPIO_PIN_9,  GPIO_PIN_10, GPIO_PIN_11
	};

/* 先把所有灯熄灭 */
	for (int i = 0; i < 4; i++) {
    HAL_GPIO_WritePin(GPIOB, led_pins[i], GPIO_PIN_RESET);
	}

		while (1)
{
    for (int i = 0; i < 4; i++)
    {
        /* 先确保所有灯都灭，避免上一个灯残留 */
        for (int j = 0; j < 4; j++) {
            HAL_GPIO_WritePin(GPIOB, led_pins[j], GPIO_PIN_SET);
        }

        /* 只点亮当前这一个 */
        HAL_GPIO_WritePin(GPIOB, led_pins[i], GPIO_PIN_RESET);
        delay_ms(100);

        /* 熄灭当前灯，下一轮循环会点亮下一个 */
        HAL_GPIO_WritePin(GPIOB, led_pins[i], GPIO_PIN_SET);
    }
}

}
