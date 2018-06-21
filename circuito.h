#ifndef _circuito_h
#define _circuito_h


void menuDadosCircuito(struct Circuito circuitos[], struct Piloto pilotos[], struct Equipe equipes[], int *qtdCircuitos,
                       int *qtdPilotos, int *qtdEquipes);
void showMenuCircuito();
void cadastrarCircuito(struct Circuito circuitos[], struct Piloto pilotos[], struct Equipe equipes[], int *qtdCircuitos,
                       int *qtdPilotos, int *qtdEquipes);
int procuraIdPiloto(struct Piloto pilotos[], struct Equipe equipes[], int *qtdPilotos, int *qtdEquipes, int id);
void printarDadosCircuito(int codigo, char nome[], char pais[], float tamanho, int minSegMilli[], int id);
// void alterarCircuito();


/* * * * * * * * * * * * * * * * *
 * Cadastrar e excluir circuitos *
 * * * * * * * * * * * * * * * * */
void menuDadosCircuito(struct Circuito circuitos[], struct Piloto pilotos[], struct Equipe equipes[], int *qtdCircuitos, 
                       int *qtdPilotos, int *qtdEquipes) {
    int resposta;
    
    showMenuCircuito();
    resposta = leValidaInt(1, 2, "Digite uma das opcoes do menu");
    switch(resposta) {
        case 1:
            cadastrarCircuito(circuitos, pilotos, equipes, qtdCircuitos, qtdPilotos, qtdEquipes);
            break;
        // case 2:
            // alterarCircuito();
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
    leValidaNome(circuitos[*qtdCircuitos].pais, 0, "País do circuito");
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
    resposta = leValidaChar2('s', 'n', "Nenhum piloto cadastrado com esse id. Deseja cadastrá-lo?");
    if(resposta == 's') {
        cadastrarPiloto(pilotos, equipes, qtdPilotos, qtdEquipes);
        return 1;
    }
    return 0;
}


void printarDadosCircuito(int codigo, char nome[], char pais[], float tamanho, int minSegMilli[], int id) {
    char temp[10];

    inserirPontos("Código", 17);
    inserirPontos(itoa(codigo, temp, 10), -35); printf("\n");

    inserirPontos("Nome", 17);
    inserirPontos(nome, -34); printf("\n");

    inserirPontos("País", 17);
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


void alterarCircuito(struct Circuitos circuitos[], int qtdCircuitos) {
    int flag = 0, i, ii, respostaInt;
    char nomeTemp[40], , paisTemp[30], [4], resposta, dataChar[11];
    int tempoTemp[3], codigoTemp, indice = 0, indices[qtdCircuitos], idPilotoTemp;

    if(pesquisaDadosCircuito(circuitos, qtdCircuitos, &indice, indices)) {
        for(i=0; i<indice; i++) {
            printarDadosCircuito(circuitos[i].codigo, circuitos[i].nome, circuitos[i].pais, circuitos[i].tamanho,
                                 circuitos[i].menorTempoMinSegMilli, circuitos[i].idPilotoMenorTempo);
        }
        if(indice > 1) {
            printf("Mais de um circuito encontrados.\n");
            while(flag == 0) {
                respostaInt = leValidaInt(1, 99, "Informe o codigo do circuito que deseja alterar da lista");
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
        strcpy(, circuitos[indices[i]].siglaEquipe);
        tempoTemp[0] = circuitos[indices[i]].menorTempoMinSegMilli[0];
        tempoTemp[1] = circuitos[indices[i]].menorTempoMinSegMilli[1];
        tempoTemp[2] = circuitos[indices[i]].menorTempoMinSegMilli[2];
         = circuitos[indices[i]].sexo;
        strcpy(paisTemp, circuitos[indices[i]].pais);

        printarDadosCircuito(circuitos[i].codigo, circuitos[i].nome, circuitos[i].pais, circuitos[i].tamanho,
                                 circuitos[i].menorTempoMinSegMilli, circuitos[i].idPilotoMenorTempo);
        resposta = leValidaChar2('s', 'n', "Deseja alterar o nome?");
        if(resposta == 's') {
            leValidaNome(nomeTemp, 1, "Novo nome");
        }
        printarDadosCircuito(circuitos[i].codigo, circuitos[i].nome, circuitos[i].pais, circuitos[i].tamanho,
                                 circuitos[i].menorTempoMinSegMilli, circuitos[i].idPilotoMenorTempo);
        resposta = leValidaChar2('s', 'n', "Deseja alterar a sigla da equipe?");
        if(resposta == 's') {
            if(!procuraSiglaExistente(circuitos, equipes, indices[i], qtdEquipes)) {
                strcpy(circuitos[indices[i]].siglaEquipe, );
            }
        }
        printarDadosCircuito(circuitos[i].codigo, circuitos[i].nome, circuitos[i].pais, circuitos[i].tamanho,
                                 circuitos[i].menorTempoMinSegMilli, circuitos[i].idPilotoMenorTempo);
        resposta = leValidaChar2('s', 'n', "Deseja alterar a data de nascimento?");
        if(resposta == 's') {
            leValidaDataInt(dataChar, tempoTemp, "Nova data");
        }
        printarDadosCircuito(circuitos[i].codigo, circuitos[i].nome, circuitos[i].pais, circuitos[i].tamanho,
                                 circuitos[i].menorTempoMinSegMilli, circuitos[i].idPilotoMenorTempo);
        resposta = leValidaChar2('s', 'n', "Deseja alterar o sexo?");
        if(resposta == 's') {
             = leValidaChar2('m', 'f', "Novo sexo");
        }
        printarDadosCircuito(circuitos[i].codigo, circuitos[i].nome, circuitos[i].pais, circuitos[i].tamanho,
                                 circuitos[i].menorTempoMinSegMilli, circuitos[i].idPilotoMenorTempo);
        resposta = leValidaChar2('s', 'n', "Deseja alterar o paÃ­s de origem?");
        if(resposta == 's') {
            leValidaNome(paisTemp, 1, "Novo paÃ­s de origem");
        }

        printarDadosCircuito(circuitos[i].codigo, circuitos[i].nome, circuitos[i].pais, circuitos[i].tamanho,
                                 circuitos[i].menorTempoMinSegMilli, circuitos[i].idPilotoMenorTempo);
        resposta = leValidaChar2('s', 'n', "Deseja fazer as alteracoes?");
        if(resposta == 's') {
            for(ii=0; ii<qtdcircuitos; ii++) {
                if(indices[i] != ii) {
                    if(strcmp(nomeTemp, circuitos[ii].nome) == 0 && strcmp(circuitos[indices[i]].siglaEquipe, circuitos[ii].siglaEquipe) == 0 
                    && (tempoTemp[0] == circuitos[ii].menorTempoMinSegMilli[0] && tempoTemp[1] == circuitos[ii].menorTempoMinSegMilli[1] && 
                    tempoTemp[2] == circuitos[ii].menorTempoMinSegMilli[2]) &&  == circuitos[ii].sexo &&
                    strcmp(paisTemp, circuitos[ii].pais) == 0) {
                        printf("Dados de circuitos ja encotrados em piloto %d (codigo).\nCancelando operacao.\n\n", circuitos[ii].codigo);
                        return;
                    }
                }
            }
            circuitos[indices[i]].codigo = codigoTemp;
            strcpy(circuitos[indices[i]].nome, nomeTemp);
            //strcpy(circuitos[i].siglaEquipe, );
            circuitos[indices[i]].menorTempoMinSegMilli[0] = tempoTemp[0];
            circuitos[indices[i]].menorTempoMinSegMilli[1] = tempoTemp[1];
            circuitos[indices[i]].menorTempoMinSegMilli[2] = tempoTemp[2];
            circuitos[indices[i]].sexo = ;
            strcpy(circuitos[indices[i]].pais, paisTemp);
            printf("Dados alterados!\n");
        } else {
            strcpy(circuitos[indices[i]].siglaEquipe, );
        }
    }
}


int pesquisaDadosCircuito(struct Circuitos circuitos[], int qtdCircuitos, int *indice, int indices[]) {
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