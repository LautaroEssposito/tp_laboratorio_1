/*
 * Funciones.h
 *
 *  Created on: 11 may. 2022
 *      Author: Lauti Esposito
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

int altaPasajeros(Passenger* list, int len, int *id);
int modificarPasajero(Passenger* list, int len);
int eliminarPasajero(Passenger* list, int len);
int subMenu(Passenger* list, int len,int opcion);
int Calculos(Passenger* list, int len, int* contador, float* promedio, float* suma);

#endif /* FUNCIONES_H_ */
