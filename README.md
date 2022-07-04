# Raspberry Pi Pico Sensirion SCD4x C Library
This is a simple port of the [Sensirion provided SCD4x embedded driver](https://github.com/Sensirion/embedded-i2c-scd4x) over to the Raspberry Pi Pico

# Wiring
By default, the SCD4x I2C pins are configured for GP4 (SDA) and GP5 (SCL). This can be changed inside the "sensirion_i2c_hal.c" file

# Demo Program
A simple demo program is given inside "main.c" which prints the CO2, Temperature, and Humidity values to a serial terminal of your choice using printf. By default, this is configured to use USB but can be changed to use UART by modifying the "CMakeLists.txt" file
