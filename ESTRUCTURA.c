#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
	char filasenteras [1000]; 
} Datos ;

int main()
 {
 	int i,ncomas;
 	//int menu1, energia, energias;
 	setlocale(LC_CTYPE,"spanish");
 	
 	Datos filas[30];
 	FILE *datos;
 	if((datos = fopen("generacion_por_tecnologias_21_22.csv","r"))==NULL)
	{

	   printf("Se ha producido un error en la apertura del fichero de lectura");
	   return -1;
    } else printf("Se ha abierto el fichero correctamente\n");
    for(i=0;i<25;i++)//HASTA Y DESDE QUE FILA GUARDO
	{
	fgets(filas[i].filasenteras,sizeof(filas[i].filasenteras),datos);//fgets COJE SALTOS DE LINEA
																  
	filas[i].filasenteras[strlen(filas[i].filasenteras)-1]=','; //ASIGNO ';' EN ESA POSICION 
																//Y ELIMINO EL SALTO DE LINEA
	filas[i].filasenteras[strlen(filas[i].filasenteras)-0]='\0';	
																//CIERRO CADENA														
    }
    for(i=0;i<23;i++)
	{//HASTA Y DESDE QUE FILA IMPRIMO
	  	printf ("%s\n",filas[i].filasenteras);
    }
    for(ncomas=0,i=0;ncomas<2;i++)//AQUI DA FALLO	
    {
    	if(filas[i]  ==',')comas++;
			printf("este es i: %i  y este es numcomas: %i\n",i,ncomas); //asi vemos en que posicion esta i
	}

    
    
 /*	switch (menu1)
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
		}*/
 	
 	return 0;
 }
