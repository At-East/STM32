/**
 ****************************************************************************************************
 * @file        demo.c
 * @author      正点原子团队(ALIENTEK)
 * @version     V1.0
 * @date        2024-11-01
 * @brief       光敏传感器 测试代码
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
#include "./BSP/ATK_LIGHT/atk_light.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LED/led.h"
#include "./BSP/ADC/adc.h"


/**
 * @brief       例程演示入口函数
 * @param       无
 * @retval      无
 */
void demo_run(void)
{
    uint16_t adcx;
    float temp;
    const uint16_t led_pins[4] = {GPIO_PIN_8, GPIO_PIN_9, GPIO_PIN_10, GPIO_PIN_11};
    uint8_t flow_step = 0;

    atk_light_init(); 

    while (1)
    {
        adcx = adc_get_result_average(ADC_ADCX_CHY, 10);  
        temp = (float)adcx * (3.3 / 4096);                
        uint8_t light_val = atk_light_get_val(); 

        printf("AD:%d, 电压:%.2fV, 光强:%d\r\n", adcx, temp, light_val);

        // ===== 1. 控制 PA8 (常亮灯) =====
        if (light_val < 5) 
        {
            // 光照小于5，点亮 PA8 (低电平亮)
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET); 
        }
        else 
        {
            // 否则熄灭 PA8
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);   
        }

        // ===== 2. 控制 PB8~11 (流水灯) =====
        if (light_val >= 20)
        {
            // 先全灭
            for (int i = 0; i < 4; i++) {
                HAL_GPIO_WritePin(GPIOB, led_pins[i], GPIO_PIN_SET); 
            }
            // 点亮当前灯
            HAL_GPIO_WritePin(GPIOB, led_pins[flow_step], GPIO_PIN_RESET); 
            
            flow_step++;
            if (flow_step >= 4) flow_step = 0;
        }
        else
        {
            // 不满足流水灯条件，全灭
            for (int i = 0; i < 4; i++) {
                HAL_GPIO_WritePin(GPIOB, led_pins[i], GPIO_PIN_SET); 
            }
        }

        delay_ms(500); 
    }
}
