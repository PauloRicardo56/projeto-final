#ifndef _volta_h
#define _volta_h
#include <time.h>


void showMenuVolta();
void menuDadosVolta(struct MelhorVolta voltas[], struct Piloto pilotos[], struct Equipe equipes[], struct Circuito circuitos[],
  int *qtdVoltas, int qtdPilotos, int qtdEquipes, int qtdCircuitos);
void printarDadosVolta(int idPiloto, int idCircuito, char equipePiloto[], int tempoVolta[], int dataVolta[]);
void cadastrarVolta(struct MelhorVolta voltas[], struct Piloto pilotos[], struct Equipe equipes[], struct Circuito circuitos[], 
  int *qtdVoltas, int qtdPilotos, int qtdEquipes, int qtdCircuitos);


/* * * * * * * * * * * * * * * * * * * *
 * Cadastrar, alterar e excluir voltas *
 * * * * * * * * * * * * * * * * * * * */
void menuDadosVolta(struct MelhorVolta voltas[], struct Piloto pilotos[], struct Equipe equipes[], struct Circuito circuitos[],
  int *qtdVoltas, int qtdPilotos, int qtdEquipes, int qtdCircuitos) {
    int resposta;
    
    showMenuVolta();
    leValidaInt(1, 3, "Digite uma das opcoes do menu");
    switch(resposta) {
        case 1:
            cadastrarVolta(voltas, pilotos, equipes, circuitos, qtdVoltas, qtdPilotos, qtdEquipes, qtdCircuitos);
            break;
        // case 2:
        //     alterarVolta();
        //     break;
        // case 3:
        //     excluirVolta();
    }
}


void showMenuVolta() {
    printf("1-Cadastrar melhor volta\n");
    printf("2-Alterar melhor volta\n");
    printf("3-Excluir melhor volta\n");
}


void cadastrarVolta(struct MelhorVolta voltas[], struct Piloto pilotos[], struct Equipe equipes[], struct Circuito circuitos[], 
  int *qtdVoltas, int qtdPilotos, int qtdEquipes, int qtdCircuitos) {
    int i, resposta, flag = 1, ii, flag2 = 0, j;
    char tempData[15];

    // char *diaSemana[] = {"Domingo", "Segunda", "Terca", "Quarta", "Quinta", "Sexta", "Sabado"};
    struct tm *data_struct;
    time_t hoje_t, volta_t;

    time(&hoje_t); //Pega o tempo atual
    data_struct = localtime(&hoje_t); //transforma para a struct tm    

    if(qtdPilotos == 0) {
        printf("Nenhum piloto cadastrado.\n");
        return;
    }
    if(qtdEquipes == 0) {
        printf("Nenhuma equipe cadastrada.\n");
        return;
    }

    printf("Selecione o código do circuito\n");
    for(i=0; i<qtdCircuitos; i++) {
        printf("[%d] - %s\n", circuitos[i].codigo, circuitos[i].nome);
    }
    while(flag > 0) {
        resposta = leValidaIntSemSequencia("\nDigite um código da lista ou 0 para voltar ao menu principal");
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
    printf("@@ %d\n@@ %d\n", i, ii);
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


// void alterarVolta() {}


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


#endif