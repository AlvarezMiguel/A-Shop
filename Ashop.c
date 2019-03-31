Ashop.c#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nombre[15];
    char apellido[15];
    char tipoEmpleado[15];
    char usuario[15];
    char contrasenio[15];
    char area[15];
    int sueldo;
}Empleado;

int main() {
	int i,op;
	do {
		printf("***MENU***\n");
		printf("1. Registrar empleado.\n");
		printf("2. Iniciar sesion\n");
		printf("3. Salir\n");
		printf("R: ");
		printf("Prueba...")
		scanf("%d",&op);
		switch (op) {
			case 1:
				printf("REGISTRAR EMPLEADO");
			break;
			case 2:
				
			break;
		}
	} while(op!=3);
	
	
	return 0;
}
