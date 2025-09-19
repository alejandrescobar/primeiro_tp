#include <stdio.h>
#include <stdlib.h>
#include "lista_de_pacotes.h"
#include "string.h" 
#define MAX_linhas 256



void CrialistaVazia(listaPacotes* lista){
    lista->primeiro=(apontador)malloc(sizeof(Celula));
    lista->ultimo = lista->primeiro;
    lista->primeiro->prox = NULL;
}       


void InserePacoteFinal(listaPacotes* lista, dadospacote *pacote ){
    lista->ultimo->prox = (apontador)malloc(sizeof(Celula));
    lista->ultimo= lista->ultimo->prox;
    lista->ultimo->pacote = *pacote;
    lista->ultimo->prox= NULL;
}

int RemovePacoteInicio( listaPacotes* lista, dadospacote *pacote){
    if (lista->primeiro->prox == NULL){
        printf("ERRO LISTA VAZIA");
        return 0;
    }
    Celula* aux=lista->primeiro->prox;
    *pacote= aux->pacote;
    lista->primeiro->prox=aux->prox;

    if(lista->primeiro->prox == NULL){
        lista->ultimo = lista->primeiro;
    }

    free(aux);
    return 1; 
}

void ImprimeLista(listaPacotes *lista){
    apontador pAux;
    pAux = lista->primeiro->prox;
    while(pAux != NULL){
        printf("Conteudo: %s\n", pAux->pacote.conteudo);
        printf("Peso: %.2f\n", pAux->pacote.peso);
        printf("Destinatario: %s\n", pAux->pacote.destinatario);
        printf("Distancia: %f\n", pAux->pacote.distancia);
        printf("\n");
        pAux = pAux->prox;
    }

}

void carregar_arquivos(listaPacotes* lista , const char *nome_do_arquivo, float *pmax){   
   FILE *arquivo = fopen(nome_do_arquivo, "r");
int numPacotes;
fscanf(arquivo, "%f", pmax);
fscanf(arquivo, "%d", &numPacotes);

for (int i = 0; i < numPacotes; i++) {
    dadospacote pacote;
    fscanf(arquivo, "%s %s %f %f",
          pacote.conteudo,
          pacote.destinatario,
          &pacote.distancia,
          &pacote.peso);

InserePacoteFinal(lista,&pacote);
          

    // Aqui você faz o que quiser com o pacote
}
    fclose(arquivo);
}