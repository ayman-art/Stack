#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#define STACK_EMPTY -1111111

typedef struct Node{
    int data;
    struct Node* next;
}Node;

struct stackType{
    Node* head;
};


Stack createStack(Stack* stackptr){
    if(stackptr == NULL)
        return NULL;
    Stack stack = *stackptr;
    
    stack = malloc(sizeof(* stack));
    if(stack==NULL){
        printf("Error: can't create the stack");
        return NULL;
    }

    stack->head = NULL;
    return stack;
}

void push(Stack stack, int data){
    if(stack == NULL)
        return;
   
    Node* new = malloc(sizeof(Node));
    if(new == NULL){
        printf("Error: Can't allocate memory for 'new' in push()");
        return;
    }

    new->data = data;
    new->next = stack->head;

    stack->head=new;

}


int pop(Stack stack){
   if(isEmpty(stack)){
        printf("The stack is Empty!\n");
        return STACK_EMPTY;
   }
    

    int ret = stack->head->data;
    Node *temp = stack->head;
    stack->head = stack->head->next;
    free(temp);

    return ret;

}

int peek(Stack stack){

    if(isEmpty(stack)){
        printf("Error: the stack is Empty!\n");
        return STACK_EMPTY;
    }

    return stack->head->data;

    
}


bool isEmpty(Stack stack){
    if(stack == NULL){
        printf("Error: stack is set to NULL");
        return true;
    }
    return (stack->head == NULL);

}


void destroy(Stack *stackptr){
    if(stackptr==NULL)
        return;
    Stack stack = *stackptr;
    if(stack == NULL)
        return;
    

    while(!isEmpty(stack)){
        printf("%d\n",pop(stack));
        
    }


    free(stack);
    (*stackptr) = NULL;

}

