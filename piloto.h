#ifndef _piloto_h
#define _piloto_h
#include "equipe.h"
#define MAX_PILOTOS 10

/****************************************
 * Cadastrar, alterar e remover pilotos *
 ****************************************/
struct Piloto {
    int codigo;
    char nome[30], siglaEquipe[4], dataNasc[11], sexo, paisOrigem[20];
};



void menuDadosPiloto(struct Piloto pilotos[], struct Equipe equipes[], int *qtdPilotos, int *qtdEquipes);
void showMenuPiloto();
void cadastrarPiloto(struct Piloto pilotos[], struct Equipe equipes[], int *qtdPilotos, int *qtdEquipes);
int procuraSiglaExistente(struct Piloto pilotos[], struct Equipe equipes[], int qtdPilotos, int *qtdEquipes);
int* gerarCodigosRandomicos(struct Piloto pilotos[], int qtdCodigos, int maxCodigos);
// void alterarPiloto();
// void removerPiloto(struct Piloto pilotos[], int *qtdPilotos);


void menuDadosPiloto(struct Piloto pilotos[], struct Equipe equipes[], int *qtdPilotos, int *qtdEquipes) {
    int resposta;
    
    showMenuPiloto();
    resposta = leValidaInt(1, 3, "Digite uma das opcoes do menu");
    switch(resposta) {
        case 1:
            cadastrarPiloto(pilotos, equipes, qtdPilotos, qtdEquipes);
            break;
        case 2:
            //alterarPiloto();
            break;
        case 3:
            //removerPiloto(pilotos, qtdPilotos);
            break;
    }
}


void showMenuPiloto() {
    printf("1-Cadastrar piloto\n");
    printf("2-Alterar piloto\n");
    printf("3-Remover piloto\n");
}


void cadastrarPiloto(struct Piloto pilotos[], struct Equipe equipes[], int *qtdPilotos, int *qtdEquipes) {
    int *codigos, qtdCodigos, resposta, i;

    if(*qtdPilotos == MAX_PILOTOS) {
        printf("Nao é mais possivel adicionar pilotos.\n");
        return;
    }
    if(MAX_PILOTOS - *qtdPilotos >= 3) {
        qtdCodigos = 3;
    } else {
        qtdCodigos = MAX_PILOTOS - *qtdPilotos;
    }
    codigos = gerarCodigosRandomicos(pilotos, *qtdPilotos, MAX_PILOTOS);
    for(i=0; i<qtdCodigos; i++) {
        printf("%d) %d\t", i+1, codigos[i]);
    }
    resposta = leValidaInt(1, i, "\n\nSelecione um dos codigos acima");
    pilotos[*qtdPilotos].codigo = codigos[resposta-1];

    leValidaNome(pilotos[*qtdPilotos].nome, "Nome do piloto");

    if(procuraSiglaExistente(pilotos, equipes, *qtdPilotos, qtdEquipes)) {
        // (*qtdPilotos)++;
    }
    
}


int procuraSiglaExistente(struct Piloto pilotos[], struct Equipe equipes[], int qtdPilotos, int *qtdEquipes) {
    int i, flag = 0;
    char resposta;

    leValidaSigla(pilotos[qtdPilotos].siglaEquipe, 3, "Sigla da equipe do piloto");
    if(qtdPilotos > 0) {
        for(i=0; i<*qtdEquipes; i++) {
            if(strcmp(equipes[i].sigla, pilotos[qtdPilotos].siglaEquipe) == 0) {
                flag++;
            }
        }
        if(flag == 0) {
            resposta = leValidaChar('s','n', "Sigla nao cadastrada em equipes. Deseja cadastra-la?");
            switch(resposta) {
                case 's':
                    cadastrarEquipe(equipes, qtdEquipes);
                    break;
                case 'n':
                    return 0;
            }
        }
    } else {
        return 1;
    }
}


int* gerarCodigosRandomicos(struct Piloto pilotos[], int qtdCodigos, int maxCodigos) {
    int flag = 1, i, ii,  qtdNumeros;
    int diferenca = maxCodigos - qtdCodigos;
    static int numeros[3] = {0, 0, 0};

    if(diferenca < 3) {
        qtdNumeros = diferenca;
    } else {
        qtdNumeros = 3;
    }

    for(i=0; i<qtdNumeros; i++) {
        flag = 1;
        while(flag > 0) {
            flag = 0;
            numeros[i] = rand() % MAX_PILOTOS + 1;
            if (qtdCodigos > 0) {
                for(ii = 0; ii < qtdCodigos; ii++) {
                    if (pilotos[ii].codigo == numeros[i]) {
                        flag++;
                        break;
                    }
                }
            }
            if(i > 0) {
                for(ii = 0; ii < i; ii++) {
                    if(numeros[ii] == numeros[i]) {
                        flag++;
                        break;
                    }
                }
            }
        }
    }
    return numeros;
}


// void alterarPiloto() {}


// void removerPiloto(struct Piloto pilotos[], int *qtdPilotos) {}


#endif