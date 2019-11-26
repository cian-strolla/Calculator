/*
Authors: Cian Strolla, Ronan Murphy, Anthony Flavin
Test file for tokenizer.
*/

#include <ctap.h>
#include "tokenizer.h"


TESTS {
	ok(loadStringFromFile("input.txt") == 0, "Input file is read without errors");
  ok(toToken() == 0, "String successfully Tokenized.");
  ok(printToFile("infix.txt") == 0, "Output written to output file without errors");
}
