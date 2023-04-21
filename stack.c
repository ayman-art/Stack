#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#define STACK_EMPTY -1111111

typedef struct Node{
    type data;
    struct Node* next;
}Node;

struct stackType{
    Node* head;
    int size;
};


Stack createStack(){
    
    Stack stack = malloc(sizeof(* stack));
    if(stack==NULL){
        printf("Error: can't create the stack");
        return NULL;
    }

    stack->head = NULL;
    stack->size = 0;
    return stack;
}

void push(Stack stack, type data){
   
    Node* new = malloc(sizeof(Node));
    if(new == NULL){
        printf("Error: Can't allocate memory for 'new' in push()");
        return;
    }

    new->data = data;
    new->next = stack->head;

    stack->head=new;
    ++stack->size;
}


type pop(Stack stack){
   if(isEmpty(stack)){
        printf("The stack is Empty!\n");
        return STACK_EMPTY;
   }
    

    type ret = stack->head->data;
    Node *temp = stack->head;
    stack->head = stack->head->next;
    free(temp);
    stack->size--;

    return ret;

}

type peek(Stack stack){

    if(isEmpty(stack)){
        printf("Error: the stack is Empty!\n");
        return STACK_EMPTY;
    }

    return stack->head->data;

    
}


bool isEmpty(Stack stack){
    
    return (stack->head == NULL);

}


void destroy(Stack *stackptr){

    Stack stack = *stackptr;
    if(stack == NULL)
        return;
    

    while(!isEmpty(stack))
       pop(stack);


    free(stack);
    (*stackptr) = NULL;

}


int size(Stack stack){
    return stack->size;
}