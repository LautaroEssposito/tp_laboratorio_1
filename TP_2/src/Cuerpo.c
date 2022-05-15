#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include "input.h"
#include "Funciones.h"
#include "menu.h"

#define SIZEPASSENGER 2000

int Cuerpo(void)
{

	setbuf(stdout, NULL);

	Passenger ArrayPasajero[SIZEPASSENGER];
	int id;
	int contPasajero = 0;
	int opcionMenu;
	int opcion;
	int flag;

	initPassengers(ArrayPasajero, SIZEPASSENGER);

	do
	{
			opcionMenu = menu();
			switch(opcionMenu)
			{

			case 1:
				if(contPasajero < SIZEPASSENGER)
				{
					altaPasajeros(ArrayPasajero, SIZEPASSENGER, &id);
					contPasajero++;
					system("pause");
				}
				else
					{
						printf("\nYa se cargaron 2000 pasajeros. No hay mas lugar!");
					}

				break;

			case 2:
				if(contPasajero > SIZEPASSENGER)
				{
					modificarPasajero(ArrayPasajero,SIZEPASSENGER);
				}
				else
					{
						printf("\nNO HAY PASAJEROS\n");
					}
				break;
			case 3:
				if(contPasajero > 0)
				{
					flag = eliminarPasajero(ArrayPasajero, SIZEPASSENGER);
					if(flag == 0)
					{
						contPasajero--;
					}
				}
				else
				{
					printf("\nNO HAY PASAJEROS\n");
				}

				break;
			case 4:
				if(contPasajero > 0)
				{
					tomarEntero(&opcion, "\n1.ORDENAR POR APELLIDO Y TIPO DE PASAJERO\n2.INFORMAR CALCULOS\n3.ORDENAR POR ESTADO DE VUELO Y CODIGO DE VUELO\nIngrese la opcion: ", "\nReingre una opcion valida: ", 1,3);
					subMenu(ArrayPasajero, SIZEPASSENGER,opcion);
				}
				else
				{
					printf("\nNO SE CARGARON PASAJEROS\n");
				}
				break;
			case 5:
				hardcode(ArrayPasajero,&id, &contPasajero);
				printPassenger(ArrayPasajero, SIZEPASSENGER);
				break;

	}


		}while(opcionMenu !=6);

	return EXIT_SUCCESS;
}


