# XENSIV DPS-310/368 Pressure Sensor

### Overview

This library provides functions for interfacing with the XENSIV DPS-310/368 Barometric Pressure Sensors. These are miniaturized digital barometric air pressure sensors with ultra-high precision (±2 cm) and a low current consumption, capable of measuring both pressure and temperature. The pressure sensor element is based on a capacitive sensing principle which guarantees high precision during temperature changes. This library can be setup to use the ModusToolbox HAL interface, or using user provided communication functions.

Sensor Website: https://www.infineon.com/cms/en/product/sensor/pressure-sensors/pressure-sensors-for-iot/

### Quick Start
Follow the steps below to create a simple application which outputs the
pressure and temperature data from the sensor to the UART
1. Create an empty application
2. Add this library to the application
3. Add retarget-io library using the Library Manager
4. Place following code in the main.c file.
5. Define I2C SDA and SCL as appropriate for your hardware/shield kit
```cpp
#include "cyhal.h"
#include "cybsp.h"
#include "cy_retarget_io.h"
#include "xensiv_dps3xx_mtb.h"

xensiv_dps3xx_t pressure_sensor;
cyhal_i2c_t i2c;
cyhal_i2c_cfg_t i2c_cfg = {
    .is_slave = false,
    .address = 0,
    .frequencyhal_hz = 400000
};

#define DPS_I2C_SDA (?) // Define me
#define DPS_I2C_SCL (?) // Define me

int main(void)
{
    cy_rslt_t result;

    /* Initialize the device and board peripherals */
    result = cybsp_init();
    CY_ASSERT(result == CY_RSLT_SUCCESS);

    __enable_irq();

    /* Initialize retarget-io to use the debug UART port */
    result = cy_retarget_io_init(CYBSP_DEBUG_UART_TX, CYBSP_DEBUG_UART_RX, CY_RETARGET_IO_BAUDRATE);
    CY_ASSERT(result == CY_RSLT_SUCCESS);

    /* Initialize i2c for pressure sensor */
    result = cyhal_i2c_init(&i2c, DPS_I2C_SDA, DPS_I2C_SCL, NULL);
    CY_ASSERT(result == CY_RSLT_SUCCESS);
    result = cyhal_i2c_configure(&i2c, &i2c_cfg);
    CY_ASSERT(result == CY_RSLT_SUCCESS);

    /* Initialize pressure sensor */
    result = xensiv_dps3xx_mtb_init_i2c(&pressure_sensor, &i2c, MTB_DPS3XX_I2C_ADDR_DEFAULT);
    CY_ASSERT(result == CY_RSLT_SUCCESS);

    for (;;)
    {
        /* Get the pressure and temperature data and print the results to the UART */
        float pressure, temperature;
        xensiv_dps3xx_read(&pressure_sensor, &pressure, &temperature);

        printf("Pressure   : %8f\r\n", pressure);
        printf("Temperature: %8f\r\n\r\n", temperature);

        cyhal_system_delay_ms(1000);
    }
}
```
6. Build the application and program the kit.

### More information

* [API Reference Guide](https://cypresssemiconductorco.github.io/sensor-xensiv-dps3xx/html/index.html)
* [Infineon Technologies](https://www.infineon.com)
* [Cypress Semiconductor GitHub](https://github.com/cypresssemiconductorco)
* [ModusToolbox](https://www.cypress.com/products/modustoolbox-software-environment)

---
© Infineon Technologies, 2021.
