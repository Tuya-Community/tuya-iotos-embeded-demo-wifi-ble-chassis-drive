/*
 * @Author: zgw
 * @email: liang.zhang@tuya.com
 * @LastEditors: zgw
 * @file name: sht21.h
 * @Description: SHT21 IIC drive src file
 * @Copyright: HANGZHOU TUYA INFORMATION TECHNOLOGY CO.,LTD
 * @Company: http://www.tuya.com
 * @Date: 2020-12-16 18:51:29
 * @LastEditTime: 2021-03-25 17:14:44
 */

#include "app_control.h"
#include "tuya_gpio.h"
#include "tuya_uart.h"
#include "BkDriverUart.h"
#include "sys_timer.h"
#include "uni_time.h"
#include "app_pwm.h"
/***********************************************************
*************************types define***********************
***********************************************************/
typedef enum
{
    LOW = 0,
    HIGH,
}default_level;

APP_CTRL_DATA_T app_ctrl_data = {0,200};

/***********************************************************
*************************IO control device define***********
***********************************************************/
#define WHEEL_A1                               (20)
#define WHEEL_A2                               (22)
/***********************************************************
*************************about adc init*********************
***********************************************************/

/***********************************************************
*************************about iic init*********************
***********************************************************/

/***********************************************************
*************************function***************************
***********************************************************/

STATIC VOID __ctrl_gpio_init(CONST TY_GPIO_PORT_E port, CONST BOOL_T high)
{   
    //Set IO port as output mode
    tuya_gpio_inout_set(port, FALSE);
    //Set IO port level
    tuya_gpio_write(port, high);
}


VOID app_device_init(VOID)
{
    app_pwm_init();
    __ctrl_gpio_init(WHEEL_A1,LOW);
    __ctrl_gpio_init(WHEEL_A2,HIGH);
}

VOID app_set_motor(MOTOR_STATE state)
{
    switch (state)
    {
    case stop:
        tuya_gpio_write(WHEEL_A1,LOW);
        tuya_gpio_write(WHEEL_A2,LOW);
        break;
    case clockwise:
        tuya_gpio_write(WHEEL_A1,LOW);
        tuya_gpio_write(WHEEL_A2,HIGH);
        break;    
    case counterclockwise:
        tuya_gpio_write(WHEEL_A1,HIGH);
        tuya_gpio_write(WHEEL_A2,LOW);
        break;
    default:
        break;
    }
}

VOID app_ctrl_handle(VOID)
{   
    app_set_motor(app_ctrl_data.motor_state);

    app_pwm_set(channel_1,app_ctrl_data.motor_speed);
}

VOID app_ctrl_all_off(VOID)
{   

}

 