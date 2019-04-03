#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "AltaBajaDep.h"
#include "BAEmpleados.h"
#include "Venta.h"
#include "sueldo.h"
#include "ConsultaInven.h"

void funcionEmpleado();
void ventas();
void compras();
void admin();

void funcionEmpleado(int tipo) {
	if(tipo==1) {
		//printf("AREA DE VENTAS\n");
		ventas();
	}
	else if (tipo==2) {
		//printf("AREA DE COMPRAS\n");
		compras();
	}
	else if (tipo==3) {
		admin();

	}
}

void admin() {
	int op;
	do {
		printf("\nBIENVENIDO\nADMINISTRADORES\n\n");
		printf("1. Dar de baja departamento\n"); //listo
		printf("2. Dar de alta departamento \n"); //listo
		printf("3. Modificar informacion de empleados\n");
		printf("4. Agregar empleado\n"); //listo
		printf("5. Eliminar empleado\n");
		printf("6. Agregar articulo\n"); //listo
		printf("7. Eliminar articulo\n");
		printf("8. Gasto de la empresa en empleados\n"); //listo
		printf("9. Consultar inventario\n"); //nombre arti, cantidad
		printf("10. Salir\n");
		printf("R: ");
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
				agregaEmpleado();
			break;

			case 5:
				eliminaEmpleado();
			break;
			case 6:
			break;
			case 7:
			break;
			case 8:
				sueldo();
			break;
			case 9:
				consultaInven();
			break;
			default:
				printf("Opcion incorrecta\n");
			break;
		}
	}while(op!=10);
}


void ventas() {
	int op;
	printf("\nBIENVENIDO\nAREA DE VENTAS\n");
	printf("Venta de articulos\n");
	vender(); 
}

void compras() {
	printf("\nBIENVENIDO\nAREA DE COMPRAS\n");
	printf("Surtir articulos existentes\n");

}
