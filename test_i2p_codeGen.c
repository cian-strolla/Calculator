#include <stdio.h>
#include <stdlib.h>

int main() {
    system("cat infix.txt");
    printf("\n");
    system("./i2p");
    printf("\n");
    system("./codeGen");
    printf("\n");
    system("cat code.txt");

    return 0;

}
