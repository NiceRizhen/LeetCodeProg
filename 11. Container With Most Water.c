int max(int a, int b)
{
    return a>b?a:b;
}

int maxArea(int* height, int heightSize) 
{
    int res = 0, left = 0, right = heightSize - 1;
    
    while(left < right)
    {
        //-max(-a, -b) = min(a, b)
        res = max(res, -max(-height[right], height[left]) * (left - right));
        
        if(height[right] > height[left]) left++;
        else right--;
    }
    
    return res;
}
