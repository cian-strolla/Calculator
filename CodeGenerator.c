#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX (100)

// This strcuture represents a stack
struct Stack {
  unsigned MAXSIZE;
  int* array;
  int top;
};

// Function to create an instance of a stack
struct Stack* createStack(unsigned MAXSIZE)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->MAXSIZE = MAXSIZE;
    stack->top = -1;
    stack->array = (int*)malloc(stack->MAXSIZE * sizeof(int));
    return stack;
}

int isempty(struct Stack* stack) {

    if(stack->top == -1) {
      return 1;
    }
    else {
      return 0;
    }
  }

int isfull(struct Stack* stack) {

    if(stack->top == stack->MAXSIZE) {
      return 1;
    }
    else {
      return 0;
    }
  }

int pop(struct Stack* stack) {
    char data;

    if(!isempty(stack)) {
      data = stack->top;
      stack->top = stack->top - 1;
      return data;
    } else {
      return -1;
    }
  }

int push(struct Stack* stack,  int data) {

    if(!isfull(stack)) {
      stack->top = stack->top + 1;
      stack->top = data;
    } else {
      return -1;
    }
  }

const int max = 100;
int N = 20; // max size of input
struct Stack *stack = createStack(MAX);


int main() {

  FILE *input;
  FILE *output;
  char str[N]; // unprocessed input from file
  char* inputfile =  "codeGen_input.txt";
  input = fopen(inputfile, "r");
  while (fgets(str,  N, input) != NULL)
  fclose(input);

  char operator0;
  char operand0;
  char operand1;
  double temp;
  string result;
  int count = 0;
  char currentChar =  str[count];
  char previousChar =  NULL;

  // while there are more characters in the input
  while (str[count]) {

    // currentChar being operated on is set
    currentChar = str[count]

    //  if the char is a space & the previous char is a number, previous number is pushed to the stack
    if (currentChar == " " && isdigit(previousChar)) {
      push(stack, previousChar);

    // else if the last char was a number and this char is a number the new number is made
    } else if (isdigit(currentChar) && isdigit(previousChar))  {
      currentChar = (previousChar * 10) + currentChar;

    // else if its not a digit and is not whitespace must be an operator
    } else if (not (isdigit(currentChar) || currentChar == " ") {
      operand0 = pop(stack);
      operand1 = pop(stack);
      if (currentChar == "*") {
        temp = operand0*operand1;
        push(stack, temp);
    } else if (currentChar == "/") {
        temp = operand1/operand0;
        push(stack, temp);
    } else if (currentChar == "%") {
        temp = operand1 % operand0;
        push(stack, temp);
    } else if (currentChar == "+") (
        temp = operand1 + operand0;
        push(stack, temp);
    ) else if (currentChar == "-") {
        temp = operand1 - operand0;
        push(stack, temp);
    } else if (currentChar == "^") {
        temp = operand1^operand0;
        push(stack, temp);
    }

    previousChar = currentChar;
    count ++;
  }

  output = fopen("codeGen_output", "w");
  result = pop(stack);
  fputs(result, output);
  fclose(output);



}
