#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
	pid_t pid;
	int children[5];
	int i,p;

	for(i=0;i<5;i++){
		p=fork();
		if(p==-1){
			printf("Error\n");
		}else{
			if(p==0){
				switch(i){
					case 0:
					execl("usr/bin/xeyes","xeyes", (char *)0);
						break;
					case 1:
					execl("usr/bin/xload", "xload", (char *)0);
						break;
					case 2:
					execl("usr/bin/xlogo", "xlogo", (char *)0);
						break;
					case 3:
					execl("usr/bin/xcalc", "xcalc", (char *)0); 
						break;
					case 4:
					execl("usr/bin/xclock", "xclock","-update","1", (char *)0);
						break;
				}
			}else{
				children[i]=p;
			}
		}
	}

	int status;
	p=wait(&status);
	while(p=!1){
		pid_t nuevop;
		nuevop=fork();
		if(nuevop==-1){
			printf("Error\n");
		}else{
			if(nuevop==0){
				if(p==children[0])
					execl("usr/bin/xeyes","xeyes", (char *)0);
				if(p==children[1])
					execl("usr/bin/xload","xload", (char *)0);
				if(p==children[2])
					execl("usr/bin/xlogo","xlogo",(char *)0);
				if(p=children[3])
					execl("usr/bin/xcalc","xcalc",(char *)0);
				if(p=children[4])
					execl("usr/bin/xclock", "xclock","-update","1", (char *)0);
			}else
            			if (pid==children[0]) children[0]==nuevop;
            			if (pid==children[1]) children[1]==nuevop;
            			if (pid==children[2]) children[2]==nuevop;
            			if (pid==children[3]) children[3]==nuevop;
           			if (pid==children[4]) children[4]==nuevop;

		}
	}
return 0;
}
