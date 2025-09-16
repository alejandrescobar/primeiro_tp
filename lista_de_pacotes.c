#include <stdio.h>
#include <stdlib.h>
#include "lista_de_pacotes.h"
#define MAX_linhas 256


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
}

void carregar_arquivos(listaPacotes* lista , const char *nome_do_arquivo)
{
    FILE *arquivo;
    char linha[MAX_linhas];

    arquivo =fopen(nome_do_arquivo,"r");

    if (arquivo == NULL)
    {
        printf("deu erro ao abrir");
        return;
    }

    while (fgets(linha,MAX_linhas,arquivo)!=NULL)
    {
        linha[strcspn(linha, "\n")] = 0;//considera a quebra de linha como 0 pois ta lendo tudo 

        if (strlen(linha)>0)
        {

        }


    }
}