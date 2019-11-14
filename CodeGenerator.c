#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NUMBER 999

char postfix[NUMBER];
char code[NUMBER];

// Function to read a string from a file
int readFile() {
  FILE *input;
  input = fopen("postfix.txt", "r");
  // creating char array 'str' where file contents will be stored
  if (input == NULL) {
    perror("Error opening input file \"postfix.txt\"");
    return 1;
  }
  if (fgets(postfix, 999, input) != NULL) {
    return 0;
  }
  else {
    perror("Error reading \"postfix.txt\"");
    return 1;
  }
}

// Function to write a string to a file
int writeFile() {
  FILE *output;
  output = fopen("code.txt", "w+");
  fprintf(output, "%s", code);
  fclose(output);
  return 0;
}


// Function that performs the code generation from an input string and returns the code as a string
int codeGenerator() {

  //  creating variables and pointers, default for currentOp is "LOADINT"
  char current;
  char *currentOp = "LOADINT ";
  char currentNum[30];
  memset(currentNum, 0, sizeof currentNum);
  memset(code, 0, 999);
  char newLine = '\n';
  // loops through each character in the file
  //for(int i = 0; i<999; i++)
  int i = 0;
  current = postfix[i];
  while (current) {
    // currentChar being operated on is set
    current = postfix[i];

     //  if the char is a space or the final character & the previous char was a number, operation and number are output to the file
    if ((current == ' ' || current == '\n') && (currentOp == "LOADFLT " || currentOp == "LOADINT ")) {
      strcat(code, currentOp);
      strcat(code, currentNum);
      strncat(code, &newLine, 1);
      currentOp = "LOADINT ";
      memset(currentNum, 0, sizeof currentNum);

    // if the char is a space or the final character & the previous char was an operator, the operator is written to the file
  } else if (current == ' ' || current == '\n') {
      strcat(code, currentOp);
      strncat(code, &newLine, 1);
      currentOp = "LOADINT ";
      memset(currentNum, 0, sizeof currentNum);

    // if the character is a '.' the current op is changed to LOADFLT and the character is appended to currentNum
    } else if (current == '.') {
        strncat(currentNum, &current, 1);
        currentOp = "LOADFLT ";

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
      i++;
    }
    return 0;
  }
