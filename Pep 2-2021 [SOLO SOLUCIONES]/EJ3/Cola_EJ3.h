//ESTRUCTURA DE DATOS TDA COLA
struct nodo{
  int T_A;
  int T_LL;
  struct nodo *sig;
};
typedef struct nodo Nodo;

struct cola{
  Nodo *frente;
  Nodo *fin;
};
typedef struct cola Cola;

Cola *crearCola();
int isColaVacia(Cola *C);
void encolar(Cola *C, Nodo *N);
Nodo *desencolar(Cola *C);

