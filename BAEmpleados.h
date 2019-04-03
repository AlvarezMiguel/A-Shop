#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//#include "Login.h"

typedef struct Empleado {
	char nombre_empleado[32];
	char apellido[32];
	char usuario[32];
	char contrasena[32];
	char tipo_empleado[20];
	char  sueldo[20];
	struct Empleado* siguiente;
}Empleado;
Empleado* empleados_inicio = NULL;

int obti(char* nombreEmp);

void agregaEmpleado(){
	int finalarchivo;
	int opcion = 2;
	char nombre[10];
	do{
		Empleado empleado;
		FILE* archivo=fopen("empleados.txt","a+");

		printf("Nombre del empleado: ");
		scanf("%s",empleado.nombre_empleado);
		fprintf(archivo,"\n%s \n",empleado.nombre_empleado);
		//fputs(empleado.nombre_empleado,archivo);

		printf("Apellido del empleado: ");
		scanf("%s",empleado.apellido);
		fprintf(archivo,"%s \n",empleado.apellido);
		//fputs(empleado.apellido,archivo);

		printf("Usuario del empleado: ");
		scanf(" %s",empleado.usuario);
		fprintf(archivo,"%s \n",empleado.usuario);
		//fputs(empleado.usuario,archivo);

		printf("Contraseña del empleado: ");
		scanf(" %s",empleado.contrasena);
		fprintf(archivo,"%s \n",empleado.contrasena);
		//fputs(empleado.contrasena,archivo);

		printf("Tipo de empleado: ");
		scanf(" %s",empleado.tipo_empleado);
		fprintf(archivo,"%s \n",empleado.tipo_empleado);
		//fputs(empleado.tipo_empleado,archivo);

		printf("Sueldo del empleado: ");
		scanf("%s",empleado.sueldo);
		fprintf(archivo,"%s \n",empleado.sueldo);	
		//fputs(*empleado.sueldo,archivo);

		fseek(archivo,0,SEEK_END);
		finalarchivo = ftell(archivo);
		fclose(archivo);
		printf("Desea continuar(1)?\n");
		scanf("%d", &opcion);
		printf("\n");

	}while(opcion == 1 || opcion == 1);	
    printf("Se ha agregado al empleado\n");
}

void eliminaEmpleado()
{
        FILE *fptr1, *fptr2;
        int lno, linectr = 0;
        char str[100],fname[100];        
        char nombreel[100], temp[] = "temp.txt";

        fptr1 = fopen("empleados.txt", "r");
        if (!fptr1) 
        {
                printf("Ocurrio un error al abrir el archivo\n");      
        }
        fptr2 = fopen(temp, "w");
        if (!fptr2) 
        {
                printf("Error en archivo auxiliar");
                fclose(fptr1);
               
        }
        printf("Nombre del empleado a eliminar: ");
		
		scanf("%s",nombreel);
       
        lno = obti(nombreel);
		lno++;
        printf("Linea %d\n",lno);

        for(int i=0;i<100;i++){
			nombreel[i]='\0';
		}

        // copy all contents to the temporary file other except specific line
        while (!feof(fptr1)) 
        {
            strcpy(str, "\0");
            fgets(str, 100, fptr1);
            if(!feof(fptr1)) 
            {
                linectr++;
             
                if (linectr == lno ) 
                {
                	fprintf(fptr2, "%s", nombreel);
                }else if(linectr == lno+1){	
                	fprintf(fptr2, "%s",nombreel);
                }else if(linectr == lno+2){	
                	fprintf(fptr2, "%s",nombreel);
                }else if(linectr == lno+3){	
                	fprintf(fptr2, "%s",nombreel);
                }else if(linectr == lno+4){	
                	fprintf(fptr2, "%s",nombreel);
                }else if(linectr == lno+5){	
                	fprintf(fptr2, "%s",nombreel);
                }else{
                    fprintf(fptr2, "%s", str);
                }

           	}
        }
        fclose(fptr1);
        fclose(fptr2);
        remove("empleados.txt");
        rename(temp, "empleados.txt");
        printf(" Se ha eliminado al empleado \n");
 
}

int obti(char* nombreEmp){
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

