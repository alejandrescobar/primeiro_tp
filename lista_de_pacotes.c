#include <stdio.h>
#include <stdlib.h>
#include "lista_de_pacotes.h"


void inicializa_lista(listadepacotes *lista)
{
    lista->inicio = NULL;
    lista->fim =NULL;

}


void insere_final(listadepacotes *lista,dadospacote pacote)
{
    celula *novacelula =(celula*) malloc(sizeof(celula));//separa o tamanho da celula
    
//preenchendo a celula 
    novacelula-> item = pacote;
    novacelula->proximo=NULL;

    if (lista->inicio==NULL)    //se a lista tiver fazia inicia 
    {
        lista->inicio = novacelula; 
        lista->fim = novacelula;   //conectando a celula a lista

    }
    else
    {
        lista->fim->proximo= novacelula; //o antigo novo aponta para ultimo
        lista->fim = novacelula; //novo se torna ultimo

    }
}