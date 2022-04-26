typedef struct nodopila{
    char info;
    struct nodopila *sig;
}nodoPila;

typedef struct pila{
    nodoPila *tope;
}Pila;


nodoPila *crearNodoPila(char ch);
Pila *crearPila();
int esVaciaPila(Pila *P);
char pop(Pila *P);
void push(Pila *P,char ch);