// Nelson Diaz

/* Lab 4 Assignment: Incorporate function that takes
expression as input and check whether parenthesis used
in expression are valid or invalid. Returns 1 if valid,
else 0.

Incorporate fuctions for priority that returns priority
of operator, also isOperator, checks whether it's an
operator, isParenthesis, and infixToPostFix which converts to given
infix to postfix*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure
typedef struct {
    char data[MAX];
    int top;
} Stack;

// Function prototypes
Stack* createStack(int capacity);
void push(Stack* s, char c);
char pop(Stack* s);
char peek(Stack* s);
int isEmpty(Stack* s);
int isMatchingPair(char character1, char character2);
int checkBalance(char exp[]);
int precedence(char c);
int isOperator(char c);
char* infixToPostfix(char* infix[], char* postfix[]);

// Main function
int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter an expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}

// Function to create a stack of given capacity
Stack* createStack(int capacity) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*) malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to add an item to stack
void push(Stack* s, char item) {
    if(s->top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }else{
        s->data[++(s->top)] = c;
    }
}

// Function to remove an item from stack
char pop(Stack* s) {
    if(s->top == -1){
        prinf("Stack Underflo\n");
        return -1;
    }else{
        return s->data[(s->top)--];
    }
}

// Function to return the top from stack without removing it
char peek(Stack* s) {
    if(s->top == -1)
    {
        return -1;
    }else{
        return s->data[s->top];
    }
}

// Function to check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Function to check if the pair of parenthesis is matching
int isMatchingPair(char character1, char character2) {
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '{' && character2 == '}')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    return 0;
}

// Function to check if the given expression has balanced parentheses
int checkBalance(char exp[]) {
    int i = 0;

    // Create a stack of capacity equal to expression length
    Stack* stack = createStack(strlen(exp));

    // Traverse the given expression to check matching parenthesis
    while (exp[i]) {
        // If the exp[i] is a starting parenthesis, then push it
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
            push(stack, exp[i]);

        // If exp[i] is a closing parenthesis
        if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {
            // If there is no matching opening parenthesis then return false
            if (isEmpty(stack) || !isMatchingPair(pop(stack), exp[i]))
                return 0;
        }
        i++;
    }

    // If there is no unmatched opening parenthesis then return true
    return isEmpty(stack);
}

// Function to return the priority of the operator
int precendence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default
            return 0;
    }
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to convert infix expression to postfix
char* infixToPostfix(char* infix[], char* postfix[]){
    Stack s;
    s.top = -1;
    int i, k = 0;
    for(i = 0, infix[i], i++)
    {
        if(isalnum(infix[i])){
            postfix[i++] = infix[i];
        }else if(infix[i] == '('){
            push(&s, infix[i]);
        }else if(infix[i] == ')'){
            while(s.top != -1 && peek(&s) != '(')
            {
                postfix[k++] = pop(&s);
            }
            pop(&s); // pop "("
        }else{
            while(s.top != -1 && precendence(peek(&s)) >= precedence(infix[i])){
                postfix[k++] = pop(&s);
            }
            push(&s, infix[i]);
        }
        while(s.top != =1)
        {
            postfix[k++] = pop(&s);
        }
        postfix[k] = '\0'
    }
}

