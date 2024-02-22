#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct nodo{
	char* cadena;
	struct nodo *enlace;
}; 
typedef struct nodo Nodo;


void agregarOrdenado(Nodo **lista, char llegada[]){
	Nodo *nuevo = malloc(sizeof(Nodo*));
	nuevo->cadena=malloc(strlen(llegada) * sizeof(char*));
	strcpy(nuevo->cadena,llegada);
	nuevo->enlace=NULL;
	
	Nodo *auxiliar = *lista;
	Nodo *anterior = NULL;
	
	while(auxiliar != NULL && strcmp(auxiliar->cadena,llegada)==-1)
	{													 //Mientras no sea nulo y dato sea menor que ingreso     
        anterior=auxiliar;						    	 //Nodo con dato anterior a ingreso
	    auxiliar=auxiliar->enlace;                    //Nodo con dato siguiente a ingreso
    }
    
    if(*lista == auxiliar)
    	*lista = nuevo;
    else
    	anterior->enlace=nuevo;
    	
	nuevo->enlace=auxiliar;
}

void insertarFrente(Nodo **lista, char llegada[]){
	Nodo *nuevo=malloc(sizeof(Nodo*));
	nuevo->cadena=malloc(strlen(llegada) * sizeof(char*));
	strcpy(nuevo->cadena,llegada);
	nuevo->enlace=NULL;
	
	nuevo->enlace=*lista;
	*lista=nuevo;
}

void insertarFin(Nodo **lista, char llegada[]){
	Nodo *nuevo=malloc(sizeof(Nodo*));
	nuevo->cadena=malloc(strlen(llegada) * sizeof(char*));
	strcpy(nuevo->cadena,llegada);
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
	return  = rand () % (ls-li+1) + li;   // Este está entre M y N


}


void reportar(Nodo *lista){
	while(lista!=NULL){
		printf("\n%s",lista->cadena);
		lista = lista->enlace;
	}
}

int buscar(Nodo *lista, char buscar[]){
	while(lista != NULL){
		if(strcmp(lista->cadena, buscar))
			return 1;
		lista = lista->enlace;
	}
	return 0;
}

void modificar(Nodo **lista, char modificar[], char nuevo[]){
	Nodo *aux= *lista;
	
	while((aux != NULL) && (strcmp(aux->cadena,modificar)!=0)){
		aux = aux->enlace;
	}
	
	free (aux->cadena);
	aux->cadena=malloc(strlen(nuevo) * sizeof(char*));
	strcpy(aux->cadena, nuevo);
}


void eliminar(Nodo **lista, char eliminar[]){
	Nodo *aux=*lista;
	Nodo *anterior=NULL;
	
	while(lista!=NULL && strcmp(aux->cadena, eliminar)!=0){
		anterior=aux;
		aux=aux->enlace;
	}
	
	if(aux==*lista)
		*lista=(*lista)->enlace;
	else
		anterior->enlace=aux->enlace;
	
	free(aux->cadena);
	free(aux);
	
}


void lecturaCadena(char cadena[]){
	do{
		printf("\nDigite su cadena: ");
		fflush(stdin);	
		scanf(" %30[^\n]s", cadena);
	}while(strlen(cadena)==0);
}



int main(){
	Nodo *lista=NULL;
	int op;
	
	insertarFrente(&lista,"1");
	insertarFrente(&lista,"2");
	insertarFrente(&lista,"3");
	insertarFrente(&lista,"4");
	
	
	insertarFin(&lista,"3d");
	insertarFin(&lista,"3334");
	insertarFin(&lista,"3rew4");
	insertarFin(&lista,"3w4");
	insertarFin(&lista,"34zzzz");
	reportar(lista);
	eliminar(&lista,"3rew4");
	eliminar(&lista,"34zzzz");
	eliminar(&lista,"4");
	printf("\n\n");
	reportar(lista);
	/*
	do{
		system("CLS");
		printf("\n\tMENU\n1.Ingresar\n2.Buscar\n3.Modificar\n4.Eliminar\n5.Reportar\n6.Salir\n7.Digite su opcion: ");
		
		
		switch(op){
			case 1:
				
				break;
		}
		
		
	}while(op!=)
	
	
	*/
}


