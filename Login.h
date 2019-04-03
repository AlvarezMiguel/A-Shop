#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int tipoEmpleado(char* user,char* contra);
int obtieneLinea(char* nombreEmp);
char * recuperarCadena(int linea);
int correrLogin();

int correrLogin() {
	char user[30];
	char contra[30];
	printf("Ingrese el usuario: ");
	scanf(" %s",user);
	printf("Ingrese la contraseña: ");
	scanf(" %s",contra);
	int tipo=tipoEmpleado(user,contra);
	//printf("%d\n",tipo );
	return tipo;
}

int tipoEmpleado(char* user,char* contra){
	int tipo;
	int lineaStrart=obtieneLinea(user);
	char* cad;
	cad=recuperarCadena(lineaStrart+2);
	
	cad=recuperarCadena(lineaStrart+3);
	if(strcmp(cad,contra) ==0){
		cad=recuperarCadena(lineaStrart+4);
		tipo = cad[0] - '0'; 
		return tipo;
	}
	else {
		return 0;
	}
}


int obtieneLinea(char* nombreEmp){
	int i;
	static char nombre[30];
	int lines=0;
	FILE *fp; //creamos apuntador a archivo

	if( ( fp = fopen("empleados.txt","r") ) == NULL )//comprueba que haya un archivo con nombre archivo.txt que se pueda leer
	printf("Error al leer el archivo.");

	else{
	while (!feof(fp)) {
		fscanf(fp, "%s\n", nombre);
		lines++;
		if(strcmp(nombre,nombreEmp) == 0) {
			fclose(fp);
			return lines-1;	
		}
	}
}
	fclose(fp); //cierra el archivo 
	return lines;
}

char * recuperarCadena(int linea){
	int i;
	static char nombre[30];
	int lines=0;
	FILE *fp; //creamos apuntador a archivo

	if( ( fp = fopen("empleados.txt","r") ) == NULL )//comprueba que haya un archivo con nombre archivo.txt que se pueda leer
	printf("Error al leer el archivo.");
	else{
		while (!feof(fp)) {
			fscanf(fp, "%s\n", nombre);
			lines++;
			if(lines==linea-1) {
				fclose(fp);
				return nombre;	
			}
		}
	}
	fclose(fp); //cierra el archivo 
	//printf("%s\n",nombre );
	//printf("sdsd\n");
	return nombre;
}