#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 30


//Caden y enlace a siguiente nodo
struct nodo{ 
	char *cadena;
	struct nodo *siguiente;
} typedef Nodo;

//Nodo que guarda el frente y el fin de la cola
struct cola{
	Nodo *frente;
	Nodo *fin;
} typedef Cola;


void encolar(Cola *cola, char llegada[]){
	
	Nodo *nuevo = malloc( sizeof(Nodo*));				//Reserva para nuevo
	nuevo->cadena=malloc(strlen(llegada)*sizeof(char*));//Reserva para cadena de llegada
	strcpy(nuevo->cadena,llegada);						//Copia de llegada
	nuevo->siguiente = NULL;                            
	
	if (cola->frente == NULL) 							//Si cola frente es nulo-> frente es igual a nuevo
		cola->frente = nuevo;
	else												//Sino se almacena detras del ultimo
		cola->fin->siguiente = nuevo;
		
	cola->fin = nuevo;          						//Se actualiza el fin de la cola que seria el elemento que ingresa
}

char *desencolar(Cola *cola){
	Nodo *aux = cola->frente;				 //Copia de primer elemento de la cola
	char *salida=malloc(DIM * sizeof(char*));//Espacio para dato que retorna
	
	strcpy(salida,aux->cadena);				//Copia de salida
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
		printf("\n\t%s",auxiliar->cadena);
		auxiliar = auxiliar->siguiente;
	}
}


Cola* crearCola(){
	Cola* cola=malloc(sizeof(Cola*)); 
	cola->fin=NULL;
	cola->frente=NULL;
	return cola;
}

void lecturaCadena(char cadena[]){
	do{
		printf("\nDigite su cadena: ");
		fflush(stdin);	
		scanf(" %30[^\n]s", cadena);
	}while(strlen(cadena)==0);
}


int main(){
	Cola *colaNueva=crearCola();
	short int op;
	char ingreso[DIM];
	char *auxDesencolar=malloc(DIM * sizeof(char*));
	
	do{
		system("CLS");
		printf("\n\tMENU\n1. Encolar\n2. Desencolar\n3. Mostrar\n4. Salir\nOpcion: ");
		scanf("%d",&op);
		
	 	switch (op){
	 		case 1:
	 			lecturaCadena(ingreso);
	 			encolar(colaNueva,ingreso);		
	 			break;
	 			
			case 2:
				if(colaVacia(colaNueva))
			        printf("\nCola vacia!\n");
				else{
				
					auxDesencolar=malloc(DIM * sizeof(char*));
					strcpy(auxDesencolar,desencolar(colaNueva));
				    printf("\tElemento extraido de la cola: %s\n",auxDesencolar);
					free(auxDesencolar);
					}
					
				break;
				
			case 3:
		        if(colaVacia(colaNueva))
			        printf("\tCola vacia\n");
				else
					printf("\n\tElementos en cola");
				    mostrar(colaNueva);
				break;
			
			case 4:
				printf("\n\tFin del programa");
				break;
				
		    default:
			    printf("\nDigite una opcion valida! ");
		 }
		 printf("\nPresione una tecla para continuar");
		 getch();
		
		}while (op != 4);
}


