#include "Tad_Drone.h"
#include <stdio.h>
#include <stdlib.h>

void InicializaDrone(Drone *drone, int peso_max){
    drone->peso_max = peso_max;
    drone->peso_carregado = 0;
    drone->distanciaTotal_percorrida = 0;
    CrialistaVazia(&drone->entregasDoDia);
}


void CarregarPacote(Drone* drone, dadospacote* pacote){
    if(drone->peso_carregado + pacote->peso <= drone->peso_max){
        InserePacoteFinal(&(drone->entregasDoDia), pacote);
        drone->peso_carregado += pacote->peso;
    }
}