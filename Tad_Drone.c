#include "Tad_Drone.h"
#include <stdio.h>
#include <stdlib.h>

void InicializaDrone(Drone *drone, int peso_max){
    drone->peso_max = peso_max;
    drone->peso_carregado = 0;
    drone->distanciaTotal_percorrida = 0;
    CrialistaVazia(drone->entregasDoDia);
}


void CarregarPacote(Drone* drone, dadospacote* pacote){
        InserePacoteFinal((drone->entregasDoDia), pacote);
        drone->peso_carregado += pacote->peso;
        drone->total_pacotes++;
    
}

void realizarEntrega(Drone *drone){
    dadospacote pacoteRemovido;
    RemovePacoteInicio((drone->entregasDoDia), &pacoteRemovido);
    printf("Entrega: \"%s\" para \"%s\"\n", pacoteRemovido.conteudo, pacoteRemovido.destinatario);
}         

void imprimeDrone(Drone* drone){
    ImprimeLista((drone->entregasDoDia));
}