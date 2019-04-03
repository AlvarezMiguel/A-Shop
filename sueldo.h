#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NOM_ARCHIVO "empleados.txt"

char * obtieneCadena(int linea); // extrae la cadena contenida en "X" numéro de lines (algo ineficiente porque recorre todo el archivo) 
int num_lineas_archivo(void); //obtiene el numero de lineas del archivo empleado con el fin de sabes cuántos empleados existen

void sueldo ()// para probarlo, cambie sueldo por main , DEBE TENER CREADO EL ARCHIVO empleado.txt
{
	
	int linea,noempleado, totallineas;
	char * cadena, *nomEmp, *apEmp; 
	float sueldo,sueldototal;
	noempleado=1;//contador de empleados 
	sueldototal=0;
	totallineas= num_lineas_archivo ();// obtiene el numero total de lineas en el archivo empleados 
	
	
	for(linea=6; noempleado<=(totallineas/7)+1; linea)  //suma el sueldo de cada empleado 
		//comienza en la linea donde está el campo sueldo (linea 5) 
		// la condición evalua que el numero de empleados conincida con la cantidad de lineas en el archivo 
	{
		
		noempleado++;
		cadena=obtieneCadena(linea);// cadena extraida del archivo, regresa  un apuntador 
		sueldo=(float)atof(cadena); //cambio de cadena a float
		printf("--------------------\n");
		nomEmp=obtieneCadena(linea-5);
		printf("%s", nomEmp);
		apEmp=obtieneCadena(linea-4);
		printf("%s", apEmp);
		printf("Sueldo :%f\n ",sueldo);
		printf("--------------------\n");
		linea=linea+7;
		sueldototal = sueldototal + sueldo;
		
	}
	printf("Total : %f\n ",sueldototal);


}

int num_lineas_archivo(void) //cuenta el número total de lineas en el archivo empleados.
{
   FILE *entrada;
   int ch, num_lineas;
   
   if ((entrada = fopen(NOM_ARCHIVO, "r")) == NULL){
     
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


char * obtieneCadena(int linea) // obtiene la cadena de una linea correspondiente al archivo
{
	
	static char cadena[30]; // aquí se almacenará el sueldo como cadena
	int lines=0;
	FILE *fp; //creamos apuntador a archivo

	if( ( fp = fopen(NOM_ARCHIVO,"r") ) == NULL )
	printf("Error al leer el archivo.");

	else{
	while (!feof(fp))
	{
		
		fgets(cadena, 100, fp) != NULL;// almacena una cadena longitud 100
		lines++; 
		if(lines==linea) 
		{
			fclose(fp);
			return cadena;	// cadena almacena la linea de interés. 
		}
	}
}
	 
	return cadena;
}