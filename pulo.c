#include <stdio.h>

int pulo_do_gato() {
    //Inputando a quantidade de lajotas
    int C;
    int i = 0;

    do {
        scanf("%d", &C);
    } while(C < 2 || C > 10000);

    // Criando a lista de tamanho C para armazenar a sequência das cores das lajotas
    int lajotas[10000];

    for(i = 0; i < C; i++) {
        scanf("%d", &lajotas[i]);
    }

    // Calculando os pulos
    i = 0;
    int cont = 0;

    while(i < C - 2) {
        if(lajotas[i] == 1 && lajotas[i + 2] == 1) {
            cont = cont + 1;
            i += 2;
        } else if(lajotas[i] == 1 && lajotas[i + 1] == 1 && lajotas [i + 2] == 0) {
            cont = cont + 1;
            i += 1;
        } else if(lajotas[i] == 1 && lajotas[i + 1] == 0 && lajotas[i + 2] == 0) {
            cont = -1;
            break;
        }
    }

    if(i == C - 2) {
        cont += 1;
    }

    return cont;
}

void main(){
    printf("%d", pulo_do_gato());
}