#include <stdio.h>

int ad(int n)
{
    int result = 0;
    while(n != 0)
    {
        result += n % 10;
        n = n/10;
    }
    return result;
}

int addDigits(int num) {
    
    if(num < 10) return num;
    
    int result = 0;
    
    while(num >= 10)
    {
        result = ad(num);
        num = result;
    }
    
    return result;
}

int main(void)
{
	printf("%d\n", addDigits(99));
}