#ifndef _equipe_h
#define _equipe_h
#include "structs.h"
#include "validacoes.h"
#include "utilidades.h"
#define MAX_LETRAS_SIGLA 3
#include <locale.h>


/* * * * * * * * * * * * * * * *
 * Cadastrar e excluir equipes *
 * * * * * * * * * * * * * * * */


void menuDadosEquipe();
void showMenuEquipe();
void cadastrarEquipe();
void leValidaSiglaNaoRepetida(struct Equipe equipes[], int qtdEquipes);
void excluirEquipe();
int pesquisaDadosEquipe(struct Equipe equipes[], int qtdEquipes, int *indice, int indices[]);
void printarDadosEquipe(char nome[], char sigla[], char pais[], int flag);
int procurarSiglaPiloto(struct Piloto pilotos[], int qtdPilotos, char sigla[]);


void menuDadosEquipe() {
    int resposta;
    setlocale(LC_ALL, "Portuguese");
    
    showMenuEquipe();
    resposta = leValidaInt(1, 2, "Digite uma das op?es do menu");
    switch(resposta) {
        case 1:
            cadastrarEquipe();
            break;
        case 2:
            excluirEquipe();
            break;
    }
}


void showMenuEquipe() {
    printf("1-Cadastrar nova equipe\n");
    printf("2-Excluir equipe\n");
}


void cadastrarEquipe() {
    int qtdDados[4], i;
    struct Equipe equipes[100];
    FILE *equipesF, *qtdDadosF;

    if((qtdDadosF = fopen("dados", "rb")) != NULL) {
        fread(&qtdDados, sizeof(int), 4, qtdDadosF); fclose(qtdDadosF);
    } else {
        for(i=0; i<4; i++) {
            qtdDados[i] = 0;
        }
    }

    if(qtdDados[1] > 0) {
        equipesF = fopen("equipes", "rb");
        fread(&equipes, sizeof(struct Equipe), qtdDados[1], equipesF); fclose(equipesF);
    }

    leValidaSiglaNaoRepetida(equipes, qtdDados[1]); system("cls");
    leValidaNome(equipes[qtdDados[1]].nome, 0, "Nome da equipe"); system("cls");
    leValidaNome(equipes[qtdDados[1]].paisOrigem, 1, "Pa? de origem"); system("cls");
    qtdDados[1]++;

    qtdDadosF = fopen("dados", "wb");
    fwrite(qtdDados, sizeof(int), 4, qtdDadosF); fclose(qtdDadosF);
    equipesF = fopen("equipes", "wb");
    fwrite(equipes, sizeof(struct Equipe), qtdDados[1], equipesF); fclose(equipesF);
}


void leValidaSiglaNaoRepetida(struct Equipe equipes[], int qtdEquipes) {
    int i, flag = 1;

    leValidaSigla(equipes[qtdEquipes].sigla, MAX_LETRAS_SIGLA, "Sigla da equipe");
    if(qtdEquipes > 0) {
        while(flag > 0) {
            flag = 0;
            for(i=0; i<qtdEquipes; i++) {
                if(strcmp(equipes[i].sigla, equipes[qtdEquipes].sigla) == 0) {
                    printf("Sigla j?cadastrada em outra equipe (%s)\n", equipes[i].nome);
                    leValidaSigla(equipes[qtdEquipes].sigla, MAX_LETRAS_SIGLA, "Informe outra"); system("cls");
                    flag++;
                }
            }
        }
    } else {
        return;
    }
}


void excluirEquipe() {
    int indice = 0, flag = 0, i, qtdDados[4];
    char resposta, pesquisa[50], respostaSigla[4];
    FILE *qtdDadosF, *equipesF, *pilotosF;
    struct Equipe equipes[100];
    struct Piloto pilotos[100];

    if((qtdDadosF = fopen("dados", "rb")) != NULL) {
        fread(&qtdDados, sizeof(int), 4, qtdDadosF); fclose(qtdDadosF);
    } else {
        for(i=0; i<4; i++) {
            qtdDados[i] = 0;
        }
    }
    if(qtdDados[1] > 0) {
        equipesF = fopen("equipes", "rb");
        fread(&equipes, sizeof(struct Equipe), qtdDados[1], equipesF); fclose(equipesF);
    } int indices[qtdDados[1]];
    if(qtdDados[0] > 0) {
        pilotosF = fopen("pilotos", "rb");
        fread(&pilotos, sizeof(struct Piloto), qtdDados[0], pilotosF); fclose(pilotosF);
    }

    if(pesquisaDadosEquipe(equipes, qtdDados[1], &indice, indices)) {
        for(i=0; i<indice; i++) {
            printarDadosEquipe(equipes[indices[i]].nome, equipes[indices[i]].sigla, equipes[indices[i]].paisOrigem, 
              procurarSiglaPiloto(pilotos, qtdDados[0], equipes[indices[i]].sigla));
        }
        if(indice > 1) {
            printf("Mais de uma equipe encontradas.\n");
            while(flag == 0) {
                leValidaSigla(respostaSigla, MAX_LETRAS_SIGLA, "Informe a sigla da equipe que deseja excluir");
                flag = 0;
                for(i=0; i<indice; i++) {
                    if(strcmp(equipes[indices[i]].sigla, respostaSigla) == 0) {
                        printarDadosEquipe(equipes[indices[i]].nome, equipes[indices[i]].sigla, equipes[indices[i]].paisOrigem,
                          procurarSiglaPiloto(pilotos, qtdDados[0], equipes[indices[i]].sigla));
                        flag++;
                        break;
                    }
                }
            }
            resposta = leValidaChar2('s', 'n', "Deseja realmente excluir essa equipe?");
        } else {
            i = 0;
            resposta = leValidaChar2('s', 'n', "Deseja realmente excluir essa equipe?");
        }
        if(resposta == 's' && !procurarSiglaPiloto(pilotos, qtdDados[0], equipes[indices[i]].sigla)) {
            strcpy(equipes[indices[i]].nome, equipes[qtdDados[1]-1].nome);
            strcpy(equipes[indices[i]].sigla, equipes[qtdDados[1]-1].sigla);
            strcpy(equipes[indices[i]].paisOrigem, equipes[qtdDados[1]-1].paisOrigem);
            qtdDados[1]--;

            qtdDadosF = fopen("dados", "wb");
            fwrite(qtdDados, sizeof(int), 4, qtdDadosF); fclose(qtdDadosF);
            equipesF = fopen("equipes", "wb");
            fwrite(equipes, sizeof(struct Equipe), qtdDados[1], equipesF); fclose(equipesF);

            printf("Equipe excluida com sucesso.\n");
            return;
        }
        printf("N? foi poss?el remover equipe.\n");
    }
}


int pesquisaDadosEquipe(struct Equipe equipes[], int qtdEquipes, int *indice, int indices[]) {
    char pesquisa[80];
    int i;

    printf("Pesquisa equipe(a) >> ");
    scanf("%[^\n]s", &pesquisa); clean_stdin();
    strcpy(pesquisa, toLowerString(pesquisa));
    for(i=0; i<qtdEquipes; i++) {
        if(strstr(toLowerString(equipes[i].nome), pesquisa) != NULL || 
           strstr(toLowerString(equipes[i].sigla), pesquisa) != NULL ||
           strstr(toLowerString(equipes[i].paisOrigem), pesquisa) != NULL) {
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


void printarDadosEquipe(char nome[], char sigla[], char pais[], int flag) {
    inserirPontos("Nome", 17);
    inserirPontos(nome, -35); printf("\n");

    inserirPontos("Sigla", 17);
    inserirPontos(sigla, -35); if(flag == 1) { printf(" (H?pilotos cadastrados nesta equipe)"); }
    printf("\n");

    inserirPontos("Pa? origem", 17);
    inserirPontos(pais, -36); printf("\n\n");
}


int procurarSiglaPiloto(struct Piloto pilotos[], int qtdPilotos, char sigla[]) {
    int i, flag = 0;

    for(i=0; i<qtdPilotos; i++) {
        if(strcmp(pilotos[i].siglaEquipe, sigla) == 0) {
            flag++;
            break;
        }
    }
    if(flag > 0) {
        return 1;
    }
    return 0;
}


#endif
