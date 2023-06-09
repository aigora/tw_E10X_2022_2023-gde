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
void funcionmedia( int nenergias, int energias[], Datos filas[30]);
float calculomedia(float datos_convertidos[][40], int nenergias, int nmeses);
void funcionmostrar(int[],int,Datos filas [30]);

int main()
 {
 	int i,j;
 	int nenergias=0,accion=0;
 	int energias [18];
 	int energia, consulta;
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
	printf("Quiere:\nConsultar(0)\nAñadir datos(1)\nFinalizar el programa(2)\n");//Control de datos
	scanf("%i",&accion);
	
	if (accion==2)
	break;
	 
	if (accion==0)
	{
		do{
			printf("¿Cuantas energías quiere consultar? (introduzca un entero positivo)\n");
			scanf("%i",&nenergias);
		if (nenergias < 1 || nenergias > 18) {
			printf("Número inválido. Por favor, intentelo de nuevo.\n");
		}
		} while (nenergias < 1 || nenergias > 18);
    	
	int energias[nenergias];
        int contador = 0;	
		
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
 	
	while (contador < nenergias) {
        
		int numero;
        
		printf("Energia %d: ", contador + 1);
        scanf(" %d", &numero);

        if (numero >= 1 && numero <= 18) {
		
            energias[contador] = numero;
            contador++;
		
        } else {
		
            printf("Numero invalido. Ingrese un numero del 1 al 18.\n");
        }
    }
		
 	  for (i=0;i<nenergias;i++)//Control de datos
 	  {
 		printf("%i",energias[i]);
	  }
		
	printf("\n");	
		
	do{	
	printf("Que tipo de consulta quiere hacer\n");
	printf("Mostrar dato/s (1)\n"); 
	printf("Calcular media (2)\n");
	printf("Calcular moda (3)\n");
	printf("Tipo de energía(4)\n");
	printf("Volver al inicio(5)\n");
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
			funcionmedia(nenergias, energias, filas);
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
		case 5:
			{
			break;
			}
		default:
                printf("Opción invalida. Por favor, intentelo de nuevo.\n");
                break;
          }
	}while(consulta!=5); 
		
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
			
			printf("la energia numero %i: No es renobable\n\n", k+1);
			
		}else{
			
			printf("la energia numero %i: Es renovable\n\n", k+1);
		}
	}
 	
 
 printf("\n");
 }

void funcionmoda(int energias[], Datos filas[30], int nenergias)
{
    int nmeses = 0, l, i, j, k, o, p, m, n, q, r;
    int mes[24], ano[24];
    int ncomas = 0;
    char datos[30][40];
    float datos_convertidos[30][40];
    float mayor;
	
do{

    printf("Introduzca el número de meses en los que se desea consultar la moda\n");
    scanf("%i", &nmeses);
    if (nmeses > 24 || nmeses <1) {
            
		printf("El maximo de meses para consultar la moda es de 24. Por favor, intentelo de nuevo.\n");
     }
}while (nmeses > 24 || nmeses <1);

    for (p = 0; p < nenergias; p++)
    {
        for (l = 0; l < nmeses; l++)
        {
	do{
            printf("Introduzca el mes %i de la energía %i\n", l + 1, p + 1);
            scanf("%i", &mes[l]);
	if (mes[l] >12 || mes[l] <1) {
		printf("El mes introducido es incorrecto. Por favor, intentelo de nuevo.\n");
	}
	}while (mes[l] >12 || mes[l] <1);	
		
	do{
            printf("Introduzca el año en el que lo quiere consultar (2021/2022)\n");
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
	    r=p*(p+o);
            if (ano[o] == 2022)//En este bucle, se recorre la cadena de la fila (energía) correspondiente. Al llegar a la coma 12 ya ha recorrido todos los datos del año 2022
            {
                for (i = energias[p] + 4, j = 1; ncomas != mes[o] + 13; j++)//Una vez llega al dato deseado guarda en una caracteres hasta la coma siguiente,por es finaliza en la coma mes+13.
                {
                    if (filas[i].filasenteras[j] == ',')
                        ncomas++;
                    else if (ncomas == mes[o] + 12)//Sigue recorriendo hasta llegar hasta la coma anterior al dato del mes deseado, por eso se suma el valor del mes al 12.
                    {
                        datos[r][k] = filas[i].filasenteras[j];
                        k++;
                    }
                }
            }
            else if (ano[o] == 2021)//Funciona de la mimsa manera pero al estar los datos del 2021 primero en el csv el programa cuenta tantas comas como el numero del mes.
            {
                for (i = energias[p] + 4, j = 1; ncomas != mes[o] + 1; j++)//Se almacena el dato desde la coma deseada hasta la siguiente.
                {
                    if (filas[i].filasenteras[j] == ',')
                        ncomas++;
                    else if (ncomas == mes[o])
                    {
                        datos[r][k] = filas[i].filasenteras[j];
                        k++;
                    }
                }
            }

            datos[r][k] = '\0';  // Agregar el carácter de terminación de cadena

            printf("Dato para el mes %i/%i de la energía %i introducida es: %s\n", mes[o], ano[o], p + 1, datos[p]);
        } r++;
    }

    
    /*for (m = 0; m < nenergias; m++)
    {
        printf("%s\n", datos[m]);
    }*/

	//Convertimos los datos tipo char a tipo float para poder compararlos
    for (n = 0; n < nenergias; n++)
    {
        for (q = 0; q < strlen(datos[m]); q++)
        {
            datos_convertidos[n][q] = atof(&datos[n][q]); // Convertir la cadena a número real
            //printf("%f\n", datos_convertidos[n][q]);
        }
    }
    mayor = calculomoda(datos_convertidos, nenergias);
    
    printf("Este es uno de los datos pertenecientes a la energía más usada en los meses introducidos: %f GWh\n", mayor);

printf("\n");
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
		do{
		printf("¿Cuantos datos de la energía %i quiere mostrar?\n",energias[i]);
		scanf("%i",&numdatos);
		if (numdatos > 24 || numdatos <1) {
            
		printf("El maximo es de 24. Por favor, intentelo de nuevo.\n");
		
		}
		}while (numdatos > 24 || numdatos <1);
		
		for (j=0;j<numdatos;j++)
		{
			do{
			printf("Intrduzca el mes %i de la energia %i: ",j+1,energias[i]);
			scanf("%i",&mes[j]);
				
			if (mes[j] >12 || mes[j] <1) {
			
			printf("El mes introducido es incorrecto. Por favor, intentelo de nuevo.\n");
			}
			
			}while (mes[j] >12 || mes[j] <1);
			
			do{
			printf("Introduzca el año de dicho mes: ");
			scanf("%i",&ano[j]);
			if(ano[j] != 2021 && ano[j] != 2022){
            	printf("No tenemos constancia de ese año. Por favor, intentelo de nuevo.\n");
			}
			
			}while(ano[j]!=2021 && ano[j]!=2022);
		}
		for (j=0;j<numdatos;j++)
	{
		if(ano[j]==2022)
       {//En este bucle, se recorre la cadena de la fila (energía) correspondiente. Al llegar a la coma 12 ya ha recorrido todos los datos del año 2022 
            	for(k=energias[i]+4,l=1,m=0,ncomas=0;ncomas!=mes[j]+13;l++)//Una vez llega al dato deseado guarda en una caracteres hasta la coma siguiente,por es finaliza en la coma mes+13. 
	    	{
    	
                	if (filas[k].filasenteras[l]==',') ncomas++;
        	else
    	        {
    	    		if (ncomas==mes[j]+12)	//Sigue recorriendo hasta llegar hasta la coma anterior al dato del mes deseado, por eso se suma el valor del mes al 12.
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
	
printf("\n");
}
void funcionmedia ( int nenergias, int energias[], Datos filas[30])
{
	
    float datos_convertidos[30][40];
    int nmeses = 0, l, i, j, k, o, p, m, n, q, y, x;
    int mes[24], ano[24];
    int ncomas = 0;
    char datos[30][40];
    float suma, media;
	
	do{
   	printf ("Introduzca el numero de meses de consulta para la energia %i \n", nenergias);
 	scanf ("%i", &nmeses);
	
	if (nmeses > 24 || nmeses <2) {
            
		printf("El maximo de meses para consultar la media es de 24. Por favor, intentelo de nuevo.\n");
		
	}
	}while (nmeses > 24 || nmeses <2);
    
    
      for (p = 0; p < nenergias; p++)
    {
        for (l = 0; l < nmeses; l++)
        {
	do{
            printf("Introduzca el mes %i de la energía %i\n", l + 1, p + 1);
            scanf("%i", &mes[l]);
	if (mes[l] >12 || mes[l] <1) {
		
		printf("El mes introducido es incorrecto. Por favor, intentelo de nuevo.\n");
		
	}
	}while (mes[l] >12 || mes[l] <1);
	
	do{
            printf("Introduzca el año en el que lo quiere consultar (2021/2022)\n");
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
                for (i = energias[p] + 4, j = 1,ncomas = 0; ncomas != mes[o] + 13; j++)
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
                for (i = energias[p] + 4, j = 1,ncomas = 0; ncomas != mes[o] + 1; j++)
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
    
    for (m = 0; m < nenergias; m++)
    {
        printf("%s\n", datos[m]);
    }

      for (n = 0; n < nenergias; n++)
    {
        for (q = 0; q < strlen(datos[m]); q++)
        {
            datos_convertidos[n][q] = atof(&datos[n][q]); // Convertir la cadena a número real
            //printf("%f\n", datos_convertidos[n][q]);
        }
    }
    for(p=0; p < nenergias; p++)
    {
	  media = calculomedia( datos_convertidos, nenergias, nmeses);
      printf("la media es %f\n", media);
	}
	
printf("\n");
}
float calculomedia ( float datos_convertidos[][40], int nenergias, int nmeses)
{
	int i, j;
	int nemeses;
	float media, suma;
	
	for(i=0; i<nenergias; i++)
	{
		for(j=0; j<nenergias; j++)
		{
			
		suma+= datos_convertidos[i][j];
		
		
	    }
	}
	media= (float) suma/ nmeses;
	return media;
}
