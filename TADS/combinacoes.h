#define MAX_PACOTES 50
#include "dados_pacote.h"
#include "galpao.h"


typedef struct {
    dadospacote* lista[MAX_PACOTES];
    int tamanho; 
    int usada;       // quantos pacotes nessa combinação
    int soma_prioridade; // soma das prioridades
    int peso_combinacao;
    
} combinacao;

void gerar_combinacoes(dadospacote* pacotes, int n, int k, int inicio, int indice, float* peso_max);
void gerar_todas_combinacoes(dadospacote* pacotes, int n, float* peso_max);
void inicializar_combinacoes();
combinacao* obter_combinacoes();
int achar_combinacao();
void enviar_galpao(combinacao* vetor_combinacoes ,Galpao* galpao, float* peso_max);

