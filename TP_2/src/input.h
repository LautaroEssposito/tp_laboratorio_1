#ifndef INPUT_H_
#define INPUT_H_

/**
 * @brief Toma un entero, muestra un mensaje, uno de error y esta validada por min y max
 *
 * @param integer
 * @param message
 * @param messageMistake
 * @param min
 * @param max
 * @return -1 ERROR O OK
 */
int tomarEntero(int* integer, char* message, char* messageMistake, int min, int max);
/**
 * @brief Toma un flotante, muestra un mensaje, uno de error y esta validada por min y max
 *
 * @param number
 * @param message
 * @param messageMistake
 * @param min
 * @param max
 * @return -1 ERROR O OK
 */
int tomarFlotante(float* number, char* message, char* messageMistake, float min, float max);
/**
 * @brief  Toma una cadena con un mensaje, tira un mensaje de error y tiene un maximo de caracteres
 *
 * @param chain
 * @param message
 * @param messageMistake
 * @param max
 * @return -1 ERROR O OK
 */
int tomarString(char* chain, char* message, char* messageMistake, int max);

#endif
