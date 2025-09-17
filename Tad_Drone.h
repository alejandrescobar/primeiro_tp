#ifndef TAD_DRONE_H
#define TAD_DRONE_H
#include "lista_de_pacotes.h"
#include "galpao.h"

typedef struct {
    int peso_max;
    int peso_carregado;
    int distanciaTotal_percorrida;
    listaPacotes* entregasDoDia;
}Drone;



void InicializaDrone(Drone* drone, int peso_max);
void CarregarPacote(Drone *drone, dadospacote* pacote);
void realizarEntrega(Drone *drone);
void imprimeDrone(Drone *drone);









#endif