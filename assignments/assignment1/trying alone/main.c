/*
Nelson Diaz

Given a list of possible smoothie ingredients, a list of smoothie
recipes, and lists of sales from several stores, program
determines how much of each ingredient each store must order.

Reading input, each number represent the line and then the meaning of what it has:

First line: Single integer, n(n ≤ 10^5), possible number of smoothie ingridients //? Next "n" number of lines have the ingridients
n-number of lines, which are the smoothie ingridients
    each line will have a single word string between 1 and 20 characters
    each ingridient numbered 0 to n - 1 represented by i^th number

After n-number of lines you will have a line organized like this:
    s (s ≤ 10^5), positive integer. Represents number of recipes. Numbered 0 to s - 1.
    next s-number of lines will contain the recipe as follows

    m I1 R1 I2 R2 ... Im Rm

    m -> # of ingridients
    I1 -> ingridient number(how you identify it) of first ingridient
    R1 -> number of parts (ratio) of first ingridient (1 ≤ R1 ≤ 1000)
    Im and Rm -> Continuation 

Following input will be a single positive integer, k (1 ≤ k ≤ 100), represents number of stores.
Last k-number of lines contain store's order,

    r S1 W1 S2 W2 ... Sr Wr
    
    r -> number of different smoothies (1 ≤ r ≤ s)
    S1 -> smoothie number of first smoothie (0 ≤ S1 ≤ s)
    W1 -> Weight of first smoothie (1 ≤ W ≤ 1000), in pounds

Format of output is:   
    Ingridient_Name Weight_To_Order
    

*/

// pre-processor directive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structures
typedef struct item{
    int itemNo;
    int portions;
}item;

typedef struct recipe{
    int itemCount;
    item* itemList;
    int totalPortions;
}recipe;

// function prototypes
char** readIngredients(int *numIngredients);

// driver function
int main(void)
{
    int numIngridients;
    char** ingridientNames = readIngredients(&numIngridients);

    for(int i = 0; i < numIngridients; i++)
    {
        printf("\n\n%s\n", ingridientNames[i]);
        free(ingridientNames[i]);
    }

    free(ingridientNames);

    return 0;
}

char** readIngredients(int *numIngredients)
{
    scanf("%d", numIngredients);
    char** ingridientNames = (char**)malloc((*numIngredients )*sizeof(char*)); // you are basically saying ingridients = the number of ingridients multiplied by char which makes space for size that a char takes up
    
    // checking if memory was allocated
    if(ingridientNames == NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }

    // looping over ingridient strings, finding size, then storing them dinamically in memory.
    for(int i = 0; i < *numIngredients; i++)
    {
        char tempName[21];
        scanf("%s", tempName);
        ingridientNames[i] = (char*)malloc((strlen(tempName) + 1) * sizeof(char));
        // checking if memory was allocated for specific string
        if(ingridientNames[i] == NULL)
        {
            printf("Memory not allocated.\n");
            exit(0);
        }
        
        strcpy(ingridientNames[i], tempName);
    }   

    return ingridientNames; // returning array of strings
}