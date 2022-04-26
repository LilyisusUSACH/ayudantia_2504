//ESTRUCTURA DE DATOS TDA COLA
typedef struct nodocola{
  char info;
  struct nodocola *sig;
}nodoCola;

struct cola{
  nodoCola *frente;
  nodoCola *fin;
};
typedef struct cola Cola;

nodoCola *crearNodoCola(char info);
Cola *crearCola();
int isColaVacia(Cola *C);
void encolar(Cola *C, nodoCola *N);
nodoCola *desencolar(Cola *C);