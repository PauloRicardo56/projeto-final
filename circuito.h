#ifndef _circuito_h
#define _circuito_h


/*********************************
 * Cadastrar e excluir circuitos *
 *********************************/
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


void cadastrarCircuito() {}


void alterarCircuito() {}

#endif