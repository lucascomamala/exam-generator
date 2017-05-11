/*
* @file		Examinador.c
*
* @brief	Aplica y califica examenes a partir de un archivo CSV
*
* @author Lucas Comamala, Angeles Contreras, Brenda Themsel 
* @date 	27/04/2017
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include "csvparser.h"

void shuffle (int arr[], int n);
void swap (int *a, int *b);

void examinador () {

  /* Variables para medir el tiempo */ 
 	double segundos = 0;
	double milis;
	struct timeval final, inicio;
	
	/***************/
	/** Variables **/
	/***************/

	int i,n, count=0, index, puntosObt=0, total=0,preguntas=0,respuestas=0;
	double calificacion;
	char answer;
	char input[40], stream[40], cals[40];
	long id;
	
	FILE *califs,*fp;
	
	/* Nombre del examen */
	do{
	  printf("Ingrese el nombre del examen (sin la extension):\n");
	  scanf(" %[^\n]", input);
	  strcpy(stream, input);
	  strcat(stream, ".csv");
	  printf("\n");
	  fp=fopen(stream, "r"); //Abrir el archivo origen como modo lectura
	  
	  if(fp==NULL)
	    {
	      printf ("No se encontro el archivo\n");
	      //exit(1);
	    }//end if
	}while(fp==NULL);
	
	/* Archivo para las calificaciones */
	strcpy(cals, input);
	strcat(cals, "_cal.csv");
	
	/* ID del alumno */
	printf("ID del alumno que va a tomar el examen:\n");
	scanf("%li", &id);
	printf("\n");
	
	/* Checa la cantidad de preguntas que hay en el examen */
	CsvParser *csvparserT = CsvParser_new(stream, ",", 0);
	CsvRow *rowT;
	rowT = CsvParser_getRow(csvparserT);
	n = CsvParser_getNumFields(rowT);
	CsvParser_destroy_row(rowT);
	CsvParser_destroy(csvparserT);
	
	/* Arrays para los reactivos y las respuestas */
	char reactivos[n][100];
	char resA[n][100];
	char resB[n][100];
	char resC[n][100];
	char resD[n][100];
	
	char respuestasTemp[4][100];
	
	/* Array para los puntosstream de cada reactivo */
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
	
	/* CsvParser
	*  Author: James Ramm
	*  Link: https://github.com/JamesRamm/csv_parser
	*/
	CsvParser *csvparser = CsvParser_new(stream, ",", 0);
	CsvRow *row;

	while ((row = CsvParser_getRow(csvparser)) ) {
		const char **rowFields = CsvParser_getFields(row);
		for (i = 0 ; i < CsvParser_getNumFields(row) ; i++) {
			switch (count) {
				case 0:
					strcpy(reactivos[i], rowFields[i]);
					break;
				case 1:
					strcpy(resA[i], rowFields[i]);
					break;
				case 2:
					strcpy(resB[i], rowFields[i]);
					break;
				case 3:
					strcpy(resC[i], rowFields[i]);
					break;
				case 4:
					strcpy(resD[i], rowFields[i]);
					break;
				case 5:
					puntos[i] = atoi(rowFields[i]);
					break;
			}
		}
		count++;
		CsvParser_destroy_row(row);
	}
	CsvParser_destroy(csvparser);

	/***********************/
	/** Aplicar el examen **/
	/***********************/
	
	shuffle(reactivosInd, n);
 	
 	gettimeofday(&inicio, NULL); //iniciamos el contador
 	
 	/* Iteramos n veces (cuantas preguntas) */
	for (i=0; i<n; i++) {
 	
		/* Imprimimos la pregunta */
		printf("%d.- %s\n", i+1, reactivos[reactivosInd[i]]);
		preguntas++;
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
	
		/* Checamos si la respuesta dada es la correcta */
		if ( answer == 'A') {
			if ( strcmp(respuestasTemp[respuestasInd[0]], resA[reactivosInd[i]]) == 0 )
			  {	puntosObt += puntos[reactivosInd[i]]; 	respuestas++;  }
			    total += puntos[reactivosInd[i]];
		
		}

		else if ( answer == 'B') {
			if ( strcmp(respuestasTemp[respuestasInd[1]], resA[reactivosInd[i]]) == 0 )
			 {	puntosObt += puntos[reactivosInd[i]]; 	respuestas++;  }
			    total += puntos[reactivosInd[i]];
		}
		
		else if ( answer == 'C') {
			if ( strcmp(respuestasTemp[respuestasInd[2]], resA[reactivosInd[i]]) == 0 )
				 {	puntosObt += puntos[reactivosInd[i]]; 	respuestas++;  }
			    total += puntos[reactivosInd[i]];
		}
		
		else if ( answer == 'D') {
			if ( strcmp(respuestasTemp[respuestasInd[3]], resA[reactivosInd[i]]) == 0 )
			 {	puntosObt += puntos[reactivosInd[i]]; 	respuestas++;  }
			    total += puntos[reactivosInd[i]];
		}
		
		printf("\n");
		
	} //end_for
	
	//Obtenemos el tiempo transcurrido
	//Codigo obtenido de Diego 
	gettimeofday(&final, NULL);//fin del clock
	segundos = (double)(final.tv_usec - inicio.tv_usec) / 1000000 + (double)(final.tv_sec - inicio.tv_sec);
	
	calificacion = puntosObt*10/total;
	
	//Imprimimos la calificacion y los datos relevantes
	printf("Calificacion: %3.2f\n", calificacion);
	printf("Puntos obtenidos: %d/%d\n", puntosObt, total);//imprimimos la cantidad de puntos que obtuvo el usuario
	printf("Tiempo: %3.2f segundos\n", segundos);//ponemos cuanto tiempo se tardo el alumno en realizar el examn

	/* Abrimos o creamos un nuevo archivo CSV y guardamos las calificacion */
	califs = fopen(cals, "a");
	fprintf(califs, "%li,%3.2f,%d,%d,%3.2f", id, calificacion, respuestas, preguntas, segundos);
	fprintf(califs, "\n");
	fclose(califs);
	
}

/* 
*	Funcion que cambia la posicion de dos ints en un arreglo 
*	Autor: Lucas Comamala
*/
void swap (int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*
*	Funcion que  altera el orden de un arreglo de intsutilizandop la funcion swap().
*	Lo utilizamos para elegir preguntas en desorden
*	Autor: Lucas Comamala
*/
void shuffle (int arr[], int n) {

	srand(time(NULL));
	int i;
	
	for (i = n-1; i > 0; i--) {
		int j = rand() % (i+1);
		swap(&arr[i], &arr[j]);
	}
}
