#include <stdio.h>
#include <string.h>

#define QTD_COLUNAS 100

int removerRepetidos(int v[], int tam) {
    if (tam <= 1)
        return tam;

    int j = 1;

    for (int i = 1; i < tam; i++) {
        if (v[i] != v[j - 1]) {
            v[j] = v[i];
            j++;
        }
    }

    return j;
}

void ordenar(int v[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                int aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

void preencherPrimos(int v[], int tam) {
    int qtd = 0;
    int numero = 2;

    while (qtd < tam) {
        int primo = 1;

        for (int i = 0; i < qtd; i++) {
            if (numero % v[i] == 0) {
                primo = 0;
                break;
            }
        }

        if (primo) {
            v[qtd] = numero;
            qtd++;
        }

        numero++;
    }
}

void maiorPorLinha(int m[][QTD_COLUNAS], int lin, int col, int v[]) {
    for (int i = 0; i < lin; i++) {
        v[i] = m[i][0];

        for (int j = 1; j < col; j++) {
            if (m[i][j] > v[i]) {
                v[i] = m[i][j];
            }
        }
    }
}

void inverterPalavras(char str[]) {
    int inicio = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ') {
            int fim = i - 1;

            while (inicio < fim) {
                char aux = str[inicio];
                str[inicio] = str[fim];
                str[fim] = aux;

                inicio++;
                fim--;
            }

            inicio = i + 1;
        }

        i++;
    }

    int fim = i - 1;

    while (inicio < fim) {
        char aux = str[inicio];
        str[inicio] = str[fim];
        str[fim] = aux;

        inicio++;
        fim--;
    }
}

int main() {
    // Teste da função removerRepetidos
    int v1[] = {3, 3, 4, 5, 6, 6, 6, 7};
    int tam1 = sizeof(v1) / sizeof(v1[0]);
    tam1 = removerRepetidos(v1, tam1);

    printf("removerRepetidos: ");
    for (int i = 0; i < tam1; i++)
        printf("%d ", v1[i]);
    printf("\n");

    // Teste da função ordenar
    int v2[] = {5, 2, 8, 1, 4};
    int tam2 = sizeof(v2) / sizeof(v2[0]);

    ordenar(v2, tam2);

    printf("ordenar: ");
    for (int i = 0; i < tam2; i++)
        printf("%d ", v2[i]);
    printf("\n");

    // Teste da função preencherPrimos
    int v3[5];

    preencherPrimos(v3, 5);

    printf("preencherPrimos: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", v3[i]);
    printf("\n");

    // Teste da função maiorPorLinha
    int m[3][QTD_COLUNAS] = {
        {10, 5, 20},
        {7, 15, 3},
        {9, 4, 12}
    };
    int v4[3];

    maiorPorLinha(m, 3, 3, v4);

    printf("maiorPorLinha: ");
    for (int i = 0; i < 3; i++)
        printf("%d ", v4[i]);
    printf("\n");

    // Teste da função inverterPalavras
    char str[] = "o rato roeu";

    inverterPalavras(str);

    printf("inverterPalavras: %s\n", str);

    return 0;
}
