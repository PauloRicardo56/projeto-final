#ifndef _validacoes_h
#define _validacoes_h


/* 
 * Objetivo:
 * Parametros:
 * Retorna: 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utilidades.h"


void leValidaNome(char nome[], int toLower, char msg[]);
void leValidaSigla(char nome[], int maxLetras, char msg[]);
void leValidaNomeTamanho(char nome[], int tamanho, char msg[]);
void leValidaNomeArquivoWindows(char nome[], char msg[]);
char leValidaChar2(char opc1, char opc2, char msg[]);
char leValidaChar3(char opc1, char opc2, char opc3, char msg[]);
float leValidaFloat(float min, float max, char msg[]);
int leValidaInt(int min, int max, char msg[]);
int leValidaIntSemSequencia(char msg[]);
void leValidaIntPont(int *valor, int min, int max, char msg[]);
// void leValidaCodigo(int *codigo, int codigos[], int qtdCodigos);
// int* gerarCodigosRandomicos(struct Piloto pilotos[], int qtdCodigos, int maxCodigos);
void leValidaStringInt(char string[], int tamanho, char msg[]);
void leValidaDataInt(char data[], int diaMesAno[], char msg[]);
void leValidaDataChar(char data[], char msg[]);
void leValidaMinSegMillInt(char tempo[], int minSegMilli[], char msg[]);
void leValidaMinSegMillChar(char tempo[], char msg[]);
void clean_stdin();


/* 
 * Objetivo: Ler e validar nome
 * Parametros: VariÃ¡vel que irÃ¡ armazenar o nome e mensagem a ser exibida
 * Retorna: Nada
 */
void leValidaNome(char nome[], int toLower, char msg[]) {
	char c;
	int flag=1, i, espacos=0;
	while (flag > 0) {
		flag = 0;
		espacos = 0;
		printf("%s (Nao pode ser vazio, conter numeros ou apenas espacos) >> ", msg);
		for(c=getchar(), i=0; c!='\n'; c=getchar(), i++) {
			nome[i] = c;
			if(!isalpha(c) && c != ' ') { flag++; }
			if(c == ' ') { espacos++; }
		}
		nome[i] = '\0';
		if(strlen(nome) == 0 || strlen(nome) == espacos) { flag++; }
	}
	// formataNomeMaiusculo(nome, toLower);
	system("cls");
}


/* 
 * Objetivo: Ler e validar sigla
 * Parametros: VariÃ¡vel que irÃ¡ armazenar o nome, max de letras e mensagem a ser exibida
 * Retorna: Nada
 */
void leValidaSigla(char sigla[], int maxLetras, char msg[]) {
	char c;
	int flag=1, i;

	while (flag > 0) {
		flag = 0;
		printf("%s max. %d letra(s) (Nao pode ser vazio, conter numeros ou espacos) >> ", msg, maxLetras);

		for(c=getchar(), i=0; c!='\n'; c=getchar(), i++) {
			sigla[i] = toupper(c);
			if(!isalpha(c)) { flag++; }
		}
		sigla[i] = '\0';
		if(strlen(sigla) == 0 || strlen(sigla) > maxLetras) { flag++; }
		
	}
	system("cls");
}


/* 
 * Objetivo: Ler e validar nome com limite de tamanho
 * Parametros: VariÃ¡vel que irÃ¡ armazenar o nome e mensagem a ser exibida
 * Retorna: Nada
 */
void leValidaNomeTamanho(char nome[], int tamanho, char msg[]) {
	char c;
	int flag=1, i, espacos=0;
	while (flag > 0) {
		flag = 0;
		espacos = 0;
		printf("%s (Maximo de %d caracteres, nao pode ser vazio, conter numeros ou apenas espacos) >> ", msg, tamanho);
		for(c=getchar(), i=0; c!='\n'; c=getchar(), i++) {
			nome[i] = c;
			if(!isalpha(c) && c != ' ') { flag++; }
			if(c == ' ') { espacos++; }
		}
		nome[i] = '\0';
		if(strlen(nome) == 0 || strlen(nome) == espacos || strlen(nome) > tamanho) { flag++; }
	}
	formataNomeMaiusculo(nome, 1);
	system("cls");
}


/* 
 * Objetivo: Ler e validar nome para criaÃ§Ã£o de arquivos no windows
 * Parametros: VariÃ¡vel que irÃ¡ armazenar o nome e mensagem a ser exibida
 * Retorna: Nada
 */
void leValidaNomeArquivoWindows(char nome[], char msg[]) {
	char c;
	int flag=1, i, espacos=0;
	while (flag > 0) {
		flag = 0;
		espacos = 0;
		printf("%s (Nao pode ser vazio ou conter / \\ : * ? \" < > |) >> ", msg);
		for(c=getchar(), i=0; c != '\n'; c = getchar(), i++) {
			nome[i] = c;
			if(c == '/' || c == '\\' || c == ':' || c == '*' || c == '?' || c == '\"' || c == '<' || c == '>' || c == '|') { flag++; }
			if(c == ' ') { espacos++; }
		}
		nome[i] = '\0';
		if(strlen(nome) == 0 || strlen(nome) == espacos) { flag++; }
	}
	formataNomeMaiusculo(nome, 1);
	system("cls");
}


/* 
 * Objetivo: Ler e validar char (duas opÃ§Ãµes)
 * Parametros: opcao 1 e 2 para a validacao e mensagem a ser exibida
 * Retorna: char validado
 */
char leValidaChar2(char opc1, char opc2, char msg[]) {
	char entrada[10], c;
	int flag=1, i;
	while (flag > 0) {
		flag=0;
		printf("%s (%c ou %c) >> ", msg, opc1, opc2);
		for(c=getchar(), i=0; c!='\n'; c=getchar(), i++) {
			entrada[i] = c;
		}
		entrada[i] = '\0';
		if(strlen(entrada) == 0) { flag++; }
		if(entrada[0] != opc1 && entrada[0] != opc2) { flag++; }
	}
	system("cls");
	return entrada[0];
}


/* 
 * Objetivo: Ler e validar char (duas opÃ§Ãµes) com ponteiro
 * Parametros: opcao 1 e 2 para a validacao e mensagem a ser exibida
 * Retorna: Nada
 */
char leValidaChar2Pont(char *valor, char opc1, char opc2, char msg[]) {
	char entrada[10], c;
	int flag=1, i;
	while (flag > 0) {
		flag=0;
		printf("%s (%c ou %c) >> ", msg, opc1, opc2);
		for(c=getchar(), i=0; c!='\n'; c=getchar(), i++) {
			entrada[i] = c;
		}
		entrada[i] = '\0';
		if(strlen(entrada) == 0) { flag++; }
		if(entrada[0] != opc1 && entrada[0] != opc2) { flag++; }
	}
	*valor = entrada[0];
	system("cls");
}


/* 
 * Objetivo: Ler e validar char (trÃªs opÃ§Ãµes)
 * Parametros: opcao 1 e 2 para a validacao e mensagem a ser exibida
 * Retorna: char validado
 */
char leValidaChar3(char opc1, char opc2, char opc3, char msg[]) {
	char entrada[30], c;
	int flag=1, i;
	while (flag > 0) {
		flag=0;
		printf("%s (%c, %c ou %c) >> ", msg, opc1, opc2, opc3);
		for(c=getchar(), i=0; c!='\n'; c=getchar(), i++) {
			entrada[i] = c;
		}
		entrada[i] = '\0';
		if(strlen(entrada) == 0) { flag++; }
		if(entrada[0] != opc1 && entrada[0] != opc2 && entrada[0] != opc3) { flag++; }
	}
	system("cls");
	return entrada[0];
}


/* 
 * Objetivo: Ler e validar float
 * Parametros: valor minimo e maximo para a vaidacao e mensagem a ser exibida
 * Retorna: float validado
 */
float leValidaFloat(float min, float max, char msg[]) {
	float entrada;
	int valorScanf;
	printf("%s (entre %.1f e %.1f) >> ", msg, min, max);
	valorScanf = scanf("%f", &entrada); clean_stdin();
	while(entrada < min || entrada > max || valorScanf == 0) {
		printf(" Digite um valor valido entre %.1f e %.1f >> ", min, max);
		valorScanf = scanf("%f", &entrada); clean_stdin(); system("cls");
	}
	system("cls");
	return entrada;
}


/* 
 * Objetivo: Ler e valida int
 * Parametros: valor minimo e maximo para a vaidacao e mensagem a ser exibida
 * Retorna: int validado
 */
int leValidaInt(int min, int max, char msg[]) {
	int entrada, valorScanf;
	printf("%s (entre %d e %d) >> ", msg, min, max);
	valorScanf = scanf("%d", &entrada); clean_stdin();
	while(entrada < min || entrada > max || valorScanf == 0) {
		printf(" Digite um valor valido entre %d e %d >> ", min, max);
		valorScanf = scanf("%d", &entrada); clean_stdin();
//		system("cls");
	}
	system("cls");
	return entrada;
}


int leValidaIntSemSequencia(char msg[]) {
	int entrada, valorScanf;
	printf("%s (Número inteiro válido) >> ", msg);
	valorScanf = scanf("%d", &entrada); clean_stdin();
	while(valorScanf == 0) {
		printf(" Digite um valor inteiro válido >> ");
		valorScanf = scanf("%d", &entrada); clean_stdin();
	}
	// system("cls");
	return entrada;
}



/* 
 * Objetivo: Ler e valida int usando ponteiro
 * Parametros: valor minimo e maximo para a vaidacao e mensagem a ser exibida
 * Retorna: Nada
 */
void leValidaIntPont(int *valor, int min, int max, char msg[]) {
	int valorScanf;
	printf("%s (entre %d e %d) >> ", msg, min, max);
	valorScanf = scanf("%d", valor); clean_stdin();
	while(*valor < min || *valor > max || valorScanf == 0) {
		printf(" Digite um valor valido entre %d e %d >> ", min, max);
		valorScanf = scanf("%d", valor); clean_stdin();
		// system("cls");
	}
	system("cls");
}


/* 
 * Objetivo: Gerar tres numeros randomicos nao existentes
 * Parametros: Lista com cÃ³digos existentes, quantidade de codigos, maximo de codigos permitidos e mensagem a ser exibida
 * Retorna: Endereco de memoria para o vetor contendo os numeros.
 */
// int* gerarCodigosRandomicos(struct Piloto pilotos[], int qtdCodigos, int maxCodigos) {
// 	int flag = 1, i, ii,  qtdNumeros;
// 	int diferenca = maxCodigos - qtdCodigos;
// 	static int numeros[3] = {0, 0, 0};

// 	if(diferenca < 3) {
// 		qtdNumeros = diferenca;
// 	} else {
// 		qtdNumeros = 3;
// 	}

// 	for(i=0; i<qtdNumeros; i++) {
// 		flag = 1;
// 		while(flag > 0) {
// 			flag = 0;
// 			numeros[i] = rand() % 10 + 1;
// 			if (qtdCodigos > 1) {
// 				for(ii = 0; ii < qtdCodigos; ii++) {
// 					if (pilotos[ii].codigo == numeros[i]) {
// 						flag++;
// 						break;
// 					}
// 				}
// 			}
// 			if(i > 0) {
// 				for(ii = 0; ii < i; ii++) {
// 					if(numeros[ii] == numeros[i]) {
// 						flag++;
// 						break;
// 					}
// 				}
// 			}
// 		}
// 	}

// 	return numeros;
// }


/* 
 * Objetivo: Ler e validar uma sequencia com quantidade definida de digitos
 * Parametros: String que sera armazenada a sequencia de digitos, quantidade
 *			   de digitos e mensagem a ser exibida.
 * Retorna: Nada
 */
void leValidaStringInt(char string[], int tamanho, char msg[]) {
	char c;
	int flag=1, i;
	while (flag > 0) {
		flag=0;
		printf("%s (%d digitos) >> ", msg, tamanho);
		for(c=getchar(), i=0; c!='\n'; c=getchar(), i++) {
			string[i] = c;
			if(!isdigit(c)) { flag++; }
		}
		string[i] = '\0';
		if(strlen(string) != tamanho) { flag++; }
	}
	system("cls");
}


/* 
 * Objetivo: Limpar buffer do teclado
 * Parametros: Nenhum
 * Retorna: Nada
 */
void clean_stdin() {
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}


/* 
 * Objetivo: Validar dia, mes e ano no formato dd/mm/aaaa
 * Parametros: VariÃ¡vel contendo a string e vetor de inteiros que irÃ¡ conter o dia, mes e ano validados
 * Retorna: Nada
 */
void leValidaDataInt(char data[], int diaMesAno[], char msg[]) {
	char c, temp[5];
	int flag = 1, i, j, k, espacos = 0;

	while(flag > 0) {
		flag = 0;
		leValidaDataChar(data, msg);
		for(i=0, j=0, k=0; i<strlen(data); i++, j++) {
			if(data[i] == '/') { 
				temp[j] = '\0';
				diaMesAno[k] = atoi(temp);
				k++; j = -1;
			} else {
				temp[j] = data[i];
			}
		}
		temp[j] = '\0';
		diaMesAno[k] = atoi(temp);


		if(diaMesAno[2] == 0) { diaMesAno[2] = 2000; }
		else if(diaMesAno[2] < 1) { printf("Ano invalido"); flag++; }
		else if(diaMesAno[2] <= 18) { diaMesAno[2] += 2000; }
		else if(diaMesAno[2] <= 99) { diaMesAno[2] += 1900; }
		else if(diaMesAno[2] <= 1900) { printf("Informe um ano ate 1900"); flag++; }

		if(diaMesAno[0] < 1 || diaMesAno[0] > 31) { printf("Dia invalido"); flag++; }
		else if(diaMesAno[1] < 1 || diaMesAno[1] > 12) { printf("Mes invalido"); flag++; }
		else if(diaMesAno[1] == 2 && diaMesAno[0] > 28) { 
			printf("Mes %d nao contem dia %d", diaMesAno[1], diaMesAno[0]);
			flag++;
		}
		else if((diaMesAno[1] < 7 && diaMesAno[1] % 2 == 0) || diaMesAno[1] == 9 || diaMesAno[1] == 11) {
			if(diaMesAno[0] > 30) {
				printf("Mes %d nao contem dia %d", diaMesAno[1], diaMesAno[0]);
				flag++;
			}
		}
	}
	system("cls");
}


/* 
 * Objetivo: Ler data no formato dd/mm/aaaa
 * Parametros: VariÃ¡vel que irÃ¡ conter a string
 * Retorna: Nada
 */
void leValidaDataChar(char data[], char msg[]) {
	char c;
	int flag = 1, i, espacos = 0;

	while (flag > 0) {
		flag = 0; espacos = 0;
		printf("%s (dd/mm/aaaa) >> ", msg);
		for(c=getchar(), i=0; c!='\n'; c=getchar(), i++) {
			data[i] = c;
			if(!isdigit(c) && c != '/') { flag++; }
			if(c == ' ') { espacos++; }
		}
		data[i] = '\0';
		if(strlen(data) == 0 || strlen(data) == espacos || strlen(data) > 10) { flag++; }
	}
}


void leValidaMinSegMillInt(char tempo[], int minSegMilli[], char msg[]) {
	char c, temp[10];
	int flag = 1, i, j, k, espacos = 0;

	while(flag > 0) {
		flag = 0;
		leValidaMinSegMillChar(tempo, msg);
		for(i=0, j=0, k=0; i<strlen(tempo); i++, j++) {
			if(tempo[i] == ':' || tempo[i] == '.') { 
				temp[j] = '\0';
				minSegMilli[k] = atoi(temp);
				k++; j = -1;
			} else {
				temp[j] = tempo[i];
			}
		}
		temp[j] = '\0';
		minSegMilli[k] = atoi(temp);

		if(minSegMilli[0] < 0 || minSegMilli[1] < 0 || minSegMilli[2] < 0) { printf("Valor negativo invÃ¡lido.\n"); flag++; }
		if(minSegMilli[0] > 999 || minSegMilli[1] > 999 || minSegMilli[2] > 999) { printf("Limite mÃ¡ximo de 3 digitos.\n"); flag++; }
	}
	system("cls");
}


void leValidaMinSegMillChar(char tempo[], char msg[]) {
	int doisPontos = 0, ponto = 0, flag = 1, espacos = 0, i;
	char c;

	while(flag > 0) {
		flag = 0; espacos = 0; doisPontos = 0; ponto = 0;
		printf("%s (mm:ss.sss) >> ", msg);
		for(c=getchar(), i=0; c!='\n'; c=getchar(), i++) {
			tempo[i] = c;
			if(!isdigit(c) && c != ':' && c != '.') { flag++; }
			if(c == ' ') { espacos++; }
			if(c == ':') { doisPontos++; }
			if(c == '.') { ponto++; }
			if(c == '.' && doisPontos == 0) { flag++; }
		}
		tempo[i] = '\0';
		if(strlen(tempo) == 0 || strlen(tempo) == espacos || strlen(tempo) < 5) { flag++; }
		if(doisPontos != 1 || ponto != 1) { flag++; printf("@@ %d\n", flag); }
	}
}


#endif
