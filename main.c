#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"
#include "Cola.h"

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

nodoLista *crearNodoLista(char c){
    nodoLista *newNodo;
    newNodo = (nodoLista*) malloc(sizeof(nodoLista));
    newNodo->info = c;
    newNodo->siguiente = NULL;
    return newNodo;
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
    if(L->head == NULL){
        return NULL;
    }else{
        nodoLista *aux;
        aux = L->head;
        L->head = aux->siguiente;
        return aux;
    }
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

int es_par(int x){
    if(x%2 == 0){
        return 1;
    }else{
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    int llave[7] = {2,3,4,1,6,1};
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

    int i = 0;
    int j;
    Pila *P;
    P = crearPila();
    Cola *C;
    C = crearCola();
    while(i<6){
        j = llave[i];
        if(es_par(j) == 1){
            while(j>0){
                pilaPush(P,crearNodoPila(extraerLista(lista)->info));
                j--;
            }
        }else{
            while(j>0){
                encolar(C,crearNodoCola(extraerLista(lista)->info));
                j--;
            }
        }
        //imprimirLista(lista);
        i++;
    }
    while (isColaVacia(C) != 1)
    {
        pilaPush(P,crearNodoPila(desencolar(C)->info));
    }
    while(esVacia(P)!=1){
        printf("%c -> ",pilaPop(P)->info);
    }
    printf("NULL \n");
    return 0;
}
