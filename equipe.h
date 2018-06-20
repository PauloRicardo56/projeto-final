#ifndef _equipe_h
#define _equipe_h
#include "structs.h"
#include "validacoes.h"
#include "utilidades.h"
#define MAX_LETRAS_SIGLA 3


/* * * * * * * * * * * * * * * *
 * Cadastrar e excluir equipes *
 * * * * * * * * * * * * * * * */


void menuDadosEquipe(struct Equipe equipes[], struct Piloto pilotos[], int *qtdEquipes, int qtdPilotos);
void showMenuEquipe();
void cadastrarEquipe(struct Equipe equipes[], int *qtdEquipes);
void leValidaSiglaNaoRepetida(struct Equipe equipes[], int qtdEquipes);
void excluirEquipe(struct Equipe equipes[], struct Piloto pilotos[], int *qtdEquipes, int qtdPilotos);
int pesquisaDadosEquipe(struct Equipe equipes[], int qtdEquipes, int *indice, int indices[]);
void printarDadosEquipe(char nome[], char sigla[], char pais[], int flag);
int procurarSiglaPiloto(struct Piloto pilotos[], int qtdPilotos, char sigla[]);


void menuDadosEquipe(struct Equipe equipes[], struct Piloto pilotos[], int *qtdEquipes, int qtdPilotos) {
    int resposta;
    
    showMenuEquipe();
    resposta = leValidaInt(1, 2, "Digite uma das opcoes do menu");
    switch(resposta) {
        case 1:
            cadastrarEquipe(equipes, qtdEquipes);
            break;
        case 2:
            excluirEquipe(equipes, pilotos, qtdEquipes, qtdPilotos);
            break;
    }
}


void showMenuEquipe() {
    printf("1-Cadastrar nova equipe\n");
    printf("2-Excluir equipe\n");
}


void cadastrarEquipe(struct Equipe equipes[], int *qtdEquipes) {
    leValidaSiglaNaoRepetida(equipes, *qtdEquipes);
    leValidaNome(equipes[*qtdEquipes].nome, 0, "Nome da equipe");
    leValidaNome(equipes[*qtdEquipes].paisOrigem, 1, "Pais de origem");
    (*qtdEquipes)++;
}


void leValidaSiglaNaoRepetida(struct Equipe equipes[], int qtdEquipes) {
    int i, flag = 1;

    leValidaSigla(equipes[qtdEquipes].sigla, MAX_LETRAS_SIGLA, "Sigla da equipe");
    if(qtdEquipes > 0) {
        while(flag > 0) {
            flag = 0;
            for(i=0; i<qtdEquipes; i++) {
                if(strcmp(equipes[i].sigla, equipes[qtdEquipes].sigla) == 0) {
                    printf("Sigla ja cadastrada em outra equipe (%s)\n", equipes[i].nome);
                    leValidaSigla(equipes[qtdEquipes].sigla, MAX_LETRAS_SIGLA, "Informe outra");
                    flag++;
                }
            }
        }
    } else {
        return;
    }
}


void excluirEquipe(struct Equipe equipes[], struct Piloto pilotos[], int *qtdEquipes, int qtdPilotos) {
    int indice = 0, flag = 0, i, indices[*qtdEquipes];
    char resposta, pesquisa[50], respostaSigla[4];

    if(pesquisaDadosEquipe(equipes, *qtdEquipes, &indice, indices)) {
        for(i=0; i<indice; i++) {
            printarDadosEquipe(equipes[indices[i]].nome, equipes[indices[i]].sigla, equipes[indices[i]].paisOrigem, 
                               procurarSiglaPiloto(pilotos, qtdPilotos, equipes[indices[i]].sigla));
        }
        if(indice > 1) {
            printf("Mais de uma equipe encontradas.\n");
            while(flag == 0) {
                leValidaSigla(respostaSigla, MAX_LETRAS_SIGLA, "Informe a sigla da equipe que deseja excluir");
                flag = 0;
                for(i=0; i<indice; i++) {
                    if(strcmp(equipes[indices[i]].sigla, respostaSigla) == 0) {
                        printarDadosEquipe(equipes[indices[i]].nome, equipes[indices[i]].sigla, equipes[indices[i]].paisOrigem,
                                           procurarSiglaPiloto(pilotos, qtdPilotos, equipes[indices[i]].sigla));
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
        if(resposta == 's' && !procurarSiglaPiloto(pilotos, qtdPilotos, equipes[indices[i]].sigla)) {
            strcpy(equipes[indices[i]].nome, equipes[*qtdEquipes-1].nome);
            strcpy(equipes[indices[i]].sigla, equipes[*qtdEquipes-1].sigla);
            strcpy(equipes[indices[i]].paisOrigem, equipes[*qtdEquipes-1].paisOrigem);
            (*qtdEquipes)--;
            printf("Equipe excluida com sucesso.\n");
            return;
        }
        printf("Não foi possível remover equipe.\n");
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
    inserirPontos(sigla, -35); if(flag == 1) { printf(" (Há pilotos cadastrados nesta equipe)"); }
    printf("\n");

    inserirPontos("País origem", 17);
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