//librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main()
{
  FILE *fp;
  unsigned char *linea;
  unsigned char *nombre;
  int nump;
  int num;
  char c;
  linea=malloc(sizeof(unsigned char));
  nombre=malloc(sizeof(unsigned char));
  printf("Ingrese el nombre del archivo\n");
  scanf("%s",nombre);
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

  printf("No.Examen|Calificacion|Res. Correctas|  No. Preg  |   Tiempo    \n");
  while((c=getc(fp))!=EOF)
    {
      //printf("  ");
      if(c==',')
	{
	  printf("             ");
	}
      else
	{
	  printf("%c",c);
	}
    }
  printf("\n");

 fclose(fp);
}//end
