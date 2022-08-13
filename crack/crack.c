#include <stdio.h>
#include <inttypes.h>

int main() {

    uint64_t num = 0xDEADBEEFFACECAFE;

    for (int i=0; i < 8; i++) {

        printf("%c", (uint8_t) (num >> ((uint8_t) (i<<3)&63)) +"KeYpress"[i]+1);


    }

    printf("\n");


    return 0;
}