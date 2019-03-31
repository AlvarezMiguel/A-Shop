#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Login.h"
#include "Empleados.h"

int main() {
	int i,op;
	int tipo;
	printf("*** BIENVENIDO A A-SHOP ***\n");
	printf("Iniciar sesion\n");
	tipo=correrLogin();
	if(tipo==0) {
		printf("Datos incorrectos\n");
	}
	else {
		funcionEmpleado(tipo);
	}
	
	return 0;
}
