/**
 ****************************************************************************************************
 * @file        demo.c
 * @author      正点原子团队(ALIENTEK)
 * @version     V1.0
 * @date        2024-11-01
 * @brief       烟雾传感器模块 测试代码
 * @license     Copyright (c) 2020-2032, 广州市星翼电子科技有限公司
 ****************************************************************************************************
 * @attention
 *
 * 实验平台:正点原子 STM32F103开发板
 * 在线视频:www.yuanzige.com
 * 技术论坛:www.openedv.com
 * 公司网址:www.alientek.com
 * 购买地址:openedv.taobao.com
 *
 ****************************************************************************************************
 */

#include "demo.h"
#include "./BSP/ATK_SMOKE/atk_smoke.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LED/led.h"
#include <stdio.h>
#include "./BSP/ATK_BUZZER/atk_buzzer.h"

/**
 * @brief       例程演示入口函数
 * @param       无
 * @retval      无
 */
void demo_run(void)
{
    float ppm;                              /* 可燃气体平均浓度 */

    atk_smoke_init();                       /* 初始化烟雾传感器模块 */
    atk_buzzer_init();                      /* 初始化蜂鸣器模块 */

    while (1)
    {
        ppm = atk_smoke_get_ppm();          /* 拟合函数换算出ppm */

        if(ppm > 120)
        {
            ATK_BUZZER(1);                  /* 如果超过120，蜂鸣器响 */
        }
        else if(ppm < 100)                  /* 如果小于100，蜂鸣器关闭 */
        {
            ATK_BUZZER(0);
        }

        delay_ms(0);
				
				LED0_TOGGLE(); /* 闪烁LED,提示系统正在运行. */
        
        delay_ms(500);
    }
}
