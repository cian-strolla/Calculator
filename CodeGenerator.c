#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char * readFile() {
  FILE *input;
<<<<<<< HEAD
  input = fopen("codeGenInput.txt", "r");
=======
  FILE *output;
  input = fopen("postfix.txt", "r");
  fseek(input, 0L, SEEK_END);
  int fileSize = ftell(input);
  rewind(input);

>>>>>>> b93cd41644f2bf8a401b66e2dc7b51d87d6f6e3b
  // creating char array 'str' where file contents will be stored
  char * str = malloc(sizeof(char) * 999);
  fgets(str, 999, input);
  fclose(input);
  return str;
}

int writeFile(char inputString[]) {
  FILE *output;
  output = fopen("codeGenOutput.txt", "w+");
  //fputs(output, inputString);
  fprintf(output, "%s", inputString);
  fclose(output);
  return 0;
}

<<<<<<< HEAD
char * codeGenerator(char *inputString) {
=======
  // creating/opening output file
  output =  fopen("code.txt", "w+");
>>>>>>> b93cd41644f2bf8a401b66e2dc7b51d87d6f6e3b

  //  creating variables and pointers, default for currentOp is "LOADINT"
  char *code = malloc(sizeof(char) * 999);
  char current;
  char *currentOp = "LOADINT ";
  char currentNum[30];
  memset(currentNum, 0, sizeof currentNum);
  memset(code, 0, 999);
  char newLine = '\n';
  // loops through each character in the file
  //for(int i = 0; i<999; i++)
  int i = 0;
  current = inputString[i];
  while (current != NULL) {
    // currentChar being operated on is set
    current = inputString[i];

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
    return code;
  }

int main() {
  char * input = readFile();
  char * code = codeGenerator(input);
  writeFile(code);
}
