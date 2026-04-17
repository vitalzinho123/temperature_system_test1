#pragma once
 
#define LIMITE_TEMPERATURA 30.0f
 
struct DadosSensor {
    float temperatura;
};
 
struct ValoresAlerta {
    bool alerta_temperatura;
};
 
DadosSensor ler_sensor();
ValoresAlerta alerta_sensor(float temperatura);