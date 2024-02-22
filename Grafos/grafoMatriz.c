#include <stdio.h>
#include <stdlib.h>
#define DIM 20


void mostrarMatriz(int matriz[DIM][DIM], int v){
	int i,j;
	
	for(i=0 ;i<v;i++){
		for(j=0;j<v;j++)
			printf("%d ", matriz[i][j]);
			
		printf("\n");
	}
			
}

void grafo(int matriz[DIM][DIM], int v, int d, int p){
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
			matriz[i][j]=peso;
		}else
			matriz[i][j]=1;	
		
		if(d==0)//Si no es dirigido
			matriz[j][i]=matriz[i][j];
	
		printf("\nIngresar otro enlace? \n1. Si\n2. No\nDigite su opcion: ");
		scanf("%d", &op);
	}while(op==1);
	
}

void construccionMatriz(int matriz[DIM][DIM], int v){
	int i, j;
	// Reserva de Memoria 
	
	for (i=0;i<v;i++)
		for(j=0;j<v;j++){
			if(i==0 && j==0)
				matriz[i][j] = 0;
			else if(i==0 )
				matriz[i][j] = j;
			else if(j==0)
				matriz[i][j] = i;
			else
				matriz[i][j] = 0;
		}



	mostrarMatriz(matriz,v);
}

void informacionGrafo(int matriz[DIM][DIM], int v){
	int i,j;
	
	
	for(i=1;i<v;i++){
		printf("\nVertice: %d\nEnlaces con: ", i);
		
		for(j=1;j<v;j++){
			if(matriz[i][j]==1)
				printf("%d, ",j);
			else if(matriz[i][j]>1)
				printf("%d (peso: %d),",j,matriz[i][j]);
		}
	}
}

int main(){
	int op;
	int matriz[DIM][DIM];
	int v;
	
	do{
		system("cls");
		printf("Cantidad de vertices: ");
		scanf("%d",&v);
		++v;
		construccionMatriz(matriz,v);
		
		printf("\n\tGrafo tipo:");
		printf("\n0. Grafo no dirigido y no ponderado\n1. Grafo no dirigido y ponderado\n2. Grafo dirigido y no ponderado\n3. Grafo dirigido y ponderado");
		printf("\nDigite su opcion: ");
		scanf("%d",&op);
		
		switch(op){
			
			case 0:
				{
					grafo(matriz,v, 0,0);
					mostrarMatriz(matriz,v);	
					informacionGrafo(matriz,v);	
				}
				
				break;
			case 1:
				{
					grafo(matriz,v, 0,1);
					mostrarMatriz(matriz,v);	
					informacionGrafo(matriz,v);	
				}
				
				break;				
			case 2:
				{
					grafo(matriz,v, 1,0);
					mostrarMatriz(matriz,v);
					informacionGrafo(matriz,v);	
				}
				break;
			case 3:
				{
					grafo(matriz,v, 1,1);
					mostrarMatriz(matriz,v);
					informacionGrafo(matriz,v);	
				}
				break;	
		}
		
		
		printf("\nIngresar otro grafo? \n1. Si\n2. No\nDigite su opcion: ");
		scanf("%d", &op);
		printf("\n\nDigite un tecla para continuar...");
		getch();
	}while(op==1);
	
}
