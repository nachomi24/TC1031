#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 

struct nodo{
    int valor;
    struct nodo *siguiente;
    struct nodo *anterior;
};

struct nodo *raiz = NULL;//inicio

//para borrar
struct nodo *fin=NULL;


int listaVacia(){
    if(raiz==NULL)
        return 1;
    else
        return 0;
}

void yithab(){
    printf("HOla yithab");
}

int longitudLista(){
    int longi=0;
    if(listaVacia()!=1){
        struct nodo *temporal=raiz;
        do{
            longi++;
            temporal=temporal->siguiente;
        }
        while(temporal!=raiz);
    }
    return longi;
}

void insertaLista(int numero){
    printf("Nuevo elemento en el final de la lista: %d \n",numero);
    struct nodo *elemento=malloc(sizeof(struct nodo));
    elemento->valor=numero;
    if(elemento==NULL){
        printf("No se puede crear un elemento en la lista");
        return;
    }
    if(listaVacia()==1){
        elemento->anterior=elemento;
        elemento->siguiente=elemento;
        raiz=elemento;
    }
    else{
        fin=raiz->anterior;
        elemento->siguiente=raiz;
        elemento->anterior=fin;
        raiz->anterior=elemento;
        fin->siguiente=elemento;
        fin=elemento;
    }
}

void insertaCons(int numNodos){
    for (int i = 0; i < numNodos; i++){
        insertaLista(i+1);
    }
}

void eliminaLista(int numero){
    struct nodo *indiceAnterior=raiz->anterior; //Try indiceAnterior = raiz->anterior 
    struct nodo *indiceActual=raiz;
    struct nodo *indiceSiguiente=raiz->siguiente;
    struct nodo *temporal;

    while(indiceActual!=NULL){//2DO (mas bien 2UNDO)
        if(indiceActual->valor==numero){//primer elemento
        //------------------------FOR FUTURE WORK
            if(longitudLista()==1){
                temporal=indiceActual;
                raiz=NULL;//para no quedarse con posiciones de memoria
                fin=NULL;
                printf("Eliminando: %d\n",temporal->valor);
                free(temporal);
                return;
            }
            else{
                temporal=indiceActual;
                printf("Eliminando: %d\n",temporal->valor);
                if(indiceActual==fin){
                    indiceAnterior->siguiente=indiceSiguiente;
                    fin=indiceAnterior;
                }
                else{
                    indiceAnterior->siguiente=indiceSiguiente;
                    indiceSiguiente->anterior=indiceAnterior;
                }
                free(temporal);
                return;
            }
        }
        indiceAnterior=indiceActual;
        indiceActual=indiceActual->siguiente;
        indiceSiguiente=indiceSiguiente->siguiente;
    }
    printf("Elemento: %d no se puede eliminar\n",numero);
}

//Para eliminar
void eliminarNodo(int numero){
    struct nodo *indiceAnterior=raiz->anterior; //Try indiceAnterior = raiz->anterior 
    struct nodo *indiceActual=raiz;
    struct nodo *indiceSiguiente=raiz->siguiente;
    struct nodo *temporal;

    do{
        if(longitudLista()==1){//un elemento
                temporal=indiceActual;
                raiz=NULL;//para no quedarse con posiciones de memoria
                fin=NULL;
                printf("Eliminando: %d\n",temporal->valor);
                free(temporal);
            
        }

        else if (indiceActual==raiz && indiceActual->valor==numero){//primer elemento
            temporal=indiceActual;
            indiceActual=indiceActual->siguiente;
            printf("Eliminando: %d\n",temporal->valor);
            raiz=indiceActual;
            indiceActual->anterior=fin;
            fin->siguiente=raiz;
			free(temporal);
        }

        //Elimina el fin elemento    
        else if(indiceActual==fin && indiceActual->valor==numero){
            temporal=indiceActual;
            indiceActual=indiceActual->siguiente;
            printf("Eliminando: %d\n",temporal->valor);
            fin=indiceAnterior;
            indiceAnterior->siguiente=raiz;
            raiz->anterior=fin;
			free(temporal);
		}
		//Elimina un elemento de en medio	
		else if(indiceActual!=fin && indiceActual!=raiz && indiceActual->valor==numero){
            temporal=indiceActual;
            indiceActual=indiceActual->siguiente;
            printf("Eliminando: %d\n",temporal->valor);
            indiceAnterior->siguiente=temporal->siguiente;
            indiceSiguiente->anterior=temporal->anterior;
			free(temporal);
        }
        //No elimina nada moverse
        else{
            indiceAnterior=indiceActual;
            indiceActual=indiceActual->siguiente;
            indiceSiguiente=indiceSiguiente->siguiente;
            
		}
            
    }while(indiceActual!=raiz);

}

void busquedaRepeticion(int numero){
    int i = 0, contador = 0;
    struct nodo *temporal=raiz;
    temporal = raiz;
    do{
        if (temporal -> valor == numero){
            printf("El numero %d se encuentra en la posicion [%d] \n", numero, i);
            //llamar a la funcion que elimina
            //eliminarNodo(numero);
            //cpigo de eliminar question mark question mark 
            contador++;
            
        }

        temporal = temporal -> siguiente;
        i++;
    }
    while(temporal!=raiz);
    
    printf("El numero %d se repite %d vez/veces \n", numero, contador);
}

void insertarN(int numero, int pos){
    struct nodo *nuevo, *actual;
    int i;
    if(listaVacia()){
        printf("Ta vacia");
    }
    else{
        nuevo = (struct nodo *)malloc(sizeof(struct nodo));
        nuevo->valor = numero;
        actual = raiz;
        if(pos==0){
            struct nodo *fin = raiz->anterior;
            nuevo->siguiente = raiz;
            nuevo->anterior = fin;
            raiz->anterior = nuevo;
            fin->siguiente = nuevo;
            raiz = nuevo;
            return;
        }
        for(i=0; i<=pos-2; i++){
            actual = actual->siguiente;
        }
        nuevo->siguiente = actual->siguiente;
        actual->siguiente = nuevo;
    }
} 

void eliminarTodaLaLista(struct nodo *raiz){
	if (raiz != NULL){
	struct nodo *temporal, *actual;
	actual = raiz -> siguiente;
	
	while(actual != raiz) {
      temporal = actual -> siguiente;
      free(actual);
      actual = temporal;
    }
    free(raiz);
    raiz = NULL;
	}

    printf("c borra\n");
}

void buscarElemento(struct nodo *raiz, int buscar){
	struct nodo *temporal = raiz;
	int encontrado = 0, indice = 0;

	if (temporal != NULL){
        while(1){
            indice++;
            if (temporal -> valor == buscar){
                encontrado++;
                break;
            }
            temporal = temporal -> siguiente;

            if (temporal ==raiz){
                break;
            }
        }
        if (encontrado == 1){
            printf("%i posicion [%i]\n", buscar, indice-1);
        } 
        else{
            printf("%i no esta en la lista\n", buscar);
        }
    }
    else {
        printf("La lista está vacía\n");
    }
}

void imprimir(){
    if (listaVacia()==0) {
        struct nodo *elemento = raiz;
        do {
            printf("%i ",elemento->valor);
            elemento = elemento->siguiente;
        } while (elemento != raiz);
        printf("\n");
    }
}


//porfin porfin es el main porfin dios ayudame
void main(){
    printf("Uso de una lista doblemente ligada circular\n\n");

    printf("Operaciones\"insercion\"\n");
    insertaLista(1);
    insertaLista(2);
    insertaLista(3);
    insertaLista(1);
    insertaLista(8);
    printf("\n");

    // printf("Operaciones\"cuenta nodos\"\n");
    // printf("El numero de nodos es: %d\n",longitudLista());
    // printf("\n");
    
    // printf("Operaciones\"eliminar\"\n");
    // eliminarNodo(1);
    // printf("\n");

    printf("Operaciones\"mostrar lista\"\n");
    imprimir();
    printf("\n");

    // printf("Operaciones\"inserta nodos consecutivos\"\n");
    // insertaCons(2);
    // printf("\n");

    // printf("Operaciones\"mostrar lista\"\n");
    // imprimir();
    // printf("\n");

    //printf("Operaciones\"borrrar toda la lista\"\n");
    //eliminarTodaLaLista(raiz);
    // printf("\n");
    // insertaLista(4);
    // insertaLista(2);
    // insertaLista(6);
    // insertaLista(6);

    // printf("\nOperaciones\"mostrar lista\"\n");
    // imprimir();
    // printf("\n");

    // printf("\nOperaciones\"busqueda\"\n");
    // buscarElemento(raiz,1);
    // printf("\n");

    printf("\nOperaciones\"busqueda todos repetidos si\"\n");
    busquedaRepeticion(1);
    printf("\n");


    // printf("\nOperaciones\"insertar ene\"\n");
    // insertarN(7,0);
    // imprimir();
    // printf("\n");



    // printf("Operaciones\"mostrar desde final\"\n");
    // mostrarElementosListaFin();
    // printf("\n");
}