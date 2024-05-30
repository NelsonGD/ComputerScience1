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
int **createRand2DArray(int m, int n);


// driver funciton
int main(void)
{
    int r, c;
    printf("How many rows and columns? ");
    scanf("%d %d", &r, &c);

    int **arr = createRand2DArray(r, c); // you need something to store this, hence **arr

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < r; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}

// An array of arrays is basically an array of pointers. So row points to column. Soooo we need a POINTER that will POINT to the array, which are POINTERS that point to the VALUE. So who ever keep the address of the 2D array has to be a pointer pointer. 
// For this code, you need to free EACH temp[i] then you get to free temp.
int **createRand2DArray(int m, int n)
{
    // We need array of pointers so malloc. We want size of "m" pointer. "myArr" will be the one who keeps them.
    int **temp= (int**)malloc(m*sizeof(int *));

    for(int i = 0; i < m; i++)
    {
        temp[i] = (int*)malloc(n*sizeof(int)); // So before we made the space for "m" size of array for "temp"(basically first dimension), NOW we are making space for the "second dimension"
    }

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            temp[i][j] = rand()%100; // temp[i] is a pointer and temp[j] is accessing that particular array.
        }
    }
    return temp;
}