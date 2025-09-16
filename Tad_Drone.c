#include "Tad_Drone.h"
#include <stdio.h>
#include <stdlib.h>

void InicializaDrone(Drone *drone, int peso_max){
    drone->peso_max = peso_max;
    drone->peso_carregado = 0;
    drone->distanciaTotal_percorrida = 0;
    CrialistaVazia(&drone->entregasDoDia);
}

void CarregarPacote(Drone *drone, int peso_max, int peso_carregado, Galpao* galpao){
    apontador aux = galpao->pacotesDia.primeiro;

    if(&galpao->pacotesDia.primeiro == NULL){

        printf("A lista esta vazia");
        return;
    }else{
        while(aux != NULL){
            if(drone->peso_carregado + &galpao->pacotesDia.primeiro->pacote.peso <= drone->peso_max){
                InserePacoteFinal(&drone->entregasDoDia, aux);
                aux = aux->prox;
                drone->peso_carregado += galpao->pacotesDia.primeiro->pacote.peso;
                carregar_drone(galpao);
            }
        }
    }

}