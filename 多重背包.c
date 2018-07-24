#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b)
{
	return a>b?a:b;
}

int main(void)
{
    int v, n;
    scanf("%d%d", &n, &v);
    
    int i = 0, j = 0, k = 0;
    int weight[n], value[n], num[n], dp[v+1];
    memset(dp, 0, sizeof(dp));
    for(i = 0; i < n; i++)
    {
    	scanf("%d%d%d", &num[i],&weight[i], &value[i]);
    }
    
    for(i = 0; i < n; i++)
    {
    	for(k = 0; k < num[i]; k++)
    	{
   		    for(j = v; j>=weight[i]; j--)
	    	{
		    	dp[j] = max(dp[j], dp[j-weight[i]]+value[i]);
		    }
	    }
    }
    
    printf("%d", dp[v]);
    return 0;
}
