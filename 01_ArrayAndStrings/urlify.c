/*
 * replace all spaces in a string with '%20'
 */

#include <stdlib.h>

typedef struct{
    int non-space=0;
    int space=0;
} NumberCharacters;

static NumberCharacters count_characters(char s[])
{
    NumberCharacters number_characters;
    int i = 0;
    while(s[i] != '\0'){
        if(s[i] == ' ')
            number_characters.space++;
        else
            number_characters.non-space++;
    }
    return number_characters;
}
    
static void realloc_space(char s[], NumberCharacters number_characters)
{
    size_t size = number_characters.non-spaces + 3*number_characters.spaces;
    s = realloc(s, size);
} 

void replace_space(char s[])
{
    NumberCharacters number_characters = count_characters(s);
    len = strlen(s); 
    realloc_space(s, number_characters); 
    while(number_characters >= 0 ){
        if (s[len-1] == ' '){
            s[number_characters-1] = '0';
            s[number_characters-2] = '2';
            s[number_characters-3] = '%';
            number_characters = number_characters - 3;
            len = len - 1;
        } else{
            s[number_characters-1] = s[len-1];
            len = len - 1;
        }
    }
    for(int i=0; i != '\0'; i++){


    }
}

