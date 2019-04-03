#include <stdio.h>
#include <stdlib.h>

void altaDep();
void bajaDep();
void almacenar(char* cadena); //Funcion para almacenar una cadena
void agregarArti();
void agregarArti2();

void altaDep() {
	int i,op2,numArti;
	
	char nombreDep[30]; //Aqui almacenamos el nombre que va a tener nuestro archivo 
	char cadena1[30];
 	char *cadena;
 	cadena=cadena1;

	FILE *nuevoDepa;
	printf("\nSe va a crear un departamento\n");
	printf("Nombre del departamento: "); //se tiene que poner el nombre del depa con txt -> nuevoDepa.txt
	scanf("%s",nombreDep); 
	nuevoDepa = fopen ( nombreDep, "w+" );
	printf("Cuandos articulos quieres agregar? ");
	scanf("%d",&numArti);
	for(i=0; i<numArti;i++) {
		printf("\nidArticulo #%d: ",i+1);
		almacenar(cadena); //mandamos a llamar a la funcion "almacenar" para almacenar la cadena
		fputs( cadena, nuevoDepa );	//escribirmos en el archivo lo que almacenamos en "cadena"
		fputc('\n', nuevoDepa); //Da un salto de linea en el archivo
		printf("Nombre del articulo #%d: ",i+1);
		almacenar(cadena);
		fputs( cadena, nuevoDepa );
		fputc('\n', nuevoDepa); 
		printf("Cantidad de articulos disponibles #%d: ",i+1);
		almacenar(cadena);
		fputs( cadena, nuevoDepa );
		fputc('\n', nuevoDepa); 
		printf("Precio venta #%d: ",i+1);
		almacenar(cadena);
		fputs( cadena, nuevoDepa );
		fputc('\n', nuevoDepa); 
		printf("Precio compra #%d: ",i+1);
		almacenar(cadena);
		fputs( cadena, nuevoDepa );
		fputc('\n', nuevoDepa); //Damos dobre salto de linea para que empiece a escribir el siguiente artículo con una separación 
		fputc('\n', nuevoDepa); 		
	}
	printf("Se ha creado el departamento de manera correcta.\n");			
	fclose(nuevoDepa); //cerramos el archivo 	
}

void bajaDep() {
	char depap[20];

 	printf("Que departamento quieres dar de baja? R: ");
	scanf("%s",depap); //Se tiene que escribir todo el nombre del archivo, ejem -> departamento1.txt
	if(remove(depap)==0) { // Eliminamos el archivo
        printf("El archivo fue eliminado satisfactoriamente\n");
    }
   	else {
    	printf("No se pudo eliminar el archivo\n");
	}
}



void agregarArti() {
	int i,op2,numArti;
	
	char nombreDep[30]; //Aqui almacenamos el nombre que va a tener nuestro archivo 
	char cadena1[30];
 	char *cadena;
 	cadena=cadena1;

	FILE *fp;
	printf("\nSe va a agregar un nuevo articulo\n");
	printf("Nombre del departamento: "); //se tiene que poner el nombre del depa con txt -> nuevoDepa.txt
	scanf("%s",nombreDep); 

	if( ( fp = fopen(nombreDep,"r+") ) == NULL )//comprueba que haya un archivo con nombre archivo.txt que se pueda leer
		printf("Error al leer el archivo.");
	
	else {
		printf("Cuandos articulos quieres agregar? ");
		scanf("%d",&numArti);
		for(i=0; i<numArti;i++) {
			printf("\nidArticulo #%d: ",i+1);
			almacenar(cadena); //mandamos a llamar a la funcion "almacenar" para almacenar la cadena
			fputs( cadena, fp );	//escribirmos en el archivo lo que almacenamos en "cadena"
			fputc('\n', fp); //Da un salto de linea en el archivo
			printf("Nombre del articulo #%d: ",i+1);
			almacenar(cadena);
			fputs( cadena, fp );
			fputc('\n', fp); 
			printf("Cantidad de articulos disponibles #%d: ",i+1);
			almacenar(cadena);
			fputs( cadena, fp );
			fputc('\n', fp); 
			printf("Precio venta #%d: ",i+1);
			almacenar(cadena);
			fputs( cadena,fp );
			fputc('\n', fp); 
			printf("Precio compra #%d: ",i+1);
			almacenar(cadena);
			fputs( cadena,fp );
			fputc('\n',fp); //Damos dobre salto de linea para que empiece a escribir el siguiente artículo con una separación 
			fputc('\n', fp); 		
		}
	}
	printf("\nSe ha agregado el producto.\n");			
	fclose(fp); //cerramos el archivo 	
}

void agregarArti2(){
	int finalarchivo;
	char cadena[30];
	int opcion = 2;
	char nombreDep[10];
	FILE* archivo;

	do{
		
		printf("\nSe va a agregar un nuevo articulo\n");
		printf("Nombre del departamento: "); //se tiene que poner el nombre del depa con txt -> nuevoDepa.txt
		scanf("%s",nombreDep); 
		if( ( archivo = fopen(nombreDep,"r+") ) == NULL )//comprueba que haya un archivo con nombre archivo.txt que se pueda leer
			printf("Error al leer el archivo.");
	
		else {

			printf("id del articulo: ");
			scanf("%s",cadena);
			fprintf(archivo,"\n%s \n",cadena);

			printf("Nombre del articulo: ");
			scanf("%s",cadena);
			fprintf(archivo,"%s \n",cadena);

			printf("Cantidad de produtos: ");
			scanf(" %s",cadena);
			fprintf(archivo,"%s \n",cadena);

			printf("Precio compra: ");
			scanf(" %s",cadena);
			fprintf(archivo,"%s \n",cadena);

			printf("Precio venta: ");
			scanf(" %s",cadena);
			fprintf(archivo,"%s \n",cadena);

			fseek(archivo,0,SEEK_END);
			finalarchivo = ftell(archivo);
			fclose(archivo);
			printf("Desea continuar(Si-1) (No-2)?\n");
			scanf("%d", &opcion);
			printf("\n");

		}
	    
	}while(opcion == 1 || opcion == 1);	
	printf("\nSe a agregado el producto\n");
}

void almacenar(char* cadena) {
	setbuf(stdin, NULL);
	scanf("%[^\n]",cadena);
	getchar(); 	
}
