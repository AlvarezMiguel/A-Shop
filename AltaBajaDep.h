#include <stdio.h>
#include <stdlib.h>

void altaDep();
void bajaDep();
void almacenar(char* cadena); //Funcion para almacenar una cadena

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


void almacenar(char* cadena) {
	setbuf(stdin, NULL);
	scanf("%[^\n]",cadena);
	getchar(); 	
}
