#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    printf("stack calculator\n");

    Stack stack = createStack(&stack);

    push(stack, 10);
    push(stack, 30);

    printf("%d\n",pop(stack));
    printf("%d\n",pop(stack));

    //CHECK EXCEPTOIN HANDLING
    printf("%d\n",pop(stack));

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);

    destroy(&stack);
    if(stack == NULL)
        printf("DESTROYED");

    //CHECK EXCEPTOIN HANDLING    
    destroy(&stack);
    
    return 0;
}