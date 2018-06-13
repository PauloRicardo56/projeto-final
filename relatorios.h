#ifndef _relatorios_h
#define _relatorios_h

/**************
 * RELATORIOS *
 **************/
void menuRelatorios() {
    int resposta;
    
    showMenuRelatorios();
    resposta = leValidaInt(1, 7, "Digite uma das opcoes do menu");
    switch(resposta) {
        case 1:
            consultarDados();
            break;
        case 2:
            pesquisarPiloto();
            break
        case 3:
            relacaoPilotoCircuito();
            break;
        case 4:
            pesquisarCircuito();
            break();
        case 5:
            pesquisaPilotoData();
            break;
        case 6:
            pesquisarDadosVoltasMenores();
            break;
        case 7:
            exibirDadosSemMelhorVolta();
    }
}


void showMenuRelatorios() {
    printf("1-Consultar dados\n");
    printf("2-Pesquisar piloto\n");
    printf("3-Relacionar pilotos de um circuito ou data\n");
    printf("4-Pesquisar circuito\n");
    printf("5-Pesquisar pilotos pela data\n");
    printf("6-Pesquisar pilotos, equipes e circuitos que realizaram voltas menores que um dado tempo\n");
    printf("7-Exibir pilotos, equipes ou circuitos que nao fizeram uma melhor volta\n");
}


void consultarDados() {}


void pesquisarPiloto() {}


void relacaoPilotoCircuito() {}


void pesquisarCircuito() {}


void pesquisaPilotoData() {}


void pesquisarDadosVoltasMenores() {}


void exibirDadosSemMelhorVolta() {}

#endif