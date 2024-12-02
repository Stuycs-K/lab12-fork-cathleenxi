#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>

static void sighandler(int signo) {
        printf("%d", signo);
}

int main(){
  pid_t child1;
  pid_t child2;
  printf("%d about to create 2 child processes\n", getpid());
  child1 = fork();
  if ( child1 == 0){ //child one stuff
    int pid = getpid();
    srand(pid);
    int x = rand() % 5 + 1;
    printf("%d %dsec\n", pid, x);
    sleep(x);
    printf("%d finished after %d seconds\n", pid, x);
    kill(getppid(),x);
  }
  else if(child1 > 0){
      child2 = fork();
      if(child2<0){
          perror("fork fail");//output to stderr instead of stdout
          exit(1);
      }
      else if ( child2 == 0){ //child two stuff
          int pid = getpid();
          srand(pid);
          int x = rand() % 5 + 1;
          printf("%d %dsec\n", pid, x);
          sleep(x);
          printf("%d finished after %d seconds\n", pid, x);
          kill(getppid(),x);
      }
      else if(child2 > 0){
          
          printf("Slept for ");
          signal(1, sighandler);
          signal(2, sighandler);
          signal(3, sighandler);
          signal(4, sighandler);
          signal(5, sighandler);
           
          
          int *status = NULL;
          pid_t firstPid = wait(status);
          
    
          printf(" seconds - Child %d\n", firstPid);
          printf("Main Process %d is done.\n", getpid());
          exit(0);
         
      }
  }
}
