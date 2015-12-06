//Merge two linked list which are in sorted order
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int num;
	struct node *next;
};
struct test
{
	int input1[30];
	int size1;
	int input2[30];
	int size2;
	int size;
	int output[30];
}testCase[10] = { { { 5, 10, 15 }, 3, { 2, 3, 20 }, 3, 6, {2,3,5,10,15,20} },
{ { 1, 2, 10 }, 3, { 3, 4, 5 }, 3, 6, { 1, 2, 3, 4, 5,10 } },
{ { -1 }, 1, { -5, -4 , -3 }, 3, 4, {-5,-4,-3,-1} },
{ { 1, 3, 5 }, 3, { 2, 4, 6 }, 3, 6, {1,2,3,4,5,6} } ,
{ { 1, 3, 5 }, 3, { 6, 7, 8 }, 3, 6, {1,3,5,6,7,8} },
{ { 1, 2, 5, 6 }, 4, { 3, 4, 7 }, 3, 7, {1,2,3,4,5,6,7} } };
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
struct node* merge(struct node *head1, struct node *head2)
{
	//struct node *a = head1; struct node *b = head2;
	struct node *ans=NULL;
	if (head1 == NULL)return head2;
	if (head2 == NULL)return head1;
	/*if (head1->num==head2->num)
	{
	ans = head1;
	ans->next = head2;
	ans->next->next = merge(head1->next, head2->next);
	}*/
	if (head1->num < head2->num)
	{
		ans = head1;
		ans->next = merge(head1->next, head2);
	}
	else
	{
		ans = head2;
		ans->next = merge(head1, head2->next);
	}

	return ans;
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
void testMethods()
{
	int i, ans;
	struct node *head = NULL, *givenList1,*givenList2 ,*expecList, *obsList;
	for (i = 0; i<6; i++)
	{
		givenList1 = create(head, testCase[i].input1, testCase[i].size1);
		givenList2 = create(head, testCase[i].input2, testCase[i].size2);
		obsList = merge(givenList1, givenList2);
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
