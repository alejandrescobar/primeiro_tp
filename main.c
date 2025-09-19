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
    int DistanciaViagem = calcularDistanciaViagem(drone);
    while(drone->entregasDoDia->primeiro->prox != NULL){
        realizarEntrega(drone);
    }
    printf("Distancia total: %dkm\n", DistanciaViagem);
    //CrialistaVazia(drone->entregasDoDia); 
    drone->total_pacotes = 0;
    drone->peso_carregado = 0;
    
}

    



int main()
{
int DistanciaTotal = 0;
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

listaPacotes pacotesRemovidos;
CrialistaVazia(&pacotesRemovidos);


while(gal.pacotesDia.primeiro->prox != NULL){
    while(gal.pacotesDia.primeiro->prox != NULL && (gal.pacotesDia.primeiro->prox->pacote.peso + dronadas.peso_carregado <= dronadas.peso_max)){
        dadospacote *a = carregar_drone(&gal);
        CarregarPacote(&dronadas, a);
    }



    if(dronadas.entregasDoDia->primeiro->prox == NULL){

    if(gal.pacotesDia.primeiro->prox == NULL){
        continue;
    }else{
        dadospacote* pacoteRetirado = (dadospacote*) malloc(sizeof(dadospacote));
        RemovePacoteInicio(&gal.pacotesDia, pacoteRetirado);

        InserePacoteFinal(&pacotesRemovidos, pacoteRetirado);

        free(pacoteRetirado);
    }
        
        dronadas.peso_carregado = 0;
        continue;
    }

    VG++;
    DistanciaTotal += calcularDistanciaViagem(&dronadas);
    printf("\nViagem : %d\n", VG);
    Rota(&dronadas);
    }
printf("\nTotal de Quilômetros Percorridos no Dia: %dkm\n", DistanciaTotal);


if(pacotesRemovidos.primeiro->prox != NULL){
    printf("\n---------------------------\n \n");
    printf("\033[1;31mOs seguintes pacotes foram devolvidos devido ao\npeso exceder o peso suportado pelo drone\033[0m\n \n");
    apontador AuxRemovidos = pacotesRemovidos.primeiro->prox;
    while(AuxRemovidos != NULL){
    printf("O pacote de %s\n", AuxRemovidos->pacote.destinatario);
    AuxRemovidos = AuxRemovidos->prox;
    free(AuxRemovidos);
}
}


free(pesomax);
 return 1 ;
}