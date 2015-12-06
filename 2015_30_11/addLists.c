/*6.Write a program to add two linked list(Each node is represented by a digit) 
(Note: Unequal Lengths can also be given)
Ex: Input 1->2->3->4 and 1->2->3->4
	Output 2->4->6->8*/

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
}testCase[15] = { { { 0 }, 1, { 0 }, 1, 1, { 0 } }, { { 1, 1, 1 }, 3, { 3, 3, 3 }, 3, 3, {4,4,4} } ,
{ { 0, 0, 0 }, 3, { 0, 0, 0 }, 3, 1, { 0 } }, { { 1, 2, 3 }, 3, { 2, 5 }, 2, 3, { 1, 4, 8 } },
{ { 7, 8, 9 }, 3, { 5, 7, 5 }, 3, 4, { 1, 3, 6, 4 } }, { { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 }, 10, { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 }, 16,16, { 5, 5, 5, 5, 5, 6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 } },
 };
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
int length(struct node *head)
{
	struct node *temp = head;
	int count = 0;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}
void insert(struct node** head, int num)
{
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = (*head);
	(*head) = newNode;
}

struct node * addSameLength(struct node *head1, struct node *head2, int *carry)
{
	int sum = 0;
	if (head1 == NULL)return head1;
	struct node*temp = (struct node *)malloc(sizeof(struct node));
	temp->next = addSameLength(head1->next, head2->next, carry);
	sum = head1->num + head2->num + *carry;
	*carry = sum / 10;
	temp->num = sum % 10;
	return temp;
}
struct node* addCarry(struct node *temp1, struct node *head1, int *carry, struct node *result)
{
	int sum;
	struct node*result1;
	if (head1 != temp1)
	{
		addCarry(temp1, head1->next, carry, result);
		sum = head1->num + (*carry);
		*carry = sum / 10;
		sum = sum % 10;
		insert(result, sum);
	}
}
void add(struct node *head1, struct node *head2, struct node **result)
{
	struct node *temp1 = head1, *temp2 = head2, *temp;
	int len1, len2, carry = 0, diff = 0;
	len1 = length(head1);
	len2 = length(head2);
	if (len1 == len2)
		*result = addSameLength(head1, head2, &carry);
	else
	{
		diff = abs(len2 - len1);
		if (len1<len2)
		{
			temp = head1;
			head1 = head2;
			head2 = temp;
		}
		for (temp1 = head1; diff--; temp1 = temp1->next);
		*result = addSameLength(temp1, head2, &carry);
		addCarry(temp1, head1, &carry, result);
	}
	if (carry == 1)
	{
		insert(result, carry);
	}
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
	struct node *head = NULL, *givenList1, *givenList2, *expecList, *obsList;
	for (i = 0; i<6; i++)
	{
		givenList1 = create(head, testCase[i].input1, testCase[i].size1);
		givenList2 = create(head, testCase[i].input2, testCase[i].size2);
		add(givenList1, givenList2,&obsList);
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


