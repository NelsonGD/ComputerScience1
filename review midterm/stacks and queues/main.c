/*
Stack: Linear data structure that follows the Last In, First Out (FIFO) principle.

Operation:
    push, pop, peek, isEmpty

Used for expressive evaluation, syntax parsing, backtracking algorithms.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

// typedef struct Stack{
//     int top;
//     int arr[MAX];
// } Stack;

// To create the stack
// Stack *createStack(){
//     Stack* stack = (struct Stack*) malloc(sizeof( Stack));
//     stack -> top = -1;
//     return stack;
// }

// push element onto stack
void push(Stack* stack, int item){
    if(stack -> top == MAX -1)
    {
        print("Stack overflow\n");
        return;
    }
    stack -> arr[++stack -> top] = item;
    printf("%d pushed to stack\n", item);
}

// pop an element from stack
int pop(Stack* stack)
{
    if(stack -> top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    return stack -> arr[stack->top--];
}

// get the top element
int peek(Stack* stack){
    if(stack->top == -1)
    {
        return -1;
    }
    return stack->arr[stack->top];
}

// check if stack empty
int isEmpty(Stack* stack)
{
    return stack->top == -1;
}

/*
Queues:

Linear data structure that follow First In, First Out (FIFO) principle.

Operation:
    enqueue, dequeue, front, isEmpty

Used for scheduling algorithms, breadth-first search(BFS)
*/

typedef struct Queue{
    int front, rear, size;
    unsigned capacity;
    int* array;
}Queue;

// Creating queue
Queue* createQueue(unsigned capacity)
{
    Queue* queue = (struct Queue*)malloc(sizeof(Queue));
    queue -> capacity = capacity;
    queue -> front = queue -> size = 0;
    queue -> rear = capacity - 1;
    queue -> array = (int*)malloc(sizeof(int)*queue->capacity);
    return queue;
}

// checking if queue is full
int isFull(struct Queue* queue){
    return(queue->size == queue->capacity);
}

// enqueue element to queue
void enqueue(Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue -> rear + 1) % queue -> capacity;
    queue -> array [queue->rear] = item; 
    queue -> size = queue -> size + 1;
    printf("%d enqueued to queue\n", item);
}

// dequeue an element from the queue
int dequeue(Queue* queue){
    if(isEmpty(queue))
        return -1;
    int item = queue -> array[queue -> front];
    queue -> front = (queue -> front + 1) % queue -> capacity;
    queue -> size = queue-> size -1;
    return item;
}

int front(Queue* queue)
{
    if(isEmpty(queue))
        return -1;
    return queue -> array[queue->front];
}

// get rear element
int rear(Queue* queue)
{
    if(isEmpty(queue))
        return -1;
    return queue -> array[queue->rear];
}

/*
Recursion

A function calling itself with a base case to terminate

Used for factorial calculationi and fibonacci series
*/

int factorial(int n)
{
    if(n == 0)
        return 1;
    return n * factorial(n - 1);
}

/*
Fast Exponentitation

Efficiently calculate power using divide-and-conquer

Used for a^b
*/

int fastExponentiation(int base, int exp)
{
    if(exp == 0)
        return 1;
    int half = fastExponentiation(base, exp/2);
    if(exp % 2 == 0)
        return half * half;
    else   
        return half * half * base;
}

/*
Linked List with Recursion

Sequence of nodes where each node points to next

For insertions, deletion, and traversal.
*/

typedef struct Node{
    int data;
    struct Node* next;
}Node;

void insert(Node** head_ref, int new_data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node -> data = new_data;
    new_node -> next = (*head_ref);
    (*head_ref) = new_node;
}

/*
Recursive Operations
*/

//Traversal
void printList(Node* node)
{
    if(node == NULL)
        return;
    printf("%d -> ", node->data);
    printList(node -> next);
}

// Permutations

/*  Basic Permutation
All possible arrangements of a set of elements */

void swap(char* x, char* y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char* a, int l, int r)
{
    int i;
    if(l == r)
        printf("%s\n", a);
    else{
        for(i = l, i <= r; i++)
        {
            swap((a+l), (a+i));
            permute(a, l+1, r);
            swap((a+l), (a+i)); //backtrack
        }
    }
}

/* Advanced Recursion Topics
Tower of Hanoi
    A mathematical puzzle involving moving disks between rods */

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod){
    if(n == 1){
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod); 
}

// Multiplication 
int multiply(int a, int b){
    if(b == 0)
        return 0;
    if(b > 0)
        return a+multiply(a, b-1);
    if(b < 0)
        return -multiply(a, -b);
}

// String Reverse
void reverseString(char* str, int start, int end){
    if(start >= end)
        return;
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverseString(str, start+1, end -1);
}

// Fibonacci Series and Recursion Trees
int fibonacci(int n){
    if(n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Permutation Approaches and Flood Fill - Flood Fill Algorithm
void floodFillUtil(int screen[][8], int x, int y, int prevC, int newC){
    if(x < 0 || x >= 8 || y < 0 || y >= 8)
        return;
    if(screen[x][y] != prevC)
        return;

    screen[x][y] = newC;

    floodFillUtil(screen, x+1, y, prevC, newC);
    floodFillUtil(screen, x-1, y, prevC, newC);
    floodFillUtil(screen, x, y+1, prevC, newC);
    floodFillUtil(screen, x, y-1, prevC, newC);
}

void floodFill(int screen[][8], int x, int y, int newC){
    int prevC = screen[x][y];
    if(prevC != newC)
        floodFillUtil(screen, x, y, prevC, newC);
}

// Stack Applications

typedef struct Stack{
    int top;
    unsigned capacity;
    int* array;
}Stack;

Stack* createStack(unsigned capacity){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack -> capacity = capacity;
    stack -> top = -1;
    stack -> array = (int*)malloc(sizeof(int) * stack -> capacity);
    return stack;
}

int isFull(Stack* stack){
    return stack -> top == stack -> capacity -1;
}

int isEmpty(Stack* stack){
    return stack -> top == -1;
}

void push(Stack* stack, int item){
    if(isFull(stack))
        return;
    stack -> array[++stack->top] = item;
}

int pop(Stack* stack){
    if(isEmpty(stack))
        return -1;
    return stack -> array[stack -> top--];
}

typedef struct Queue{
    Stack* stack1;
    Stack* stack2;
}Queue;

Queue* createQueue(unsigned capacity){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->stack1 = createStack(capacity);
    queue -> stack2 = createStack(capacity);
}

void enqueue(Queue* queue, int item){
    push(queue -> stack1, item);
}

int dequeue(Queue* queue){
    if(isEmpty(queue -> stack2)){
        while(!isEmpty(queue->stack1)){
            push(queue->stack2, pop(queue->stack1));
        }
    }
    return pop(queue->stack2);
}


// Circular Queues
typedef struct CircularQueue{
    int front, rear, size;
    unsigned capacity;
    int* array;
}CircularQueue;

CircularQueue* createQueue(unsigned capacity){
    CircularQueue* queue = (CircularQueue*)malloc(sizeof(CircularQueue));
    queue -> capacity = capcity;
    queue -> front = queue->size = 0;
    queue -> rear = capacity -1;
    queue -> array = (int*)malloc(sizeof(int) * queue->capacity);
    return queue;
}

int isFull(CircularQueue* queue){
    return(queue->size == queue->capacity);
}

int isEmpty(CircularQueue* queue){
    return(queue->size == 0);
}

void enqueue(CircularQueue* queue, int item){
    if(isFull(queue))
        return;
    queue->rear = (queue->rear+1) & queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d enqueued to queue\n", item);
}

int front(CircularQueue* queue){
    if(isEmpty(queue))
        return -1;
    return queue -> array[queue->front];
}

int rear(CircularQueue* queue){
    if(isEmpty(queue))
        return -1;
    return queue -> array[queue->array];
}

// Base Conversion and Number Systems;
void decimalToBinary(int n){
    if(n > 1)
        decimalToBinary(n / 2);
    
    printf("%d", n % 2);
}

int binaryToDecimal(int n){
    int num = n;
    int dec_value = 0;

    int base = 1;

    int temp = numn;
    while(temp){
        int last_digit = temp % 10;
        temp = temp/10;
        dec_value += last_digit * base;
        base = base * 2;
    }

    return dec_value;
}

// Linked List Advanced Operations
// Circular linked list
typdeDef struct Node{
    int data;
    Node* next;
}Node;

void insert(Node** head_ref, int new_data){
    Node* new_node = (Node*)malloc(sizeof(node));
    Node* last = *head_ref;
    new_node -> data = new_data;
    new_node -> next = *head_ref;

    if(*head_ref != NULL){
        while(last -> next != *head_ref)
            last = last -> next;
        last -> next = new_node;
    }else
        new_node -> next = new_node;
    
    *head_ref = new_node;
}

void printList(Node* head){
    Node* temp = head;
    if(head != NULL){
        do{
            printf("%d -> ", temp->data);
            temp = temp -> next;
        }while(temp != head);
    }
}

int main(void){

    return 0;
}