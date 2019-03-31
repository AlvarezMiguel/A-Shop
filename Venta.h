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
char * recuperarCad(int linea,char depar[30]);


void vender() {
	char compraArt[30];
	int cant;
	mostrarArticulos();
	printf("Que articulo quieres comprar? R: ");
	scanf("%s",compraArt);
	printf("Cuantos quieres comprar? R: ");
	scanf("%d",&cant);
	//De aqui modificamos el txt
	
}

void mostrarArticulos() {
	char depar[30];
	char caracter;
	printf("De que departamento quieres comprar? R: ");
	scanf("%s",depar); //poner con extencion txt

	char* cad;
	char* precio;
	int i,cont=3;
    printf("\nLos articulos del departamento son:\n");
    for(i=0;i<2;i++) {
   		cad=recuperarCad(cont,depar);
      	printf("%s",cad);
       	precio=recuperarCad(cont+2,depar);
    	printf("  $%s\n",precio);
    	cont=cont+5;
    }
}


char * recuperarCad(int linea,char depar[30]){
	int i;
	static char nombre[30];
	int lines=0;
	FILE *fp; //creamos apuntador a archivo

	if( ( fp = fopen(depar,"r") ) == NULL )//comprueba que haya un archivo con nombre archivo.txt que se pueda leer
	printf("Error al leer el archivo.");
	else{
		while (!feof(fp)) {
			fscanf(fp, "%s\n", nombre);
			lines++;
			if(lines==linea-1) {
				//fclose(departamento);
				return nombre;	
			}
		}
	}
	fclose(fp); //cierra el archivo 
	//printf("%s\n",nombre );
	//printf("sdsd\n");
	return nombre;
}

