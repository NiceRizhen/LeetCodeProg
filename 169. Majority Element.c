int cmp(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}

int majorityElement(int* nums, int numsSize) 
{
    int size = (numsSize/2);
    int i = 0;
    
    qsort(nums, numsSize, sizeof(int), cmp);
    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] == nums[i+size]) return nums[i];
    }
    
    return 0;
}