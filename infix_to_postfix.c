/* This program converts infix expression to postfix expression.
 * This program assume that there are Five operators: (*, /, +, -,^)
	in infix expression and operands can be of integer or float type.*/

#include<stdio.h>
#include<stdlib.h>      /* for exit() */
#include<ctype.h>     /* for isdigit(char ) */
#include<string.h>

#define SIZE 100

char infix[SIZE] = {0};
char postfix[SIZE];         /* declare infix string and postfix strings
 														as gloabal variables*/


/* declared here as global variable because stack[]
* is used by more than one fucntions */
char stack[SIZE];
int top = -1;

/* define push operation */

void push(char item)
{
	if(top >= SIZE-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top+1;
		stack[top] = item;
	}
}

/* define pop operation */
char pop()
{
	char item ;

	if(top <0)
	{
		printf("stack under flow: invalid infix expression");
		getchar();
		/* underflow may occur for invalid expression */
		/* where ( and ) are not matched */
		exit(1);
	}
	else
	{
		item = stack[top];
		top = top-1;
		return(item);
	}
}

/* define function that is used to determine whether any symbol is operator or not
(that is symbol is operand)
* this fucntion returns 1 if symbol is opreator else return 0 */

int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}

/* define fucntion that is used to assign precendence to operator.
* Here ^ denotes exponent operator.
* In this fucntion we assume that higher integer value
* means higher precendence */

int precedence(char symbol)
{
	if(symbol == '^')/* exponent operator, highest precedence*/
	{
		return(3);
	}
	else if(symbol == '*' || symbol == '/')
	{
		return(2);
	}
	else if(symbol == '+' || symbol == '-')          /* lowest precedence */
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

int InfixToPostfix()
{
	int i, j;
	char item;
	char x;
  const char space[2] = " ";

	push('(');                               /* push '(' onto stack */
	strcat(infix,")");                  /* add ')' to infix expression */

	i=0;
	j=0;
	item=infix[i];         /* initialize before loop*/

	while(item != '\0')        /* run loop till end of infix expression */
	{
		if(item == '(')
		{
			push(item);
		}
		else if( isdigit(item))
		{
			postfix[j] = item;              /* add operand symbol to postfix expr */
			j++;
      int k = i;
      char next_item;
      while (1) {                       /* check if token is a multi-digit integer
                                           or a float*/
        k++;
        next_item = infix[k];
        if (isdigit(next_item) || next_item == '.') {
          postfix[j] = next_item;
          j++;
          i = k;
        } else {
          break;
        }
      }

      postfix[j] = *space;
      j++;
		}
		else if(is_operator(item) == 1)        /* means symbol is operator */
		{
			x=pop();
			while(is_operator(x) == 1 && precedence(x)>= precedence(item))
			{
				postfix[j] = x;                  /* so pop all higher precendence operator and */
				j++;
        postfix[j] = *space;
        j++;
				x = pop();                       /* add them to postfix expresion */
			}
			push(x);
			/* because just above while loop will terminate we have
			popped one extra item
			for which condition fails and loop terminates, so that one*/

			push(item);                 /* push current oprerator symbol onto stack */
		}
		else if(item == ')')         /* if current symbol is ')' then */
		{
			x = pop();                   /* pop and keep popping until */
			while(x != '(')                /* '(' encounterd */
			{
				postfix[j] = x;
				j++;
        postfix[j] = *space;
        j++;
				x = pop();
			}
		}
		else
		{ /* if current symbol is neither operand not '(' nor ')' and nor
			operator */
			printf("\nInvalid infix Expression.\n");        /* the it is illegeal  symbol */
			getchar();
			exit(1);
		}
		i++;


		item = infix[i]; /* go to next symbol of infix expression */
	} /* while loop ends here */
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");        /* the it is illegeal  symbol */
		getchar();
		exit(1);
	}


	postfix[j-1] = '\0'; /* add sentinel else puts() fucntion */
	/* will print entire postfix[] array upto SIZE */

	return 0;
}

int readfile (char *infix_file) {
  char c[100];

  FILE *fptr;
  if ((fptr = fopen(infix_file, "r")) == NULL)
  {
      printf("Error! opening file");
      // Program exits if file pointer returns NULL.
      exit(1);
  }
  int i = 0;
  // reads text until newline
  while (fscanf(fptr,"%s", c) == 1) {
    strcat(infix,c);
    // uncomment this to see the file being read line by line printf("%s\n", infix);
  }
  fclose(fptr);
	return 0;
}

int writefile (char *postfix_file) {
	const char s[2] = "";  //delim setting for token splitting

  char *token;

  token = strtok(postfix, s);  //strtok function splitting string into tokens

  FILE *output;
  char* outputfile = postfix_file;
  output = fopen(outputfile, "w");  //open output file in write mode
  while (token != NULL) { //loop through tokens and print to output file

    fprintf(output, "%s", token);

    token = strtok(NULL, s);
  }
	fprintf(output, "\n");
  fclose(output); //close output file
	return 0;
}
