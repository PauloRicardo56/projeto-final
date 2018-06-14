#ifndef _piloto_h
#define _piloto_h

/****************************************
 * Cadastrar, alterar e remover pilotos *
 ****************************************/
void menuDadosPiloto(struct Piloto pilotos[], int *qtdPilotos) {
    int resposta;
    
    showMenuPiloto();
    resposta = leValidaInt(1, 3, "Digite uma das opcoes do menu");
    switch(resposta) {
        case 1:
            cadastrarPiloto(pilotos, qtdPilotos);
            break;
        case 2:
            alterarPiloto();
            break;
        case 3:
            removerPiloto(pilotos, qtdPilotos);
    }
}


void showMenuPiloto() {
    printf("1-Cadastrar piloto\n");
    printf("2-Alterar piloto\n");
    printf("3-Remover piloto\n");
}


void cadastrarPiloto(struct Piloto pilotos[], int *qtdPilotos) {
    leValidaCodigo(&pilotos[*qtdPilotos].codigo, pilotos, *qtdPilotos, "Codigo do piloto");
    leValidaNome(pilotos[*qtdPilotos].nome, "Nome do piloto");
}


void alterarPiloto() {}


void removerPiloto(struct Piloto pilotos[], int *qtdPilotos) {}




#endif