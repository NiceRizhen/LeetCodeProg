int reverse(int x) {
    int sum = 0;
    
    while(x != 0)
    {
        if(abs(sum) > INT_MAX/10) return 0;
        sum = sum * 10 + x%10;
        x /= 10;
    }

    return sum;
}