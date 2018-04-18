#include <stdlib.h>
#include "stack.h"

void push(Stack* stack, double value)
{
	if( stack->size == stack->capacity )
	{
		stack->capacity *= 2;
		stack->values = (double*)realloc(stack->values, sizeof(double) * stack->capacity);
	}
	
	stack->values[stack->size] = value;
	stack->size++;
}

double pop(Stack* stack)
{
	stack->size--;
	double temp = stack->values[stack->size];
	return temp;
}

double top(Stack* stack)
{
	return stack->values[stack->size-1];
}

void initialize( Stack* stack ) 
{
	stack->capacity = 5;
	stack->values = (double)malloc(sizeof(double) * stack.capacity);
	stack->size = 0;
}

void cleanUp(Stack* stack)
{
	free(stack->capacity);
	stack->values = NULL;
	free(&stack);
}
