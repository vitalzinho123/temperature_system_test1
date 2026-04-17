#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "sensor.h"
 
extern DallasTemperature sensores;
 
ValoresAlerta alerta_sensor(float temperatura) {
    ValoresAlerta valoresAlerta;
    valoresAlerta.alerta_temperatura = false;
 
    if (temperatura > LIMITE_TEMPERATURA) {
        valoresAlerta.alerta_temperatura = true;
    }
 
    return valoresAlerta;
}
 
DadosSensor ler_sensor() {
    DadosSensor dadosSensor;
    dadosSensor.temperatura = sensores.getTempCByIndex(0);
    return dadosSensor;
}
 