#include <stdio.h>
#include <stdlib.h>

int verificarResultados(int n, int resultados[]) {
    int i;

    for(i = 1; i < n; i++) {
        if(resultados[i] != resultados[i-1]) {
            return -1;
        }
    }

    return resultados[0];
}

int calculoDasLinhas(int n, int matriz[10][10]) {
    int i, j, resultado, somas[10];

    for(i = 0; i < n; i++) {
        resultado = 0;

        for(j = 0; j < n; j++) {
            resultado += matriz[i][j];
        }

        somas[i] = resultado;
    }

    return verificarResultados(n, somas);
}

int calculoDasColunas(int n, int matriz[10][10]) {
    int i, j, resultado, somas[10];

    for(i = 0; i < n; i++) {
        resultado = 0;

        for(j = 0; j < n; j++) {
            resultado += matriz[j][i];
        }

        somas[i] = resultado;
    }

    return verificarResultados(n,somas);
}

int calculoDasDiagonais1(int n, int matriz[10][10]){
    int i, resultado = 0;

    for(i = 0; i < n; i++) {
        resultado += matriz[i][i];
    }

    return resultado;
}

int calculoDasDiagonais2(int n, int matriz[10][10]) {
    int i, resultado = 0;

    for(i = 0; i < n; i++) {
        resultado += matriz[i][n - i - 1];
    }

    return resultado;
}

void main(){
    int n, i, j, linhas, colunas, diagonal1, diagonal2;
    int matriz[10][10];

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    linhas = calculoDasLinhas(n, matriz);
    colunas = calculoDasColunas(n, matriz);
    diagonal1 = calculoDasDiagonais1(n, matriz);
    diagonal2 = calculoDasDiagonais2(n, matriz);

    if(linhas == colunas && linhas == diagonal1 && linhas == diagonal2) {
        printf("%d", linhas);
    }else{
        printf("%d", -1);
    }
}