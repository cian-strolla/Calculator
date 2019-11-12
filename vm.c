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

// Stack type
struct Stack
{
    int top;
    unsigned capacity;
    double* array;
};

// Stack Operations
struct Stack* createStack( unsigned capacity )
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));

    if (!stack) return NULL;

    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (double*) malloc(stack->capacity * sizeof(double));

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

double pop(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

void push(struct Stack* stack, double op)
{
    stack->array[++stack->top] = op;
}


int readfile (char *code_file) {
  if ((fptr = fopen(code_file, "r")) == NULL)
  {
      printf("Error! opening file");
      // Program exits if file pointer returns NULL.
      exit(1);
  }

  return 0;

}

int calculate() {
  char line[256];
  char *p;

  while (fgets(line, sizeof(line), fptr)) {

      const char s[2] = " ";


      p = strtok(line, s);



      while (p != NULL ) {
          if (strcmp(p,integer) == 0) {
              p = strtok(NULL,s);
              double full_num = *p - '0';
              int i = 1;
              int next_char = p[i];
              while (next_char != 10) {
                  full_num = (full_num * 10) + (next_char - '0');
                  i++;
                  next_char = p[i];
              }
              push(stack, full_num);
              p = strtok(NULL,s);
          } else if (strcmp(p,flt) == 0) {
              p = strtok(NULL,s);
              char flt_string[50];
              int i = 0;
              int next_char = p[i];
              while (next_char != 10) {
                  flt_string[i] = p[i];
                  i++;
                  next_char = p[i];
              }
              double flt_val = atof(flt_string);
              push(stack, flt_val);
              p = strtok(NULL,s);
          } else {
              double val1 = pop(stack);
              double val2 = pop(stack);
              if (strcmp(p,add) == 0) {
                  push(stack, val2 + val1);
                  p = strtok(NULL,s);
                  break;
              } else if (strcmp(p,subtract) == 0) {
                  push(stack, val2 - val1);
                  p = strtok(NULL,s);
                  break;
              } else if (strcmp(p,multiply) == 0) {
                  push(stack, val1 * val2);
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

  return 0;
}

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
