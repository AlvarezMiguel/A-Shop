#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int tipoEmpleado(char* user);
int obtieneLinea(char* idA);
char * recuperarCadena(int linea);
int correrLogin();


int main(int argc, char const *argv[]) {
	int lineaStart,numarti, opcion,mascantidad, menoscantidad;
	char * contenido;
	char dep[30];
	char id[30];
	int op;

	do {
		printf("1. Agregar articulo\n");
		printf("2. Eliminar articulo\n");
		printf("3. Salir\n");
		printf("R: ");
		scanf("%d",&op);
		switch (op) {
			case 1:
			break;

			case 2:
				printf("Ingrese el nombre del departamento: ");
				scanf("%s",dep);
				FILE *archivo; //creamos apuntador a archivo

				if( ( archivo = fopen(dep,"r") ) == NULL ) {//comprueba que haya un archivo con nombre archivo.txt que se pueda leer
					printf("Error al leer el archivo.\n");
					break;
				}
				else {
					int var=correrLogin();
					printf("%d\n",var);
					
					}
				fclose(archivo); 
			break;

			default:
				printf("Opcion incorrecta\n");
			break;
		}

	}while(op!=3);

	return 0;
}

int correrLogin() {
	char user[30];
	//char contra[30];
	printf("Ingrese el id del articulo: ");
	scanf(" %s",user);
	int tipo=tipoEmpleado(user);
	//printf("%d\n",tipo );
	return tipo;
}

int tipoEmpleado(char* user){
	int tipo;
	int lineaStrart=obtieneLinea(user);
	char* cad;
	return lineaStrart+1;
}


int obtieneLinea(char* idA){
	int i;
	static char nombre[30];
	int lines=0;
	FILE *fp; //creamos apuntador a archivo

	if( ( fp = fopen("depaPrueba.txt","r") ) == NULL )//comprueba que haya un archivo con nombre archivo.txt que se pueda leer
	printf("Error al leer el archivo.");

	else{
	while (!feof(fp)) {
		fscanf(fp, "%s\n", nombre);
		lines++;
		if(strcmp(nombre,idA) == 0) {
			fclose(fp);
			return lines-1;	
		}
	}
}
	fclose(fp); //cierra el archivo 
	return lines;
}
