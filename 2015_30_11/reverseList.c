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
}testCase[10] = { { { 1 }, 1, { 1 } }, { { 1, 2, 3 }, 3, { 3, 2, 1 }}, 
{ { 1, 1, 1 }, 3, { 1, 1, 1 } }, { { -5 }, 1, { -5 } }, { { -9, 0, 7, -78 }, 4, {-78,7,0,-9} } };
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
	while (temp!=NULL)
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
	if (flag>0)return 0;
	else return 1;
}
struct node * reverse(struct node *head1)
{
	struct node *temp;
	//printf("hii");
	if (head1->next == NULL || head1 == NULL)
		return head1;
	temp = reverse(head1->next);

	head1->next->next = head1;
	head1->next = NULL;
	//printf("\ntemp= "); display(temp);
	return temp;
}
void testMethods()
{
	int i, ans;
	struct node *head = NULL, *givenList, *expecList, *obsList;
	for (i = 0; i<5; i++)
	{
		givenList = create(head, testCase[i].input, testCase[i].size);
		obsList = reverse(givenList);
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

