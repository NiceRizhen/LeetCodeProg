int findContentChildren(int* g, int gSize, int* s, int sSize) {
    if(gSize == 0 || sSize == 0) return 0;
    
    int i , j;
    int res = 0;
    int ocupy[sSize];
    int curmin, ocuindex;
    bool exist;
    memset(ocupy, 0, sizeof(ocupy));
    
    for(i = 0; i < gSize; i++)
    {
        curmin = INT_MAX;
        exist = false;
        ocuindex = -1;
        for(j = 0; j < sSize; j++)
        {
            if(g[i] <= s[j])
            {
                if(ocupy[j] == 1) continue;
                
                exist = true;
                if(s[j] < curmin)
                {
                    curmin = s[j];
                    ocuindex = j;
                }
            }
        }
        
        if(exist) res++;
        if(ocuindex > -1) ocupy[ocuindex] = 1;
    }
    
    return res;
}