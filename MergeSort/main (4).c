#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

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

void merge(int *V, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim-inicio+1;
    p1 = inicio;
    p2 = meio+1;
    temp = (int *) malloc(tamanho*sizeof(int));
    if(temp != NULL){
        for(i=0; i<tamanho; i++){
            if(!fim1 && !fim2){
                if(V[p1] < V[p2])
                    temp[i]=V[p1++];
                else
                    temp[i]=V[p2++];
                if(p1>meio) fim1=1;
                if(p2>fim) fim2=1;
            }else{
                if(!fim1)
                    temp[i]=V[p1++];
                else
                    temp[i]=V[p2++];
            }
        }
        for(j=0, k=inicio; j<tamanho; j++, k++)
            V[k]=temp[j];
    }
    free(temp);
}

int mergeSort(int *V, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = floor((inicio+fim)/2);
        mergeSort(V,inicio,meio);
        mergeSort(V,meio+1,fim);
        merge(V,inicio,meio,fim);
    }
}


int main() {
    clock_t tempototal;
    int x = 10000;
    int numeros[x]; 
    
    tempototal = clock ();
    Ale(numeros, x, 20000);
    mergeSort(numeros, 0, x);
    
    tempototal = clock() - tempototal;

    printf("Tempo total: %lf segundos", ((float)tempototal)/CLOCKS_PER_SEC);
    
    
    return 0;
}