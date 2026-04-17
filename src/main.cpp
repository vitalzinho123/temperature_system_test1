#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
 
#include "sensor.h"
#include "buffer.h"
 
const int pinoBarramento = 4;
OneWire barramento(pinoBarramento);
DallasTemperature sensores(&barramento);
 
void setup() {
    sensores.begin();
    Serial.begin(115200);
}
 
void loop() {
    static BufferSensor bufferSensor = {0};
    static DadosSensor dadosSensor;
    static unsigned long ultimaLeitura = millis();
 
    if (millis() - ultimaLeitura >= 2000) {
        sensores.requestTemperatures();
        dadosSensor = ler_sensor();
        buffer_inserir(&bufferSensor, dadosSensor);
        ultimaLeitura = millis();
 
        if (dadosSensor.temperatura == DEVICE_DISCONNECTED_C) {
            Serial.println("Erro: Não foi possível conectar ao sensor de temperatura");
            return;
        }
 
        if (dadosSensor.temperatura == 85) {
            Serial.println("Erro: Leitura do sensor inválida");
            return;
        }
 
        float media_temperatura = buffer_media_temperatura(&bufferSensor);
 
        Serial.print("Temperatura: ");
        Serial.print(media_temperatura);
        Serial.println(" °C");
 
        ValoresAlerta valoresAlerta = alerta_sensor(media_temperatura);
 
        if (valoresAlerta.alerta_temperatura) {
            Serial.println("Alerta: A temperatura está acima do limite!");
        }
    }
}