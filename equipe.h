#ifndef _equipe_h
#define _equipe_h
#define MAX_LETRAS_SIGLA 3

/* * * * * * * * * * * * * * * *
 * Cadastrar e excluir equipes *
 * * * * * * * * * * * * * * * */
struct Equipe {
    char nome[40], sigla[4], paisOrigem[20];
};


void menuDadosEquipe(struct Equipe equipes[], int *qtdEquipes);
void showMenuEquipe();
void cadastrarEquipe(struct Equipe equipes[], int *qtdEquipes);
// void excluirEquipe();


void menuDadosEquipe(struct Equipe equipes[], int *qtdEquipes) {
    int resposta;
    
    showMenuEquipe();
    resposta = leValidaInt(1, 2, "Digite uma das opcoes do menu");
    switch(resposta) {
        case 1:
            cadastrarEquipe(equipes, qtdEquipes);
            break;
        case 2:
            // excluirEquipe();
    }
}


void showMenuEquipe() {
    printf("1-Cadastrar nova equipe\n");
    printf("2-Excluir equipe\n");
}


void cadastrarEquipe(struct Equipe equipes[], int *qtdEquipes) {
    validaSiglaNaoRepetida(equipes, *qtdEquipes);
    leValidaNome(equipes[*qtdEquipes].nome, 0, "Nome da equipe");
    leValidaNome(equipes[*qtdEquipes].paisOrigem, 1, "Pais de origem");
    (*qtdEquipes)++;
}


void leValidaSiglaNaoRepetida(struct Equipe equipes[], int qtdEquipes) {
    int i, flag = 1;

    leValidaSigla(equipes[qtdEquipes].sigla, MAX_LETRAS_SIGLA, "Sigla da equipe");
    if(qtdEquipes > 0) {
        while(flag > 0) {
            flag = 0;
            for(i=0; i<qtdEquipes; i++) {
                if(strcmp(equipes[i].sigla, equipes[qtdEquipes].sigla) == 0) {
                    printf("Sigla ja cadastrada em outra equipe (%s)\n", equipes[i].nome);
                    leValidaSigla(equipes[qtdEquipes].sigla, MAX_LETRAS_SIGLA, "Informe outra");
                    flag++;
                }
            }
        }
    } else {
        return;
    }
}


// void excluirEquipe() {}


#endif