#include <stdio.h>
#include "lista_de_pacotes.h"
#include "dados_pacote.h"
#include <stdlib.h>
#define max_linha 256
#include "galpao.h"
#include "Tad_Drone.h"
#include <math.h>


int calcularDistanciaViagem(Drone *drone){

    int dist_viagem = 0;
    int ultima_dis = 0;

    apontador Aux = drone->entregasDoDia->primeiro->prox;
    while (Aux != NULL) {
            dist_viagem += fabs(Aux->pacote.distancia - ultima_dis);
            ultima_dis = Aux->pacote.distancia;
            Aux = Aux->prox;
    }
    dist_viagem += ultima_dis;
    return dist_viagem;
    
}


void Rota(Drone* drone){
    while(drone->entregasDoDia->primeiro->prox != NULL){
        realizarEntrega(drone);
    }
    //CrialistaVazia(drone->entregasDoDia); 
    drone->total_pacotes = 0;
    drone->peso_carregado = 0;
    
}

    



int main()
{

int VG = 0;

listaPacotes lista;
CrialistaVazia(&lista);

int *pesomax = (int*) malloc(sizeof(int));
carregar_arquivos(&lista,"teste2.txt", pesomax);


Galpao gal;

inicializar_galpao(&gal);

receber_pacotes(&gal, &lista);

Drone dronadas;
InicializaDrone(&dronadas, *pesomax);




while(gal.pacotesDia.primeiro->prox != NULL){
    while(gal.pacotesDia.primeiro->prox != NULL && (gal.pacotesDia.primeiro->prox->pacote.peso + dronadas.peso_carregado <= dronadas.peso_max)){
        dadospacote *a = carregar_drone(&gal);
        CarregarPacote(&dronadas, a);
    }

    VG++;
    printf("Viagem : %d\n", VG);
    Rota(&dronadas);
    }












 return 1 ;
}