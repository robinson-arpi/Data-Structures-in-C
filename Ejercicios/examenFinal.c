#include <stdio.h>
#include <stdlib.h>

//Pila-------------------------------
struct nodoPila {
	int Valor;
	struct nodoPila *cima;
};
typedef struct nodoPila NodoPila;

void push(NodoPila **pila, int Valor) {
    NodoPila *nuevo = malloc(sizeof(NodoPila));
    nuevo->Valor = Valor;
	nuevo->cima = *pila;
	*pila=nuevo;
}

int pop(NodoPila **pila){
	NodoPila *auxiliar;
	int salida;
	auxiliar = *pila;
	*pila = auxiliar->cima;
	salida = auxiliar->Valor;
	free(auxiliar);
	return salida;
}

void mostrar(NodoPila *pila){	
	printf("\nContenido de pila: ");
	while(pila != NULL){
		printf("%d ", pila->Valor);
		pila = pila->cima;
	}
	printf("\n");
}

void crearPila(NodoPila** miPila, int Datos[], int dim){
	int i=0;
	for(i = 0;i<dim ;i++){
		push(miPila, Datos[i]);
	}
	mostrar(*miPila);
}

//Cola-------------------------------

struct nodoCola{ 
	int Valor;
	struct nodoCola *siguiente;
};
typedef struct nodoCola NodoCola;

//NodoCola que guarda el frente y el fin de la cola
struct cola{
	NodoCola *frente;
	NodoCola *fin;
};
typedef struct cola Cola;


void encolar(Cola *cola, int llegada){
	NodoCola *nuevo = malloc( sizeof(NodoCola));				//Reserva para nuevo
	nuevo->Valor = llegada;						//Copia de llegadada
	nuevo->siguiente = NULL;                            
	
	if (cola->frente == NULL) 							//Si cola frente es nulo-> frente es igual a nuevo
		cola->frente = nuevo;
	else												//Sino se almacena detras del ultimo
		cola->fin->siguiente = nuevo;
		
	cola->fin = nuevo;          						//Se actualiza el fin de la cola que seria el elemento que ingresa
}

int desencolar(Cola *cola){
	NodoCola *aux = cola->frente;				 //Copia de primer elemento de la cola
	int salida = aux->Valor;				//Copia de salida
	cola->frente = aux->siguiente;			//Se actualiza el frente de la cola
	free(aux);								//Libera memoria de Valor desencolado
	return salida;							//Devuelve Valor desencolado
}

int colaVacia(Cola *cola){
	return (cola->frente==NULL); //1 si esta vacia
}	
	
void mostrarCola(Cola *cola){
	NodoCola *auxiliar = cola->frente;
	printf("\nContenido de cola: ");
	while(auxiliar != NULL){
		printf("%d ",auxiliar->Valor);
		auxiliar = auxiliar->siguiente;
	}
	printf("\n");
}


Cola* memoriaCola(){
	Cola* cola=malloc(sizeof(Cola)); 
	cola->fin=NULL;
	cola->frente=NULL;
	return cola;
}

void CrearCola(Cola* miCola,int Datos[], int dim){
	int i=0;
	printf("datos %d		dato[0] %d		dim %d",sizeof(Datos),sizeof(Datos[0]), sizeof(Datos)/sizeof(Datos[0]));
	for(i=0;i<dim;i++){
		encolar(miCola, Datos[i]);	
	}
	mostrarCola(miCola);
	
}


//Arbol------------------------->
struct nodo{
	int Valor;
	int Ocurrencias;
	struct nodo *Izq;
	struct nodo *Der;	
};

typedef struct nodo Nodo;

void addNodoArbol(Nodo **arbol, int Valor){
    Nodo *nuevo = NULL;
    
    if(!(*arbol)) //Creacion de nodo nuevo
    {
        nuevo = malloc(sizeof(Nodo));
        nuevo->Der =NULL;
		nuevo->Izq = NULL;
        nuevo->Valor = Valor;
        nuevo->Ocurrencias = 1;
        *arbol = nuevo;
        return;
    }
    
	if(Valor < (*arbol)->Valor)		
   		addNodoArbol(&(*arbol)->Izq, Valor);    	   
	else if(Valor > (*arbol)->Valor)
   		addNodoArbol(&(*arbol)->Der, Valor);    	
	else
		++(*arbol)->Ocurrencias;
}


void recorrerArbol(Nodo *arbol) {//Impresion in order

	if (arbol != NULL) {
		recorrerArbol(arbol->Izq);
    	printf("\n%d (%d)",arbol->Valor, arbol->Ocurrencias);
    	recorrerArbol(arbol->Der);	
    }
}

Nodo* unirArbol(Nodo *izquierdo, Nodo *derecho) {
    
	if(izquierdo == NULL) return derecho;
    if(derecho == NULL) return izquierdo;
    
	Nodo *centro = unirArbol(izquierdo->Der,derecho->Izq);
    izquierdo->Der = centro;
    derecho->Izq = izquierdo;
    return derecho;
}


void deleteNodoArbol(Nodo **arbol, int datoEliminar){	
    if(*arbol == NULL) return;
	
    if(datoEliminar < (*arbol)->Valor)
		deleteNodoArbol(&(*arbol)->Izq, datoEliminar);
	else if(datoEliminar> (*arbol)->Valor)
		deleteNodoArbol(&(*arbol)->Der, datoEliminar);
    else
    {
    	if((*arbol)->Ocurrencias>1)
    		(*arbol)->Ocurrencias--;
		else{
	        Nodo *p = *arbol;
	        *arbol = unirArbol((*arbol)->Izq, (*arbol)->Der);
	        free(p);
	    }
	}
	
}


int main(){
	NodoPila *miPila = NULL;
	Cola *miCola = memoriaCola();
	Nodo *arbol = NULL;
	
	int dimensionAux; 
	int Datos[]={1,2,5,6,3,4,7,7,8,9,20,0, 12,15, 63, 34, 12, 34, 56, 7};
	dimensionAux = sizeof(Datos) / sizeof(Datos[0]);
	
	printf("datos %d		dato[0] %d		dim %d",sizeof(Datos),sizeof(Datos[0]), dimensionAux);
	
	crearPila(&miPila, Datos, dimensionAux);
	
	CrearCola(miCola,  Datos,dimensionAux);
	
	
	char datosArbol[]={'P','D','D','P','D','P','P','P','D','P','P','P','P','D','P','D','D','P','D','P','P','P','D','P'};
	dimensionAux = sizeof(datosArbol) / sizeof(datosArbol[0]);
	int i;
	int aux;	
	for(i=0 ;i<dimensionAux;i++){
		if(datosArbol[i] == 'P')
			if(miPila!=NULL)
				addNodoArbol(&arbol, pop(&miPila));	
		else
			if(miCola->frente!=NULL)
				addNodoArbol(&arbol, desencolar(miCola));
	}
	printf("\nContenido de arbol: ");
	recorrerArbol(arbol);
	printf("\n");
	
	int paraEliminar[]={1,2,9,20,0, 12,15, 63, 34,34, 56, 7};
	dimensionAux = sizeof(paraEliminar) / sizeof(paraEliminar[0]);
	for(i=0;i<dimensionAux;i++){
		deleteNodoArbol(&arbol,paraEliminar[i]);
	}
	printf("\nContenido tras eliminar: ");
	recorrerArbol(arbol);
	
	
	
}
