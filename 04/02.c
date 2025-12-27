#include<stdio.h>
#include <unistd.h>
#include<pthread.h>
#include <sys/wait.h>
void* say_hello(void* data)
{
char *str;
str = (char*)data;
printf("%s\n",str);
}
int main(){
  pid_t pid;
  pthread_t t1,t2;
  pid = fork();
  if (pid < 0) {
    printf("Error Create Child");
    return 0;
  }
  else if (pid == 0) {
    pthread_create(&t1, NULL, say_hello, "First thread from child process\n");
    pthread_create(&t2, NULL, say_hello, "Second thread from child process\n"); 
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
  }
  else {
    pthread_create(&t1, NULL, say_hello, "First thread from parent process\n");
    pthread_create(&t2, NULL, say_hello, "Second thread from parent process\n"); 
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    wait(NULL);
  }
  return 0;
}
