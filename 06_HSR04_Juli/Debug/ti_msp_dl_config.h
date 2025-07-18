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



/* Defines for PWM_0 */
#define PWM_0_INST                                                         TIMG6
#define PWM_0_INST_IRQHandler                                   TIMG6_IRQHandler
#define PWM_0_INST_INT_IRQN                                     (TIMG6_INT_IRQn)
#define PWM_0_INST_CLK_FREQ                                              4000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_0_C0_PORT                                                 GPIOB
#define GPIO_PWM_0_C0_PIN                                          DL_GPIO_PIN_2
#define GPIO_PWM_0_C0_IOMUX                                      (IOMUX_PINCM15)
#define GPIO_PWM_0_C0_IOMUX_FUNC                     IOMUX_PINCM15_PF_TIMG6_CCP0
#define GPIO_PWM_0_C0_IDX                                    DL_TIMER_CC_0_INDEX
/* GPIO defines for channel 1 */
#define GPIO_PWM_0_C1_PORT                                                 GPIOA
#define GPIO_PWM_0_C1_PIN                                         DL_GPIO_PIN_22
#define GPIO_PWM_0_C1_IOMUX                                      (IOMUX_PINCM47)
#define GPIO_PWM_0_C1_IOMUX_FUNC                     IOMUX_PINCM47_PF_TIMG6_CCP1
#define GPIO_PWM_0_C1_IDX                                    DL_TIMER_CC_1_INDEX



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





/* Port definition for Pin Group GPIO_LED */
#define GPIO_LED_PORT                                                    (GPIOB)

/* Defines for PIN_LED_1: GPIOB.22 with pinCMx 50 on package pin 21 */
#define GPIO_LED_PIN_LED_1_PIN                                  (DL_GPIO_PIN_22)
#define GPIO_LED_PIN_LED_1_IOMUX                                 (IOMUX_PINCM50)
/* Port definition for Pin Group GPIO_KEY */
#define GPIO_KEY_PORT                                                    (GPIOB)

/* Defines for PIN_KEY_S1: GPIOB.21 with pinCMx 49 on package pin 20 */
#define GPIO_KEY_PIN_KEY_S1_PIN                                 (DL_GPIO_PIN_21)
#define GPIO_KEY_PIN_KEY_S1_IOMUX                                (IOMUX_PINCM49)
/* Port definition for Pin Group GPIO_OLED */
#define GPIO_OLED_PORT                                                   (GPIOA)

/* Defines for PIN_SCL: GPIOA.13 with pinCMx 35 on package pin 6 */
#define GPIO_OLED_PIN_SCL_PIN                                   (DL_GPIO_PIN_13)
#define GPIO_OLED_PIN_SCL_IOMUX                                  (IOMUX_PINCM35)
/* Defines for PIN_SDA: GPIOA.12 with pinCMx 34 on package pin 5 */
#define GPIO_OLED_PIN_SDA_PIN                                   (DL_GPIO_PIN_12)
#define GPIO_OLED_PIN_SDA_IOMUX                                  (IOMUX_PINCM34)
/* Port definition for Pin Group GPIO_Encoder */
#define GPIO_Encoder_PORT                                                (GPIOB)

/* Defines for PIN_A: GPIOB.16 with pinCMx 33 on package pin 4 */
// groups represented: ["GPIO_HSR04","GPIO_Encoder"]
// pins affected: ["PIN_Echo","PIN_A"]
#define GPIO_MULTIPLE_GPIOB_INT_IRQN                            (GPIOB_INT_IRQn)
#define GPIO_MULTIPLE_GPIOB_INT_IIDX            (DL_INTERRUPT_GROUP1_IIDX_GPIOB)
#define GPIO_Encoder_PIN_A_IIDX                             (DL_GPIO_IIDX_DIO16)
#define GPIO_Encoder_PIN_A_PIN                                  (DL_GPIO_PIN_16)
#define GPIO_Encoder_PIN_A_IOMUX                                 (IOMUX_PINCM33)
/* Defines for PIN_B: GPIOB.17 with pinCMx 43 on package pin 14 */
#define GPIO_Encoder_PIN_B_PIN                                  (DL_GPIO_PIN_17)
#define GPIO_Encoder_PIN_B_IOMUX                                 (IOMUX_PINCM43)
/* Port definition for Pin Group GPIO_HSR04 */
#define GPIO_HSR04_PORT                                                  (GPIOB)

/* Defines for PIN_Trig: GPIOB.24 with pinCMx 52 on package pin 23 */
#define GPIO_HSR04_PIN_Trig_PIN                                 (DL_GPIO_PIN_24)
#define GPIO_HSR04_PIN_Trig_IOMUX                                (IOMUX_PINCM52)
/* Defines for PIN_Echo: GPIOB.25 with pinCMx 56 on package pin 27 */
#define GPIO_HSR04_PIN_Echo_IIDX                            (DL_GPIO_IIDX_DIO25)
#define GPIO_HSR04_PIN_Echo_PIN                                 (DL_GPIO_PIN_25)
#define GPIO_HSR04_PIN_Echo_IOMUX                                (IOMUX_PINCM56)



/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_0_init(void);
void SYSCFG_DL_TIMER_0_init(void);
void SYSCFG_DL_TIMER_HSR04_init(void);
void SYSCFG_DL_UART_0_init(void);

void SYSCFG_DL_SYSTICK_init(void);

bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
