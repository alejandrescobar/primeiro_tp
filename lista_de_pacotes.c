#include <stdio.h>
#include <stdlib.h>
#include "lista_de_pacotes.h"

<<<<<<< HEAD
void CrialistaVazia(listaPacotes* lista){
    lista->primeiro=(apontador)malloc(sizeof(Celula));
    lista->ultimo = lista->primeiro;
    lista->primeiro->prox=NULL;
}

void InserePacoteFinal(listaPacotes* lista, dadospacote *pacote ){
    lista->ultimo->prox = (apontador)malloc(sizeof(Celula));
    lista->ultimo= lista->ultimo->prox;
    lista->ultimo->pacote = *pacote;
    lista->ultimo->prox= NULL;
}

int RemovePacoteInicio( listaPacotes* lista, dadospacote *pacote){
    if (lista->primeiro==lista->ultimo){
        return 0;
    }
    Celula* aux=lista->primeiro->prox;
    *pacote= aux->pacote;
    lista->primeiro->prox=aux->prox;
    free(aux);
    return 1; 
}

void ImprimeLista(listaPacotes lista){

