int removeDuplicates(int* nums, int numsSize) {
    int i = 0;
    int n = 0;
    
    for(i = 0; i < numsSize; i++)
    {
        if(i == 0) nums[n++] = nums[i];
        else
        {
            if(nums[i] == nums[i-1]) continue;
            else nums[n++] = nums[i];
        }
    }
    return n;   
}
