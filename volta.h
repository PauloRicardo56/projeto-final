#ifndef _volta_h
#define _volta_h
#include <time.h>
#include <locale.h>
#include "structs.h"
#include "validacoes.h"
#include "utilidades.h"


void showMenuVolta();
void menuDadosVolta(struct MelhorVolta voltas[], struct Piloto pilotos[], struct Equipe equipes[], struct Circuito circuitos[],
  int *qtdVoltas, int qtdPilotos, int qtdEquipes, int qtdCircuitos);
void printarDadosVolta(int idPiloto, int idCircuito, char equipePiloto[], int tempoVolta[], int dataVolta[]);
void cadastrarVolta(struct MelhorVolta voltas[], struct Piloto pilotos[], struct Equipe equipes[], struct Circuito circuitos[], 
  int *qtdVoltas, int qtdPilotos, int qtdEquipes, int qtdCircuitos);
void alterarVolta(struct MelhorVolta voltas[], struct Piloto pilotos[], struct Equipe equipes[], struct Circuito circuitos[], int qtdVoltas, int qtdPilotos, int qtdEquipes, int qtdCircuitos);
int pesquisaDadosVolta(struct MelhorVolta voltas[], int qtdVoltas, int indices[], int *indice);


/* * * * * * * * * * * * * * * * * * * *
 * Cadastrar, alterar e excluir voltas *
 * * * * * * * * * * * * * * * * * * * */
void menuDadosVolta(struct MelhorVolta voltas[], struct Piloto pilotos[], struct Equipe equipes[], struct Circuito circuitos[], int *qtdVoltas, int qtdPilotos, int qtdEquipes, int qtdCircuitos) {
    int resposta;
    setlocale(LC_ALL, "Portuguese");
    
	showMenuVolta();
	resposta = leValidaInt(1, 3, "Digite uma das opcoes do menu Oi");
	switch(resposta) {
		case 1:
	        cadastrarVolta(voltas, pilotos, equipes, circuitos, qtdVoltas, qtdPilotos, qtdEquipes, qtdCircuitos);
	        break;
//	    case 2:
//		 	alterarVolta(voltas, pilotos, equipes, circuitos, *qtdVoltas, qtdPilotos, qtdEquipes, qtdCircuitos);
//	        break;
	}
}


void showMenuVolta() {
    printf("1-Cadastrar melhor volta\n");
    printf("2-Alterar melhor volta (X)\n");
    printf("3-Excluir melhor volta (X)\n");
}


void cadastrarVolta(struct MelhorVolta voltas[], struct Piloto pilotos[], struct Equipe equipes[], struct Circuito circuitos[], 
  int *qtdVoltas, int qtdPilotos, int qtdEquipes, int qtdCircuitos) {
    int i, resposta, flag = 1, ii, flag2 = 0, j;
    char tempData[15];

    // char *diaSemana[] = {"Domingo", "Segunda", "Terca", "Quarta", "Quinta", "Sexta", "Sabado"};
    struct tm *data_struct;
    time_t hoje_t, volta_t;

    time(&hoje_t); //Pega o tempo atual
    data_struct = localtime(&hoje_t);

    if(qtdPilotos == 0) {
        printf("Nenhum piloto cadastrado.\n");
        return;
    }
    if(qtdEquipes == 0) {
        printf("Nenhuma equipe cadastrada.\n");
        return;
    }

    printf("Selecione o c?igo do circuito\n");
    for(i=0; i<qtdCircuitos; i++) {
        printf("[%d] - %s\n", circuitos[i].codigo, circuitos[i].nome);
    }
    while(flag > 0) {
        resposta = leValidaIntSemSequencia("\nDigite um c?igo da lista ou 0 para voltar ao menu principal");
        for(ii=0; ii<qtdCircuitos; ii++) {
            if(resposta == circuitos[ii].codigo) {
                flag = 0;
                system("cls");
                break;
            }
            if(resposta == 0) {
                system("cls");
                return;
            }
        }
    }
    if(*qtdVoltas > 0) {
        for(i=0; i<*qtdVoltas; i++) {
            if(voltas[i].circuitoId == resposta) {
                flag2++;
                break;
            }
        }
    }
    if(flag2 == 0) {
        i = *qtdVoltas;
    }
    voltas[i].pilotoId = circuitos[ii].idPilotoMenorTempo;
    voltas[i].circuitoId = circuitos[ii].codigo;
    voltas[i].tempoVolta[0] = circuitos[ii].menorTempoMinSegMilli[0];
    voltas[i].tempoVolta[1] = circuitos[ii].menorTempoMinSegMilli[1];
    voltas[i].tempoVolta[2] = circuitos[ii].menorTempoMinSegMilli[2];

    for(j=0; j<qtdPilotos; j++) {
        if(voltas[i].pilotoId == pilotos[j].codigo) {
            break;
        }
    }
    for(ii=0; ii<qtdEquipes; ii++) {
        if(strcmp(equipes[ii].sigla, pilotos[j].siglaEquipe) == 0) {
            strcpy(voltas[i].equipePiloto, equipes[ii].nome);
            break;
        }
    }

    flag = 1;
    while(flag > 0) {
        flag = 0;
        leValidaDataInt(tempData, voltas[i].voltaData, "Data da melhor volta (Apenas domingos)");
        data_struct->tm_year = voltas[i].voltaData[2] - 1900;
        data_struct->tm_mon = voltas[i].voltaData[1] - 1;
        data_struct->tm_mday = voltas[i].voltaData[0];
        volta_t = mktime(data_struct);
        if(data_struct->tm_wday != 0) {
            printf("Tem que ser um domingo.\n");
            flag++;
        }
        data_struct = localtime(&hoje_t);
        data_struct->tm_year;
        data_struct->tm_mon;
        hoje_t = mktime(data_struct);
        if(hoje_t - volta_t < 0) {
            printf("Data ainda não ocorreu.\n");
            flag++;
        }
    }


    // flag = 0;
    // if(*qtdVoltas > 1) {
    //     for(i=0; i<*qtdVoltas; i++) {
    //         if(voltas[i].pilotoId == voltas[*qtdVoltas].pilotoId && voltas[i].voltaData[0] == voltas[*qtdVoltas].voltaData[0]
    //           && voltas[i].voltaData[1] == voltas[*qtdVoltas].voltaData[1] && voltas[i].voltaData[2] == voltas[*qtdVoltas].voltaData[2]) {
    //             voltas[i].tempoVolta[0] = voltas[*qtdVoltas].tempoVolta[0];
    //             voltas[i].tempoVolta[1] = voltas[*qtdVoltas].tempoVolta[1];
    //             voltas[i].tempoVolta[2] = voltas[*qtdVoltas].tempoVolta[2];
    //             flag++;
    //         }
    //     }
    // }
    if(flag2 == 0) {
        (*qtdVoltas)++;
    }
    printf("Melhor volta cadastrado com sucesso.\n");
}


void alterarVolta(struct MelhorVolta voltas[], struct Piloto pilotos[], struct Equipe equipes[], struct Circuito circuitos[], int qtdVoltas, int qtdPilotos, int qtdEquipes, int qtdCircuitos) {
	int flag = 0, flag2 = 0, i, ii, j, respostaInt;
    char equipePilotoTemp[40], resposta;
    int pilotoIdTemp, circuitoIdTemp, tempoVoltaTemp[3], voltaDataTemp[3], indice = 0, indices[qtdPilotos];
    char tempData[15];

    // char *diaSemana[] = {"Domingo", "Segunda", "Terca", "Quarta", "Quinta", "Sexta", "Sabado"};
    struct tm *data_struct;
    time_t hoje_t, volta_t;

    time(&hoje_t); //Pega o tempo atual
    data_struct = localtime(&hoje_t);
    
    printf("@@ Oi\n");

    if(pesquisaDadosVolta(voltas, qtdVoltas, indices, &indice)) {
        for(i=0; i<indice; i++) {
            printarDadosVolta(voltas[indices[i]].pilotoId, voltas[indices[i]].circuitoId, voltas[indices[i]].equipePiloto, 
			  voltas[indices[i]].tempoVolta, voltas[indices[i]].voltaData);
        }
        if(indice > 1) {
            printf("Mais de um piloto encontrados.\n");
            while(flag == 0) {
                respostaInt = leValidaInt(1, 99, "Informe o c?igo do piloto que deseja alterar da lista");
                flag = 0;
                for(i=0; i<indice; i++) {
                    if(pilotos[indices[i]].codigo == respostaInt) {
                    	
//                    	int pilotoId, circuitoId;
//						char equipePiloto[40];
//						int tempoVolta[3], voltaData[3];
                    	
                    	
                        printarDadosVolta(pilotoIdTemp, circuitoIdTemp, equipePilotoTemp, tempoVoltaTemp, voltaDataTemp);
                        
                        flag++;
                        break;
                    }
                }
            }
        } else {
            i = 0;
        }

        pilotoIdTemp = voltas[indices[i]].pilotoId;
        circuitoIdTemp = voltas[indices[i]].circuitoId;
        strcpy(equipePilotoTemp, voltas[indices[i]].equipePiloto);
        tempoVoltaTemp[0] = voltas[indices[i]].tempoVolta[0];
        tempoVoltaTemp[1] = voltas[indices[i]].tempoVolta[1];
        tempoVoltaTemp[2] = voltas[indices[i]].tempoVolta[2];
        voltaDataTemp[0] = voltas[indices[i]].voltaData[0];
        voltaDataTemp[1] = voltas[indices[i]].voltaData[1];
        voltaDataTemp[2] = voltas[indices[i]].voltaData[2];

//        printarDadosVolta(pilotoIdTemp, circuitoIdTemp, equipePilotoTemp, tempoVoltaTemp, voltaDataTemp);
        printf("@@ Oi\n");
        resposta = leValidaChar2('s', 'n', "Deseja alterar o id do circuito?");
        if(resposta == 's') {
        	printf("Selecione o c?igo do circuito\n");
		    for(i=0; i<qtdCircuitos; i++) {
		        printf("[%d] - %s\n", circuitos[i].codigo, circuitos[i].nome);
		    }
		    while(flag > 0) {
		        resposta = leValidaIntSemSequencia("\nDigite um c?igo da lista ou 0 para voltar ao menu principal");
		        for(ii=0; ii<qtdCircuitos; ii++) {
		            if(resposta == circuitos[ii].codigo) {
		            	printf("@@ %d\n", circuitoIdTemp);
		                flag = 0;
		                system("cls");
		                break;
		            }
		            if(resposta == 0) {
		                system("cls");
		                return;
		            }
		        }
		    }
		    if(flag2 == 0) {
		        i = qtdVoltas;
		    }
		    pilotoIdTemp = circuitos[ii].idPilotoMenorTempo;
		    circuitoIdTemp = circuitos[ii].codigo;
		    
		    tempoVoltaTemp[0] = circuitos[ii].menorTempoMinSegMilli[0];
		    tempoVoltaTemp[1] = circuitos[ii].menorTempoMinSegMilli[1];
		    tempoVoltaTemp[2] = circuitos[ii].menorTempoMinSegMilli[2];
		
		    for(j=0; j<qtdPilotos; j++) {
		        if(voltas[i].pilotoId == pilotos[j].codigo) {
		            break;
		        }
		    }
		    for(ii=0; ii<qtdEquipes; ii++) {
		        if(strcmp(equipes[ii].sigla, pilotos[j].siglaEquipe) == 0) {
		            strcpy(equipePilotoTemp, equipes[ii].nome);
		            break;
		        }
		    }
		    
		    
		    printarDadosVolta(pilotoIdTemp, circuitoIdTemp, equipePilotoTemp, tempoVoltaTemp, voltaDataTemp);
	        resposta = leValidaChar2('s', 'n', "Deseja alterar a data da melhor volta?");
	        if(resposta == 's') {
			    flag = 1;
			    while(flag > 0) {
			        flag = 0;
			        leValidaDataInt(tempData, voltaDataTemp, "Data da melhor volta (Apenas domingos)");
			        data_struct->tm_year = voltaDataTemp[2] - 1900;
			        data_struct->tm_mon = voltaDataTemp[1] - 1;
			        data_struct->tm_mday = voltaDataTemp[0];
			        volta_t = mktime(data_struct);
			        if(data_struct->tm_wday != 0) {
			            printf("Tem que ser um domingo.\n");
			            flag++;
			        }
			        data_struct = localtime(&hoje_t);
			        data_struct->tm_year;
			        data_struct->tm_mon;
			        hoje_t = mktime(data_struct);
			        if(hoje_t - volta_t < 0) {
			            printf("Data ainda n? ocorreu.\n");
			            flag++;
			        }
			    }
			}
        }
//        printarDadosVolta(voltas[indices[i]].pilotoId, voltas[indices[i]].circuitoId, voltas[indices[i]].equipePiloto, 
//						  voltas[indices[i]].tempoVolta, voltas[indices[i]].voltaData);
//        resposta = leValidaChar2('s', 'n', "Deseja alterar o id do circuito?");
//        if(resposta == 's') {
//            if(!procuraSiglaExistente(pilotos, equipes, indices[i], qtdEquipes)) {
//                strcpy(pilotos[indices[i]].siglaEquipe, siglaEquipeTemp);
//            }
//        }
//        printarDadosVolta(voltas[indices[i]].pilotoId, voltas[indices[i]].circuitoId, voltas[indices[i]].equipePiloto, 
//						  voltas[indices[i]].tempoVolta, voltas[indices[i]].voltaData);
//        resposta = leValidaChar2('s', 'n', "Deseja alterar a data de nascimento?");
//        if(resposta == 's') {
//            leValidaDataInt(dataChar, dataTemp, "Nova data");
//        }
//        printarDadosVolta(voltas[indices[i]].pilotoId, voltas[indices[i]].circuitoId, voltas[indices[i]].equipePiloto, 
//						  voltas[indices[i]].tempoVolta, voltas[indices[i]].voltaData);
//        resposta = leValidaChar2('s', 'n', "Deseja alterar o sexo?");
//        if(resposta == 's') {
//            sexoTemp = leValidaChar2('m', 'f', "Novo sexo");
//        }
//        printarDadosVolta(voltas[indices[i]].pilotoId, voltas[indices[i]].circuitoId, voltas[indices[i]].equipePiloto, 
//						  voltas[indices[i]].tempoVolta, voltas[indices[i]].voltaData);
//        resposta = leValidaChar2('s', 'n', "Deseja alterar o pa? de origem?");
//        if(resposta == 's') {
//            leValidaNome(paisOrigemTemp, 1, "Novo paÃ­s de origem");
//        }

        printarDadosVolta(pilotoIdTemp, circuitoIdTemp, equipePilotoTemp, tempoVoltaTemp, voltaDataTemp);
        resposta = leValidaChar2('s', 'n', "Deseja fazer as altera?es?");
        if(resposta == 's') {
//            for(ii=0; ii<qtdPilotos; ii++) {
//                if(indices[i] != ii) {
//                    if(strcmp(nomeTemp, pilotos[ii].nome) == 0 && strcmp(pilotos[indices[i]].siglaEquipe, pilotos[ii].siglaEquipe) == 0 
//                    && (dataTemp[0] == pilotos[ii].dataNascimento[0] && dataTemp[1] == pilotos[ii].dataNascimento[1] && 
//                    dataTemp[2] == pilotos[ii].dataNascimento[2]) && sexoTemp == pilotos[ii].sexo &&
//                    strcmp(paisOrigemTemp, pilotos[ii].paisOrigem) == 0) {
//                        printf("Dados de pilotos ja encotrados em piloto %d (codigo).\nCancelando opera?o.\n\n", pilotos[ii].codigo);
//                        return;
//                    }
//                }
//            }
            voltas[indices[i]].pilotoId = pilotoIdTemp;
	        voltas[indices[i]].circuitoId = circuitoIdTemp;
	        strcpy(voltas[indices[i]].equipePiloto, equipePilotoTemp);
	        voltas[indices[i]].tempoVolta[0] = tempoVoltaTemp[0];
	        voltas[indices[i]].tempoVolta[1] = tempoVoltaTemp[1];
	        voltas[indices[i]].tempoVolta[2] = tempoVoltaTemp[2];
	        voltas[indices[i]].voltaData[0] = voltaDataTemp[0];
	        voltas[indices[i]].voltaData[1] = voltaDataTemp[1];
	        voltas[indices[i]].voltaData[2] = voltaDataTemp[2];
            printf("Dados alterados!\n");
//        } else {
//            strcpy(pilotos[indices[i]].siglaEquipe, siglaEquipeTemp);
        }
    }
}


// void excluirVolta() {}


void printarDadosVolta(int idPiloto, int idCircuito, char equipePiloto[], int tempoVolta[], int dataVolta[]) {
    char temp[10];

    inserirPontos("Piloto (id)", 21);
    inserirPontos(itoa(idPiloto, temp, 10), -35); printf("\n");

    inserirPontos("Circuito (id)", 21);
    inserirPontos(itoa(idPiloto, temp, 10), -35); printf("\n");

    inserirPontos("Equipe do piloto", 21);
    inserirPontos(equipePiloto, -35); printf("\n");

    inserirPontos("Tempo da melhor volta (mm:ss.sss)", 21);
    inserirPontos("", 2);
    printf("%02d:%02d.%03d", tempoVolta[0], tempoVolta[1], tempoVolta[2]); printf("\n");

    inserirPontos("Data da melhor volta (dd/mm/aaaa)", 21);
    inserirPontos("", 1);
    printf("%02d/%02d/%d", dataVolta[0], dataVolta[1], dataVolta[2]);
    printf("\n\n");
}


int pesquisaDadosVolta(struct MelhorVolta voltas[], int qtdVoltas, int indices[], int *indice) {
	char pesquisa[80];
    int i;

    printf("Pesquisa melhor volta >> ");
    scanf("%[^\n]s", &pesquisa); clean_stdin(); system("cls");
    strcpy(pesquisa, toLowerString(pesquisa));
    for(i=0; i<qtdVoltas; i++) {
        if(strstr(toLowerString(voltas[i].equipePiloto), pesquisa) != NULL) {
            indices[*indice] = i;
            (*indice)++;
        } else if(atoi(pesquisa) == voltas[i].pilotoId || atoi(pesquisa) == voltas[i].circuitoId) {
            indices[*indice] = i;
            (*indice)++;
        } else if(voltas[i].tempoVolta[0] == atoi(pesquisa) || voltas[i].tempoVolta[1] == atoi(pesquisa)
           || voltas[i].tempoVolta[2] == atoi(pesquisa)) {
            indices[*indice] = i;
            (*indice)++;
        } else if(voltas[i].voltaData[0] == atoi(pesquisa) || voltas[i].voltaData[1] == atoi(pesquisa)
           || voltas[i].voltaData[2] == atoi(pesquisa)) {
            indices[*indice] = i;
            (*indice)++;
        }
    }
    if(*indice == 0) {
        printf("Nenhum dado encontrado.\n");
        return 0;
    }
    return 1;
}













#endif
