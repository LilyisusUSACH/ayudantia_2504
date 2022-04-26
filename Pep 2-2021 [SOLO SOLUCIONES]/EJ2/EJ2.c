#include <stdio.h>
#include <stdlib.h>
#include "piladoble.h"

// ejecutar con: gcc ./EJ2/EJ2.c ./EJ2/piladoble.c -o try_EJ2
// ./try_EJ2

int main()
{
    Piladoble *Pila1;
    int N = 10;
    Pila1 = crearPilaDoble(N);
    printf(" %d \n",capacidad(Pila1));

    push(Pila1,1,1);

    push(Pila1,2,3);

    push(Pila1,2,4); // ya esta completa

    printf(" Tope 1 : %d \n",tope(Pila1,1));
    printf(" Tope 2 : %d \n",tope(Pila1,2));

    for (int i = 0; i < 10; i++)
    {
        printf(" %d: %d ->",i,Pila1->array[i]);
    }

    printf("\n---------------\n");
    pop(Pila1,1,N);
    pop(Pila1,1,N);
    pop(Pila1,1,N);
    pop(Pila1,2,N);
    pop(Pila1,2,N);
    pop(Pila1,1,N);
    pop(Pila1,1,N);
    pop(Pila1,1,N);
    pop(Pila1,2,N);
    pop(Pila1,2,N);

    push(Pila1,1,3);

    for (int i = 0; i < 10; i++)
    {
        printf(" %d: %d ->",i,Pila1->array[i]);
    }

    return 0;
}
