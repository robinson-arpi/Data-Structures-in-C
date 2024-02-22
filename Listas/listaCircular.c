#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int dato;
	struct nodo *siguiente;
};

typedef struct nodo Nodo;

void insertar(Nodo **lista, int dato){
	Nodo *nuevo=malloc(sizeof(Nodo*));
	nuevo->dato=dato;
	nuevo->siguiente=nuevo;
	
	if(*lista!=NULL){
		nuevo->siguiente=(*lista)->siguiente;
		(*lista)->siguiente=nuevo;
	}
	*lista=nuevo;
}

void reportar(Nodo *lista){
	int i=0;
	for(i=0;i<10;i++){
		printf("\n%d", lista->dato);
		lista=lista->siguiente;
	}
}


int main(){
	Nodo *lista=NULL;
	insertar(&lista,3);
	
	insertar(&lista,4);
	insertar(&lista,5);
	insertar(&lista,2);
	insertar(&lista,1);
	reportar(lista);
}
