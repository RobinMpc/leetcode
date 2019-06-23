#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char * longestPalindrome(char * s){
    int station;
    int i, len = 0;
    int str_len = strlen(s);
    char* result = (char*) malloc (sizeof(char) * str_len);
    char* result_2 = (char*) malloc (sizeof(char) * str_len);
    for(i = 0; i < str_len; i++)
    {
        int j = 0;
        while (i - j >= 0 && i + j < str_len)
        {
            if (*(s + i - j) == *(s + i + j))
            {
                j = j + 1;
            }
            else{
                break;
            }
        }
        if (j > len)
        {
            len = j;
            station = i;
        }
    }
    strncpy(result, s + station + 1 - len, 2 * len - 1);

    len = 0;
    
    for(i = 0; i < str_len; i++)
    {
        int j = 0;
        while(i - j >= 0 && i + j + 1 < str_len)
        {
            if (*(s + i - j) == *(s + i + j + 1))
            {
                j = j + 1;
            }
            else
            {
                break;
            }
        }
        if (j > len)
        {
            len = j;
            station = i;
        }
    }

    strncpy(result_2, s + station + 1 - len, 2 * len);
    *(result_2 + 2 * len) = '\0';

    if (strlen(result) > strlen(result_2)){
        return result;
    } else {
        return result_2;
    }

}


void main()
{
    char* str = "babad";

    char* substr = longestPalindrome(str);
    printf("%s\n" , substr);
}
