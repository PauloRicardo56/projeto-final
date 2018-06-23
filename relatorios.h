#ifndef _relatorios_h
#define _relatorios_h
#include "piloto.h"
#include "utilidades.h"


void menuRelatorios(struct Piloto pilotos[], struct Equipe equipes[], struct Circuito circuitos[], struct MelhorVolta voltas[], 
  int qtdPilotos, int qtdEquipes, int qtdCircuitos, int qtdVoltas);
void showMenuRelatorios();
void pesquisarPiloto(struct Piloto pilotos[], int qtdPilotos);


void pesquisarDadosVoltasMenores(struct Piloto pilotos[], struct Equipe equipes[], struct Circuito circuitos[], struct MelhorVolta voltas[], 
  int qtdPilotos, int qtdEquipes, int qtdCircuitos, int qtdVoltas);
void exibirDadosSemMelhorVolta(struct Piloto pilotos[], struct Equipe equipes[], struct Circuito circuitos[], struct MelhorVolta voltas[], 
  int qtdPilotos, int qtdEquipes, int qtdCircuitos, int qtdVoltas);


/**************
 * RELATORIOS *
 **************/
void menuRelatorios(struct Piloto pilotos[], struct Equipe equipes[], struct Circuito circuitos[], struct MelhorVolta voltas[], 
  int qtdPilotos, int qtdEquipes, int qtdCircuitos, int qtdVoltas) {
    int resposta;
    
    showMenuRelatorios(); 
    resposta = leValidaInt(1, 7, "Digite uma das opcoes do menu");
    switch(resposta) {
        // case 1:
        //     consultarDados();
        //     break;
        case 2:
            pesquisarPiloto(pilotos, qtdPilotos);
            break;
        // case 3:
        //     relacaoPilotoCircuito();
        //     break;
        // case 4:
        //     pesquisarCircuito();
        //     break();
        // case 5:
        //     pesquisaPilotoData();
        //     break;
        case 6:
            pesquisarDadosVoltasMenores(pilotos, equipes, circuitos, voltas, qtdPilotos, qtdEquipes, qtdCircuitos, qtdVoltas);
            break;
        case 7:
            exibirDadosSemMelhorVolta(pilotos, equipes, circuitos, voltas, qtdPilotos, qtdEquipes, qtdCircuitos, qtdVoltas);
            break;
    }
}


void showMenuRelatorios() {
    printf("1-Consultar dados (X)\n");
    printf("2-Pesquisar piloto\n");
    printf("3-Relacionar pilotos de um circuito ou data (X)\n");
    printf("4-Pesquisar circuito (X)\n");
    printf("5-Pesquisar pilotos pela data (X)\n");
    printf("6-Pesquisar pilotos, equipes e circuitos que realizaram voltas menores que um dado tempo\n");
    printf("7-Exibir pilotos, equipes ou circuitos que nao fizeram uma melhor volta\n");
}


// void consultarDados() {

// }


void pesquisarPiloto(struct Piloto pilotos[], int qtdPilotos) {
    char pesquisa[80];
    int i, indice = 0, indices[qtdPilotos];

    printf("Pesquisa piloto(a) >> ");
    scanf("%[^\n]s", &pesquisa); clean_stdin(); system("cls");
    strcpy(pesquisa, toLowerString(pesquisa));
    for(i=0; i<qtdPilotos; i++) {
        if(strstr(toLowerString(pilotos[i].nome), pesquisa) != NULL) {
            indices[indice] = i;
            indice++;
        }
    }
    if(indice == 0) {
        printf("Nenhum dado encontrado.\n");
        return;
    }
    for(i=0; i<indice; i++) {
        printarDadosPiloto(pilotos[indices[i]].codigo, pilotos[indices[i]].nome, pilotos[indices[i]].siglaEquipe,
          pilotos[indices[i]].dataNascimento[0], pilotos[indices[i]].dataNascimento[1], pilotos[indices[i]].dataNascimento[2], 
          pilotos[indices[i]].sexo, pilotos[indices[i]].paisOrigem);
    }
}


// void relacaoPilotoCircuito() {}


// void pesquisarCircuito() {}


// void pesquisaPilotoData() {}


void pesquisarDadosVoltasMenores(struct Piloto pilotos[], struct Equipe equipes[], struct Circuito circuitos[], struct MelhorVolta voltas[], 
  int qtdPilotos, int qtdEquipes, int qtdCircuitos, int qtdVoltas) {
    int i, ii, flag = 0, pesquisa[3], pesquisaTransformada, indiceVolta = 0, indicesVoltas[qtdVoltas], indicePiloto = 0, indiceEquipe = 0, 
      indiceCircuito = 0, indicesPilotos[qtdPilotos], indicesEquipes[qtdEquipes], indicesCircuitos[qtdCircuitos];
    char temp[15];

    leValidaMinSegMillInt(temp, pesquisa, "Pesquise o tempo");
    pesquisaTransformada = pesquisa[0]*60*1000 + pesquisa[1]*1000 + pesquisa[2];
    for(i=0; i<qtdVoltas; i++) {
        if(voltas[i].tempoVolta[0]*60*100 + voltas[i].tempoVolta[1]*1000 + voltas[i].tempoVolta[2] < pesquisaTransformada) {
            printf("IU\n");
            indicesVoltas[indiceVolta] = i;
            indiceVolta++;
        }
    }
    if(indiceVolta > 0) {
        for(i=0; i<indiceVolta; i++) {
            printf("  PILOTOS\n");
            for(ii=0; ii<qtdPilotos; ii++) {
                if(pilotos[ii].codigo == voltas[indicesVoltas[i]].pilotoId) {
                    printarDadosPiloto(pilotos[ii].codigo, pilotos[ii].nome, pilotos[ii].siglaEquipe, 
                      pilotos[ii].dataNascimento[0], pilotos[ii].dataNascimento[1], pilotos[ii].dataNascimento[2], 
                      pilotos[ii].sexo, pilotos[ii].paisOrigem);
                    flag++;
                }
            }
            if(flag == 0) {
                printf("Nenhum dado encontrado.\n");
            }
        }
        // for(i=0; i<indiceVolta; i++) {
        //     for(ii=0; ii<qtdEquipes; ii++) {
        //         if(equipes[ii].codigo == voltas[indiceVolta[i]].pilotoId) {
        //             printarDadosEquipe(equipes[indicesEquipes[i]].nome, equipes[indicesEquipes[i]].sigla, equipes[indicesEquipes[i]].paisOrigem, 0);
        //             flag++
        //         }
        //     }
        //     if(flag == 0) {
        //         printf("Nenhum dado encontrado.\n");
        //     }
        // }
        printf("  CIRCUITOS\n");
        flag = 0;
        for(i=0; i<indiceVolta; i++) {
            for(ii=0; ii<qtdCircuitos; ii++) {
                if(circuitos[ii].codigo == voltas[indicesVoltas[i]].circuitoId) {
                    printarDadosCircuito(circuitos[ii].codigo, circuitos[ii].nome, circuitos[ii].pais, 
                      circuitos[ii].tamanho, circuitos[ii].menorTempoMinSegMilli,
                      circuitos[ii].idPilotoMenorTempo);
                    flag++;
                }
            }
            if(flag == 0) {
                printf("Nenhum dado encontrado.\n");
            }
        }
    }
}


void exibirDadosSemMelhorVolta(struct Piloto pilotos[], struct Equipe equipes[], struct Circuito circuitos[], struct MelhorVolta voltas[], 
  int qtdPilotos, int qtdEquipes, int qtdCircuitos, int qtdVoltas) {
    int i, ii, indicePiloto = 0, indiceEquipe = 0, indiceCircuito = 0, indicesPilotos[qtdPilotos], indicesEquipes[qtdEquipes], indicesCircuitos[qtdCircuitos], indicesVoltas[qtdVoltas], flag = 0;

    for(i=0; i<qtdPilotos; i++) {
        flag = 0;
        for(ii=0; ii<qtdVoltas; ii++) {
            if(pilotos[i].codigo == voltas[ii].pilotoId) {
                flag++;
            }
        }
        if(flag == 0) {
            indicesPilotos[indicePiloto] = i;
            indicePiloto++;
        }
    }
    for(i=0; i<qtdEquipes; i++) {
        flag = 0;
        for(ii=0; ii<qtdVoltas; ii++) {
            if(strcmp(equipes[i].nome, voltas[ii].equipePiloto) == 0) {
                flag++;
                printf("@@ %s - %s\n", equipes[i].nome, voltas[ii].equipePiloto);
            }
        }
        if(flag == 0) {
            indicesEquipes[indiceEquipe] = i;
            indiceEquipe++;
        }
    }
    for(i=0; i<qtdCircuitos; i++) {
        flag = 0;
        for(ii=0; ii<qtdVoltas; ii++) {
            if(circuitos[i].codigo == voltas[ii].circuitoId) {
                flag++;
            }
        }
        if(flag == 0) {
            indicesCircuitos[indiceCircuito] = i;
            indiceCircuito++;
        }
    }
    printf("  PILOTOS\n");
    if(indicePiloto > 0) {
        for(i=0; i<indicePiloto; i++) {
            printarDadosPiloto(pilotos[indicesPilotos[i]].codigo, pilotos[indicesPilotos[i]].nome, pilotos[indicesPilotos[i]].siglaEquipe, 
              pilotos[indicesPilotos[i]].dataNascimento[0], pilotos[indicesPilotos[i]].dataNascimento[1], pilotos[indicesPilotos[i]].dataNascimento[2], 
              pilotos[indicesPilotos[i]].sexo, pilotos[indicesPilotos[i]].paisOrigem);
        }
    } else {
        printf("Nenhum piloto encontrado.\n\n");
    }
    printf("  EQUIPES\n");
    if(indiceEquipe > 0) {
        for(i=0; i<indiceEquipe; i++) {
            printarDadosEquipe(equipes[indicesEquipes[i]].nome, equipes[indicesEquipes[i]].sigla, equipes[indicesEquipes[i]].paisOrigem, 0);
        }
    } else {
        printf("Nenhuma equipe encontrada.\n\n");
    }
    printf("  CIRCUITOS\n");
    if(indiceCircuito > 0) {
        for(i=0; i<indiceCircuito; i++) {
            printarDadosCircuito(circuitos[indicesCircuitos[i]].codigo, circuitos[indicesCircuitos[i]].nome, circuitos[indicesCircuitos[i]].pais, 
              circuitos[indicesCircuitos[i]].tamanho, circuitos[indicesCircuitos[i]].menorTempoMinSegMilli,
              circuitos[indicesCircuitos[i]].idPilotoMenorTempo);
        }
    } else {
        printf("Nenhum circuito encontrado.\n\n");
    }

}

#endif