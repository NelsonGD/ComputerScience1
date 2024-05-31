/*
Nelson Diaz

Given a list of possible smoothie ingredients, a list of smoothie
recipes, and lists of sales from several stores, program
determines how much of each ingredient each store must order.
*/

// pre-processor directive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// structs
typedef struct item {
    int itemNo;
    int portions;
} item;

typedef struct recipe {
    int itemCount;
    item* itemList;
    int totalPortions;
} recipe;

// Function Prototypes
char **readIngridients(int *numIngridients); // pointer function that points to ingridents that points to value of amount.
recipe* readRecipe();


// driver function
int main(void)
{

    return 0;
}

// functions
char **readIngridients(int *numIngridients)
{
    //variable declaration
    int *numIngridients;

    // Takes input for value of num of ingridients and then allocates memory according to the number of possible ingridients.
    scanf("%d", numIngridients);
    char **ingridients = (char**)malloc(*numIngridients * sizeof(char*)); //? translate this to english

    // loop for ingridients
    for(int i = 0; i < *numIngridients; i++) //? why is numIngridients a pointer?
    {
        // take input and allocate memory for each item name and number
        int temp[21]; // stores string temporarily to then have access to its length and use that to create an array
        scanf("%s", temp);
        ingridients[i] = (char*)malloc((strlen(temp) + 1) * sizeof(char)); // memory allocation for ingridient name
        strcpy(ingridients[i], temp); // send name of ingridient to memory allocated space in ingridient array
    }
    return ingridients;
}

// s - num of recipes   m - num of ingridients (1 ≤ m ≤ 100)    I - number of first ingridient (0 ≤ I < n)   R -  number of parts (ratio) of the first ingredient (1 ≤ R1 ≤ 1000) in smoothie recipe
recipe* readRecipe()
{
    // declaring and taking input for number of recipes
    // Allocate memory for number of recipes
    recipe* r = (recipe*)malloc(sizeof(recipe));
    scanf("%d", &r -> itemCount);
    r->itemList = (item*)malloc(r->itemCount * sizeof(item));
    r -> totalPortions = 0;

    // loop for taking in values for recipes
    for(int i = 0; i < r->itemCount; i++)
    {
        scanf("%d %d", &r->itemList[i].itemNo, &r->itemList[i].portions);
        r->totalPortions += r->itemList[i].portions;
    }
}