/**
 ****************************************************************************************************
 * @file        led.h
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


#ifndef _LED_H
#define _LED_H
#include "./SYSTEM/sys/sys.h"

/******************************************************************************************/
/* 引脚 定义 */

/* 常亮灯 - PA8 */
#define LED_PA8_PORT                  GPIOA
#define LED_PA8_PIN                   GPIO_PIN_8
#define LED_PA8_CLK_ENABLE()          do{ __HAL_RCC_GPIOA_CLK_ENABLE(); }while(0)

/* 流水灯 - PB8~PB11 */
#define LED_FLOW_PORT                 GPIOB
#define LED_FLOW_PINS                 (GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11)
#define LED_FLOW_CLK_ENABLE()         do{ __HAL_RCC_GPIOB_CLK_ENABLE(); }while(0)

/******************************************************************************************/
/* 外部接口函数*/
void led_init(void);                                                                            /* 初始化 */

#endif
