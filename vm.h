/*
Authors: Cian Strolla, Ronan Murphy, Anthony Flavin
Header file for the Virtual Machine.
*/


struct Stack* createStack( unsigned capacity );
int isEmpty(struct Stack* stack);
char peek(struct Stack* stack);
double pop(struct Stack* stack);
void push(struct Stack* stack, double op);
int readfile (char *code_file);
int calculate();
