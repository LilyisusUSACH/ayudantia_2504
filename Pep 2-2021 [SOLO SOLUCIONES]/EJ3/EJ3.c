#include "Cola_EJ3.h"
#include <stdlib.h>
#include <stdio.h>

// Ejecutar con gcc ./EJ3/EJ3.c ./EJ3/Cola_EJ3.c -o try_EJ3
// ./try_EJ3

void llegada(Cola *C,int Tiempo,int intervalo,int *PS){
    if ((Tiempo % intervalo) == 0)
    {    
        Nodo *nuevoPaciente;
        nuevoPaciente = (Nodo*) malloc(sizeof(Nodo));
        nuevoPaciente->T_LL = Tiempo;
        nuevoPaciente->T_A = -1;
        nuevoPaciente->sig = NULL;
        encolar(C,nuevoPaciente);
        *PS+=1;
    }
}

int atender(int T){
    if(T == 15 || T == 39){
        return 1;
    } return 0;
}

int main()
{
    int T_max = 45,intervalo = 10;

    Cola *PPA,*PA;
    PA = crearCola();
    PPA = crearCola();
    
    int Tiempo = 0,PS = 0, PV = 0;
    while(Tiempo <= T_max){
        llegada(PPA,Tiempo,intervalo,&PS);
        if(atender(Tiempo) == 1){
            while (isColaVacia(PPA) != 1)
            {
                Nodo *paciente_a_atender;
                paciente_a_atender = desencolar(PPA);
                paciente_a_atender->T_A = Tiempo;
                //printf(" %d / %d  \n",paciente_a_atender->T_LL,paciente_a_atender->T_A);
                encolar(PA,paciente_a_atender);
                PS--;
                PV++;
                Tiempo++;
                llegada(PPA,Tiempo,intervalo,&PS);
            }
        }
        Tiempo++;
        //printf(" %d sec. \n",Tiempo);
    }

    float t_espera = 0, i = 0;
    printf("VACUNADOS \n");
    while (isColaVacia(PA) != 1)
    {
        Nodo *aux;
        aux = desencolar(PA);
        printf(" %d / %d en %d seg. ---> ",aux->T_LL,aux->T_A, (aux->T_A - aux->T_LL));
        t_espera += (aux->T_A - aux->T_LL);
        i++;
    }
    printf("\nSIN VACUNAR \n");
    while (isColaVacia(PPA) != 1)
    {
        Nodo *aux;
        aux = desencolar(PPA);
        printf(" %d ---> ",aux->T_LL);
    }
    printf("\nT de espera promedio = %.2f \n",(t_espera/i));
    printf("Pacientes vacunado = %d \n",PV);
    printf("Pacientes sin vacunar = %d \n",PS);
    return 0;
}
