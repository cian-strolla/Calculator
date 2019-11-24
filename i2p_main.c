#include <stdio.h>
#include "infix_to_postfix.h"


/* main function begins */
int main(int argc, char *argv[])
{
	readfile("infix.txt");

	InfixToPostfix();                   /* call to convert */

	writefile("postfix.txt");

	return 0;
}
