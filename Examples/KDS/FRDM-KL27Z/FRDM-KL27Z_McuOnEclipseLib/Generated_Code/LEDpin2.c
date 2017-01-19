/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : LEDpin2.c
**     Project     : FRDM-KL27Z_McuOnEclipseLib
**     Processor   : MKL25Z128VLK4
**     Component   : SDK_BitIO
**     Version     : Component 01.019, Driver 01.00, CPU db: 3.00.000
**     Repository  : Legacy User Components
**     Compiler    : GNU C Compiler
**     Date/Time   : 2017-01-19, 17:19, # CodeGen: 4
**     Abstract    :
**
**     Settings    :
**          Component name                                 : LEDpin2
**          SDK                                            : MCUC1
**          GPIO Name                                      : GPIOB
**          PORT Name                                      : PORTB
**          Pin Number                                     : 18
**          Pin Symbol                                     : LED_RED
**          Do Pin Muxing                                  : yes
**     Contents    :
**         GetDir    - bool LEDpin2_GetDir(void);
**         SetDir    - void LEDpin2_SetDir(bool Dir);
**         SetInput  - void LEDpin2_SetInput(void);
**         SetOutput - void LEDpin2_SetOutput(void);
**         GetVal    - bool LEDpin2_GetVal(void);
**         PutVal    - void LEDpin2_PutVal(bool Val);
**         ClrVal    - void LEDpin2_ClrVal(void);
**         SetVal    - void LEDpin2_SetVal(void);
**         NegVal    - void LEDpin2_NegVal(void);
**         Init      - void LEDpin2_Init(void);
**         Deinit    - void LEDpin2_Deinit(void);
**
**     * Copyright (c) 2015-2017, Erich Styger
**      * Web:         https://mcuoneclipse.com
**      * SourceForge: https://sourceforge.net/projects/mcuoneclipse
**      * Git:         https://github.com/ErichStyger/McuOnEclipse_PEx
**      * All rights reserved.
**      *
**      * Redistribution and use in source and binary forms, with or without modification,
**      * are permitted provided that the following conditions are met:
**      *
**      * - Redistributions of source code must retain the above copyright notice, this list
**      *   of conditions and the following disclaimer.
**      *
**      * - Redistributions in binary form must reproduce the above copyright notice, this
**      *   list of conditions and the following disclaimer in the documentation and/or
**      *   other materials provided with the distribution.
**      *
**      * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**      * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**      * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**      * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**      * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**      * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**      * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**      * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**      * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**      * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
** ###################################################################*/
/*!
** @file LEDpin2.c
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup LEDpin2_module LEDpin2 module documentation
**  @{
*/         

/* MODULE LEDpin2. */

#include "LEDpin2.h"
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  #include "fsl_port.h" /* include SDK header file for port muxing */
  #include "fsl_gpio.h" /* include SDK header file for GPIO */
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  #include "fsl_gpio_driver.h" /* include SDK header file for GPIO */
#else
  #error "This component only works with the Kinetis SDK!"
#endif

#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  #define LEDpin2_PORTName   PORTB /* name of PORT, is pointer to PORT_Type */
  #define LEDpin2_GPIOName   GPIOB /* name of GPIO, is pointer to GPIO_Type */
  #define LEDpin2_PinNumber  18u   /* number of pin, type unsigned integer */

  static const gpio_pin_config_t LEDpin2_configOutput = {
    kGPIO_DigitalOutput,  /* use as output pin */
    1,  /* initial value */
  };

  static const gpio_pin_config_t LEDpin2_configInput = {
    kGPIO_DigitalInput,  /* use as input pin */
    0,  /* initial value */
  };
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  const gpio_output_pin_user_config_t LEDpin2_OutputConfig[] = {
    {
      .pinName = LED_RED,
      .config.outputLogic = 0,
    #if FSL_FEATURE_PORT_HAS_SLEW_RATE
      .config.slewRate = kPortSlowSlewRate,
    #endif
    #if FSL_FEATURE_PORT_HAS_OPEN_DRAIN
      .config.isOpenDrainEnabled = true,
    #endif
    #if FSL_FEATURE_PORT_HAS_DRIVE_STRENGTH
      .config.driveStrength = kPortLowDriveStrength,
    #endif
    },
    {
      .pinName = GPIO_PINS_OUT_OF_RANGE,
    }
  };

  const gpio_input_pin_user_config_t LEDpin2_InputConfig[] = {
    {
      .pinName = LED_RED,
    #if FSL_FEATURE_PORT_HAS_PULL_ENABLE
      .config.isPullEnable = true,
    #endif
    #if FSL_FEATURE_PORT_HAS_PULL_SELECTION
      .config.pullSelect = kPortPullDown,
    #endif
    #if FSL_FEATURE_PORT_HAS_PASSIVE_FILTER
      .config.isPassiveFilterEnabled = true,
    #endif
    #if FSL_FEATURE_PORT_HAS_DIGITAL_FILTER
      .config.isDigitalFilterEnabled = true,
    #endif
    #if FSL_FEATURE_GPIO_HAS_INTERRUPT_VECTOR
      .config.interrupt = kPortIntDisabled
    #endif
    },
    {
      .pinName = GPIO_PINS_OUT_OF_RANGE,
    }
  };

#endif

static bool LEDpin2_isOutput = false;
/*
** ===================================================================
**     Method      :  LEDpin2_ClrVal (component SDK_BitIO)
**     Description :
**         Clears the pin value (sets it to a low level)
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin2_ClrVal(void)
{
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  GPIO_ClearPinsOutput(LEDpin2_GPIOName, 1<<LEDpin2_PinNumber);
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_ClearPinOutput(LED_RED);
#endif
}

/*
** ===================================================================
**     Method      :  LEDpin2_SetVal (component SDK_BitIO)
**     Description :
**         Sets the pin value to a high value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin2_SetVal(void)
{
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  GPIO_SetPinsOutput(LEDpin2_GPIOName, 1<<LEDpin2_PinNumber);
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_SetPinOutput(LED_RED);
#endif
}

/*
** ===================================================================
**     Method      :  LEDpin2_NegVal (component SDK_BitIO)
**     Description :
**         Toggles/negates the pin value
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin2_NegVal(void)
{
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  GPIO_TogglePinsOutput(LEDpin2_GPIOName, 1<<LEDpin2_PinNumber);
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_TogglePinOutput(LED_RED);
#endif
}

/*
** ===================================================================
**     Method      :  LEDpin2_GetVal (component SDK_BitIO)
**     Description :
**         Returns the pin value
**     Parameters  : None
**     Returns     :
**         ---             - Returns the value of the pin:
**                           FALSE/logical level '0' or TRUE/logical
**                           level '1'
** ===================================================================
*/
bool LEDpin2_GetVal(void)
{
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  return GPIO_ReadPinInput(LEDpin2_GPIOName, LEDpin2_PinNumber)!=0;
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  return GPIO_DRV_ReadPinInput(LED_RED)!=0;
#else
  return FALSE;
#endif
}

/*
** ===================================================================
**     Method      :  LEDpin2_GetDir (component SDK_BitIO)
**     Description :
**         Return the direction of the pin (input/output)
**     Parameters  : None
**     Returns     :
**         ---             - FALSE if port is input, TRUE if port is
**                           output
** ===================================================================
*/
bool LEDpin2_GetDir(void)
{
  return LEDpin2_isOutput;
}

/*
** ===================================================================
**     Method      :  LEDpin2_SetDir (component SDK_BitIO)
**     Description :
**         Sets the direction of the pin (input or output)
**     Parameters  :
**         NAME            - DESCRIPTION
**         Dir             - FALSE: input, TRUE: output
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin2_SetDir(bool Dir)
{
  if (Dir) {
    LEDpin2_SetOutput();
  } else {
    LEDpin2_SetInput();
  }
}

/*
** ===================================================================
**     Method      :  LEDpin2_SetInput (component SDK_BitIO)
**     Description :
**         Sets the pin as input
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin2_SetInput(void)
{
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  GPIO_PinInit(LEDpin2_GPIOName, LEDpin2_PinNumber, &LEDpin2_configInput);
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_SetPinDir(LED_RED, kGpioDigitalInput);
#endif
  LEDpin2_isOutput = false;
}

/*
** ===================================================================
**     Method      :  LEDpin2_SetOutput (component SDK_BitIO)
**     Description :
**         Sets the pin as output
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin2_SetOutput(void)
{
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  GPIO_PinInit(LEDpin2_GPIOName, LEDpin2_PinNumber, &LEDpin2_configOutput);
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_SetPinDir(LED_RED, kGpioDigitalOutput);
#endif
  LEDpin2_isOutput = true;
}

/*
** ===================================================================
**     Method      :  LEDpin2_PutVal (component SDK_BitIO)
**     Description :
**         Sets the pin value
**     Parameters  :
**         NAME            - DESCRIPTION
**         Val             - Value to set. FALSE/logical '0' or
**                           TRUE/logical '1'
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin2_PutVal(bool Val)
{
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  if (Val) {
    GPIO_SetPinsOutput(LEDpin2_GPIOName, 1<<LEDpin2_PinNumber);
  } else {
    GPIO_ClearPinsOutput(LEDpin2_GPIOName, 1<<LEDpin2_PinNumber);
  }
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_WritePinOutput(LED_RED, Val);
#endif
}

/*
** ===================================================================
**     Method      :  LEDpin2_Init (component SDK_BitIO)
**     Description :
**         Driver initialization method
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin2_Init(void)
{
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  #if LEDpin2_CONFIG_DO_PIN_MUXING
  PORT_SetPinMux(LEDpin2_PORTName, LEDpin2_PinNumber, kPORT_MuxAsGpio); /* mux as GPIO */
  #endif
  LEDpin2_SetOutput();
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  /*! \todo Pin Muxing not implemented */
  GPIO_DRV_Init(LEDpin2_InputConfig, LEDpin2_OutputConfig);
#endif
}

/*
** ===================================================================
**     Method      :  LEDpin2_Deinit (component SDK_BitIO)
**     Description :
**         Driver de-initialization method
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin2_Deinit(void)
{
  /* nothing needed */
}

/* END LEDpin2. */

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
