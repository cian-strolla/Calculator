#include <ctap.h>

int codeGenerator (char *input_string);
char *testInput = "3 * 2 + 3.24 - 1 / 4";
char *testOutput = "LOADINT 3\nMUL\nLOADINT 2\nADD\nLOADFLT 3.24\nSUB\nLOADINT 1\nDIV\nLOADINT 4\n";
TESTS {
  is(codeGenerator(testInput), testOutput, "Input postfix should correspond to output code");
}
