#include "galpao.h"
#include <stdio.h>
#include <stdlib.h>

void inicializar_galpao(Galpao* galpao){
    CrialistaVazia(&galpao->pacotesDia);
}

void receber_pacotes(Galpao* galpao, listaPacotes* lista){
    apontador aux = lista->primeiro->prox;
    if(lista->primeiro == NULL){
        printf("A lista está vazia");
        return;
    } else{
        while(aux != NULL){
            InserePacoteFinal(&galpao->pacotesDia, &aux->pacote);
            aux = aux->prox;
        }
    }

}


dadospacote* carregar_drone(Galpao* galpao){

    if(galpao->pacotesDia.primeiro->prox == NULL){
        return NULL;
    }

    dadospacote* pacoteRetirado = (dadospacote*) malloc(sizeof(dadospacote));

    RemovePacoteInicio(&galpao->pacotesDia, pacoteRetirado);
    return pacoteRetirado;
}

void imprimir_pacotesDoDia(Galpao* galpao){
    ImprimeLista(&galpao->pacotesDia);
}