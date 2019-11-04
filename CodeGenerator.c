#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {

  // creating files objects, determining input file size
  FILE *input;
  FILE *output;
  input = fopen("codeGenInput.txt", "r");
  fseek(input, 0L, SEEK_END);
  int fileSize = ftell(input);
  printf("%i", fileSize);
  rewind(input);

  // creating char array 'str' where file contents will be stored
  char str[fileSize];
  fgets(str, fileSize, input);
  fclose(input);

  output =  fopen("codeGenOutput.txt", "w+");

  char current;
  char *currentOp = "LOADINT";
  char currentNum[30];
  int count = 0;

  for (int i = 1; i < fileSize; i++) {

    // currentChar being operated on is set
    current = str[i];
    printf("%c", current);

     //  if the char is a space & the previous char is a number, operation and number are output to the file
    if ((current == ' ' || i == fileSize-1) && (currentOp == "LOADFLT" || currentOp == "LOADINT")) {
      fprintf(output, "%s %s\n", currentOp, currentNum);
      currentOp = "LOADINT";
      memset(currentNum, 0, sizeof currentNum);

    } else if (current == ' ' || i == fileSize-1) {
      fprintf(output, "%s\n", currentOp);
      currentOp = "LOADINT";
      memset(currentNum, 0, sizeof currentNum);

    // else if the last char was a number and this char is a number the new number is made
  } else if (current == '.')  {
        strncat(currentNum, &current, 1);
        currentOp = "LOADFLT";

    } else if (isdigit(current)) {
        strncat(currentNum, &current, 1);

    } else {
        if (current == '+') {
          currentOp = "ADD";
        }
        else if (current == '-') {
          currentOp = "SUB";
        }
        else if (current == '*') {
          currentOp = "MUL";
        }
        else if (current == '/') {
          currentOp = "DIV";
        }
    }
  }
  fclose(output);
}
