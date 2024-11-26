#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main(){
  pid_t child1;
  pid_t child2;
  child1 = fork();
  if ( child1 == 0){ //child one stuff
    printf("Hello from Child1!\n");
  }
  else{
  child2 = fork();
  if(child2<0){
    perror("fork fail");//output to stderr instead of stdout
    exit(1);
  }
  else if ( child2 == 0){ //child two stuff
      printf("Hello from Child2!\n");
    }
  }

}
