# Microbit-HHS
Arduino examples for the BBC Microbit v1.5

Some examples are borrowed from the libraries below and adapted to work with Microbit v1.5 hardware.

The Adafruit_Microbit library only supports V1.3 hardware (to this date: July 1, 2019)
The LSM303AGR library supports Microbit v1.5 hardware

Dependencies:

https://github.com/adafruit/Adafruit_Microbit

https://github.com/stm32duino/LSM303AGR


Original file contents:

# LSM303AGR
Arduino library to support the LSM303AGR 3D accelerometer and 3D magnetometer

## API

This sensor uses I2C to communicate. It is then required to create a TwoWire interface before accessing to the sensors:  

    dev_i2c = new TwoWire(I2C2_SDA, I2C2_SCL);  
    dev_i2c->begin();  

An instance can be created and enbaled following the procedure below:  

    Acc = new LSM303AGR_ACC_Sensor(dev_i2c);
    Acc->Enable();
    Mag = new LSM303AGR_MAG_Sensor(dev_i2c);  
    Mag->Enable();  

The access to the sensor values is done as explained below:  

  Read accelerometer and magnetometer.  

    Acc->GetAxes(accelerometer);
    Mag->GetAxes(magnetometer);  

## Documentation

You can find the source files at  
https://github.com/stm32duino/LSM303AGR

The LSM303AGR datasheet is available at  
http://www.st.com/content/st_com/en/products/mems-and-sensors/e-compasses/lsm303agr.html
