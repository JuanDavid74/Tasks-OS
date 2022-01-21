/*
 * Este programa muestra como leer varias palabras del teclado (stdin)
 * Codigo tomado de: https://www.programiz.com/c-programming/c-strings
 *
 * Modificado por: John Sanabria - john.sanabria@correounivalle.edu.co
 * Fecha: 2021-02-26

 * Actualización: Este programa muestra como leer una palabra del teclado
 * Y ejecuta el codigo correspondiente a esta palabra
 * Modificado por: Camila Rodriguez - maria.buchwald@correounivalle.edu.co 
 * y Juan David Olaya - juan.getial@correounivalle.edu.co
 * Fecha: 2021-12-16
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "leercadena.h"

int main(int argc, char *argv[]) {
  char comando[BUFSIZ];
  char **vector;
  int i;
  int cont = 0;

    if(argc !=2){
    printf("Digite el comando a ejecutar\n");
    exit(1);
    }else{
   	 if (strcmp("exit",argv[1]) == 0) {
   	 exit(1);
    }
     	 vector = de_cadena_a_vector(argv[1]);
      	 execvp(vector[0],vector);
      	 perror("Return from execlp() not expected");
      	 exit(EXIT_FAILURE);
    }
return 0;
}
