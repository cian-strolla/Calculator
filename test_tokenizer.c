#include <ctap.h>

int loadStringFromFile(char *inputfile);
int toToken();
int printToFile(char *outputfile);

TESTS {
	ok(loadStringFromFile("input.txt") == 0, "Input file is read without errors");
  ok(toToken() == 0, "String successfully Tokenized.");
  ok(printToFile("infix.txt") == 0, "Output written to output file without errors");
}
