#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *str1 = malloc(sizeof(char) * 16);
    char *str2 = malloc(sizeof(char) * 16);

    str1[0] = 'p';
    str1[1] = 'a';
    str1[2] = 's';
    str1[3] = 's';
    str1[4] = ',';
    str1[5] = '\0';

    printf("%s", str1); 
    str2 = str1;
    printf("%s", str2);
    str2 = NULL;
    strcpy(str1, "pass the exam!");
    printf("%s\n", str1);

    free(str1);
    free(str2);

    return 0;
}