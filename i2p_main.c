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
