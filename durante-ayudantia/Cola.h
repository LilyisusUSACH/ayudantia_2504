typedef struct nodocola{
    char info;
    struct nodocola *sig;
}nodoCola;

typedef struct cola{
    nodoCola *frente;
    nodoCola *final;
}Cola;

nodoCola *crearNodo(char item);
Cola *crearCola();
int esColaVacia(Cola *C);

void encolar(Cola *C,char ch);
char desencolar(Cola *C);