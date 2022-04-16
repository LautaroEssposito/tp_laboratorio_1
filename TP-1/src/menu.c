/*
 * menu.c
 *
 *  Created on: 12 abr. 2022
 *      Author: Lauti Esposito
 */
#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"
void menu()
{

	    setbuf(stdout, NULL);

		int opcionMenu;
		int km = 0;
		float z = 0;
		float y = 0;
		float precioDebitoLatam;
		float precioDebitoAerolinea;
		float precioCreditoLatam;
		float precioCreditoAerolinea;
		float precioBTCLatam;
		float precioBTCAero;
		float kmUnitarioLatam;
		float kmUnitarioAero;
		float diferenciaPrecio;
		int flag = 0;

		do
		{

		Separador();
		printf("Bienvenido/a a Aeropuerto Argentino Online!!\n");
		Separador();
		printf("1)Ingresar KM(km = %d):", km);
		printf("\n2)Ingresar Precio de Vuelos(Aerolíneas = %.2f, Latam = %.2f):", y, z);
		printf("\n3) Calcular todos los costos: ");
		printf("\n4) Informar resultados: ");
		printf("\n5) Carga forzada de datos: ");
		printf("\n6) Salir: \n");
		Separador();
		opcionMenu = PedirOpcionMenu();
		switch(opcionMenu)
		{
		case 1:
			km = IngresarKm(km);
			flag = 1;
			break;

		case 2:
			if(flag == 1)
			{
				z = PedirNumerosFloat("\nIngrese el precio del vuelo Latam(Mayor a $0): ");
				y = PedirNumerosFloat("\nIngrese el precio del vuelo Aerolinea(Mayor a $0): ");
				flag = 2;
			}
			else
			{
				printf("\n\nPor favor debe ingresar los Km antes: \n\n");
			   }
			break;

		case 3:
			if(flag == 2)
			{
				precioDebitoAerolinea = calcularTarjetaDebito(y);
				precioDebitoLatam = calcularTarjetaDebito(z);
				precioCreditoAerolinea = calcularTarjetaCredito(y);
				precioCreditoLatam = calcularTarjetaCredito(z);
				precioBTCLatam = calcularPrecioBitcoin(z);
				precioBTCAero = calcularPrecioBitcoin(y);
				kmUnitarioAero = calcularKmUnitario(km,y);
				kmUnitarioLatam = calcularKmUnitario(km,z);
				diferenciaPrecio = diferenciarPrecio(y,z);
				flag = 3;
			}
			else
			{
				printf("\n\nDebe ingresar los precios de ambas aerolineas: \n\n");
			}
				break;

		case 4:
			if(flag == 3)
			{
				printf("\n\n\tKm ingresados: %d\n\n", km);
				printf("\n\tEl precio ingresado de Aerolineas es: $%.2f\n",y);
				printf("\n\t\ta)Precio con tarjeta de debito Aerolinea: $%.2f", precioDebitoAerolinea);
				printf("\n\t\tb)Precio con tarjeta de credito Aerolinea: $%.2f", precioCreditoAerolinea);
				printf("\n\t\tc)Precio en BTC para Aerolineas es: %.7f ", precioBTCAero);
				printf("\n\t\td)Precio unitario por kilometro de Aerolinea es: $%.2f\n", kmUnitarioAero);
				printf("\n\tEl precio ingresado de Latam es: $%.2f\n",z);
				printf("\n\t\ta)Precio con tarjeta de debito Latam: $%.2f", precioDebitoLatam);
				printf("\n\t\tb)Precio con tarjeta de credito Latam: $%.2f", precioCreditoLatam);
				printf("\n\t\tc)Precio en BTC para Latam es: %.7f ", precioBTCLatam);
				printf("\n\t\td)Precio unitario por kilometro de Latam es: $%.2f\n\n", kmUnitarioLatam);
				printf("\t\tLa diferencia de precio entre ambas aerolineas es: $%.2f\n\n\n", diferenciaPrecio);
			}
			else
			{
				printf("\n\nDebe ingresar los datos de km y precio para seleccionar esta opcion:\n\n");
			}
			system("pause");
			break;

		case 5:
			km = 7090;
			z = 159339;
			y = 162965;
			cargarForzadamente(km, y, z);
			break;
		}


	}while(opcionMenu != 6);

	printf("\nHa salido con exito!");
}
