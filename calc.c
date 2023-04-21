#include "calc.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

static void trim(char*);


bool operate(Stack stack, char op){

    if(isEmpty(stack))
        return false;   
    type second;
    type first;
    switch(op){
            
        case '+':
            if(size(stack)<2) return false;
            second = pop(stack);
            first = pop(stack);
            push(stack,first + second);
            break;
        case '-':       
            if(size(stack) == 1)
                push(stack, pop(stack)*-1);
            else
            {
                second = pop(stack);
                first = pop(stack);   
                push(stack,first - second);
            }
            break;
        case '*':
            if(size(stack)<2) return false;
            second = pop(stack);
            first = pop(stack);
            push(stack,first * second);
            break;
        case '/': 
            if(size(stack)<2) return false;  
            second = pop(stack);
            first = pop(stack);
            push(stack,first / second);
            break;
        case '^':
            if(size(stack)<2) return false;
            second = pop(stack);
            first = pop(stack);
            push(stack, pow(first, second)); 
            break;   
        default:
            printf("Error in the operation\n");                  
            return false;
    }
    return true;
}


void calculator(char* expression){

    trim(expression);
    Stack stackCalc = createStack();

    char *strptr =  strtok(expression," ");
    if(strptr && strcmp(strptr,"\n")==0){
        destroy(&stackCalc);
        return;
    }
        

    while(strptr){ 
        if(isdigit(*strptr) || *strptr == '-' && isdigit(*(strptr+1))){
            char *endptr;
            push(stackCalc,format_read(strptr,&endptr));
            if(*endptr && *endptr != '\n'){
                printf("Invalid expression\n");
                destroy(&stackCalc);
                return;
            }
        }   
        else
            if(!operate(stackCalc, *strptr)){
                printf("Invalid expression\n");
                destroy(&stackCalc);
                return;
            }   
                

        strptr = strtok(NULL," ");     
    }
            
        
        if((size(stackCalc) != 1))
            printf("Invalid expression\n");
        else
            printf(FORMAT "\n",pop(stackCalc));
      
    destroy(&stackCalc);
    return;
}



static void trim(char* str) {
    int i = strlen(str), j;
    bool hasNewLine = false;
    if(i>0 && str[i-1] == '\n'){
       hasNewLine = true;
       i--;
    }

    for (i = i - 1; i >= 0 && str[i] == ' '; i--) {
        str[i] = '\0';
    }
    i++;
    if (hasNewLine) {
        str[i] = '\n';
        str[i+1] = '\0';
    }   
    

     i, j = 0;
    while (str[j] == ' ') {
        j++;
    }
    if(j != 0){
        for (i = 0; str[j+i] != '\0'; i++) {
            str[i] = str[j+i];
        }
    str[i] = '\0';}
}



