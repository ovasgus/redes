#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include "buscar.h"

int main(int argc, char *argv[]){
    
    char tmp[80], directorio[100], palabra[50], salida[50], archivo[150];
    int len, tipo, count, guardia;
    struct dirent *pDirent;
    DIR *pDir;
    guardia = 0;

   /* Aqui vendria la comprobacion de argumentos */
   
   /* Si se especifica la opcion -d, se obtiene el directorio, por
    * default es '.' */
   
	for (i = 1; i < argc; i++) {
		if (strcmp(argv[i],"-d") == 0) {
			strcpy(directorio, argv[i+1]);
			guardia = 1;
		}
	}
	if (guardia != 0) {
		strcmp(directorio, ".");
	}
	
	/* Se obtiene la palabra a buscar y el archivo de salida */
	
	strcpy(palabra, argv[argc-2]);
	strcpy(salida, argv[argc-1]); 
	
	/* El proceso maestro busca los archivos .txt en el directorio
	 * especificado */	
	
    pDir = opendir(directorio);
    if (pDir == NULL) {
        printf("No se puede abrir el directorio '%s'\n", directorio);
        exit(1);
    }

	printf("palabra: %s \n", palabra);
    while ((pDirent = readdir(pDir)) != NULL) {
        printf("[%s]\n", pDirent->d_name);
        tipo = pDirent->d_type;
        
        if (tipo == 8){
			strcpy(archivo, argv[1]);
			strcat(archivo, pDirent->d_name);
			
			if (archivo[i] == 't') {
		tmp[0] = archivo[i];
		tmp[1] = archivo[i-1];
		tmp[2] = archivo[i-2];
		tmp[3] = archivo[i-3];
		
		if (strcmp(tmp, "txt.") != 0) {
			return -1;
		}	
	}
			
			
			
			
			count = buscar(argv[2], temp);
			
			if(count != -1){
				printf("El numero de veces que '%s' esta en %s es %d\n", argv[2], temp, count);
			} else {
				continue;
			}
			
		}
    }
    
    closedir (pDir);
    return 0;
}
