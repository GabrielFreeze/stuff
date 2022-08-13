#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int main() {
   uint64_t o;
   uint64_t t = 0x37408d756a1f32d3;
   srand(*(uint64_t*)memcpy(&o,&"GabFreez",8));
    
   uint64_t z = ((uint64_t)rand()<<32) | rand();
   for (char i=0;i<8;i++)putc(((z^t)>>(8*i))&0xFF,stdout);
   putc('\n',stdout);    
   return 0;
}