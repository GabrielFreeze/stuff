#include <stdio.h>
#include <inttypes.h>

int main() {
    for (int i=1 ; i<=100; i++) {
      uint32_t Fizz[4] = {i,0x2A447,0x2A51F,0x2A51A447};
      uint8_t Buzz = ((!(i%5)) << 1) | (!(i%3));
      
      if (!Buzz) printf("%d\n",Fizz[Buzz]);
      else while(Fizz[Buzz]>>=3) putc(0xA75427A6946 >> ((Fizz[Buzz]&7)<<0B11) & 255ULL,stdout);
    }
    return 0;
}
