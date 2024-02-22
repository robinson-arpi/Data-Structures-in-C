#include <stdio.h>
#include <stdlib.h>
#define DIM 30

struct nodo {
	char *cadena;
	struct nodo *cima;
};

typedef struct nodo Nodo;

void push(Nodo **pila, char llegada[]){
    Nodo *nuevo = malloc(sizeof(Nodo));
    nuevo->cadena=malloc(strlen(llegada) * sizeof(char));
    strcpy(nuevo->cadena,llegada);
	nuevo->cima = *pila;
	*pila=nuevo;
}

char *pop(Nodo **pila){
	Nodo *auxiliar = *pila;
	char *salida=malloc(DIM *sizeof(char));
	
	*pila = auxiliar->cima;
	strcpy(salida, auxiliar->cadena);
	free(auxiliar);
	
	return salida;
}

int pilaVacia(Nodo **pila){
	return *pila==NULL;    
}

void mostrar(Nodo *pila){	
	while(pila != NULL){
		printf("\n%s ", pila->cadena);
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
	nodoPila *pila = NULL;
	push(&pila ,"buenas1");
	push(&pila ,"buenas2");
	push(&pila ,"buenas3");
	push(&pila ,"buenas4");
	push(&pila ,"buenas5");
	push(&pila ,"buenas6");
	
	printf("\nContenido: \n");
	mostrar(pila);
	
	
	
	printf("%s \n", pop(&pila));
	printf("%s \n", pop(&pila));
	printf("%s \n", pop(&pila));;
	
	printf("\nContenido: \n");
	mostrar(pila);
}
