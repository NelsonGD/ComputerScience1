/*
Code going over implementing queues with linked list.
*/

#include <stdio.h>
#include <stdlib.h>

#define EMPTY -1 // if linked list is empty write to return empty

// Stores one node of the linked list
struct node{
    int data;
    struct node* next;
};

// Stores our queue.
struct queue{
    struct node* front;
    struct node* back;
};

void init(struct queue* qPtr);
int enqueue(struct queue*qPtr, int val);
int dequeue(struct queue* qPtr);
int empty(struct queue* qPtr);
int peek(struct queue* qPtr);
void displayQueue(struct queue* myQ);

int main(){
    
    struct queue myQ; // Creates one queue; myQ [f | b]
    init(&myQ); // Pass by reference

    int choice;
    int data;

    int i;

    while(1)
    {
        printf("\n1. Insert element to queue\n");
        printf("2. Delete element from queue\n");
        printf("3. Display all elements of queue\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: 
                printf("\nWhat data you want to put in the queue?: ");
                scanf("%d", &data);
                enqueue(&myQ, data); // Always pass address of structure because its EFFICIENT
                displayQueue(&myQ);
                break;
            case 2:
                data = dequeue(&myQ);
                if(data!=EMPTY)
                {
                    printf("\n%d deleted from queue\n", data);
                    displayQueue(&myQ);
                }
                else
                    printf("Empty queue\n");
                break;
            case 3:
                displayQueue(&myQ);
            case 4:
                exit(1);
            default:
                printf("Wrong choice \n");
        }
    }
    return 0;
}

// Printing linked list
void displayQueue(struct queue* MyQueuePtr)
{
    struct node *t = MyQueuePtr -> front;
    while(t)
    {
        printf("%d ", t->data);
        t = t->next;
    }
}

// Pre-condition: qPtr points to a valid struct queue.
// Post-condition: The struct that qPtr points to will be set up to represent an
// empty queue.
void init(struct queue* qPtr){ // recived reference to queue

    qPtr -> front = NULL; // dereferences and updates front to NULL
    qPtr -> back = NULL; // same thing for back


    // This helps you initialize any queue when passing reference to this function.
}

int enqueue(struct queue* qPtr, int x)
{
    // according to plan in notion notes, first sep is to create a node
    // To create node use malloc
    struct node* temp = malloc(sizeof(struct node));
    if(temp == NULL)
    {
        return 0; // means that malloc failed
    }
    temp -> data = x;
    temp -> next = NULL;

    // before accesing null check if back is null
    if(qPtr -> back == NULL) // This means that the front is also NULL
    {
        qPtr -> front = temp;
        qPtr -> back = temp;

        return 1; // succesfully added the item
    }

    // main part of the code: queues
    qPtr -> back -> next = temp;
    qPtr -> back = temp; // same as qPtr -> back -> next

    return 1;
}

/*
Steps
--- save the front node to a temp node pointer
--- move front forward to the next node
--- save the temp's data to an int variable retval
--- free temp
--- return retval
*/
int dequeue(struct queue* qPtr)
{
    // not the same as the next check
    if(empty(qPtr))
        return EMPTY;
    
    struct node* temp = qPtr -> front;
    qPtr -> front = qPtr -> front -> next;
    int retval = temp -> data;
    free(temp);

    // how do you know when to change back?
    // back will not be same anymore because front move foward and after moving from foward, front became null.
    // this check is based on the code before
    if(empty(qPtr))
        qPtr -> back = NULL;

    return retval;
}

int empty(struct queue* qPtr)
{
    return qPtr -> front == NULL; // boolean expression; returns 1 if true, 0 if false.
}
int peek(struct queue* qPtr)
{
    if(qPtr -> front != NULL)
        return qPtr -> front -> data;
    else
        return EMPTY;
}