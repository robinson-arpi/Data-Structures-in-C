#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct nodo{
	int dato;
	struct nodo *enlace;
}; 
typedef struct nodo Nodo;


void insertarOrdenado(Nodo **lista, int llegada){
	Nodo *nuevo = malloc(sizeof(Nodo));
	nuevo->dato =llegada;
	nuevo->enlace = NULL;
	
	Nodo *auxiliar = *lista;
	Nodo *anterior = NULL;
	
	while(auxiliar != NULL && auxiliar->dato < llegada)
	{							 						 //Mientras no sea nulo y dato sea menor que ingreso     
        anterior=auxiliar;						    	 //Nodo con dato anterior a ingreso
	    auxiliar=auxiliar->enlace;                    //Nodo con dato siguiente a ingreso
    }
    
    if(*lista == auxiliar)
    	*lista = nuevo;
    else
    	anterior->enlace=nuevo;
    	
	nuevo->enlace=auxiliar;
}

void insertarFrente(Nodo **lista, int llegada){
	Nodo *nuevo=malloc(sizeof(Nodo));
	nuevo->dato = llegada;
	nuevo->enlace = NULL;
	nuevo->enlace=*lista;
	*lista=nuevo;
}

void insertarFin(Nodo **lista, int llegada){
	Nodo *nuevo=malloc(sizeof(Nodo));
	nuevo->dato = llegada;
	nuevo->enlace=NULL;
	
	Nodo *aux=*lista;
		
	if(aux==NULL){
		*lista=nuevo;
	}else{
		while(aux->enlace!=NULL){
			aux=aux->enlace;
		}
		aux->enlace=nuevo;
	}	
}

int aleatorioa(int li, int ls){
	return  rand () % (ls-li+1) + li;   // Este está entre M y N
}


void reportar(Nodo *lista){
	while(lista!=NULL){
		printf("\n%d",lista->dato);
		lista = lista->enlace;
	}
}

int buscar(Nodo *lista, int buscar){
	while(lista != NULL){
		if(lista->dato == buscar) return 1;
		
		lista = lista->enlace;
	}
	return 0;
}

void modificar(Nodo **lista, int modificar, int nuevo){
	Nodo *aux= *lista;
	while((aux != NULL) && aux->dato!=modificar){
		aux = aux->enlace;
	}
	aux->dato=nuevo;
}


void eliminar(Nodo **lista, int eliminar){
	Nodo *aux=*lista;
	Nodo *anterior=NULL;
	
	while(lista!=NULL && aux->dato!=eliminar){
		anterior=aux;
		aux=aux->enlace;
	}
	
	if(aux==*lista)
		*lista=(*lista)->enlace;
	else
		anterior->enlace=aux->enlace;
	
	free(aux);
}

int main(){
	Nodo *lista=NULL;
	int op;
	
	insertarOrdenado(&lista,1);
	insertarOrdenado(&lista,7);
	insertarOrdenado(&lista,2);
	insertarOrdenado(&lista,5);
	
	
	insertarOrdenado(&lista,90);
	insertarOrdenado(&lista,96);
	insertarOrdenado(&lista,45);
	insertarOrdenado(&lista,67);
	insertarOrdenado(&lista,76);
	reportar(lista);
	eliminar(&lista,45);
	
	printf("\n\n");
	reportar(lista);
	
	
}
