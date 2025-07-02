/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X
#define CONFIG_MSPM0G3507

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)



#define CPUCLK_FREQ                                                     32000000



/* Defines for TimerA1_PWM */
#define TimerA1_PWM_INST                                                   TIMA1
#define TimerA1_PWM_INST_IRQHandler                             TIMA1_IRQHandler
#define TimerA1_PWM_INST_INT_IRQN                               (TIMA1_INT_IRQn)
#define TimerA1_PWM_INST_CLK_FREQ                                        4000000
/* GPIO defines for channel 0 */
#define GPIO_TimerA1_PWM_C0_PORT                                           GPIOB
#define GPIO_TimerA1_PWM_C0_PIN                                    DL_GPIO_PIN_4
#define GPIO_TimerA1_PWM_C0_IOMUX                                (IOMUX_PINCM17)
#define GPIO_TimerA1_PWM_C0_IOMUX_FUNC               IOMUX_PINCM17_PF_TIMA1_CCP0
#define GPIO_TimerA1_PWM_C0_IDX                              DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_TimerA1_PWM_C1_PORT                                           GPIOB
#define GPIO_TimerA1_PWM_C1_PIN                                    DL_GPIO_PIN_5
#define GPIO_TimerA1_PWM_C1_IOMUX                                (IOMUX_PINCM18)
#define GPIO_TimerA1_PWM_C1_IOMUX_FUNC               IOMUX_PINCM18_PF_TIMA1_CCP1
#define GPIO_TimerA1_PWM_C1_IDX                              DL_TIMER_CC_1_INDEX



/* Defines for TIMER_0 */
#define TIMER_0_INST                                                     (TIMG0)
#define TIMER_0_INST_IRQHandler                                 TIMG0_IRQHandler
#define TIMER_0_INST_INT_IRQN                                   (TIMG0_INT_IRQn)
#define TIMER_0_INST_LOAD_VALUE                                         (62499U)
/* Defines for TIMER_HSR04 */
#define TIMER_HSR04_INST                                                 (TIMA0)
#define TIMER_HSR04_INST_IRQHandler                             TIMA0_IRQHandler
#define TIMER_HSR04_INST_INT_IRQN                               (TIMA0_INT_IRQn)
#define TIMER_HSR04_INST_LOAD_VALUE                                     (24999U)




/* Defines for I2C_MPU6050 */
#define I2C_MPU6050_INST                                                    I2C1
#define I2C_MPU6050_INST_IRQHandler                              I2C1_IRQHandler
#define I2C_MPU6050_INST_INT_IRQN                                  I2C1_INT_IRQn
#define I2C_MPU6050_BUS_SPEED_HZ                                          400000
#define GPIO_I2C_MPU6050_SDA_PORT                                          GPIOA
#define GPIO_I2C_MPU6050_SDA_PIN                                  DL_GPIO_PIN_16
#define GPIO_I2C_MPU6050_IOMUX_SDA                               (IOMUX_PINCM38)
#define GPIO_I2C_MPU6050_IOMUX_SDA_FUNC                IOMUX_PINCM38_PF_I2C1_SDA
#define GPIO_I2C_MPU6050_SCL_PORT                                          GPIOA
#define GPIO_I2C_MPU6050_SCL_PIN                                  DL_GPIO_PIN_17
#define GPIO_I2C_MPU6050_IOMUX_SCL                               (IOMUX_PINCM39)
#define GPIO_I2C_MPU6050_IOMUX_SCL_FUNC                IOMUX_PINCM39_PF_I2C1_SCL


/* Defines for UART_0 */
#define UART_0_INST                                                        UART0
#define UART_0_INST_FREQUENCY                                           32000000
#define UART_0_INST_IRQHandler                                  UART0_IRQHandler
#define UART_0_INST_INT_IRQN                                      UART0_INT_IRQn
#define GPIO_UART_0_RX_PORT                                                GPIOA
#define GPIO_UART_0_TX_PORT                                                GPIOA
#define GPIO_UART_0_RX_PIN                                        DL_GPIO_PIN_11
#define GPIO_UART_0_TX_PIN                                        DL_GPIO_PIN_10
#define GPIO_UART_0_IOMUX_RX                                     (IOMUX_PINCM22)
#define GPIO_UART_0_IOMUX_TX                                     (IOMUX_PINCM21)
#define GPIO_UART_0_IOMUX_RX_FUNC                      IOMUX_PINCM22_PF_UART0_RX
#define GPIO_UART_0_IOMUX_TX_FUNC                      IOMUX_PINCM21_PF_UART0_TX
#define UART_0_BAUD_RATE                                                (115200)
#define UART_0_IBRD_32_MHZ_115200_BAUD                                      (17)
#define UART_0_FBRD_32_MHZ_115200_BAUD                                      (23)





/* Defines for ADC12_0 */
#define ADC12_0_INST                                                        ADC0
#define ADC12_0_INST_IRQHandler                                  ADC0_IRQHandler
#define ADC12_0_INST_INT_IRQN                                    (ADC0_INT_IRQn)
#define ADC12_0_ADCMEM_0                                      DL_ADC12_MEM_IDX_0
#define ADC12_0_ADCMEM_0_REF                     DL_ADC12_REFERENCE_VOLTAGE_VDDA
#define ADC12_0_ADCMEM_0_REF_VOLTAGE_V                                       3.3
#define GPIO_ADC12_0_C0_PORT                                               GPIOA
#define GPIO_ADC12_0_C0_PIN                                       DL_GPIO_PIN_27



/* Port definition for Pin Group GPIO_LED */
#define GPIO_LED_PORT                                                    (GPIOB)

/* Defines for PIN_LED_1: GPIOB.22 with pinCMx 50 on package pin 21 */
#define GPIO_LED_PIN_LED_1_PIN                                  (DL_GPIO_PIN_22)
#define GPIO_LED_PIN_LED_1_IOMUX                                 (IOMUX_PINCM50)
/* Port definition for Pin Group GPIO_BUZZ */
#define GPIO_BUZZ_PORT                                                   (GPIOB)

/* Defines for PIN_BUZZ_1: GPIOB.1 with pinCMx 13 on package pin 48 */
#define GPIO_BUZZ_PIN_BUZZ_1_PIN                                 (DL_GPIO_PIN_1)
#define GPIO_BUZZ_PIN_BUZZ_1_IOMUX                               (IOMUX_PINCM13)
/* Port definition for Pin Group GPIO_MPU6050 */
#define GPIO_MPU6050_PORT                                                (GPIOB)

/* Defines for PIN_INT: GPIOB.0 with pinCMx 12 on package pin 47 */
// groups represented: ["GPIO_Encoder","GPIO_MPU6050"]
// pins affected: ["PIN_LA","PIN_INT"]
#define GPIO_MULTIPLE_GPIOB_INT_IRQN                            (GPIOB_INT_IRQn)
#define GPIO_MULTIPLE_GPIOB_INT_IIDX            (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define GPIO_MPU6050_PIN_INT_IIDX                            (DL_GPIO_IIDX_DIO0)
#define GPIO_MPU6050_PIN_INT_PIN                                 (DL_GPIO_PIN_0)
#define GPIO_MPU6050_PIN_INT_IOMUX                               (IOMUX_PINCM12)
/* Port definition for Pin Group GPIO_KEY */
#define GPIO_KEY_PORT                                                    (GPIOB)

/* Defines for PIN_KEY_S1: GPIOB.21 with pinCMx 49 on package pin 20 */
#define GPIO_KEY_PIN_KEY_S1_PIN                                 (DL_GPIO_PIN_21)
#define GPIO_KEY_PIN_KEY_S1_IOMUX                                (IOMUX_PINCM49)
/* Defines for PIN_KEY_SW2: GPIOB.17 with pinCMx 43 on package pin 14 */
#define GPIO_KEY_PIN_KEY_SW2_PIN                                (DL_GPIO_PIN_17)
#define GPIO_KEY_PIN_KEY_SW2_IOMUX                               (IOMUX_PINCM43)
/* Defines for PIN_KEY_SW3: GPIOB.18 with pinCMx 44 on package pin 15 */
#define GPIO_KEY_PIN_KEY_SW3_PIN                                (DL_GPIO_PIN_18)
#define GPIO_KEY_PIN_KEY_SW3_IOMUX                               (IOMUX_PINCM44)
/* Defines for PIN_KEY_SW4: GPIOB.19 with pinCMx 45 on package pin 16 */
#define GPIO_KEY_PIN_KEY_SW4_PIN                                (DL_GPIO_PIN_19)
#define GPIO_KEY_PIN_KEY_SW4_IOMUX                               (IOMUX_PINCM45)
/* Defines for PIN_KEY_SW5: GPIOB.20 with pinCMx 48 on package pin 19 */
#define GPIO_KEY_PIN_KEY_SW5_PIN                                (DL_GPIO_PIN_20)
#define GPIO_KEY_PIN_KEY_SW5_IOMUX                               (IOMUX_PINCM48)
/* Port definition for Pin Group GPIO_Motor */
#define GPIO_Motor_PORT                                                  (GPIOB)

/* Defines for PIN_Motor_AIN1: GPIOB.13 with pinCMx 30 on package pin 1 */
#define GPIO_Motor_PIN_Motor_AIN1_PIN                           (DL_GPIO_PIN_13)
#define GPIO_Motor_PIN_Motor_AIN1_IOMUX                          (IOMUX_PINCM30)
/* Defines for PIN_Motor_AIN2: GPIOB.12 with pinCMx 29 on package pin 64 */
#define GPIO_Motor_PIN_Motor_AIN2_PIN                           (DL_GPIO_PIN_12)
#define GPIO_Motor_PIN_Motor_AIN2_IOMUX                          (IOMUX_PINCM29)
/* Defines for PIN_Motor_BIN1: GPIOB.26 with pinCMx 57 on package pin 28 */
#define GPIO_Motor_PIN_Motor_BIN1_PIN                           (DL_GPIO_PIN_26)
#define GPIO_Motor_PIN_Motor_BIN1_IOMUX                          (IOMUX_PINCM57)
/* Defines for PIN_Motor_BIN2: GPIOB.27 with pinCMx 58 on package pin 29 */
#define GPIO_Motor_PIN_Motor_BIN2_PIN                           (DL_GPIO_PIN_27)
#define GPIO_Motor_PIN_Motor_BIN2_IOMUX                          (IOMUX_PINCM58)
/* Port definition for Pin Group GPIO_OLED */
#define GPIO_OLED_PORT                                                   (GPIOA)

/* Defines for PIN_SCL: GPIOA.31 with pinCMx 6 on package pin 39 */
#define GPIO_OLED_PIN_SCL_PIN                                   (DL_GPIO_PIN_31)
#define GPIO_OLED_PIN_SCL_IOMUX                                   (IOMUX_PINCM6)
/* Defines for PIN_SDA: GPIOA.28 with pinCMx 3 on package pin 35 */
#define GPIO_OLED_PIN_SDA_PIN                                   (DL_GPIO_PIN_28)
#define GPIO_OLED_PIN_SDA_IOMUX                                   (IOMUX_PINCM3)
/* Defines for PIN_LA: GPIOB.14 with pinCMx 31 on package pin 2 */
#define GPIO_Encoder_PIN_LA_PORT                                         (GPIOB)
#define GPIO_Encoder_PIN_LA_IIDX                            (DL_GPIO_IIDX_DIO14)
#define GPIO_Encoder_PIN_LA_PIN                                 (DL_GPIO_PIN_14)
#define GPIO_Encoder_PIN_LA_IOMUX                                (IOMUX_PINCM31)
/* Defines for PIN_LB: GPIOA.15 with pinCMx 37 on package pin 8 */
#define GPIO_Encoder_PIN_LB_PORT                                         (GPIOA)
// groups represented: ["GPIO_HSR04","GPIO_Encoder"]
// pins affected: ["PIN_Echo","PIN_LB","PIN_RA","PIN_RB"]
#define GPIO_MULTIPLE_GPIOA_INT_IRQN                            (GPIOA_INT_IRQn)
#define GPIO_MULTIPLE_GPIOA_INT_IIDX            (DL_INTERRUPT_GROUP1_IIDX_GPIOA)
#define GPIO_Encoder_PIN_LB_IIDX                            (DL_GPIO_IIDX_DIO15)
#define GPIO_Encoder_PIN_LB_PIN                                 (DL_GPIO_PIN_15)
#define GPIO_Encoder_PIN_LB_IOMUX                                (IOMUX_PINCM37)
/* Defines for PIN_RA: GPIOA.1 with pinCMx 2 on package pin 34 */
#define GPIO_Encoder_PIN_RA_PORT                                         (GPIOA)
#define GPIO_Encoder_PIN_RA_IIDX                             (DL_GPIO_IIDX_DIO1)
#define GPIO_Encoder_PIN_RA_PIN                                  (DL_GPIO_PIN_1)
#define GPIO_Encoder_PIN_RA_IOMUX                                 (IOMUX_PINCM2)
/* Defines for PIN_RB: GPIOA.7 with pinCMx 14 on package pin 49 */
#define GPIO_Encoder_PIN_RB_PORT                                         (GPIOA)
#define GPIO_Encoder_PIN_RB_IIDX                             (DL_GPIO_IIDX_DIO7)
#define GPIO_Encoder_PIN_RB_PIN                                  (DL_GPIO_PIN_7)
#define GPIO_Encoder_PIN_RB_IOMUX                                (IOMUX_PINCM14)
/* Port definition for Pin Group GPIO_HSR04 */
#define GPIO_HSR04_PORT                                                  (GPIOA)

/* Defines for PIN_Trig: GPIOA.8 with pinCMx 19 on package pin 54 */
#define GPIO_HSR04_PIN_Trig_PIN                                  (DL_GPIO_PIN_8)
#define GPIO_HSR04_PIN_Trig_IOMUX                                (IOMUX_PINCM19)
/* Defines for PIN_Echo: GPIOA.9 with pinCMx 20 on package pin 55 */
#define GPIO_HSR04_PIN_Echo_IIDX                             (DL_GPIO_IIDX_DIO9)
#define GPIO_HSR04_PIN_Echo_PIN                                  (DL_GPIO_PIN_9)
#define GPIO_HSR04_PIN_Echo_IOMUX                                (IOMUX_PINCM20)



/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_TimerA1_PWM_init(void);
void SYSCFG_DL_TIMER_0_init(void);
void SYSCFG_DL_TIMER_HSR04_init(void);
void SYSCFG_DL_I2C_MPU6050_init(void);
void SYSCFG_DL_UART_0_init(void);
void SYSCFG_DL_ADC12_0_init(void);

void SYSCFG_DL_SYSTICK_init(void);

bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
