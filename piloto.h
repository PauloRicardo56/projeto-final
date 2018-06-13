#ifndef _piloto_h
#define _piloto_h

/****************************************
 * Cadastrar, alterar e remover pilotos *
 ****************************************/
void menuDadosPiloto() {
    int resposta;
    
    showMenuPiloto();
    resposta = leValidaInt(1, 3, "Digite uma das opcoes do menu");
    switch(resposta) {
        case 1:
            cadastrarPiloto();
            break;
        case 2:
            alterarPiloto();
            break;
        case 3:
            removerPiloto();
    }
}


void showMenuPiloto() {
    printf("1-Cadastrar piloto\n");
    printf("2-Alterar piloto\n");
    printf("3-Remover piloto\n");
}


void cadastrarPiloto() {}


void alterarPiloto();


void removerPiloto();




#endif