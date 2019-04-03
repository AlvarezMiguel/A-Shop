#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NOM_ARCHIVO "Dulces.txt"


char * obtieneCadena(int linea,char *nombredepa);
int num_lineas_archivo(char * nombredepa);

void consultaInven(int argc, char const *argv[])
{
	char nombredepa[20];

	printf("Nombre del departamento a consultar \n");
	scanf("%s", nombredepa);	

	int linea, noarticulos,totallineas;
	char * cadena, * cantidad;
	float sueldo;
	totallineas= num_lineas_archivo (nombredepa);
	noarticulos=1;
	
	for (linea = 2 ; noarticulos<=(totallineas/6)+1 ; linea)
	{
		noarticulos ++;
		cadena=obtieneCadena(linea,nombredepa);
		printf("***************************\n");
		printf("Articulo : %s\n", cadena);
		cantidad=obtieneCadena(linea+1,nombredepa);
		printf("En existencia : %s\n",cantidad );
		printf("***************************\n");
		linea=linea +5;
	}


}
int num_lineas_archivo(char * nombredepa) //cuenta el número total de lineas en el archivo empleados.
{
   FILE *entrada;
   int ch, num_lineas;
   
   if ((entrada = fopen(nombredepa, "r")) == NULL){
     
     }
   
   num_lineas = 0;
   while ((ch = fgetc(entrada)) != EOF)
   {
      if (ch == '\n')
         num_lineas++;
   }
   
   fclose(entrada);
      
   return num_lineas;
}



char * obtieneCadena(int linea,char*  nombredepa){
	int i;
	static char cadena[30];
	int lines=0;
	FILE *fp; //creamos apuntador a archivo

	if( ( fp = fopen(nombredepa,"r") ) == NULL )//comprueba que haya un archivo con nombre archivo.txt que se pueda leer
	printf("Error al leer el archivo.");

	else{
	while (!feof(fp)){
		
		fscanf(fp, "%s\n", cadena);
		lines++;
		if(lines==linea){
			fclose(fp);
			return cadena;	
		}
	}
}
	fclose(fp); //cierra el archivo 
	return cadena;
}
