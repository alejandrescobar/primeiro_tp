#define MAX_PACOTES 50
#include "dados_pacote.h"



typedef struct {
    dadospacote* lista[MAX_PACOTES];
    int tamanho; 
    int usada;       // quantos pacotes nessa combinação
    int soma_prioridade; // soma das prioridades
    int peso_combinacao;
    
} combinacao;

void gerar_combinacoes(dadospacote* pacotes[], int n, int k, int inicio, int indice, float peso_max);
void inicializar_combinacoes();
combinacao* obter_combinacoes();
int achar_combinacao();