#include "Pila.h"
#include <stdio.h>
#include <stdlib.h>

nodoPila *crearNodoPila(char info){
    nodoPila *nuevoNodo;
    nuevoNodo = (nodoPila *) malloc(sizeof(nodoPila));
    nuevoNodo->info = info;
    nuevoNodo->sig = NULL;
    return nuevoNodo;
}
Pila *crearPila(){
    Pila *newPila;
    newPila = (Pila*) malloc(sizeof(Pila));
    newPila->tope = NULL;
    return newPila;
}
int esVacia(Pila *P){
    if(P->tope == NULL){
        return 1;
    }else{
        return 0;
    }
}
void pilaPush(Pila *P, nodoPila *N){
    if(esVacia(P) == 1){
        P->tope = N;
    }else{
        nodoPila *aux;
        aux = P->tope;
        N->sig = aux;
        P->tope = N;
    }
}
nodoPila *pilaPop(Pila *P){
    if(esVacia(P) == 1){
        return P->tope;
    }else{
        nodoPila *aux;
        aux = P->tope;
        P->tope = aux->sig;
        return aux;
    }
}