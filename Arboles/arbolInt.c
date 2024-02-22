#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct nodo{
	int dato;
	struct nodo *izq;
	struct nodo *der;
};

typedef struct nodo Nodo;


Nodo* buscar(Nodo** arbol, int datoBuscar){
	if(!(*arbol))
		return NULL;
	else if (datoBuscar < (*arbol)->dato)
		return buscar(&(*arbol)->izq, datoBuscar);	
	else if (datoBuscar > (*arbol)->dato)	
		return buscar(&(*arbol)->der, datoBuscar);
	else
		return *arbol;	
}

Nodo *busquedaParaNiveles(Nodo *arbol, int dato)
{
    if (!arbol)
        return NULL;
    Nodo *curr = arbol, *padre = arbol;
    while (curr && padre->dato != dato)
    {
        padre = curr;
        curr = curr->dato <= dato ? curr->izq : curr->der;
    }
    curr = padre->dato == dato ? padre : NULL;
    return curr;
}

int cantidadDeElementos(Nodo *arbol, int n)
{
    // int n = 0;
    if (!arbol)
        return n;
    n++;
    n = cantidadDeElementos(arbol->izq, n);
    n = cantidadDeElementos(arbol->der, n);
}
/*
void InsertByLevel(nodoArbol **root, int data)
{
    nodoArbol *newest = Search(*root, data);
    if (newest)
    {
        newest->nRepet++;
        return;
    }

    nodoArbol *act = *root;
    newest = malloc(sizeof(nodoArbol));
    newest->left = newest->right = NULL;
    newest->data = data;
    newest->nRepet = 1;

    if (!*root)
    {
        *root = newest;
        return;
    }

    int num_nodes = Count_elements(*root, 0);

    nodoArbol *(*nodes) = malloc(sizeof(nodoArbol *) * (num_nodes+1)); // find a better way instead of num_nodes
    for (int i = 0; i < num_nodes+1; ++i)
        nodes[i] = NULL;

    nodes[0] = *root;

    nodoArbol *node = NULL;
    int i = 0;

    while (nodes[0]) // el vector se va actualizando cada vez
    {
        node = nodes[0]; 
        for (i = 0; nodes[i + 1]; ++i) // mover todo una pos a la izq
            nodes[i] = nodes[i + 1];

        nodes[i] = NULL; // borrar el ultimo elemento

        if (node->left) // si tiene hijo se agrega al vector
            nodes[i++] = node->left;
        else // sino, es el elemento que debe se debe ingresar
        {
            node->left = newest;
            break;
        }

        if (node->right) // si tiene hijo se agrega al vector
            nodes[i] = node->right;
        else // sino, es el elemento que debe se debe ingresar
        {
            node->right = newest;
            break;
        }
    }
    free(nodes);
}
*/
void insertarPorNivel(Nodo **arbol, int dato)
{
    
	Nodo *masNuevo = busquedaParaNiveles(*arbol, dato);
	printf("\nEntrar a insertar");
    Nodo *act = *arbol;
    masNuevo = malloc(sizeof(Nodo));
    masNuevo->izq = masNuevo->der = NULL;
    masNuevo->dato = dato;

    if (!*arbol)
    {
        *arbol = masNuevo;
        return;
    }

    int numeroNodos = cantidadDeElementos(*arbol, 0);

    Nodo *(*vectorNodos) = malloc(sizeof(Nodo *) * (numeroNodos+1)); // find a better way instead of numeroNodos
    for (int i = 0; i < numeroNodos+1; ++i)
        vectorNodos[i] = NULL;

    vectorNodos[0] = *arbol;

    Nodo *auxiliar = NULL;
    int i = 0;

    while (vectorNodos[0]) // el vector se va actualizando cada vez
    {
        auxiliar = vectorNodos[0];
        for (i = 0; vectorNodos[i + 1]; ++i) // mover todo una pos a la izq
            vectorNodos[i] = vectorNodos[i + 1];

        vectorNodos[i] = NULL; // borrar el ultimo elemento

        if (auxiliar->izq) // si tiene hijo se agrega al vector
            vectorNodos[i++] = auxiliar->izq;
        else // sino, es el elemento que debe se debe ingresar
        {
            auxiliar->izq = masNuevo;
            break;
        }

        if (auxiliar->der) // si tiene hijo se agrega al vector
            vectorNodos[i] = auxiliar->der;
        else // sino, es el elemento que debe se debe ingresar
        {
            auxiliar->der = masNuevo;
            break;
        }
    }
    free(vectorNodos);
}



void insertar(Nodo **arbol, int dato){
    Nodo *nuevo = NULL;
    
    if(!(*arbol)) //Creacion de nodo nuevo
    {
        nuevo = malloc(sizeof(Nodo));
        nuevo->der =NULL;
		nuevo->izq = NULL;
        nuevo->dato = dato;
        *arbol = nuevo;
        return;
    }
    
	if(dato < (*arbol)->dato)		
   		insertar(&(*arbol)->izq, dato);
	else if(dato > (*arbol)->dato)
   		insertar(&(*arbol)->der, dato);
   	else	
   		printf("\nNumero ya ingresado!");
}


int existe(Nodo *arbol, int buscar) {
        while (arbol != NULL) { //Mientras no sea nulo busca
            if (buscar == arbol->dato)
                return 1;
            else if (buscar > arbol->dato)
                arbol = arbol->der;
			else
        		arbol = arbol->izq;
        }
        return 0;//No se ha encontrado
}
/*

Nodo* existeRecursivo(Nodo *arbol, int buscar){
        if(arbol)
		
		while (arbol != NULL) { //Mientras no sea nulo busca
            if (buscar == arbol->dato)
                return 1;
            else if (buscar > arbol->dato)
                arbol = arbol->der;
			else
                arbol = arbol->izq;
        }
        return 0;//No se ha encontrado
}
*/




void inOrden(Nodo *arbol) {//Impresion in order
    if (arbol != NULL) {
		inOrden(arbol->der);
    	printf("\n%d ",arbol->dato);
    	inOrden(arbol->izq);	
    }
    printf("\nnuloooooooooo");
}

void preOrden(Nodo *arbol) {//Impresion in order
    if (arbol != NULL) {
    	printf("\n%d ",arbol->dato);
    	preOrden(arbol->izq);
    	preOrden(arbol->der);	
		
    }
}

void posOrden(Nodo *arbol) {//Impresion in order
    if (arbol != NULL) {
        posOrden(arbol->izq);
        posOrden(arbol->der);
		printf("\n%d ",arbol->dato);
    }
}    

Nodo* unirArbol(Nodo *izquierdo, Nodo *derecho) {
    
	if(izquierdo == NULL) 
		return derecho;
	if(derecho == NULL)
		return izquierdo;
		
	Nodo *centro = unirArbol(izquierdo->der,derecho->izq);
    izquierdo->der = centro;
    derecho->izq = izquierdo;
    return derecho;
}


void elimina(Nodo **arbol, int datoEliminar){
    if(*arbol == NULL) return;

    if(datoEliminar < (*arbol)->dato)
    	elimina(&(*arbol)->izq, datoEliminar);
	else if(datoEliminar> (*arbol)->dato)
        elimina(&(*arbol)->der, datoEliminar);
    else
    {
        Nodo *p = *arbol;
        *arbol = unirArbol((*arbol)->izq, (*arbol)->der);
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
		free(*arbol);
	}
	*arbol=NULL;
}

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
    /*
	printf("\n\n-----Complete Level Order Traversal:-----\n");
    for ( i=0; i<altura; i++) {
        imprimirNivel(arbol, i);
    }
    printf("\n");
    */
}


int main(){
	Nodo *arbol=NULL;
	int opcionI;//Izquierda o derecha
	int lectura;//Lecturas de teclado
	
	int i;//Iterdor
	int opcion, opcion1;
	Nodo *auxiliar= NULL;
	
	do{
		system("cls");
		printf("\n1.Ingresar\n2Buscar\n3.Eliminar\n4.Ver Arbol\n5.Vaciar meoria\n6.Salir\n7.Digite su opcion: ");
		
		scanf("%d",&opcion);
		
		switch(opcion){
			case 1:
				{
					do{
						printf("\nIngrese un dato: ");
						scanf("%d",&lectura);
						insertar(&arbol, lectura);
						printf("\nDesea ingresar mas dato? \n1. Si\n2.No\nDigite su opcion: ");
						scanf("%d",&lectura);
					}while(lectura!=2);
					
				}
				break;
			case 2:
				{
					printf("\nDigite el dato a buscar: ");
					scanf("%d", &lectura);
					if(existe(arbol, lectura)){
						printf("\nExiste");
						auxiliar=buscar(&arbol,lectura);
						printf("\nBusqueda  nodo: %d",auxiliar->dato);
					}
						
					else
						printf("\nNo existe");
						
					
						
				}
				
				
				break;
				
			case 3:
				{
					printf("\nDigite el dato a eliminar: ");
					scanf("%d", &lectura);
					elimina(&arbol, lectura);
				}	
				break;
				
			case 4:
				{
					printf("\n1. InOrder\n2.PreOrder\n3.PosOrder\n4.Niveles");
					scanf("%d",&opcion1);
					switch (opcion1){
						case 1:
							inOrden(arbol);
							break;
						case 2:
							preOrden(arbol);
							break;
						case 3:
							posOrden(arbol);
							break;
						case 4:
							imprimirNivelArbol(arbol);
							break;	
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

