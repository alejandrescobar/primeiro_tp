#include "../TADS/Tad_Drone.h"
#include <stdio.h>
#include <stdlib.h>






// Função inicializa drone recebe um ponteiro do drone e um peso máximo que é lido dos arquivos
void InicializaDrone(Drone *drone, float peso_max){
    // Passa os valores para o drone
    drone->peso_max = peso_max;
    drone->peso_carregado = 0;
    drone->distanciaTotal_percorrida = 0;
    drone->entregasDoDia = malloc(sizeof(listaPacotes));
    // Cria uma lista vazia do drone para as entregas a serem realizada
    CrialistaVazia(drone->entregasDoDia);
}

// Carrega Pacote adiciona pacotes do galpão ao drone
void CarregarPacote(Drone* drone, dadospacote* pacote){
    // Verifica se o peso do pacote cabe no drone
    if(pacote->peso + drone->peso_carregado <= drone->peso_max){
        // Se couber é chamado a função para inserir pacote na lista de entregas do dia do drone
        InserePacoteFinal((drone->entregasDoDia), pacote);
        // Adiciona o peso do pacote ao peso carregado do drone
        drone->peso_carregado += pacote->peso;
        // Adiciona o total de pacotes possuido dentro do drone
        drone->total_pacotes++;
    } else{
        //Se não couber é exibido o erro 
        printf("A entrega do %s não cabe no drone", pacote->destinatario);
    }
    
}

// A função realizar entrega necessita de um parâmetro drone
void realizarEntrega(Drone *drone){
    // Cria uma variável temporária para chamar outra função
    dadospacote pacoteRemovido;
    // Remove o pacote do ínicio da lista de entregas do dia 
    RemovePacoteInicio((drone->entregasDoDia), &pacoteRemovido);
    
    printf("Entrega: \"%s\" para \"%s\"\n", pacoteRemovido.conteudo, pacoteRemovido.destinatario);
}         


// Imprime os pacotes que existem dentro do drone usando a função ImprimeLista que recebe o atributo da lista do drone entregasDoDia
void imprimeDrone(Drone* drone){
    ImprimeLista((drone->entregasDoDia));
}