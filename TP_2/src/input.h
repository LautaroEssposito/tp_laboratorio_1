#ifndef INPUT_H_
#define INPUT_H_

/**
 * @brief Su funcion es pedir la opcion del menu validada entre 1 y 5
 *
 * @return opcion
 */
int tomarEntero(int* integer, char* message, char* messageMistake, int min, int max);
/**
 * @brief Su funcion es validar un tipo de dato flotante
 *
 * @param mensaje
 * @param pResultado
 * @return -1 en caso de error y retorna 0 si esta bien
 */
int tomarFlotante(float* number, char* message, char* messageMistake, float min, float max);
/**
 * @brief Su funcion es validar un tipo de dato de caracteres
 *
 * @param mensaje
 * @param pResultado
 * @return -1 en caso de error y retorna 0 si esta bien
 */
int tomarString(char* chain, char* message, char* messageMistake, int max);

#endif
