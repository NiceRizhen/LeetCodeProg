#include <stdio.h>

double toNum(char *s, int *k)
{
	double x = 0.0, y = 0.1;
	int flag = 1;
	while((s[*k] >= '0' && s[*k <= '9']) || s[*k] == '.')
	{
		if(s[*k] == '.')
		{
			flag = 0;
		}
		else
		{
			if(flag)
			{
				x = x*10 + s[*k] - '0';
			}
			else
			{
				x = x + y*(s[*k] - '0');
				y = y * 0.1;
			}
		}
		(*k) = (*k) + 1;
	}	
	return x;
}

int priority(char c)  
{  
    int k;  
    switch (c)  
    {  
	    case '*':k = 2; break;  
	    case '/':k = 2; break;  
	    case '+':k = 1; break;  
	    case '-':k = 1; break;  
	    case '(':k = 0; break;  
	    case ')':k = 0; break;  
	    default:k = -1; break;
    }  
    return k;  
}

int main(void)
{
	double stacks[1000];
	int tops = -1;
	char stacky[1000];
	int topy = -1;
	char *s = "7*6+3*4+5/2";
	
	stacky[++topy] = '\0';
	
	char c = s[0];
	
	int k = 0, flag = 1;
	double x, y;
	
	while(flag)
	{
		if((c >= '0' && c<= '9')||c == '.')
		{
			stacks[++tops] = toNum(s, &k);
		}
		else if(c == '\0' && stacky[topy] == '\0')
		{
			flag = 0;
		}
		else if(c == '(' || priority(c) > priority(stacky[topy]))
		{
			stacky[++topy] = c;
			k++;
		}
		else if(c == ')' && stacky[topy] == '(')
		{
			topy--;
			k++;
		}
		else if(priority(c) <= priority(stacky[topy]))
		{
			x = stacks[tops--];
			y = stacks[tops--];
			c = stacky[topy--];
			switch(c)
			{
				case '+': y = x + y; break;
				case '-': y = y-x; break;
				case '*': y = y * x; break;
				case '/': y = y/x; break;
			}
			stacks[++tops] = y;
		}		
		c = s[k];
	}
	
	printf("%lf\n", stacks[tops]);
	
	return 0;
}
