#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void funciontipo(int [],int);

typedef struct {
	char filasenteras [1000]; 
} Datos ;

int main()
 {
 	int i,j;
 	int ncomas=0,nenergias=0,accion=0;
 	int energias [18];
 	int menu1, energia;
 	setlocale(LC_CTYPE,"spanish");
 	
 	Datos filas[30];
 	FILE *datos;
 	if((datos = fopen("generacion_por_tecnologias_21_22_puntos_simplificado.csv","r"))==NULL)
	{

	   printf("Se ha producido un error en la apertura del fichero de lectura");
	   return -1;
    } else printf("Se ha abierto el fichero correctamente\n");
    for(i=0;i<24;i++)//HASTA Y DESDE QUE FILA GUARDO
	{
	fgets(filas[i].filasenteras,sizeof(filas[i].filasenteras),datos);//fgets COJE SALTOS DE LINEA
																  
	filas[i].filasenteras[strlen(filas[i].filasenteras)-1]=','; //ASIGNO ',' EN ESA POSICION 
																//Y ELIMINO EL SALTO DE LINEA
	filas[i].filasenteras[strlen(filas[i].filasenteras)]='\0';	
																//CIERRO CADENA														
    }
    /*for(i=0;i<24;i++)
	{
	  	printf ("%s\n",filas[i].filasenteras);
    }*/
    
   
  /*  for(j=0;filas[0].filasenteras[j]!='\0';j++){
		  printf("%c",filas[0].filasenteras[j]);
    	
    	if (filas[0].filasenteras[j]==',') ncomas++;
    	//printf("%i",ncomas);
    //}	
	}
	printf("\n%i",ncomas);*/
	
	printf("Quiere consultar (0) o añadir datos (1)\n");//Control de datos
	scanf("%i",&accion);
	if (accion==0)
	{
		printf("¿Cuantas energías quiere consultar? (introduzca un entero positivo)\n");
    	scanf("%i",&nenergias);
    	
    printf ("Introduzca la energia/as que quiere consultar.\n");
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
 	
 	  for (i=0;i<nenergias;i++)//Control de datos
 	  {
 		scanf("%i",&energias[i]);
	  }
	printf("Que tipo de consulta quiere hacer\n");
	printf("Mostrar dato/s (1)\n"); 
	printf("Calcular media (2)");
	printf("Calcular moda (3)");
	printf("Tipo de energía(4)");
	 scanf("%i",&consulta);
	 switch (consulta)
	   {
	 	case 1:
	 		{
	 		//FUNCION DE MOSTRAR DATOS
	 		break;
			}
		case 2:
			{
			//FUNCION PARA CALCULAR MEDIA
			break;	
			}
		case 3:
			{
			//FUNCION PARA CALCULAR MODA
			break;
			}
		case 4:
			{
			//FUNCION PARA TIPO DE ENERGÍA
			funciontipo(energias,nenergias);
			break;
			}	
          }
        }
 	
 	return 0;
 }

void funciontipo(int numeros[], int nenergias) 
 {
 	
 	int k=0;
 	   
 	
    for (k=0; k<nenergias; k++){
		
		if (numeros[k] == 2 || numeros[k] == 3 || numeros[k] == 4 || numeros[k] == 5 || numeros[k] == 15 || numeros[k] == 16){
			
			printf("la energia numero %i: No es renobable\n", k+1);
			
		}else{
			
			printf("la energia numero %i: Es renovable\n", k+1);
		}
	}
 	
 
 
 }
