#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b)
{
	return a>b?a:b;
}

int main(void)
{
    int n;
	scanf("%d", &n);
	
	int sum, big, list[n+1];
	int i = 0;
	
	for(i = 0; i<n; i++)
	{
		scanf("%d", &list[i]);
	}
    big = list[0];
	sum = list[0];
    for(i = 1; i < n; i++)
    {
    	sum = max(list[i], sum+list[i]);
    	big = max(big, sum);
    }
    if(big<0)
    {
    	printf("Game Over");
    	return 0;
    }
    
    printf("%d", big);
    
    return 0;
}
