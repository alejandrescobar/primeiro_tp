#include <stdio.h>
#include "lista_de_pacotes.h"
#include "dados_pacote.h"
#include <stdlib.h>
#define max_linha 256
#include "galpao.h"
#include "Tad_Drone.h"

int main()
{


    
    
listaPacotes lista;
CrialistaVazia(&lista);

int *pesomax = (int*) malloc(sizeof(int));
carregar_arquivos(&lista,"teste1.txt", pesomax);


Galpao gal;

inicializar_galpao(&gal);

receber_pacotes(&gal, &lista);

Drone dronadas;
InicializaDrone(&dronadas, *pesomax);
imprimeDrone(&dronadas);


 return 1 ;
}