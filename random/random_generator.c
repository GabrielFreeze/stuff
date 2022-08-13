#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int main(int argc, char** argv) {

    if (argc != 2 || strlen(argv[1]) != 8)
        return 0;
    
    //Get hex representation of string.
    uint64_t o;
    memcpy(&o,argv[1],8);
    
    //Seed random generator with hex string and generate z.
    srand(o);
    uint64_t z = ((uint64_t)rand()<<32) | rand();

    //Generate key (t) using xor of hex string and z.
    uint64_t t = z^o;

    //Input variables in resulting C program.
    char buffer[1024];
    snprintf(buffer,1024,"#include <stdio.h>\n#include <stdlib.h>\n#include <stdint.h>\n#include <string.h>\n\nint main() {\n   uint64_t o;\n   uint64_t t = 0x%lx;\n   srand(*(uint64_t*)memcpy(&o,&\"%s\",8));\n    \n   uint64_t z = ((uint64_t)rand()<<32) | rand();\n   for (char i=0;i<8;i++)putc(((z^t)>>(8*i))&0xFF,stdout);\n   putc('\\n',stdout);    \n   return 0;\n}",t,argv[1]);

    //Write to file.
    FILE* fp = fopen("random.c","w");
    fputs(buffer,fp);
    fclose(fp);
    
    return 0;
}