#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int dato;
	int contador;
	struct nodo *izq;
	struct nodo *der;	
};
typedef struct nodo NodoA;

struct nodoL {
	NodoA *arbol;
	struct nodoL *siguiente;
};
typedef struct nodoL NodoL;

void insertar(NodoA **arbol, int dato){
    NodoA *nuevo = NULL;
    
    if(!(*arbol)) //Creacion de nodo nuevo
    {
        nuevo = malloc(sizeof(NodoA));
        nuevo->der =NULL;
		nuevo->izq = NULL;
        nuevo->dato = dato;
        nuevo->contador = 1;
        *arbol = nuevo;
        return;
    }
    
	if(dato < (*arbol)->dato)		
   		insertar(&(*arbol)->izq, dato);    	
	else if(dato > (*arbol)->dato)
   		insertar(&(*arbol)->der, dato);    	
}



void insertarArbol(NodoL **lista, NodoA *llegada){
	NodoL *nuevo=malloc(sizeof(NodoL));
	
	nuevo->arbol = llegada;
	nuevo->siguiente=NULL;
	
	NodoL *aux=*lista;
		
	if(aux==NULL){
		*lista=nuevo;
	}else{
		while(aux->siguiente!=NULL){
			aux=aux->siguiente;
		}
		aux->siguiente=nuevo;
	}	
}

void inOrden(NodoA *arbol) {//Impresion in order
    if (arbol != NULL) {
		inOrden(arbol->der);
    	printf("\n%d ",arbol->dato);
    	inOrden(arbol->izq);	
    }
}

NodoA* unirArbol(NodoA *izquierdo, NodoA *derecho) {
    
	if(izquierdo == NULL)	return derecho;
		
    if(derecho == NULL)	return izquierdo;

    
	NodoA *centro = unirArbol(izquierdo->der,derecho->izq);
    izquierdo->der = centro;
    derecho->izq = izquierdo;
    return derecho;
}


void elimina(NodoA **arbol, int datoEliminar){	
    if(*arbol == NULL) return;

    if(datoEliminar < (*arbol)->dato)
		elimina(&(*arbol)->izq, datoEliminar);
    else if(datoEliminar> (*arbol)->dato)
        elimina(&(*arbol)->der, datoEliminar);
    else
    {
    	if((*arbol)->contador>1)
    		(*arbol)->contador--;
    	else{
    		NodoA *p = *arbol;
        	*arbol = unirArbol((*arbol)->izq, (*arbol)->der);
        	free(p);	
		}
        
	}
	
}

void liberarMemoria (NodoA **arbol){
	
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




int alturaArbol(NodoA* arbol) {
    
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
 


void imprimirNivelArbol(NodoA* arbol) {
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



void retornarAltura(NodoA *arbol , int nivel,int *altura)
{
    if (arbol != NULL)
    {
        retornarAltura(arbol->izq, nivel + 1,altura);
        if (nivel>*altura)
            *altura = nivel;
        retornarAltura(arbol->der, nivel + 1,altura);
    }
}


void imprimirArboles(NodoL *lista){
	int i=1;
	while(lista!=NULL){
		printf("\nArbol %d",i);
		inOrden(lista->arbol);
		i++;
		lista=lista->siguiente;
	}
	
}


Nodo* buscar(Nodo** arbol, int datoBuscar){
	if(!(*arbol))
		return NULL;
	else if (datoBuscar < (*arbol)->dato)
		buscar(&(*arbol)->izq, datoBuscar, clave);	
	else if (datoBuscar > (*arbol)->dato)	
		buscar(&(*arbol)->der, datoBuscar, clave);
	else
		return *arbol;	
}

int comparacionArboles(Nodo *arbol1, Nodo *arbol2)
{
   if (arbol1 != NULL && arbol2 != NULL && arbol1->dato == arbol2->dato)
      return comparacionArboles(arbol1->izq, arbol2->izq) && comparacionArboles(arbol1->der, arbol2->der);
   else 
      return arbol1 == arbol2;
}

void comparacionesArboles(NodoL *lista){
	NodoA *aux=null;
	NodoL *listaAuxiliar = lista;
	NodoL *iteracion = NULL;
	NodoA *comparacionAux=NULL;
	int i = 0;
	int j = 0;
	
	while(listaAuxiliar!=NULL){
		aux=listaAuxiliar->arbol;
		iteracion= lista;
		j=0;	
		while(iteracion!=NULL){
			if(i!=j){
				comparacionAux= buscar();
				if(comparacionArboles(aux, iteracion->arbol)){
					printf("\nArbol ")
				}
				
				
			}
			
			iteracion=iteracion->siguiente;
			j++;
		}
		
		
		
		
		
		listaAuxiliar=listaAuxiliar->siguiente;
		i++
	}
	
	
}

int main(){
	NodoA *arbol=NULL;
	
	int lectura;//Lecturas de teclado
	int cantidad;//Cantidad d enumero a ingresar
	int i;//Iterdor
	int opcion;

	NodoL *listaArboles= NULL;
	
	int altura=0;
	int dato;
	
	do{
		printf("\nInsertar dato: ");
		scanf("%d",&dato);
		insertar(&arbol, dato);	
			
		altura=0;
		retornarAltura(arbol,1,&altura);
		
		if((altura-1)==4){
			printf("\nAltura actual: %d", altura);
			printf("\nCreacion de nuevo arbol->Insercion en lista");
			elimina(&arbol, dato);//Vuekve a tener arbol fr 3 niveles
			insertarArbol(&listaArboles, arbol);
			arbol= NULL;
			insertar(&arbol, dato);	//Ingreso en otro arbol	
		}
		
		printf("\nInsertar otro dato\n1. Si\n2. Nod\nDigite su opcion: ");
		scanf("%d", &opcion);
		
	}while(opcion==1);
	
	compararArboles(listaArboles);
	
	imprimirArboles(listaArboles);
}


