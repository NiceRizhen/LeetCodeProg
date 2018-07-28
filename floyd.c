#define _CRT_SECURE_NO_WARNING

#include <stdio.h>

int main(void)
{
	int ans[101][101];

	int n, m;
	while (scanf("%d%d", &n, &m))
	{
		if (n == 0 && m == 0) break;
		int i, j, k;
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				ans[i][j] = -1;
			}
			ans[i][i] = 0;
		}
		int a, b, cost;
		for (i = 1; i <= m; i++)
		{
			scanf("%d%d%d", &a, &b, &cost);
			ans[a][b] = cost;
			ans[b][a] = cost;
		}

		for (k = 1; k <= n; k++)
		{
			for (i = 1; i <= n; i++)
			{
				for (j = 1; j <= n; j++)
				{
					if (ans[i][k] == -1 || ans[j][k] == -1) continue;
					if (ans[i][j] == -1 || ans[i][k] + ans[k][j] < ans[i][j])
						ans[i][j] = ans[i][k] + ans[k][j];
				}
			}
		}

		printf("%d", ans[1][n]);
	}

	return 0;
}
