int removeElement(int* nums, int numsSize, int val) {
    
    int i = 0;
    
    int n = 0;
    int temp = numsSize - 1;
    
    while(i <= temp)
    {
        if(nums[i] == val)
        {
            nums[i] = nums[temp--];
            i--;
        }
        i++;
    }
    
    return temp+1;
    
}