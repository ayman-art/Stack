#ifndef STACK_h
#define STACK_h

#include <stdbool.h>
////////////////////////////////
//CONTROLLING THE TYPE
#define FORMAT "%lf"
#define format_read strtof

typedef double type;
/////////////////////////////////
typedef struct stackType* Stack;


Stack createStack();
void destroy(Stack *stackptr);

bool isEmpty(Stack stack);

type pop(Stack stack);
void push(Stack stack, type data);
type peek(Stack stack);
int size(Stack stack);


#endif