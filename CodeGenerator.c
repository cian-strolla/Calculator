#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stack.h>

int N = 20; // max size of input
struct stack *stack;
int main() {

  FILE *input;
  char str[N]; // unprocessed input from file
  char* inputfile =  "codeGen_input.txt";
  input = fopen(inputfile, "r");
  while (fgets(str,  N, input) != NULL)
  fclose(input);

  char operator0;
  char operand0;
  char operand1;
  double result;
  int count = 0;
  char newOperand;
  char currentChar =  str[count]
  char previousChar =  NULL;

  while (str[count]):
    currentChar = str[count]
    if (currentChar == " ") {
      previousChar =  currentChar;
      continue;
    } else if (isdigit(currentChar) && isdigit(previousChar))  {
      currentChar = (previousChar * 10) + currentChar;
    } else if (isdigit(currentChar)) {
      stack.push(currentChar);
    } else {
    }
    previousChar = currentChar
    count ++;
  }
}
