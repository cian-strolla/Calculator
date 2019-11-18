#include <ctap.h>

char * testInput = "7 + 3.23 * 4 - 2 / 3\n";
char * testOutput = "LOADINT 7\nADD\nLOADFLT 3.23\nMUL\nLOADINT 4\nSUB\nLOADINT 2\nDIV\nLOADINT 3\n";

int codeGenerator();
int readFile();
int writeFile();

TESTS {
  ok(readFile() == 0, "readFile Working");
  ok(codeGenerator() == 0, "codeGenerator Working");
  ok(writeFile() == 0, "writeFile() Working");
}
