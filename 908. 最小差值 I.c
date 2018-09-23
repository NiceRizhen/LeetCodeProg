int cmp(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}

int smallestRangeI(int* A, int ASize, int K) 
{
    qsort(A, ASize, sizeof(int), cmp);
    
    int min = INT_MAX, cur = 0;
    
    if(A[ASize-1] - A[0] <= 2 * K) min = 0;
    else min =  A[ASize-1] - A[0] - 2 * K;
    
    return min;
}