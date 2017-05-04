/*
* @file		Generador.c
*
* @brief	Genera examenes a partir de un archivo CSV
*
* @author Lucas Comamala, Angeles Contreras, Brenda Themsel 
* @date 	27/04/2017
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "csvparser.h"

void shuffle1 (int arr[], int n);
void swap1 (int *a, int *b);

int generador () {

	/***************/
	/** Variables **/
	/***************/
	
	int i, count=0, index, n, maxRea;
	char answer;
	char exam[40], archivo[40];
	FILE *newExam;

	/* Nombre del archivo template */
	printf("Ingrese el nombre del archivo fuente para generar el examen (sin la extension):\n");
	scanf(" %[^\n]", archivo);
	strcat(archivo, ".csv");
	printf("\n");
	
	/* Checa la cantidad de preguntas que hay en el template */
	CsvParser *csvparserT = CsvParser_new(archivo, ",", 0);
	CsvRow *rowT;
	rowT = CsvParser_getRow(csvparserT);
	maxRea = CsvParser_getNumFields(rowT);
	CsvParser_destroy_row(rowT);
	CsvParser_destroy(csvparserT);
	
	/* Cantidad de preguntas para el examen generado */
	printf("Ingrese la cantidad de preguntas que desea:\n");
	scanf("%d",&n);
	printf("\n");
	
	/* Nombre para el examen generado */
	printf("Ingrese el nombre del examen que se va a generar (sin extension):\n");
	scanf(" %[^\n]", exam);
	strcat(exam, ".csv");
	printf("\n");
	
	/* Creamos un nuevo archivo CSV para el examen generado */
	newExam = fopen(exam, "wt");
	
	
	/* Arrays para los reactivos y las respuestas */
	char reactivos[maxRea][100];
	char resA[maxRea][100];
	char resB[maxRea][100];
	char resC[maxRea][100];
	char resD[maxRea][100];

	/* Array para los puntos de cada reactivo */
	int puntos[maxRea];

	/* Index arrays */
	int reactivosInd[n];
	for (i=0; i<n; i++)
		reactivosInd[i] = i;
	
	/**************/
	/** Leer CSV **/
	/**************/
	
	/*************************************************/
	/*	CsvParser
	/*	Author: James Ramm
	/*	Link: https://github.com/JamesRamm/csv_parser
	/************************************************/
	
	CsvParser *csvparser = CsvParser_new(archivo, ",", 0);
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

	/*******************************************/
	/** Guardamos n preguntas en el nuevo CSV **/
	/*******************************************/
	
	shuffle1(reactivosInd, n);
 	
 	/* Escribimos la preguntas */
	for (i=0; i<n; i++) {
		if (i == n-1)
			fprintf(newExam, "%s", reactivos[reactivosInd[i]]);
		else
			fprintf(newExam, "%s,", reactivos[reactivosInd[i]]);
	}
	fprintf(newExam, "\n"); //New Line
	
	/* Escribimos la respuestas A */
	for (i=0; i<n; i++)
		if (i == n-1)
			fprintf(newExam, "%s", resA[reactivosInd[i]]);
		else
			fprintf(newExam, "%s,", resA[reactivosInd[i]]);
	fprintf(newExam,"\n"); //New Line
	
	/* Escribimos la respuestas B */
	for (i=0; i<n; i++)
		if (i == n-1)
			fprintf(newExam, "%s", resB[reactivosInd[i]]);
		else
			fprintf(newExam, "%s,", resB[reactivosInd[i]]);
	fprintf(newExam,"\n"); //New Line

	/* Escribimos la respuestas C */
	for (i=0; i<n; i++)
		if (i == n-1)
			fprintf(newExam, "%s,", resC[reactivosInd[i]]);
		else
			fprintf(newExam, "%s,", resC[reactivosInd[i]]);
	fprintf(newExam,"\n"); //New Line

	/* Escribimos la respuestas D */
	for (i=0; i<n; i++)
		if (i == n-1)
			fprintf(newExam, "%s", resD[reactivosInd[i]]);
		else
			fprintf(newExam, "%s,", resD[reactivosInd[i]]);
	fprintf(newExam,"\n"); //New Line
	
	/* Escribimos los puntos */
	for (i=0;i<n;i++)
		if (i == n-1)
			fprintf(newExam, "%d", puntos[reactivosInd[i]]);
		else
			fprintf(newExam, "%d,", puntos[reactivosInd[i]]);

	fclose(newExam);
	
	printf("Examen generado exitosamente!\n");
	
} //fin del main

/* Brief:funcion que cambia la posicion de dos ints en un arreglo 
 autor: Lucas Comamala*/
void swap1 (int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
/*Funcion que  altera el orden de un arreglo de ints, se usa para elegir preguntas en desorden
Autor: Lucas Comamala*/
void shuffle1 (int arr[], int n) {

	srand(time(NULL));
	int i;
	
	for (i = n-1; i > 0; i--) {
		int j = rand() % (i+1);
		swap1(&arr[i], &arr[j]);
	}
}
