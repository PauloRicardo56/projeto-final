#ifndef _piloto_h
#define _piloto_h
#define MAX_PILOTOS 10

/****************************************
 * Cadastrar, alterar e remover pilotos *
 ****************************************/
struct Piloto {
    int codigo;
    char nome[30], siglaEquipe[4], dataNasc[11], sexo, paisOrigem[20];
};



void menuDadosPiloto(struct Piloto pilotos[], int *qtdPilotos);
void showMenuPiloto();
void cadastrarPiloto(struct Piloto pilotos[], int *qtdPilotos);
int* gerarCodigosRandomicos(struct Piloto pilotos[], int qtdCodigos, int maxCodigos);
// void alterarPiloto();
// void removerPiloto(struct Piloto pilotos[], int *qtdPilotos);


void menuDadosPiloto(struct Piloto pilotos[], int *qtdPilotos) {
    int resposta;
    
    showMenuPiloto();
    resposta = leValidaInt(1, 3, "Digite uma das opcoes do menu");
    switch(resposta) {
        case 1:
            cadastrarPiloto(pilotos, qtdPilotos);
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


void cadastrarPiloto(struct Piloto pilotos[], int *qtdPilotos) {
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
    printf("@@ %d - %d\n", *qtdPilotos, resposta);
    pilotos[*qtdPilotos].codigo = codigos[resposta-1];

    leValidaNome(pilotos[*qtdPilotos].nome, "Nome do piloto");
    (*qtdPilotos)++;
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