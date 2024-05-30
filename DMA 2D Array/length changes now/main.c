/*
Nelson Diaz

Learning how to dynamically allocate
memory for a 2D array.
*/

// pre-processor directive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
int **createRand2DArray(int m, int *L);


// driver funciton
int main(void)
{
    int lengthArray[5] = {3, 2, 4, 5, 2};

    int **arr = createRand2DArray(5, lengthArray); // you need something to store this, hence **arr

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < lengthArray[i]; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < 5; i++)
    {
        free(arr[i]); // You don't need to know how many columns because you are freeing the "block" of memory
    }
    free(arr);

    return 0;
}

// An array of arrays is basically an array of pointers. So row points to column. Soooo we need a POINTER that will POINT to the array, which are POINTERS that point to the VALUE. So who ever keep the address of the 2D array has to be a pointer pointer. 
// For this code, you need to free EACH temp[i] then you get to free temp.
int **createRand2DArray(int m, int *L)
{
    // We need array of pointers so malloc. We want size of "m" pointer. "myArr" will be the one who keeps them.
    int **temp= (int**)malloc(m*sizeof(int *));

    for(int i = 0; i < m; i++)
    {
        temp[i] = (int*)malloc(L[i]*sizeof(int)); // now we are getting the length based on the index
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < L[i]; j++)
        {
            temp[i][j] = rand()%100; // temp[i] is a pointer and temp[j] is accessing that particular array.
        }
    }
    return temp;
}