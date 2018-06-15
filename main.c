//Todo "leValida" vai estar em validacoes.h


#include <stdio.h>
#include "piloto.h"
#include "equipe.h"
#include "circuito.h"
#include "volta.h"
#include "relatorios.h"


struct Piloto {
    int codigo;
    char nome[30], siglaEquipe[4], dataNasc[11], sexo, paisOrigem[20];
};


// struct Equipe {
//     char nome[40], sigla[4], paisOrigem[20];
// };


struct Circuito {
    int codigo, idPilotoMenorTempo;
    char nome[30], pais[20];
    float tamanho;
    long int menorTempo; //Podemos fazer em milisegundos e na hora de apresentar converter para minutos e segundos.
};


struct MelhorVolta {
    int pilotoId;
    char equipePiloto[40], voltaData[11];
    long int tempoVolta;
};    


int main() {
    struct Piloto pilotos[100];
    struct Equipe equipes[100];
    struct Circuito circuitos[100];
    struct MelhorVolta melhoresVoltas[100];
    int resposta, qtdPilotos, qtdEquipes = 0, qtdCircuitos, qtdMelhoresVoltas;
    
    do {
        showMenu();
        resposta = leValidaInt(1, 7, "Digite uma das opcoes do menu");
        switch(resposta) {
            case 1:
                menuDadosPiloto(pilotos, &qtdPilotos);
                break;
            case 2:
                menuDadosEquipe(equipes, &qtdEquipes);
                break;
            case 3:
                menuDadosCircuito();
                break;
            case 4:
                menuDadosVolta();
                break;
            case 5:
                menuRelatorios();
                break;
            case 6:
                menuPesquisas();
                break;
            case 7:
        }
    } while(resposta != 5);
    
    return 0;
}


void showMenu() {
    printf("1-Menu dos pilotos\n");
    printf("2-Menu das equipes\n");
    printf("3-Menu dos circuitos\n");
    printf("4-Menu das voltas\n");
    printf("5-Relatorios\n");
    printf("6-Pesquisas\n");
    printf("7-Sair\n");
}