#include "../TADS/combinacoes.h"
#include "../TADS/lista_de_pacotes.h"
#include <stdio.h>
#include <stdlib.h>
#include "../TADS/galpao.h"

combinacao vetor_combinacoes[100000];
int total_combinacoes = 0;

// Vetor temporario usado na recursao
dadospacote* combinacao_atual[MAX_PACOTES];

// Inicializa armazenamento de combinacoes
void inicializar_combinacoes() {
    total_combinacoes = 0;
}

// Função recursiva para gerar combinações com filtro de peso
void gerar_combinacoes(dadospacote* pacotes, int n, int k, int inicio, int indice, float* peso_max) {
    if (indice == k) {
        float peso_total = 0;
        for (int i = 0; i < k; i++){
            peso_total += combinacao_atual[i]->peso;

        }
        if (peso_total <= *peso_max && total_combinacoes < 10000) {
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
        combinacao_atual[indice] = &pacotes[i];
        gerar_combinacoes(pacotes, n, k, i + 1, indice + 1, peso_max);
    }
}

// Função que gera todas as combinacoes de 1 até N pacotes
void gerar_todas_combinacoes(dadospacote* pacotes, int n, float* peso_max) {
    total_combinacoes = 0; // reinicia contagem
    for (int k = 1; k <= n; k++) {
        gerar_combinacoes(pacotes, n, k, 0, 0, peso_max);
    }
}

// Retorna ponteiro para todas as combinacoes geradas
combinacao* obter_combinacoes() {
    return vetor_combinacoes;
}


int melhor_combinacao(float* peso_max)
{
    
    int melhor_indice=-1;
    int maior_prioridade=-1;

    for (int i=0;i<total_combinacoes;i++)
    {
        combinacao *aux = &vetor_combinacoes[i];
        if(aux->peso_combinacao<=*peso_max && aux->usada !=1)
        {   
           int pacote_entregue = 0;
            for (int j = 0 ; j <aux->tamanho;j ++)
            {
                if (aux->lista[j]->entregue==1)
                {   
                    pacote_entregue=1;
                    break;//sai desse j e verifica o prox
                }
             
            }
            if(pacote_entregue==1)
             {  
                    continue;
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
void enviar_galpao(combinacao* vetor_combinacoes,Galpao* galpao, float* peso_max){
    while(1){ // Loop infinito para buscar todas as combinações possíveis
        int temp = melhor_combinacao(peso_max);
        
        // CORREÇÃO ESSENCIAL 1 (Ponto 2 de SegFault)
        if (temp == -1) {
            // Nenhuma combinação válida restante. Sai do loop.
            printf("\nBusca por combinacoes concluida.\n"); 
            break; 
        }

        // Se chegamos aqui, 'temp' é um índice válido (>= 0)
        combinacao *melhor_c = &vetor_combinacoes[temp];
        
        // 2. Marcar e mover pacotes:
        melhor_c->usada = 1; // Marca a combinação como usada
        
        int tam_combinacao = melhor_c->tamanho;
        
        for(int i = 0; i < tam_combinacao; i++){
            // 3. Marcar o pacote como entregue E mover para o galpão
            melhor_c->lista[i]->entregue = 1; 
            InserePacoteFinal(&galpao->pacotesDia, melhor_c->lista[i]);
            
            // O pacote já foi marcado como 'entregue' (1), o que é importante
            // para que 'melhor_combinacao' não o inclua em futuras combinações.
        }
        
        // 4. Atualiza o contador do galpão
        galpao->itens_galpao += tam_combinacao;
        
        // O loop continua, buscando a próxima melhor combinação não usada.
    }

}