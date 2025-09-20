#include <stdio.h>
#include <stdlib.h>
#include "lista_de_pacotes.h"
#include "string.h" 
#define MAX_linhas 256



void CrialistaVazia(listaPacotes* lista){ //recebe um ponteiro para lista para manipular os valores internos
    lista->primeiro=(apontador)malloc(sizeof(Celula)); // aloca a memoria para a primeira celula (cabeca)
    lista->ultimo = lista->primeiro; // agora o ultimo tem o valor da alocação da primeira 
    lista->primeiro->prox = NULL; // aqui o parametro que nos alocamos ou seja o conteudo do primeiro recebe um valor do tipo delula contendo um ponteiro para a proxima celula , e estamos falando que falor que ele aponta é null 
}       


void InserePacoteFinal(listaPacotes* lista, dadospacote *pacote ){
    lista->ultimo->prox = (apontador)malloc(sizeof(Celula)); // agora alocamos espaço para o ultimo prox tornando um celula
    lista->ultimo= lista->ultimo->prox;// o ultimo deixa de apontar para a cabeca , e comeca apontar para esse ultimo espaço alocado 
    lista->ultimo->pacote = *pacote; //coloca no valor do pacote da celula criada o conteudo passado no parametro 
    lista->ultimo->prox= NULL;
}

int RemovePacoteInicio( listaPacotes* lista, dadospacote *pacote){
    if (lista->primeiro->prox == NULL){ // aqui nos fazemos a verificação para ver se a lista esta ou nao vazia
        printf("ERRO LISTA VAZIA");
        return 0;
    }
    Celula* aux=lista->primeiro->prox;//criamos uma auxiliar para armazenar onde a cabeca esta apontando 
    *pacote= aux->pacote;//copia dos dados do pacote para a auxiliar 
    lista->primeiro->prox=aux->prox;//ajustando o primeiro para pular para o proximo apontando para o porximo do que a cabeca apontava 

    if(lista->primeiro->prox == NULL){
        lista->ultimo = lista->primeiro;//aqui nos garantimos que se a cabeca aponta para nulo , ou seja temos uma celula , o ultimo vai apontar para o primeiro (zerando a lista)
    }

    free(aux);// liberamos a memoria que estava acumulando o valor da antiga celula 
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