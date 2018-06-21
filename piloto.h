#ifndef _piloto_h
#define _piloto_h
#include "structs.h"
#include "equipe.h"
#define MAX_PILOTOS 10


/* * * * * * * * * * * * * * * * * * * * *
 * Cadastrar, alterar e remover pilotos  *
 * * * * * * * * * * * * * * * * * * * * */


void menuDadosPiloto(struct Piloto pilotos[], struct Equipe equipes[], int *qtdPilotos, int *qtdEquipes);
void showMenuPiloto();
void cadastrarPiloto(struct Piloto pilotos[], struct Equipe equipes[], int *qtdPilotos, int *qtdEquipes);
int procuraSiglaExistente(struct Piloto pilotos[], struct Equipe equipes[], int qtdPilotos, int *qtdEquipes);
int* gerarCodigosRandomicos(struct Piloto pilotos[], int qtdCodigos, int maxCodigos);
void alterarPiloto(struct Piloto pilotos[], struct Equipe equipes[], int qtdPilotos, int *qtdEquipes);
void removerPiloto(struct Piloto pilotos[], int *qtdPilotos);
int pesquisaDadosPiloto(struct Piloto pilotos[], int qtdPilotos, int *indice, int indices[]);
void printarDadosPiloto(int codigo, char nome[], char sigla[], int dia, int mes, int ano, char sexo, char pais[]);
// void inserirPontos(char string[], int tamanho);


/* 
 * Objetivo: Menu principal para as funÃ§Ãµes dos pilotos.
 * Parametros: Lista com os pilotos existentes, lista com as equipes existentes, quantidade de pilotos
 *   cadastrados e quantidade de equipes cadastradas.
 * Retorna: Nada.
 */
void menuDadosPiloto(struct Piloto pilotos[], struct Equipe equipes[], int *qtdPilotos, int *qtdEquipes) {
    int resposta;
    
    showMenuPiloto();
    resposta = leValidaInt(1, 3, "Digite uma das opcoes do menu"); system("cls");
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


/* 
 * Objetivo: Apresentar o menu dos pilotos.
 * Parametros: Nada.
 * Retorna: Nada.
 */
void showMenuPiloto() {
    printf("1-Cadastrar piloto(a)\n");
    printf("2-Alterar piloto(a)\n");
    printf("3-Remover piloto(a)\n");
}


/* 
 * Objetivo: Cadastrar um piloto.
 * Parametros: Lista com os pilotos existentes, lista com as equipes existentes, quantidade de pilotos
 *   cadastrados e quantidade de equipes cadastradas.
 * Retorna: Nada.
 */
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
    resposta = leValidaInt(1, i, "\n\nSelecione um dos codigos acima"); system("cls");
    pilotos[*qtdPilotos].codigo = codigos[resposta-1];

    leValidaNome(pilotos[*qtdPilotos].nome, 1, "Nome do(a) piloto(a)"); system("cls");

    if(procuraSiglaExistente(pilotos, equipes, *qtdPilotos, qtdEquipes)) {
        leValidaDataInt(data, pilotos[*qtdPilotos].dataNascimento, "Data de nascimento do(a) piloto(a)"); system("cls");
        pilotos[*qtdPilotos].sexo = leValidaChar2('f', 'm', "Sexo do(a) piloto(a)"); system("cls");
        leValidaNome(pilotos[*qtdPilotos].paisOrigem, 1, "País do(a) piloto(a)"); system("cls");
        (*qtdPilotos)++;
    }
}


/* 
 * Objetivo: Procurar sigla de equipe existente em equipes ja cadastradas para o cadastramento do piloto.
 * Parametros: Lista com pilotos ja cadastrados, lista com equipes ja cadastradas, quantidade de pilotos
 *   cadastrados e quantidade de equipes cadastradas.
 * Retorna: 1 se encontrar sigla ou 0 se nÃ£o.
 */
int procuraSiglaExistente(struct Piloto pilotos[], struct Equipe equipes[], int qtdPilotos, int *qtdEquipes) {
    int i, flag = 0;
    char resposta;

    leValidaSigla(pilotos[qtdPilotos].siglaEquipe, 3, "Sigla da equipe do piloto"); system("cls");
    for(i=0; i<*qtdEquipes; i++) {
        if(strcmp(equipes[i].sigla, pilotos[qtdPilotos].siglaEquipe) == 0) {
            flag++;
        }
    }
    if(flag == 0) {
        resposta = leValidaChar2('s','n', "Sigla nao cadastrada em equipes. Deseja cadastra-la?"); system("cls");
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


/* 
 * Objetivo: Gerar cÃ³digos randomicos para o usuÃ¡rio selecionar na hora do cadastramento de um novo piloto.
 * Parametros: Lista com pilotos jÃ¡ cadastrados, quantidade de cÃ³digos ja cadastrados e maximo de codigos permitidos.
 * Retorna: Lista com os cÃ³digos randomicos.
 */
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


/* 
 * Objetivo: Alterar os dados de um piloto.
 * Parametros: Lista com pilotos ja cadastrados, lista com equipes ja cadastradas, quantidade de pilotos
 *   cadastrados e quantidade de equipes cadastradas.
 * Retorna: Nada
 */
void alterarPiloto(struct Piloto pilotos[], struct Equipe equipes[], int qtdPilotos, int *qtdEquipes) {
    int flag = 0, i, ii, respostaInt;
    char nomeTemp[40], sexoTemp, paisOrigemTemp[30], siglaEquipeTemp[4], resposta, dataChar[11];
    int dataTemp[3], codigoTemp, indice = 0, indices[qtdPilotos];

    if(pesquisaDadosPiloto(pilotos, qtdPilotos, &indice, indices)) {
        for(i=0; i<indice; i++) {
            printarDadosPiloto(pilotos[indices[i]].codigo, pilotos[indices[i]].nome, pilotos[indices[i]].siglaEquipe, pilotos[indices[i]].dataNascimento[0], pilotos[indices[i]].dataNascimento[1],
                         pilotos[indices[i]].dataNascimento[2], pilotos[indices[i]].sexo, pilotos[indices[i]].paisOrigem);
        }
        if(indice > 1) {
            printf("Mais de um piloto encontrados.\n");
            while(flag == 0) {
                respostaInt = leValidaInt(1, 99, "Informe o codigo do piloto que deseja alterar da lista");
                flag = 0;
                for(i=0; i<indice; i++) {
                    if(pilotos[indices[i]].codigo == respostaInt) {
                        printarDadosPiloto(pilotos[indices[i]].codigo, pilotos[indices[i]].nome, pilotos[indices[i]].siglaEquipe, pilotos[indices[i]].dataNascimento[0], pilotos[indices[i]].dataNascimento[1],
                             pilotos[indices[i]].dataNascimento[2], pilotos[indices[i]].sexo, pilotos[indices[i]].paisOrigem);
                        flag++;
                        break;
                    }
                }
            }
        } else {
            i = 0;
        }

        codigoTemp = pilotos[indices[i]].codigo;
        strcpy(nomeTemp, pilotos[indices[i]].nome);
        strcpy(siglaEquipeTemp, pilotos[indices[i]].siglaEquipe);
        dataTemp[0] = pilotos[indices[i]].dataNascimento[0];
        dataTemp[1] = pilotos[indices[i]].dataNascimento[1];
        dataTemp[2] = pilotos[indices[i]].dataNascimento[2];
        sexoTemp = pilotos[indices[i]].sexo;
        strcpy(paisOrigemTemp, pilotos[indices[i]].paisOrigem);

        printarDadosPiloto(codigoTemp, nomeTemp, pilotos[indices[i]].siglaEquipe, dataTemp[0], dataTemp[1], dataTemp[2], sexoTemp, paisOrigemTemp);
        resposta = leValidaChar2('s', 'n', "Deseja alterar o nome?");
        if(resposta == 's') {
            leValidaNome(nomeTemp, 1, "Novo nome");
        }
        printarDadosPiloto(codigoTemp, nomeTemp, pilotos[indices[i]].siglaEquipe, dataTemp[0], dataTemp[1], dataTemp[2], sexoTemp, paisOrigemTemp);
        resposta = leValidaChar2('s', 'n', "Deseja alterar a sigla da equipe?");
        if(resposta == 's') {
            if(!procuraSiglaExistente(pilotos, equipes, indices[i], qtdEquipes)) {
                strcpy(pilotos[indices[i]].siglaEquipe, siglaEquipeTemp);
            }
        }
        printarDadosPiloto(codigoTemp, nomeTemp, pilotos[indices[i]].siglaEquipe, dataTemp[0], dataTemp[1], dataTemp[2], sexoTemp, paisOrigemTemp);
        resposta = leValidaChar2('s', 'n', "Deseja alterar a data de nascimento?");
        if(resposta == 's') {
            leValidaDataInt(dataChar, dataTemp, "Nova data");
        }
        printarDadosPiloto(codigoTemp, nomeTemp, pilotos[indices[i]].siglaEquipe, dataTemp[0], dataTemp[1], dataTemp[2], sexoTemp, paisOrigemTemp);
        resposta = leValidaChar2('s', 'n', "Deseja alterar o sexo?");
        if(resposta == 's') {
            sexoTemp = leValidaChar2('m', 'f', "Novo sexo");
        }
        printarDadosPiloto(codigoTemp, nomeTemp, pilotos[indices[i]].siglaEquipe, dataTemp[0], dataTemp[1], dataTemp[2], sexoTemp, paisOrigemTemp);
        resposta = leValidaChar2('s', 'n', "Deseja alterar o paÃ­s de origem?");
        if(resposta == 's') {
            leValidaNome(paisOrigemTemp, 1, "Novo paÃ­s de origem");
        }

        printarDadosPiloto(codigoTemp, nomeTemp, pilotos[indices[i]].siglaEquipe, dataTemp[0], dataTemp[1], dataTemp[2], sexoTemp, paisOrigemTemp);
        resposta = leValidaChar2('s', 'n', "Deseja fazer as alteracoes?");
        if(resposta == 's') {
            for(ii=0; ii<qtdPilotos; ii++) {
                if(indices[i] != ii) {
                    if(strcmp(nomeTemp, pilotos[ii].nome) == 0 && strcmp(pilotos[indices[i]].siglaEquipe, pilotos[ii].siglaEquipe) == 0 
                    && (dataTemp[0] == pilotos[ii].dataNascimento[0] && dataTemp[1] == pilotos[ii].dataNascimento[1] && 
                    dataTemp[2] == pilotos[ii].dataNascimento[2]) && sexoTemp == pilotos[ii].sexo &&
                    strcmp(paisOrigemTemp, pilotos[ii].paisOrigem) == 0) {
                        printf("Dados de pilotos ja encotrados em piloto %d (codigo).\nCancelando operacao.\n\n", pilotos[ii].codigo);
                        return;
                    }
                }
            }
            pilotos[indices[i]].codigo = codigoTemp;
            strcpy(pilotos[indices[i]].nome, nomeTemp);
            //strcpy(pilotos[i].siglaEquipe, siglaEquipeTemp);
            pilotos[indices[i]].dataNascimento[0] = dataTemp[0];
            pilotos[indices[i]].dataNascimento[1] = dataTemp[1];
            pilotos[indices[i]].dataNascimento[2] = dataTemp[2];
            pilotos[indices[i]].sexo = sexoTemp;
            strcpy(pilotos[indices[i]].paisOrigem, paisOrigemTemp);
            printf("Dados alterados!\n");
        } else {
            strcpy(pilotos[indices[i]].siglaEquipe, siglaEquipeTemp);
        }
    }
}


/* 
 * Objetivo: Remover um piloto ja cadastrado.
 * Parametros: Lista com pilotos ja cadastrados e quantidade de pilotos.
 * Retorna: Nada
 */
void removerPiloto(struct Piloto pilotos[], int *qtdPilotos) {
    int indice = 0, flag = 0, i, indices[*qtdPilotos], respostaInt;
    char resposta, pesquisa[50];

    if(pesquisaDadosPiloto(pilotos, *qtdPilotos, &indice, indices)) {
        for(i=0; i<indice; i++) {
            printarDadosPiloto(pilotos[indices[i]].codigo, pilotos[indices[i]].nome, pilotos[indices[i]].siglaEquipe, pilotos[indices[i]].dataNascimento[0], pilotos[indices[i]].dataNascimento[1],
                         pilotos[indices[i]].dataNascimento[2], pilotos[indices[i]].sexo, pilotos[indices[i]].paisOrigem);
        }
        if(indice > 1) {
            printf("Mais de um piloto encontrados.\n");
            while(flag == 0) {
                respostaInt = leValidaInt(1, 99, "Informe o codigo do piloto que deseja excluir da lista");
                flag = 0;
                for(i=0; i<indice; i++) {
                    if(pilotos[indices[i]].codigo == respostaInt) {
                        printarDadosPiloto(pilotos[indices[i]].codigo, pilotos[indices[i]].nome, pilotos[indices[i]].siglaEquipe, pilotos[indices[i]].dataNascimento[0], pilotos[indices[i]].dataNascimento[1],
                             pilotos[indices[i]].dataNascimento[2], pilotos[indices[i]].sexo, pilotos[indices[i]].paisOrigem);
                        flag++;
                        break;
                    }
                }
            }
            resposta = leValidaChar2('s', 'n', "Deseja realmente excluir esse piloto?");
        } else {
            i = 0;
            resposta = leValidaChar2('s', 'n', "Deseja realmente excluir esse piloto?");
        }
        if(resposta == 's') {
            pilotos[indices[i]].codigo = pilotos[*qtdPilotos-1].codigo;

            strcpy(pilotos[indices[i]].nome, pilotos[*qtdPilotos-1].nome);
            strcpy(pilotos[indices[i]].siglaEquipe, pilotos[*qtdPilotos-1].siglaEquipe);
            pilotos[indices[i]].dataNascimento[0] = pilotos[*qtdPilotos-1].dataNascimento[0];
            pilotos[indices[i]].dataNascimento[1] = pilotos[*qtdPilotos-1].dataNascimento[1];

            pilotos[indices[i]].dataNascimento[2] = pilotos[*qtdPilotos-1].dataNascimento[2];

            pilotos[indices[i]].sexo = pilotos[*qtdPilotos-1].sexo;
            // printf("@@ OI\n");
            strcpy(pilotos[indices[i]].paisOrigem, pilotos[*qtdPilotos-1].paisOrigem);

            (*qtdPilotos)--;
            printf("Piloto excluido com sucesso.\n");
            return;
        }
        printf("Exclusao cancelada.\n");
    }
}


/* 
 * Objetivo: Pesquisar um piloto
 * Parametros: Lista com pilotos ja cadastrados, quantidade de pilotos, indice correspondente dos pilotos encontrados
 *   na pesquisa, lista com os Ã­ndices encontrados que correspondem com a pesquisa.
 * Retorna: 1 se encontrou pilotos 0 se nÃ£o.
 */
int pesquisaDadosPiloto(struct Piloto pilotos[], int qtdPilotos, int *indice, int indices[]) {
    char pesquisa[80];
    int i;

    printf("Pesquisa piloto(a) >> ");
    scanf("%[^\n]s", &pesquisa); clean_stdin(); system("cls");
    strcpy(pesquisa, toLowerString(pesquisa));
    for(i=0; i<qtdPilotos; i++) {
        if(strstr(toLowerString(pilotos[i].nome), pesquisa) != NULL || 
           strstr(toLowerString(pilotos[i].siglaEquipe), pesquisa) != NULL ||
           strstr(toLowerString(pilotos[i].paisOrigem), pesquisa) != NULL) {
            indices[*indice] = i;
            (*indice)++;
        } else if(strlen(pesquisa) == 1) {
            if(pesquisa[0] == pilotos[i].sexo) {
                indices[*indice] = i;
                (*indice)++;
            }
        } else if(atoi(pesquisa) == pilotos[i].codigo) {
            indices[*indice] = i;
            (*indice)++;
        } else if(pilotos[i].dataNascimento[0] == atoi(pesquisa) || pilotos[i].dataNascimento[1] == atoi(pesquisa)
           || pilotos[i].dataNascimento[2] == atoi(pesquisa)) {
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


/* 
 * Objetivo: Printa na tela os dados de um piloto.
 * Parametros: CÃ³digo, nome, sigla da equipe, dia, mÃªs e ano de nascimento, sexo e paÃ­s de origem do piloto.
 * Retorna: Nada.
 */
void printarDadosPiloto(int codigo, char nome[], char sigla[], int dia, int mes, int ano, char sexo, char pais[]) {
    char temp[50];

    inserirPontos("Codigo", 17);
    inserirPontos(itoa(codigo, temp, 10), -35); printf("\n");

    inserirPontos("Nome", 17);
    inserirPontos(nome, -35); printf("\n");

    inserirPontos("Sigla da equipe", 17);
    inserirPontos(sigla, -35); printf("\n");

    inserirPontos("Data nasc.", 17);
    inserirPontos("", -25); printf("%02d/%02d/%d\n", dia, mes, ano);

    inserirPontos("Sexo", 17);
    inserirPontos(sexo == 'm' ? "Masculino" : "Feminino", -35); printf("\n");

    inserirPontos("País origem", 17);
    inserirPontos(pais, -36); printf("\n\n");
}


#endif
