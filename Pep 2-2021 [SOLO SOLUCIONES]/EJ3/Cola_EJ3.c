#include "Cola_EJ3.h"
#include <stdio.h>
#include <stdlib.h>

Cola *crearCola(){
    Cola *C;
    C = (Cola*) malloc(sizeof(Cola*));
    C->fin = NULL;
    C->frente = NULL;
    return C;
}

int isColaVacia(Cola *C){
    if(C->fin == NULL){
        return 1;
    }
    return 0;
}

void encolar(Cola *C,Nodo *N){
    if(isColaVacia(C)==1){
        C->fin = N;
        C->frente = N;
    }else{
        N->sig = C->fin;
        C->fin = N;
    }
}

Nodo *desencolar(Cola *C){
    Nodo *N,*aux;
    N = C->frente;
    aux = C->fin;
    if(C->frente != C->fin){
        while(aux->sig->sig!=NULL){
            aux = aux->sig;
        }
        C->frente = aux;
        aux->sig = NULL;
    }else{
        C->fin = NULL;
        C->frente = NULL;
    }
    return N;
}