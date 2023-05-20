//ESQUEMA PARA EXTRAER DATOS ESPECÍFICOS
   
    char dato[40];
    int mes=3;
    int i,j,k;
    int energy=1;
    int ncomas=0
    if(ano==2022)
    {
    	for(i=energy+4,j=1,k=0;ncomas!=mes+13;j++)
		{
    	
    	if (filas[i].filasenteras[j]==',') ncomas++;
    	else
    	{
    			if (ncomas==mes+12)	
		    {
	
				dato[k]=filas[i].filasenteras[j];
				k++;
			
			}
		}
	    }
	}
	
    printf("%s\n",dato);
	printf("%i",ncomas);
	//HASTA AQUI,QUEDA ALMACENADO EN EL VECTOR DATO 
	//DE AQUI SE CONVIERTE A FLOAT.	
