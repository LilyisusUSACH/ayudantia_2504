#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"
#include "Cola.h"

// cd "/home/lilyisus/Documentos/EDA_ayudante/Ayudantia_25_04/" && gcc main_ejemplos.c Pila.c Cola.c -o main_ejemplos && "/home/lilyisus/Documentos/EDA_ayudante/Ayudantia_25_04/"main_ejemplos

int main()
{
    Cola *firstCola = crearCola();
    encolar(firstCola,crearNodoCola(10));
    encolar(firstCola,crearNodoCola(9));
    encolar(firstCola,crearNodoCola(0));
    encolar(firstCola,crearNodoCola(12));
    encolar(firstCola,crearNodoCola(15));
    while (isColaVacia(firstCola) != 1)
    {
        printf("desencolando : %d \n", desencolar(firstCola)->info);
    }
    Pila *firstPila = crearPila();
    pilaPush(firstPila,crearNodoPila(10));
    pilaPush(firstPila,crearNodoPila(9));
    pilaPush(firstPila,crearNodoPila(0));
    pilaPush(firstPila,crearNodoPila(12));
    pilaPush(firstPila,crearNodoPila(15));
    while(esVacia(firstPila)!=1){
        printf("Pop : %d \n", pilaPop(firstPila)->info);
    }
    return 0;
}