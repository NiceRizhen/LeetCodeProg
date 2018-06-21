#include <stdio.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) 
{
    char *result;
    int i = 0, j = 0;
    
    if(strsSize <= 0) return "";
    
    result = strs[0];
    for(i=1; i<strsSize; i++){   
          
        j=0;
          
        while(result[j] && strs[i][j] && result[j]==strs[i][j])
            j ++;  
          
        result[j] = '\0';
    }
    
    return result;
}

int main(void)
{
	char *s[] = {"flower","flow","flight"};
	printf("%s\n", longestCommonPrefix(s, 3));
}
