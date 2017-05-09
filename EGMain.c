/*
* @file		EGMain.c
*
* @brief	Este es un programa para la creacion de examenes a partir de un archivo
*					CSV. Los examenes se aplican y califican para un alumno y se guardan
*					los datos de cada examen aplicado.
*					
*					Al aplicar un examen se revuelve el orden de las preguntas (y las
*					respuestas) cada vez que se aplica a diferentes alumnos.
*
*					Este archivo es el menu principal para el programa.
*
* @author Lucas Comamala, Angeles Contreras, Brenda Themsel 
* @date 	27/04/2017
*/


#include <stdio.h>

#include "Generador.h"
#include "Examinador.h"
#include "consultas.h"

void generar(void);
void examinar(void);
void consultar(void);

int main (int argc, char *argv[]) {
	system("clear");
	
	char opc[5];
	
	printf("\t\t\tSistema generador de examenes.\n");
	printf("\tAutores: Lucas Comamala, Angeles Contreras, Brenda Themsel\n");
	
	do {
		
		/* Menu */
		printf("\n\n");
		printf("1. Generar un examen\n");
		printf("2. Aplicar examen\n");
		printf("3. Consultar calificaciones\n");
		printf("0. Salir\n");
	
		scanf(" %[^\n]", opc);
		printf("\n");
		
		switch (opc[0]) {
			case '0':
				break;
			case '1':
				generar();
				break;
			case '2':
				examinar();
				break;
			case '3':
				consultar();
				break;
			default:
				printf("Opcion no valida\n");
				break;
		} //end_switch
		
	} while (opc[0] != '0');
	
	return 1;
	
} //end_main

void generar() {
	generador();
}

void examinar() {
	examinador();
}

void consultar() {
	consultador();
}
