#include <stdio.h>
#include "utilidades.h"
#include "validacoes.h"
#include "piloto.h"
#include "equipe.h"
// #define MAX_PILOTOS 10


int main() {
	int qtdPilotos = 2, qtdEquipes = 1, i;
	srand(time(NULL));
	struct Piloto pilotos[MAX_PILOTOS];
	struct Equipe equipes[MAX_PILOTOS];

	strcpy(equipes[0].sigla, "FRR");

	pilotos[0].codigo = 1;
	pilotos[0].dataNascimento[0] = 17;
	pilotos[0].dataNascimento[1] = 6;
	pilotos[0].dataNascimento[2] = 1997;
	strcpy(pilotos[0].nome, "Paulo Ricardo de Araujo Vieira");
	strcpy(pilotos[0].siglaEquipe, "FRR");
	pilotos[0].sexo = 'm';
	strcpy(pilotos[0].paisOrigem, "Brasil");

	pilotos[1].codigo = 2;
	pilotos[1].dataNascimento[0] = 17;
	pilotos[1].dataNascimento[1] = 6;
	pilotos[1].dataNascimento[2] = 1990;
	strcpy(pilotos[1].nome, "Paulo");
	strcpy(pilotos[1].siglaEquipe, "FRR");
	pilotos[1].sexo = 'm';
	strcpy(pilotos[1].paisOrigem, "Brasil");

	while(1) {
		menuDadosPiloto(pilotos, equipes, &qtdPilotos, &qtdEquipes);
		for(i = 0; i<qtdPilotos; i++) {
			printarDados(pilotos[i].codigo, pilotos[i].nome, pilotos[i].siglaEquipe, pilotos[i].dataNascimento[0], pilotos[i].dataNascimento[1],
                         pilotos[i].dataNascimento[2], pilotos[i].sexo, pilotos[i].paisOrigem);
		}
	}

	// removerPiloto(pilotos, &qtdPilotos);
	// alterarPiloto(pilotos, equipes, qtdPilotos, &qtdEquipes);
	// for(i = 0; i<qtdPilotos; i++) {
	// 		printarDados(pilotos[i].codigo, pilotos[i].nome, pilotos[i].siglaEquipe, pilotos[i].dataNascimento[0], pilotos[i].dataNascimento[1],
 //                     pilotos[i].dataNascimento[2], pilotos[i].sexo, pilotos[i].paisOrigem);
	// }
}