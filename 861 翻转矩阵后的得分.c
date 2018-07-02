int count(int *a, int size)
{
    int result = 0;
    int i = 0;
    
    for(i = 0; i < size; i++)
    {
        result += a[i] * pow(2, size - i - 1);
    }
    return result;
}

int matrixScore(int** A, int ARowSize, int *AColSizes) {
    if(A == NULL || AColSizes == NULL) return -1;    

    int znum = 0;
    int result = 0;
    int i = 0, j = 0;
    

    for(i = 0; i < ARowSize; i++)
    {
        if(A[i][0] == 0)
        {
            for(j = 0; j < *AColSizes; j++)
            {
                if(A[i][j] == 0) A[i][j] = 1;
                else A[i][j] = 0;
            }
        }
    }

    for(j = 1; j < *AColSizes; j++)
    {
        znum = 0;
        for(i = 0; i < ARowSize; i++)
        {
            if(A[i][j] == 0 ) znum++;
        }
        if(znum >= (ARowSize+1)/2)
        {
            for(i = 0; i < ARowSize; i++)
            {
                if(A[i][j] == 0 ) A[i][j] = 1;
                else A[i][j] = 0;
            }
        }
    }
    
    
    for(i = 0; i < ARowSize; i++)
    {
        result += count(A[i], *AColSizes);
    }
    
    return result;
}