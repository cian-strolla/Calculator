#include <ctap.h>

char * testInput = "7 + 3.23 * 4 - 2 / 3\n";
char * testOutput = "LOADINT 7\nADD\nLOADFLT 3.23\nMUL\nLOADINT 4\nSUB\nLOADINT 2\nDIV\nLOADINT 3\n";

char * codeGenerator(char * input);
char * readFile();

TESTS {
  is(codeGenerator(testInput), testOutput, "Test output should be the same as result from codeGenerator() on testInput");
  ok(readFile() == 0, "Working");
}
