/***********************************************************************************************//**
 * \file xensiv_dps3xx_mtb.h
 *
 * Description: This file contains ModusToolbox specific public interface for the XENSIV DPS3xx
 * pressure sensors.
 ***************************************************************************************************
 * \copyright
 * Copyright 2021 Cypress Semiconductor Corporation
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 **************************************************************************************************/

#pragma once

/**
 * \addtogroup group_board_libs Pressure Sensor
 * \{
 */

#include "cy_result.h"
#include "xensiv_dps3xx.h"
#if defined(CY_USING_HAL)
#include "cyhal_i2c.h"

#pragma once

#if defined(__cplusplus)
extern "C" {
#endif

/** Initialize the DPS sensor, and configures it to use the specified I2C peripheral.
 * By default it is configured in command mode.
 *
 * This is equivalent to \ref xensiv_dps3xx_init_i2c() but automatically sets up the function
 * pointers based on the provided I2C HAL object.
 *
 * @param[out]  obj         Pointer to an pressure sensor object. The caller must allocate the
 * memory for this object but the init function will initialize its contents.
 * @param[in]   i2c         Pointer to an initialized I2C object.
 * @param[in]   i2c_addr    I2C address to use when communicating with the sensor.
 * @return CY_RSLT_SUCCESS if properly initialized, else an error indicating what went wrong.
 */
cy_rslt_t xensiv_dps3xx_mtb_init_i2c(xensiv_dps3xx_t* obj, cyhal_i2c_t* i2c,
                                     xensiv_dps3xx_i2c_addr_t i2c_addr);

#if defined(__cplusplus)
}
#endif

#endif // defined(CY_USING_HAL)

/** \} group_board_libs */
