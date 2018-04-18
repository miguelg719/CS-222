#include "stack.h"
#include "term.h"
#include <stdio.h>

double evaluate(Term term[], int size);

int main()
{
	//printf("Stack size: %lu\n", sizeof(Stack));
	
	Term terms[5];
	terms[0].type = OPERAND;
	terms[0].operand = 15;
	terms[1].type = OPERAND;
	terms[1].operand = 23;
	terms[2].type = OPERAND;
	terms[2].operand = 7;
	terms[3].type = OPERATOR;
	terms[3].operand = '*';
	terms[4].type = OPERATOR;
	terms[4].operand = '-';
	
	double eval = evaluate(terms, 5);
	printf("The answer is: %lf", eval);
	
	return 0;
}

double evaluate(Term term[], int size)
{
	Stack stack;
	initialize(&stack);
	
	int i = 0;
	for( i = 0; i < size; i++ )
	{
		if( term[i].type == OPERAND ) 
			push(&stack, term[i].operand);
		
		else
		{
			double a = pop(&stack);
			double b = pop(&stack);
			switch( term[i].operator )
			{
				case '+': push(&stack, b + a); break;
				case '-': push(&stack, b - a); break;
				case '*': push(&stack, b * a); break;
				case '/': push(&stack, b / a); break;
			}
		}
		
	}
	
	double answer = pop(&stack);
	cleanUp(&stack);
	return answer;
}
