#include<stdio.h>
#include<stdlib.h>      /* for exit() */
#include<ctype.h>     /* for isdigit(char ) */
#include<string.h>


// Stack type
struct Stack
{
    int top;
    unsigned capacity;
    int* array;
};

// Stack Operations
struct Stack* createStack( unsigned capacity )
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));

    if (!stack) return NULL;

    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));

    if (!stack->array) return NULL;

    return stack;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1 ;
}

char peek(struct Stack* stack)
{
    return stack->array[stack->top];
}

char pop(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return '$';
}

void push(struct Stack* stack, char op)
{
    stack->array[++stack->top] = op;
}




/* main function begins */
int main(int argc, char *argv[])
{
    char *integer = "LOADINT";
    char *flt = "LOADFLT";
    char *multiply = "MUL\n";
    char *divide = "DIV\n";
    char *add = "ADD\n";
    char *subtract = "SUB\n";

    struct Stack* stack = createStack(10000);


    if (argc != 2) {             //check if user has passed argument for input file
      fprintf(stderr, "Usage: %s \"<input file>\"\n", argv[0]);
      exit(0);
    }

    FILE *fptr;
    char *input_file = argv[1];


    if ((fptr = fopen(input_file, "r")) == NULL)
    {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);
    }

    char line[256];
    char *p;


    while (fgets(line, sizeof(line), fptr)) {   //looping through each line

        const char s[2] = " ";

        p = strtok(line, s);

        while (p != NULL ) {      //looping through each token in the line
            if (strcmp(p,integer) == 0) {   //checking if it is a loadint command
                p = strtok(NULL,s);
                push(stack, *p - '0');
                p = strtok(NULL,s);
            } else if (strcmp(p,flt) == 0) {    //checking if it is a loadflt command
                p = strtok(NULL,s);
                push(stack, *p - '0');
                p = strtok(NULL,s);
            } else {                //if it is an operator, operate on the top two values of the stack 
                int val1 = pop(stack);
                int val2 = pop(stack);
                if (strcmp(p,add) == 0) {
                    push(stack, val2 + val1);
                    p = strtok(NULL,s);
                    break;
                } else if (strcmp(p,subtract) == 0) {
                    push(stack, val2 - val1);
                    p = strtok(NULL,s);
                    break;
                } else if (strcmp(p,multiply) == 0) {
                    push(stack, val2 * val1);
                    p = strtok(NULL,s);
                    break;
                } else if (strcmp(p,divide) == 0) {
                    push(stack, val2/val1);
                    p = strtok(NULL,s);
                    break;
                }
            }
        }


    }



    fclose(fptr);

    int answer = pop(stack);
    printf("%d", answer);

    return 0;
}
