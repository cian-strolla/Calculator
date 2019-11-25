#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
  char *inputfile = argv[1];
  char heading[100] = "Testing ";
  strcat(heading, inputfile);
  printf("%s\n", heading);
  char printer[100] = "cat ";
  strcat(printer, inputfile);
  char runner[100] = "./tokenizer ";
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
