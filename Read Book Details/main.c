/*
INPUT:

3
"The Catcher in the Rye" "J.D. Salinger" 277
"To Kill a Mockingbird" "Harper Lee" 324
"1984" "George Orwell" 328



OUTPUT:

Book 1:
Title: The Catcher in the Rye
Author: J.D. Salinger
Pages: 277

Book 2:
Title: To Kill a Mockingbird
Author: Harper Lee
Pages: 324

Book 3:
Title: 1984
Author: George Orwell
Pages: 328
*/

// pre-processor directive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *title;
    char *author;
    int pages;
} Book;

Book* readBooks(int *numBooks) {
    scanf("%d", numBooks);
    Book *books = (Book *)malloc(*numBooks * sizeof(Book));
    
    for (int i = 0; i < *numBooks; i++) {
        char tempTitle[51];
        char tempAuthor[51];
        
        // TODO: Read the book details into tempTitle, tempAuthor, and pages
        // Hint: Use scanf to read the strings and the integer
        scanf("\"%[^\"]\" \"%[^\"]\" %d", tempTitle, tempAuthor, &books[i].pages);
        
        books[i].title = (char *)malloc((strlen(tempTitle) + 1) * sizeof(char));
        books[i].author = (char *)malloc((strlen(tempAuthor) + 1) * sizeof(char));
        
        strcpy(books[i].title, tempTitle);
        strcpy(books[i].author, tempAuthor);
    }
    
    return books;
}

void printBooks(Book *books, int numBooks) {
    for (int i = 0; i < numBooks; i++) {
        // TODO: Print the details of each book
        // Hint: Use printf to format the output
        printf("Book %d:\n", i + 1);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Pages: %d\n\n", books[i].pages);    
    }
}

void freeBooks(Book *books, int numBooks) {
    for (int i = 0; i < numBooks; i++) {
        // TODO: Free the memory allocated for each book's title and author
        free(books[i].author);
        free(books[i].title);
    }
    free(books);
}

int main() {
    int numBooks;
    Book *books = readBooks(&numBooks);
    printBooks(books, numBooks);
    freeBooks(books, numBooks);
    return 0;
}
