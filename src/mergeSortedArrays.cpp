/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int compare(struct transaction *p, struct transaction *q)
{
	int a = (p[0].date[6] - '0') * 1000 + (p[0].date[7] - '0') * 100 + (p[0].date[8] - '0') * 10 + (p[0].date[9] - '0');
	int b = (p[0].date[3] - '0') * 10 + (p[0].date[4] - '0');
	int o = (p[0].date[0] - '0') * 10 + (p[0].date[1] - '0');
	int d = (q[0].date[6] - '0') * 1000 + (q[0].date[7] - '0') * 100 + (q[0].date[8] - '0') * 10 + (q[0].date[9] - '0');
	int e = (q[0].date[3] - '0') * 10 + (q[0].date[4] - '0');
	int f = (q[0].date[0] - '0') * 10 + (q[0].date[1] - '0');
	if (a > d)
	{
		return 1;

	}
	else if (a == d)
	{
		if (b > e)
		{
			return 1;
		}
		else if (b == e)
		{
			if (o > f)
			{
				return 1;
			}
			else
			{
				return 2;
			}
		}
		else
		{
			return 2;
		}
	}
	else
	{
		return 2;
	}
}



struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	struct transaction c[100];
	if (A == NULL || B == NULL || ALen <= 0 || BLen <= 0)
	{
		return NULL;
	}
	int i=0, j=0, u = ALen, z = BLen,k=0;
	while (i < u&&j < z)
	{
		int x = compare(&A[i], &B[j]);
		
			if (x == 2)
			{
				c[k] = A[i];
			
				k++;
				i++;
			}
			else
			{
				
				c[k] = B[j];
				j++;
				k++;
			}
			
	}
	printf("%d%d%d%d%d", i, j, k,u,z);
	if (i == u&&j<z)
	{
		for (int m = j; m<z; m++)
		{
			c[k] = B[m];
			
			k++;
			
		}
	}
	if (j==z&&i<u)
	
	{
		
		for (int p = i; p < u; p++)
		{
			c[k] = A[p];
			
	
			k++;
		}
	}
	return c;
}