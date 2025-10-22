#include "combinacoes.h"
#include "lista_de_pacotes.h"
#include <stdio.h>
#include <stdlib.h>

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
    
    int melhor_indice=-0;
    int maior_prioridade=0;

    for (int i=0;i<total_combinacoes;i++)
    {
        if(vetor_combinacoes[i].peso_combinacao<peso_max && vetor_combinacoes[i].usada != 1)
        {   
            for (int j = 0 ; j<vetor_combinacoes->tamanho;j ++)
            {
                if (vetor_combinacoes[j].entrega==1 )
                {   
                    
                }
            }
            if (vetor_combinacoes[i].soma_prioridade>maior_prioridade)
            {
                maior_prioridade=vetor_combinacoes->soma_prioridade;
                melhor_indice = i;
            }
        }

    }
        return melhor_indice;

}


listaPacotes organiza(combinacao* vetor_combinacoes, int total_combinacoes, int peso_max){
    listaPacotes lista;
    CrialistaVazia(&lista);
    for(int i = 0; i < total_combinacoes; i++){
        int temp = melhor_combinacao(peso_max);
        int temp2 = vetor_combinacoes[temp].tamanho;
        for(int i = 0; i < temp2; i++){
            if(vetor_combinacoes[temp].lista[i]->entregue != 1){
                vetor_combinacoes[temp].lista[i]->entregue = 1;
                lista.primeiro->prox->pacote = *(vetor_combinacoes[temp].lista[i]);
        }
    }
    return lista;
}