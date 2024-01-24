#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* hexbin(char c) {
    switch (c) {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': case 'a': return "1010";
        case 'B': case 'b': return "1011";
        case 'C': case 'c': return "1100";
        case 'D': case 'd': return "1101";
        case 'E': case 'e': return "1110";
        case 'F': case 'f': return "1111";
        default: return NULL;
    }
}


char* hex2bin(const char* hexstr) {
    size_t hexlen = strlen(hexstr);
    size_t binlen = hexlen * 4 + 1;
    char* binstr = (char*)malloc(binlen);

    if (binstr == NULL) {
        perror("malloc error");
        exit(EXIT_FAILURE);
    }

    binstr[0] = '\0';

    for (size_t i = 0; i < hexlen; ++i) {
        const char* bindig = hexbin(hexstr[i]);
        if (bindig == NULL) {
            fprintf(stderr, "Error: %c\n", hexstr[i]);
            exit(EXIT_FAILURE);
        }
        strcat(binstr, bindig);
    }

    return binstr;
}


int main() {
    char hexstr[100];

    printf("hex: ");
    scanf("%s", hexstr);

    char* binstr = hex2bin(hexstr);
    
    printf("bin: %s\n", binstr);


    free(binstr);

    return 0;
}
