#ifndef TAD_DRONE_H
#define TAD_DRONE_H
#include "lista_de_pacotes.h"
#define PESOMAX 15000

typedef struct {
    float peso_max = PESOMAX;
    float peso_carregado;
    float distanciaTotal_percorrida;
    listaPacotes* listaDePacotes;
}Drone;


void InicializaDrone(Drone* drone, float PesoMAX);
void CarregarPacote();










#endif