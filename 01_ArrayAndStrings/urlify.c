/*
 * replace all spaces in a string with '%20'
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define IN_SPACE 1
#define OUT_SPACE 0

typedef struct{
    int non_space;
    int space;
} NumberCharacters;

static size_t count_characters(char s[])
{
    NumberCharacters number_characters;
    number_characters.non_space = 0;
    number_characters.space = 0;
    int new_len;
    int state = OUT_SPACE;
    int i = 0;
    while(s[i] != '\0'){
        if(s[i] == ' ' && (state == OUT_SPACE)){
            number_characters.space++;
            state = IN_SPACE;
        } else if (s[i] != ' '){
            number_characters.non_space++;
            state = OUT_SPACE;
        }
        i++;
    }
    new_len = number_characters.non_space + 3*number_characters.space + 1;
    return new_len;
}
    
void replace_space(char s[])
{
    size_t new_len = count_characters(s);
    int state = OUT_SPACE;
    int len = strlen(s); 
    s = realloc(s, new_len*sizeof(*s));
    while(new_len >= 0 ){
        if (s[len-1] == ' ' && (state == OUT_SPACE)){
            state = IN_SPACE;
            s[new_len-1] = '0';
            s[new_len-2] = '2';
            s[new_len-3] = '%';
            new_len = new_len - 3;
            len = len - 1;
        } else if (s[len-1] == ' ' && (state == IN_SPACE)){
            len = len - 1;
        } else{
            s[new_len-1] = s[len-1];
            len = len - 1;
            state = OUT_SPACE;
        }
    }
    for(int i=0; i != '\0'; i++){


    }
}

int main()
{
    char *s1 = (char *) malloc(strlen("danie l")+1);
    strncpy(s1,"danie l",strlen("danie l")+1);

    char *s2 = (char *) malloc(strlen("dan            i    el")+1);
    strncpy(s2,"dan            i    el",strlen("dan            i    el")+1);

    char *s3 = (char *) malloc(strlen(" daniel   ")+1);
    strncpy(s3," daniel   ",strlen(" daniel   ")+1);

    printf("s1=%s\n", s1);
    replace_space(s1);
    printf("s1_new=%s\n", s1);

    printf("s2=%s\n", s2);
    replace_space(s2);
    printf("s2_new=%s\n", s2);
    
    printf("s3=%s\n", s3);
    replace_space(s3);
    printf("s3_new=%s\n", s3);

    return 0;
}
