#include <stdio.h>
#include "utilidades.h"
#include "validacoes.h"


int main() {
	// srand(time(NULL));
	// int *numeros, i, ii, codigos[9] = {6,2,3,4,5,0,0,0,0}, flag = 0;

	for(i=0; i<10; i++) {
		numeros = gerarCodigosRandomicos(codigos, 5, 9, "Teste");
		printf("%d %d %d\n", numeros[0], numeros[1], numeros[2]);
	}
	printf("\nFlag = %d\n", flag);

}