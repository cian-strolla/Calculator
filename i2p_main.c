#include <stdio.h>

int readfile (char *infix_file);
int InfixToPostfix();
int puts(const char *str);
int writefile (char *postfix_file);

char postfix[100];


/* main function begins */
int main(int argc, char *argv[])
{
	readfile("infix.txt");

	InfixToPostfix();                   /* call to convert */
	printf("Postfix Expression: ");
	puts(postfix);                     /* print postfix expression */

	writefile("postfix.txt");

	return 0;
}
