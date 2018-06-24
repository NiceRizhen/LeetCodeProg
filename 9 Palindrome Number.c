bool isPalindrome(int x) {
    if(x < 0) return false;
    if(x<10) return true;
    
    int a[32];
    int wei=0;
    memset(a, 0, sizeof(a));
    
    while(x > 9)
    {
        a[wei++] = x%10;
        x=x/10;
    }
    a[wei] = x;
    
    int i;
    
    for(i = 0; i<(wei+1)/2; i++)
    {
        if(a[i]!=a[wei-i]) return false;
    }
    
    return true;
    
}