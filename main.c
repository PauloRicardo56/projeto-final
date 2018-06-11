//Todo "leValida" vai estar em validacoes.h


#include <stdio.h>


struct Piloto {
    int id;
    char nome[30], siglaEquipe[4], dataNasc[11], sexo, paisOrigem[20];
};


struct Equipe {
    char nome[40], sigla[4], paisOrigem[20];
};


struct Circuito {
    int codigo, idPilotoMenorTempo;
    char nome[30], pais[20];
    float tamanho;
    long int menorTempo; //Podemos fazer em milisegundos e na hora de apresentar converter para minutos e segundos.
};


struct MelhorVolta {
    int pilotoId;
    char equipePiloto[40], voltaData[11];
    long int tempoVolta;
};    


int main() {
    int resposta;
    
    do {
        showMenu();
        resposta = leValidaInt(1, 5, "Informe uma das opcoes do menu");
        
        switch(resposta) {
            case '1':
                menuDadosPiloto();
                break;
            case '2':
                menuDadosEquipe();
                break;
            case '3':
                menuDadosCircuito();
                break;
            case '4':
                menuDadosVolta();
                break;
            case '5':
        }
    } while(resposta != 5);
    
    return 0;
}


void showMenu() {
    printf("1-Menu dos pilotos\n");
    printf("2-Menu das equipes\n");
    printf("3-Menu dos circuitos\n");
    printf("4-Menu das voltas\n");
}

/*
PODEMOS COLOCAR CADA PARTE (PILOTO, EQUIPE, CIRCUITO E VOLTAS) EM ARQUIVOS SEPARADOS.
*/

/**********
 * PILOTO *
 **********/
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


/**********
 * EQUIPE *
 **********/
void menuDadosEquipe() {
    int resposta;
    
    showMenuEquipe();
    resposta = leValidaInt(1, 2, "Digite uma das opcoes do menu");
    switch(resposta) {
        case 1:
            cadastrarEquipe();
            break;
        case 2:
            excluitEquipe();
    }
}


void showMenuEquipe() {
    printf("1-Cadastrar nova equipe\n");
    printf("2-Excluir equipe\n");
}


void cadastrarEquipe() {}


void excluirEquipe() {}


/************
 * CIRCUITO *
 ************/
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


/*********
 * VOLTA *
 *********/
void menuDadosVolta() {
    int resposta;
    
    showMenuVolta();
    leValidaInt(1, 3, "Digite uma das pcoes do menu");
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
