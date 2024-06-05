#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Consider the following struct, which contains a string and its length in one nice, neat package:
typedef struct smart_string{
    char *word;
    int length;
} smart_string;

/*
Write  a function that takes a string as its input, create a new smart_string struct, and
stores a new copy of the string in the word field of the struct and the length of that
string in the length member of the struct. The function should then return a pointer to
that new smart_string struct. Use dynamic memory management as necessary. The function
signature is:
*/ 

smart_string *create_smart_string(char *str){
    // Allocate memory for new structure
    smart_string* s_string = malloc(sizeof(smart_string));
    // check for error
    if(s_string == NULL){ 
        printf("DMA NOT DONE FOR s_string"); 
        return NULL;
    }
    // find length of string
    int len = strlen(str);

    // allocate memory for word member with the size that has been found
    s_string -> word = malloc(sizeof(char) * (len + 1));
    // check for error
    if(s_string->word == NULL)
    {
        printf("DMA NOT DONE FOR s_string->word");
        return NULL;
    }

    // copy the string
    strcpy(s_string -> word, str);

    // store length in struct, we use arrow becaue we are using a poitner, same thing as *s_string.length
    s_string -> length = len;

    // return pointer to new smart_string struct
    return s_string;
}

/*
Suppose we have a linked list implemented with structure below. Write a function that will
take in a pointer to the head of a list and inserts a node storing -1 after each even
value in the list. If the list is empty or there are no even values in the list, no
modifications should be made to the list. (For example, if the initial list had 2,6,7,1,3,8
the resulting list would have 2, -1, 6, -1, 7, 1, 8 , -1).
*/
typedef struct node {
    int data;
    struct node* next;
}node;

void markEven(node *head)
{
    if(head != NULL)
    {
        
    }
}