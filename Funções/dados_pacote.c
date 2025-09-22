#include <stdio.h>
#include "../TADS/dados_pacote.h"
#include <string.h>

void inicializa_pacote(dadospacote *dados,char *conteudo, char *destinatario,float peso, float distancia)
{
    strcpy(dados->conteudo, conteudo);// comecamos a preencher o conteudo com seus respectivos dados 
    strcpy(dados->destinatario,destinatario);
    dados->peso = peso;
    dados->distancia = distancia;
}
void set_conteudo(dadospacote *dados,char*conteudo){
    strcpy(dados->conteudo,conteudo);//serve para trocar o campo conteudo do dados pacote se necessario 
}

void set_destinatario(dadospacote *dados,char*destinatario)
{
    strcpy(dados->destinatario,destinatario);//serve para trocar o campo destinatario do dados pacote se necessario 
} 

void set_peso(dadospacote *dados,float peso)
{
    dados->peso = peso;//serve para trocar o campo peso do dados pacote se necessario 

}


void set_distancia(dadospacote *dados,float distancia)
{
    dados->distancia = distancia;//serve para trocar o campo destinatario do dados pacote se necessario 
}

char *get_conteudo(dadospacote *dados){
    return dados->conteudo; // serve para pegar o dados e retorna o valor conteudo
}

char *get_destinatario(dadospacote *dados){
    return dados->destinatario;// serve para retornar o destinatario 
}

float get_peso(dadospacote *dados){
    return dados->peso; // serve para retornar peso 
}

float get_distancia(dadospacote *dados){
    return dados->distancia;// serve para retornar a distancia 
}
