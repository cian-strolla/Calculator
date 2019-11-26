/*
Authors: Cian Strolla, Ronan Murphy, Anthony Flavin
This programs takes the generated code and computes the answer to the original
expression.
*/

#include<stdio.h>
#include "vm.h"

/* main function begins */
int main(int argc, char *argv[])
{
    readfile("code.txt");

    calculate();

    return 0;
}
