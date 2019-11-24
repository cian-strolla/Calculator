#include<stdio.h>
#include "vm.h"

/* main function begins */
int main(int argc, char *argv[])
{
    readfile("code.txt");

    calculate();

    return 0;
}
