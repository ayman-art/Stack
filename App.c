#include "calc.h"
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX_SIZE 200


int main(){

    printf("Welcome to Stack Calculator! To exit program, type exit\n");
    printf("Enter a postfix expression\n");
    
    char string[MAX_SIZE];
    
    fgets(string ,MAX_SIZE-1,stdin);
    while(strcmp(string,"exit\n") != 0){
        calculator(string);
        fgets(string ,MAX_SIZE-1,stdin);
    }

    printf("Exited");
    
    return 0;
}