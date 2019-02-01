#include <stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct len_pos
{
    int position;
    int len;    
} len_pos;

int charInString(char c, char* str, int strLen)
{
    int i = 0;
    for(i = 0; i < strLen; i++)
    {
        if (c == *(str + i))
        {
            return i;
        }
    }
    return -1;
}

len_pos* lengthOfStartStr(char *s)
{
    int i = 1, position;
    len_pos *lp = (len_pos*)malloc(sizeof(len_pos));
    if (s[i] == 0){
        lp->len = 1;
        lp->position = -1;
        return lp;
    }
    while (s[i] != 0)
    {
        position = charInString(*(s + i), s, i);
        if (position == -1) {
            i++;
        } else {
            break;
        }
    }
    lp->position = position;
    lp->len = i;
    return lp;
}


int lengthOfLongestSubstring(char* s) 
{
    char *str = s;
    int str_len = strlen(str);
    int len = 0, start = 0, max = 0;
    while(start + len < str_len)
    {
        str = s + start;
        len_pos *lp = lengthOfStartStr(str);
        if (lp->len > max)
            max = lp->len;
        if (lp->position == -1)
            break;
        start = start + lp->position + 1;
    }
    
    return max;
}

int main()
{
   char* str = "asdfwergdqwertyuio\0";
   int len = lengthOfLongestSubstring(str);
   printf("%d\n", len);
}
