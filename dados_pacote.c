#include <stdio.h>
#include "dados_pacote.h"


void inicializa_pacote(dadospacote *dados,char *conteudo, char *destinatario,float peso, float distancia)
{
    strcpy(dados->conteudo, conteudo);
    strcpy(dados->destinatario,destinatario);
    dados->peso = peso;
    dados->distancia = distancia;
}
    void set_conteudo(dadospacote *dados,char*conteudo)
    {
        strcpy(dados->conteudo,conteudo);
    }

    void set_destinatario(dadospacote *dados,char*destinatario)
    {
        strcpy(dados->destinatario,destinatario);
    } 

    void set_peso(dadospacote *dados,float peso)
    {
        dados->peso = peso;

    }


    void set_distancia(dadospacote *dados,float distancia)
    {
        dados->distancia = distancia;
    }

    char *get_conteudo(dadospacote *dados)
    {
        return dados->conteudo;
    }

    char *get_destinatario(dadospacote *dados)
    {
        return dados->destinatario;
    }

    float get_peso(dadospacote *dados)
    {
        return dados->peso;
    }

    float get_distancia(dadospacote *dados)
    {
        return dados->distancia;
    }




