#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct colaPrioridades{
    int valor; 
    int prioridad;
} colaConPrioridad[MAX];

/*indica el índice del último elemento de la cola con prioridades... 
inicializado en -1 ya que está vacía*/
int indice = -1;

int colaVacia(){
    if (indice == -1)
        return 1;
    else
        return 0;
}

int colaLlena(){
    if (indice == MAX-1)
        return 1;
    else 
        return 0;
}

void enqueue(int v, int p){
    indice++;
    colaConPrioridad[indice].valor = v;
    colaConPrioridad[indice].prioridad = p;
}

int obtenerPrioridadMasAlta(){
    int i, p= -1;
    if(!colaVacia())
    {
        for (i = 0; i <= indice; i++)
        {
            if (colaConPrioridad[i].prioridad > p)
                p = colaConPrioridad[i].prioridad;
        }
    }
    return p;
}

int dequeue(){
    int i, j, p, valor;
    p = obtenerPrioridadMasAlta();
    for (i = 0; i <= indice; i++)
    {
        if(colaConPrioridad[i].prioridad == p)
        {
            valor = colaConPrioridad[i].valor;
            break;
        }
    }
    if (i < indice)
    {
        for(j = i; j < indice; j++)
        {
            colaConPrioridad[j].valor = colaConPrioridad[j+1].valor;
            colaConPrioridad[j].prioridad = colaConPrioridad[j+1].prioridad;
        }
    }
    indice--;
    return valor; 
}

void mostrarElementosEnCola(){
    for (int i = 0;i<=indice;i++)
    {
        printf("Valor, prioridad: (%d,%d) \n", colaConPrioridad[i].valor, colaConPrioridad[i].prioridad);
    }
}

void main(){
    enqueue(37,1);
    enqueue(29,1);
    enqueue(30,3);
    enqueue(27,2);
    enqueue(70,5);
    enqueue(35,2);
    

    printf("\n Antes de dequeue por prioridad: \n");
    mostrarElementosEnCola();

    dequeue(); //el elemento con máxima prioridad se elimina
    dequeue(); //el elemento con máxima prioridad se elimina

    /*printf("\nLa prioridad mas alta en la cola es: \n");
    obtenerPrioridadMasAlta();*/

    printf("Despues de dequeue por prioridad: \n");
    mostrarElementosEnCola();  
}
