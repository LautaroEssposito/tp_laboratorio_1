#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"
#define BITCOIN	 4606954.55


int PedirOpcionMenu(void)
{
	int opcion = 0;

	printf("\nIngrese la opcion elegida: ");
	fflush(stdin);
	scanf("%d", &opcion);
	while(opcion < 1 || opcion > 6)
	{
		printf("\nError. Ingrese la opcion elegida nuevamente: ");
		fflush(stdin);
		scanf("%d", &opcion);
	}
	return opcion;
}
void Separador(void)
{
	printf("-------------------------------------------\n");
}
//-------------------------------------------------------------------------------------------------------------------------------------------------
void distanciador(void)
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");

}
//-------------------------------------------------------------------------------------------------------------------------------------------------
int PedirNumerosInt(char mensaje[])
{
	int numero;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%d", &numero);


	while(numero < 1 )
	{
	printf("\nError. Ingrese kilometros: ");
	fflush(stdin);
	scanf("%d", &numero);

	}

	return numero;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------
float PedirNumerosFloat(char mensaje[])
{
	float numero;

	printf("%s", mensaje);
	scanf("%f", &numero);
	fflush(stdin);

	while(numero < 1 )
	{
		printf("\nError. Ingrese el precio nuevamente(Mayor a $0): ");
		//fflush(stdin);
		scanf("%f", &numero);
	}
	return numero;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------
int IngresarKm(int numero)
{
	numero = PedirNumerosInt("\nIngrese los kilometros a recorrer(Mayor a 0): ");
	return numero;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------
 float calcularTarjetaDebito(float precioIngresado)
 {
	 float descuento;
	 descuento = precioIngresado * .1 ;
	 precioIngresado = precioIngresado - descuento;
	 return precioIngresado;
 }
//-------------------------------------------------------------------------------------------------------------------------------------------------
 float calcularTarjetaCredito(float precioIngresado)
  {
 	 float interes;
 	 interes = precioIngresado * .25 ;
 	 precioIngresado = precioIngresado + interes;
 	 return precioIngresado;
  }
//-------------------------------------------------------------------------------------------------------------------------------------------------
 float calcularPrecioBitcoin(float precioIngresado)
 {
	 precioIngresado = precioIngresado / BITCOIN;
	 return precioIngresado;
 }
//-------------------------------------------------------------------------------------------------------------------------------------------------
 float calcularKmUnitario(int kmIngresado, float precioIngresado)
 {
	 float kmUnitario;
	 kmUnitario = precioIngresado / (float)kmIngresado;
	 return kmUnitario;
 }
//-------------------------------------------------------------------------------------------------------------------------------------------------
float diferenciarPrecio(float precioLatam, float precioAero)
{
	float precioFinal;

	if(precioLatam > precioAero)
	{
		precioFinal = precioLatam - precioAero;
	}
	else
	{
		precioFinal = precioAero - precioLatam;
	}
	return precioFinal;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------
void cargarForzadamente(int km, float y, float z)
{
	float precioDebitoLatam;
	float precioDebitoAerolinea;
	float precioCreditoLatam;
	float precioCreditoAerolinea;
	float precioBTCLatam;
	float precioBTCAero;
	float kmUnitarioLatam;
	float kmUnitarioAero;
	float diferenciaPrecio;

	precioDebitoAerolinea = calcularTarjetaDebito(y);
	precioDebitoLatam = calcularTarjetaDebito(z);
	precioCreditoAerolinea = calcularTarjetaCredito(y);
	precioCreditoLatam = calcularTarjetaCredito(z);
	precioBTCLatam = calcularPrecioBitcoin(z);
	precioBTCAero = calcularPrecioBitcoin(y);
	kmUnitarioAero = calcularKmUnitario(km,y);
	kmUnitarioLatam = calcularKmUnitario(km,z);
	diferenciaPrecio = diferenciarPrecio(y,z);

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
	printf("\t\tLa diferencia de precio entre ambas aerolineas es: $%.2f\n", diferenciaPrecio);
}
//-------------------------------------------------------------------------------------------------------------------------------------------------
