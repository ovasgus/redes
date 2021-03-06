/********************************************/
/*				 Proyecto 2					*/
/********************************************/
/*			Gustavo Ortega 09-10590			*/
/*		   Katrin Bethencourt 09-10102		*/
/********************************************/

/*********************************************/
/* Archivo que contiene la implementación de */
/*   las funciones utilizadas en el archivo	 */
/* 			principal del programa			 */
/*********************************************/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/****************************************************************/ 
/* 						FUNCION: buscar							*/
/*																*/
/* OBJETIVO: Buscar una palabra en un archivo.					*/
/*																*/
/* PARAMETROS: Dos arreglos de caracteres, uno con la palabra a */
/* buscar y otro con el archivo en donde se va a buscar.		*/
/*																*/
/* RETORNO: Entero con el numero de veces que se encontro la 	*/
/* palabra en el archivo 										*/
/****************************************************************/
int buscar(char pal[], char archivo[])
{
	int i;
	i = 0;
	FILE *fd;
	char pal_archivo[125];	
	/* pal_archivo es un arreglo de caracteres donde se almacena cada 
	 * palabra leida del texto */
	
	/* Abre el archivo pasado como argumento, detectando si se produjo
	 * algun error con la llamada al sistema */
	fd = fopen(archivo, "r");
	if (fd == NULL) {
		printf("No se pudo abrir el archivo %s\n", archivo);
		exit(1);
	}

	/* Lee las palabras del archivo y las compara con la palabra a buscar
	* enviada por el padre, aumenta el contador si fue encontrada */
	fscanf(fd, "%s", pal_archivo);
	while (!feof(fd)) {
		if (strcmp(pal_archivo, pal) == 0) {
			i++;
		}
		fscanf(fd, "%s", pal_archivo);
	}
	
	fclose(fd);
	return i;
}

/****************************************************************/ 
/* 					FUNCION: comprobacion						*/
/*																*/
/* OBJETIVO: Comprobar la validez de los parametros pasados al	*/
/* proceso.														*/
/*																*/
/* PARAMETROS: Un entero con el numero de argumentos pasados al */
/* proceso, y un apuntador a un arreglo de caracteres que		*/
/* contiene los argumentos pasados al proceso.					*/
/*																*/
/* RETORNO: No retorna nada.								 	*/
/****************************************************************/
void comprobacion(int argc, char *argv[])
{
	int i;
	
	if (!(argc > 2 && argc < 9)) {
		printf("Numero de argumentos invalidos\n");
		exit(1);
	}

	if(strcmp(argv[1],"-h") == 0) {
		if ((argv[2]) != NULL) {
			printf("-h es excluyente de las otras opciones\n");
			exit(1);
		}
	}else {
		for(i = 1; i < argc; i++) {
			if (strcmp(argv[i],"-d") == 0) {
				if (argv[i+2] == NULL) {
					printf("Falta palabra a buscar\n");
					exit(1);
				}
				if (argv[i+3] == NULL) {
					printf("Falta archivo de salida\n");
					exit(1);
				}	
			}
		}
		
		if (strcmp(argv[1],"-n") == 0)
		{
			int num = atoi(argv[2]);
			if (num < 1) {
				printf("n debe ser un entero mayor o igual que 1\n");
				exit(1);
			}
			
			if (argv[3] == NULL) {
				printf("Falta palabra a buscar\n");
				exit(1);
			}
			if (argv[4] == NULL) {
				printf("Falta archivo de salida\n");
				exit(1);
			}	
		}
	}

}

/****************************************************************/ 
/* 						FUNCION: comptxt						*/
/*																*/
/* OBJETIVO: Comprobar que un archivo tiene extension .txt.		*/
/*																*/
/* PARAMETROS: Un arreglo de caracteres con el nombre del		*/
/* archivo deseado.												*/
/*																*/
/* RETORNO: Devuelve un entero con valor -1 si el archivo no	*/ 
/* tiene la extension deseada .txt.							 	*/
/****************************************************************/
int comptxt(char archivo[]) {
	char *txt;
	/* tmp es un arreglo de caracteres usado para comparar los ultimos 4
	 * caracteres del nombre del archivo, para saber si su extension es
	 * .txt */
	char *pos;
	txt = ".txt"; 
	pos = strstr(archivo,".txt");
	if(!pos){
		return -1;
	}else{
		return 0;
	}
}

/****************************************************************/ 
/* 						FUNCION: ayuda							*/
/*																*/
/* OBJETIVO: Imprimir la ayuda del programa						*/
/*																*/
/* PARAMETROS: Ninguno.											*/
/*																*/
/* RETORNO: Ninguno.											*/
/****************************************************************/
void ayuda() {
	printf(" Sintaxis:\n 	\n pargrep { -h | [-n i] -r -d directorio palabra salida }\n");
	printf("\n -h: Imprime esta ayuda.\n -n i: Cantidad de hilos, i debe ser mayor o igual que 1.\n");
	printf(" -d directorio: Especifica el directorio donde se encuentran los archivos a analizar\n");
	printf(" -r: Se realiza la busqueda recursivamente.\n");
	printf(" -palabra: Palabra que se desea buscar.\n");
	printf(" -salida: Archivo en donde se escribirán los archivos analizados y el numero de veces");
	printf(" que se encontró la palabra a buscar\n");
	exit(0);
		
}
