#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include <string.h>
void* say_hello(void* data)
{
char *str;
str = (char*)data;
while(1)
{
printf("%s\n",str);
sleep(1);
}
}
void main(int argc, char *argv[])
{
if (argc < 3){
    printf("usage : thread_sol1 arg1 arg2\n");
    return;
}
pthread_t t1,t2;
char buffer1[256];
char buffer2[256];
sprintf(buffer1, "This is thread %s\n", argv[1]);
sprintf(buffer2, "This is thread %s\n", argv[2]);
pthread_create(&t1,NULL,say_hello, (void*)buffer1);
pthread_create(&t2,NULL,say_hello, (void*)buffer2);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
}
