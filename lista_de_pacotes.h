<<<<<<< HEAD
#ifndef LISTA_PACOTES_H
#define LISTA_PACOTES_H
#include "dados_pacote.h"

typedef struct Celula* apontador;
typedef struct Celula {
    dadospacote pacote;
    struct Celula* prox;
}Celula;


typedef struct {
    apontador primeiro;
    apontador ultimo;
}listaPacotes;


void CrialistaVazia(listaPacotes* lista);
void InserePacoteFinal(listaPacotes* lista, dadospacote* pacote);
int RemovePacoteInicio( listaPacotes* lista, dadospacote *pacote);
void ImprimeLista(listaPacotes lista);


#endif 
=======
#include <stdio.h>
#include "dados_pacote.h"


typedef struct 
{
    dadospacote item;
    struct celula *proximo;
    
    
}celula;

typedef struct 
{
    celula* inicio;
    celula* fim;
}listadepacotes;


void inicializa_lista(listadepacotes *lista);

void insere_final(listadepacotes *lista,dadospacote pacote);

void mostrar_lista(listadepacotes *lista )
{


}
>>>>>>> 2f6a8e694acd382df9d89ece63c62dc3ecf2b53a
