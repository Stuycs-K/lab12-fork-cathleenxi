#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main(){
  pid_t p;
p = fork();
if(p<0){
  perror("fork fail");//output to stderr instead of stdout
  exit(1);
} else if ( p == 0){
    printf("Hello from Child!\n");
}
    printf("Hello from Parent!\n");

}
