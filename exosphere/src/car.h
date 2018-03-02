#ifndef EXOSPHERE_CLOCK_AND_RESET_H
#define EXOSPHERE_CLOCK_AND_RESET_H

#include <stdint.h>

#include "memory_map.h"

/* Exosphere Driver for the Tegra X1 Clock and Reset registers. */

#define CAR_BASE (MMIO_GET_DEVICE_ADDRESS(MMIO_DEVID_CLKRST))

#define MAKE_CAR_REG(n) (*((volatile uint32_t *)(CAR_BASE + n)))

#define NUM_CAR_BANKS 7

typedef enum {
    CARDEVICE_UARTA = 6,
    CARDEVICE_UARTB = 7,
    CARDEVICE_I2C1 = 12,
    CARDEVICE_I2C5 = 47,
    CARDEVICE_BPMP = 1
} car_device_t;

void clk_enable(car_device_t dev);
void clk_disable(car_device_t dev);
void rst_enable(car_device_t dev);
void rst_disable(car_device_t dev);

void clkrst_enable(car_device_t dev);
void clkrst_disable(car_device_t dev);

void clkrst_reboot(car_device_t dev);

#endif