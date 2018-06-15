#include <stdio.h>
#include "utilidades.h"
#include "validacoes.h"
#include "piloto.h"
#include "equipe.h"
// #define MAX_PILOTOS 10


int main() {
	int qtdPilotos = 0, qtdEquipes = 1, i;
	srand(time(NULL));
	struct Piloto pilotos[MAX_PILOTOS];
	struct Equipe equipes[MAX_PILOTOS];

	strcpy(equipes[0].sigla, "FRR"); 

	while (1) {
		cadastrarPiloto(pilotos, equipes, &qtdPilotos, &qtdEquipes);
		for(i = 0; i<qtdPilotos; i++) {
			printf("%d - %s - %s - %d/%02d/%d - %s - %s\n", pilotos[i].codigo, pilotos[i].nome, pilotos[i].siglaEquipe,
				pilotos[i].dataNascimento[0], pilotos[i].dataNascimento[1], pilotos[i].dataNascimento[2], pilotos[i].sexo == 'm' ? "Masculino" 
				: "Feminino", pilotos[i].paisOrigem);
		}
		printf("\n");
	}
	// char data[11];
	// int dat[3];
	// leValidaDataInt(data, dat, "Teste");
	// printf("%d/%d/%d", dat[0], dat[1], dat[2]);
}