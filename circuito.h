#ifndef _circuito_h
#define _circuito_h
#include "structs.h"
#include <locale.h>
#include "validacoes.h"
#include "utilidades.h"
#include "piloto.h"


void menuDadosCircuito(struct Circuito circuitos[], struct Piloto pilotos[], struct Equipe equipes[], int *qtdCircuitos,
                       int *qtdPilotos, int *qtdEquipes);
void showMenuCircuito();
void cadastrarCircuito(struct Circuito circuitos[], struct Piloto pilotos[], struct Equipe equipes[], int *qtdCircuitos,
                       int *qtdPilotos, int *qtdEquipes);
int procuraIdPiloto(struct Piloto pilotos[], struct Equipe equipes[], int *qtdPilotos, int *qtdEquipes, int id);
void printarDadosCircuito(int codigo, char nome[], char pais[], float tamanho, int minSegMilli[], int id);
void alterarCircuito(struct Circuito circuitos[], struct Piloto pilotos[], struct Equipe equipes[], int qtdCircuitos, int *qtdPilotos,
                     int *qtdEquipes);
int pesquisaDadosCircuito(struct Circuito circuitos[], int qtdCircuitos, int *indice, int indices[]);


/* * * * * * * * * * * * * * * * *
 * Cadastrar e excluir circuitos *
 * * * * * * * * * * * * * * * * */
void menuDadosCircuito(struct Circuito circuitos[], struct Piloto pilotos[], struct Equipe equipes[], int *qtdCircuitos, 
  int *qtdPilotos, int *qtdEquipes) {
    int resposta;
    setlocale(LC_ALL, "Portuguese");
    
    showMenuCircuito();
    resposta = leValidaInt(1, 2, "Digite uma das op?es do menu");
    switch(resposta) {
        case 1:
            cadastrarCircuito(circuitos, pilotos, equipes, qtdCircuitos, qtdPilotos, qtdEquipes);
            break;
        case 2:
            alterarCircuito(circuitos, pilotos, equipes, *qtdCircuitos, qtdPilotos, qtdEquipes);
            break;
    }
}


void showMenuCircuito() {
    printf("1-Cadastrar novo circuito\n");
    printf("2-Alterar circuito\n");
}


void cadastrarCircuito(struct Circuito circuitos[], struct Piloto pilotos[], struct Equipe equipes[], int *qtdCircuitos, 
                       int *qtdPilotos, int *qtdEquipes) {
    int i;
    char temp[15];

    leValidaNome(circuitos[*qtdCircuitos].nome, 0, "Nome do circuito");
    leValidaNome(circuitos[*qtdCircuitos].pais, 0, "Pa? do circuito");
    circuitos[*qtdCircuitos].tamanho = leValidaFloat(3, 20, "Tamanho do circuito (Km)");
    leValidaMinSegMillInt(temp, circuitos[*qtdCircuitos].menorTempoMinSegMilli, "Menor tempo do circuito");
    circuitos[*qtdCircuitos].idPilotoMenorTempo = leValidaInt(1, 99, "Id do piloto com menor tempo no circuito");
    if(procuraIdPiloto(pilotos, equipes, qtdPilotos, qtdEquipes, circuitos[*qtdCircuitos].idPilotoMenorTempo)) {
        printf("Circuito cadastrado com sucesso.\n");
        circuitos[*qtdCircuitos].codigo = ++(*qtdCircuitos);
    }
}


int procuraIdPiloto(struct Piloto pilotos[], struct Equipe equipes[], int *qtdPilotos, int *qtdEquipes, int id) {
    int i, flag = 0;
    char resposta;

    for(i=0; i<*qtdPilotos; i++) {
        if(pilotos[i].codigo == id) {
            flag++;
            break;
        }
    }
    if(flag > 0) {
        return 1;
    }
    resposta = leValidaChar2('s', 'n', "Nenhum piloto cadastrado com esse id. Deseja cadastr?lo?");
    if(resposta == 's') {
        cadastrarPiloto(equipes, qtdPilotos, qtdEquipes);
        return 1;
    }
    return 0;
}


void printarDadosCircuito(int codigo, char nome[], char pais[], float tamanho, int minSegMilli[], int id) {
    char temp[10];

    inserirPontos("C?igo", 17);
    inserirPontos(itoa(codigo, temp, 10), -35); printf("\n");

    inserirPontos("Nome", 17);
    inserirPontos(nome, -34); printf("\n");

    inserirPontos("Pa?", 17);
    inserirPontos(pais, -35); printf("\n");

    inserirPontos("Tamanho (Km)", 17);
    inserirPontos("", -29);
    printf("%05.2f\n", tamanho);

    inserirPontos("Menor tempo (mm:ss.sss)", 17);
    inserirPontos("", -12);
    printf("%03d:%02d.%03d\n", minSegMilli[0], minSegMilli[1], minSegMilli[2]);

    inserirPontos("Piloto com menor tempo (Id)", 17);
    inserirPontos(itoa(id, temp, 10), -14); printf("\n\n");
}


void alterarCircuito(struct Circuito circuitos[], struct Piloto pilotos[], struct Equipe equipes[], int qtdCircuitos, int *qtdPilotos, int *qtdEquipes) {
    int flag = 0, i, ii, respostaInt;
    char nomeTemp[40], paisTemp[30], resposta, temp[15];//, tempoChar[11];
    int tempoTemp[3], codigoTemp, indice = 0, indices[qtdCircuitos], idPilotoTemp;
    float tamanhoTemp;

    if(pesquisaDadosCircuito(circuitos, qtdCircuitos, &indice, indices)) {
        for(i=0; i<indice; i++) {
            printarDadosCircuito(circuitos[i].codigo, circuitos[i].nome, circuitos[i].pais, circuitos[i].tamanho,
                                 circuitos[i].menorTempoMinSegMilli, circuitos[i].idPilotoMenorTempo);
        }
        if(indice > 1) {
            printf("Mais de um circuito encontrados.\n");
            while(flag == 0) {
                respostaInt = leValidaInt(1, 99, "Informe o c?igo do circuito que deseja alterar da lista");
                flag = 0;
                for(i=0; i<indice; i++) {
                    if(circuitos[indices[i]].codigo == respostaInt) {
                        printarDadosCircuito(circuitos[i].codigo, circuitos[i].nome, circuitos[i].pais, circuitos[i].tamanho,
                                 circuitos[i].menorTempoMinSegMilli, circuitos[i].idPilotoMenorTempo);
                        flag++;
                        break;
                    }
                }
            }
        } else {
            i = 0;
        }

        codigoTemp = circuitos[indices[i]].codigo;
        idPilotoTemp = circuitos[indices[i]].idPilotoMenorTempo;
        strcpy(nomeTemp, circuitos[indices[i]].nome);
        tempoTemp[0] = circuitos[indices[i]].menorTempoMinSegMilli[0];
        tempoTemp[1] = circuitos[indices[i]].menorTempoMinSegMilli[1];
        tempoTemp[2] = circuitos[indices[i]].menorTempoMinSegMilli[2];
        tamanhoTemp = circuitos[indices[i]].tamanho;
        strcpy(paisTemp, circuitos[indices[i]].pais);

        printarDadosCircuito(circuitos[i].codigo, nomeTemp, paisTemp, tamanhoTemp, tempoTemp, idPilotoTemp);
        resposta = leValidaChar2('s', 'n', "Deseja alterar o nome do circuito?");
        if(resposta == 's') {
            leValidaNome(nomeTemp, 1, "Novo nome");
        }
        printarDadosCircuito(circuitos[i].codigo, nomeTemp, paisTemp, tamanhoTemp, tempoTemp, idPilotoTemp);
        resposta = leValidaChar2('s', 'n', "Deseja alterar o pa? do circuito?");
        if(resposta == 's') {
            leValidaNome(paisTemp, 1, "Novo pa?");
        }
        printarDadosCircuito(circuitos[i].codigo, nomeTemp, paisTemp, tamanhoTemp, tempoTemp, idPilotoTemp);
        resposta = leValidaChar2('s', 'n', "Deseja alterar o tamanho do circuito?");
        if(resposta == 's') {
            tamanhoTemp = leValidaFloat(3, 20, "Novo tamanho");
        }
        printarDadosCircuito(circuitos[i].codigo, nomeTemp, paisTemp, tamanhoTemp, tempoTemp, idPilotoTemp);
        resposta = leValidaChar2('s', 'n', "Deseja alterar o menor tempo do circuito?");
        if(resposta == 's') {
             leValidaMinSegMillInt(temp, tempoTemp, "Menor tempo do circuito");
        }
        printarDadosCircuito(circuitos[i].codigo, nomeTemp, paisTemp, tamanhoTemp, tempoTemp, idPilotoTemp);
        resposta = leValidaChar2('s', 'n', "Deseja alterar o id do piloto com menor tempo?");
        if(resposta == 's') {
            idPilotoTemp = leValidaInt(1, 99, "Novo id do piloto");
            if(!procuraIdPiloto(pilotos, equipes, qtdPilotos, qtdEquipes, idPilotoTemp)) {
                printf("Altera?es de dados cancelada.\n");
                return;
            }
//            idPilotoTemp = pilotos[*qtdPilotos-1].codigo;
        }
        printarDadosCircuito(circuitos[i].codigo, nomeTemp, paisTemp, tamanhoTemp, tempoTemp, idPilotoTemp);
        resposta = leValidaChar2('s', 'n', "Deseja fazer as altera?es?");
        if(resposta == 's') {
            for(ii=0; ii<qtdCircuitos; ii++) {
                if(indices[i] != ii) {
                    if(strcmp(nomeTemp, circuitos[ii].nome) == 0 && tempoTemp[0] == circuitos[ii].menorTempoMinSegMilli[0] && 
                       tempoTemp[1] == circuitos[ii].menorTempoMinSegMilli[1] && tempoTemp[2] == circuitos[ii].menorTempoMinSegMilli[2]
                       && strcmp(paisTemp, circuitos[ii].pais) == 0 && idPilotoTemp == circuitos[ii].idPilotoMenorTempo &&
                       codigoTemp == circuitos[ii].codigo && tamanhoTemp == circuitos[ii].tamanho) {
                        printf("Dados de circuitos j?encotrados em circuito %d (c?igo).\nCancelando opera?o.\n\n", circuitos[ii].codigo);
                        return;
                    }
                }
            }

            circuitos[indices[i]].codigo = codigoTemp;
            circuitos[indices[i]].idPilotoMenorTempo = idPilotoTemp;
            strcpy(circuitos[indices[i]].nome, nomeTemp);
            circuitos[indices[i]].menorTempoMinSegMilli[0] = tempoTemp[0];
            circuitos[indices[i]].menorTempoMinSegMilli[1] = tempoTemp[1];
            circuitos[indices[i]].menorTempoMinSegMilli[2] = tempoTemp[2];
            circuitos[indices[i]].tamanho = tamanhoTemp;
            strcpy(circuitos[indices[i]].pais, paisTemp);
            printf("Dados alterados!\n");
        }
    }
}


int pesquisaDadosCircuito(struct Circuito circuitos[], int qtdCircuitos, int *indice, int indices[]) {
    char pesquisa[80];
    int i;

    printf("Pesquisa circuito >> ");
    scanf("%[^\n]s", &pesquisa); clean_stdin(); system("cls");
    strcpy(pesquisa, toLowerString(pesquisa));
    for(i=0; i<qtdCircuitos; i++) {
        if(strstr(toLowerString(circuitos[i].nome), pesquisa) != NULL || 
           strstr(toLowerString(circuitos[i].pais), pesquisa) != NULL) {
            indices[*indice] = i;
            (*indice)++;
        } else if(atoi(pesquisa) == circuitos[i].codigo || atoi(pesquisa) == circuitos[i].idPilotoMenorTempo) {
            indices[*indice] = i;
            (*indice)++;
        } else if(circuitos[i].menorTempoMinSegMilli[0] == atoi(pesquisa) || circuitos[i].menorTempoMinSegMilli[1] == atoi(pesquisa)
           || circuitos[i].menorTempoMinSegMilli[2] == atoi(pesquisa)) {
            indices[*indice] = i;
            (*indice)++;
        } else if(atoi(pesquisa) == (int) circuitos[i].tamanho) {
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
