/*
Authors: Cian Strolla, Ronan Murphy, Anthony Flavin
Test file for virtual machine.
*/

#include <ctap.h>

int readfile(char *code_file);
int calculate();

TESTS {
	ok(readfile("code.txt") == 0, "Input file is read without errors");
    ok(calculate() == 0, "Answer has been calculated without errors");
}
