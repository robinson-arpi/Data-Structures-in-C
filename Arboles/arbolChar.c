#include <stdio.h>
#include <stdlib.h>

struct nodo{
	char dato;
	int contador;
	struct nodo *izq;
	struct nodo *der;
};

typedef struct nodo Nodo;

void insertar(Nodo **arbol, char dato, int clave){
    Nodo *nuevo = NULL;
    
    if(!(*arbol)) //Creacion de nodo nuevo
    {
        nuevo = malloc(sizeof(Nodo));
        nuevo->der =NULL;
		nuevo->izq = NULL;
        nuevo->dato = dato;
        nuevo->contador = 1;
        *arbol = nuevo;
        return;
    }
    
	if(dato < (*arbol)->dato)		
   		if(clave==0)
   			insertar(&(*arbol)->izq, dato, clave);
		else   
		    insertar(&(*arbol)->der, dato, clave);
		   
	else if(dato > (*arbol)->dato)
   		if(clave==0)
   			insertar(&(*arbol)->der, dato, clave);
		else
		    insertar(&(*arbol)->izq, dato, clave);    	
	else
		++(*arbol)->contador;
}

int existe(Nodo *arbol, char buscar, int clave) {
        while (arbol != NULL) { //Mientras no sea nulo busca
            if (buscar == arbol->dato)
                return 1;
            else if (buscar > arbol->dato)
                if (clave==0)
					arbol = arbol->der;
				else
					arbol = arbol->izq;
            else
                if (clave==0)
					arbol = arbol->izq;
				else
					arbol = arbol->der;                
        }
        return 0;//No se ha encontrado
}



Nodo* buscar(Nodo** arbol, int datoBuscar, int clave){
	if(!(*arbol))
		return NULL;
	else if (datoBuscar < (*arbol)->dato)
		if(clave ==0)
			buscar(&(*arbol)->izq, datoBuscar, clave);	
		else
			buscar(&(*arbol)->der, datoBuscar, clave);
		
	else if (datoBuscar > (*arbol)->dato)	
		if(clave==0)
			buscar(&(*arbol)->der, datoBuscar, clave);
		else
			buscar(&(*arbol)->izq, datoBuscar, clave);	
	else
		return *arbol;	
}


void inOrden(Nodo *arbol) {//Impresion in order
    if (arbol != NULL) {
		inOrden(arbol->der);
    	printf("\n%c -> Apariciones: %d ",arbol->dato, arbol->contador);
    	inOrden(arbol->izq);	
    }
}

void preOrden(Nodo *arbol) {//Impresion in order
    if (arbol != NULL) {
    	printf("\n%c -> Apariciones: %d",arbol->dato, arbol->contador);
    	preOrden(arbol->izq);
    	preOrden(arbol->der);	
		
    }
}

void posOrden(Nodo *arbol) {//Impresion in order
    if (arbol != NULL) {
        posOrden(arbol->izq);
        posOrden(arbol->der);
		printf("\n%c -> Apariciones: %d",arbol->dato, arbol->contador);
    }
}    

Nodo* unirArbol(Nodo *izquierdo, Nodo *derecho, int clave) {
    
	if(izquierdo == NULL) 
		if(clave == 0)
			return derecho;
		else
			return izquierdo;	
    if(derecho == NULL)
    	if(clave == 0)
			return izquierdo;
		else
			return derecho;
    
	Nodo *centro = unirArbol(izquierdo->der,derecho->izq,clave);
    izquierdo->der = centro;
    derecho->izq = izquierdo;
    return derecho;
}


void elimina(Nodo **arbol, char datoEliminar, int clave){
    if(*arbol == NULL) return;

    if(datoEliminar < (*arbol)->dato)
    	if(clave ==0)
			elimina(&(*arbol)->izq, datoEliminar,clave);
		else
			elimina(&(*arbol)->der, datoEliminar, clave);
    else if(datoEliminar> (*arbol)->dato)
        if(clave ==0)
			elimina(&(*arbol)->der, datoEliminar,clave);
		else
			elimina(&(*arbol)->izq, datoEliminar, clave);
    else
    {
        Nodo *p = *arbol;
        *arbol = unirArbol((*arbol)->izq, (*arbol)->der, clave);
        free(p);
	}
	
}

void verArbol(Nodo *arbol, int n)
{
     if(arbol==NULL)
          return;
     verArbol(arbol->der, n+1);
	
	int i=0;
     for(i=0; i<n; i++)
         printf("   ");

     printf("%d\n",arbol->dato);

     verArbol(arbol->izq, n+1);
}


void liberarMemoria (Nodo **arbol){
	
	if((*arbol) != NULL){
	    liberarMemoria(&(*arbol) -> izq);
		liberarMemoria(&(*arbol) -> der);
	}
	free(*arbol);
}
/*
void free_tree(Node* root) {
    // Deallocates memory corresponding
    // to every node in the tree.
    Node* temp = root;
    if (!temp)
        return;
    free_tree(temp->left);
    free_tree(temp->right);
    if (!temp->left && !temp->right) {
        free(temp);
        return;
    }
}

*/

int comparacionArboles(Nodo *arbol1, Nodo *arbol2)
{
   if (arbol1 != NULL && arbol2 != NULL && arbol1->dato == arbol2->dato)
      return comparacionArboles(arbol1->izq, arbol2->izq) && comparacionArboles(arbol1->der, arbol2->der);
   else 
      return arbol1 == arbol2;
}



int alturaArbol(Nodo* arbol) {
    
	if (!arbol)
        return 0;
    else {
        int alturaIzquierda = alturaArbol(arbol->izq);
        int alturaDerecha = alturaArbol(arbol->der);
        if (alturaIzquierda >= alturaDerecha)
            return alturaIzquierda + 1;
        else
            return alturaDerecha + 1;
    }
}
 
void imprimirNivel(Nodo* arbol, int numeroNivel) {
    if (!arbol)
        return;
    if (numeroNivel == 0) {
        printf("%d -> ", arbol->dato);
    }
    else {
        imprimirNivel(arbol->izq, numeroNivel - 1);
        imprimirNivel(arbol->der, numeroNivel - 1);
    }
 
}

void imprimirNivelArbol(Nodo* arbol) {
    if (!arbol)
        return;
    int altura = alturaArbol(arbol);
    int i;
    for (i=0; i<altura; i++) {
        printf("Nivel %d: ", i);
        imprimirNivel(arbol, i);
        printf("\n");
    }
    printf("\n\n-----Complete Level Order Traversal:-----\n");
    for ( i=0; i<altura; i++) {
        imprimirNivel(arbol, i);
    }
    printf("\n");
}


int main(){
	Nodo *arbol=NULL;
	int opcionI;//Izquierda o derecha
	int lectura;//Lecturas de teclado
	int cantidad;//Cantidad d enumero a ingresar
	int i;//Iterdor
	int opcion;
	Nodo *auxiliar= NULL;
	
	do{
		system("cls");
		printf("\n1. Izquierda o derecha\n2. Ingresar valores\n3. Buscar\n4. Eliminar\n5. Salir\nDigite su opcion: ");
		scanf("%d",&opcion);
		
		switch(opcion){
			case 1:
				{
					printf("Ingreso de datos menores. \n1. Izquierda\n2. Derecha.\nDigite su opcion: ");
					scanf("%d",&opcionI);
					if(opcionI==1)
						opcionI=0;
					else
						opcionI=1;
				}
				break;
			case 2:
				{
					printf("Cantidad de datos a insertar: ");
					scanf("%d",&cantidad);
					
					for(i=0;i<cantidad;i++){
						printf("Ingreso %i: ", i+1);
						scanf("%d",&lectura);
						insertar(&arbol,lectura, opcionI);
					}
					
					printf("\nImpreison ver rbol\n");
					verArbol(arbol,0);
					printf("\n----------------------------");
					
				}
				break;
				
			case 3:
				{
					printf("Digite el valor a buscar: ");
					scanf("%d", &lectura);
					if(existe(arbol, lectura, opcionI))
						printf("\nEl valor existe en el arbol!");
					else
						printf("\nEl valor no existe en el arbol!");
				}	
				break;
				
			case 4:
				{
					if(arbol!=NULL){
						printf("\n\n--------------------------------------------------------------->\nContenido del arbol (in Order): ");
						imprimirNivelArbol(arbol);
						printf("\nDigite el valor que desea eliminar: ");
						scanf("%d", &lectura);
						elimina(&arbol, lectura, opcionI);
						printf("\nEliminado: Contenido del arbol actualizado (in Order) ");
						inOrden(arbol);
					}else{
						printf("\nArbol vacio! :c");
					}	
				}
			break;	
			
			case 5:
				{
					liberarMemoria(&arbol);
					printf("\n\tPROGRAMA FINLIZADO");
				}
				break;
			
			default:
				printf("\nDigite una opcion valida!");
			break;	
		
		}
		
		printf("\nDigite una tecla para continuar");
		getch();
		
	}while(opcion!=5);
		
	
}

