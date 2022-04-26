typedef struct nodopila{
  char info;
  struct nodopila *sig;
}nodoPila;

typedef struct pila
{
	nodoPila *tope;
}Pila;

// Operaciones
nodoPila *crearNodoPila(char info);
Pila *crearPila();
int esVacia(Pila *P);
void pilaPush(Pila *P,nodoPila *N);
nodoPila *pilaPop(Pila *P);