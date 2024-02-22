#include <stdio.h>

typedef struct Nodo {
   int dato;
   struct Nodo *siguiente,*anterior;
} tipocelda;

typedef Nodo *nodoLista;



void insertar(nodoLista *lista, int ingreso){
    //Creacion de nodo nuevo
	nodoLista nuevo = malloc(sizeof(nodoLista));
    nuevo->dato=ingreso;
	nuevo->siguiente=NULL;
	nuevo->anterior=NULL;
	
	nodoLista auxiliar1=*lista;//Copia de lista para no alterar la original
	nodoLista anterior=NULL;
	nodoLista siguiente=NULL;       

	while(auxiliar1 != NULL && auxiliar1->dato< ingreso)
	{													 //Mientras no sea nulo y dato sea menor que ingreso     
        anterior=auxiliar1;						    	 //Nodo con dato anterior
	    auxiliar1=auxiliar1->siguiente;                  //Nodo con dato siguiente
    }
	 		                        
    //Se coloca al inicio
    if(*lista == auxiliar1)			//Lista nula
    	*lista=nuevo;
	else							//Se coloca despues del inicio-> Ej si se tiene 6 y 9: 6 se guarda en aux2 y 9 en aux1 
		anterior->siguiente=nuevo; //Insercion de nuevo nodo en nodo antecedente por valor
	
	nuevo->siguiente=auxiliar1;	   //Se asigna siguiente dato a la lista
}
