int min(int a, int b)
{
    return a>b?b:a;
}

int max(int a, int b)
{
    return a>b?a:b;
}

int maxArea(int* height, int heightSize) 
{
    int res = 0, left = 0, right = heightSize - 1;
    
    while(left < right)
    {
        res = max(res, min(height[right], height[left]) * (right - left));
        
        if(height[right] > height[left]) left++;
        else right--;
    }
    
    return res;
}
