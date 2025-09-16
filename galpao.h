#ifndef GALPAO_H
#define GALPAO_H
#include "lista_de_pacotes.h"

typedef struct{
    listaPacotes pacotesDia;
}Galpao;


void inicializar_galpao(Galpao* galpao);

void receber_pacotes(Galpao* galpao, listaPacotes* lista);
void carregar_drone(Galpao* galpao);
void imprimir_pacotesDoDia(Galpao* galpao);




#endif