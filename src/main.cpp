/*

******************************************
*                                        *
*    Código para teste de VL53L0x        *
*                                        *
*    Autor: João Vitor Santos Barbosa    *
*                                        *
******************************************

*/


//Recomenda-se o uso do  ST-link + PIO Debug

#include "../include/defines.h"
#include "../include/Sensor.h"

Sensor* Sensores[SENSOR_QTDY];
uint8 SensorXsuhts[SENSOR_QTDY] = {XSHUT};
unsigned char SensorAdresses[SENSOR_QTDY] = {ADRSS};

void setup() {
    Wire.begin();
    Serial.begin(9600);

     for (int i = 0; i < SENSOR_QTDY; i++) {
        Sensores[i] = new Sensor(SensorXsuhts[i], SensorAdresses[i]);
    }
    
}

void loop() {
    uint16_t dist[SENSOR_QTDY] = {0};
    for (int sensor = 0; sensor < SENSOR_QTDY; sensor++) {
        dist[sensor] = Sensores[sensor]->ler();
    }
    delay(100);
}
