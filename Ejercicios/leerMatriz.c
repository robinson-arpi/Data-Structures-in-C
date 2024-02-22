#include <stdio.h>
#include <stdlib.h>


int **leerMatrizIntSinFinal(int *dimension){
	char carac;
	char lecturaNumero[15];
	FILE *file = NULL;
	
	int **matriz = NULL;
	int i,j, aux;
	int filas,columnas;
	file = fopen("matriz.txt", "rt");
	
	int longitudMatriz = 0;
	
	
    if (file)
    {
        while (fscanf(file, "%c", &carac) == 1 && carac != '\n') // si se leyo correctamente el caracter
            if (carac == ',') //Numeros separados por comas
                longitudMatriz++; 
        longitudMatriz++;
        printf("Longitud de matriz dentro: %d", longitudMatriz);
        fclose(file);
    }
        
    matriz = malloc(sizeof(int*) * longitudMatriz);//Reserva memoria
	for ( i = 0; i < longitudMatriz; i++)
        matriz[i] = malloc(sizeof(int) * longitudMatriz);
        
        
    file = fopen("matriz.txt", "rt");    
	// rellenar el array
	filas = 0;
	columnas = 0;
	aux = 0;
	
    while (fscanf(file, "%c", &carac)==1){
        if (carac == '\n' || carac == ','){ // si se avanza una linea
        	
			lecturaNumero[aux] = '\0';
            matriz[filas][columnas++] = atoi(lecturaNumero);
        	aux = 0;
            if(carac == '\n'){
            	filas++;
            columnas = 0;	
			}
			
			for (i = 0; i < 15; i++)
            lecturaNumero[i] = ' '; // "borrar" el contenido
			continue;	
        } 
        lecturaNumero[aux++] = carac; // conformar el string caracter por caracter	
    }
    //Ultimo valor
    lecturaNumero[aux] = '\0';
    matriz[filas][columnas++] = atoi(lecturaNumero);
    
    fclose(file);
    
	*dimension = longitudMatriz;
	return matriz;
}

int **leerMatrizIntConFinal(int *dimension){
	char carac;
	char lecturaNumero[15];
	FILE *file = NULL;
	
	int **matriz = NULL;
	int i,j, aux;
	int filas,columnas;
	file = fopen("matriz.txt", "rt");
	
	int longitudMatriz = 0;
	int longitudFilas = 2;
	
    if (file)
    {
        while (fscanf(file, "%c", &carac) == 1 && carac != '\n') // si se leyo correctamente el caracter
            if (carac == ',') //Numeros separados por comas
                longitudMatriz++; 
        longitudMatriz++;
        
        while (fscanf(file, "%c", &carac)==1) {
        	if(carac == '\n'){
        		longitudFilas++;
			}
		}
        
        if(longitudFilas != longitudMatriz){
        	printf("\nNo es matriz");
		}
        
        
        fclose(file);
    }
        
    matriz = malloc(sizeof(int*) * longitudMatriz);//Reserva memoria
	for ( i = 0; i < longitudMatriz; i++)
        matriz[i] = malloc(sizeof(int) * longitudMatriz);
        
        
    file = fopen("matriz.txt", "rt");    
	// rellenar el array
	filas = 0;
	columnas = 0;
	aux = 0;
	
    while (fscanf(file, "%c", &carac)==1){
        if (carac == '\n'){
        	filas++;
            columnas = 0;	
		}
		
		if (carac == ',' || carac == ';'){ // si se avanza una linea
        	
			lecturaNumero[aux] = '\0';
            matriz[filas][columnas++] = atoi(lecturaNumero);
        	aux = 0;
            
			for (i = 0; i < 15; i++)
            lecturaNumero[i] = ' '; // "borrar" el contenido
			continue;	
        } 
        lecturaNumero[aux++] = carac; // conformar el string caracter por caracter	
    }
    
    fclose(file);
    
	*dimension = longitudMatriz;
	return matriz;
}



int main(){
	int **matriz = NULL;
	int dimension;
	
	matriz = leerMatrizIntConFinal(&dimension);
	printf("\n\n\nLongitud de matriz fuera: %d", dimension);
	for(int i = 0;i< dimension ;i++){
		printf("\n");
		for(int j = 0;j<dimension ;j ++){
			printf("%d ", matriz[i][j]);
		}
	}
	
	
}
