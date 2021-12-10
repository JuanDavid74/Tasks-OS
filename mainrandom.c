#include "maxrand.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int maxrand(int max) {
  srand(time(0));
  return rand()%max;
}

pid_t pid;

int hijoRandom(){

pid = fork();

int numRandom = maxrand(100);

if(pid == 0){
printf("[%d] Hijo Ejecutandose\n",getpid());
printf("[%d] - %d\n",getpid(),numRandom);
exit(1); 
}else{

int status;
pid = wait(&status);

/*printf("[%d] Padre wait status: %d\n",getpid(),pid);*/
/*printf("[%d] Padre num random : %d\n",getpid(),numRandom);*/

if(WIFEXITED(status)){
 printf("padre exit status = %d\n",WEXITSTATUS(status));

 return 0;
}

}
return 0;
}

int main(int argc, char** argv) {

  hijoRandom();
  return 0;
}
