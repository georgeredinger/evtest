#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void main(){
 struct input_event {
     long sec;
     long  usec;
     unsigned short type;
     unsigned short code;
     unsigned  value;
   } ev[2];
 int rd,fd,i;
 if ((fd = open("/dev/input/event2", O_RDONLY)) < 0) {
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
  printf("sec usec type code value %ld %ld %x %x %x\n",ev[0].sec, ev[0].usec,ev[0].type,ev[0].code,ev[0].value);
 }
}

