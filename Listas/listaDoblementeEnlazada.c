#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodo{
	char *cadena;
	struct nodo *siguiente;
	struct nodo *anterior;
};
typedef struct nodo Nodo;

void insertar(Nodo **lista, char llegada[]){
	Nodo *nuevo=malloc(sizeof(Nodo*));
	nuevo->cadena=malloc(strlen(llegada) * sizeof(char*));
	strcpy(nuevo->cadena, llegada);
	nuevo->anterior=NULL;
	nuevo->siguiente=NULL;
	
	Nodo *auxiliar=*lista;
	if( auxiliar==NULL)
		*lista=nuevo;
	else{
		while(auxiliar->siguiente!=NULL){
			auxiliar=auxiliar->siguiente;
		}
		auxiliar->siguiente=nuevo;
		nuevo->anterior=auxiliar;
	}		
}

void reportar(Nodo *lista){
	Nodo *aux;
	while(lista != NULL){
		printf("\n%s", lista->cadena);
		aux=lista;
		lista=lista->siguiente;
	}
	printf("\n");
	lista=aux;
	while(lista != NULL){
		printf("\n%s", lista->cadena);
		lista=lista->anterior;
	}
}



void eliminar(Nodo **lista, char eliminar[]){
	Nodo *aux=*lista;
	Nodo *anterior=NULL;
	
	while(lista!=NULL && strcmp(aux->cadena, eliminar)!=0){
		anterior=aux;
		aux=aux->siguiente;
	}
	
	if(aux==*lista)
		*lista=(*lista)->siguiente;
	else{
		anterior->siguiente=aux->siguiente;
		aux->siguiente->anterior=anterior;
	}
	free(aux->cadena);
	free(aux);
	
}



int main(){
	Nodo *lista=NULL;
	insertar(&lista, "a");
	insertar(&lista, "b");
	insertar(&lista, "c");
	
	insertar(&lista, "d");
	eliminar(&lista, "c");
	reportar(lista);
}
