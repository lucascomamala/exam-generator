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

int generador () {

	/***************/
	/** Variables **/
	/***************/
	
	int i, count=0, index, n, maxRea;
	char answer;
	char exam[40], archivo[40];
	FILE *newExam,*fp;

	/* Nombre del archivo template */
	do{
	  printf("Ingrese el nombre del archivo fuente para generar el examen (sin la extension):\n");
	  scanf(" %[^\n]", archivo);
	  strcat(archivo, ".csv");
	  printf("\n");
	  fp=fopen(archivo, "r"); //Abrir el archivo origen como modo lectura
	  
	  if(fp==NULL)
	    {
	      printf ("No se encontro el archivo\n");
	      // exit(1);
	    }//end if
	}while(fp==NULL);
	
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
 	
 	/* Escribimos la preguntas */
	for (i=0; i<n; i++) {
		if (i == n-1)
			fprintf(newExam, "%s", reactivos[i]);
		else
			fprintf(newExam, "%s,", reactivos[i]);
	}
	fprintf(newExam, "\n"); //New Line
	
	/* Escribimos la respuestas A */
	for (i=0; i<n; i++)
		if (i == n-1)
			fprintf(newExam, "%s", resA[i]);
		else
			fprintf(newExam, "%s,", resA[i]);
	fprintf(newExam,"\n"); //New Line
	
	/* Escribimos la respuestas B */
	for (i=0; i<n; i++)
		if (i == n-1)
			fprintf(newExam, "%s", resB[i]);
		else
			fprintf(newExam, "%s,", resB[i]);
	fprintf(newExam,"\n"); //New Line

	/* Escribimos la respuestas C */
	for (i=0; i<n; i++)
		if (i == n-1)
			fprintf(newExam, "%s,", resC[i]);
		else
			fprintf(newExam, "%s,", resC[i]);
	fprintf(newExam,"\n"); //New Line

	/* Escribimos la respuestas D */
	for (i=0; i<n; i++)
		if (i == n-1)
			fprintf(newExam, "%s", resD[i]);
		else
			fprintf(newExam, "%s,", resD[i]);
	fprintf(newExam,"\n"); //New Line
	
	/* Escribimos los puntos */
	for (i=0;i<n;i++)
		if (i == n-1)
			fprintf(newExam, "%d", puntos[i]);
		else
			fprintf(newExam, "%d,", puntos[i]);

	fclose(newExam);
	
	printf("Examen generado exitosamente!\n");
	
} //fin del main
