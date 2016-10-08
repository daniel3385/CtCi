/*
 * Check if two strings are perumtations of each other
 */

#define OK  0 
#define NOK 1 

typedef int Result; 

int compare_function(const void *a, const void *b)
{
    const int *ia = (const int *)a;  
    const int *ib = (const int *)b;
    return *ia  - *ib; 
}

void sort_string(char s[])
{
    qsort(s, sizeof(s), sizeof(char), compare_function)
}

Result check_permutation(char s1[], char s2[])
{
    Result result = OK
    sort_string(s1);
    sort_string(s2);
    while(*s1 != '\0')
        if(*s1++ != *s2++)
            return NOK;
    return OK;

}

int main()
{
    char *s1, *s2
    Result result;
    check_permutation(s1, s2);
    return 0;
}
