#include<stdio.h>
#include<stdlib.h>      /* for exit() */
#include<ctype.h>     /* for isdigit(char ) */
#include<string.h>

char *integer = "LOADINT";
char *flt = "LOADFLT";
char *multiply = "MUL\n";
char *divide = "DIV\n";
char *add = "ADD\n";
char *subtract = "SUB\n";

FILE *fptr;

struct Stack* stack;

/* main function begins */
int main(int argc, char *argv[])
{
    stack = createStack(10000);

    readfile("code.txt");

    calculate();

    double answer = pop(stack);
    printf("%.2f", answer);

    return 0;
}
