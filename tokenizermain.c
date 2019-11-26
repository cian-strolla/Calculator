/*
Authors: Cian Strolla, Ronan Murphy, Anthony Flavin
This programs takes an expression and produces a tokenized output.
*/

#include "tokenizer.h"

int main(int argc, char* argv[]) {

  loadStringFromFile(argv[1]);

  toToken();

  printToFile("infix.txt");

  return(0);
}
