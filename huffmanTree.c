/***********************************
To realize a huffman treeon my own,
based on the  code in the book.
***********************************/
#include <limits.h>
#include <stdio.h>

typedef struct
{
	int weight;
	int parent;
	int lchild;
	int rchild;
}TreeNode;

void selectMin(TreeNode *HT, int g, int *s1, int *s2);
void createHuffmanTree(TreeNode T[1000], int n)
{
	int m = 2*n;
	int i;
	for(i = 1; i <= m; i++)
	{
		T[i].weight = 0;
		T[i].parent = 0;
		T[i].lchild = 0;
		T[i].rchild = 0; 
	}
	
	int temp;
	for(i = 1; i <= n; i++)
	{
		scanf("%d", &temp);
		T[i].weight = temp;
	}
	
	int p1,p2;
	for(i = n+1; i<m; i++)
	{
		selectMin(T, i-1, &p1, &p2);
		T[p1].parent = T[p2].parent = i;
		T[i].lchild = p1;
		T[i].rchild = p2;
		T[i].weight = T[p1].weight + T[p2].weight;
		if(i == m-1) T[i].parent = -1;
	}
	printf("i\tweight\tparent\tlchild\trchild\n");
	for(i = 1; i <= m-1; i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\n", i, T[i].weight, T[i].parent, T[i].lchild, T[i].rchild);
	}
	printf("\n\n");
	
}

void selectMin(TreeNode *HT, int g, int *s1, int *s2)
{
	int i;
	int cur;
	*s1 = g+1;
	*s2 = g+1;
	int w = INT_MAX;
	for(i = 1; i <= g; i++)
	{
		if(HT[i].parent==0)
		{
			if(HT[i].weight<w)
			{
				w = HT[i].weight;
				*s1 = i;
			} 
		}
	}
	
	HT[*s1].parent = -1;
	
	w = INT_MAX;
	for(i = 1; i <= g; i++)
	{
		if(HT[i].parent==0 && HT[i].weight<w)
		{
			w = HT[i].weight;
			*s2 = i;
		}
	}
}

int main(void)
{
	TreeNode ht[1000];
	createHuffmanTree(ht, 4);
}
