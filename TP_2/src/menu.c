#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "ArrayPassenger.h"

int menu()
{
	int opcion;
		printf("|---------------------|\n");
		printf("|1-ALTA PASAJERO      |\n");
		printf("|2-MODIFICAR PASAJERO |\n");
		printf("|3-BAJA PASAJERO      |\n");
		printf("|4-INFORMAR           |\n");
		printf("|5-ALTA FORZADA       |\n");
		printf("|6-SALIR              |\n");
		printf("Ingrese la opcion: ");
		scanf("%d", &opcion);
		while(opcion < 0 || opcion > 5)
		{
			printf("ERROR, Reingrese una opcion valida");
			scanf("%d", &opcion);
		}
		return opcion;
}
int hardcode(Passenger* list, int* id, int* contador)
{
    int ret = -1;
    Passenger eHarcodeo [] = {
        {0, "Lautaro", "Esposito", 134000, "RELZ", 2, 1, 0},
        {0, "Hugo", "Hernandez", 640000, "SAFS", 2, 2, 0},
        {0, "Ezequiel", "Esposito", 1330000, "DSAD", 3, 2, 0},
        {0, "Maria Eugenia", "Faller", 1890000, "BGJF", 2, 2, 0},
        {0, "Alan", "Lemes", 158888, "ADAW", 2, 1, 0},
        {0, "Patricia", "Mucha", 245000, "45FD", 3, 1, 0},
        {0, "Bruce", "Wayne", 110600, "Q24WR", 1, 1, 0},
        {0, "Adrian", "Jimenez", 115000, "WETW", 3, 2, 0},
        {0, "Alfred", "Wayne", 510000, "CEWF", 2, 2, 0},
        {0, "Andres", "Sanchez", 123000, "NOY", 1, 1, 0},
    };

    if(list != NULL && id != NULL)
    {
        for(int i=0; i < 10; i++)
        {
          list[i] = eHarcodeo[i];
          list[i].id = *id;
          *id = *id + 1;
          *contador = *contador +1;
        }
        ret = 0;
    }
    return ret;
}
