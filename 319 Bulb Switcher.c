#include <stdio.h>
#include <string.h>

int bulbSwitch(int n) {
    int a[n + 1];
    
    int i,j,result = 0;
    
    memset(a, 0, sizeof(a));
    
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(j%i==0) a[j] = !a[j];
        }
    }
    
    for(i=1; i <= n; i++)
    {
        if(a[i]!=0) result++;
    }
    return result;
}

int main()
{
	printf("%d\n", bulbSwitch(4));
	return 0;
}
