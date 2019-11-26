/*
Authors: Cian Strolla, Ronan Murphy, Anthony Flavin
Header file for infix to postfix converter.
*/


void push(char item);
char pop();
int is_operator(char symbol);
int precedence(char symbol);
int InfixToPostfix();
int readfile (char *infix_file);
int writefile (char *postfix_file);
