#include<stdio.h>
#include<sys/io.h>

int main(void){
	FILE *fp;
	char *mode = "r";
	char outputFilename[2048];
	int c;
	fp = fopen("in.txt", mode);

	if (fp == NULL) {
	  printf( "Can't open input file!\n");
	  fclose(fp);
	  return 0;
	}
	while((c = getc(fp)) != EOF){
		putchar(c);
		printf("\n");
	}
	fclose(fp);
}

char switch_to_char(){
 	

}


fifo(for examinging the heap):
7f88f5e41400
7fb1626bd400
7fa69c6a5400
7f7a018dc400
7f4168ad8400
7f4da53e6400
7f8e6a252400
7f9fef782400
7f0832ba1400
7f4421a5a400
7f12ec692400
7fd39e78f400


after disabling ASLR:
fifo: 
555556202400
bh struct: 
555556202b00

(gdb) x/64bx 0x555556202b00
0x555556202b00:	0x00	0xcc	0x14	0x56	0x55	0x55	0x00	0x00
0x555556202b08:	0xc0	0xf3	0x6e	0x55	0x55	0x55	0x00	0x00
0x555556202b10:	0x40	0xa5	0x1c	0x56	0x55	0x55	0x00	0x00
0x555556202b18:	0xc0	0x45	0x1d	0x56	0x55	0x55	0x00	0x00
0x555556202b20:	0x00	0x00	0x00	0x00	0x00	0x00	0x00	0x00


map_exec: 0x55555586dba0
page start for fifo: 555556202000
mprotect: 0x000000000007e4e0


7ffff63dea20
0x00007ffff63dea27 in mprotect
 0x00007ffff66b48d0 in mprotect@plt ()  this can redirect to 

 now: 1st goto
  5555558e82a5
  parameter doesnt matter

  then goto mprotect