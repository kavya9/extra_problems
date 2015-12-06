/*Given three numbers n1, n2, and r.Merge the table of n1 and n2 and find the r th number.In merging it should eliminate duplicate values(tables consists the multiples of those numbers, ie 3 contains 3, 6, 9, 12..)
Ex, n1 = 3, n2 = 5 and r = 5, The merged table is 3, 5, 9, 10, 12, 15(One more 15 is removed as its duplicate) 18, 20, 21, 24, 25........so on .
The rth num ie 5th number is 12, so OP is 12*/

#include<stdio.h>
#include<stdlib.h>
struct test
{
	int n1;
	int n2;
	int k;
	int ans;
}testCase[10] = { { 3, 5, 0, -1 }, { 3, 5, -12, -1 }, { 3, 5, 1, 3 }, { 99, 128, 2, 128 }, {3,5,2,5} ,
{ 3, 5, 3, 6 }, { 2, 3, 4, 6 }, { 2, 3, 6, 9 }, { 123, 478, 999, 97908 }, {6745,987,9482,8165451} };
int gcd(int n, int m)
{
	if (m <= n && n%m == 0)
		return m;
	if (n < m)
		return gcd(m, n);
	else
		return gcd(m, n%m);
}
int mergeTables(int n1, int n2, int k)
{
	if (k <= 0)return -1;
	int lcm,low,high,mid,r,cnt;
	lcm = (n1*n2) / gcd(n1, n2);
	low = 0; high = (n1*k)+1;
	while (high - low>1)
	{
		mid = (high + low) / 2;
		cnt = (mid / n1) + (mid / n2) - (mid / lcm);
		if (cnt >= k)
			high = mid;
		else low = mid;
	}
	return high;
}
int compare(int a, int b)
{
	if (a == b)return 1;
	return 0;
}
void testMethods()
{
	int n1, n2, k, x,i,final;
	for (i = 0; i < 10; i++)
	{
		final=mergeTables(testCase[i].n1, testCase[i].n2, testCase[i].k);
		x = compare(final, testCase[i].ans);
		if (x) printf("\npassed");
		else printf("\nfailed");
	}
}
int main()
{
	testMethods();
	getch();
	return 0;
}
