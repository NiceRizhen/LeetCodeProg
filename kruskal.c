#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 101

int Tree[N];

int findRoot(int x)
{
	if (Tree[x] == -1) return x;

	else
	{
		int temp = findRoot(Tree[x]);
		Tree[x] = temp;
		return temp;
	}
}

typedef struct
{
	int a, b;
	int cost;
}Edge;
Edge edge[6000];

int cmp(void *a, void *b)
{
	return (*(Edge*)a).cost - (*(Edge*)b).cost;
}

int main(void)
{
	int n;
	int i;
	while (scanf("%d", &n) && n != 0)
	{
		for (i = 1; i <= n*(n - 1) / 2; i++)
		{
			scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].cost);
		}
		qsort(edge + 1, n*(n - 1) / 2, sizeof(Edge), cmp);

		for (i = 1; i <= n; i++)
		{
			Tree[i] = -1;
		}

		int res = 0;
		for (i = 1; i <= n; i++)
		{
			int a = findRoot(edge[i].a);
			int b = findRoot(edge[i].b);

			if (a != b)
			{
				Tree[a] = b;
				res += edge[i].cost;
			}
		}

		printf("%d\n", res);
	}

	return 0;
}

