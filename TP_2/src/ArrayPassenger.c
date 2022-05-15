#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"


int initPassengers(Passenger* list, int len)
{
	int retorno = -1;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			list[i].id = -1;
			list[i].isEmpty = 1;
		}
		retorno = 0;
	}

	return retorno;
}
/*--------------------------------------------------------------*/
int addPassenger(Passenger* list, int len, int id, char name[],char
lastName[],float price,int typePassenger, char flycode[], int statusFlight)
{
	int retorno = -1;

	if(list != NULL && len > 0 && name != NULL && lastName != NULL && price > 0 && typePassenger > 0 && flycode != NULL && statusFlight > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 1)
			{
				list[i].id = id;
				strcpy(list[i].name, name);
				strcpy(list[i].lastName, lastName);
				list[i].price = price;
				list[i].typePassenger = typePassenger;
				strcpy(list[i].flycode, flycode);
				list[i].statusFlight = statusFlight;


				list[i].isEmpty = 0;// lo cambio a estado lleno para que no sobreescriba

				retorno = 0;

				break;
			}
		}
	}


	return retorno;
}
/*--------------------------------------------------------------*/
int findPassengerById(Passenger* list, int len,int id)
{
	int retorno = -1;

	if(list != NULL && len > 0 && id > -1)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].id == id && list[i].isEmpty==0)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}
/*--------------------------------------------------------------*/
int removePassenger(Passenger* list, int len, int id)
{
	int retorno = -1;

	if(list != NULL && len > 0 && id > -1)
		{
			for(int i = 0; i < len; i++)
			{
				if(list[i].id == id && list[i].isEmpty == 0)
				{
					list[i].isEmpty = 1;
					retorno = 0;
					break;
				}
			}
		}


	return retorno;
}
/*--------------------------------------------------------------*/
int sortPassengers(Passenger* list, int len, int order)
{
	 int retorno = -1;
	    Passenger auxPasajero;

	    if(list != NULL && len > 0 && order > -1 && order < 2)
	    {
			switch (order)
			{
	            case 1:
				for (int i = 0; i < len - 1; i++)
				{
					for (int j = i + 1; j < len; j++)
	                {

						if (list[i].isEmpty == 0 && list[j].isEmpty == 0)
	                    {

							if ((list[i].typePassenger == list[j].typePassenger && strcmp(list[i].lastName, list[j].lastName)== 1 )|| list[i].typePassenger > list[j].typePassenger)
	                        {
								auxPasajero = list[i];
								list[i] = list[j];
								list[j] = auxPasajero;
							}
						}
					}
				}
				retorno = 0;
				break;
	            case 0:
	                for (int i = 0; i < len - 1; i++)
	                {
	                    for (int j = i + 1; j < len; j++)
	                    {

	                        if (list[i].isEmpty == 0 && list[j].isEmpty == 0)
	                        {

	                            if ((list[i].typePassenger == list[j].typePassenger && strcmp(list[i].lastName, list[j].lastName)==-1)||list[i].typePassenger < list[j].typePassenger)
	                            {

	                            	auxPasajero = list[i];
	                                list[i] = list[j];
	                                list[j] = auxPasajero;
	                            }
	                        }
	                    }
	                }
				retorno = 0;
				break;
			}
		}
	    return retorno;
}
/*--------------------------------------------------------------*/
int printPassenger(Passenger* list, int length)
{
	int retorno = -1;
	char tipoPasajero[20];
	char estadoVuelo[20];
	if(list != NULL && length > 0 )
	{
		printf("|ID\t|   Name \t|   Last Name  \t|  Price\t|  Fly Code \t    | Type Passenger \t   |\t Status Flight      |\n");

		for(int i = 0; i < length; i++)
		{

			if(list[i].isEmpty == 0)
			{
				switch(list[i].typePassenger)
				{
				case 1:
					strcpy(tipoPasajero, "CLASE BAJA");
					break;
				case 2:
					strcpy(tipoPasajero, "CLASE MEDIA");
					break;
				case 3:
					strcpy(tipoPasajero, "CLASE ALTA");
					break;
				}
				switch(list[i].statusFlight)
				{
				case 1:
					strcpy(estadoVuelo, "ACTIVO");
					break;
				case 2:
					strcpy(estadoVuelo, "ATRASADO");
					break;
				}

				printf("| %4d  | %13s | %13s | %11.2f | %19s | %20s |  %20s  |\n",
				list[i].id, list[i].name, list[i].lastName, list[i].price, list[i].flycode, tipoPasajero, estadoVuelo);
			}

		}
	}
	return retorno;
}
/*--------------------------------------------------------------*/
int sortPassengersByCode(Passenger* list, int len, int order)
{
	 int retorno = -1;
	    Passenger auxPasajero;

	    if(list != NULL && len > 0 && order > -1 && order < 2)
	    {
			switch (order)
			{
	            case 1:
				for (int i = 0; i < len - 1; i++)
				{
					for (int j = i + 1; j < len; j++)
	                {

						if (list[i].isEmpty == 0 && list[j].isEmpty == 0)
	                    {

							if ((list[i].statusFlight == list[j].statusFlight && strcmp(list[i].flycode, list[j].flycode)== 1 )|| list[i].statusFlight > list[j].statusFlight)
	                        {
								auxPasajero = list[i];
								list[i] = list[j];
								list[j] = auxPasajero;
							}
						}
					}
				}
				retorno = 0;
				break;
	            case 0:
	                for (int i = 0; i < len - 1; i++)
	                {
	                    for (int j = i + 1; j < len; j++)
	                    {

	                        if (list[i].isEmpty == 0 && list[j].isEmpty == 0)
	                        {

	                            if ((list[i].statusFlight == list[j].statusFlight && strcmp(list[i].flycode, list[j].flycode)==-1)||list[i].statusFlight < list[j].statusFlight)
	                            {

	                            	auxPasajero = list[i];
	                                list[i] = list[j];
	                                list[j] = auxPasajero;
	                            }
	                        }
	                    }
	                }
				retorno = 0;
				break;
			}
		}
	    return retorno;
}
