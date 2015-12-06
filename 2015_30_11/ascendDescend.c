/*Given a linked list which is in pattern like combination of ascending and descending. Sort it.
(First all ascending numbers occur ,next all descending nums )
Note : min of descending part is greater than max of ascending 
Ex: Input 1->2->7->20->15->10
Output 1->2->7->10->15->20*/


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
}testCase[10] = { { { 1, 2, 3, 6, 5, 4 }, 6, { 1, 2, 3, 4, 5, 6 } }, { { 1, 2, 3, 4, 5 }, 5, { 1, 2, 3, 4, 5 } },
{ { 3, 2, 1 }, 3, { 1, 2, 3 } }, { { 1, 2, 3, 5, 7, 6 }, 6, { 1, 2, 3, 5, 6, 7 } },{ { 1, 6, 5, 4 }, 4, {1,4,5,6}},
{ { 1, 2, 99, 45 }, 4, { 1, 2, 45, 99 } }, { { 1, 2, 7, 20, 15, 10 }, 6, {1,2,7,10,15,20} } };
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
int compare(struct node *expecHead, struct node *obserHead)
{
	int flag = 0;
	struct node * temp = expecHead;
	while (temp != NULL)
	{
		if (temp->num != obserHead->num)
		{
			flag++;
			break;
		}
		temp = temp->next;
		obserHead = obserHead->next;
	}
	if (flag>0)return 0;
	else return 1;
}
struct node * reverse(struct node *head1)
{
	struct node *temp;
	if (head1->next == NULL || head1 == NULL)
		return head1;
	temp = reverse(head1->next);

	head1->next->next = head1;
	head1->next = NULL;
	return temp;
}
struct node *sort(struct node *head)
{
	struct node *temp = head, *start = head, *end, *rev, *prev = head;
	int flag = 0,flag1=0;
	while ( temp != NULL&&temp->next != NULL)
	{
		if (temp->num <= temp->next->num)
		{
			flag1++;
			prev = temp;
			temp = temp->next;
		}
		else
		{
			flag = 1;
			rev = reverse(temp);
			if (flag1==0)return rev;
			break;
		}
	}
	if (flag)prev->next = rev;
	return head;
}
void testMethods()
{
	int i, ans;
	struct node *head = NULL, *givenList, *expecList, *obsList;
	for (i = 0; i<7; i++)
	{
		givenList = create(head, testCase[i].input, testCase[i].size);
		obsList = sort(givenList);
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


