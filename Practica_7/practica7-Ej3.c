#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>

//pid_t gettid(void) {
 //return syscall(__NR_gettid);
//}

pid_t gettid(void){
	return pthread_self();
}


void *pruebaSpid(void *ptr) {
 	printf("Thread secundario: PID=%d, SPID=%d\n", getpid(), gettid());
 	sleep(10);
 	pthread_exit(NULL);
} 

int main() {
	pthread_t thread1;
 	pthread_create(&thread1, NULL, pruebaSpid, NULL);
	printf("Thread principal: PID=%d, SPID=%d\n", getpid(), gettid());
 	sleep(20);
 return 0;
}