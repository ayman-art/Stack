#ifndef STACK_h
#define STACK_h

#include <stdbool.h>


typedef int type;
typedef struct stackType* Stack;


Stack createStack(Stack *stackptr);
void destroy(Stack *stackptr);

bool isEmpty(Stack stack);

int pop(Stack stackptr);
void push(Stack stackptr, int data);


#endif