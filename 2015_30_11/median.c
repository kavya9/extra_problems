//Find median of a given linked list (Sorted Linked List) 

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int num;
	struct node *next;
	int visit;
};
struct test
{
	int input[30];
	int size;
	float output;
	//struct node *head;
}testCase[10] = { { { 1, 2 }, 2, 1.500000 }, { { -1 }, 0, -1 }, { {25},1,25.000000 },
{ { -5, -2, 3, 7, 12, 15 }, 6, 5.000000 }, {{124,200,621,1010,5145},5,621.000000 },
{ { -10, -1, 0 }, 3, -1.000000 }, { { -5, -4, -2, -1 }, 4, -3.000000 } };

struct node * create(struct node * head,int *givenList,int size)
{
	int i, n;
	struct node *prev;
	/*printf("enter n:");
	scanf("%d", &n);*/

	for (i = 0; i < size; i++)
	{
		struct node * newNode = (struct node*)malloc(sizeof(struct node));
		newNode->num = givenList[i];
		//scanf("%d", &newNode->num);
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
int compare(float expected,float observed )
{
	if (expected == observed)return 1;
	else return 0;
}

/*method 1 : traversing the list to find the count of nodes ,then again retraversing from the starting of
the list till half of the list.now median = num at (count/2) if count = odd ,otherwise median = num at
(count+(count+1))/2 */
float median1(struct node *head)
{
	int count = 0, even = 0, mid1;
	struct node *temp;
	temp = head;
	if (head == NULL)return -1;
	if (head->next == NULL)return head->num;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	if (count % 2 == 0)
		even = 1;
	count /= 2;
	while (count > 1)
	{
		head = head->next;
		count--;
	}
	if (even)
	{
		//printf("mid 1 = %d ,mid 2 = %d", (head->num), (head->next->num));
		return (((head->num) + (head->next->num)))*(1.0) / 2;
	}
	return head->next->num;
}

/*method 2 : maintain two pointers single - which traverses one node at once ; doubl - which traverses two
nodes at once. if no of nodes is even then by the time doubl reaches NULL single will be at mid of the list
average of num at that mid node and previous node gives median .if no of nodes is odd then by the time doubl
reaches NULL ,single will be at mid of the list which is the required median.*/

float median2(struct node * head)
{
	struct node *single, *doubl, *prev;
	single = head;
	doubl = head;
	prev = head;
	if (head == NULL)return -1;
	if (head->next == NULL)return head->num;
	while (doubl != NULL && doubl->next != NULL)
	{
	prev = single;
	single = single->next;
	doubl = doubl->next->next;
	}
	if (doubl == NULL)return (((prev->num) + (single->num)))*(1.0) / 2;
	else return single->num;
}

void testMethods()
{
	int i,ans1,ans2;
	float expecMedian1,expecMedian2;
	struct node *head=NULL,*givenList;
	for (i = 0; i<7; i++)
	{
		givenList = create(head,testCase[i].input, testCase[i].size);
		expecMedian1 = median1(givenList);
		expecMedian2 = median1(givenList);
		//printf("\n%f\n", expecMedian2);
		ans1 = compare(testCase[i].output, expecMedian1);
		ans2 = compare(testCase[i].output, expecMedian2);
		if (ans1 && ans2 )
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



