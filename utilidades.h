#ifndef utilidades_h
#define utilidades_h


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>


void inserirPontos(char string[], int tamanho);
const char *toLowerString(char string[]);
char *itoa(int value, char *result, int base);
int calcDigitosNum(int num);
void formataNomeMaiusculo(char string[], int toLower);


/* 
 * Objetivo: Insere pontos como padding de uma string.
 * Parametros: string e tamanho total do padding.
 * Retorna: Nada.
 */
void inserirPontos(char string[], int tamanho) {
    int i, padding = abs(strlen(string) - abs(tamanho));

    if(tamanho < 0) {
        for(i=0; i<padding; i++) {
            printf(".");
        }
        printf("%s", string);
    } else {
        printf("%s", string);
        for(i=0; i<padding; i++) {
            printf(".");
        }
    }
}


const char *toLowerString(char string[]) {
	int i;
	static char saida[100];

	for(i=0; i<strlen(string); i++) {

		saida[i] = tolower(string[i]);
		
	}

	saida[i] = '\0';
	return saida;
}


char *itoa(int value, char *result, int base) {
    // check that the base if valid
    if (base < 2 || base > 36) { *result = '\0'; return result; }

    char* ptr = result, *ptr1 = result, tmp_char;
    int tmp_value;

    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
    } while ( value );

    // Apply negative sign
    if (tmp_value < 0) *ptr++ = '-';
    *ptr-- = '\0';
    while (ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}


/* 
 * Objetivo: Fromatar nome para iniciais maiusculas e resto minusculas
 * Parametros: VariÃ¡vel do nome
 * Retorna: Nada
 */
void formataNomeMaiusculo(char string[], int toLower) {
	int i;
	for(i = 0; i < strlen(string); i++) {
		if(i == 0) {
			string[i] = toupper(string[i]);
		} else if(string[i] == ' ') {
			string[i+1] = toupper(string[i+1]);
			i++;
		} else {
			if(toLower == 1) {
				string[i] = tolower(string[i]);
			}
		}
	}
}


 
//  * Objetivo: Gerar numeros randomicos de 1 Ã  n
//  * Parametros: NÃºmero qualquer
//  * Retorna: Quantidade de dÃ­gitos desse nÃºmero
// int gerarNumeroRandomico(int n) {
// 	int numero = rand() % n + 1;
// 	return numero;
// }


/* 
 * Objetivo: Descobrir quantos difitos possui um nÃºmero
 * Parametros: NÃºmero qualquer
 * Retorna: Quantidade de dÃ­gitos desse nÃºmero
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
