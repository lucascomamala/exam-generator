/*
* @file		Genrador.c
*
* @brief	Genera examenes a partir de un archivo CSV
*
* @author Lucas Comamala, Angeles Contreras, Brenda Themsel 
* @date 	27/04/2017
*/
/*Librerias*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "csvparser.h"


void swap (int *a, int *b);
void shuffle (int arr[], int n);


/*Inicio del main*/

int main () {

 
	/***************/
	/** Variables **/
	/***************/
	int i, count=0, index, n;
	char answer;
	char exam[30];
	FILE *fp;

	/* Nombre del archivo y cantidad de preguntas */
	printf("Ingrese el nombre del archivo del cual quiere generar examen:");
	scanf(" %[^\n]",exam);
	printf("Ingrese la cantidad de preguntas que desea\n");
	scanf("%d",&n);
	
	/* TODO: Append .csv */
	fp = fopen(exam, "wt");

	/* Arrays para los reactivos y las respuestas */
	char reactivos[30][100];
	char resA[30][100];
	char resB[30][100];
	char resC[30][100];
	char resD[30][100];
	
	char respuestasTemp[4][100];

	/* Array para los puntos de cada reactivo */
	int puntos[30];

	/* Index arrays */
	int reactivosInd[30];
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
	CsvParser *csvparser = CsvParser_new(exam, ",", 0);
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
	
	shuffle(reactivosInd, 30);
 	
 	/* Iteramos n veces (cuantas preguntas) */
	for (i=0; i<n; i++) {
 	
		/* Imprimimos la pregunta */
	  fprintf(fp," %s", reactivos[reactivosInd[i]]);
		
                         	}
	fprintf(fp,"\n");
	for (i=0; i<n; i++){

		fprintf(fp, "%s\n", resA[respuestasInd[i]]);
	            }
	    fprintf(fp,"\n");
	for (i=0; i<n; i++){
	        fprintf(fp,"\n");
	}
	fprintf(fp,"\n");
	for (i=0; i<n; i++){
		fprintf(fp," %s", resB[respuestasInd[i]]);
	           }
	     fprintf(fp,"\n");
	for (i=0; i<n; i++){

		fprintf(fp," %s", resC[respuestasInd[i]]);
	}
	fprintf(fp,"\n");
	for (i=0; i<n; i++){

		fprintf(" %s", resD[respuestasInd[i]]);
	}
	fprintf(fp,"\n");
	for (i=0;i<n;i++){
	  
	  fprintf(" %d", puntos[respuestasInd[i]]);
	}
		fprintf(fp,"\n");
       
	 	
} //end_for
	fclose(fp);
	return 0;	
		
}//fin del main 


/* Brief:funcion que cambia la posicion de dos ints en un arreglo 
 autor: Lucas Comamala*/
void swap (int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
/*Funcion que  altera el orden de un arreglo de ints, se usa para elegir preguntas en desorden
Autor: Lucas Comamala*/
void shuffle (int arr[], int n) {

	srand(time(NULL));
	int i;
	
	for (i = n-1; i > 0; i--) {
		int j = rand() % (i+1);
		swap(&arr[i], &arr[j]);
	}
}
