/*
 * Funciones.h
 *
 *  Created on: 11 may. 2022
 *      Author: Lauti Esposito
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
/**
 * @brief pide datos de pasajeros y los da de alta
 *
 * @param list
 * @param len
 * @param id
 * @return -1 ERROR O OK
 */
int altaPasajeros(Passenger* list, int len, int *id);
/**
 * @brief pide los datos del pasajero a modificar y se los cambia
 *
 * @param list
 * @param len
 * @return -1 ERROR O OK
 */
int modificarPasajero(Passenger* list, int len);
/**
 * @brief pide los datos del pasajero a eliminar y lo elimina
 *
 * @param list
 * @param len
 * @return -1 ERROR O OK
 */
int eliminarPasajero(Passenger* list, int len);
/**
 * @brief Muestra el submenu
 *
 * @param list
 * @param len
 * @param opcion
 * @return -1 ERROR O OK
 */
int subMenu(Passenger* list, int len,int opcion);
/**
 * @brief se encarga de realizar los calculos para informarlos
 *
 * @param list
 * @param len
 * @param contador
 * @param promedio
 * @param suma
 * @return -1 ERROR O OK
 */
int Calculos(Passenger* list, int len, int* contador, float* promedio, float* suma);

#endif /* FUNCIONES_H_ */
