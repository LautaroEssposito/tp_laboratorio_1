/*
 * menu.h
 *
 *  Created on: 14 may. 2022
 *      Author: Lauti Esposito
 */

#ifndef MENU_H_
#define MENU_H_
#include "ArrayPassenger.h"
/**
 * @brief Esta funcion contiene el menu
 *
 * @return opcion
 */
int menu();
/**
 * @brief Hardcodea los datos
 *
 * @param list
 * @param id
 * @param contador
 * @return -1 ERROR O OK
 */
int hardcode(Passenger* list, int* id, int* contador);

#endif /* MENU_H_ */
