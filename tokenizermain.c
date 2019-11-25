#include "tokenizer.h"

int main(int argc, char* argv[]) {

  loadStringFromFile(argv[1]);

  toToken();

  printToFile("infix.txt");

  return(0);
}
