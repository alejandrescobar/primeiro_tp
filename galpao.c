#include "galpao.h"
#include <stdio.h>
#include <stdlib.h>

void inicializar_galpao(Galpao* galpao){
    CrialistaVazia(&galpao->pacotesDia);
}

void receber_pacotes(Galpao* galpao, listaPacotes* lista){
    apontador aux = lista->primeiro;
    if(lista->primeiro == NULL){
        printf("A lista está vazia");
        return;
    } else{
        while(aux != NULL){
            InserePacoteFinal(&galpao, aux);
            aux = aux->prox;
        }
    }

}


dadospacote* carregar_drone(Galpao* galpao){

    dadospacote* pacoteRetirado = (dadospacote*) malloc(sizeof(dadospacote));

    RemovePacoteInicio(&galpao->pacotesDia, pacoteRetirado);
    return pacoteRetirado;
}

void imprimir_pacotesDoDia(Galpao* galpao){
    ImprimeLista(&galpao);
}