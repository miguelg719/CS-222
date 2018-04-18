#ifndef STACK_H
#define STACK_H

typedef struct 
{
	int size;
	int capacity;
	double* values;
} Stack;

void push(Stack* stack, double value);
double pop(Stack* stack);
double top(Stack* stack);


#endif
