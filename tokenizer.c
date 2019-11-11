
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int N = 999; //variable for total length of input

int main() {

  char period = '.';

  FILE *input;
  char str[N];  //will be full unprocessed string from input file
  char* inputfile = "tokenizer_input.txt";
  input = fopen(inputfile, "r");  //open input file in read mode
  while (fgets(str, N, input) != NULL)  //get string from file and store in 'str'
  fclose(input);

  char str2[N*2]; //will contain original string with each character separated by a space

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



  const char s[2] = " ";  //delim setting for token splitting

  char *token;

  token = strtok(str2, s);  //strtok function splitting string into tokens

  FILE *output;
  char* outputfile = "tokenizer_output.txt";
  output = fopen(outputfile, "w");  //open output file in write mode

  while (token != NULL) { //loop through tokens and print to output file

    // printf("%s\n", token); use to print to screen

    fprintf(output, "%s\n", token);

    token = strtok(NULL, s);
  }
  fclose(output); //close output file


  return(0);
}
