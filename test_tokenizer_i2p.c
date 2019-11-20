#include <stdio.h>
#include <stdlib.h>

int main() {
    system("cat input.txt");
    printf("\n");
    system("./tokenizer");
    printf("\n");
    system("./i2p");
    printf("\n");
    system("cat infix.txt");

    return 0;

}
