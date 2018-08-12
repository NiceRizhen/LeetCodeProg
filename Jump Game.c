bool canJump(int* nums, int numsSize) 
{ 
    if(numsSize == 1) return true;
    int max = 0;
    max = nums[0];
    
    if(max >= numsSize - 1) return true;
    
    int i = 1;
    for(i = 1; i < numsSize-1; i++)
    {
        if(i <= max)
        {
            if(i + nums[i] >= numsSize-1) return true;
            if(i + nums[i] > max)
            {
                max = i + nums[i];
            }
        }
        else return false;
    }
    
    return false;
}