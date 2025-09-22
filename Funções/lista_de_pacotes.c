#include <stdio.h>
#include <stdlib.h>
#include "../TADS/lista_de_pacotes.h"
#include "string.h" 




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
    apontador pAux;//criamos um apontador
    pAux = lista->primeiro->prox; //o apontador ta recebendo a primeira celula que a cabeca esta apontando 
    while(pAux != NULL){//aqui nos estamos fazendo a verificação se o conteudo dela é nulo se for ele nao entra no laço e a lista chegou ao fim 
        printf("Conteudo: %s\n", pAux->pacote.conteudo);
        printf("Peso: %.2f\n", pAux->pacote.peso);
        printf("Destinatario: %s\n", pAux->pacote.destinatario);
        printf("Distancia: %f\n", pAux->pacote.distancia);
        printf("\n");
        pAux = pAux->prox;// fazemos o apontador ir para a proxima celula
    }

}

void carregar_arquivos(listaPacotes* lista , const char *nome_do_arquivo, float *pmax){   //os parametros vai receber um pontrito da lista , o nome do arquivo , em formato de ponteiro para podermos acessar , e um outro para armazenar o peso maximo 
   FILE *arquivo = fopen(nome_do_arquivo, "r");// estrutura padrão para ler arquivo apenas ler 
int numPacotes;// declaramos uma variavel para armazenar no numero de pacotes para ser base posteriormente no nosso laço de repetição 
fscanf(arquivo, "%f", pmax);// armazenamos o conteudo da primeira linha dentro da variavel pmax
fscanf(arquivo, "%d", &numPacotes);// armazenamos o valor da segunda linha para num de pacotes

for (int i = 0; i < numPacotes; i++) {// laço de repetição para armazenar a quantidade de pacotes em cada dado respectivo no pacote 
    dadospacote pacote;
    fscanf(arquivo, "%s %s %f %f",
          pacote.conteudo,
          pacote.destinatario,
          &pacote.peso,
          &pacote.distancia);

InserePacoteFinal(lista,&pacote);// adicionamos cada pacote individual na celula 
          

    // Aqui você faz o que quiser com o pacote
}
    fclose(arquivo);
}