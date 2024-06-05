//quickSort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool Existe(int valores[], int tam, int valor) {
    for (int i = 0; i < tam; i++) {
        if (valores[i] == valor)
            return true;
    }
    return false;
}

void Ale(int numeros[], int quantNumeros, int Limite) {
    srand(time(NULL));

    int v;
    for (int i = 0; i < quantNumeros; i++) {
        v = rand() % Limite;
        while (Existe(numeros, i, v)) {
            v = rand() % Limite;
        }
        numeros[i] = v;
    }
}

int particiona(int *v, int inicio, int fim){
    int pivo = (v[inicio]+v[fim]+v[(inicio+fim)/2])/3;
    while(inicio<fim){
        while(inicio<fim && v[inicio] <= pivo)
            inicio = inicio + 1;
        while(inicio<fim && v[fim]>pivo)
            fim = fim - 1;
        int aux = v[inicio];
        v[inicio]=v[fim];
        v[fim]=aux;
    }
    return inicio;
}

void quickSort(int *v, int inicio, int fim){
    if(inicio<fim){
        int pos = particiona(v,inicio,fim);
        quickSort(v, inicio, pos - 1);
        quickSort(v, pos, fim);
    }
}

int main() {
    clock_t tempototal;
    int a = 100000;
    int numeros[a]; 

    tempototal = clock ();
    Ale(numeros, a, 200000);
    quickSort(numeros, 0, a);
    tempototal = clock() - tempototal;


    printf("Tempo total: %lf segundos", ((float)tempototal)/CLOCKS_PER_SEC);
    return 0;
}