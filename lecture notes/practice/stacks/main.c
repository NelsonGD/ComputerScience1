/*
Push and Pop Operations

Create a stack with a maximum size of 5. Perform the following sequence of operations and show the stack at each step:
Push(10)
Push(20)
Push(30)
Pop()
Push(40)
Pop()
Pop()
Pop()
Push(50)
Push(60)
*/

// pre-processor directive
#include <stdio.h>
#include <stdlib.h>

struct stack {
    int data;
    struct stack* next;
};

int push(struct stack **top, int num);
int poop(struct stack **top);

// driver function
int main(void)
{
    struct stack* stack1 = NULL; // Initialize the stack to NULL
     


    return 0;
}

int push(struct stack **front, int num)
{
    struct stack* temp = (struct stack *)malloc(sizeof(struct stack));
    temp = NULL;
    
}