#include <stdio.h>
#include <stdlib.h>

#include "Cola.h"
#include "Pila.h"

typedef struct nodolista{
    char info;
    struct nodolista *siguiente;
}nodoLista;

typedef struct lista{
    nodoLista *head;
}Lista;

Lista *crearLista(){
    Lista *newLista;
    newLista = (Lista*) malloc(sizeof(Lista));
    newLista->head = NULL;
    return newLista;
}

void addLista(Lista *L, nodoLista *N){
    if(L->head == NULL){
        L->head = N;
    }else{
        N->siguiente = L->head;
        L->head = N;
    }
}

nodoLista *extraerLista(Lista *L){
    nodoLista *aux;
    aux = L->head;
    if (aux == NULL)
    {
       return NULL;
    }else{
        L->head = aux->siguiente;
        aux->siguiente = NULL;
        return aux;
    }
}

nodoLista *crearNodoLista(char c){
    nodoLista *newNodo;
    newNodo = (nodoLista*) malloc(sizeof(nodoLista));
    newNodo->info = c;
    newNodo->siguiente = NULL;
    return newNodo;
}

void imprimirLista(Lista *L){
    nodoLista *aux;
    aux = L->head;
    while (aux!=NULL)
    {
        printf("%c -> ",aux->info);
        aux = aux->siguiente;
    }
    printf("NULL \n");
    
}

int es_par(int i){
    if(i%2 == 0){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int largo = 6;
    int llave[7] = {2,3,4,1,6,1};
    int i = 0;

    Cola *C;
    C = crearCola();

    Pila *P;
    P = crearPila();

    Lista *lista;
    lista = crearLista();
    addLista(lista, crearNodoLista('e'));
    addLista(lista, crearNodoLista('t'));
    addLista(lista, crearNodoLista('r'));
    addLista(lista, crearNodoLista('a'));
    addLista(lista, crearNodoLista('m'));
    addLista(lista, crearNodoLista('s'));
    addLista(lista, crearNodoLista('o'));
    addLista(lista, crearNodoLista('m'));
    addLista(lista, crearNodoLista('i'));
    addLista(lista, crearNodoLista('d'));
    addLista(lista, crearNodoLista('a'));
    addLista(lista, crearNodoLista('v'));
    addLista(lista, crearNodoLista('n'));
    addLista(lista, crearNodoLista('i'));
    addLista(lista, crearNodoLista('y'));
    addLista(lista, crearNodoLista('o'));
    addLista(lista, crearNodoLista('h'));
    imprimirLista(lista);
    while(i<largo){
        if(es_par(llave[i]) == 1){
            int digito_par = llave[i];
            while (digito_par > 0)
            {
                push(P,extraerLista(lista)->info);
                digito_par--;
            } 
        }else{
            int digito_impar = llave[i];
            while (digito_impar > 0)
            {
                encolar(C,extraerLista(lista)->info);
                digito_impar--;
            } 
        }
        i++;
    }
    while (esColaVacia(C)!=1)
    {
        char c = desencolar(C);
        push(P,c);
    }
    while (esVaciaPila(P)!=1)
    {
        printf(" %c ->",pop(P));
    }

    
    return 0;
}
