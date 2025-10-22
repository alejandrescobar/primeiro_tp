#include "combinacoes.h"
#include "lista_de_pacotes.h"
#include <stdio.h>
#include <stdlib.h>
#include <galpao.h>

combinacao vetor_combinacoes[10000];
int total_combinacoes = 0;

// Vetor temporario usado na recursao
dadospacote* combinacao_atual[MAX_PACOTES];

// Inicializa armazenamento de combinacoes
void inicializar_combinacoes() {
    total_combinacoes = 0;
}

// Função recursiva para gerar combinações com filtro de peso
void gerar_combinacoes(dadospacote* pacotes[], int n, int k, int inicio, int indice, float peso_max) {
    if (indice == k) {
        float peso_total = 0;
        for (int i = 0; i < k; i++)
            peso_total += combinacao_atual[i]->peso;

        if (peso_total <= peso_max && total_combinacoes < 10000) {
            // Salva combinacao no vetor global
            combinacao *c = &vetor_combinacoes[total_combinacoes++];
            c->tamanho = k;
            c->peso_combinacao = peso_total;
            c->soma_prioridade = 0;

            for (int i = 0; i < k; i++) {
                c->lista[i] = combinacao_atual[i];
                c->soma_prioridade += combinacao_atual[i]->prioridade;
            }
        }
        return;
    }

    for (int i = inicio; i < n; i++) {
        combinacao_atual[indice] = pacotes[i];
        gerar_combinacoes(pacotes, n, k, i + 1, indice + 1, peso_max);
    }
}

// Função que gera todas as combinacoes de 1 até N pacotes
void gerar_todas_combinacoes(dadospacote* pacotes[], int n, float peso_max) {
    total_combinacoes = 0; // reinicia contagem
    for (int k = 1; k <= n; k++) {
        gerar_combinacoes(pacotes, n, k, 0, 0, peso_max);
    }
}

// Retorna ponteiro para todas as combinacoes geradas
combinacao* obter_combinacoes() {
    return vetor_combinacoes;
}


int melhor_combinacao(int peso_max)
{
    
    int melhor_indice=-1;
    int maior_prioridade=-1;

    for (int i=0;i<total_combinacoes;i++)
    {
        combinacao *aux = &vetor_combinacoes[i];
        if(aux->peso_combinacao<=peso_max && aux->usada !=1)
        {   
           int pacote_entregue;
            for (int j = 0 ; j <aux->tamanho;j ++)
            {
                if (aux->lista[j]->entregue==1)
                {   
                    pacote_entregue=1;
                    break;//sai desse j e verifica o prox
                }
             if(pacote_entregue==1)
             {  
                    continue;
             }   
            }
            if (aux->soma_prioridade>maior_prioridade)
            {
                maior_prioridade=vetor_combinacoes[i].soma_prioridade;
                melhor_indice = i;
            }
        }

    }
        return melhor_indice;

}
void enviar_galpao(combinacao* vetor_combinacoes,Galpao* galpao, dadospacote* pacotes[], int peso_max){
    int temp = melhor_combinacao(peso_max);
    int tam_combinacao = vetor_combinacoes[temp].tamanho;
    while(galpao->itens_galpao < tam_combinacao){
        vetor_combinacoes[temp].usada = 1;
        for(int i=0; i < vetor_combinacoes[temp].tamanho; i++){
            vetor_combinacoes[temp].lista[i]->entregue = 1;
            InserePacoteFinal(galpao,vetor_combinacoes[temp].lista[i]);
        }
        galpao->itens_galpao += tam_combinacao;
    }

