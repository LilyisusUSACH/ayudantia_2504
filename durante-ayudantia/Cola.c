#include <stdio.h>
#include <stdlib.h>
#include "Cola.h"

nodoCola *crearNodo(char item){
    nodoCola *nuevoNodo;
    nuevoNodo = (nodoCola*) malloc(sizeof(nodoCola));
    nuevoNodo->info = item;
    nuevoNodo->sig = NULL;
    return nuevoNodo;
}

Cola *crearCola(){
    Cola *nuevaCola;
    nuevaCola = (Cola*) malloc(sizeof(Cola*));
    nuevaCola->final = NULL;
    nuevaCola->frente = NULL;
    return nuevaCola;
}

int esColaVacia(Cola *C){
    if(C->final == NULL){
        return 1;
    }else{
        return 0;
    }
}
void encolar(Cola *C,char ch){
    nodoCola *nuevoNodo;
    nuevoNodo = crearNodo(ch);
    if(esColaVacia(C) == 1){
        C->final = nuevoNodo;
        C->frente = nuevoNodo;
    }else{
        nuevoNodo->sig = C->final;
        C->final = nuevoNodo;
    }
}

char desencolar(Cola *C){
    nodoCola *N,*aux;
    N = C->frente;
    aux = C->final;
    if(C->frente != C->final){
        while(aux->sig->sig!=NULL){
            aux = aux->sig;
        }
        C->frente = aux;
        aux->sig = NULL;
    }else{
        C->final = NULL;
        C->frente = NULL;
    }
    return N->info;
}