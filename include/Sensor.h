#ifndef SENSOR_H
#define SENSOR_H

#include "./defines.h"


class Sensor {
    private:
        VL53L0X sensor;
        int pin;
        bool isWorking; 
        bool timeout;
    public:
        Sensor(uint8 pin, uint8_t adress);
        uint16_t ler();
        bool getIsWorking();
};

#endif