#include<stdio.h>
#include<unistd.h>
int main (){
	printf("Hola!");
	int i;
	for(i=1;i<=100;i++){
		sleep(1);
		printf("han pasado %d segundos\n",i);
	}


	printf("Mundo!");
return 0;

}
