#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "Funciones.h"
#include "input.h"
#include <ctype.h>

#define ORDEND 0
#define ORDENA 1
int altaPasajeros(Passenger* list, int len, int *id)
{
	int ret = -1;

	char nombre[51];
	char apellido[51];
	float precio;
	int tipoPasajero;
	char codigoVuelo[10];
	int estadoVuelo;


	if(list != NULL && len > 0 && id != NULL)
	{

		tomarString(nombre, "\nEl nombre es: ","\nReingrese un nombre valido: " , 51 );
		tomarString(apellido,"\nEl apellido es: ","\nReingrese un apellido valido: " , 51 );
		tomarFlotante(&precio, "\nEl  precio es: ", "\nReingrese un precio valido: ", 50000, 2000000);
		tomarEntero(&tipoPasajero, "\n1-CLASE BAJA\n2-CLASE MEDIA\n3-CLASE ALTA\nEl  tipo de pasajero es: ", "\nReingrese un tipo de pasajero valido: ", 1, 3);
		tomarString(codigoVuelo, "\nEl  codigo de vuelo es: ", "\nReingrese el codigo de vuelo: ", 10);
		tomarEntero(&estadoVuelo, "\n1-ACTIVO\n2-ATRASADO\nEl  estado de vuelo es: ", "\nReingrese un estado de vuelo valido: ", 1, 2);

		addPassenger(list,
						len,
						*id,
						nombre,
						apellido,
						precio,
						tipoPasajero,
						codigoVuelo,
						estadoVuelo);

			*id = *id + 1;

			printf("Se cargo correctamente el usuario!\n");

			ret = 0;
	}

	return ret;
}

int modificarPasajero(Passenger* list, int len)
{
	int ret = -1;
	int id;
	int aux;
	int mod;
	Passenger ModPasajero;

	if(list != NULL && len > 0)
	{
		printPassenger(list, len);

		printf("\nIngrese el ID que desea modificar: ");
		scanf("%d", &id);

		aux = findPassengerById(list, len, id);

		if(aux > -1)
		{
			tomarEntero(&mod, "\n1)Modificarnombre\n2)Modificar apellido\n3)Modificar precio\n4)Modificar Tipo de pasajero\n5)Modificar Codigo de vuelo\nIngrese opcion: ","\nReingre la opcion: " ,1,5);
			ModPasajero = list[aux];
			switch(mod)
			{
			case 1:
				tomarString(ModPasajero.name, "\nEl nuevo nombre es: ","\nReingrese un nombre valido: " , 51 );
				break;

			case 2:
				tomarString(ModPasajero.lastName,"\nEl nuevo apellido es: ","\nReingrese un apellido valido: " , 51 );
				break;

			case 3:
				tomarFlotante(&ModPasajero.price, "\nEl nuevo precio es: ", "\nReingrese un precio valido: ", 50000, 2000000);
				break;
			case 4:
				tomarEntero(&ModPasajero.typePassenger, "\nEl nuevo tipo de pasajero es: ", "\nReingrese un tipo de pasajero valido: ", 1, 3);
				break;
			case 5:
				tomarString(ModPasajero.flycode, "\nEl nuevo codigo de vuelo es: ", "\nReingrese el codigo de vuelo: ", 10);
				break;

			}
				list[aux] = ModPasajero;
				ret = 0;
		}
			else
			{
				printf("No se ha encontrado ningun pasajero a modificar!\n");
			}

	}
	return ret;
}
int eliminarPasajero(Passenger* list, int len)
{
	int ret = -1;
	int id;
	int aux;
	if(list != NULL && len > 0)
	{
		printPassenger(list, len);
		printf("\nIngrese el ID que desea eliminar: ");
		scanf("%d", &id);
		aux = removePassenger(list, len, id);

		if(aux == 0)
		{
			printf("\nPASAJERO ELIMINADO\n");
			ret = 0;
		}
		else
		{
			printf("\nNO SE ENCONTRO EL PASAJERO\n");
		}


	}

	return ret;
}
int subMenu(Passenger* list, int len,int opcion)
{
	int retorno = -1;
	int opcion1;
	int contador = 0;
	float suma = 0;
	float promedio;
	if(list!= NULL && len > 0)
	{
		switch(opcion)
		{
		case 1:
			tomarEntero(&opcion1, "\n1.Ascendente\n2.Descendente\nOpcion: ", "Reingrese una opcion valida: ", 1, 2);
			switch(opcion1)
			{
				case 1:
					sortPassengers(list, len, ORDENA);
					printPassenger(list, len);
				break;
				case 2:
					sortPassengers(list, len, ORDEND);
					printPassenger(list, len);
					break;
			}
			break;
		case 2:
			Calculos(list, len, &contador, &promedio, &suma);
			printf("El total es:%.2f\n",suma);
			printf("El promedio es:%.2f\n",promedio);
			printf("La cantidad de pasajeros que superan el promedio son :%d\n",contador);

			break;
		case 3:
			tomarEntero(&opcion1, "\n1.Ascendente\n2.Descendente\nOpcion: ", "Reingrese una opcion valida: ", 1, 2);
			switch(opcion1)
			{
				case 1:
					sortPassengersByCode(list, len, ORDENA);
					printPassenger(list, len);
				break;
				case 2:
					sortPassengersByCode(list, len, ORDEND);
					printPassenger(list, len);
					break;
			}
			break;
		}
	}

	return retorno;
}
int Calculos(Passenger* list, int len, int* contador, float* promedio, float* suma)
{
		int retorno = -1;
		int contadorP = 0;
		float sumaF = 0;
		int contadorF = 0;
		float promedioF = 0;

		if(list  != NULL && len > 0)
		{
			for(int i = 0;i<len;i++)
			{
				if(list[i].isEmpty == 0)
				{
					sumaF += list[i].price;
					contadorP++;
				}
			}

			promedioF = sumaF / contadorP;

			for(int i = 0; i<len;i++)
			{
				if(list[i].isEmpty == 0 && list[i].price > promedioF)
				{
					contadorF = contadorF +1;
				}
			}
			*promedio = promedioF;
			*suma = sumaF;
			*contador = contadorF;
			retorno = 0;
		}
		return retorno;
}
