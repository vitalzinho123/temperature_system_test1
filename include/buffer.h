#pragma once
#include "sensor.h"
 
#define TAMANHO_BUFFER 10
 
struct BufferSensor {
    DadosSensor leituras[TAMANHO_BUFFER];
    int head;
    int quantidade;
};
 
void buffer_inserir(BufferSensor* buffer, DadosSensor leitura);
float buffer_media_temperatura(const BufferSensor* buffer);
 