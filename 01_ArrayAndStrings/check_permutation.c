/*
 * Check if two strings are perumtations of each other
 */

#define OK  0 
#define NOK 1 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int Result; 

static void sort_string(char s[], int n)
{
    char tmp;
    int j,k;
    for(j = 1; j < n; j++){
        tmp = s[j];
        k = j-1;
        while(k >= 0 && tmp < s[k]){
            s[k+1] = s[k];
            k = k-1;
        }
        s[k+1] = tmp;
    }
}

static Result check_permutation(char s1[], char s2[])
{
    Result result = OK;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    sort_string(s1, len1);
    printf("String 1->%s\n", s1);
    sort_string(s2, len2);
    printf("String 2->%s\n", s2);
    while(*s1 != '\0')
        if(*s1++ != *s2++)
            return NOK;
    return OK;
}

int main()
{
    //TODO TDD
    char s1[] = "daniel"; 
    char s2[] = "dnaile";
    Result result;
    result = check_permutation(s1, s2);
    if (result == OK)
        printf("It's permutation.\n");
    else
        printf("It's not permutation.\n");
    return 0;
}
