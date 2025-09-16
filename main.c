#include <stdio.h>
#include "lista_de_pacotes.h"
#include "dados_pacote.h"
#define max_linha 256
int main()
{
    
listaPacotes lista ;
CrialistaVazia(&lista);


carregar_arquivos(&lista,"teste1.txt");
ImprimeLista(&lista);

printf("olá mundo");


 return 1 ;
}