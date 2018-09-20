/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}

int* majorityElement(int* nums, int numsSize, int* returnSize) 
{
    if(numsSize <= 0) return NULL;
    int *res;
    res = (int *)malloc(numsSize * sizeof(int));
    int pos = 0, cur = 1;
    qsort(nums, numsSize, sizeof(int), cmp);
    
    int i = 1;
    for(i = 1; i < numsSize; i++)
    {
        if(nums[i] == nums[i-1])
        {
            cur++;
        }
        else
        {
            if(cur > numsSize/3)
            {
                res[pos++] = nums[i-1];
            }
            cur = 1;
        }
    }
    if(cur > numsSize/3) res[pos++] = nums[numsSize - 1];
    *returnSize = pos;
    
    return res;
}