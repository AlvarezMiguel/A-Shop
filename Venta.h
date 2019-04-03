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

int num_lineas_archivo(char * nombredepa);

int main() {
	Producto product1, product2;
    Producto productos[] = {product1,product2};
	char compraArt[30];
	char cant[30],preArtic;
	int cantint;

	int lineaC;
	mostrarArticulos();
	printf("Que articulo quieres comprar? R: ");
	scanf("%s",compraArt);
	lineaC=obtiLinea(compraArt);
	//printf("%d",lineaC);
	preArtic=

	strcpy(productos[0].nombre,compraArt);
	printf("Cuantos quieres comprar? R: ");
	scanf("%s",cant);
	strcpy(productos[0].cantidad,cant);

	cantint=atoi(cant);



	recibo(productos);
	//De aqui modificamos el txt
	
	return 0;
}

void mostrarArticulos() {
	char depar[30];
	char caracter;

	printf("De que departamento quieres comprar? R: ");
	scanf("%s",depar); //poner con extencion txt

	char* cad;
	char* precio;
	int linea, noarticulos=0,totallineas;
    printf("\nLos articulos del departamento son:\n");

    totallineas=num_lineas_archivo(depar);
    for(linea=3;noarticulos<=(totallineas/6);linea) {
    	noarticulos ++;
    	printf("%d ",noarticulos );
   		cad=recuperarCad(linea,depar);
      	printf("%s",cad);
       	precio=recuperarCad(linea+3,depar);
    	printf("  $%s\n",precio);
    	linea=linea+5;
    }
}


char * recuperarCad(int linea,char depar[30]){
	int i;
	static char nombre[30];
	int lines=0;
	FILE *fp; //creamos apuntador a archivo

	if( ( fp = fopen(depar,"r") ) == NULL )//comprueba que haya un archivo con nombre archivo.txt que se pueda leer
	printf("Error al leer el archivo ");
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
	printf("Error al leer el archivo .");

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
    	fprintf (fp, "\tTienda A Shop Super Pro\n");
	    fprintf(fp, "\tAv. No se que #1001 Estado de México, México.\n");
	    //fprintf(fp,"Empleado: %s",);
	    fprintf(fp, "-------\n\tRECIBO DE COMPRA\n--------");
	    int j;
	    for(j = 0; j < 1; j++){

	    	//int productoCan = 2;
	    	//printf("%s\n",productos[0].nombre );
	        fprintf(fp, "%s $ , Cantidad:%s    Sub: \n",productos[j].nombre,productos[j].cantidad);
	    }
	    //fprintf(fp, "\n\t TOTAL : $%d\n",);
	    fprintf(fp, "\n\tAgradecemos su preferencia. Vuelva pronto\n");
    }
   	printf("Se ha generado tu recibo.");
    fclose(fp);

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