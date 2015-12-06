/*Sorted a linked list which is in ascending order but two numbers are changed, i mean not in the usual order they need to be
Ex : 1->2->3->15->10->4->20; O / p:1 - 2 - 3 - 4 - 10 - 15 - 20*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int num;
	struct node *next;
};
struct test
{
	int input[30];
	int size;
	int output[30];
}testCase[10] = { { {1, 2, 3, 15, 10, 4, 20 }, 7, { 1, 2, 3, 4, 10, 15, 20 } },
{ { 2, 1, 3, 5 }, 4, { 1, 2, 3, 5 } }, { { 1, 2, 4, 3 }, 4, {1,2,3,4} },
{ { 1, 2, 4, 3, 5, 6 }, 6, { 1, 2, 3, 4, 5, 6 } }, { { 8, 1, 2, 3, 5, 0 }, 6, {0,1,2,3,5,8} },
{ { 1000,-1, 100, 128, -20,1001 }, 5, {-20,-1,100,128,1000,1001} },
{ { 1, 2, 4, 7 }, 4, {1,2,4,7} } };
struct node * create(struct node * head, int *givenList, int size)
{
	int i, n;
	struct node *prev;
	for (i = 0; i < size; i++)
	{
		struct node * newNode = (struct node*)malloc(sizeof(struct node));
		newNode->num = givenList[i];
		if (head == NULL)
		{
			head = newNode;
			prev = head;
		}
		prev->next = newNode;
		prev = newNode;
		newNode->next = NULL;
	}
	return head;
}
void swap(int *num1, int *num2)
{
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
struct node * misPlaced(struct node *head)
{
	struct node *cur1 = head, *prev1 = head, *sprev1 = head, *cur2, *prev2, *next2;
	int flag1 = -1, flag2 = -1, temp;
	while (cur1 != NULL)
	{
		if (prev1->num > cur1->num)
		{
			flag1++;
			break;
		}
		prev1 = cur1;
		cur1 = cur1->next;
	}
	if (flag1 == -1)return head;
	prev2 = cur1;
	cur2 = cur1->next;
	while (cur2 != NULL)
	{
		if (prev2->num > cur2->num)
		{
			flag2++;
			break;
		}
		prev2 = cur2;
		cur2 = cur2->next;
	}
	if (flag1 != -1 && flag2 != -1)
		swap(&(prev1->num), &(cur2->num));
	else if (flag1 != -1 && flag2 == -1)
		swap(&(prev1->num), &(cur1->num));
	return head;
}
int compare(struct node *expecHead, struct node *obserHead)
{
	int flag = 0;
	struct node * temp = expecHead;
	while (temp != NULL)
	{
		if (temp->num != obserHead->num)
		{
			//printf("hii");
			flag++;
			break;
		}
		temp = temp->next;
		obserHead = obserHead->next;
	}
	if (flag>0)return 0;
	else return 1;
}

void testMethods()
{
	int i, ans;
	struct node *head = NULL, *givenList, *expecList, *obsList;
	for (i = 0; i<7; i++)
	{
		givenList = create(head, testCase[i].input, testCase[i].size);
		obsList = misPlaced(givenList);
		head = NULL;
		expecList = create(head, testCase[i].output, testCase[i].size);
		ans = compare(expecList, obsList);
		if (ans)
			printf("\n passed");
		else
			printf("\n failed");
	}
}
int main()
{
	testMethods();
	getchar();
	return 0;
}
