#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
  printf("I am the parent process. My PID is %d\n", getpid());
  pid_t pid = fork();
  if (pid < 0) {
    printf("[Parent]Error fork failed\n");
  }
  if (pid == 0){
    printf("I am the child process. My PID is %d and my parent's PID is %d\n", getpid(), getppid());
    pid_t pid_2 = fork();
    if (pid_2 < 0){
      printf("[Child]Error fork failed\n");
    }
    if (pid_2 == 0) {
      printf("I am the grandchild process. My PID is %d and my parent's PID is %d\n", getpid(), getppid());
    } 
    else{
      wait(NULL);
    }
  }
  else{
    wait(NULL);
  }
  return 0;
}
