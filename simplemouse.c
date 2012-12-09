#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char *button(int code) {
	static char n[10];
	sprintf(n,"%d",code);
	switch(code){
		case 272:
			return "left";
			break;
		case 273:
			return "right";
			break;
		case 274:
			return "middle";
			break;
		default:
			return n;	
	}
}

void main(){
 struct input_event {
     long sec;
     long  usec;
     unsigned short type;
     unsigned short code;
     unsigned  value;
   } ev[2];
 int rd,fd,i;
 char *state[]={"Up","Down"};
 if ((fd = open("/dev/input/event7", O_RDONLY)) < 0) {
   perror("evtest");
   exit(-1);
 }
 

 while(1) {
   printf("-----\n");
  rd = read(fd, ev, sizeof(struct input_event)*2);
  printf("%d %d\n",rd,sizeof(struct input_event));
  if (rd < (int) sizeof(struct input_event)) {
    continue;
  }
  printf(" %ld.%ld  %s %s\n",
			ev[0].sec, ev[0].usec/1000,button(ev[0].code),state[ev[0].value]);
 }
}

