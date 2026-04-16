#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) 
{
    char *prefix = malloc(strlen(strs[0]) + 1);
    strcpy(prefix, strs[0]);

    for (int i = 1; i < strsSize; i++)
    {
        int j = 0;
        while(prefix[j] && strs[i][j] && prefix[j] == strs[i][j])
        {
            j++;
        }
        prefix[j] = '\0';
        if(prefix[0] == '\0') break;
    }
    return prefix;
}