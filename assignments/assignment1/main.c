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
recipe* readRecipe(); // read details of single recipe and dynamically allocate necessary memory.
recipe** readAllRecipes(int *numRecipes); // read multiple recipes and store in array of pointers to recipes.
double* calculateOrder(int ingredientCount, int numSmoothies, recipe** recipeList); // calculate total amount of ingredients needed for store orders.
void printOrder(char** ingredientNames, double* orderList, int numIngredients); // print order list for each store

// free dynamically allocated memory
void freeIngredients(char** ingredientList, int numIngredients); 
void freeRecipes(recipe** allRecipes, int numRecipes);

// driver function
int main(void)
{   
    // reading ingridients, recipes, and number of stores
    int numIngredients;
    char** ingredients = readIngridients(&numIngredients);

    int numRecipes;
    recipe** recipes = readAllRecipes(&numRecipes);

    int numStores;
    scanf("%d", &numStores);

    // print header, num of smoothies, order for store, and free memory for order.
    for (int store = 1; store <= numStores; store++) {
        printf("List of items for store %d:\n", store);
        int numSmoothies;
        scanf("%d", &numSmoothies);
        
        // calculating order for store
        double* order = calculateOrder(numIngredients, numSmoothies, recipes);

        printOrder(ingredients, order, numIngredients);
        free(order);
        printf("\n");
    }

    // free allocated memory for ingredients and for recipes.
    freeIngredients(ingredients, numIngredients);
    freeRecipes(recipes, numRecipes);

    return 0;
}

// functions
char **readIngridients(int *numIngridients)
{
    // Takes input for value of num of ingridients and then allocates memory according to the number of possible ingridients.
    scanf("%d", numIngridients);
    char **ingridients = (char**)malloc(*numIngridients * sizeof(char*)); //? translate this to english

    // loop for ingridients
    for(int i = 0; i < *numIngridients; i++) //? why is numIngridients a pointer?
    {
        // take input and allocate memory for each item name and number
        char temp[21]; // stores string temporarily to then have access to its length and use that to create an array
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

    return r;
}

recipe** readAllRecipes(int *numRecipes)
{
    scanf("%d", numRecipes);

    // allocating mem for array of pointer for recipes
    recipe** recipes = (recipe**)malloc((*numRecipes) * sizeof(recipe*));
    
    // reading recipes
    for(int i = 0; i < *numRecipes; i++)
    {   
        recipes[i] = readRecipe();
    }

    return recipes;
}

double* calculateOrder(int ingredientCount, int numSmoothies, recipe** recipeList)
{
    // allocate memory for order, then run loop that will get smoothie number and weight
    // read number of smmootheis and their weight
    double* order = (double*)calloc(ingredientCount, sizeof(double));
    for (int i = 0; i < numSmoothies; i++) {
        int smoothieNo, weight;
        scanf("%d %d", &smoothieNo, &weight);
        recipe* r = recipeList[smoothieNo];
        for (int j = 0; j < r->itemCount; j++) {
            // calculating amount for each ingridient
            order[r->itemList[j].itemNo] += (double)(r->itemList[j].portions * weight) / r->totalPortions;
        }
    }
    return order;
}

void printOrder(char** ingredientNames, double* orderList, int numIngredients) 
{
    // printing each ingridient
    for (int i = 0; i < numIngredients; i++) {
        if (orderList[i] > 0) {
            printf("%s %.6lf\n", ingredientNames[i], orderList[i]);
        }
    }
}

// freeing dynamically allocated memory for each ingridient and then list itself
void freeIngredients(char** ingredientList, int numIngredients) 
{
    for (int i = 0; i < numIngredients; i++) {
        free(ingredientList[i]);
    }
    free(ingredientList);
}

// freeing dynamically allocated memory for each item on the list, the recipes, and all the recipes.
void freeRecipes(recipe** allRecipes, int numRecipes) 
{
    for (int i = 0; i < numRecipes; i++) {
        free(allRecipes[i]->itemList);
        free(allRecipes[i]);
    }
    free(allRecipes);
}