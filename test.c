#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Inital Input: \n");
    system("cat input.txt");
    printf("\n");
    system("./tokenizer");
    printf("Infix Expression: \n");
    system("cat infix.txt");
    printf("\n");
    system("./i2p");
    printf("Postfix Expression: \n");
    system("cat postfix.txt");
    printf("\n");
    system("./codeGen");
    printf("Generated Code: \n");
    system("cat code.txt");
    printf("\n");
    printf("Result: \n");
    system("./vm");
    printf("\n");

    return 0;

}
