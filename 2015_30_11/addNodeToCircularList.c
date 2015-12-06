//Add a node to the circular linked list(sorted) in correct positon
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
	int numToAdd;
	int output[30];
}testCase[10] = { { { 1, 1, 1 }, 3, 1, { 1, 1, 1, 1 } }, { { 1, 2, 2, 3 }, 4, 2, {1,2,2,2,3} } ,
{ { 2, 2, 2, 2, 3 }, 2, 2, { 2, 2, 2, 2, 2, 3 } }, { { 2, 3, 4, 5 }, 4, 1, {1,2,3,4,5} } ,
{ { 1, 3, 4, 5 }, 4, 2, { 1, 2, 3, 4, 5 } }, { { 1, 2, 4, 5 }, 4, 3, {1,2,3,4,5} },
{ { 1, 2, 3, 5 }, 4, 4, { 1, 2, 3, 4, 5 } }, { { 1, 2, 3, 4 }, 4,5, {1,2,3,4,5} } ,
{ { 1, 2, 3, 3, 3 }, 5, 3, { 1, 2, 3, 3, 3, 3 } }, { { 1, 2, 3, 3, 3, 4, 5, 5 }, 8, 4, {1,2,3,3,3,4,4,5,5} } };

struct node * create(struct node * head, int *givenList, int size)
{
	int i, n;
	struct node *prev;
	if (size == 0)return head;
	struct node * newNode;
	for (i = 0; i < size; i++)
	{
		newNode = (struct node*)malloc(sizeof(struct node));
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
	newNode->next = head;
	return head;
}
int compare(struct node *expecHead, struct node *obserHead)
{
	int flag=0;
	struct node * temp = expecHead;
	while (temp->next != expecHead)
	{
		if (temp->num != obserHead->num)
		{
			printf("hii");
			flag++;
			break;
		}
		temp = temp->next;
		obserHead = obserHead->next;
	}
	if (temp->num != obserHead->num)flag++;
	if (flag>0)return 0;
	else return 1;
}
struct node * addNode(struct node *head,int numToAdd)
{
	struct node *cur, *prev;
	cur = head; prev = head;
	int flag = 0, flag2 = 0;
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->num = numToAdd;
	if (head == NULL)
	{
		head = newNode;
		newNode->next = head;
	}
	else
	{
		while (cur->next != head)
		{
			if (cur == head && newNode->num < head->num) flag2++;
			else if (newNode->num <= cur->num && cur != head && flag2 == 0)
			{
				prev->next = newNode;
				newNode->next = cur;
				flag++;
				break;
			}
			prev = cur;
			cur = cur->next;
		}
		if (flag2)
		{
			newNode->next = head;
			head = newNode;
			cur->next = head;
		}
		else if (!flag)
		{
			if (newNode->num <= cur->num)
			{
				prev->next = newNode;
				newNode->next = cur;
			}
			else
			{
				cur->next = newNode;
				newNode->next = head;
			}
		}
	}
	return head;
}
void testMethods()
{
	int i, ans;
	struct node *head = NULL, *givenList,*expecList,*obsList;
	for (i = 0; i<10; i++)
	{
		givenList = create(head, testCase[i].input, testCase[i].size);
		obsList = addNode(givenList,testCase[i].numToAdd);
		head = NULL; 
		expecList = create(head, testCase[i].output, (testCase[i].size) + 1);
		
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
