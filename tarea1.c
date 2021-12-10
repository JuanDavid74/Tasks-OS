#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){

pid_t pid;

int contador = 1;
pid = fork();

if(pid == 0 ){
contador += 5; 
}else{
contador += 2;
}
printf("[%d] El valor de contador es: %i\n",getpid(),contador);

return 0;
}
