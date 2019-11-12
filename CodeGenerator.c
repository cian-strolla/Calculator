#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {

  // creating files pointers, determining input file size
  FILE *input;
  FILE *output;
  input = fopen("postfix.txt", "r");
  fseek(input, 0L, SEEK_END);
  int fileSize = ftell(input);
  rewind(input);

  // creating char array 'str' where file contents will be stored
  char str[fileSize];
  fgets(str, fileSize, input);
  fclose(input);

  // creating/opening output file
  output =  fopen("code.txt", "w+");

  //  creating variables and pointers, default for currentOp is "LOADINT"
  char current;
  char *currentOp = "LOADINT";
  char currentNum[30];
  memset(currentNum, 0, sizeof currentNum);

  // loops through each character in the file
  for (int i = 0; i < fileSize; i++) {

    // currentChar being operated on is set
    current = str[i];

     //  if the char is a space or the final character & the previous char was a number, operation and number are output to the file
    if ((current == ' ' || i == fileSize-1) && (currentOp == "LOADFLT" || currentOp == "LOADINT")) {
      fprintf(output, "%s %s\n", currentOp, currentNum);
      currentOp = "LOADINT";
      memset(currentNum, 0, sizeof currentNum);

    // if the char is a space or the final character & the previous char was an operator, the operator is written to the file
    } else if (current == ' ' || i == fileSize-1) {
      fprintf(output, "%s\n", currentOp);
      currentOp = "LOADINT";
      memset(currentNum, 0, sizeof currentNum);

    // if the character is a '.' the current op is changed to LOADFLT and the character is appended to currentNum
    } else if (current == '.')  {
        strncat(currentNum, &current, 1);
        currentOp = "LOADFLT";

    // else if the character is a number the digit is appended to currentNum
    } else if (isdigit(current)) {
        strncat(currentNum, &current, 1);

    // otherwise it must be an operator & currentOp is changed accordingly
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
