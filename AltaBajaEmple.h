#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Empleado {
	char nombre_empleado[30];
	char apellido[30];
	char usuario[30];
	char contrasena[30];
	char tipo_empleado[5];
	char  sueldo[30];
	struct Empleado* siguiente;
}Empleado;
Empleado* empleados_inicio = NULL;

void agregaEmpleado(){
	int finalarchivo;
	int opcion = 2;
	char nombre[10];
	do{
		Empleado empleado;
		FILE* archivo=fopen("empleados.txt","a+");

		printf("Nombre del empleado: ");
		scanf("%s",empleado.nombre_empleado);
		fprintf(archivo,"\n");
		fprintf(archivo,"%s \n",empleado.nombre_empleado);
		//fputs(empleado.nombre_empleado,archivo);

		printf("Apellido del empleado: ");
		scanf(" %s",empleado.apellido);
		fprintf(archivo,"%s \n",empleado.apellido);

		printf("Usuario del empleado: ");
		scanf(" %s",empleado.usuario);
		fprintf(archivo,"%s \n",empleado.usuario);
		//fputs(empleado.usuario,archivo);

		printf("Contraseña del empleado: \n");
		scanf(" %s",empleado.contrasena);
		fprintf(archivo,"%s \n",empleado.contrasena);
		//fputs(empleado.contrasena,archivo);

		printf("Tipo de empleado: ");
		scanf(" %s",empleado.tipo_empleado);
		fprintf(archivo,"%s \n",empleado.tipo_empleado);
		//fputs(empleado.tipo_empleado,archivo);

		printf("Sueldo del empleado: ");
		scanf("%s",empleado.sueldo);
		fprintf(archivo,"%s\n",empleado.sueldo);	
		//fputs(*empleado.sueldo,archivo);

		fseek(archivo,0,SEEK_END);
		finalarchivo = ftell(archivo);
		fclose(archivo);
		printf("Desea continuar(1)?\n");
		scanf("%d", &opcion);
		printf("\n");

	}while(opcion == 1 || opcion == 1);
	
	
}

void eliminaEmpleado(){
	FILE *archivo, *archivoAux;
        Empleado empleado;
        archivoAux=fopen("empleadosAux.txt","rb");
        archivo =fopen("empleados.txt","a+");

        if(!archivo){
            printf("Vacio\n");
        }
        else{

    	    char nombre_empleado[20];
            printf("Nombre a eliminar:\n");
            //fgets(nombre_empleado, 20, archivo);
            scanf("%c",nombre_empleado);
            //Recibe los mismo parametros que fwrite
           while(fread(&empleado, sizeof(Empleado),1, archivo)){

            if (!strcmp(empleado.nombre_empleado,nombre_empleado))
                fwrite(&empleado, sizeof(Empleado),1, archivoAux);
            }
            archivoAux=fopen("empleadosAux.txt","rb");
            archivo=fopen("empleados.txt","a+");
            while(fread(&empleado, sizeof(Empleado),1, archivoAux)){

                fwrite(&empleado, sizeof(Empleado),1, archivo);
            }
        }
        fclose(archivo);
        fclose(archivoAux);

        if(remove("archivoAux.txt") == 0){
        	printf("Borrado exitosamente\n");
        }
}