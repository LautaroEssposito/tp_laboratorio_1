/*
 * funcion.h
 *
 *  Created on: 7 abr. 2022
 *      Author: Lauti Esposito
 */

#ifndef FUNCION_H_
#define FUNCION_H_


/**
 * @brief Esta funcion se encarga de pedir laopcion del menu al usuario y esta validada entre 1 y 6
 *
 * @return opcion
 */
int PedirOpcionMenu(void);
//----------------------------------------------------------------------------------------------------------------
/**
 * @brief Esta funcion basicamente son \n con el proposito de separar texto
 *
 */
void Separador(void);
//----------------------------------------------------------------------------------------------------------------
/**
 * @brief Esta funcion basicamente son \t con el proposito de separar texto
 *
 */
void distanciador(void);
//----------------------------------------------------------------------------------------------------------------
/**
 * @brief Esta funcion pide el ingreso de un numero entero validado mayor a 0
 *
 * @param mensaje
 * @return numero
 */
int PedirNumerosInt(char mensaje[]);
//----------------------------------------------------------------------------------------------------------------
/**
 * @brief Esta funcion pide el ingreso de un numero flotante validado mayor a 0
 *
 * @param mensaje
 * @return numero
 */
float PedirNumerosFloat(char mensaje[]);
//----------------------------------------------------------------------------------------------------------------
/**
 * @brief Esta funcion le pide al usuario que ingrese los km y esta validado mayor a 0
 *
 * @param precioIngresado
 * @return numero
 */
int IngresarKm(int numero);
//----------------------------------------------------------------------------------------------------------------
/**
 * @brief Esta funcion calcula el precio del vuelo descontando un %10
 *
 * @param precioIngresado
 * @return precioIngresado
 */
float calcularTarjetaDebito(float precioIngresado);
//----------------------------------------------------------------------------------------------------------------
/**
 * @brief Esta funcion calcula el precio del vuelo agregando un %25
 *
 * @param precioIngresado
 * @return precioIngresado
 */
float calcularTarjetaCredito(float precioIngresado);
//----------------------------------------------------------------------------------------------------------------
/**
 * @brief Esta funcion calcula cuantos Bitcoin cuesta el vuelo
 *
 * @param precioIngresado
 * @return precioIngresado
 */
float calcularPrecioBitcoin(float precioIngresado);
//----------------------------------------------------------------------------------------------------------------
/**
 * @brief Esta funcion divide el precio del vuelo por los km y calcula cuanto cuesta cada km
 *
 * @param kmIngresado
 * @param precioIngresado
 * @return kmUnitario
 */
float calcularKmUnitario(int kmIngresado, float precioIngresado);
//----------------------------------------------------------------------------------------------------------------
/**
 * @brief Esta funcion calcula la diferencia de precio entre ambas aerolineas
 *
 * @param precioLatam
 * @param precioAero
 * @return precioFinal
 */
float diferenciarPrecio(float precioLatam, float precioAero);
//----------------------------------------------------------------------------------------------------------------
/**
 * @brief Esta funcion tiene ya hardcodeados los valores, los calcula y los muestra al usuario
 *
 * @param km
 * @param y
 * @param z
 */
void cargarForzadamente(int km, float y, float z);
//----------------------------------------------------------------------------------------------------------------
/**
 * @brief Esta funcion contiene todo el menu
 *
 */
void menu();

#endif /* FUNCION_H_ */
