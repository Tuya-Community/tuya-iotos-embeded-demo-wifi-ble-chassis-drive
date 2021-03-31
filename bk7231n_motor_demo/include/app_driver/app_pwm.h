/*
 * @file name: 
 * @Descripttion: 
 * @Author: zgw
 * @email: liang.zhang@tuya.com
 * @Copyright: HANGZHOU TUYA INFORMATION TECHNOLOGY CO.,LTD
 * @Company: http://www.tuya.com
 * @Date: 2021-03-03 17:19:36
 * @LastEditors: zgw
 * @LastEditTime: 2021-03-13 11:13:36
 */

#ifndef __APP_PWM_H__
#define __APP_PWM_H__

#include "uni_log.h"
#include "tuya_cloud_error_code.h"



/**
 * @brief pwm init data structure
 * pwm send data structure
 */
typedef struct 
{
    USHORT_T usFreq;            ///< PWM Frequency
    USHORT_T usDuty;            ///< PWM Init duty
    UCHAR_T ucList[3];          ///< GPIO List 
    UCHAR_T ucChannelNum;       ///< GPIO List length
    BOOL_T bPolarity;           ///< PWM output polarity
    BOOL_T bCCTFlag;           ///< CCT drive mode flag
}USER_PWM_INIT_T;

typedef struct 
{
    USHORT_T duty_channel_1;       
    USHORT_T duty_channel_2;      
    USHORT_T duty_channel_3;       
    USHORT_T duty_channel_1_old;       
    USHORT_T duty_channel_2_old;       
    USHORT_T duty_channel_3_old;
}USER_PWM_DUTY_T;

typedef enum
{
    channel_1 = 0,
    channel_2,
    channel_3,
}PWM_CHANNEL;

OPERATE_RET app_pwm_init(VOID);

OPERATE_RET app_pwm_set(PWM_CHANNEL channel, USHORT_T duty);

OPERATE_RET app_pwm_off(VOID);

#endif