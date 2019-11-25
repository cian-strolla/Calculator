#include <stdio.h>
#include <stdlib.h>

int main() {
    system("cat postfix.txt");
    printf("\n");
    system("./codeGen");
    printf("\n");
    system("./vm");
    printf("\n");

    return 0;

}
