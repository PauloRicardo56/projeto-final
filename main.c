#include <stdio.h>

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


void showMenu() {}


int leValidaInt() {}


void menuDadosPiloto() {}


void menuDadosEquipe() {}


void menuDadosCircuito() {}


void menuDadosVolta() {}
