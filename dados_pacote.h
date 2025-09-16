<<<<<<< HEAD

=======
#ifndef DADOS_PACOTE_H
#define DADOS_PACOTE_H
>>>>>>> 2f6a8e694acd382df9d89ece63c62dc3ecf2b53a
typedef struct 
{

    char conteudo [50];
    char destinatario [50];
    float peso;
    float distancia;

    
}dadospacote;






void inicializa_pacote(dadospacote *dados,char *conteudo, char *destinatario,float peso, float distancia);

void set_conteudo(dadospacote *dados,char*conteudo);
void set_destinatario(dadospacote *dados,char*destinatario);
void set_peso(dadospacote *dados,float peso);
void set_distancia(dadospacote *dados,float distancia);

char *get_conteudo(dadospacote *dados);
char *get_destinatario(dadospacote *dados);
float get_peso(dadospacote *dados);
float get_distancia(dadospacote *dados);


#endif
