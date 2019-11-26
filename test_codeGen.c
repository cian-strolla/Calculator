/*
Authors: Cian Strolla, Ronan Murphy, Anthony Flavin
Test flie for Code Generator.
*/

#include <ctap.h>
#include "codeGen.h"

char * testInput = "7 + 3.23 * 4 - 2 / 3\n";
char * testOutput = "LOADINT 7\nADD\nLOADFLT 3.23\nMUL\nLOADINT 4\nSUB\nLOADINT 2\nDIV\nLOADINT 3\n";

TESTS {
  ok(readFile() == 0, "readFile() Working");
  ok(codeGenerator() == 0, "codeGenerator() Working");
  ok(writeFile() == 0, "writeFile() Working");
}
