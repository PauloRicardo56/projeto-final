#ifndef _structs_h
#define _structs_h


struct Piloto {
    int codigo, dataNascimento[3]; //Dia, mes e ano
    char nome[50], siglaEquipe[4], sexo, paisOrigem[20];
};


struct Equipe {
    char nome[40], sigla[4], paisOrigem[20];
};


#endif