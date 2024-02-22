#include <stdio.h>
#include <stdlib.h>

struct nodo{ 
	char dato;
	struct nodo *siguiente;
};
typedef struct nodo Nodo;

//Nodo que guarda el frente y el fin de la cola
struct cola{
	Nodo *frente;
	Nodo *fin;
};
typedef struct cola Cola;


void encolar(Cola *cola, int llegada){
	Nodo *nuevo = malloc( sizeof(Nodo));				//Reserva para nuevo
	nuevo->dato = llegada;						//Copia de llegadada
	nuevo->siguiente = NULL;                            
	
	if (cola->frente == NULL) 							//Si cola frente es nulo-> frente es igual a nuevo
		cola->frente = nuevo;
	else												//Sino se almacena detras del ultimo
		cola->fin->siguiente = nuevo;
		
	cola->fin = nuevo;          						//Se actualiza el fin de la cola que seria el elemento que ingresa
}

char desencolar(Cola *cola){
	Nodo *aux = cola->frente;				 //Copia de primer elemento de la cola
	char salida = aux->dato;				//Copia de salida
	cola->frente = aux->siguiente;			//Se actualiza el frente de la cola
	free(aux);								//Libera memoria de dato desencolado
	return salida;							//Devuelve dato desencolado
}

int colaVacia(Cola *cola){
	return (cola->frente==NULL); //1 si esta vacia
}	
	
void mostrar(Cola *cola){
	Nodo *auxiliar = cola->frente;
	while(auxiliar != NULL){
		printf("\n%c",auxiliar->dato);
		auxiliar = auxiliar->siguiente;
	}
}


Cola* crearCola(){
	Cola* cola=malloc(sizeof(Cola)); 
	cola->fin = NULL;
	cola->frente = NULL;
	return cola;
}

int main(){
	Cola *cola = crearCola();
	char lectura;
	int opcion;
	
	do{
		system("CLS");
		printf("\n\tMENU\n1. Encolar\n2. Desencolar\n3. Mostrar\n4. Salir\nOpcion: ");
		scanf("%d",&opcion);
		
	 	switch (opcion){
	 		case 1:
	 			printf("\nDigite un numero: ");
	 			fflush(stdin);
	 			scanf("%c", &lectura);
	 			encolar(cola,lectura);		
	 			break;
	 			
			case 2:
				if(colaVacia(cola))
			        printf("\nCola vacia!\n");
				else
				    printf("\tElemento extraido de la cola: %c\n", desencolar(cola));
				    
				break;
				
			case 3:
		        if(colaVacia(cola))
			        printf("\tCola vacia\n");
				else
					printf("\n\tElementos en cola");
				    mostrar(cola);
				break;
			
			case 4:
				printf("\n\tFin del programa");
				break;
				
		    default:
			    printf("\nDigite una opcion valida! ");
		 }
		 printf("\nPresione una tecla para continuar");
		 getch();
		
		}while (opcion != 4);
}
