typedef struct piladoble{
    int *array;
    int T1;
    int T2;
}Piladoble;

Piladoble *crearPilaDoble(int N);

int capacidad(Piladoble *P);

void push(Piladoble *P,int pila,int X);

int pop(Piladoble *P,int pila, int N);

int tope(Piladoble *P,int pila);
