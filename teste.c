#include <stdio.h>
#include "utilidades.h"
#include "validacoes.h"
#include "piloto.h"
#include "equipe.h"
#include "circuito.h"
#include "volta.h"
#include "relatorios.h"
#include <time.h>


int main() {
	int qtdPilotos = 3, qtdEquipes = 3, qtdCircuitos = 2, qtdVoltas = 1, i;
	srand(time(NULL));
	FILE *pilotosF, *equipesF, *circuitosF, *voltasF;

	struct Piloto pilotos[MAX_PILOTOS];
	struct Equipe equipes[MAX_PILOTOS];
	struct Circuito circuitos[MAX_PILOTOS];
	struct MelhorVolta voltas[MAX_PILOTOS];


	// strcpy(equipes[0].nome, "Ferrari");
	// strcpy(equipes[0].sigla, "FRR");
	// strcpy(equipes[0].paisOrigem, "Italia");

	// strcpy(equipes[1].nome, "Mitsubishi");
	// strcpy(equipes[1].sigla, "MTB");
	// strcpy(equipes[1].paisOrigem, "Franca");

	// strcpy(equipes[2].nome, "Merceds");
	// strcpy(equipes[2].sigla, "MCD");
	// strcpy(equipes[2].paisOrigem, "Inglaterra");

	pilotos[0].codigo = 1;
	pilotos[0].dataNascimento[0] = 17;
	pilotos[0].dataNascimento[1] = 6;
	pilotos[0].dataNascimento[2] = 1997;
	strcpy(pilotos[0].nome, "Paulo Ricardo");
	strcpy(pilotos[0].siglaEquipe, "MTB");
	pilotos[0].sexo = 'm';
	strcpy(pilotos[0].paisOrigem, "Inglaterra");

	pilotos[1].codigo = 2;
	pilotos[1].dataNascimento[0] = 1;
	pilotos[1].dataNascimento[1] = 12;
	pilotos[1].dataNascimento[2] = 1990;
	strcpy(pilotos[1].nome, "Paulo");
	strcpy(pilotos[1].siglaEquipe, "FRR");
	pilotos[1].sexo = 'm';
	strcpy(pilotos[1].paisOrigem, "Italia");

	pilotos[2].codigo = 3;
	pilotos[2].dataNascimento[0] = 17;
	pilotos[2].dataNascimento[1] = 7;
	pilotos[2].dataNascimento[2] = 1997;
	strcpy(pilotos[2].nome, "Ana");
	strcpy(pilotos[2].siglaEquipe, "MCD");
	pilotos[2].sexo = 'f';
	strcpy(pilotos[2].paisOrigem, "Inglaterra");

	circuitos[0].codigo = 1;
	circuitos[0].idPilotoMenorTempo = 1;
	strcpy(circuitos[0].nome, "senna");
	strcpy(circuitos[0].pais, "Brazil");
	circuitos[0].tamanho = 12.78;
	circuitos[0].menorTempoMinSegMilli[0] = 12;
	circuitos[0].menorTempoMinSegMilli[1] = 12;
	circuitos[0].menorTempoMinSegMilli[2] = 12;

	circuitos[1].codigo = 2;
	circuitos[1].idPilotoMenorTempo = 3;
	strcpy(circuitos[1].nome, "Ayrton");
	strcpy(circuitos[1].pais, "Argentina");
	circuitos[1].tamanho = 9.78;
	circuitos[1].menorTempoMinSegMilli[0] = 9;
	circuitos[1].menorTempoMinSegMilli[1] = 59;
	circuitos[1].menorTempoMinSegMilli[2] = 735;


	voltas[0].pilotoId = 1;
	voltas[0].circuitoId = 2;
	voltas[0].tempoVolta[0] = 10;
	voltas[0].tempoVolta[1] = 56;
	voltas[0].tempoVolta[2] = 890;
	voltas[0].voltaData[0] = 12;
	voltas[0].voltaData[1] = 10;
	voltas[0].voltaData[2] = 2016;
	strcpy(voltas[0].equipePiloto, "Ferrari");

	// pilotosF = fopen("pilotos", "wb");
	// fwrite(pilotos, sizeof(struct Piloto), qtdPilotos, pilotosF);
	// fclose(pilotosF);

	// equipesF = fopen("equipes", "wb");
	// fwrite(equipes, sizeof(struct Equipe), qtdEquipes, equipesF);
	// fclose(equipesF);

	// pilotosF = fopen("pilotos", "rb");	
	// fread(&testeP, sizeof(struct Piloto), qtdPilotos, pilotosF);

	// printf("%s\n", testeP[3].nome);

	// while(1) {
		// cadastrarPiloto(equipes, &qtdPilotos, &qtdEquipes);
		pilotosF = fopen("pilotos", "rb");	
		fread(&pilotos, sizeof(struct Piloto), qtdPilotos, pilotosF);
		fclose(pilotosF);

	// 	for(i = 0; i<qtdPilotos; i++) {
	// 		printarDadosPiloto(testeP[i].codigo, testeP[i].nome, testeP[i].siglaEquipe, testeP[i].dataNascimento[0], testeP[i].dataNascimento[1],
 //              testeP[i].dataNascimento[2], testeP[i].sexo, testeP[i].paisOrigem);
	// 	}
	// }

	while(1) {
		cadastrarEquipe(&qtdEquipes);
		equipesF = fopen("equipes", "rb");	
		fread(&equipes, sizeof(struct Equipe), qtdEquipes, equipesF);
		fclose(equipesF);
		printf("@@ %s\n", equipes[0].nome);

		for(i = 0; i<qtdEquipes; i++) {
			printarDadosEquipe(equipes[i].nome, equipes[i].sigla, equipes[i].paisOrigem, 
	  		  procurarSiglaPiloto(equipes, qtdPilotos, equipes[i].sigla));
		}
	}

	// printarDadosVolta(voltas[0].pilotoId, voltas[0].circuitoId, voltas[0].equipePiloto, voltas[0].tempoVolta, 
	// 		  voltas[0].voltaData);

	// while(1) {
	// 	menuDadosPiloto(pilotos, equipes, &qtdPilotos, &qtdEquipes);
	// 	for(i = 0; i<qtdPilotos; i++) {
	// 		printarDados(pilotos[i].codigo, pilotos[i].nome, pilotos[i].siglaEquipe, pilotos[i].dataNascimento[0], pilotos[i].dataNascimento[1],
 //                         pilotos[i].dataNascimento[2], pilotos[i].sexo, pilotos[i].paisOrigem);
	// 	}
	// }
	// while(1) {
	// 	alterarCircuito(circuitos, pilotos, equipes, qtdCircuitos, &qtdPilotos, &qtdEquipes);
	// 	// for(i = 0; i<qtdEquipes; i++) {
	// 	// 	printarDadosEquipe(equipes[i].nome, equipes[i].sigla, equipes[i].paisOrigem, 
	// 	// 					   procurarSiglaPiloto(pilotos, qtdPilotos, equipes[i].sigla));
	// 	// }
	// 	for(i = 0; i<qtdCircuitos; i++) {
	// 		printarDadosCircuito(circuitos[i].codigo, circuitos[i].nome, circuitos[i].pais, circuitos[i].tamanho, 
	// 							 circuitos[i].menorTempoMinSegMilli, circuitos[i].idPilotoMenorTempo);
	// 	}
	// }


	// while(1) {
	// 	cadastrarVolta(voltas, pilotos, equipes, circuitos, &qtdVoltas, qtdPilotos, qtdEquipes, qtdCircuitos);
	// 	// for(i = 0; i<qtdEquipes; i++) {
	// 	// 	printarDadosEquipe(equipes[i].nome, equipes[i].sigla, equipes[i].paisOrigem, 
	// 	// 					   procurarSiglaPiloto(pilotos, qtdPilotos, equipes[i].sigla));
	// 	// }
	// 	for(i = 0; i<qtdVoltas; i++) {
	// 		printarDadosVolta(voltas[i].pilotoId, voltas[i].circuitoId, voltas[i].equipePiloto, voltas[i].tempoVolta, 
	// 		  voltas[i].voltaData);
	// 	}
	// }

	// pesquisarPiloto(pilotos, qtdPilotos);
	// exibirDadosSemMelhorVolta(pilotos, equipes, circuitos, voltas, qtdPilotos, qtdEquipes, qtdCircuitos, qtdVoltas);
	// pesquisarDadosVoltasMenores(pilotos, equipes, circuitos, voltas, qtdPilotos, qtdEquipes, qtdCircuitos, qtdVoltas);
	// for(i = 0; i<qtdVoltas; i++) {
	// 	printarDadosVolta(voltas[i].pilotoId, voltas[i].circuitoId, voltas[i].equipePiloto, voltas[i].tempoVolta, 
	// 	  voltas[i].voltaData);
	// }











	// char *diaSemana[] = {"Domingo", "Segunda", "Terca", "Quarta", "Quinta", "Sexta", "Sabado"};
 //    struct tm *data_struct;
 //    time_t hoje_t, data_t;
 //    int diaMesAno[3];
 //    char tempData[15];

 //    time(&hoje_t); //Pega o tempo atual
 //    data_struct = localtime(&hoje_t); //transforma para a struct tm

 //    // flag = 0;
 //    leValidaDataInt(tempData, diaMesAno, "Tempo da melhor volta (Apenas domingos)");

 //    data_struct->tm_year = diaMesAno[2] - 1900;
 //    data_struct->tm_mon = diaMesAno[1] - 1;
 //    data_struct->tm_mday = diaMesAno[0];
 //    data_t = mktime(data_struct);
 //    if(data_struct->tm_wday != 0) {
 //        printf("Tem que ser um domingo.\n");
 //    }
 //    // time(&hoje_t); //Pega o tempo atual
 //    data_struct = localtime(&hoje_t); //transforma para a struct tm

 //    data_struct->tm_year;
 //    data_struct->tm_mon;
 //    hoje_t = mktime(data_struct);
 //    printf("%d\n%d\n%d", hoje_t, data_t, hoje_t - data_t);
 //    if(hoje_t - data_t < 0) {
 //        printf("Data ainda não ocorreu.\n");
 //    }

}