#ifndef _structs_h
#define _structs_h


struct Piloto {
    int codigo, dataNascimento[3]; //Dia, mes e ano
    char nome[50], siglaEquipe[4], sexo, paisOrigem[20];
};


struct Equipe {
    char nome[40], sigla[4], paisOrigem[20];
};


struct Circuito {
    int codigo, idPilotoMenorTempo;
    char nome[30], pais[20];
    float tamanho;
    int menorTempoMinSegMilli[3];
};


struct MelhorVolta {
    int pilotoId;
    char equipePiloto[40], voltaData[11];
    long int tempoVolta;
};


#endif