/*
Authors: Cian Strolla, Ronan Murphy, Anthony Flavin
Test file for infix to postfix converter.
*/

#include <ctap.h>

int readfile(char *infix_file);
int writefile(char *postfix_file);
int InfixToPostfix();

TESTS {
	ok(readfile("infix.txt") == 0, "Input file is read without errors");
    ok(InfixToPostfix() == 0, "Infix expression is valid and has been converted to postfix format");
    ok(writefile("postfix.txt") == 0, "Output written to output file without errors");
}
