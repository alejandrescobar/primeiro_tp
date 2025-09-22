#include "../TADS/Tad_Drone.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função inicializa drone recebe um ponteiro do drone e um peso máximo que é lido dos arquivos
void InicializaDrone(Drone *drone, float peso_max){
    // Passa os valores para o drone
    drone->peso_max = peso_max;
    drone->peso_carregado = 0;
    drone->distanciaTotal_percorrida = 0;
    drone->total_pacotes = 0;
    drone->entregasDoDia = malloc(sizeof(listaPacotes));

    // Cria uma lista vazia do drone para as entregas a serem realizada
    CrialistaVazia(drone->entregasDoDia);
}

// Carrega Pacote adiciona pacotes do galpão ao drone
void CarregarPacote(Drone* drone, dadospacote* pacote){
    float pesoPacote = get_peso(pacote);

    // Verifica se o peso do pacote cabe no drone
    if(pesoPacote + drone->peso_carregado <= drone->peso_max){
        // Se couber é chamado a função para inserir pacote na lista de entregas do dia do drone
        InserePacoteFinal((drone->entregasDoDia), pacote);

        // Adiciona o peso do pacote ao peso carregado do drone
        drone->peso_carregado += pesoPacote;

        // Adiciona o total de pacotes possuido dentro do drone
        drone->total_pacotes++;
    } else {
        // Se não couber é exibido o erro 
        printf("A entrega para %s não cabe no drone\n", get_destinatario(pacote));
    }
}

// A função realizar entrega necessita de um parâmetro drone
void realizarEntrega(Drone *drone){
    // Cria uma variável temporária para chamar outra função
    dadospacote pacoteRemovido;

    // Remove o pacote do início da lista de entregas do dia 
    if(RemovePacoteInicio((drone->entregasDoDia), &pacoteRemovido)){
        printf("Entrega: \"%s\" para \"%s\"\n", 
                get_conteudo(&pacoteRemovido), 
                get_destinatario(&pacoteRemovido));

        // Atualiza peso carregado (removendo o peso do pacote entregue)
        drone->peso_carregado -= get_peso(&pacoteRemovido);
        drone->total_pacotes--;
    } else {
        printf("Não há pacotes para entregar!\n");
    }
}         

// Imprime os pacotes que existem dentro do drone usando a função ImprimeLista que recebe o atributo da lista do drone entregasDoDia
void imprimeDrone(Drone* drone){
    ImprimeLista((drone->entregasDoDia));
}
