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
void ImprimeLista(listaPacotes *lista);

void carregar_arquivos(listaPacotes* lista,const char *nome_arquivo, float *pmax );

#endif 