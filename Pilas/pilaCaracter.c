#include <stdio.h>
#include <stdlib.h>

struct nodo {
	char dato;
	struct nodo *cima;
};
typedef struct nodo Nodo;

void push(Nodo **pila, char dato) {
    Nodo *nuevo = malloc(sizeof(Nodo));
    nuevo->dato = dato;
	nuevo->cima = *pila;
	*pila=nuevo;
}

char pop(Nodo **pila){
	Nodo *auxiliar;
	char salida;
	auxiliar = *pila;
	*pila = auxiliar->cima;
	salida = auxiliar->dato;
	free(auxiliar);
	return salida;
}

int pilaVacia(Nodo **pila){
	return *pila==NULL;    
}

void mostrar(Nodo *pila){	
	while(pila != NULL){
		printf("\n%c ", pila->dato);
		pila = pila->cima;
	}
}

int buscar(Nodo *pila, int buscar){	
	while(pila != NULL){
		if (pila->dato==buscar){
			return 1;
		}
		pila = pila->cima;
	}
	return 0;
}

int main(){
	Nodo *pila = NULL;
	
	push(&pila ,'d');

	printf("%c \n", pop(&pila));;
	
	printf("\nContenido: \n");
	mostrar(pila);
}
