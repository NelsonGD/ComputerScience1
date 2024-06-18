// Nelson Diaz

/* Programming Assingment 2: Program reads in information
about customers; line placement, enter time, number of smootheis
and estimated wait time till check out */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_LINES 12
#define MAX_NAME_LEN 16


typedef struct Customer 
{
    char name[MAX_NAME_LEN];
    int line_number;
    int arrival_time;
    int num_smoothies;
} Customer;

typedef struct Node 
{
    Customer* customer;
    struct Node* next;
} Node;

typedef struct Queue 
{
    Node* front;
    Node* rear;
} Queue;

// creates a new queue
Queue* createQueue() 
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// creates new customers
Customer* createCustomer(int arrival_time, int line_number, char* name, int num_smoothies) 
{
    Customer* customer = (Customer*)malloc(sizeof(Customer));
    customer->arrival_time = arrival_time;
    customer->line_number = line_number;
    strncpy(customer->name, name, MAX_NAME_LEN);
    customer->num_smoothies = num_smoothies;
    return customer;
}

// adds customers to the queue
void enqueue(Queue* queue, Customer* customer) 
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->customer = customer;
    node->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = node;
        return;
    }
    queue->rear->next = node;
    queue->rear = node;
}

// removes customers from the queue
Customer* dequeue(Queue* queue) 
{
    if (queue->front == NULL) return NULL;
    Node* node = queue->front;
    Customer* customer = node->customer;
    queue->front = queue->front->next;
    if (queue->front == NULL) queue->rear = NULL;
    free(node);
    return customer;
}

// returns the front customer without removing any of the other customers
Customer* peek(Queue* queue) 
{
    if (queue->front == NULL) return NULL;
    return queue->front->customer;
}

// functions checks if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

// frees all the nodes in the queue 
void freeQueue(Queue* queue) 
{
    while (!isEmpty(queue)) 
    {
        Customer* customer = dequeue(queue);
        free(customer);
    }
    free(queue);
}

int main() 
{
    int test_cases;
    // reading number of test cases
    scanf("%d", &test_cases);

    for (int t = 0; t < test_cases; t++) 
    { 
        int num_customers;
        // getting number of customers for especific test_case
        scanf("%d", &num_customers);

        // Loop for creating the queues for each line
        Queue* lines[NUM_LINES];
        for (int i = 0; i < NUM_LINES; i++) 
        {
            lines[i] = createQueue();
        }

        // reading the data from the customers then adding it to the appropiate queue
        for (int i = 0; i < num_customers; i++) 
        {
            int arrival_time, line_number, num_smoothies;
            char name[MAX_NAME_LEN];
            scanf("%d %d %s %d", &arrival_time, &line_number, name, &num_smoothies); // customer information
            Customer* customer = createCustomer(arrival_time, line_number, name, num_smoothies); // adding the customer
            enqueue(lines[line_number - 1], customer); // In appropiate line, enqueue the customer
        }

        int current_time = 0; // keeping track of the current item

        while (1) {
            int min_smoothies = 101; // max num of smoothies
            int selected_line = -1; // tracking lines with whatever customer is been served
            Customer* next_customer = NULL;

            // Looking for the next one that needs to be served
            for (int i = 0; i < NUM_LINES; i++) 
            {
                if (!isEmpty(lines[i])) 
                {
                    Customer* customer = peek(lines[i]); // looking at front of customers in queue
                    if (customer->arrival_time <= current_time) 
                    {
                        // The customer with the fewest smoothies
                        if (customer->num_smoothies < min_smoothies || (customer->num_smoothies == min_smoothies && customer->line_number < selected_line)) 
                        {
                            min_smoothies = customer->num_smoothies;
                            selected_line = i;
                            next_customer = customer;
                        }
                    }
                }
            }

            // In case no customer is completed.
            if (selected_line == -1) 
            {
                int earliest_time = 1000000000; // just a huge number for reference
                for (int i = 0; i < NUM_LINES; i++) 
                {
                    if (!isEmpty(lines[i])) 
                    {
                        Customer* customer = peek(lines[i]); // front customer in queue
                        if (customer->arrival_time < earliest_time) 
                        {
                            earliest_time = customer->arrival_time;
                            selected_line = i;
                            next_customer = customer;
                        }
                    }
                }
                current_time = earliest_time; // makes the current time become the next customer's come in time
            }

            if (selected_line == -1) break; // when customers are done then finish

            // dequeue the customers
            Customer* customer = dequeue(lines[selected_line]);
            // math to find checkout time
            int checkout_time = current_time + 30 + customer->num_smoothies * 5;
            printf("At time %d, %s left the counter from line %d.\n", checkout_time, customer->name, customer->line_number);
            // free memory
            free(customer);
            // update time
            current_time = checkout_time;
        }

        // freeing all the memory
        for (int i = 0; i < NUM_LINES; i++) 
        {
            freeQueue(lines[i]);
        }
    }

    return 0;
}
