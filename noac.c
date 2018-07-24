#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int starttime;
	int endtime;
}T;

int cmp(void*a, void* b)
{
	return (*(T*)a).endtime - (*(T*)b).endtime;
}

int main(void)
{
	int n;
	int i;
	int res = 0, cur = 0;
	T table[100];
	while(scanf("%d", &n)&&n!=0)
	{
		res = 0;
		cur = 0;
		for(i = 0; i < n; i++)
		{
			scanf("%d%d", &table[i].starttime, &table[i].endtime);
		}
		
		qsort(table, n, sizeof(T), cmp);
		
		for(i = 0; i < n; i++)
		{
			if(table[i].starttime>=cur)
			{
				cur = table[i].endtime;
				res++;
			}
		}
		
		printf("%d\n", res);
	}

	return 0;
}
