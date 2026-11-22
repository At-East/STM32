/**
 ******************************************************************************
 * @file     main.c
 * @author   正点原子团队(ALIENTEK)
 * @version  V1.0
 * @date     2024-11-01
 * @brief    烟雾传感器模块 实验
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
    /* ????????. */
    printf("\n");
    printf("********************************\r\n");
    printf(" Smoke Sensor\r\n");
    printf(" ATK-MB005\r\n");
    printf(" ATOMGALIENTEK\r\n");
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
}
