#include <stdio.h>
 
int main(void)
{
    int n;
    scanf("%d", &n);
 
    int d[n+5][2];
    d[1][0] = 1;
    d[1][1] = 1;
    d[2][0] = 2;
    d[2][1] = 2;
 
    int i;
    for(i = 3; i<=n; i++)
    {
        d[i][0] = d[i-1][0]+d[i-1][1];
        d[i][1] = d[i-2][0]+d[i-1][0];
    }
    printf("%d", d[n][0] + d[n][1]);

    return 0;
}
