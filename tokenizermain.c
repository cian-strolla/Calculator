#include "tokenizer.h"

int main() {

  loadStringFromFile("input.txt");

  toToken();

  printToFile("infix.txt");

  return(0);
}
