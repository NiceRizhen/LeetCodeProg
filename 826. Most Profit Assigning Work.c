typedef struct
{
    int diff;
    int prof;
}work;

int cmp(void *a, void *b)
{
    return (*(work*)a).prof - (*(work*)b).prof;
}

int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize) 
{
    int res = 0,max;
    int i,j,k;
    
    work w[difficultySize];
    
    for(i = 0; i < difficultySize; i++)
    {
        w[i].diff = difficulty[i];
        w[i].prof = profit[i];
    }
    
    qsort(w, difficultySize, sizeof(work), cmp);
    
    for(i = 0; i < workerSize; i++)
    {
        max = 0;
        for(j = difficultySize-1; j>=0; j--)
        {
            if(worker[i] >= w[j].diff) 
            {
                max = w[j].prof;
                break;
            }
        }
        if(max>0) res+=max;
    }
    
    return res;
}