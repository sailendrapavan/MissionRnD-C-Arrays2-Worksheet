/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<string.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int compare1(struct transaction *p, struct transaction *q)
{
	int a = (p[0].date[6] - '0') * 1000 + (p[0].date[7] - '0') * 100 + (p[0].date[8] - '0') * 10 + (p[0].date[9] - '0');
	int b = (p[0].date[3] - '0') * 10 + (p[0].date[4] - '0');
	int o = (p[0].date[0] - '0') * 10 + (p[0].date[1] - '0');
	int d = (q[0].date[6] - '0') * 1000 + (q[0].date[7] - '0') * 100 + (q[0].date[8] - '0') * 10 + (q[0].date[9] - '0');
	int e = (q[0].date[3] - '0') * 10 + (q[0].date[4] - '0');
	int f = (q[0].date[0] - '0') * 10 + (q[0].date[1] - '0');
	if (a == d&&b == e&&o == f && (p[0].amount == q[0].amount) && !strcmp(p[0].description, q[0].description))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen)
{
	if ( A == NULL || B == NULL || ALen <= 0 || BLen <= 0)
	{
		return NULL;
	}
	int a = ALen, b = BLen,i=0,j=0,k=0,t;
	struct transaction c[100];
	while (i < a)
	{
		while (j < b)
		{   
			t = compare1(&A[i], &B[j]);
			printf("%d", t);
			if (t)
			{
				
				c[k] = A[i];
				k++;
			}
			j++;
		}
		i++;
		j = 0;
	}
	if (k == 0)
	{
		return NULL;
	}
	return c;
}