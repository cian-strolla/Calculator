#include<stdio.h>

struct Stack* createStack( unsigned capacity );
int readfile (char *code_file);
int calculate();
double pop(struct Stack* stack);

FILE *fptr;

struct Stack* stack;

/* main function begins */
int main(int argc, char *argv[])
{
    stack = createStack(10000);

    readfile("code.txt");

    calculate();

    fclose(fptr);     //close the input file

    double answer = pop(stack);
    printf("%.2f", answer);



    return 0;
}
