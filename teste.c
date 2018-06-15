#include <stdio.h>
#include "utilidades.h"
#include "validacoes.h"
#include "piloto.h"
// #define MAX_PILOTOS 10


int main() {
	int qtdPilotos = 0, i;
	srand(time(NULL));
	struct Piloto pilotos[MAX_PILOTOS]

	while (1) {
		menuDadosPiloto(pilotos, &qtdPilotos);
		for(i = 0; i<qtdPilotos; i++) {
			printf("%d - ", pilotos[i].codigo);
		}
		printf("\n");
	}
}