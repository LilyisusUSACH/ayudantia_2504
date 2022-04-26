#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"

nodoPila *crearNodoPila(char ch){
    nodoPila *nuevoNodo;
    nuevoNodo = (nodoPila*) malloc(sizeof(nodoPila));
    nuevoNodo->info = ch;
    nuevoNodo->sig = NULL;
    return nuevoNodo;
}

Pila *crearPila(){
    Pila *P;
    P = (Pila*) malloc(sizeof(Pila*));
    P->tope = NULL;
    return P;
}

int esVaciaPila(Pila *P){
    if(P->tope == NULL){
        return 1;
    }else{
        return 0;
    }
}
char pop(Pila *P){
    nodoPila *aux;
    if(esVaciaPila(P)!=1){
        aux = P->tope;
        P->tope = P->tope->sig;
        return aux->info;
    }else{
        return ' ';
    }
}
void push(Pila *P,char ch){
    nodoPila *nuevoNodo;
    nuevoNodo = crearNodoPila(ch);
    nuevoNodo->sig = P->tope;
    P->tope = nuevoNodo;
}