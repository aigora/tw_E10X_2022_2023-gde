#include <stdio.h>
#include <stdlib.h>

int main()
 {
 	int menu1, energia;
 	printf ("Que quiere consultar?\n -Datos de una sola energia(1)\n -Datos de varias energias(2)\n");
 	scanf ("%c", &menu1);
 	switch (menu1)
 		{
 			case 1:
 			{
 				printf ("Introduzca la energia que quiere consultar.\n");
 				printf ("Hidraulica(1)\n");
 				printf ("Turbinacion bombeo(2)\n");
 				printf ("Nuclear(3)\n");
 				printf ("Carbon(4)\n");
 				printf ("Fuel y gas (5)\n");
 				printf ("Motores diesel(6)\n");
 				printf ("Turbina de gas(7)\n");
 				printf ("Turbina de vapor(8)\n");
 				printf ("Ciclo combinado(9)\n");
 				printf ("Hidroeolica(10)\n");
 				printf ("Eolica(11)\n");
 				printf ("Solar fotovoltaica(12)\n");
 				printf ("Solar termica(13)\n");
 				printf ("Otras renovables(14)\n");
 				printf ("Cogeneracion(15)\n");
 				printf ("Residuos no renovables(16)\n");
 				printf ("Residuos renovables(17)\n");
 				printf ("Generacion total(18)\n");
 				scanf ("%i", &energia);
 				break;
			}
		}
 	
 	return 0;
 }
