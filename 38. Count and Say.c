char* countAndSay(int n) 
{
    char *list;
    char *res;
    list = (char *)malloc(100000*sizeof(char));
    res = (char *)malloc(100000*sizeof(char));
    
    int i = 0;     // repeat for n-1 times;
    int t = 0;     // to travel the list;
    int cur = 1;   // the num of repeat number;
    int top = 0;   // to insert in res list;
    
    list[0] = '1';
    list[1] = '\0';
    res[0] = '1';
    res[1] = '\0';
    
    for(i = 1; i < n; i++)
    {
        t = 0;
        cur = 1;
        top = 0;
        while(list[t] != '\0')
        {
            while(list[t] == list[t+1])
            {
                cur++;
                t++;
            }
            res[top++] = cur + '0';
            res[top++] = list[t];
            t++;
            cur = 1;
        }
        res[top] = '\0';
        strcpy(list, res);
    }
    
    return res;
}