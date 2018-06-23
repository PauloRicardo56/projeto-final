#include <stdio.h>
#include "piloto.h"
#include "equipe.h"
#include "circuito.h"
#include "volta.h"
#include "relatorios.h" 


int main() {
    srand(time(NULL));
    struct Piloto pilotos[100];
    struct Equipe equipes[100];
    struct Circuito circuitos[100];
    struct MelhorVolta melhoresVoltas[100];
    int resposta, qtdPilotos = 0, qtdEquipes = 0, qtdCircuitos = 0, qtdMelhoresVoltas = 0;
    
    do {
        showMenu();
        resposta = leValidaInt(1, 6, "Digite uma das opcoes do menu");
        switch(resposta) {
            case 1:
                menuDadosPiloto(pilotos, equipes, &qtdPilotos, &qtdEquipes);
                break;
            case 2:
                menuDadosEquipe(equipes, pilotos, &qtdEquipes, qtdPilotos);
                break;
            case 3:
                menuDadosCircuito(circuitos, pilotos, equipes, &qtdCircuitos, &qtdPilotos, &qtdEquipes);
                break;
            case 4:
                menuDadosVolta(melhoresVoltas, pilotos, equipes, circuitos, &qtdMelhoresVoltas, qtdPilotos, qtdEquipes, qtdCircuitos);
                break;
            case 5:
                menuRelatorios(pilotos, equipes, circuitos, melhoresVoltas, qtdPilotos, qtdEquipes, qtdCircuitos, qtdMelhoresVoltas);
                break;
        }
    } while(resposta != 6);
    
    return 0;
}


void showMenu() {
    printf("1-Menu dos pilotos\n");
    printf("2-Menu das equipes\n");
    printf("3-Menu dos circuitos\n");
    printf("4-Menu das voltas (Necessário cadastro de pilotos e equipes)\n");
    printf("5-Relatorios\n");
    printf("6-Sair\n");
}