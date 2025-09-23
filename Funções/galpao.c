#include "../TADS/galpao.h"
#include <stdio.h>
#include <stdlib.h>

void inicializar_galpao(Galpao* galpao){  
    CrialistaVazia(&galpao->pacotesDia);            // Cria uma lista vazia para o galpao 
}

void receber_pacotes(Galpao* galpao, listaPacotes* lista){     //Recebe os pacotes contidos na lista de pacotes e transfere para a lista galpão 
    apontador aux = lista->primeiro->prox;                     // Adiociona uma variavel auxiliar contendo o primeiro elemento da lista de pacotes     
    if(lista->primeiro == NULL){                                // Caso a lista recebida esteja vazia, não há pacotes para transferir
        printf("A lista está vazia");
        return;                                                 
    } else{ 
        while(aux != NULL){                                     
            InserePacoteFinal(&galpao->pacotesDia, &aux->pacote);       // faz a inserção do pacote na lista do galpão 
            aux = aux->prox;                                            // avança para o próximo pacote 
        }
    }

}


dadospacote* carregar_drone(Galpao* galpao){ // Cria uma função do tipo dados pacotes que remove o primeiro pacote da lista galpão e retorna o pacote removido  

    if(galpao->pacotesDia.primeiro->prox == NULL){ // Se não existir nenhum pacote existente no galpao, retorna NULL
        return NULL;                                        
    }

    dadospacote* pacoteRetirado = (dadospacote*) malloc(sizeof(dadospacote)); //  Aloca memória para armazenar o pacote que será retirado

    RemovePacoteInicio(&galpao->pacotesDia, pacoteRetirado);     // Remove o primeiro pacote do galpão e copia seus dados para 'pacoteRetirado' 
    return pacoteRetirado; 
}

void imprimir_pacotesDoDia(Galpao* galpao){
    ImprimeLista(&galpao->pacotesDia);          // Imprime todos os pacotes armazenados no galpão 
}