#include<stdio.h>
#include<sys/io.h>
#define FIFO 0x3f5
#define RDID 0x0a
#define SPC_COMMAND 0x8e
#define BH_COUNT 0x08
#define SH_POSITION 0x1ff
#define SH_COUNT 7
#define TEST_VAL  0x11
#define FD_CMD_READ 0x06
#define WRITE 0x05
#define NUM_STRUCT 0x00
#define STRUCT_LEN 0x28
int main(void){
        //open up port and set permission
        iopl(3);
        ioperm(FIFO, 1, 1);
        outb(SPC_COMMAND, FIFO);
       
        int i;
        for(i=0; i<BH_COUNT; i++){
            outb(TEST_VAL, FIFO);
        }
        
}
