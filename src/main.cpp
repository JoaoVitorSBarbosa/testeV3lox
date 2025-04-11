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

Sensor* sensor;

void setup() {
    Wire.begin();
    Serial.begin(9600);
    sensor = new Sensor(XSHUT, ADRSS);
    
}

void loop() {
    uint16 dist = sensor->ler();
    delay(100);
}
