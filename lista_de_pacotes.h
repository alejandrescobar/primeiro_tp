#include <stdio.h>
#include "dados_pacote.h"


typedef struct 
{
    dadospacote item;
    struct celula *proximo;
    
    
}celula;

typedef struct 
{
    celula* inicio;
    celula* fim;
}listadepacotes;


void inicializa_lista(listadepacotes *lista);

void insere_final(listadepacotes *lista,dadospacote pacote);

void mostrar_lista(listadepacotes *lista )
{


}