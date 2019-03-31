#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	int linea,numarti, opcion,mascantidad, menoscantidad;
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

				if( ( archivo = fopen(dep,"r") ) == NULL )//comprueba que haya un archivo con nombre archivo.txt que se pueda leer
					printf("Error al leer el archivo.");
				else {
					printf("Ingrese el id del articulo: ");
					scanf(" %s",id);
				}
			break;

			default:
				printf("Opcion incorrecta\n");
			break;
		}

	}while(op!=3);

	return 0;
}