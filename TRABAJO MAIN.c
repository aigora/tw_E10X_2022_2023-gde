#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>




typedef struct {
	char filasenteras [1000]; 
} Datos ;

void funciontipo(int [],int);
void funcionmoda(int energias[], Datos filas[30], int nenergias);
float calculomoda(float datos_convertidos[][40], int nenergias);
void funcionmostrar(int[],int,Datos filas [30]);

int main()
 {
 	int i,j;
 	int nenergias=0,accion=0;
 	int energias [18];
 	int menu1, energia, consulta;
	char filanueva[1000];
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
 while (1) {
	printf("Quiere consultar (0) o añadir datos (1)\n");//Control de datos
	scanf("%i",&accion);
	
	if (accion==0)
	{
		do{
			printf("¿Cuantas energías quiere consultar? (introduzca un entero positivo)\n");
			scanf("%i",&nenergias);
		if (nenergias < 1 || nenergias > 18) {
			printf("Número inválido. Por favor, intentelo de nuevo.\n");
		}
		} while (nenergias < 1 || nenergias > 18);
    	
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
		
	do{	
	printf("Que tipo de consulta quiere hacer\n");
	printf("Mostrar dato/s (1)\n"); 
	printf("Calcular media (2)\n");
	printf("Calcular moda (3)\n");
	printf("Tipo de energía(4)\n");
	 scanf("%i",&consulta);
	 switch (consulta)
	   {
	 	case 1:
	 		{
	 		//FUNCION DE MOSTRAR DATOS
			funcionmostrar(energias,nenergias,filas);	
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
			funcionmoda(energias, filas, nenergias);
			break;
			}
		case 4:
			{
			//FUNCION PARA TIPO DE ENERGÍA
			funciontipo(energias,nenergias);
			break;
			}
		default:
                printf("Opción invalida. Por favor, intentelo de nuevo.\n");
                break;
          }
	}while(consulta!=4); 
		
        }else if (accion==1){
    	FILE *add; 

       if ((add = fopen("generacion_por_tecnologias_21_22_puntos_simplificado.csv","a"))==NULL)
	    {
        printf("No se pudo abrir el archivo.\n");
        return 1;
        }


    printf("Ingrese los datos nuevos de la siguiente manera:\n");
    printf("Nombre de la energía,dato (01/2021),dato(02/2021),...\n");
    
    scanf("%s",filanueva);
    fprintf(add, "%s\n", filanueva);

    fclose(add);
    printf("Los datos se han agregado al archivo correctamente\n");
	
printf("Ha llegado al final de su ejecución.\n");
		
 	}else{
		printf("Ese número no es válido. Por favor, intentelo de nuevo.\n");
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

void funcionmoda(int energias[], Datos filas[30], int nenergias)
{
    int nmeses = 0, l, i, j, k, o, p, m, n, q;
    int mes[24], ano[24];
    int energy = 1;
    int ncomas = 0;
    char datos[30][40];
    float datos_convertidos[30][40];
    float mayor;
	
do{

    printf("Introduzca el número de meses en los que se desea consultar la moda\n");
    scanf("%i", &nmeses);
    if (1 < nmeses > 24) {
            
		printf("El maximo de meses para consultar la moda es de 24. Por favor, intentelo de nuevo.\n");
     }
}while (1 < nmeses > 24);

    for (p = 0; p < nenergias; p++)
    {
        for (l = 0; l < nmeses; l++)
        {
	do{
            printf("Introduzca el mes %i de la energía %i\n", l + 1, p + 1);
            scanf("%i", &mes[l]);
	if (1< mes[l] > 12) {
		printf("El mes introducido es incorrecto. Por favor, intentelo de nuevo.\n");
	}
	}while (1< mes[l]>12);	
		
	do{
            printf("Introduzca el año en el que lo quiere consultar (2021/2022)");
            scanf("%i", &ano[l]);
	if(ano[l] != 2021 && ano[l] != 2022){
            	printf("No tenemos constancia de ese año. Por favor, intentelo de nuevo.\n");
	}
			
	}while(ano[l]!=2021 && ano[l]!=2022);
        }

        for (o = 0; o < nmeses; o++)
        {
            ncomas = 0;
            k = 0;

            if (ano[o] == 2022)
            {
                for (i = energias[p] + 4, j = 1; ncomas != mes[o] + 13; j++)
                {
                    if (filas[i].filasenteras[j] == ',')
                        ncomas++;
                    else if (ncomas == mes[o] + 12)
                    {
                        datos[p][k] = filas[i].filasenteras[j];
                        k++;
                    }
                }
            }
            else if (ano[o] == 2021)
            {
                for (i = energias[p] + 4, j = 1; ncomas != mes[o] + 1; j++)
                {
                    if (filas[i].filasenteras[j] == ',')
                        ncomas++;
                    else if (ncomas == mes[o])
                    {
                        datos[p][k] = filas[i].filasenteras[j];
                        k++;
                    }
                }
            }

            datos[p][k] = '\0';  // Agregar el carácter de terminación de cadena

            printf("Dato para el mes %i/%i de la energía %i es: %s\n", mes[o], ano[o], p + 1, datos[p]);
        }
    }

    // Imprimir todos los datos almacenados en el vector
    for (m = 0; m < nenergias; m++)
    {
        printf("%s\n", datos[m]);
    }

	//Convertimos los datos tipo char a tipo float para poder compararlos
    for (n = 0; n < nenergias; n++)
    {
        for (q = 0; q < strlen(datos[m]); q++)
        {
            datos_convertidos[n][q] = atof(&datos[n][q]); // Convertir la cadena a número real
            printf("%f\n", datos_convertidos[n][q]);
        }
    }
    mayor = calculomoda(datos_convertidos, nenergias);
    
    printf("Este es el dato de la energía más usada en los meses introducidos: %f", mayor);
	
}

float calculomoda(float datos_convertidos[][40], int nenergias)
{
    int i, j, k = nenergias - 1;
    float mayor;
    
    for (j = 0; j < nenergias - 1; j++)
    {
        for (i = 0; i < k; i++)
        {
            if (datos_convertidos[i][j] < datos_convertidos[i + 1][j])
            {
                mayor = datos_convertidos[i][j];
                datos_convertidos[i][j] = datos_convertidos[i + 1][j];
                datos_convertidos[i + 1][j] = mayor;
            }
        }
        k--;
    }
    
    return datos_convertidos[0][0];  // Retornar el elemento de mayor valor
}
void funcionmostrar(int energias [],int nenergias,Datos filas [30])
{
	int i,j,k,l,m;
	int ncomas=0;
	char dato[30];
	int numdatos=0;
	int mes[24],ano[24];
	for (i=0;i<nenergias;i++)
{       
		printf("¿Cuantos datos de la energía %i quiere mostrar?\n",energias[i]);
		scanf("%i",&numdatos);
		for (j=0;j<numdatos;j++)
		{
			printf("Intrduzca el mes %i de la energia %i: ",j+1,energias[i]);
			scanf("%i",&mes[j]);
			printf("Introduzca el año de dicho mes: ");
			scanf("%i",&ano[j]);
		}
		for (j=0;j<numdatos;j++)
	{
		if(ano[j]==2022)
       {
            	for(k=energias[i]+4,l=1,m=0,ncomas=0;ncomas!=mes[j]+13;l++)
	    	{
    	
                	if (filas[k].filasenteras[l]==',') ncomas++;
        	else
    	        {
    	    		if (ncomas==mes[j]+12)	
		           {
				      dato[m]=filas[k].filasenteras[l];
				    m++;
			       }
		        }
	       }
	       printf("Este es el dato del %i/%i de la energía %i: %s \n",mes[j],ano[j],energias[i],dato); 
	   } 
	   if (ano[j]==2021)
	   {
	   	    	for(k=energias[i]+4,l=1,m=0,ncomas=0;ncomas!=mes[j]+1;l++)
	    	{
    	
                	if (filas[k].filasenteras[l]==',') ncomas++;
        	else
    	        {
    	    		if (ncomas==mes[j])	
		           {
				      dato[m]=filas[k].filasenteras[l];
				    m++;
			       }
		        }
	       }
	       printf("Este es el dato del %i/%i de la energía %i: %s \n",mes[j],ano[j],energias[i],dato); 
	   }
	}
}
	
}
