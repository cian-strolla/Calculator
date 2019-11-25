
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "tokenizer.h"

#define N 999

char str[N];
char str2[N*2];
char period = '.';
const char s[2] = " ";
char *token;

int loadStringFromFile(char *inputfile) {
  FILE *input;
  input = fopen(inputfile, "r");
  while (fgets(str, N, input) != NULL)
  fclose(input);
  return(0);
}

int toToken() {
  for (int i = 0; i < N; i++) { //loops through original string, adding a space between each char
    str2[2*i] = str[i];
    if (i != N - 1) {
      str2[2*i + 1] = ' ';
    }
  }
  for (int u = 0; u < sizeof(str2); u++) {  // function to ensure double digit numbers remain on same line
    if (isdigit(str2[u])) {
      if (isdigit(str2[u + 2])) {
        for (int j = u + 1; j < sizeof(str2); j++) {
          str2[j] = str2[j+1];
        }
      }
      if (str2[u + 2] == period) {
        for (int j = u + 1; j < sizeof(str2); j++) {
          str2[j] = str2[j+1];
        }
        for (int j = u + 1; j < sizeof(str2); j++) {
          str2[j + 1] = str2[j + 2];
        }
      }
    }
  }
  token = strtok(str2, s);  //strtok function splitting string into tokens
  return(0);
}


int printToFile(char *outputfile) {
  FILE *output;
  output = fopen(outputfile, "w");  //open output file in write mode
  while (token != NULL) { //loop through tokens and print to output file
    fprintf(output, "%s\n", token);
    token = strtok(NULL, s);
  }
  fclose(output); //close output file
  return(0);
}
