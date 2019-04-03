#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>


typedef struct{
    char nombre[30];
    char cantidad[30];
    char precio[30];
}Producto;

void vender();
void mostrarArticulos();
char * recuperarCad(int linea,char depar[30]);
void recibo(Producto productos[2]);
int obtiLinea(char* nombreEmp);


void vender() {
	Producto product1, product2;
    Producto productos[] = {product1,product2};
	char compraArt[30];
	char cant[30];
	int cantint;

	int lineaC;
	mostrarArticulos();
	printf("Que articulo quieres comprar? R: ");
	scanf("%s",compraArt);
	lineaC=obtiLinea(compraArt);
	printf("%d",lineaC);

	strcpy(productos[0].nombre,compraArt);
	printf("Cuantos quieres comprar? R: ");
	scanf("%s",cant);
	strcpy(productos[0].cantidad,cant);

	cantint=atoi(cant);



	recibo(productos);
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

int obtiLinea(char* nombreEmp){
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
	//fclose(fp); //cierra el archivo 
	return lines;
}

void recibo(Producto productos[2]) {
	FILE *fp;
    //system("touch recibo.txt");
    fp = fopen ("recibo.txt", "wr" );
    if (fp==NULL) {
        fputs ("Error al generar el recibo",stderr);
    }
    else {
    	fprintf (fp, "\tTienda A Shop Retail\n");
	    fprintf(fp, "\tAv. Proteco #33, Av. Tabasco 2000, Villahermosa, Tabasco.\n");
	    //fprintf(fp,"Empleado: %s",);
	    fprintf(fp, "---------------\n\tRECIBO DE COMPRA\n---------------");
	    int j;
	    for(j = 0; j < 1; j++){

	    	//int productoCan = 2;
	    	//printf("%s\n",productos[0].nombre );
	        fprintf(fp, "%s $ , Cantidad:%s    Sub: \n",productos[j].nombre,productos[j].cantidad);
	    }
	    //fprintf(fp, "\n\t TOTAL : $%d\n",);
	    fprintf(fp, "\n\tA SHOP agradece su preferencia\n");
    }
   	printf("Se ha generado tu recibo.");
    fclose(fp);

}

