bool wordPattern(char* pattern, char* str) 
{
    if(pattern==NULL||str==NULL) return false;

    int i = 0, j = 0;
    char *s[1000];
    for(i = 0; i <1000; i++)
    {
        s[i] = (char*)malloc(sizeof(char)*10);
    }
    int top = -1;
    char*temp = strtok(str, " ");
    while(temp)
    {
        strcpy(s[++top], temp);
        temp = strtok(NULL, " ");
    }

    int len = strlen(pattern);
    if(top!=len-1) return false;
    

    for(i = 0; i < len-1; i++)   
    {
        for(j=i+1; j < len; j++)
        {
            if(pattern[i]==pattern[j])
            {
                if(strcmp(s[i], s[j])!=0) return false;
            }
            else   
            {
                if(strcmp(s[i], s[j])==0) return false;
            }
        }
    }
    return true;
}