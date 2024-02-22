#include <stdio.h>
#include <stdlib.h>

struct Nodo {
	int dato;
	struct Nodo *cima;
};

typedef struct Nodo *nodoPila;

void push(nodoPila *pila, int dato) {
    nodoPila nuevo = malloc(sizeof(nodoPila));
	nuevo->dato = dato;
	nuevo->cima = *pila;
	*pila=nuevo;
}

int pop(nodoPila *pila){
	nodoPila auxiliar;
	int dato;
	
	auxiliar = *pila;
	*pila = auxiliar->cima;
	dato = auxiliar->dato;
	free(auxiliar);
	return dato;

}

short int pilaVacia(nodoPila *pila){
	return pila==NULL;    
}

void mostrar(nodoPila pila){	
	while(pila != NULL){
		printf("\n%d ", pila->dato);
		pila = pila->cima;
	}
}

int buscar(nodoPila pila, int buscar){	
	while(pila != NULL){
		if (pila->dato==buscar){
			return 1;
		}
		pila = pila->cima;
	}
	return 0;
}

int main(){
	nodoPila pila = NULL;
	push(&pila ,7);
	push(&pila ,0);
	push(&pila ,9);
	push(&pila ,8);
	push(&pila ,1);
	
	printf("%d \n", pop(&pila));
	printf("%d \n", pop(&pila));
	printf("%d \n", pop(&pila));;
	
	printf("\nContenido: \n");
	mostrar(pila);
}
