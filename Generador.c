/*
* @file		Genrador.c
*
* @brief	Genera examenes a partir de un archivo CSV
*
* @author Lucas Comamala
* @date 	27/04/2017
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void swap (int *a, int *b);
void shuffle (int arr[], int n);

int main (int argc, char *argv[]) {
	
	/***************/
	/** Variables **/
	/***************/
	int i, index;
	char answer;
	
	/* Cantidad de preguntas */
	int n = 10; // TODO
	
	/* Arrays para los reactivos y las respuestas */
	char reactivos[n][50];
	char resA[n][50];
	char resB[n][50];
	char resC[n][50];
	char resD[n][50];
	
	char respuestasTemp[4][50];
	
	/* Array para los puntos de cada reactivo */
	int puntos[n];
	
	/* Index arrays */
	int reactivosInd[n];
	for (i=0; i<n; i++)
		reactivosInd[i] = i;
	int respuestasInd[] = {0, 1, 2, 3};
	
	//int nn = sizeof(reactivosInd)/ sizeof(reactivosInd[0]);
	
	/********************/
	/** Inicializacion **/
	/********************/
	
	/* Preguntas */
	strcpy(reactivos[0], "Francia");
	strcpy(reactivos[1], "Italia");
	strcpy(reactivos[2], "Alemania");
	strcpy(reactivos[3], "Espana");
	strcpy(reactivos[4], "Suiza");
	strcpy(reactivos[5], "Suecia");
	strcpy(reactivos[6], "Reino Unido");
	strcpy(reactivos[7], "Polonia");
	strcpy(reactivos[8], "Austria");
	strcpy(reactivos[9], "Portugal");
	
	/* Respuestas Correctoas */
	strcpy(resA[0], "Paris");
	strcpy(resA[1], "Roma");
	strcpy(resA[2], "Berlin");
	strcpy(resA[3], "Madrid");
	strcpy(resA[4], "Berne");
	strcpy(resA[5], "Estocolmo");
	strcpy(resA[6], "Londres");
	strcpy(resA[7], "Varsovia");
	strcpy(resA[8], "Vienna");
	strcpy(resA[9], "Lisbon");
	
	/* Respuestas Incorrectoas */
	for (i=0; i<10; i++)
		strcpy(resB[i], "x");
	
	for (i=0; i<10; i++)
		strcpy(resC[i], "y");
	
	for (i=0; i<10; i++)
		strcpy(resD[i], "z");


	/***********************/
	/** Aplicar el examen **/
	/***********************/
	
	//shuffle(reactivosInd, n);
 	
 	/* Iteramos n veces (cuantas preguntas) */
	for (i=0; i<n; i++) {
 	
		/* Imprimimos la pregunta */
		printf("%d.- %s\n", i+1, reactivos[reactivosInd[i]]);
		
		/* Creamos un array temporal con las respuestas de una solo pregunta y utilizamos shuffle */
		strcpy(respuestasTemp[0], resA[reactivosInd[i]]);
		strcpy(respuestasTemp[1], resB[reactivosInd[i]]);
		strcpy(respuestasTemp[2], resC[reactivosInd[i]]);
		strcpy(respuestasTemp[3], resD[reactivosInd[i]]);
		
		shuffle(respuestasInd, 4);	 	
		
		/* Imprimimos las respuestas */
		printf("  A - %s\n", respuestasTemp[respuestasInd[0]]);
		printf("  B - %s\n", respuestasTemp[respuestasInd[1]]);
		printf("  C - %s\n", respuestasTemp[respuestasInd[2]]);
		printf("  D - %s\n", respuestasTemp[respuestasInd[3]]);
		
		/* Capturamos y validamos la respuesta del usuario */
		while (1) {
			scanf(" %c", &answer);
			answer = toupper(answer);
			if ( answer=='A' || answer=='B' || answer=='C' || answer=='D' ) break;
		}
		
		/* Checamos si la respuesta dada es la Correctoa */
		if ( answer == 'A')
			if ( strcmp(respuestasTemp[respuestasInd[0]], resA[reactivosInd[i]]) == 0 )
				printf("Correcto\n");
			else
				printf("Incorrecto\n");
		
		else if ( answer == 'B')
			if ( strcmp(respuestasTemp[respuestasInd[1]], resA[reactivosInd[i]]) == 0 )
				printf("Correcto\n");
			else
				printf("Incorrecto\n");
		
		else if ( answer == 'C')
			if ( strcmp(respuestasTemp[respuestasInd[2]], resA[reactivosInd[i]]) == 0 )
				printf("Correcto\n");
			else
				printf("Incorrecto\n");
		
		else if ( answer == 'D')
			if ( strcmp(respuestasTemp[respuestasInd[3]], resA[reactivosInd[i]]) == 0 )
				printf("Correcto\n");
			else
				printf("Incorrecto\n");
		
		printf("\n");
	 	
} //end_for
	
	
	return 0;
}

/* 
* Funciones para alterar el orden de un arreglo de ints al azar
*/

void swap (int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void shuffle (int arr[], int n) {

	srand(time(NULL));
	int i;
	
	for (i = n-1; i > 0; i--) {
		int j = rand() % (i+1);
		swap(&arr[i], &arr[j]);
	}
}
