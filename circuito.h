#ifndef _circuito_h
#define _circuito_h


/* * * * * * * * * * * * * * * * *
 * Cadastrar e excluir circuitos *
 * * * * * * * * * * * * * * * * */
void menuDadosCircuito() {
    int resposta;
    
    showMenuCircuito();
    resposta = leValidaInt(1, 2, "Digite uma das opcoes do menu");
    switch(resposta) {
        case 1:
            cadastrarCircuito();
            break;
        case 2:
            alterarCircuito();
    }
}


void showMenuCircuito() {
    printf("1-Cadastrar novo circuito\n");
    printf("2-Alterar circuito\n");
}


void cadastrarCircuito(struct Circuito circuitos[], int *qtdCircuitos) {
    int i;
    char temp[15];

    leValidaNome(circuitos[*qtdCircuitos].nome, 0, "Nome do circuito");
    leValidaNome(circuito[*qtdCircuitos].pais, 0, "País do circuito");
    leValidaFloat(3, 20, "Tamanho do circuito (Km)");
    leValidaMinSegMillInt(temp, circuito[*qtdCircuitos].menorTempoMinSegMilli, "Menor tempo do circuito");
    idPilotoMenorTempo = leValidaInt()
}





void alterarCircuito() {}


#endif