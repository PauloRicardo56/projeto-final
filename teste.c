#include <stdio.h>
#include "utilidades.h"
#include "validacoes.h"
#include "piloto.h"
#include "equipe.h"
// #define MAX_PILOTOS 10


int main() {
	int qtdPilotos = 0, qtdEquipes = 0, i;
	srand(time(NULL));
	struct Piloto pilotos[MAX_PILOTOS];
	struct Equipe equipes[MAX_PILOTOS];

	while (1) {
		menuDadosPiloto(pilotos, equipes, &qtdPilotos, &qtdEquipes);
		for(i = 0; i<qtdPilotos; i++) {
			printf("%d - ", pilotos[i].codigo);
		}
		printf("\n");
	}
}