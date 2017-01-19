/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : LEDpin1.c
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
**          Component name                                 : LEDpin1
**          SDK                                            : MCUC1
**          GPIO Name                                      : GPIOA
**          PORT Name                                      : PORTA
**          Pin Number                                     : 13
**          Pin Symbol                                     : LED_RED
**          Do Pin Muxing                                  : yes
**     Contents    :
**         GetDir    - bool LEDpin1_GetDir(void);
**         SetDir    - void LEDpin1_SetDir(bool Dir);
**         SetInput  - void LEDpin1_SetInput(void);
**         SetOutput - void LEDpin1_SetOutput(void);
**         GetVal    - bool LEDpin1_GetVal(void);
**         PutVal    - void LEDpin1_PutVal(bool Val);
**         ClrVal    - void LEDpin1_ClrVal(void);
**         SetVal    - void LEDpin1_SetVal(void);
**         NegVal    - void LEDpin1_NegVal(void);
**         Init      - void LEDpin1_Init(void);
**         Deinit    - void LEDpin1_Deinit(void);
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
** @file LEDpin1.c
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup LEDpin1_module LEDpin1 module documentation
**  @{
*/         

/* MODULE LEDpin1. */

#include "LEDpin1.h"
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  #include "fsl_port.h" /* include SDK header file for port muxing */
  #include "fsl_gpio.h" /* include SDK header file for GPIO */
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  #include "fsl_gpio_driver.h" /* include SDK header file for GPIO */
#else
  #error "This component only works with the Kinetis SDK!"
#endif

#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  #define LEDpin1_PORTName   PORTA /* name of PORT, is pointer to PORT_Type */
  #define LEDpin1_GPIOName   GPIOA /* name of GPIO, is pointer to GPIO_Type */
  #define LEDpin1_PinNumber  13u   /* number of pin, type unsigned integer */

  static const gpio_pin_config_t LEDpin1_configOutput = {
    kGPIO_DigitalOutput,  /* use as output pin */
    1,  /* initial value */
  };

  static const gpio_pin_config_t LEDpin1_configInput = {
    kGPIO_DigitalInput,  /* use as input pin */
    0,  /* initial value */
  };
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  const gpio_output_pin_user_config_t LEDpin1_OutputConfig[] = {
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

  const gpio_input_pin_user_config_t LEDpin1_InputConfig[] = {
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

static bool LEDpin1_isOutput = false;
/*
** ===================================================================
**     Method      :  LEDpin1_ClrVal (component SDK_BitIO)
**     Description :
**         Clears the pin value (sets it to a low level)
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin1_ClrVal(void)
{
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  GPIO_ClearPinsOutput(LEDpin1_GPIOName, 1<<LEDpin1_PinNumber);
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_ClearPinOutput(LED_RED);
#endif
}

/*
** ===================================================================
**     Method      :  LEDpin1_SetVal (component SDK_BitIO)
**     Description :
**         Sets the pin value to a high value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin1_SetVal(void)
{
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  GPIO_SetPinsOutput(LEDpin1_GPIOName, 1<<LEDpin1_PinNumber);
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_SetPinOutput(LED_RED);
#endif
}

/*
** ===================================================================
**     Method      :  LEDpin1_NegVal (component SDK_BitIO)
**     Description :
**         Toggles/negates the pin value
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin1_NegVal(void)
{
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  GPIO_TogglePinsOutput(LEDpin1_GPIOName, 1<<LEDpin1_PinNumber);
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_TogglePinOutput(LED_RED);
#endif
}

/*
** ===================================================================
**     Method      :  LEDpin1_GetVal (component SDK_BitIO)
**     Description :
**         Returns the pin value
**     Parameters  : None
**     Returns     :
**         ---             - Returns the value of the pin:
**                           FALSE/logical level '0' or TRUE/logical
**                           level '1'
** ===================================================================
*/
bool LEDpin1_GetVal(void)
{
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  return GPIO_ReadPinInput(LEDpin1_GPIOName, LEDpin1_PinNumber)!=0;
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  return GPIO_DRV_ReadPinInput(LED_RED)!=0;
#else
  return FALSE;
#endif
}

/*
** ===================================================================
**     Method      :  LEDpin1_GetDir (component SDK_BitIO)
**     Description :
**         Return the direction of the pin (input/output)
**     Parameters  : None
**     Returns     :
**         ---             - FALSE if port is input, TRUE if port is
**                           output
** ===================================================================
*/
bool LEDpin1_GetDir(void)
{
  return LEDpin1_isOutput;
}

/*
** ===================================================================
**     Method      :  LEDpin1_SetDir (component SDK_BitIO)
**     Description :
**         Sets the direction of the pin (input or output)
**     Parameters  :
**         NAME            - DESCRIPTION
**         Dir             - FALSE: input, TRUE: output
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin1_SetDir(bool Dir)
{
  if (Dir) {
    LEDpin1_SetOutput();
  } else {
    LEDpin1_SetInput();
  }
}

/*
** ===================================================================
**     Method      :  LEDpin1_SetInput (component SDK_BitIO)
**     Description :
**         Sets the pin as input
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin1_SetInput(void)
{
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  GPIO_PinInit(LEDpin1_GPIOName, LEDpin1_PinNumber, &LEDpin1_configInput);
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_SetPinDir(LED_RED, kGpioDigitalInput);
#endif
  LEDpin1_isOutput = false;
}

/*
** ===================================================================
**     Method      :  LEDpin1_SetOutput (component SDK_BitIO)
**     Description :
**         Sets the pin as output
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin1_SetOutput(void)
{
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  GPIO_PinInit(LEDpin1_GPIOName, LEDpin1_PinNumber, &LEDpin1_configOutput);
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_SetPinDir(LED_RED, kGpioDigitalOutput);
#endif
  LEDpin1_isOutput = true;
}

/*
** ===================================================================
**     Method      :  LEDpin1_PutVal (component SDK_BitIO)
**     Description :
**         Sets the pin value
**     Parameters  :
**         NAME            - DESCRIPTION
**         Val             - Value to set. FALSE/logical '0' or
**                           TRUE/logical '1'
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin1_PutVal(bool Val)
{
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  if (Val) {
    GPIO_SetPinsOutput(LEDpin1_GPIOName, 1<<LEDpin1_PinNumber);
  } else {
    GPIO_ClearPinsOutput(LEDpin1_GPIOName, 1<<LEDpin1_PinNumber);
  }
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  GPIO_DRV_WritePinOutput(LED_RED, Val);
#endif
}

/*
** ===================================================================
**     Method      :  LEDpin1_Init (component SDK_BitIO)
**     Description :
**         Driver initialization method
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin1_Init(void)
{
#if MCUC1_CONFIG_NXP_SDK_2_0_USED
  #if LEDpin1_CONFIG_DO_PIN_MUXING
  PORT_SetPinMux(LEDpin1_PORTName, LEDpin1_PinNumber, kPORT_MuxAsGpio); /* mux as GPIO */
  #endif
  LEDpin1_SetOutput();
#elif MCUC1_CONFIG_SDK_VERSION_USED == MCUC1_CONFIG_SDK_KINETIS_1_3
  /*! \todo Pin Muxing not implemented */
  GPIO_DRV_Init(LEDpin1_InputConfig, LEDpin1_OutputConfig);
#endif
}

/*
** ===================================================================
**     Method      :  LEDpin1_Deinit (component SDK_BitIO)
**     Description :
**         Driver de-initialization method
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void LEDpin1_Deinit(void)
{
  /* nothing needed */
}

/* END LEDpin1. */

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
