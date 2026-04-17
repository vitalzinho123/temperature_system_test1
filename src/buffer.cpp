#include <Arduino.h>
#include "buffer.h"
 
void buffer_inserir(BufferSensor* buffer, DadosSensor leitura) {
    buffer->leituras[buffer->head] = leitura;
    buffer->head = (buffer->head + 1) % TAMANHO_BUFFER;
    if (buffer->quantidade < TAMANHO_BUFFER) {
        buffer->quantidade += 1;
    }
}
 
float buffer_media_temperatura(const BufferSensor* buffer) {
    float soma_temperatura = 0.0;
 
    if (buffer->quantidade == 0) {
        return 0.0; // Evita divisão por zero
    }
 
    for (int i = 0; i < buffer->quantidade; i++) {
        soma_temperatura += buffer->leituras[i].temperatura;
    }
 
    return soma_temperatura / buffer->quantidade;
}
 