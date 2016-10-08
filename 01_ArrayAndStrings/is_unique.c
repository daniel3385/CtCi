/*
 * Determine if a string has all unique characters.
 * Author: Daniel Cabral Silveira
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define OK 0
#define NOK 1
typedef int Result ;
typedef int Table ;

int table_of_ASCII[128] = {0};

static int has_in_table(const char character)
{
    int converted_character = (int) character;
    if(table_of_ASCII[converted_character] == 0){
        table_of_ASCII[converted_character] = 1;
        return OK;
    } else
        return NOK;
}

static void is_unique(char string[])
{
    printf("Testing \'%s\' ...\n", string);
    Result result;
    int i = 0;
    while(string[i] != '\0'){
        result = has_in_table(string[i]);
        if (result == NOK){
            printf("%s is not unique, catch %c duplicated\n", string, string[i]);
            return;
        }
        i++;
    }
    printf("%s is unique\n", string);
    memset(table_of_ASCII, 0, sizeof(table_of_ASCII));
}

int main()
{
    char string1[] = "daniel";
    char string2[] = "dannel";
    is_unique(string1);
    is_unique(string2);
    return 0;
}




