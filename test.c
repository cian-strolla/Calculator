#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char inputfile[100];
char printer[100];
char runner[100];

int main(int argc, char* argv[]) {
  
  inputfile == argv[1];
  printer == "cat ";
  strcat(printer, inputfile);
  printf("%s\n", printer);
  runner == "./tokenizer ";
  strcat(runner, inputfile);
  printf("Inital Input: \n");
  system(printer);
  printf("\n");
  system(runner);
  printf("Infix Expression: \n");
  system("cat infix.txt");
  printf("\n");
  system("./i2p");
  printf("Postfix Expression: \n");
  system("cat postfix.txt");
  printf("\n");
  system("./codeGen");
  printf("Generated Code: \n");
  system("cat code.txt");
  printf("\n");
  printf("Result: \n");
  system("./vm");
  printf("\n");

  return 0;

}
