//Raspberry Pi Pico SCD41 Demo
//Device: RP2040, SCD41
//File: main.c
//Author: Mike Kushnerik
//Date: 7/4/2022

//based on "scd4x_i2c_example_usage.c" from Sensirion
//https://github.com/Sensirion/embedded-i2c-scd4x

//I2C Bus Wiring (default):
//SDA = GP4
//SCL = GP5
//see sensirion_i2c_hal_init(void) in "sensirion_i2c_hal.c" to change from default

#include <stdio.h>
#include "scd4x_i2c.h"
#include "sensirion_common.h"
#include "sensirion_i2c_hal.h"
#include "pico/stdlib.h"

int main() 
{
    stdio_init_all();

    sensirion_i2c_hal_init();

    scd4x_wake_up();
    scd4x_stop_periodic_measurement();
    scd4x_reinit();

    int16_t error = scd4x_start_periodic_measurement();
    if (error) 
    {
        printf("Error executing scd4x_start_periodic_measurement(): %i\n", error);
    }

    printf("Waiting for first measurement... (5 sec)\n");
    printf("\n");

    sleep_ms(5000);

    while(1)
    {
        uint16_t co2;
        int32_t temperature;
        int32_t humidity;

        error = scd4x_read_measurement(&co2, &temperature, &humidity);

        if (error) 
        {
            printf("Error executing scd4x_read_measurement(): %i\n", error);
        }
        else if (co2 == 0)
        {
            printf("Invalid sample detected, skipping.\n");
        }
        else
        {
            printf("CO2: %u ppm\n", co2);
            printf("Temperature: %.2f C\n", temperature / 1000.0);
            printf("Humidity: %.2f %%\n", humidity / 1000.0);
            printf("\n");
        }

        sleep_ms(5000);
    }

    return 0;
}