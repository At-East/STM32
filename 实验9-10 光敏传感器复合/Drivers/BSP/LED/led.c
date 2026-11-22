/**
 ****************************************************************************************************
 * @file        led.c
 * @author      正点原子团队(ALIENTEK)
 * @version     V1.0
 * @date        2023-08-01
 * @brief       LED 驱动代码
 * @license     Copyright (c) 2020-2032, 广州市星翼电子科技有限公司
 ****************************************************************************************************
 * @attention
 *
 * 实验平台:正点原子 M48Z-M3最小系统板STM32F103版
 * 在线视频:www.yuanzige.com
 * 技术论坛:www.openedv.com
 * 公司网址:www.alientek.com
 * 购买地址:openedv.taobao.com
 *
 ****************************************************************************************************
 */

#include "./BSP/LED/led.h"

/**
 * @brief       初始化LED相关IO口, 并使能时钟
 * @param       无
 * @retval      无
 */
void led_init(void)
{
    GPIO_InitTypeDef gpio_init_struct = {0};

    /* 1. 开启两个端口的时钟 */
    LED_PA8_CLK_ENABLE();   /* 开启 GPIOA 时钟 */
    LED_FLOW_CLK_ENABLE();  /* 开启 GPIOB 时钟 */

    /* 2. 初始化 PA8 (常亮灯) */
    gpio_init_struct.Pin = LED_PA8_PIN;
    gpio_init_struct.Mode = GPIO_MODE_OUTPUT_PP;            /* 推挽输出 */
    gpio_init_struct.Pull = GPIO_PULLUP;                    /* 上拉 */
    gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;          /* 高速 */
    HAL_GPIO_Init(LED_PA8_PORT, &gpio_init_struct);         

    /* 3. 初始化 PB8~PB11 (流水灯) */
    gpio_init_struct.Pin = LED_FLOW_PINS;
    HAL_GPIO_Init(LED_FLOW_PORT, &gpio_init_struct);

    /* 4. 默认状态：全部熄灭 (假设低电平亮，高电平灭) */
    HAL_GPIO_WritePin(LED_PA8_PORT, LED_PA8_PIN, GPIO_PIN_SET); 
    HAL_GPIO_WritePin(LED_FLOW_PORT, LED_FLOW_PINS, GPIO_PIN_SET);
}
