#include "lista_de_pacotes.h"
#include "dados_pacote.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    dadospacote ximenespacotudo;
    inicializa_pacote(&ximenespacotudo, "remedio", "GuelaDoJhon", 1.8, 2);
    listaPacotes maiorespacotudos;

    CrialistaVazia(&maiorespacotudos);
    InserePacoteFinal(&maiorespacotudos, &ximenespacotudo);
    ImprimeLista(&maiorespacotudos);

    return 0;
}