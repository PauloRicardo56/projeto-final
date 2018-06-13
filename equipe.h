#ifndef _equipe_h
#define _equipe_h

/*******************************
 * Cadastrar e excluir equipes *
 *******************************/
void menuDadosEquipe() {
    int resposta;
    
    showMenuEquipe();
    resposta = leValidaInt(1, 2, "Digite uma das opcoes do menu");
    switch(resposta) {
        case 1:
            cadastrarEquipe();
            break;
        case 2:
            excluirEquipe();
    }
}


void showMenuEquipe() {
    printf("1-Cadastrar nova equipe\n");
    printf("2-Excluir equipe\n");
}


void cadastrarEquipe() {}


void excluirEquipe() {}

#endif