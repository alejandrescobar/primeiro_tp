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

void carregar_arquivos(listaPacotes* lista , const char *nome_do_arquivo, int *pmax)
{   
    float peso_maximo_drone;
    int numero_de_pacotes;
    FILE *arquivo;
    char linha[MAX_linhas];

    arquivo =fopen(nome_do_arquivo,"r");

    if (arquivo == NULL)
    {
        printf("deu erro ao abrir");
        return;
    }

        fgets(linha,MAX_linhas,arquivo);//armazena o primeiro valor da linha(pesomaximodrone)
        linha[strcspn(linha, "\n")] = 0;//tira a quebra de linha
        peso_maximo_drone =atof(linha);
        *pmax = peso_maximo_drone;
        fgets(linha,MAX_linhas,arquivo);//le a segunda linha com numero de pacotes
        linha[strcspn(linha, "\n")] = 0;
        numero_de_pacotes=atoi(linha);// atof convert para o tipo int o conteudo das linhas 
       
        for (int i = 0;i<numero_de_pacotes;i++){

        dadospacote novo_pacote;
        char *conteudo_str;
        char *destinatario_str;
        char *peso_str;
        char *distancia_str;
        // variaveis para receber os vaores do arquivo 
        
        fgets(linha, MAX_linhas, arquivo);//ler linhas do pacote
        linha[strcspn(linha, "\n")] = 0;

    if (strlen(linha)>0){

        conteudo_str = strtok(linha, " ");
        destinatario_str = strtok(NULL," ");
        peso_str = strtok(NULL," ");
        distancia_str = strtok(NULL," ");
// estamos pegando cada segmento de linha e separando em cada variavel , usando o espaço como requisito de quebra 
        float peso_convertido = atof(peso_str);
        float distancia_convertida = atof(distancia_str);//convertendo de char para float 

        strncpy(novo_pacote.conteudo ,conteudo_str,sizeof(novo_pacote.conteudo)-1);//strncpy precisa de 3 parametros destino, conteudo,e o tamanho
        strncpy(novo_pacote.destinatario,destinatario_str,sizeof(novo_pacote.destinatario)-1);
        novo_pacote.peso = peso_convertido;
        novo_pacote.distancia = distancia_convertida;     //estamos passando o valor direto , se fosse ponteiro teriamos que usar as setinhas             
        InserePacoteFinal(lista,&novo_pacote);
        
        

    
                        }
                    }

    fclose(arquivo);
}