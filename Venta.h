#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char producto[10];
    int venta;
    char fecha[9];
}Ventas;


typedef struct{
    char idArticulo[20];
    char nombre[20];
    int cantidad;
    int precioCompra;
    int precioVenta;
    char depto[20];
}Producto;

void vender();
void mostrarArticulos();
char * recuperarCad(int linea);


void vender() {
	mostrarArticulos();
	
}

void mostrarArticulos() {
	char depar[30];
	char caracter;
	printf("De que departamento quieres comprar? R: ");
	scanf("%s",depar); //poner con extencion txt

	FILE *departamento;
	if( (departamento= fopen(depar,"r") ) == NULL ) {//abre archivo lectura, del archivo debe existir 
		printf("El departamento no existe");
	}
	else {
		char* cad;
		char* precio;
		int i,cont=3;
        printf("\nLos articulos del departamento son:\n\n");
        for(i=0;i<2;i++) {
        	cad=recuperarCad(cont);
        	printf("%s",cad);
        	precio=recuperarCad(cont+2);
       		printf("  $%s\n",precio);
       		cont=cont+5;
        }
       	

		fclose(departamento);
	}
}


char * recuperarCad(int linea){
	int i;
	static char nombre[30];
	int lines=0;
	FILE *fp; //creamos apuntador a archivo

	if( ( fp = fopen("Dulces.txt","r") ) == NULL )//comprueba que haya un archivo con nombre archivo.txt que se pueda leer
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

