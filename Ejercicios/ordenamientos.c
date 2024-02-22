#include <stdio.h>
#include <stdlib.h>

  
int dividir(int *arreglo, int inicio, int fin)
{
  int izq;
  int der;
  int pivote;
  int temp;

  pivote = arreglo[inicio];
  izq = inicio;
  der = fin;

	while (izq < der){	//Mientras no se cruzen los índices
    	while (arreglo[der] > pivote)
			der--;

	while ((izq < der) && (arreglo[izq] <= pivote))
		izq++;
    
	if(izq < der){	// Si todavia no se cruzan los indices seguimos intercambiando
		temp= arreglo[izq];
		arreglo[izq] = arreglo[der];
		arreglo[der] = temp;
    }
  }

  //Los indices ya se han cruzado, ponemos el pivote en el lugar que le corresponde
  temp = arreglo[der];
  arreglo[der] = arreglo[inicio];
  arreglo[inicio] = temp;

  return der; //La nueva posición del pivote
}

void quickSort(int *arreglo, int inicio, int fin){
	int pivote;
	
	if(inicio < fin){
		pivote = dividir(arreglo, inicio, fin );
		quickSort( arreglo, inicio, pivote - 1 );//ordeno la lista de los menores
    	quickSort( arreglo, pivote + 1, fin );//ordeno la lista de los mayores
  	}
}



void heapify(int *arreglo, int dimension, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 	int temporal;
    // If left child is larger than root
    if (l < dimension && arreglo[l] > arreglo[largest])
        largest = l;
 
    // If right child is larger than largest so far
    if (r < dimension && arreglo[r] > arreglo[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        temporal = arreglo[i];
        arreglo[i] = arreglo[largest];
        arreglo[largest] = temporal;
        heapify(arreglo, dimension, largest);
    }
}

/*

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify (int *numbers, int size, int i) {
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2
    int tmp;

    // If left child is larger than root
    if (l < size && numbers[l] > numbers[largest]) {
        largest = l;
    }

    // If right child is larger than largest so far
    if (r < size && numbers[r] > numbers[largest]) {
        largest = r;
    }

    // If largest is not root
    if (largest != i) {
        swap(i, largest, numbers);

        // Recursively heapify the affected sub-tree
        heapify(numbers, size, largest);
    }
}

// main function to do heap sort
void heapSort (int *numbers, int size) {
    int i, tmp;
    // Build heap (rearrange array)
    for (i = size / 2 - 1; i >= 0; i--) {
        heapify(numbers, size, i);
    }

    // One by one extract an element from heap
    for (i = size-1; i >= 0; i--) {
        // Move current root to end
        swap(0, i, numbers);

        // call max heapify on the reduced heap
        heapify(numbers, i, 0);
    }
}


*/
 
// main function to do heap sort
void heapSort(int *arreglo, int dimension)
{
	int temporal;
    // Build heap (rearregloange arregloay)
    for (int i = dimension / 2 - 1; i >= 0; i--)
        heapify(arreglo, dimension, i);
 
    // One by one extract an element from heap
    for (int i = dimension - 1; i >= 0; i--) {
        // Move current root to end
 		temporal = arreglo[0];
        arreglo[0] = arreglo[i];
        arreglo[i] = temporal;
        // call max heapify on the reduced heap
        heapify(arreglo, i, 0);
    }
}
 







void burbuja(int *arreglo,int dimension){
  int i, j, aux;

  	for (i = 0; i < dimension; i++)
    	for ( j = 0; j < dimension-1-i; j++)
      		if (arreglo[j] > arreglo[j+1]) {
	         	aux = arreglo[j];
    		     arreglo[j] = arreglo[j+1];
         		arreglo[j+1] = aux;
       		}
}

void seleccion(int *arreglo, int dimension) {
  	int temporal;
  
	for (int i = 0; i < dimension - 1; i++) {
		for (int j = i + 1; j < dimension; j++){
	     	if (arreglo[i] > arreglo[j]) {
	        	temporal = arreglo[i];
	        	arreglo[i] = arreglo[j];
	        	arreglo[j] = temporal;
	     	}
		}
	}
}


void insercion(int *arreglo, int dimension) {
	int i, j, temporal;

	for(i=0; i<dimension; i++){
		temporal=arreglo[i];
		j=i-1;
		
		while(j>=0 && arreglo[j] >temporal){
			arreglo[j+1] = arreglo[j];
			j--;
		}
		arreglo[j+1] = temporal;
	}
}



void merge(int *izq,int nIzq,int *der,int nDer,int *A)
{
 	int i=0,j=0,k=0;
 	
 	while( ( i < nIzq ) && ( j < nDer ) ){
  		if( izq[i] <= der[j]){
   			A[k] = izq[i];
   			i++;	
		}else{
   			A[k] = der[j];
   			j++;
  		}
		k++;
 	}
 
 	while(i < nIzq){
  		A[k] = izq[i];
  		i++;
		k++;
 	}
 
 	while(j < nDer){
  		A[k] = der[j];
  		j++;
		k++;
 	}
}


void mergeSort(int *arreglo,int dimension) {
 	if(dimension==1) return;
 
 	int mitad = dimension / 2;
 	
 	int *izq =  malloc(sizeof(int) * mitad);
 	int *der =malloc(sizeof(int) * (dimension-mitad));
 	
	 for(int i=0;i<mitad;i++)
  		izq[i] = arreglo[i];
 	for(int i=mitad;i<dimension;i++)
  		der[i-mitad] = arreglo[i];
 	
	mergeSort(izq, mitad);
 	mergeSort(der, dimension-mitad);
 	merge(izq, mitad, der, dimension-mitad, arreglo);
}


void main()
{
    int i;
    int A[] = {2, 4,100, 5, 7, 1, 2, 3, 9,-2,0,6,56,7,-1};
    int r = sizeof(A)/sizeof(A[0]);
	
	
	//burbuja(A, r);
	//insercion(A, r);
	//seleccion(A, r);
    //heapSort(A, r);
	//mergeSort(A, r);
	quickSort(A, 0,r-1);

    for (i = 0; i < r ; i++)
    {
        printf(" %i ", *(A + i));
    }
}
