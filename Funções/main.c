#include <stdio.h>
#include "../TADS/lista_de_pacotes.h"
#include "../TADS/dados_pacote.h"
#include <stdlib.h>
#define max_linha 256
#include "../TADS/galpao.h"
#include "../TADS/Tad_Drone.h"
#include <math.h>


// Define aqui a função para calcular a distancia de cada viagem feita pelo drone
int calcularDistanciaViagem(Drone *drone){

    // Variáveis para armazenar valores do calculo
    float dist_viagem = 0;
    float ultima_dis = 0;

    // Aqui é colocado um apontador auxiliar  da primeira entrega do drone
    apontador Aux = drone->entregasDoDia->primeiro->prox;
    // Um laço de repetição para percorrer a lista de entregas dentro do drone enquando houver pacotes
    while (Aux != NULL) {
            dist_viagem += fabs(Aux->pacote.distancia - ultima_dis); // Aqui é feito um calculo usando a função fabs que transforma valores negativos em positivos
            ultima_dis = Aux->pacote.distancia; // É atualizado a ultima distancia para o qual o drone percorreu
            Aux = Aux->prox; // É passado a auxiliar para o próximo item da lista para que consiga percorrer a lista
    }
    dist_viagem += ultima_dis; // É feito o calculo da distancia em que o drone está até a base
    return dist_viagem; // A função retorna a distancia percorrida daquele viagem
    
}


void Rota(Drone* drone){ // Define a função para inicializar a rota do drone, realizando as entregas
    int DistanciaViagem = calcularDistanciaViagem(drone); // A distância da viagem é calculada com a função criada acima e armazenada em uma variável
    while(drone->entregasDoDia->primeiro->prox != NULL){ // Laço de repetição para percorrer cada item que está dentro do drone
        realizarEntrega(drone); // Chama a função de realizar entrega
    }
    printf("Distancia total: %dkm\n", DistanciaViagem); // Printa printa a distância total da viagem

    drone->total_pacotes = 0; // Zera os atributos do drone para que ele esteja pronto para fazer uma nova rota de entregas
    drone->peso_carregado = 0; // Zera os atributos do drone para que ele esteja pronto para fazer uma nova rota de entregas
    
}

    



int main()
{

// Inicializa as variáveis que receberão a distância total percorrida no dia e o número de viagens 
int DistanciaTotal = 0;
int VG = 0;

// Crioa uma variável do tipo listaPacotes
listaPacotes lista;
CrialistaVazia(&lista); // Uso a função para incializar uma lista vazia

// Passa o peso máximo que vou obter na função carregar_arquivo
float *pesomax = (float*) malloc(sizeof(float));
carregar_arquivos(&lista,"teste2.txt", pesomax);
// Inicializa o galpão
Galpao gal;
inicializar_galpao(&gal);
// Usa a função para receber os pacotes, passando a lista de pacotes carregadas nos arquivos para o galpão de entregas do dia
receber_pacotes(&gal, &lista);


// Inicializa o drone
Drone dronadas;

InicializaDrone(&dronadas, *pesomax);

// Cria uma lista auxiliar para guardar os itens que não poderão ser entregues
listaPacotes pacotesRemovidos;
CrialistaVazia(&pacotesRemovidos);

//  É feitonum laço de repetição para gerenciar o sistema de entregasw
while(gal.pacotesDia.primeiro->prox != NULL){ // Laço de repetição para percorrer o galpão
    // Faço a verificação para ver se o galpão está vazio e para ver se o pacote que vai ser adicionado na rota de entregas do drone cabe dentro do drone
    while(gal.pacotesDia.primeiro->prox != NULL && (gal.pacotesDia.primeiro->prox->pacote.peso + dronadas.peso_carregado <= dronadas.peso_max)){
        // Se couber,a função carrega_drone para remover do galpão e adicionar no drone
        dadospacote *a = carregar_drone(&gal);
        CarregarPacote(&dronadas, a);
    }


    // Faço uma condicional para desviar o fluxo se o drone estiver vazio
        if(dronadas.entregasDoDia->primeiro->prox == NULL){
            // Se o drone estiver vazio e o galpão também, o if pula o resto do laço e sai dele
            if(gal.pacotesDia.primeiro->prox == NULL){
            continue;
            }else{
            // Se o drone estiver vazio e ainda tiver um item no galpão, significa que o item que está no galpão excede o peso máximo do drone
            // Com isso ele é retirado do galpão e enviado para uma lista auxiliar de pacotesRemovidos 
            dadospacote* pacoteRetirado = (dadospacote*) malloc(sizeof(dadospacote));
            RemovePacoteInicio(&gal.pacotesDia, pacoteRetirado);
            
            InserePacoteFinal(&pacotesRemovidos, pacoteRetirado);

            free(pacoteRetirado);
            }
        // O peso do drone é resetado;
        dronadas.peso_carregado = 0;
        // O resto do laço é pulado
        continue;
    }
    // Se o código chegou até aqui, significa que será realizada uma viagem, então é incrementado variável de viagens 
    VG++;
    // Adiciona a distância da viagem à variável de distância percorrida no dia
    DistanciaTotal += calcularDistanciaViagem(&dronadas);
    printf("\nViagem : %d\n", VG);
    // A função Rota é chamada para realizar as entregas
    Rota(&dronadas);
    }
printf("\nTotal de Quilômetros Percorridos no Dia: %dkm\n", DistanciaTotal);

// Verifica se algum pacote foi devolvido devido ao excesso de peso, se for é exibido o nome dos destinatários que tiveram seus pacotes devolvidos
if(pacotesRemovidos.primeiro->prox != NULL){
    printf("\n---------------------------\n \n");
    printf("Os seguintes pacotes foram devolvidos devido ao\npeso exceder o peso suportado pelo drone\n \n");
    apontador AuxRemovidos = pacotesRemovidos.primeiro->prox;
    while(AuxRemovidos != NULL){
    printf("O pacote de %s\n", AuxRemovidos->pacote.destinatario);
    AuxRemovidos = AuxRemovidos->prox;

}
}

// Libera memória da variável alocada para o peso máximo
free(pesomax);
 return 1 ;
}
