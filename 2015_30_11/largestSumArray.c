/*Largest Contiguous Sum Array .
Ex : 1, 2, 3, 5, -10, 20, 40 O / P : 1,2,3,5,-10,20, 40 Sum : 61
 Ex : 1 2 3 4 5 - 2 - 3 - 4 - 20 10 2 O / : P : 1 2 3 4 5 Sum : 15*/
#include<stdio.h>
#include<stdlib.h>
struct test
{
	int input[30];
	int size;
	int finalsize;
	int output[30];
	int sum;
}testCase[10] = {{ { 1, 2, 3, 4, 5, -2, -3, -4, -20, 10 }, 10, 5, { 1, 2, 3, 4, 5 }, 15 } ,
{ { 1, 2, 3, 5, -10, 20, 40 }, 7, 7, { 1, 2, 3, 5, -10, 20, 40 },61 },
{ { -1, -2, -3, -4, -5 }, 5, 1, { -1 }, -1 },
{ { -1, 3, -5, 4, 6, -1, 2, -7, 13, -3 }, 10, 6, { 4, 6, -1, 2, -7, 13 } ,17},
{ { 0, -1, -2, 100 }, 4, 1, {100},100 } };
struct output
{
	int subSet[30];
	int maxSum;
};
int *allocate(int *a, int l)
{
	int i, *r;
	r = (int*)malloc(l*sizeof(int));
	for (i = 0; i<l; i++)
		r[i] = a[i];
	return r;
}
struct output maxSumSubArray(int *array, int len)
{
	struct output out;
	int maxSumSoFar = -2147483648,maxSum,start=0,end=0;
	int curSum = 0,b,s,i;
	s = i = 0;
	for (i = 0; i < len; i++)
	{
		curSum += array[i];
		if (curSum > maxSumSoFar) 
		{
			maxSumSoFar = curSum;
			start = s;
			end = i;
		}
		if (curSum < 0) 
		{
			curSum = 0;
			s = i + 1;
		}
	}
	out.maxSum = maxSumSoFar;
	int j = 0;
	for (i = start; i <= end; i++)
	{
		out.subSet[j] = array[i];
		j++;
	}
	return out;
}
int compare(int *subSet, int *finalArray, int size, int sum, int maxSum)
{
	int flag1 = 0, i;
	for (i = 0; i < size; i++)
	{
		if (subSet[i] != finalArray[i])
		{
			flag1++;
			break;
		}
	}
	if (flag1 == 0 && (sum == maxSum))return 1;
	return 0;
}
void testMethods()
{
	int i, *givenArray,finalArray, x;
	struct output final;
	for (i = 0; i<5; i++)
	{
		givenArray = allocate(testCase[i].input, testCase[i].size);
		final = maxSumSubArray(givenArray, testCase[i].size);
		finalArray = allocate(testCase[i].output, testCase[i].finalsize);
		x = compare(final.subSet, finalArray, testCase[i].finalsize,testCase[i].sum,final.maxSum);
		if (x == 1)
			printf("\n passed");
		else
			printf("\n failed");
	}
}
int main()
{
	testMethods();
	getchar();
}
