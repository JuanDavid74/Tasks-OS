#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#define READ  0
#define WRITE 1

int main(void) {
	int nRandom, fd[2];
	pid_t pid;
  	pipe(fd); //Creating a pipe
  	if ((pid=fork()) == 0){  //CHILD
    		close(fd[1]);
		char snum[5];
		read(fd[0], snum, 5);
		int num = (int) strtol(snum,NULL,10); //convert a long int in short int en base 10
	if(num >= 500){
		printf("Mayor/igual a 500\n");
	}else{
		printf("Menor a 500\n");
	} close(fd[0]);
  }else{
    close(fd[0]);  //FATHER
    srand(time(NULL));
    nRandom = rand() % 1000 + 1;
    char snum[5];
    sprintf(snum, "%d\n", nRandom); //int to string 
    write(fd[1], snum, strlen(snum)); //strlen take lenght of a char
    printf("El numero enviado por el pipe es: %s", snum);

}
  close(fd[1]);
  exit(0);
  return 0;
}
