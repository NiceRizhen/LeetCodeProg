int numberOfArithmeticSlices(int* A, int ASize) 
{
    int i = 0, j = 0;
    int res = 0;
    for(i = 0; i < ASize-2; i++)
    {
        j = 0;
        while((A[i+j+1] - A[i+j] == A[i+j+2]-A[i+j+1])&&i+j+2<ASize)
        {
            res++;
            j++;
        }
    }
    
    return res;
}