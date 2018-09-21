int cmp(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}

int firstMissingPositive(int* nums, int numsSize) 
{
    if(numsSize <= 0) return 1;
    
    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    
    int i = 1;
    int n = 0;
    
    for(n = 0; n < numsSize; n++)
    {
        if(nums[n] == i) i++;
        
        if(n+1 < numsSize+1)
        {
            if(nums[n] == nums[n+1]) continue;
            if(i > 1 && nums[n+1] != i) return i;
        }
    }
    
    return i;
}