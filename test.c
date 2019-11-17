#include <stdio.h>
#include <stdlib.h>

int main() {
    system("./tokenizer");
    system("./i2p");
    printf("\n");
    system("./codeGen");
    system("./vm");
    
    return 0;
    
}
