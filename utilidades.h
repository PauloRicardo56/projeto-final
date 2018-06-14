#ifndef utilidades_h
#define utilidades_h


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


int calcDigitosNum(int num);
void formataNomeMaiusculo(char string[]);


/* 
 * Objetivo: Fromatar nome para iniciais maiusculas e resto minusculas
 * Parametros: Variável do nome
 * Retorna: Nada
 */
void formataNomeMaiusculo(char string[]) {
	int i;
	for(i = 0; i < strlen(string); i++) {
		if(i == 0) {
			string[i] = toupper(string[i]);
		} else if(string[i] == ' ') {
			string[i+1] = toupper(string[i+1]);
			i++;
		} else {
			string[i] = tolower(string[i]);
		}
	}
}


 
//  * Objetivo: Gerar numeros randomicos de 1 à n
//  * Parametros: Número qualquer
//  * Retorna: Quantidade de dígitos desse número
// int gerarNumeroRandomico(int n) {
// 	int numero = rand() % n + 1;
// 	return numero;
// }


/* 
 * Objetivo: Descobrir quantos difitos possui um número
 * Parametros: Número qualquer
 * Retorna: Quantidade de dígitos desse número
 */
int calcDigitosNum(int num) {
	int digitos=0;
	while(num != 0) {
		num /= 10;
		digitos++;
	}
	return digitos;
}


#endif