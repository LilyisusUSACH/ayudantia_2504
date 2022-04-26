#include <stdio.h>
#include <stdlib.h>
#include "piladoble.h"

Piladoble *crearPilaDoble(int N){
    Piladoble *P;
    P = malloc(sizeof(Piladoble));
    P->array = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        P->array[i] = 0;
    }
    P->T1 = 0;
    P->T2 = N-1;
    return P;
}

int capacidad(Piladoble *P){
    return (P->T2 - P->T1 + 1);
}

void push(Piladoble *P,int pila,int X){
    if(capacidad(P) > 0){
        if(pila == 1){
            P->array[P->T1] = X;
            P->T1 = P->T1 + 1;
        }else if(pila == 2){
            P->array[P->T2] = X;
            P->T2 = P->T2 - 1;
        }
    }else{
        printf("La pila doble ya esta completa \n");
    }
}

int pop(Piladoble *P,int pila,int N){
    if(pila == 1 && P->T1>0){
        P->array[P->T1-1] = 0;
        P->T1 = P->T1 - 1;
    }else if(pila == 2 && P->T2<N-1){
        P->array[P->T2+1] = 0;
        P->T2 = P->T2 + 1;
    }
}

int tope(Piladoble *P,int pila){
    if(pila == 1){
        return P->array[P->T1-1];
    }else if(pila == 2){
        return P->array[P->T2+1];
    }
}
