#ifndef _volta_h
#define _volta_h

/*********
 * VOLTA *
 *********/
void menuDadosVolta() {
    int resposta;
    
    showMenuVolta();
    leValidaInt(1, 3, "Digite uma das opcoes do menu");
    switch(resposta) {
        case 1:
            cadastrarVolta();
            break;
        case 2:
            alterarVolta();
            break;
        case 3:
            excluirVolta();
    }
}


void showMenuVolta() {
    printf("1-Cadastrar melhor volta\n");
    printf("2-Alterar melhor volta\n");
    printf("3-Excluir melhor volta\n");
}


void cadastrarVolta() {}


void alterarVolta() {}


void excluirVolta() {}

#endif