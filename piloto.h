#ifndef _piloto_h
#define _piloto_h
#include "equipe.h"
#define MAX_PILOTOS 10

/****************************************
 * Cadastrar, alterar e remover pilotos *
 ****************************************/
struct Piloto {
    int codigo, dataNascimento[3]; //Dia, mes e ano
    char nome[30], siglaEquipe[4], sexo, paisOrigem[20];
};



void menuDadosPiloto(struct Piloto pilotos[], struct Equipe equipes[], int *qtdPilotos, int *qtdEquipes);
void showMenuPiloto();
void cadastrarPiloto(struct Piloto pilotos[], struct Equipe equipes[], int *qtdPilotos, int *qtdEquipes);
int procuraSiglaExistente(struct Piloto pilotos[], struct Equipe equipes[], int qtdPilotos, int *qtdEquipes);
int* gerarCodigosRandomicos(struct Piloto pilotos[], int qtdCodigos, int maxCodigos);
void alterarPiloto(struct Piloto pilotos[], struct Equipe equipes[], int qtdPilotos, int *qtdEquipes);
void removerPiloto(struct Piloto pilotos[], int *qtdPilotos);


void menuDadosPiloto(struct Piloto pilotos[], struct Equipe equipes[], int *qtdPilotos, int *qtdEquipes) {
    int resposta;
    
    showMenuPiloto();
    resposta = leValidaInt(1, 3, "Digite uma das opcoes do menu");
    switch(resposta) {
        case 1:
            cadastrarPiloto(pilotos, equipes, qtdPilotos, qtdEquipes);
            break;
        case 2:
            alterarPiloto(pilotos, equipes, *qtdPilotos, qtdEquipes);
            break;
        case 3:
            removerPiloto(pilotos, qtdPilotos);
            break;
    }
}


void showMenuPiloto() {
    printf("1-Cadastrar piloto(a)\n");
    printf("2-Alterar piloto(a)\n");
    printf("3-Remover piloto(a)\n");
}


void cadastrarPiloto(struct Piloto pilotos[], struct Equipe equipes[], int *qtdPilotos, int *qtdEquipes) {
    int *codigos, qtdCodigos, resposta, i;
    char data[11];

    if(*qtdPilotos == MAX_PILOTOS) {
        printf("Nao é mais possivel adicionar pilotos(as).\n");
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

    leValidaNome(pilotos[*qtdPilotos].nome, 1, "Nome do(a) piloto(a)");

    if(procuraSiglaExistente(pilotos, equipes, *qtdPilotos, qtdEquipes)) {
        leValidaDataInt(data, pilotos[*qtdPilotos].dataNascimento, "Data de nascimento do(a) piloto(a)");
        pilotos[*qtdPilotos].sexo = leValidaChar2('f', 'm', "Sexo do(a) piloto(a)");
        leValidaNome(pilotos[*qtdPilotos].paisOrigem, 1, "País do(a) piloto(a)");
        (*qtdPilotos)++;
    }
    
}


int procuraSiglaExistente(struct Piloto pilotos[], struct Equipe equipes[], int qtdPilotos, int *qtdEquipes) {
    int i, flag = 0;
    char resposta;

    leValidaSigla(pilotos[qtdPilotos].siglaEquipe, 3, "Sigla da equipe do piloto");
    for(i=0; i<*qtdEquipes; i++) {
        if(strcmp(equipes[i].sigla, pilotos[qtdPilotos].siglaEquipe) == 0) {
            flag++;
        }
    }
    if(flag == 0) {
        resposta = leValidaChar2('s','n', "Sigla nao cadastrada em equipes. Deseja cadastra-la?");
        switch(resposta) {
            case 's':
                cadastrarEquipe(equipes, qtdEquipes);
                break;
            case 'n':
                return 0;
        }
    }
    return 1;
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


void alterarPiloto(struct Piloto pilotos[], struct Equipe equipes[], int qtdPilotos, int *qtdEquipes) {
    int pesquisa, flag = 0, i, ii;
    char nomeTemp[40], sexoTemp, paisOrigemTemp[30], siglaEquipeTemp[4], resposta, dataChar[11];
    int dataTemp[3], codigoTemp;

    pesquisa = leValidaInt(1, 99, "Codigo do piloto");
    for(i=0; i<qtdPilotos; i++) {
        if(pilotos[i].codigo == pesquisa) {
            flag++;
            break;
        }
    }
    if(flag == 0) {
        printf("Codigo de piloto(a) nao encontrado.\n");
        return;
    }

    codigoTemp = pilotos[i].codigo;
    strcpy(nomeTemp, pilotos[i].nome);
    strcpy(siglaEquipeTemp, pilotos[i].siglaEquipe);
    dataTemp[0] = pilotos[i].dataNascimento[0];
    dataTemp[1] = pilotos[i].dataNascimento[1];
    dataTemp[2] = pilotos[i].dataNascimento[2];
    sexoTemp = pilotos[i].sexo;
    strcpy(paisOrigemTemp, pilotos[i].paisOrigem);

    printf("Codigo: %d\nNome: %s\nSigla da equipe: %s\nData nasc.: %02d/%02d/%d\nSexo: %s\nPaís de origem: %s\n\n", codigoTemp, nomeTemp, 
        pilotos[i].siglaEquipe, dataTemp[0], dataTemp[1], dataTemp[2], sexoTemp == 'm' ? "Masculino" : "Feminino", paisOrigemTemp);
    resposta = leValidaChar2('s', 'n', "Deseja alterar o nome?");
    if(resposta == 's') {
        leValidaNome(nomeTemp, 1, "Novo nome");
    }
    printf("Codigo: %d\nNome: %s\nSigla da equipe: %s\nData nasc.: %02d/%02d/%d\nSexo: %s\nPaís de origem: %s\n\n", codigoTemp, nomeTemp, 
        pilotos[i].siglaEquipe, dataTemp[0], dataTemp[1], dataTemp[2], sexoTemp == 'm' ? "Masculino" : "Feminino", paisOrigemTemp);
    resposta = leValidaChar2('s', 'n', "Deseja alterar a sigla da equipe?");
    if(resposta == 's') {
        if(!procuraSiglaExistente(pilotos, equipes, i, &qtdEquipes)) {
            strcpy(pilotos[i].siglaEquipe, siglaEquipeTemp);
        }
    }
    printf("Codigo: %d\nNome: %s\nSigla da equipe: %s\nData nasc.: %02d/%02d/%d\nSexo: %s\nPaís de origem: %s\n\n", codigoTemp, nomeTemp, 
        pilotos[i].siglaEquipe, dataTemp[0], dataTemp[1], dataTemp[2], sexoTemp == 'm' ? "Masculino" : "Feminino", paisOrigemTemp);
    resposta = leValidaChar2('s', 'n', "Deseja alterar a data de nascimento?");
    if(resposta == 's') {
        leValidaDataInt(dataChar, dataTemp, "Nova data");
    }
    printf("Codigo: %d\nNome: %s\nSigla da equipe: %s\nData nasc.: %02d/%02d/%d\nSexo: %s\nPaís de origem: %s\n\n", codigoTemp, nomeTemp, 
        pilotos[i].siglaEquipe, dataTemp[0], dataTemp[1], dataTemp[2], sexoTemp == 'm' ? "Masculino" : "Feminino", paisOrigemTemp);
    resposta = leValidaChar2('s', 'n', "Deseja alterar o sexo?");
    if(resposta == 's') {
        sexoTemp = leValidaChar2('m', 'f', "Novo sexo");
    }
    printf("Codigo: %d\nNome: %s\nSigla da equipe: %s\nData nasc.: %02d/%02d/%d\nSexo: %s\nPaís de origem: %s\n\n", codigoTemp, nomeTemp, 
        pilotos[i].siglaEquipe, dataTemp[0], dataTemp[1], dataTemp[2], sexoTemp == 'm' ? "Masculino" : "Feminino", paisOrigemTemp);
    resposta = leValidaChar2('s', 'n', "Deseja alterar o país de origem?");
    if(resposta == 's') {
        leValidaNome(paisOrigemTemp, 1, "Novo país de origem");
    }

    resposta = leValidaChar2('s', 'n', "Deseja fazer as alteracoes?");
    if(resposta == 's') {
        for(ii=0; ii<qtdPilotos; ii++) {
            if(i != ii) {
                if(strcmp(nomeTemp, pilotos[ii].nome) == 0 && strcmp(pilotos[i].siglaEquipe, pilotos[ii].siglaEquipe) == 0 
                && (dataTemp[0] == pilotos[ii].dataNascimento[0] && dataTemp[1] == pilotos[ii].dataNascimento[1] && 
                dataTemp[2] == pilotos[ii].dataNascimento[2]) && sexoTemp == pilotos[ii].sexo &&
                strcmp(paisOrigemTemp, pilotos[ii].paisOrigem) == 0) {
                    printf("Dados de pilotos ja encotrados em piloto %d (codigo).\nCancelando operacao.\n\n", pilotos[ii].codigo);
                    return;
                }
            }
        }
        pilotos[i].codigo = codigoTemp;
        strcpy(pilotos[i].nome, nomeTemp);
        //strcpy(pilotos[i].siglaEquipe, siglaEquipeTemp);
        pilotos[i].dataNascimento[0] = dataTemp[0];
        pilotos[i].dataNascimento[1] = dataTemp[1];
        pilotos[i].dataNascimento[2] = dataTemp[2];
        pilotos[i].sexo = sexoTemp;
        strcpy(pilotos[i].paisOrigem, paisOrigemTemp);
        printf("Dados alterados!\n");
    } else {
        strcpy(pilotos[i].siglaEquipe, siglaEquipeTemp);
    }
}


void removerPiloto(struct Piloto pilotos[], int *qtdPilotos) {
    int pesquisa, flag = 0, i;
    char resposta;

    pesquisa = leValidaInt(1, 99, "Codigo do piloto");
    for(i=0; i<*qtdPilotos; i++) {
        if(pilotos[i].codigo == pesquisa) {
            flag++;
            break;
        }
    }
    if(flag == 0) {
        printf("Codigo de piloto(a) nao encontrado.\n");
        return;
    }
    printf("Codigo: %d\nNome: %s\nSigla da equipe: %s\nData nasc.: %02d/%02d/%d\nSexo: %s\nPaís de origem: %s\n\n", pilotos[i].codigo, 
        pilotos[i].nome, pilotos[i].siglaEquipe, pilotos[i].dataNascimento[0], pilotos[i].dataNascimento[1], pilotos[i].dataNascimento[2], 
        pilotos[i].sexo == 'm' ? "Masculino" : "Feminino", pilotos[i].paisOrigem);
    resposta = leValidaChar2('s', 'n', "Deseja realmente excluir esse piloto?");
    if(resposta == 's') {
        pilotos[i].codigo = pilotos[*qtdPilotos-1].codigo;

        strcpy(pilotos[i].nome, pilotos[*qtdPilotos-1].nome);
        strcpy(pilotos[i].siglaEquipe, pilotos[*qtdPilotos-1].siglaEquipe);
        pilotos[i].dataNascimento[0] = pilotos[*qtdPilotos-1].dataNascimento[0];
        pilotos[i].dataNascimento[1] = pilotos[*qtdPilotos-1].dataNascimento[1];

        pilotos[i].dataNascimento[2] = pilotos[*qtdPilotos-1].dataNascimento[2];

        pilotos[i].sexo = pilotos[*qtdPilotos-1].sexo;
        // printf("@@ OI\n");
        strcpy(pilotos[i].paisOrigem, pilotos[*qtdPilotos-1].paisOrigem);

        (*qtdPilotos)--;
        printf("Piloto excluido com sucesso.\n");
        return;
    }
    printf("Exclusao cancelada.\n");
}


#endif