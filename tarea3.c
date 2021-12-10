#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int fibonacci(int n){
/*printf("num:%n\n",n);*/
if(n > 2){
 return fibonacci(n-1) + fibonacci(n-2);
  }else if (n == 2){
   return 1;
 }else if (n == 1){
   return 1;
}else if (n == 0){
   return 1;
}
}

pid_t pid;

int waitSinHijo(){

pid = fork();

int valorUsuario;

unsigned int resultado;
resultado = fibonacci(25);
if(pid <= -1){
 printf("¡Ha habido un error\n!");
}
else if(pid == 0){
 printf("[%d] hijo Ejecutandose\n",getpid());
}
else{
 printf("[%d] padre ejecutandose\n",getpid());
}

printf("Resultado %d\n",resultado);

return 0;
}

int waitConHijo(){

pid = fork();

int valorUsuario;

unsigned int resultado;
resultado = fibonacci(25);
if(pid <= -1){
 printf("¡Ha habido un error\n!");
}
else if(pid == 0){
 printf("[%d] hijo Ejecutandose\n",getpid());
}
else{
 printf("[%d] padre ejecutandose\n",getpid());
 wait(NULL);
}

printf("Resultado %d\n",resultado);

return 0;
}



int main(int argc, char *argv[]){
waitConHijo();
}



