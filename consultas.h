//librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int consultador()
{
  FILE *fp;
  unsigned char *linea;
  unsigned char *nombre;
  int nump, num, count=1;
  char c;
  
  linea=malloc(sizeof(unsigned char));
  nombre=malloc(sizeof(unsigned char));
  printf("Ingrese el nombre del archivo\n");
  scanf("%s",nombre);
  strcat(nombre, "_cal.csv");
  printf("\n");
  fp=fopen(nombre, "r"); //Abrir el archivo origen como modo lectura
 
  if(fp==NULL)
    {
      printf ("No se encontro el archivo\n");
      exit(1);
    }//end ifgit stat
 
  
  /*while(!feof(fp))
    {
      fgets(linea,sizeof(linea),fp);
       printf("%s",linea);
       num=strlen(linea);
       printf("\n%d",num);
       printf("\n");
      
       }*/

  printf("*--------*--------------*----------------*---------------*--------------------*\n");
  printf("| Cuenta | Calificacion | Res. Correctas | No. Preguntas | Tiempo Transcurrido|\n");
  printf("*--------*--------------*----------------*---------------*--------------------*\n");
  
	while( (c=getc(fp)) != EOF ) {
		//printf("  ");
		
		if(c == ',')
			printf("\t\t");
		
		else
			printf("%c",c);
		
	}
	
	printf("*-----------------------------------------------------------------------------*\n");

 fclose(fp);
}//end
