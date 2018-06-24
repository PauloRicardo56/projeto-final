#include <stdio.h>
#include "piloto.h"
#include "equipe.h"
#include "circuito.h"
#include "volta.h"
#include "relatorios.h" 
#include <locale.h>


int main() {
    srand(time(NULL));
    struct Piloto pilotos[100];
    struct Equipe equipes[100];
    struct Circuito circuitos[100];
    struct MelhorVolta melhoresVoltas[100];
    int resposta, qtdPilotos = 0, qtdEquipes = 0, qtdCircuitos = 0, qtdMelhoresVoltas = 0;
    setlocale(LC_ALL, "Portuguese");
    
//  strcpy(equipes[0].nome, "Ferrari");
//	strcpy(equipes[0].sigla, "FRR");
//	strcpy(equipes[0].paisOrigem, "Italia");
//
//	strcpy(equipes[1].nome, "Mitsubishi");
//	strcpy(equipes[1].sigla, "MTB");
//	strcpy(equipes[1].paisOrigem, "Franca");
//
//	strcpy(equipes[2].nome, "Merceds");
//	strcpy(equipes[2].sigla, "MCD");
//	strcpy(equipes[2].paisOrigem, "Inglaterra");
//	qtdEquipes=3;
//
//	 pilotos[0].codigo = 1;
//	 pilotos[0].dataNascimento[0] = 17;
//	 pilotos[0].dataNascimento[1] = 6;
//	 pilotos[0].dataNascimento[2] = 1997;
//	 strcpy(pilotos[0].nome, "Paulo Ricardo");
//	 strcpy(pilotos[0].siglaEquipe, "MTB");
//	 pilotos[0].sexo = 'm';
//	 strcpy(pilotos[0].paisOrigem, "Inglaterra");
//
//	 pilotos[1].codigo = 2;
//	 pilotos[1].dataNascimento[0] = 1;
//	 pilotos[1].dataNascimento[1] = 12;
//	 pilotos[1].dataNascimento[2] = 1990;
//	 strcpy(pilotos[1].nome, "Paulo");
//	 strcpy(pilotos[1].siglaEquipe, "FRR");
//	 pilotos[1].sexo = 'm';
//	 strcpy(pilotos[1].paisOrigem, "Italia");
//
//	 pilotos[2].codigo = 3;
//	 pilotos[2].dataNascimento[0] = 17;
//	 pilotos[2].dataNascimento[1] = 7;
//	 pilotos[2].dataNascimento[2] = 1997;
//	 strcpy(pilotos[2].nome, "Ana");
//	 strcpy(pilotos[2].siglaEquipe, "MCD");
//	 pilotos[2].sexo = 'f';
//	 strcpy(pilotos[2].paisOrigem, "Inglaterra");
//	 qtdPilotos = 3;
//
//	circuitos[0].codigo = 1;
//	circuitos[0].idPilotoMenorTempo = 1;
//	strcpy(circuitos[0].nome, "senna");
//	strcpy(circuitos[0].pais, "Brazil");
//	circuitos[0].tamanho = 12.78;
//	circuitos[0].menorTempoMinSegMilli[0] = 12;
//	circuitos[0].menorTempoMinSegMilli[1] = 12;
//	circuitos[0].menorTempoMinSegMilli[2] = 12;
//
//	circuitos[1].codigo = 2;
//	circuitos[1].idPilotoMenorTempo = 3;
//	strcpy(circuitos[1].nome, "Ayrton");
//	strcpy(circuitos[1].pais, "Argentina");
//	circuitos[1].tamanho = 9.78;
//	circuitos[1].menorTempoMinSegMilli[0] = 9;
//	circuitos[1].menorTempoMinSegMilli[1] = 59;
//	circuitos[1].menorTempoMinSegMilli[2] = 735;
//	qtdCircuitos = 2;
//
//
//	melhoresVoltas[0].pilotoId = 1;
//	melhoresVoltas[0].circuitoId = 2;
//	melhoresVoltas[0].tempoVolta[0] = 10;
//	melhoresVoltas[0].tempoVolta[1] = 56;
//	melhoresVoltas[0].tempoVolta[2] = 890;
//	melhoresVoltas[0].voltaData[0] = 12;
//	melhoresVoltas[0].voltaData[1] = 10;
//	melhoresVoltas[0].voltaData[2] = 2016;
//	strcpy(melhoresVoltas[0].equipePiloto, "Ferrari");
//	qtdMelhoresVoltas = 1;
    
    
    do {
        showMenu();
        resposta = leValidaInt(1, 6, "Digite uma das opções do menu");
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
    printf("5-Relatórios\n");
    printf("6-Sair\n");
}
