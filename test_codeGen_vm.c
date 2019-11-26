/*
Authors: Cian Strolla, Ronan Murphy, Anthony Flavin
Integration test for Code Generator and Virtual Machine.
*/


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
