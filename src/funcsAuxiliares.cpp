#include "../include/funcsAuxiliares.h"

#include "../include/defines.h"

VL53L0X sensor[8];

uint8 sensorPins[8] = {XSHUT1, XSHUT2, XSHUT3, XSHUT4, XSHUT5, XSHUT6, XSHUT7, XSHUT8};
int sensorNum[8] = {0, 1, 2, 3, 4, 5, 6, 7};

FuncsAux::FuncsAux() {}

bool FuncsAux::init() {
    for (int i = 0; i < 8; i++) {
        digitalWrite(sensorPins[i], (i == sensorNum[i]));
        delay(10);
        sensor[i].setTimeout(500);
        sensor[i].setMeasurementTimingBudget(200000);
        if (!sensor[i].init()) {
            Serial.println("Não deu certo");
            return false;
        }
    }
    return true;
}

void FuncsAux::ler(uint16 data[]) {
    for(int i = 0; i < 8; i++) {
    digitalWrite(sensorPins[i], (i == sensorNum[i]));
    data[i] = sensor[i].readRangeSingleMillimeters();
        if (sensor[i].timeoutOccurred()) {
            Serial.println("TIMEOUT");
            if (!sensor[i].init()) {
                Serial.println("Parou");
            }
        }
    }