#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "AltaBajaDep.h"

void funcionEmpleado();
//void ventas();
//void compras();
void admin();

void funcionEmpleado(int tipo) {
	if(tipo==1) {
		//printf("AREA DE VENTAS\n");
		//ventas();
	}
	else if (tipo==2) {
		//printf("AREA DE COMPRAS\n");
		//compras();
	}
	else if (tipo==3) {
		admin();

	}
}

void admin() {
	int op;
	do {
		printf("\nADMINISTRADORES\n\n");
		printf("1. Dar de baja departamento\n");
		printf("2. Dar de alta departamento \n");
		printf("3. Modificar informacion de empleados\n");
		printf("4. Agregar empleado\n");
		printf("5. Eliminar empleado\n");
		printf("6. Salir\n");
		scanf("%d",&op);
		switch(op) {
			case 1:
				bajaDep();
			break;

			case 2:
				altaDep();
			break;

			case 3:

			break;

			case 4:

			break;

			case 5:

			break;

			default:
				printf("Opcion incorrecta\n");
			break;
		}
	}while(op!=6);
}