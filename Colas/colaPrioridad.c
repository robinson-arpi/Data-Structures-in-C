#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct nodo{ 
	int dato;
	int prioridad;
	struct nodo *siguiente;
};
typedef struct nodo NodoCola;

//NodoCola que guarda el frente y el fin de la cola
struct cola{
	NodoCola *frente;
	NodoCola *fin;
};
typedef struct cola Cola;

void encolar(Cola *cola, int llegada, int prioridad){
	NodoCola *nuevo = malloc( sizeof(NodoCola));				//Reserva para nuevo
	nuevo->dato = llegada;						//Copia de llegadada
	nuevo->siguiente = NULL;                            
	nuevo->prioridad = prioridad;
	
	if (cola->frente == NULL) 							//Si cola frente es nulo-> frente es igual a nuevo
		cola->frente = nuevo;
	else												//Sino se almacena detras del ultimo
		cola->fin->siguiente = nuevo;
		
	cola->fin = nuevo;          						//Se actualiza el fin de la cola que seria el elemento que ingresa
}

void ordenarPrioridad( Cola *cola )
{
    NodoCola *aux1 = NULL;
    NodoCola *aux2 = NULL;

    int p_aux;
    int d_aux;
     
    aux1 = cola->frente;
     
	while( aux1->siguiente != NULL){
		aux2 = aux1->siguiente;
		
        while( aux2 != NULL){
        	if( aux1->prioridad > aux2->prioridad ){
				p_aux = aux1->prioridad;
				d_aux = aux1->dato;
				
				aux1->prioridad = aux2->prioridad;
				aux1->dato = aux2->dato;
				
				aux2->prioridad = p_aux;
				aux2->dato = d_aux;
            }
                   
            aux2 = aux2->siguiente;
        }
        
        aux1 = aux1->siguiente;
     }
}

void insertar(Cola *cola, int c, int pr )
{
     /* Encolando caracteres */
     encolar( cola, c, pr );
     
     /* Ordenando por prioridad */
     ordenarPrioridad(cola); 
}

int desencolar(Cola *cola){
	NodoCola *aux = cola->frente;				 //Copia de primer elemento de la cola
	int salida = aux->dato;				//Copia de salida
	cola->frente = aux->siguiente;			//Se actualiza el frente de la cola
	free(aux);								//Libera memoria de dato desencolado
	return salida;							//Devuelve dato desencolado
}

int colaVacia(Cola *cola){
	return (cola->frente==NULL); //1 si esta vacia
}	
	
void mostrar(Cola *cola){
	NodoCola *auxiliar = cola->frente;
	while(auxiliar != NULL){
		printf("\n%d    ->prioridad",auxiliar->dato, auxiliar->prioridad);
		auxiliar = auxiliar->siguiente;
	}
}


Cola* crearCola(){
	Cola* cola=malloc(sizeof(Cola));
	cola->fin=NULL;
	cola->frente=NULL;
	return cola;
}

int main(){
	
	int prioridades;
	Cola *(*colas) = NULL;
	int i ;
	
	printf("Digite la cantidad de colas: ");
	
	scanf("%d",&prioridades);
	
	colas=malloc(sizeof(Cola*) *prioridades);
	printf("entra de reserva\n\n");
	for(i = 0 ;i<prioridades;i++){
		(colas)[i]= crearCola();
	}
	printf("Salio de reserva\n\n");
	int lectura;
	int opcion;
	int prioridadIngreso;
	int numeroCola;
	
	do{
		system("CLS");
		printf("\n\tMENU\n1. Encolar\n2. Desencolar\n3. Mostrar\n4. Salir\nOpcion: ");
		scanf("%d",&opcion);
		
	 	switch (opcion){
	 		case 1:
	 			printf("\nDigite un numero: ");
	 			scanf("%d", &lectura);
	 			printf("\nDigite la prioridad: ");
	 			scanf("%d", &prioridadIngreso);
	 			printf("\nDigite el numero de cola: ");
	 			scanf("%d", &numeroCola);
	 			insertar(colas[numeroCola],lectura, prioridadIngreso);
	 			break;
	 			
			case 2:
				printf("\nDigite el numero de cola: ");
	 			scanf("%d", &numeroCola);
	 			
				if(colaVacia(colas[numeroCola]))
			        printf("\nCola vacia!\n");
				else{
					printf("\tElemento extraido de la cola: %s\n", desencolar(colas[numeroCola]));	
				}    
				break;
				
			case 3:
				for(int i=0;i<prioridades;i++){
					if(colaVacia(colas[i]))
			        printf("\nCola %d vacia\n",i+1);
				else
					printf("\nElementos en cola %d: ",i+1);
				    mostrar(colas[i]);
				}
				
		        
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
