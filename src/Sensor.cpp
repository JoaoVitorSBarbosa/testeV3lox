#include "../include/Sensor.h"

Sensor::Sensor(uint8 pin, uint8_t adress) {
    this->pin = pin;

    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
    delay(70);

    sensor.setAddress(adress);

    isWorking = sensor.init();
    sensor.startContinuous();
    sensor.setTimeout(500);
    sensor.setMeasurementTimingBudget(2000);
    timeout = false;
}

uint16_t Sensor::ler() {
    uint16_t measure = 0;

    measure = sensor.readRangeContinuousMillimeters();
    timeout = sensor.timeoutOccurred();
    return measure;
    
}

bool Sensor::getIsWorking() {
    return isWorking;
}