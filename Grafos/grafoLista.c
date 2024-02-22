#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int verticeEnlace;
	int peso;
	struct nodo *enlace;
	
};
typedef struct nodo Nodo;

struct nodoV{
	int vertice;
	struct nodoV *enlace;
	Nodo *listaEnlaces;
};
typedef struct nodoV NodoV;

void insertarEnlace(Nodo **lista, int llegada, int peso){
	Nodo *nuevo=malloc(sizeof(Nodo));
	nuevo->verticeEnlace=llegada;
	nuevo->peso=peso;
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

void insertarVertice(NodoV **lista, int llegada){
	NodoV *nuevo=malloc(sizeof(NodoV));
	
	nuevo->vertice = llegada;
	nuevo->enlace = NULL;
	nuevo->listaEnlaces =NULL;
	
	
	NodoV *aux=*lista;
		
	if(aux==NULL){
		*lista=nuevo;
	}else{
		while(aux->enlace!=NULL){
			aux=aux->enlace;
		}
		aux->enlace=nuevo;
	}	
}



void imprimir(NodoV **lista){
	NodoV *aux= *lista;
	Nodo *auxEnlace =NULL;
	while(aux!=NULL){
		printf("\nVertice: %d\n\tEnlaces: ", aux->vertice);
		auxEnlace = aux->listaEnlaces;
		while(auxEnlace!=NULL){
			
			printf("%d ", auxEnlace->verticeEnlace );
			if(auxEnlace->peso!=0) printf("(peso: %d), ", auxEnlace->peso);
			
			auxEnlace= auxEnlace->enlace;
		}
		aux=aux->enlace;
	}
}


void localizarVertice(NodoV **grafo,int vertice, int enlace, int peso){
	NodoV *aux = *grafo;
	while(aux!=NULL && aux->vertice!=vertice){
		aux=aux->enlace;
	}
	insertarEnlace(&(aux->listaEnlaces), enlace, peso);
}


void crearGrafo(NodoV **grafo, int d, int p){
	printf("\nEnlaces.");
	int i,j,op;
	int peso;
	
	printf("\nTipo: ");
	if(p) printf("\n Ponderado");
	else printf("\nNo ponderado");
	
	if(d) printf("\n Dirigido");
	else printf("\nNo Dirigido");
	
	do{
		printf("\nDesde: ");
		scanf("%d", &i);
		printf("Hasta: ");
		scanf("%d", &j);
		
		if(p==1){
			printf("Peso: ");
			scanf("%d", &peso);
			localizarVertice(grafo,i,j,peso );
			if(d==0) localizarVertice(grafo,j,i,peso );
		}else{
			localizarVertice(grafo,i,j,0 );
			if(d==0) localizarVertice(grafo,j,i,0 );
		}
			
	
		printf("\nIngresar otro enlace? \n1. Si\n2. No\nDigite su opcion: ");
		scanf("%d", &op);
	}while(op==1);
	
}

void construccionGrafo(NodoV **grafo, int v){
	int i;
	
	for(i = 1; i < v ; i++){
		insertarVertice(grafo, i);
	}
}


int main(){
	int op;
	NodoV *grafo = NULL;
	int v;
	
	do{
		system("cls");
		printf("Cantidad de vertices: ");
		scanf("%d",&v);
		++v;
		construccionGrafo(&grafo,v);
		
		printf("\n\tGrafo tipo:");
		printf("\n0. Grafo no dirigido y no ponderado\n1. Grafo no dirigido y ponderado\n2. Grafo dirigido y no ponderado\n3. Grafo dirigido y ponderado");
		printf("\nDigite su opcion: ");
		scanf("%d",&op);
		
		switch(op){
			
			case 0:
				{
					crearGrafo(&grafo,0,0);
					imprimir(&grafo);
					
				}
				
				break;
			case 1:
				{
					crearGrafo(&grafo, 0,1);
					imprimir(&grafo);
				}
				
				break;				
			case 2:
				{
					crearGrafo(&grafo, 1,0);
					imprimir(&grafo);
				}
				break;
			case 3:
				{
					crearGrafo(&grafo, 1,1);
					imprimir(&grafo);
				}
				break;	
		}
		
		
		printf("\nIngresar otro grafo? \n1. Si\n2. No\nDigite su opcion: ");
		scanf("%d", &op);
		printf("\n\nDigite un tecla para continuar...");
		getch();
	}while(op==1);
	
}
